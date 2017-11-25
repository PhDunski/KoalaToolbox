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
#ifndef FACTORY_EXAMPLE_DERIVEE2_HPP_INCLUDED
#define FACTORY_EXAMPLE_DERIVEE2_HPP_INCLUDED

#include <Base.hpp>
#include <string>
#include <Color.hpp>

class Derivee2 : public Base
{
    public:
        Derivee2(std::string const & str) : Derivee2{str, Color{}}{}
        Derivee2(std::string const & str, Color const & c):
            str_{str},color_{c}{}
        void print()const final override;
    protected:
    private:
        std::string str_;
        Color color_;
};

#endif // FACTORY_EXAMPLE_DERIVEE2_HPP_INCLUDED
