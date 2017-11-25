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
#include <Factory.hpp>
#include <Derivee1.hpp>
#include <Derivee2.hpp>
using factory = Ktb::Tools::Factory<Base>;
//template Base *  factory::template create <Base>(); it's an abstract class!!!
template Base *  factory::template create <Derivee1>(int);
template Base *  factory::template create <Derivee1>(int, Color const &);
template Base *  factory::template create <Derivee2>(std::string const &);
template Base *  factory::template create <Derivee2>(std::string const &, Color const &);
