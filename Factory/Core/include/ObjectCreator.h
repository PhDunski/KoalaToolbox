/** @file ObjectCreator.h
  *
  * Fournit la classe qui prendra effectivement en charge la création des
  * différents objets
  *
  * Ce fichier fait partie du coeur du projet que je vous présente
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#ifndef OBJECTCREATOR_H_INCLUDED
#define OBJECTCREATOR_H_INCLUDED
template <typename BaseObject,
          typename ObjectTrait,
          typename List>
struct ObjectCreator{
    using value_type = typename ObjectTrait::value_type;
    BaseObject * create(List const & list) const;
};


#endif // OBJECTCREATOR_H_INCLUDED
