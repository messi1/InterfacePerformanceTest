#ifndef INTERFACEVERSION4B_H
#define INTERFACEVERSION4B_H
#include <functional>
#include <iostream>

using MyFuncRead = std::function<long(void)>;
using MyFuncWrite = std::function<void(const long)>;

template <class Derived>
class BaseLambdaTemplate : private Derived
{
  public:
    long read() { return Derived::readFunc(); }
    void write() { Derived::writeFunc(); }
};

class ChildLambdaTemplate
{
  protected:
    MyFuncRead readFunc = []() {
        return 253 * 324; /*std::cout << "Child::read\n" ;*/
    };
    MyFuncWrite writeFunc = [](const long value) { std::cout << "Child::write " << value << std::endl; };
};

using BaseLambdaT = BaseLambdaTemplate<ChildLambdaTemplate>;

#endif // INTERFACEVERSION4B_H
