#ifndef INTERFACEVERSION3B_H
#define INTERFACEVERSION3B_H
#include <iostream>

template <class Derived>
class BaseTemplate
{
  public:
    BaseTemplate(const Derived& der = Derived()) : derived(der) {}

    long read() const { return derived.read(); }

    void write(const long value) { derived.write(value); }

  private:
    Derived derived;
};

class ChildTemplate
{
  public:
    long read() const
    {
        return 253 * 324;
        //        std::cout << "Child::read\n";
    }
    void write(const long value) { std::cout << "Child::write" << value << std::endl; }
};

using BaseTemplateT = BaseTemplate<ChildTemplate>;

#endif // INTERFACEVERSION3B_H
