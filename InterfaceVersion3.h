#ifndef INTERFACEVERSION3_H
#define INTERFACEVERSION3_H
#include <iostream>
#include <memory>

template< class Derived >
class BaseCrtp {
public:
    void read() {
        static_cast< Derived * >( this )->read_Impl();
    }

    void write() {
        static_cast< Derived * >( this )->write_Impl();
    }
};

class ChildCrtp: public BaseCrtp< ChildCrtp > {
    friend class BaseCrtp< ChildCrtp >;
private:
    int  read_Impl() {
       return 253*324;
//        std::cout << "Child::read_Impl" << std::endl;
    }

    void write_Impl() {
//        std::cout << "Child::write_Impl" << std::endl;
    }
};

using BaseChildCrtp = BaseCrtp<ChildCrtp>;

#endif // INTERFACEVERSION3_H
