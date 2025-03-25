#include "MutantStack.hpp"
#include <list>

void test_from_main()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

void test_from_main_with_list()
{
    std::list<int> lst;

    lst.push_back(5);
    lst.push_back(17);
    std::cout << lst.back() << std::endl;

    lst.pop_back();
    std::cout << lst.size() << std::endl;

    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);

    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
}

void test_with_mutant_stack_basic()
{
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);
    
    std::cout << "Top element: " << mstack.top() << std::endl;  // Expected: 30
    std::cout << "Stack size: " << mstack.size() << std::endl;  // Expected: 3
    
    mstack.pop();
    std::cout << "Stack size after pop: " << mstack.size() << std::endl;  // Expected: 2
}

void test_with_mutant_stack_iterator_reverse()
{
    MutantStack<int> mstack;
    mstack.push(1);
    mstack.push(2);
    mstack.push(3);
    mstack.push(4);
    
    std::cout << "Iterating in reverse:" << std::endl;
    MutantStack<int>::iterator it = mstack.end();
    --it;
    
    while (it != mstack.begin()) {
        std::cout << *it << std::endl;  // Expected: 4, 3, 2
        --it;
    }
    std::cout << *it << std::endl;  // Expected: 1
}

void test_with_mutant_stack_copy_constructor()
{
    MutantStack<int> mstack1;
    mstack1.push(10);
    mstack1.push(20);
    mstack1.push(30);
    
    MutantStack<int> mstack2(mstack1);
    
    std::cout << "Top of copied stack: " << mstack2.top() << std::endl;  // Expected: 30
    std::cout << "Size of copied stack: " << mstack2.size() << std::endl;  // Expected: 3
}

void test_with_mutant_stack_assignment_operator()
{
    MutantStack<int> mstack1;
    mstack1.push(50);
    mstack1.push(60);
    
    MutantStack<int> mstack2;
    mstack2 = mstack1;
    
    std::cout << "Top of assigned stack: " << mstack2.top() << std::endl;  // Expected: 60
    std::cout << "Size of assigned stack: " << mstack2.size() << std::endl;  // Expected: 2
}

void test_with_mutant_stack_large_data()
{
    MutantStack<int> mstack;
    
    for (int i = 1; i <= 100; ++i) {
        mstack.push(i);
    }
    
    std::cout << "Stack size after pushing 100 elements: " << mstack.size() << std::endl;  // Expected: 10000
    
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void test_with_mutant_stack_push_pop()
{
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(10);
    mstack.push(15);
    
    mstack.pop();
    mstack.push(20);
    mstack.push(25);
    
    std::cout << "Final top element: " << mstack.top() << std::endl;  // Expected: 25
    std::cout << "Final size: " << mstack.size() << std::endl;  // Expected: 4
}


int main()
{
    std::cout << "---- Testing with MutantStack ----" << std::endl;
    test_from_main();

    std::cout << "-------- Testing with std::list ----" << std::endl;
    test_from_main_with_list();

    std::cout << "---- Testing with MutantStack basic ----" << std::endl;
    test_with_mutant_stack_basic();

    std::cout << "---- Testing with MutantStack iterator reverse ----" << std::endl;
    test_with_mutant_stack_iterator_reverse();

    std::cout << "---- Testing with MutantStack copy constructor ----" << std::endl;
    test_with_mutant_stack_copy_constructor();

    std::cout << "---- Testing with MutantStack assignment operator ----" << std::endl;
    test_with_mutant_stack_assignment_operator();

    std::cout << "---- Testing with MutantStack large data ----" << std::endl;
    test_with_mutant_stack_large_data();

    std::cout << "---- Testing with MutantStack push pop ----" << std::endl;
    test_with_mutant_stack_push_pop();
    return 0;
}
