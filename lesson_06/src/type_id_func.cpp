/**
 * @file    : LESSON_6 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 23 / May / 2020
 * @code    : type_id_func.cpp file
 * @details : 
 */


#include <iostream>

int main()
{
    using namespace std;

    cout << typeid(76).name()      << "\n";
    cout << typeid(0x1ac4).name()  << "\n";
    cout << typeid(0x1ac4L).name() << "\n";
    cout << typeid(01234u).name()  << "\n";
    cout << typeid(45UL).name()    << "\n";
    cout << typeid(45ULL).name()   << "\n";

    cout << typeid(2147483647).name() << "\n"; //int
    cout << typeid(2147483650).name() << "\n"; //unsigned long
    cout << typeid(0x80000002).name() << "\n";  //unsigned int

    return 0;
}