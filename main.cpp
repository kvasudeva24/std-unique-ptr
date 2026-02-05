#include <memory>
#include "unique_ptr.hpp"
#include <cassert>
#include <memory>
#include <iostream>




int main(){

    test::unique_ptr<int> a(new int(4));
    test::unique_ptr<int> b = test::make_unique<int>(12);

    // a = b; //should throw an error (it does)

    // test::unique_ptr<int> c = a;  //should throw an error (it does)
    assert(*(a.get()) == 4);
    assert(*(b.get()) == 12);

    test::unique_ptr<int> c = std::move(a);

    assert(!(a.get()));
    assert(*(c.get()) == 4);

    c = std::move(b);

    assert(!(a.get()));
    assert(*(c.get()) == 12);
    
    int* released = c.release();
    assert(*released == 12);
    delete released; 

    //need to delete here since we are responsible for the object

    test::unique_ptr<int> d = test::make_unique<int>(12);
    d.reset(new int(44)); //unique ptr does not protest from passing in stack pointers
    assert(*(d.get()) == 44);

    test::unique_ptr<int> e = test::make_unique<int>(100);
    e.swap(d);

    assert(*(d.get()) == 100);
    assert(*(e.get()) == 44);

    std::cout << "\033[32mPassed all test cases\033[0m" << std::endl;

    return 0;
}