/** @file Derivee1.cpp
  *
  * Fournit la définition des fonctions membres de la classe Derivee1
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#include "Derivee1.h"
#include <iostream>
void Derivee1::print() const{
    std::cout<<"Derivee1 :"
             <<" i = "<< i
             <<" color : "<<color<<std::endl;
}
