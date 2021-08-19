#ifndef INTERFACEVERSION1_H
#define INTERFACEVERSION1_H

#include <iostream>
#include <memory>


class BasePublicVirtual
{
public:
    virtual int read()  = 0;
    virtual void write() = 0;
};

class ChildPublicVirtual final :  public BasePublicVirtual
{
public:
    virtual int read() final
    {
        return 253*324;
//       std::cout << "Child::read_impl" << std::endl;
    }

    virtual void write() final
    {
       std::cout << "Child::read_impl" << std::endl;
    }
};

#endif // INTERFACEVERSION1_H
