/** @file DerivedAliases.h
  *
  * Fournit quelques alias de type pour faciliter le travail lors du test
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#ifndef DERIVEDALIASES_H_INCLUDED
#define DERIVEDALIASES_H_INCLUDED
#include <ParameterTraits.h>
#include <ParameterLists.h>
#include <CreationLists.h>
using Derivee1ListOnlyInt = ConcreteCretionParameterList<Base,Factory,Derivee1Trait,IntOnlyParam>;
using Derivee1ListIntAndColor = ConcreteCretionParameterList<Base,Factory,Derivee1Trait,IntAndColorParam>;
using Derivee1ListOnlyString = ConcreteCretionParameterList<Base,Factory,Derivee2Trait,StringOnlyParam>;
using Derivee1ListStringAndColor = ConcreteCretionParameterList<Base,Factory,Derivee2Trait,StringAndColorParam>;


#endif // DERIVEDALIASES_H_INCLUDED
