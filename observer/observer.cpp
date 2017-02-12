 /* Stupid example of observer pattern */

#include <iostream>
#include <set>

using namespace std;

class Observer
{
    public:
        virtual ~Observer() {}
        virtual void update() = 0;
};

class ConcreteObserver1: public Observer
{
    public:
        virtual void update() {cout<<"concrete observer 1"<<endl;}
};

class ConcreteObserver2: public Observer
{
    public:
        virtual void update() {cout<<"concrete observer 2"<<endl;}
};

class Subject
{
    private:
        set<Observer*> listObserver;
    public:
        virtual ~Subject() {
            for(set<Observer*>::iterator it=listObserver.begin(); it!=listObserver.end(); it++)
                delete *it;
        }
        
        void addObserver(Observer * obs) {listObserver.insert(obs);}
        
        void removeObserver(Observer * obs) {
            listObserver.erase(listObserver.find(obs));
            delete obs;
        }
        
        void notify() {
            for(set<Observer*>::iterator it=listObserver.begin(); it!=listObserver.end(); it++)
                (*it)->update();
        }
};

int main()
{
    Observer * obs1 = new ConcreteObserver1;
    Observer * obs2 = new ConcreteObserver2;
    
    Subject subject;
    subject.addObserver(obs1);
    subject.addObserver(obs2);
    
    subject.notify();
    subject.removeObserver(obs1);
    subject.notify();
}