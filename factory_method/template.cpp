/* Stupid example of factory method with template */

#include <iostream>

class Product
{
    public:
        virtual ~Product() {}
        virtual void what() {std::cout<<"product"<<std::endl;}
};

class AnotherProduct: public Product
{
    public:
        virtual void what() {std::cout<<"concrete product"<<std::endl;}
};

template <class P>
class GenericFactory
{
    public:
        virtual P * makeProduct() const {return new P();}
};

int main()
{
    GenericFactory<Product> factory;
    GenericFactory<AnotherProduct> concrete_factory;
    
    Product * product1 = factory.makeProduct();
    Product * product2 = concrete_factory.makeProduct();
    
    product1->what();
    product2->what();
    
    delete product1;
    delete product2;
}