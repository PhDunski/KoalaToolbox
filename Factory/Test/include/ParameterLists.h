/** @file ParameterLists.h
  *
  * Fournit quelques alias de type pour faciliter le travail lors du test
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#ifndef PARAMETERLISTS_H_INCLUDED
#define PARAMETERLISTS_H_INCLUDED
#include <Color.h>
#include <string>
#include <tuple>
using NoParamList = std::tuple<void>;
using IntOnlyParam = std::tuple<int>;
using IntAndColorParam = std::tuple<int, Color>;
using StringOnlyParam = std::tuple<std::string>;
using StringAndColorParam  = std::tuple<std::string, Color>;
#endif // PARAMETERLISTS_H_INCLUDED
