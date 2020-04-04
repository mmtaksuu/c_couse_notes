

#include <iostream>



int main()
{
    int a[10];
    int x = 5;
    int *ptr = &x;

    std::cout << "x     :" << typeid(x).name()      << std::endl;
    std::cout << "&x    :" << typeid(&x).name()     << std::endl;
    std::cout << "a     :" << typeid(a).name()      << std::endl;
    std::cout << "a[0]  :" << typeid(a[0]).name()   << std::endl;
    std::cout << "&a[0] :" << typeid(&a[0]).name()  << std::endl;
    std::cout << "ptr   :" << typeid(ptr).name()    << std::endl;
    std::cout << "*ptr  :" << typeid(*ptr).name()   << std::endl;
    std::cout << "&ptr  :" << typeid(&ptr).name()   << std::endl;

    return 0;
}
