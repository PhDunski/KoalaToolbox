/** @file Derivee1.h
  *
  * Fournit la définition d'une classe dérivée utilisée pour le test
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#ifndef DERIVEE1_H
#define DERIVEE1_H

#include <Base.h>
#include <ParameterLists.h>

class Derivee1 : public Base
{
    public:
        Derivee1(IntOnlyParam const & pl) : i(std::get<0>(pl)){}
        Derivee1(IntAndColorParam const & pl) : i(std::get<0>(pl)),
                                           color(std::get<1>(pl)){}
        void print() const;
    protected:
    private:
        int i;
        Color color;
};

#endif // DERIVEE1_H
