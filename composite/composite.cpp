/* Stupid example of composite pattern */

#include <iostream>
#include <list>

class Component
{
    public:
        virtual void operation() = 0;
        virtual void add(Component *) {}
        virtual void remove(Component *) {}
        virtual bool isComposite() {return false;}
        virtual ~Component() {}
};

class Leaf1: public Component
{
    public:
        virtual void operation() {std::cout<<"operation on leaf 1"<<std::endl;}
};

class Leaf2: public Component
{
    public:
        virtual void operation() {std::cout<<"operation on leaf 2"<<std::endl;}
};

class Composite: public Component
{
    protected:
        std::list<Component*> listComponent;
    public:
        virtual void operation() {
            std::cout<<"operation on composite"<<std::endl;
            for(std::list<Component*>::iterator it=listComponent.begin(); it!=listComponent.end(); it++)
                (*it)->operation();
        }
        
        virtual void add(Component * comp) {listComponent.push_back(comp);}
        
        virtual void remove(Component * comp) {listComponent.remove(comp);}
        
        virtual bool isComposite() {return true;}
        
        virtual ~Composite() {
            for(std::list<Component*>::iterator it=listComponent.begin(); it!=listComponent.end(); it++)
                delete *it;
        }
};

int main()
{
    Composite stuff;
    Composite * subStuff = new Composite;
    subStuff->add(new Leaf2);
    subStuff->add(new Leaf1);
    stuff.add(new Leaf1);
    stuff.add(new Leaf2);
    stuff.add(subStuff);
    stuff.operation();
}
