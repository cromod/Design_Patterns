/* Stupid example of abstract factory */

#include <iostream>
#include <utility>

class ProductA
{
    public:
        virtual ~ProductA() {}
        virtual void makeSomething() = 0;
};

class ProductA1: public ProductA
{
    public:
        virtual void makeSomething() {std::cout<<"Product A1"<<std::endl;}
};

class ProductA2: public ProductA
{
    public:
        virtual void makeSomething() {std::cout<<"Product A2"<<std::endl;}
};

class ProductB
{
    public:
        virtual ~ProductB() {}
        virtual void makeSomethingElse() = 0;
};

class ProductB1: public ProductB
{
    public:
        virtual void makeSomethingElse() {std::cout<<"Product B1"<<std::endl;}
};

class ProductB2: public ProductB
{
    public:
        virtual void makeSomethingElse() {std::cout<<"Product B2"<<std::endl;}
};

typedef std::pair<ProductA*,ProductB*> Products;

class AbstractFactory
{
    public:
        virtual ProductA * makeProductA() const = 0;
        virtual ProductB * makeProductB() const = 0;
        // using template method pattern (not mandatory)
        Products makeProducts() const {
            return std::make_pair(makeProductA(), makeProductB());
        }
};

class ConcreteFactory1: public AbstractFactory
{
    public:
        virtual ProductA * makeProductA() const {return new ProductA1();}
        virtual ProductB * makeProductB() const {return new ProductB1();}
};

class ConcreteFactory2: public AbstractFactory
{
    public:
        virtual ProductA * makeProductA() const {return new ProductA2();}
        virtual ProductB * makeProductB() const {return new ProductB2();}
};

int main()
{
    ConcreteFactory1 factory1;
    ConcreteFactory2 factory2;
    
    Products products1 = factory1.makeProducts();
    Products products2 = factory2.makeProducts();
    
    products1.first->makeSomething();
    products1.second->makeSomethingElse();
    products2.first->makeSomething();
    products2.second->makeSomethingElse();
    
    delete products1.first;
    delete products1.second;
    delete products2.first;
    delete products2.second;
}