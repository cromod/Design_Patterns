/* Stupid example of default factory method */

#include <iostream>

class Product
{
    public:
        virtual ~Product() {}
        virtual void what() {std::cout<<"product"<<std::endl;}
};

class ConcreteProduct: public Product
{
    public:
        virtual void what() {std::cout<<"concrete product"<<std::endl;}
};

class Factory
{
    public:
        virtual Product * makeProduct() const {return new Product();}
};

class ConcreteFactory: public Factory
{
    public:
        virtual Product * makeProduct() const {return new ConcreteProduct();}
};

int main()
{
    Factory factory;
    ConcreteFactory concrete_factory;
    
    Product * product1 = factory.makeProduct();
    Product * product2 = concrete_factory.makeProduct();
    
    product1->what();
    product2->what();
    
    delete product1;
    delete product2;
}