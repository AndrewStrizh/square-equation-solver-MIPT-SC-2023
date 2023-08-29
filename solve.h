/**
 *\file
 *File solve.cpp containing functions for solving linear and quadratic equations
 */


#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#define ERROR_COLOR(str) RED_TEXT str RESET_COLOR

#define CORRECT_COLOR(str) GREEN_TEXT str RESET_COLOR

#define SMALL_ERROR_COLOR(str) YELLOW_TEXT str RESET_COLOR


#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define YELLOW_TEXT "\x1b[33m"
#define RESET_COLOR "\x1b[0m"

const double EPS_ALL = 1e-6; /**< Accuracy of the numerical data type */


/**
 *\enum
 * Possible number of roots
 */
enum ROOT_KEYS
{
    ZERO_ROOTS,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS
};


/**
 *Function for solving a quadratic equation
 *\param p - structure stores the parameters of the quadratic equation
 *\param *r - address of the structure storing the values of the roots of a quadratic equation
 */
ROOT_KEYS solve_square(const struct Params p, struct Roots* r);


/**
 *Function for solving a quadratic equation
 *\param p - structure stores the parameters of the quadratic equation
 *\param *r - address of the structure storing the values of the roots of a quadratic equation
 */
ROOT_KEYS solve_linear(const struct Params p, struct Roots* r);


/**
 *Function for comparing double number and zero
 *\param x - compared number
 */
int equate_zero(const double x);


/**
 *The main function solving the quadratic equation
 *\param params - structure storing the parameters of a quadratic equation
 *\param *roots - address of the structure storing the values of the roots of a quadratic equation
 */
int print_solution(const struct Params params, struct Roots* roots);


/**
 *\brief This structure stores the parameters of the quadratic equation
 */
struct Params
{
    double a, b, c;
};


/**
 *\brief This structure storing the values of the roots of a quadratic equation
 */
struct Roots
{
    double x1, x2;
};


#endif // HEADER_H_INCLUDED
