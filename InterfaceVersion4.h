#ifndef INTERFACEVERSION4_H
#define INTERFACEVERSION4_H
#include <functional>
#include <iostream>
#include <memory>

using MyFuncRead = std::function<long(void)>;
using MyFuncWrite = std::function<void(const long)>;

class BaseLambda
{
  public:
    long read() { return m_readFunc(); }
    void write(const long value) { m_writeFunc(value); }

  protected:
    BaseLambda(MyFuncRead readFunc, MyFuncWrite writeFunc) : m_readFunc(readFunc), m_writeFunc(writeFunc) {}
    MyFuncRead m_readFunc;
    MyFuncWrite m_writeFunc;
};

class ChildLambda : public BaseLambda
{
  public:
    ChildLambda()
        : BaseLambda([]() { return ChildLambda::read_impl(); },
                     [](const long value) { ChildLambda::write_impl(value); })
    {}

  private:
    static long read_impl() { return 253 * 324; /*std::cout << "Child::read\n";*/ }
    static void write_impl(const long value) { std::cout << "Child::write " << value << std::endl; }
};

#endif // INTERFACEVERSION4_H
