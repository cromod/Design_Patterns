/* Stupid example of factory method with a parameter */

#include <iostream>
#include <string>

class Product
{
    public:
        virtual ~Product() {}
        virtual void what() {std::cout<<"default product"<<std::endl;}
};

class NewProduct: public Product
{
    public:
        virtual void what() {std::cout<<"new product"<<std::endl;}
};

class OldProduct: public Product
{
    public:
        virtual void what() {std::cout<<"old product"<<std::endl;}
};

class ParamFactory
{
    public:
        virtual Product * makeProduct(std::string productId) const {
            Product * result = nullptr;
            if(productId == "NEW") {
                result = new NewProduct();
            }
            else if(productId == "OLD") {
                result = new OldProduct();
            }
            else {
                result = new Product();
            }
            return result;
        }
};

int main()
{
    ParamFactory factory;
    
    Product * product1 = factory.makeProduct("NEW");
    Product * product2 = factory.makeProduct("OLD");
    Product * product3 = factory.makeProduct("fsdqfq");
    
    product1->what();
    product2->what();
    product3->what();
    
    delete product1;
    delete product2;
    delete product3;
}