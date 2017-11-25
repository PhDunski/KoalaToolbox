/** @file color.cpp
  *
  * Fournit la définition de l'opérateur << pour l'affichage de couleurs
  * au travers des flux standards
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#include <Color.hpp>
#include <iostream>
std::ostream & operator<<(std::ostream & os, Color const & color){
    os<<"red = "<<color.red
      <<" green = "<<color.green
      <<" blue = "<<color.blue<<std::endl;
    return os;
}
