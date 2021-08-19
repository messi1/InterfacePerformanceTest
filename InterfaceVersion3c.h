#ifndef INTERFACEVERSION3C_H
#define INTERFACEVERSION3C_H
#include <iostream>

template <class Derived>
class BaseTemplate2 : private Derived
{
  public:
    long read() const { return Derived::read_Impl(); }

    void write(const long value) { Derived::write_Impl(value); }
};

class ChildTemplate2
{
  protected:
    long read_Impl() const
    {
        return 253 * 324;
        //        std::cout << "Child::read_Impl" << std::endl;
    }

    void write_Impl(const long value) { std::cout << "Child::write_Impl " << value << std::endl; }
};

using BaseTemplate2T = BaseTemplate2<ChildTemplate2>;

#endif // INTERFACEVERSION3C_H
