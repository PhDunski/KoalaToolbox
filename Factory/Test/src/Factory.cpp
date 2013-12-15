/** @file Factory.cpp
  *
  * Fichier qui peut être privilégié pour l'instanciation explicite des classes
  * template ConcreteCretionParameterList et ObjectCreator.
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#include "Factory.h"
#include <ParameterLists.h>
#include <Derivee1.h>
#include <Derivee2.h>
#include <DerivedAliases.h>
#include <CoreImplementation.h>

template class ConcreteCretionParameterList<Base, Factory, Derivee1Trait, IntOnlyParam>;
template class ConcreteCretionParameterList<Base, Factory, Derivee1Trait, IntAndColorParam>;
template class ConcreteCretionParameterList<Base, Factory, Derivee2Trait, StringOnlyParam>;
template class ConcreteCretionParameterList<Base, Factory, Derivee2Trait, StringAndColorParam>;
template class ObjectCreator<Base,Derivee1Trait, IntOnlyParam>;
template class ObjectCreator<Base,Derivee1Trait, IntAndColorParam>;
template class ObjectCreator<Base,Derivee2Trait, StringOnlyParam>;
template class ObjectCreator<Base,Derivee2Trait, StringAndColorParam>;
