<a id="top" />
# Un autre langage de programmation

Ce n'est un secret pour personne : de tous les langages de programmation
que je connais, ma préférence va clairement au C++.

Cette préférence est essentiellement due  la
philosophie du langage dont on peut aisément tracer les grandes
lignes:

- on ne paye le prix de ce que l'on utilise
- on privilégie l'utile au "sécuritaire"
- on ne se limite pas à un paradigme particulier
<a id="why" />
## Pourquoi un nouveau langage?

Vous auriez tout à fait raison de vous demander la raison qui me pousse
à essayer de créer un nouveau langage.

Cette raison est finalement toute simple : malgré les énormes qualités
que je reconnais à C++, je lui trouve quelques défauts qui mériteraient
-- selon moi -- d'être corrigés.

Malheureusement, ces défauts font intrinsèquement partie de son ADN,
si bien qu'il serait difficiles de les corriger.

Parmi les principaux, j'ai envie de citer :

- la constance explicite
- un système de déclaration des fonctionnalités archaïque
- le sens ambigu du mot clé `static`
- la non différentiation des sémantiques
- une intégration imparfaite de la programmation par contrat
- l'acceptation de décisions conceptuellement aberrantes
- une trop grande compatibilité avec C
- l'ordre d'évaluation des arguments et des opérandes est mal défini
- le manque de distinction entre un `char` et un `byte` (avant C++17)

Ces quelques défauts rendent -- à mon humble avis -- C++ bien plus complexe
qu'il n'aurait pu l'être si il n'en avait pas souffert.

Le but de ce projet est (d'essayer) de créer un langage qui aurait toute
la puissance du C++ mais qui en résoudrait les problèmes les plus criants.
<a id="changes" />
## Qu'est ce que cela changerait?

Bien sûr, si m'autorise à considérer certains aspects
d'un langage créé par quelqu'un de très certainement
plus intelligent et mieux formé que moi comme "problématique",
c'est parce que je crois très sincèrement que
leur correction permettrait d'obtenir un langage tout aussi puissant, mais
bien plus "sécurisant" à l'emploi.  Voici les raisons qui me poussent
à le croire
<a id="mutable"/>
### La mutabilité explicite

Le fait que C++ considère les données comme étant
mutables par défaut favorise d'une certaine manière les effets de
bord non désirés.

En effet, si l'on oublie de déclarer une variable ou un paramètre
comme étant constant, le compilateur ne verrra absolument aucune
objection au fait que l'on essaye de la modifier.

En inversant les règles et en obligeant le dévelopeur à
indiquer explicitement son souhait de pouvoir modifier une donné
on pourrait réduire très fortement les erreurs d'attention, car
le compilateur refuserait toute tentative de modification par défaut.
<a id="modules"/>
### utilisation de modules

C++ utilise la directive du préprocesseur `#include <filename>` pour permettre
au compilateur de connaitre les éléments externes à l'unité de compilation
dont il a besoin.

L'utilisation de **modules** rendrait la compilation plus rapide
<a id="static" />
### le mot clé `static`

En C++, le mot clé `static` peut être utilisé de trop
nombreuses maniêres, ce qui le rend particuliérement ambigu.

Il est -- en effet -- possible de l'utiliser pour représenter une fonction
ou une donnée membre dans une classe (ou dans une structure), sous
une forme proche de

```cpp

    struct MaStruct{
        static void foo();
        static int data;
    };

    // OU - OU - OU
    class MaClasse{
        static void foo();
        static int data;
    };

```
Dans cette circonstance, le mot clé indique que nous avons affaire à une
fonction (ou à une donnée) qui **fait partie intégrante
de la classe** (ou de la structure), mais qui **ne dépend d'aucune
instance** de celle-ci.

Autrement dit, la donnée ou la fonction est accessible (en fonction)
de son accessibilité) même s'il n'existe aucune instance du
type de la structure ou de la classe; et, par voie de conséquence,
que toutes les instances de la classe (ou de la structure)partagent la
même valeur : si A de la classe modifie la valeur de la donné,
l'instance B de la classe utilisera la même valeur que celle de A.

Nous pourrions dire qu'il s'agit de donnée (ou de fonction) de type,
par opposition aux données et aux fonctions d'instance, qui ne sont
accessible qu'au départ d'une instance existante et bien particulière
de la classe (ou de la structure)

D'un autre coté, le mot clé `static` peut désigner une
donnée au sein d'une fonction dont la valeur est réutilisée
d'une exécution de la fonction à l'autre, un code proche de

```C++

    void foo(){
        static int i{0};
        ++i;
        std::cout<<i<<"\n";
    }
    int main(){
        for(int i = 0; i<5;++i)
            foo()
    }

```

produisant la sortie


```Bash

    1
    2
    3
    4
    5
```

Enfin, le mot clé `static` signifie, quand il est utilisé
pour désigner une fonction libre, que la fonction n'est accessible
que dans l'unité de compilation dans laquelle elle est définie.

Ainsi, avec un code proche prenant la forme de

~~~C++

    // Dans foo.cpp
    static void foo(){
        // ...
    }
    // dans main.cpp
    static void foo();
    // OU - OU - OU
    void foo();
    int main(){
        foo();
    }

```

la commande

```Bash

CC foo.cpp main.cpp

```

échouera à l'édition de liens sous prétexte d'une référence indéfinie vers "foo()".

A mon sens, chacune des situations présentes mérite d'être désignée par un mot clé spécifique.

### Différencier les sémantiques

En forçant l'utilisateur à choisir un mot clé
différent pour ses agrégats de données en fonction
de la sémentique qu'il souhaite lui donner, on le forcerait à
se poser la question de la sémantique avant de faire quoi que ce
soit.

Bien sûr, cela ne l'empêcherait pas de faire un choix inadapé
(comme : décider de donner une sémantique de valeur au type
`Vehicle` ou une sémantique d'enti& au type `Color`) mais
cela l'obligerait à se poser la question.

De plus, en ayant deux mots clé distincts; il devient tout à
fait possible de faire en sorte que l'un

- implémente automatiquement un constructeur de copie, un opérateur
  d'affectation et un comparateur d'égalité
- refuse l'héritage **public** qui est l'apanage de la sémantique
  d'entité
- autorise l'héritage privé, qui n'a rien à voir avec le LSP
- autorise le CRTP, vu que ce n'est pas de l'héritage au sens du LSP
- utilise l'accessibilité **publique** par défaut, vu que chaque
  donnée de l'agrégat est -- par nature --
  un élément auquel nous voudrions accéder.

et que l'autre

- interdise formellement la création d'un constructeur de copie, d'u
  opérateur d'affectation et de n'importe quel opérateur de
  comparaison
- autorise l'héritage **public**
- autorise l'héritage privé
- autorise le CRTP
- utilise l'accessibilité **privé** par défaut car
  nous sommes face à un fournisseur de service avant tout
<a id="ppc" />
### Meilleur support de la programmation par contrat

Ce n'est un secret pour personne : je suis un ardent défenseur de
ce que l'on appelle couremment la *programmation par contrat*.

Bien que j'aie tendance à la favoriser par rapport à la *programmation
défensive*, il n'est pas dans mes intentions de mettre ces deux
approche en compétition, car chacune d'elle présente des avantages.

Cependant, force est de constater que la programmation par contrat est
finalement très mal intégrée en C++ :

Une meilleure intégration de la programmation par contrat permettrait :
- au compilateur de vérifier certains éléments à la compilation
- au compilateur de générer automatiquement le code adéquat pour vérifier
  les invariants, les pré et les post conditions
- aux outils d'apporter plus facielement la preuve que le programme est
  correct
- Sans doute bien d'autres choses encore
<a id="conception" />
### Interdire les décisions conceptuelles aberrantes

Un code porche de

```C++

    class Base{
        public:
            virtual void foo();
    };
    class Derivee : public Base{
        private:
            void foo() override;
    }

```

est tout à fait légal en C++.  Il m'a fallu une discussion acharnée pour
arriver à convaincre diverses personnes que le fait que le compilateur
**accepte** ce code, un tel code :

- était conceptuellement incorrect
- violait le LSP

De manière générale, C++ autorise le développeur à prendre beaucoup trop
de décisions conceptuellement incorrectes, qui finissent systématiquement
par lui poser  problème.

Certaines sont impossibles à empêcher, mais celles qui peuvent être interdites
(comme le code que je présente) devraient l'être.
<a id="compat" />
### Abandonner la compatibilité avec le C

Pour des raisons historiques, C++ est "aussi compatible que faire se peut"
avec C.

A l'heure actuelle encore, certains développeurs utilisent cette compatibilité
accrue pour justifier le fait de coder en C++ comme ils le feraient en C,
et pour adapter les "bonnes pratiques" du C au C++.

Il ne s'agit pas ici de dénigrer ces bonnes pratiques, mais force est de
constater que la plupart d'entres elles font bien plus de mal que de bien
lorsqu'elles sont adapatées au C++.

C et C++ sont deux langages totalement différents, ce qui implique des
bonnes pratiques différentes.

Je ne nie pas le fait que C est la `franqua linguae` des langages de
programmation ni le fait que la capacité de profiter de bibliothèques
écrites en C soit primordiale.  Mais lorsque l'on développe dans un langage
donné, c'est ce langage qui doit être utilisé, à l'exception de tout autre.
<a id="eval"/>
### Une définition plus précise de l'ordre d'évaluation

En C++, un code proche de

```c++

    int main(){
        int i{5};
        foo(++i, --i);
    }

```

va provoquer un comportement indéfini, parce que l'on ne peut pas estimer
précisément dans quel ordre les argument seront transmis à foo.

Si bien que ce code pourrait être évalué sous la forme de `foo(6, 5)` si
les arguments sont évalués de gauche à droite ou sous la forme de `foo(5, 4)`
s'ils sont évalués de droite à gauche.

Et bien sur, le résultat obtenu risque d'être fondamentalement différnt.

Une meilleure définition de l'ordre d'évaluation des argument et des opérandes
en tous genre faciliterait la vie du développeur, sans pour autant lui
imposer de limites inutiles.
<a id="no_change" />
## Ce qui ne changera pas

Pour faire simple : rien de ce qui est sans rapport avec les points cité
plus haut ne devrait fondamentalement changer.

### Distinguer clairement le char du byte

Je ne compte plus le nombre de fois où j'ai du expliquer la différence
qu'il y avait entre la notion de caractère (sélectionne un *glyphe* dans
une table de correspondance) et la notion de *byte* (souvent françisé à
tord avec le terme *octet* ) uniquement parce que les deux notions étaient
représentées par le même type primitif : le `/*unsigned*/ char`.

Ce manque de distinction a été résolu avec l'apparition en C++17 de `std::byte`
qui représente explicitement un byte qui n'est pas mis en relation avec un
glyphe particulier dans une table de correspondance.

Je trouve néanmoins dommage que cette distinction soit faite au niveau de
la bibliothèque et non au niveau du langage.

Si la notion de *byte* (un ensemble de N bits successifs en mémoire) pouvait
être décorellée de la notion de caractères **au niveau du langage**, la
distinction entre les deux deviendrait beaucoup plus claire, et la notion de
`ByteArray` plus facile à expliquer et à justifier.

## Voir aussi

- [la description de base](description#top)
- [les fonctionnalités du langage](fonctionnalities#top)
- [les mots clés du langage](keywords#top)
- [La syntaxe du langage](grammar#top)
