int main()
{
	//int *p1, p2;
	int *p1;
	int p2;
}
/**********************************************************************************************************************/


int main()
{
	int *p1, *p2;
	//int *p1;
	//int *p2;
}
/**********************************************************************************************************************/


int main()
{
	/*int x, *y, z[5];*/
	int x;
	int *y;
	int z[5];
}
/**********************************************************************************************************************/

int x, func(int), *ptr;

int main()
{
}
/**********************************************************************************************************************/


pointer
	object pointers
	function pointers



#include <stdio.h>

int main()
{
	printf("sizeof(char) = %zu\n", sizeof(char));
	printf("sizeof(char*) = %zu\n", sizeof(char*));
	printf("\n");
	printf("sizeof(short) = %zu\n", sizeof(short));
	printf("sizeof(short *) = %zu\n", sizeof(short *));
	printf("\n");
	printf("sizeof(int) = %zu\n", sizeof(int));
	printf("sizeof(int*) = %zu\n", sizeof(int*));
	printf("\n");
	printf("sizeof(double) = %zu\n", sizeof(double));
	printf("sizeof(double *) = %zu\n", sizeof(double *));

}
/**********************************************************************************************************************/
#include <stdio.h>

int *gp;

void func(int *p)
{
	int *ptr;
	static int *sptr;
	//
}

int main()
{


}
/**********************************************************************************************************************/
#include <stdio.h>


int foo();

int main()
{
	int x = 10;
	int a[4] = { 0 };

	//10  ----> int R val
	//x       ----> int L val
	//x + 5   ----> int Rval
	//a[2]   ----> int Lval
	//foo()  ----> int Rval
}
/**********************************************************************************************************************/
#include <stdio.h>


int *foo();

int main()
{
	int x;
	int a[5];
	int *ptr;
	int *p[5];

	// &x
	// a + 2
	// (int *)10000
	// foo()
	// ptr
	// p[3]
}
/**********************************************************************************************************************/


--------------------------------------------------
1         [ ]       ->
--------------------------------------------------
2          &      *
--------------------------------------------------



&     address of					(adres operatörü)
*     dereferencing /indirection	(içerik operatörü)
[]    index / subscript             (köşeli parantez)
->    member selection (arrow op)    (ok operatörü)


ptr[-5]


adres operatörü

2. seviyesinde
unary prefix


10

#include <stdio.h>


int main()
{
	int x = 10;
	int y = 20;

	int *ptr = &x;

	ptr = &y;

}
/**********************************************************************************************************************/


ptr points to x
ptr'nin değeri x'in adresi
ptr x'i gösteriyor
ptr x'e işaret ediyor
ptr x'in adresini tutuyor

#include <stdio.h>


int main()
{
	int x = 10;
	int *ptr = &x;

	printf("&x    =  %p\n", &x);
	printf("ptr   =  %p\n", ptr);
	printf("&ptr  =  %p\n", &ptr);

}
/**********************************************************************************************************************/

#include <stdio.h>

//warning C4047 : 'initializing' : 'int *' differs in levels of indirection from 'int'

int main()
{
	int x = 10;
	int *ptr = x;  //C'de yanlış C++'da gecersiz


}
/**********************************************************************************************************************/
#include <stdio.h>


int main()
{
	double x = 1.0;
	int *ptr = &x; //C'de yanlis ama gecerli C++'da gecersiz


}
/**********************************************************************************************************************/
#include <stdio.h>


int main()
{
	double x = 1.0;
	int *ptr = &x; //C'de yanlis ama gecerli C++'da gecersiz

}
/**********************************************************************************************************************/
#include <stdio.h>


int main()
{
	int x = 10;
	int *ptr;
	int *p1 = &x;
	int *p2 = p1;

	ptr = p1;



}
/**********************************************************************************************************************/



&x = ptr;

array to pointer conversion (diziden adrese dönüşüm)
array decay


a -------> &a[0]


ptr = a;

#include <stdio.h>

int main()
{
	int a[10] = { 0 };
	int *ptr = a;
	//int *ptr = &a[0];

	printf("%p  %p  %p\n", a, &a[0], ptr);

}
/**********************************************************************************************************************/


ptr = &x;
ptr = ptr2;
ptr = a;

#include <stdio.h>

int main()
{
	int a[10];

	printf("sizeof(a) = %zu\n", sizeof(a));
	printf("sizeof(&a[0]) = %zu\n", sizeof(&a[0]));


}
/**********************************************************************************************************************/
#include <stdio.h>

int main()
{
	//int x = 5, a[10] = { 0 }, *p1 = a, *p2 = p1, *p3 = &x;
	int x = 5;
	int a[10] = { 0 };
	int *p1 = a;
	int *p2 = p1;
	int *p3 = &x;


}
/**********************************************************************************************************************/


içerik operatörü
(dereferencing op / indirection)

------------------------------------------
2      & * + - ! ++ -- sizeof  (double)   sağdan sola
------------------------------------------


+
-
&
*

#include <stdio.h>

int main()
{
	int x = 10;
	int *ptr = &x;
	int a[10] = { 0 };  // int[10]

	// *500
	// *x

}
/**********************************************************************************************************************/

#include <stdio.h>
#include <iostream>

int main()
{
	int x = 10;
	int *ptr = &x;
	int a[10] = { 0 };  // int[10]

	std::cout << typeid(a).name() << "\n";
	std::cout << typeid(&a[0]).name() << "\n";

}
/**********************************************************************************************************************/
#include <stdio.h>

int main()
{
	int x = 10;
	int *ptr = &x;
	int a[10] = { 0 };

	//*500
	//*x
	// *&x
	// *ptr
	// *a
}
/**********************************************************************************************************************/

#include <stdio.h>

int main()
{
	int x = 10;

	printf("x = %d\n", x);

	*&x = 20;

	printf("x = %d\n", x);

	//++*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&*&x;

}
/**********************************************************************************************************************/

if (*(int *)0xB800000)

#include <stdio.h>

int main()
{
	int a[5] = { 0 ,1, 2, 3, 4 };

	*a = 435;

}
/**********************************************************************************************************************/

pointee

employee
payee
referee
addresse


*ptr

#include <stdio.h>

int main()
{
	int x = 10;
	int *ptr = &x;

	*ptr = 87;

	printf("x = %d\n", x);
}
/**********************************************************************************************************************/
#include <stdio.h>

int main()
{
	int x = 10, *p1 = &x, y = 34, *p2 = &y;

	*p1 = *p2;

	printf("x = %d\n", x);


}
/**********************************************************************************************************************/
#include <stdio.h>

int main()
{
	int x = 10;
	int y = 20;
	int z = 50;

	int *p = &x;
	++*p;
	p = &y;
	++*p;
	p = &z;
	++*p;

	printf("x = %d\n", x);
	printf("y = %d\n", y);
	printf("z = %d\n", z);


}
/**********************************************************************************************************************/
#include <stdio.h>

void func(int x)
{
	printf("&x = %p\n", &x);

	x = 9999;
}

int main()
{
	int y = 12;
	printf("&y = %p\n", &y);
	func(y);

	printf("y = %d\n", y);

}
/**********************************************************************************************************************/
#include <stdio.h>


void func(int *ptr)
{
	*ptr = 2456;
	//code
}

int main()
{
	int y = 12;

	func(&y);

	printf("y = %d\n", y);

}
/**********************************************************************************************************************/
#include <stdio.h>


void Swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}


int main()
{
	int x = 10, y = 34;

	Swap(x, y);

	printf("x = %d\n", x);
	printf("y = %d\n", y);

}
/**********************************************************************************************************************/
#include <stdio.h>


void Swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


int main()
{
	int x = 10, y = 34;

	Swap(&x, &y);

	printf("x = %d\n", x);
	printf("y = %d\n", y);

}
/**********************************************************************************************************************/
#include <stdio.h>


void Swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


int main()
{
	int x = 10, y = 34;
	int *a = &x, *b = &y;

	Swap(a, b);

	printf("x = %d\n", x);
	printf("y = %d\n", y);

}
/**********************************************************************************************************************/
#include <stdio.h>


void Swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


int main()
{
	int x = 10, y = 34;
	int a[] = { 1, 2, 3 };
	int b[] = { -1, -2, -3 };

	Swap(a, b);

	printf("a[0] = %d\n", a[0]);
	printf("b[0] = %d\n", b[0]);

}
/**********************************************************************************************************************/
#include <stdio.h>


void Swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


int main()
{
	int x = 10, y = 34;
	int a[] = { 1, 2, 3 };
	int b[] = { -1, -2, -3 };

	//Swap(a, b);
	Swap(&a[0], &b[0]);

	printf("a[0] = %d\n", a[0]);
	printf("b[0] = %d\n", b[0]);

}
/**********************************************************************************************************************/
#include <stdio.h>


double get_circle_area(double radius)
{
	return 3.1415926 * radius * radius;
}


int main()
{
	double r = 4.567;
	double area;

	area = get_circle_area(r);

	printf("area = %f\n", area);


}
/**********************************************************************************************************************/

#include <stdio.h>

void get_circle_area(double radius, double *pArea)
{
	*pArea = 3.1415926 * radius * radius;
}


int main()
{
	double r = 4.567;
	double area;

	get_circle_area(r, &area);

	printf("area = %f\n", area);


}


