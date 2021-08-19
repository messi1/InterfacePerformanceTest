#ifndef INTERFACEVERSION4_H
#define INTERFACEVERSION4_H
#include <functional>
#include <iostream>
#include <memory>

using MyFunc = std::function<void(void)>;

class BaseLambda
{
  public:
    void read(){ m_readFunc(); }
    void write(){ m_writeFunc(); }
  protected:
    BaseLambda( MyFunc readFunc, MyFunc writeFunc) : m_readFunc(readFunc), m_writeFunc(writeFunc)
    {}
    MyFunc m_readFunc;
    MyFunc m_writeFunc;
};

class ChildLambda : public BaseLambda
{
  public:
    ChildLambda() : BaseLambda([](){ ChildLambda::read_impl();}, [](){ ChildLambda::write_impl();}) { }
  private:
    static int read_impl(){ return 253*324;/*std::cout << "Child::read\n";*/ }
    static void write_impl(){ std::cout << "Child::write\n"; }
};


#endif // INTERFACEVERSION4_H
