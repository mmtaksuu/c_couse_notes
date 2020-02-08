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


## Lesson 09 :
    - Maximum munch ( int z = x+++y; )
    - Comparison Operators ( > >= < <= == != )
    - Logic Operators ( ! && || )
    - Assigment Operators ( = += -= *= /= %= &= |= ^= <<= >>= )
    - Undifined Behaviour
    - Implementation Defined
    - Implementation Specified
    
## Lesson 10 :
    - Squence Points in C  
        1) End of the each statement ( exp; )
        2) exp1 && exp2
        3) exp1 || exp2
        4) * exp ? exp1 : exp2
        5) exp1, exp2
        6) if (exp++)
    - Comma Operators ( , )
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
    
    
## Lesson 11 :
    - Else-if statement
    - Redundancy if
    - Test Functions
    - Clamp expression
    - Mersenne Primes
    - Standard ctype.h library funtions
        1) isupper(ch)
        2) islower(ch)
        3) isalpha(ch)
        4) isdigit(ch)
        4) isalnum(ch)
        5) isxdigit(ch)
        6) ispunct(ch)
        7) isspace(ch)
        8) isblank(ch)
        9) isprint(ch)
        10) isgraph(ch)
        11) iscntrl(ch)
    - Ternary Operator ( ? : )
    
## Lesson 12 :
    - Loop statements in C
        * while loop
    - How to get out of a loop in C ? 
        1) With a false control statement 
        2) return statement
        3) break statement 
        4) goto statement 
        5) exit / quick_exit / abort
    - break statement
    - do while loop
    - continue statement
    
## Lesson 13 :
    - For loop
    - For - while relationship
    - Infinite loop ( for(;;), for(;1;), while(1) )
    - Nested Loops
    - Function Prototypes or Decleration


## Lesson 14 :
    - Function prototype decleration
    - C seperate compilation model ( .c file and .h file )
    - Header files
    - Preprecessor Directives
        #  //null directive
        #include
        #define
        #undef
        #if
        #endif
        #else
        #elif
        #ifdef
        #ifndef
        #line
        #error
        #pragma
    - Object-like Macros


## Lesson 15 :
    - Funtion-like Macros
    - Macros versus Funtions
    - Preprecessor Operators
        1) #    stringification (stringizing)
        2) ##   token-pasting
        3) defined operator

## Lesson 16 :    
    - Conditional Compiling
    - Preprecessor expressions
    - Multiple Inclusion Guard
        1) 
        ``` c
        #ifndef NUTILITY_H
        #define NUTILITY_H
            
        #endif
        ```
        2) 
        ``` c
        #pragma once
        ```
    