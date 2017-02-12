/* Stupid example of strategy pattern */

#include <iostream>

class Strategy
{
    public:
        virtual void execute() = 0;
};

class ConcreteStrategy1: public Strategy
{
    public:
        ConcreteStrategy1() {}
        virtual void execute() {std::cout<<"execute strategy 1..."<<std::endl;}
};

class ConcreteStrategy2: public Strategy
{
    public:
        ConcreteStrategy2() {}
        virtual void execute() {std::cout<<"execute strategy 2..."<<std::endl;}
};

class Context
{
    private:
        Strategy * strategy;
    public:
        Context(Strategy * choice) : strategy(choice) {}
        virtual ~Context() {delete strategy;}
        void execute() {strategy->execute();}
};

int main()
{
    Context context1(new ConcreteStrategy1);
    context1.execute();
    Context context2(new ConcreteStrategy2);
    context2.execute();
}
