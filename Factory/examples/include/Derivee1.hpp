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
#ifndef FACTORY_EXAMPLE_DERIVEE1_HPP_INCLUDED
#define FACTORY_EXAMPLE_DERIVEE1_HPP_INCLUDED

#include <Base.hpp>
#include <Color.hpp>

class Derivee1 : public Base
{
    public:
        Derivee1(int i) :Derivee1{i, Color{}}{}
        Derivee1(int i, Color const & c) : i_{i},
                                           color_{c}{}
        void print() const final override;
    protected:
    private:
        int i_;
        Color color_;
};

#endif // FACTORY_EXAMPLE_DERIVEE1_HPP_INCLUDED
