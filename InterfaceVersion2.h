#ifndef INTERFACEVERSION2_H
#define INTERFACEVERSION2_H
#include <iostream>
#include <memory>

class BasePrivateVirtual
{
  public:
    long read() const { return read_impl(); }
    void write(const long value) { write_impl(value); }

  private:
    virtual long read_impl() const = 0;
    virtual void write_impl(const long value) = 0;
};

class ChildPrivateVirtual : public BasePrivateVirtual
{
  private:
    virtual long read_impl() const override
    {
        return 253 * 324;
        //  std::cout << "Child::read_impl" << std::endl;
    }

    virtual void write_impl(const long value) override
    {
        std::cout << "Child::read_impl " << value << std::endl;
    }
};

#endif // INTERFACEVERSION2_H
