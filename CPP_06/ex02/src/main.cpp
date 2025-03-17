#include <iostream>
#include <cstdlib>
#include <ctime>

class Base
{
public:
    virtual ~Base() {} // makes class polymorphic
};

class A : public Base
{
public:
    A() { std::cout << "A constructor" << std::endl; }
};
class B : public Base
{
public:
    B() { std::cout << "B constructor" << std::endl; }
};

class C : public Base
{
public:
    C() { std::cout << "C constructor" << std::endl; }
};

Base *generate(void)
{
    std::srand(std::time(0));
    int random = std::rand() % 3;

    switch (random)
    {
    case 0:
        return new A();
    case 1:
        return new B();
    case 2:
        return new C();
    default:
        return NULL;
    }
}

void identify(Base *p)
{
    if (dynamic_cast<A *>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B *>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C *>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base &p)
{
    try
    {
        (void)dynamic_cast<A &>(p);
        std::cout << "A" << std::endl;
        return;
    }
    catch (...){}

    try
    {
        (void)dynamic_cast<B &>(p);
        std::cout << "B" << std::endl;
        return;
    }
    catch (...) {}

    try
    {
        (void)dynamic_cast<C &>(p);
        std::cout << "C" << std::endl;
        return;
    }
    catch (...) {}

    std::cout << "Unknown type" << std::endl;
}

int main()
{
    Base *obj = generate();

    std::cout << "Identify via pointer: ";
    identify(obj);

    std::cout << "Identify via reference: ";
    identify(*obj);

    delete obj;
    return 0;
}