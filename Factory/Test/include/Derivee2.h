/** @file Derivee2.h
  *
  * Fournit la définition d'une classe dérivée utilisée pour le test
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#ifndef DERIVEE2_H
#define DERIVEE2_H

#include <Base.h>
#include <ParameterLists.h>


class Derivee2 : public Base
{
    public:
        Derivee2(StringOnlyParam const & pl) : str(std::get<0>(pl)){}
        Derivee2(StringAndColorParam const & pl) : str(std::get<0>(pl)),
                                           color(std::get<1>(pl)){}
        void print()const;
    protected:
    private:
        std::string str;
        Color color;
};

#endif // DERIVEE2_H
