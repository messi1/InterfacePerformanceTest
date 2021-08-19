#ifndef INTERFACEVERSION1_H
#define INTERFACEVERSION1_H

#include <iostream>
#include <memory>

class BasePublicVirtual
{
  public:
    virtual long read() const = 0;
    virtual void write(const long value) = 0;
};

class ChildPublicVirtual final : public BasePublicVirtual
{
  public:
    virtual long read() const final
    {
        return 253 * 324;
        //       std::cout << "Child::read_impl" << std::endl;
    }

    virtual void write(const long value) final { std::cout << "Child::read_impl: " << value << std::endl; }
};

#endif // INTERFACEVERSION1_H
