#ifndef INTERFACEVERSION3B_H
#define INTERFACEVERSION3B_H
#include <iostream>

template<class Derived>
class BaseTemplate
{
public:
  BaseTemplate(const Derived& der = Derived()) : derived(der) {}

  void read()
  {
    derived.read();
  }

  void write()
  {
      derived.write();
  }

private:
  Derived derived;
};

class ChildTemplate {
public:
    int read()
    {
        return 253*324;
//        std::cout << "Child::read\n";
    }
    void write()
    {
        std::cout << "Child::write\n";
    }
};

using BaseTemplateT = BaseTemplate<ChildTemplate>;

//int main( void ) {
//    Base<Child>bla;

//    bla.read();
//    bla.write();

//  return 0;
//}
#endif // INTERFACEVERSION3B_H
