/** @file Base.h
  *
  * Fournit la définition de la classe de base utilisée pour le test
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#ifndef FACTORY_EXAMPLE_BASE_HPP_INCLUDED
#define FACTORY_EXAMPLE_BASE_HPP_INCLUDED


class Base
{
    public:
        Base();
        Base(Base const &) = delete;
        Base & operator=(Base const &)= delete;
        virtual ~Base();
        virtual void print() const = 0;
    protected:
    private:
};

#endif // FACTORY_EXAMPLE_BASE_HPP_INCLUDED
