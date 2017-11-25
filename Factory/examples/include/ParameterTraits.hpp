/** @file ParameterTraits.h
  *
  * Fournit les traits de politiques utilisés pour le test
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */

#ifndef PARAMETERTRAITS_H_INCLUDED
#define PARAMETERTRAITS_H_INCLUDED
#include <Derivees_fwd.h>
struct Derivee1Trait{
    using value_type  = Derivee1;
};
struct Derivee2Trait{
    using value_type = Derivee2;
};

#endif // PARAMETERTRAITS_H_INCLUDED
