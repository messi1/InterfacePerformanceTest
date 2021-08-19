#ifndef INTERFACEVERSION3_H
#define INTERFACEVERSION3_H
#include <iostream>
#include <memory>

template <class Derived>
class BaseCrtp
{
  public:
    long read() { return static_cast<Derived*>(this)->read_Impl(); }

    void write(const long value) { static_cast<Derived*>(this)->write_Impl(value); }
};

class ChildCrtp : public BaseCrtp<ChildCrtp>
{
    friend class BaseCrtp<ChildCrtp>;

  private:
    long read_Impl() const
    {
        return 253 * 324;
        //        std::cout << "Child::read_Impl" << std::endl;
    }

    void write_Impl(const long value) { std::cout << "Child::write_Impl " << value << std::endl; }
};

using BaseChildCrtp = BaseCrtp<ChildCrtp>;

#endif // INTERFACEVERSION3_H
