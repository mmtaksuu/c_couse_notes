# Contents of the C Programming Chapters

# Lesson 01 : 
    - Types of the programming languages
    - Definition of C language
    - Differences between Imperative and Declerative languages
    - Differences between statically typed and dynamically typed languages

## Lesson 02 :  
    - C standards
    - Compiling a C program
    - Syntax error
    - Run time Error
    - Optimizations made by the compilers
        * Branch prediction
        * Programmers optimizations (const)
    - One's complement and two's complement 
    
## Lesson 03 : 
    - Tokenizing
    - Tokens in C 
        * Keywords
        * Identifiers
        * Constants
        * Operators
        * String Literals
    - Character Sets in C (ASCII)
    - Introduction to C 
    - Data Types in C
        --------------------
        _Bool
        --------------------
        char
        signed char
        unsigned char
        --------------------
        signed short int
        signed short
        short int
        short
        --------------------
        unsigned short int
        unsigned short
        --------------------
        signed int
        int
        signed
        --------------------
        unsigned int
        unsigned
        --------------------
        signed long int
        signed long
        long int
        long
        --------------------
        unsigned long int
        unsigned long
        --------------------
        signed long long int
        signed long long
        long long int
        long long
        --------------------
        unsigned long long int
        unsigned long long
        --------------------

## Lesson 04 :
    - Definition of a variable in C
    - Difference between definition and decleration
    - Name look-up searching
    - Scopes in C
        * File scope
        * Block scope
        * Function Prototype scope
        * Function scope
    - Storage Duration in C
        * Static storage class
        * Automatic storage class
        * Dynamic storage class
    - Name Collision
    
## Lesson 05 :
    - Funtions in C
        * to define a function
        * to call a function
        * to declare a function
    - Syntax and Semantics of C language
    - Defining a function
    - Control Statements of C
        * if statement
          
        * while statement
          do while statement
          for statement
          
        * switch statement
          goto statement
          
        * continue statement
          break statement
          return statement
          
    - Call by value and Call by refrence
    - Return values of funtions in C
        * to discard the return value
        * Test funtions (true or false)
        * functions with return value success information (0 or 1)
        

## Lesson 06 :
    - Funtion Calling
    - Difference between parameter and argument of a funtion
    - C standard library 
    - Constant Literals
        * Integer Constants
        * Floating Constants
    - Types of Constants

## Lesson 07 :
    - Character Literals
    - Escape sequences in C
    - Input and Output Operations in C
        * Formatted Input
            - scanf()
            - fscanf()
            - sscanf() 
        * Formatted Output
            - printf()
            - fprintf()
            - sprintf()
     
## Lesson 08 :
    - Unformatted Input and Output
        * getchar()
        * putchar()
    - Operators in C 
        * unary   operator ( ++, -- )
        * binary  operator ( <, >=  )
        * ternary operator ( ?  :   )
          
        * prefix  ( ++x   )
        * postfix ( x++   )
        * infix   ( x + y )
    - Side Effect
    - Priority of the Operators
    - Table of the Priority Order of the Operators in C

## Table of the Priority Order of the Operators in C
    TABLE
    -------------------------------------------
    1    ()  []   .  ->
    -------------------------------------------
    2    + -  ++ --  ! ~ &  * sizeof  (type)    from right to left precedence
    -------------------------------------------
    3	 * /  %
    -------------------------------------------
    4	  + -
    -------------------------------------------
    5	 >>  <<
    -------------------------------------------
    6     > < >= <=
    -------------------------------------------
    7     ==  !=
    -------------------------------------------
    8      &
    -------------------------------------------
    9      ^
    -------------------------------------------
    10     |
    -------------------------------------------
    11		&&
    -------------------------------------------
    12		||
    -------------------------------------------
    13     ? :                                  from right to left precedence
    -------------------------------------------
    14    = += *= -= /= %=  >>= <<= &= ^=  |=   from right to left precedence
    -------------------------------------------
    15   ,
    -------------------------------------------

## [link](https://github.com/mmtaksuu/c_couse_notes)

``` python
import os
for i in range(5):
    i+=1
```

``` c
int main(){

    return 0;
}
```