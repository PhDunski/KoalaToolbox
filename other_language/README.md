<a id="top" />
# Un autre langage de programmation

Ce n'est un secret pour personne : de tous les langages de programmation
que je connais, ma pr&eacute;f&eacute;rence va clairement au C++.

Cette pr&eacute;f&eacute;rence est essentiellement due  la
philosophie du langage dont on peut ais&eacute;ment tracer les grandes
lignes:

- on ne paye le prix de ce que l'on utilise
- on privil&eacute;gie l'utile au "s&eacute;curitaire"
- on ne se limite pas à un paradigme particulier
<a id="why" />
## Pourquoi un nouveau langage?

Vous auriez tout à fait raison de vous demander la raison qui me pousse
à essayer de cr&eacute;er un nouveau langage.

Cette raison est finalement toute simple : malgr&eacute; les &eacute;normes qualit&eacute;s
que je reconnais à C++, je lui trouve quelques d&eacute;fauts qui m&eacute;riteraient
-- selon moi -- d'être corrig&eacute;s.

Malheureusement, ces d&eacute;fauts font intrins&egrave;quement partie de son ADN,
si bien qu'il serait difficiles de les corriger.

Parmi les principaux, j'ai envie de citer :

- la constance explicite
- un système de déclaration des fonctionnalités archaïque
- le sens ambigu du mot cl&eacute; `static`
- la non diff&eacute;rentiation des s&eacute;mantiques
- une intégration imparfaite de la programmation par contrat
- l'acceptation de décisions conceptuellement aberrantes
- une trop grande compatibilit&eacute; avec C
- l'ordre d'évaluation des arguments et des opérandes est mal défini
- le manque de distinction entre un `char` et un `byte` (avant C++17)

Ces quelques d&eacute;fauts rendent -- à mon humble avis -- C++ bien plus complexe
qu'il n'aurait pu l'être si il n'en avait pas souffert.

Le but de ce projet est (d'essayer) de cr&eacute;er un langage qui aurait toute
la puissance du C++ mais qui en r&eacute;soudrait les probl&egrave;mes les plus criants.
<a id="changes" />
## Qu'est ce que cela changerait?

Bien s&ucurcr, si m'autorise &agrave; consid&eacute;rer certains aspects
d'un langage cr&eacute;&eacute; par quelqu'un de tr&egrave;s certainement
plus intelligent et mieux form&eacute; que moi comme "probl&eacute;matique",
c'est parce que je crois tr&egrave;s sinc&egrave;rement que
leur correction permettrait d'obtenir un langage tout aussi puissant, mais
bien plus "s&eacute;curisant" à l'emploi.  Voici les raisons qui me poussent
à le croire
<a id="mutable"/>
### La mutabilit&eacute; explicite

Le fait que C++ consid&egrave;re les donn&eacute;es comme &eacute;tant
mutables par d&eacute;faut favorise d'une certaine manière les effets de
bord non d&eacute;sir&eacutes.

En effet, si l'on oublie de déclarer une variable ou un param&egrave;tre
comme &eacute;tant constant, le compilateur ne verrra absolument aucune
objection au fait que l'on essaye de la modifier.

En inversant les r&egrave;gles et en obligeant le d&eacute;velopeur &agrave;
indiquer explicitement son souhait de pouvoir modifier une donn&eacute;
on pourrait r&eacute;duire très fortement les erreurs d'attention, car
le compilateur refuserait toute tentative de modification par d&eacute;faut.
<a id="modules"/>
### utilisation de modules

C++ utilise la directive du préprocesseur `#include <filename>` pour permettre
au compilateur de connaitre les éléments externes à l'unité de compilation
dont il a besoin.

L'utilisation de **modules** rendrait la compilation plus rapide
<a id="static" />
### le mot cl&eacute; `static`

En C++, le mot cl&eacute; `static` peut &ecirc;tre utilis&eacute; de trop
nombreuses mani&ecirc;res, ce qui le rend particuli&eacute;rement ambigu.

Il est -- en effet -- possible de l'utiliser pour représenter une fonction
ou une donn&eacute;e membre dans une classe (ou dans une structure), sous
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
fonction (ou &agrave; une donn&eacute;e) qui **fait partie int&eacute;grante
de la classe** (ou de la structure), mais qui **ne d&eacute;pend d'aucune
instance** de celle-ci.

Autrement dit, la donn&eacute;e ou la fonction est accessible (en fonction)
de son accessibilit&eaucte;) m&ecirc;me s'il n'existe aucune instance du
type de la structure ou de la classe; et, par voie de cons&eacute;quence,
que toutes les instances de la classe (ou de la structure)partagent la
m&ecirc;me valeur : si A de la classe modifie la valeur de la donn&eacute;,
l'instance B de la classe utilisera la m&ecirc;me valeur que celle de A.

Nous pourrions dire qu'il s'agit de donn&eacute;e (ou de fonction) de type,
par opposition aux donn&eacute;es et aux fonctions d'instance, qui ne sont
accessible qu'au d&eacute;part d'une instance existante et bien particuli&egrave;re
de la classe (ou de la structure)

D'un autre cot&eacute;, le mot cl&eacute; `static` peut d&eacute;signer une
donn&eacute;e au sein d'une fonction dont la valeur est r&eacute;utilis&eacute;e
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

Enfin, le mot cl&eacute; `static` signifie, quand il est utilis&eacute;
pour d&eacute;signer une fonction libre, que la fonction n'est accessible
que dans l'unit&eacute; de compilation dans laquelle elle est définie.

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

&eacute;chouera &agrave; l'&eacutedition de liens sous pr&eacute;texte
d'une r&eacute;f&eacute;rence ind&eacute;finie vers "foo()".

&Agrave; mon sens, chacune des situations pr&eacute;sentes m&eacute;rite
d'&ecirc;tre d&eacute;sign&eacute;e par un mot cl&eacute; sp&eacutecifique.
<a id="semantic" />
### Diff&eacute;rencier les s&eacute;mantiques

En for&ccedil;ant l'utilisateur &agrave; choisir un mot cl&eacute;
diff&eacute;rent pour ses agr&eacute;gats de donn&eacute;es en fonction
de la s&eacute;mentique qu'il souhaite lui donner, on le forcerait &agrave;
se poser la question de la s&eacute;mantique avant de faire quoi que ce
soit.

Bien s&ucirc;r, cela ne l'emp&ecirc;cherait pas de faire un choix inadap&eacute;
(comme : d&eacute;cider de donner une s&eacute;mantique de valeur au type
`Vehicle` ou une s&eacute;mantique d'enti&eacute au type `Color`) mais
cela l'obligerait à se poser la question.

De plus, en ayant deux mots cl&eaucte; distincts; il devient tout &agrave;
fait possible de faire en sorte que l'un

- implémente automatiquement un constructeur de copie, un op&eacute;rateur
  d'affectation et un comparateur d'&eacute;galité
- refuse l'h&eacute;ritage **public** qui est l'apanage de la s&eacute;mantique
  d'entit&eacute;
- autorise l'h&eacute;ritage priv&eacute;, qui n'a rien à voir avec le LSP
- autorise le CRTP, vu que ce n'est pas de l'héritage au sens du LSP
- utilise l'accessibilité **publique** par d&eacute;faut, vu que chaque
  donn&eacute;e de l'agr&eacute;gat est -- par nature --
  un &eacute;l&eacutement auquel nous voudrions acc&eacute;der.

et que l'autre

- interdise formellement la cr&eacute;ation d'un constructeur de copie, d'u
  op&eacute;rateur d'affectation et de n'importe quel op&eacute;rateur de
  comparaison
- autorise l'h&eacute;ritage **public**
- autorise l'h&eacute;ritage priv&eacute;
- autorise le CRTP
- utilise l'accessibilit&eacute; **priv&eacute;** par d&eacute;faut car
  nous sommes face &agrave; un fournisseur de service avant tout
<a id="ppc" />
### Meilleur support de la programmation par contrat

Ce n'est un secret pour personne : je suis un ardent d&eacute;fenseur de
ce que l'on appelle couremment la *programmation par contrat*.

Bien que j'aie tendance à la favoriser par rapport à la *programmation
d&eacute;fensive*, il n'est pas dans mes intentions de mettre ces deux
approche en comp&eacutetition, car chacune d'elle pr&eacute;sente des avantages.

Cependant, force est de constater que la programmation par contrat est
finalement très mal int&eacute;gr&eacute;e en C++ :

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
