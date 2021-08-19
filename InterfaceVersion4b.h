#ifndef INTERFACEVERSION4B_H
#define INTERFACEVERSION4B_H
#include <functional>
#include <iostream>

using MyFunc = std::function<void(void)>;

template< class Derived >
class BaseLambdaTemplate: private Derived
{
    public:
        void read() { Derived::readFunc();  }
        void write(){ Derived::writeFunc(); }
};

class ChildLambdaTemplate
{
    protected:
        MyFunc readFunc  = [](){ return 253*324;/*std::cout << "Child::read\n" ;*/};
        MyFunc writeFunc = [](){ std::cout << "Child::write\n";};
};

using BaseLambdaT = BaseLambdaTemplate<ChildLambdaTemplate>;

#endif // INTERFACEVERSION4B_H
