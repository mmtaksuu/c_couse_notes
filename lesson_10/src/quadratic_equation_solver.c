/**
 * @file    : LESSON_10 project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 25 / May / 2020
 * @code    : quadratic_equation_solver.c file
 * @details : Ikinci Dereceden Denklemin Koklerinin Bulunmasi
 *            Quadratic Equation Solver
 */

#include <stdio.h>
#include <math.h>

typedef struct {
    double reel;
    double im;
} COMPLEX_t ;

typedef struct {
    double a;
    double b;
    double c;
    double delta;
    double x1;
    double x2;
    COMPLEX_t c_x1;
    COMPLEX_t c_x2;
} Quadratic_Equation_t;


void quadratic_equation_solver(Quadratic_Equation_t *p_quad_eq);
void prints_quadratic_equation_result(Quadratic_Equation_t *p_quad_eq);

int main(void)
{
    Quadratic_Equation_t quadratic_equation_t = {0};

    printf("Enter the coefficients of the equation 'ax^2 + bx + c = 0'\n");

    printf("a : ");
    scanf("%lf", &quadratic_equation_t.a);

    printf("b : ");
    scanf("%lf", &quadratic_equation_t.b);

    printf("c : ");
    scanf("%lf", &quadratic_equation_t.c);

    quadratic_equation_solver(&quadratic_equation_t);
    prints_quadratic_equation_result(&quadratic_equation_t);

    return 0;
}


void quadratic_equation_solver(Quadratic_Equation_t *p_quad_eq)
{
    // First, find the discriminant    Δ = b^2 − 4ac
    p_quad_eq->delta = pow(p_quad_eq->b, 2) - (4 * p_quad_eq->a * p_quad_eq->c);

    if (p_quad_eq->delta > 0) // we get two real solutions
    {
        // x1 = (−b - √Δ) / 2a
        p_quad_eq->x1 = (-p_quad_eq->b - sqrt(p_quad_eq->delta)) / (2 * p_quad_eq->a);

        // x2 = (−b + √Δ) / 2a
        p_quad_eq->x2 = (-p_quad_eq->b + sqrt(p_quad_eq->delta)) / (2 * p_quad_eq->a);
    }
    else if (p_quad_eq->delta == 0)  // we get just ONE solution
    {
        // x1 = x2 = -b / 2a
        p_quad_eq->x1 = p_quad_eq->x2 = (-p_quad_eq->b) / (2 * p_quad_eq->a);
    }
    else if (p_quad_eq->delta < 0)  // we get complex solutions
    {
        // x1 = a - bi
        p_quad_eq->c_x1.reel = (-p_quad_eq->b) / (2 * p_quad_eq->a);
        p_quad_eq->c_x1.im   = (-sqrt(fabs(p_quad_eq->delta))) / (2 * p_quad_eq->a);

        // x2 = = a + bi
        p_quad_eq->c_x2.reel = (-p_quad_eq->b) / (2 * p_quad_eq->a);
        p_quad_eq->c_x2.im   = (sqrt(fabs(p_quad_eq->delta))) / (2 * p_quad_eq->a);
    }
}


void prints_quadratic_equation_result(Quadratic_Equation_t *p_quad_eq)
{
    printf("Answer: \n\n");

    if (p_quad_eq->delta > 0) // we get two real solutions
    {
        printf("There are two real solutions \n");
        printf("The parabola crosses the x axis at two different points. \n");
        printf("x1 = %.2f\nx2 = %.2f\n", p_quad_eq->x1, p_quad_eq->x2);
    }
    else if (p_quad_eq->delta == 0)  // we get just ONE solution
    {
        printf("There is just one real solutions \n");
        printf("The parabola is tangent to the x axis. \n");

        if (-p_quad_eq->b / (2* p_quad_eq->a) > 0)
            printf("The parabola is tangent on the positive side of the y axis. \n");
        else if (-p_quad_eq->b / (2* p_quad_eq->a) < 0)
            printf("The parabola is tangent on the negative side of the y axis. \n");

        printf("x1 = %.2f\nx2 = %.2f\n", p_quad_eq->x1, p_quad_eq->x2);

    }
    else if (p_quad_eq->delta < 0)  // we get complex solutions
    {
        printf("There are two complex solutions \n");
        printf("The parabola does not cross the x axis. \n");

        if (p_quad_eq->a > 0)
            printf("The parabola is on the positive side of the y axis. \n");
        else if (p_quad_eq->a < 0)
            printf("The parabola is on the negative side of the y axis. \n");

        printf("x1 = %.1f %c %.2fi\n", p_quad_eq->c_x1.reel, p_quad_eq->c_x1.im > 0 ? '+' : '-', fabs(p_quad_eq->c_x1.im));
        printf("x2 = %.1f %c %.2fi\n", p_quad_eq->c_x2.reel, p_quad_eq->c_x2.im > 0 ? '+' : '-', fabs(p_quad_eq->c_x2.im));
    }
}

