/** @file CreationLists.h
  *
  * Fournit les classes permettront de profiter du double dispatch pour la
  * création d'objets concrets
  *
  * Ce fichier fait partie du coeur du projet que je vous présente
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#ifndef CREATIONLISTS_H_INCLUDED
#define CREATIONLISTS_H_INCLUDED
#include <type_traits>
/** Classe de base commune aux listes de paramètres utilisées
  * lors de la création d'objets faisant partie d'une
  * hiérarchie de classe
  *
  * @tparam BaseObject type du pointeur renvoyé. Il s'agit
  * du type de base de l'objet renvoyé
  * @tparam FactoryType type de la fabrique qui sera utilisée
  *
  * @pre FactoryType expose un comportement create susceptible
  * d'accepter tous les spécialisations de ConcreteCretionParameterList
  * pour lesquelles les paramètres template BaseObject et FactoryType
  * correspondent à ceux utilisés pour cette classe
  * @note Cette classe représente la classe de base abstraite
  * des objets visités dans le patron de conception Visitor.
  * @note Le paramètre template joue le rôle du visiteur dans
  * ce patron de conception.
  *
  */
template <typename BaseObject, typename FactoryType>
class AbstractCreationList{
public:
    virtual BaseObject * accept(FactoryType const & ) const = 0;
protected:
    AbstractCreationList(){}
    ~AbstractCreationList(){}
};
/** Classe concrete représentant la liste des paramètres utilisé
  * lors de la création d'objets faisant partie d'une
  * hiérarchie de classe
  *
  * @tparam BaseObject type du pointeur renvoyé. Il s'agit
  * du type de base de l'objet renvoyé
  * @tparam FactoryType type de la fabrique qui sera utilisée
  * @tparam ObjectTrait trait utilisé pour déterminer le type
  * concret devant être créé.
  * @tparam ParameterList type de liste de paramètres à utiliser
  * pour la construction de l'objet demandé
  *
  * @pre FactoryType expose un comportement create susceptible
  * d'accepter tous les spécialisations de ConcreteCretionParameterList
  * pour lesquelles les paramètres template BaseObject et FactoryType
  * correspondent à ceux utilisés pour cette classe
  * @pre ObjectTrait propose un alias de type nommé value_type
  * représentant le type réel de l'objet à créer
  *
  */
template <typename BaseObject,
          typename FactoryType,
          typename ObjectTrait,
          typename ParameterList>
class ConcreteCretionParameterList :
          public ParameterList,
          public AbstractCreationList<BaseObject, FactoryType>{
public:
    ConcreteCretionParameterList(ParameterList const & list):
        ParameterList(list){}
    BaseObject * accept(FactoryType const & factory) const;
};

#endif // CREATIONLISTS_H_INCLUDED
