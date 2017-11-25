/** @file main.cpp
  *
  * Ce fichier permet de tester les classes de création d'objet au départ
  * de listes de paramètres à transmettre au constructeur
  * @author koala01
  * @version 1.0
  * @date 2013/12/15
  */
#include <Derivee1.hpp>
#include <Derivee2.hpp>
#include <Color.hpp>
#include <Factory.hpp>
#include <memory>
using namespace std;
int main()
{
    using ptr_t = std::unique_ptr<Base>;
    /* Créons quelques listes de paramètres à transmettre aux différent constructeurs */
    Ktb::Tools::Factory<Base> factory;
    /* Construisons un objet de chaque type */
    ptr_t ptr_1{factory.template create<Derivee1>(12)};
    ptr_t ptr_2{factory.template create<Derivee1>(12, Color{0x00,0x44,0x66})};
    ptr_t ptr_3{factory.template create<Derivee2>("salut")};
    ptr_t ptr_4{factory.template create<Derivee2>("hello", Color{0x00,0x44,0x66})};
    /* affichons le tout pour nous assurer que cela fonctionne */
    ptr_1.get()->print();
    ptr_2.get()->print();
    ptr_3.get()->print();
    ptr_4.get()->print();
    return 0;
}
