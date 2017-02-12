/* Stupid example of interpreter pattern */

#include <iostream>
#include <list>

using namespace std;

class Context {};

class AbstractExpression
{
    public:
        virtual void interpret(Context context) = 0;
        virtual void add(AbstractExpression * exp) {}
};

class TerminalExpression: public AbstractExpression
{
    public:
        TerminalExpression() {}
        virtual ~TerminalExpression() {}
        virtual void interpret(Context context) {cout<<"Interpret terminal expression..."<<endl;}
};

class NonTerminalExpression: public AbstractExpression
{
    protected:
        list<AbstractExpression*> listExp; // agregation of Expression instances
    public:
        NonTerminalExpression() {}
        virtual ~NonTerminalExpression() {}
        virtual void interpret(Context context) {cout<<"Interpret non terminal expression..."<<endl;} // must handle listExp
};

class CompositeExpression: public AbstractExpression
{
    protected:
        list<AbstractExpression*> syntaxTree;
    public:
        CompositeExpression(): syntaxTree() {}
        virtual ~CompositeExpression()
        {
            while(!syntaxTree.empty())
            {
                delete syntaxTree.back();
                syntaxTree.pop_back();
            }
        }
        virtual void interpret(Context context)
        {
            for(list<AbstractExpression*>::iterator it=syntaxTree.begin(); it!=syntaxTree.end(); ++it) (*it)->interpret(context);
        }
        virtual void add(AbstractExpression * exp) {syntaxTree.push_back(exp);}
};

int main()
{
    Context context;
    CompositeExpression tree;

    tree.add(new TerminalExpression());
    tree.add(new NonTerminalExpression());
    tree.add(new NonTerminalExpression());

    tree.interpret(context);
}
