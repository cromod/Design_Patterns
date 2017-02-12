/* Stupid example of singleton pattern */

#include <cstddef>

class Singleton
{
    private:
        static Singleton * singleInstance;
    protected:
        Singleton();
        virtual ~Singleton();
    public:
        static Singleton * getInstance();
        static void freeInstance();
        void display();
};

Singleton * Singleton::singleInstance = nullptr;

Singleton::Singleton() {}

Singleton::~Singleton() {}

Singleton * Singleton::getInstance()
{
    if(singleInstance == nullptr) singleInstance = new Singleton();
    return singleInstance;
}

void Singleton::freeInstance()
{
    if (singleInstance != nullptr)
    {
        delete singleInstance;
        singleInstance = nullptr;
    }
}

int main()
{
    Singleton::getInstance();
    Singleton::freeInstance();
}
