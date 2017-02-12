/* Stupid example of iterator */

class Item;//we can use template too

class Iterator
{
  public:
    virtual void begin() = 0;
    virtual Item & currentItem() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
};

class Agregate
{
  public:
    virtual Iterator * createIterator() = 0;
};

class ConcreteAgregate: public Agregate
{
  public:
    ConcreteAgregate() {}
    virtual ~ConcreteAgregate() {}
    virtual Iterator * createIterator();
};

class ConcreteIterator: public Iterator
{
  public:
    ConcreteIterator(ConcreteAgregate * ptr): agregate(ptr) {}
    ~ConcreteIterator() {delete agregate;}
    virtual void begin() {}
    virtual Item & currentItem() {}
    virtual void next() {}
    virtual bool isDone() {}
  private:
    ConcreteAgregate * agregate;
};

Iterator * ConcreteAgregate::createIterator()
{
  return new ConcreteIterator(this);
}

int main()
{
  ConcreteAgregate agregate;
  Iterator * iterator = agregate.createIterator();
}
