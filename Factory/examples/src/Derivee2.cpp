/** @file Derivee1.cpp
  *
  * Fournit la définition des fonctions membres de la classe Derivee2
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#include <Derivee2.hpp>
#include <iostream>
void Derivee2::print() const{
    std::cout<<"Derivee2 :"
             <<" str = "<< str_
             <<" color : "<<color_<<std::endl;
}
