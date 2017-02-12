/* Stupid example of class adapter */

#include <iostream>

class Adaptee1
{
  public:
    void method1() {std::cout<<"call method1 of Adaptee1"<<std::endl;}
};

class Adaptee2
{
  public:
    void method2() {std::cout<<"call method2 of Adaptee2"<<std::endl;}
};

class Adaptor: public Adaptee1, public Adaptee2 //can't be used with derived class of Adaptee1 or 2
{
  public:
    void methodA() {method1(); method2();}
};

int main()
{
  Adaptor stuff;
  stuff.methodA();
}
