/** @file CoreImplementation.h
  *
  * Fournit l'implémentation des fonctions membre des classes template
  * qu'il est préférable de ne pas implémenter directement dans les
  * fonctions dont elles sont issues.
  *
  * Le comportement des fonctions définies dans ce fichier fait qu'elles
  * ne peuvent se contenter d'une déclaration anticipée des paramètres template
  * qu'elles utilisent:
  *
  * La fonction membre de ObjectCreator a en effet besoin de connaître la définition
  * complète du type d'objet concret qu'elle essaye de créer alors que la fonction
  * membre de ConcreteCretionParameterList a besoin de la définition complète du type
  * de la fabrique utilisée.
  *
  * Ce fichier doit donc être inclus en dernier lieu exlusivement dans le fichier dans
  * lequel on procédera à l'instanciation explicite (de préférence dans le fichier
  * d'implémentation de la fabrique utilisée
  *
  * Ce fichier fait partie du coeur du projet que je vous présente
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#ifndef OBJECT_CREATOR_INL_H_INCLUDED
#define OBJECT_CREATOR_INL_H_INCLUDED
template <typename BaseObject,
          typename ObjectTrait,
          typename List>
BaseObject * ObjectCreator<BaseObject, ObjectTrait,List>::create(List const & list) const{
    return new value_type(list);
}
template <typename BaseObject,
          typename FactoryType,
          typename ObjectTrait,
          typename ParameterList>
BaseObject * ConcreteCretionParameterList<BaseObject, FactoryType, ObjectTrait, ParameterList>::
             accept(FactoryType const & factory) const{
    return factory.create( *this);
}
#endif // OBJECT_CREATOR_INL_H_INCLUDED
