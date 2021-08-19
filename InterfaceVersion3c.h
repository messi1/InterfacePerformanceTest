#ifndef INTERFACEVERSION3C_H
#define INTERFACEVERSION3C_H
#include <iostream>

template< class Derived >
class BaseTemplate2: private Derived {
public:
    void read() {
         Derived::read_Impl();
    }

    void write() {
        Derived::write_Impl();
    }
};

class ChildTemplate2 {
protected:
    int  read_Impl() {
        return 253*324;
//        std::cout << "Child::read_Impl" << std::endl;
    }

    void write_Impl() {
        std::cout << "Child::write_Impl" << std::endl;
    }
};

using BaseTemplate2T = BaseTemplate2<ChildTemplate2>;

#endif // INTERFACEVERSION3C_H
