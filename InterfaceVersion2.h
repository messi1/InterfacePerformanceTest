#ifndef INTERFACEVERSION2_H
#define INTERFACEVERSION2_H
#include <iostream>
#include <memory>

class BasePrivateVirtual
{
public:
 void read() { read_impl(); }
 void write() { write_impl();}

private:
 virtual int read_impl() = 0;
 virtual void write_impl() = 0;
};

class ChildPrivateVirtual : public BasePrivateVirtual
{

private:
 virtual int read_impl() override
 {
        return 253*324;
//  std::cout << "Child::read_impl" << std::endl;
 }

 virtual void write_impl() override
 {
  std::cout << "Child::read_impl" << std::endl;
 }
};

#endif // INTERFACEVERSION2_H
