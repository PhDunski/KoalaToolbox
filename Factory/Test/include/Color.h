/** @file Couleur.h
  *
  * Fournit la définition d'une structure de donnée (Couleur, en l'occurrence)
  * utilisée pour le test
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED
#include <iosfwd>
struct Color{
    Color():red(0),green(0),blue(0){}
    Color(int red, int green, int blue):
        red(red),green(green),blue(blue){}
    int red;
    int green;
    int blue;
};
std::ostream & operator<<(std::ostream & os, Color const & color);

#endif // COLOR_H_INCLUDED
