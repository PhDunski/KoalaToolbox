/** @file Factory.h
  *
  * Fournit la définition de la fabrique utilisée pour le test
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#ifndef FACTORY_H
#define FACTORY_H
#include <ObjectCreator.h>
#include <CreationLists.h>
class Factory;
class Base;
template <typename ObjectTrait,
          typename List>
using BaseParameterList = ConcreteCretionParameterList<Base,
                                                      Factory,
                                                      ObjectTrait,
                                                      List>;

template <typename ObjectTrait,
          typename List>
using BaseCreator =  ObjectCreator<Base,ObjectTrait,List>;
class Factory
{
    public:
        template <typename ObjectTrait, typename List>
        Base * create(BaseParameterList<ObjectTrait, List> const & list) const{
            return  ObjectCreator<Base,ObjectTrait,List>().create(list);
        }
    protected:
    private:
};

#endif // FACTORY_H
