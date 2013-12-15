/** @file main.cpp
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#include <Base.h>
#include <ParameterLists.h>
#include <Factory.h>
#include <DerivedAliases.h>
using namespace std;

int main()
{
    /* Créons quelques listes de paramètres à transmettre aux différent constructeurs */
    IntOnlyParam paramOneInt(55);
    IntAndColorParam paramIntAndColor(12, Color(5,5,5));
    StringOnlyParam paramOneString("hello");
    StringAndColorParam paramStringAndColor("world", Color(10,10,10));
    Factory factory;
    /* Construisons un objet de chaque type */
    Base * ptr_1 = factory.create(Derivee1ListOnlyInt(paramOneInt));
    Base * ptr_2 = factory.create(Derivee1ListIntAndColor(paramIntAndColor));
    Base * ptr_3 = factory.create(Derivee1ListOnlyString(paramOneString));
    Base * ptr_4 = factory.create(Derivee1ListStringAndColor(paramStringAndColor));
    /* affichons le tout pour nous assurer que cela fonctionne */
    ptr_1->print();
    ptr_2->print();
    ptr_3->print();
    ptr_4->print();
    /* et faisons le ménage */
    delete ptr_1;
    delete ptr_2;
    delete ptr_3;
    delete ptr_4;
    return 0;
}
