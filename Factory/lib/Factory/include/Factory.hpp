#ifndef KTB_FACTORY_HPP_INCLUDED
#define KTB_FACTORY_HPP_INCLUDED
namespace Ktb{
namespace Tools{
template <typename Base>
class Factory{
public:
    template <typename Derived,
              typename ... Args>
    static Base * create(Args ... args){
        return new Derived{args ...};
    }
};
} // namepsace Tools
} //namespace Ktb
#endif // KTB_FACTORY_HPP_INCLUDED
