/* Stupid example of template method */

#include <iostream>

class AbstractClass
{
  public:
    void templateMethod()
    {
      method1();
      method2();
    }
    virtual void method1() = 0;
    virtual void method2() = 0;
};

class ConcreteClass: public AbstractClass
{
  virtual void method1() {std::cout<<"a implementation of method1"<<std::endl;}
  virtual void method2() {std::cout<<"a implementation of method2"<<std::endl;}
};

int main()
{
  ConcreteClass stuff;
  stuff.templateMethod();
}
