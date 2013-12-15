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
#ifndef BASE_H
#define BASE_H


class Base
{
    public:
        Base();
        virtual ~Base();
        virtual void print() const = 0;
    protected:
    private:
};

#endif // BASE_H
