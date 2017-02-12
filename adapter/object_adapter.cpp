/* Object adapter that can be used for
   every derived class of Adaptee */

#include <iostream>

class Adaptee
{
  public:
    virtual void method() {std::cout<<"call method of Adaptee"<<std::endl;}
};

class DerivedAdaptee: public Adaptee
{
  public:
    virtual void method() {std::cout<<"call method of DerivedAdaptee"<<std::endl;}
};

class Adaptor
{
  public:
    Adaptee* adapteePtr; //this pointer enables to use polymorphism in methodA
    void methodA() {adapteePtr->method();}
    
    Adaptor(Adaptee* ptr): adapteePtr(ptr) {}
    virtual ~Adaptor() {delete adapteePtr;}
};

int main()
{
  Adaptor stuff1(new DerivedAdaptee());
  stuff1.methodA();
  
  Adaptor stuff2(new Adaptee());
  stuff2.methodA();
}
