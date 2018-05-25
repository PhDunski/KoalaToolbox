<a id="top"></a>
<a id="structured" ></a>
# la programmation structurée

Le langage devra bien entendu supporter l'ensemble des concepts de la
programmation structurée, c'est à dire qu'il devra supporter:

- les types primitifs
    - booléens (dont la valeur se limite à `Vrai` ou à `Faux`)
    - susceptibles de représenter des valeurs numérique entières --
      signées et non signées -- limitées à certains intervalles
    - susceptible de représenter des valeurs numériques à virgules flottante
      limitées à certains intervalles
    - susceptible de représenter la notion de "caractère" dans le respect
      des normes principales (ASCII, UTF-X, Unicode, ...)
- les structures décisionnelles telles que
    - les tests décisionnels, contenant :
        - les tests "Vrai / Faux" et la possibilité de prévoir une alternative
        - les tests "à choix multiple"
    - les répétition conditionnelles (les boucles), contenant :
        - les boucles "Tant que"
        - les boucles "Jusque"
        - les boucle "Pour" (`<debut>` <`conditiond'arret> <pas>`)
        - les boucle "pour tout" (`<élément>  <collection>`)
        - les boucle "Pour" (`<intervalle>`)
- le passage de paramètres
- le retour de fonction
- les type définis par l'utilisateur
- la récursivité
- un moyen efficace de briser le flux d'exécution en cas d'erreur impossible
  à prévoir (exception)

>> **note** Je ne suis pas favorable du tout à l'utilisation de mots clés
   semblable au `continue` et `break` du C++ à l'intérieur de boucles ou
   de tests'

>> **note** Je suis farouchement opposé à la possibilité de créer des sauts
   dans le code.  Tout mot clé similaire au `goto` du C++ est **banni du
   langage**
