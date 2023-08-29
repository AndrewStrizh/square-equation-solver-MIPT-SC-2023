/**
 *\file
 * File main.cpp - file with the main function
 */

/**
 *\mainpage Square equation solver
 *\section ABOUT
 *A simple and intuitive solver of quadratic equations. Written in C as a task at the MIPT Summer School 2023.
 *The project is launched via the console using a makefile. The documentation for the project is written using Doxygen.
 *To start testing the program, you can use the TEST_SOLVE_SQUARE macro in the file tests.cpp.
 *If you specify the tests argument when running through make, the erroneous tests will be saved to this file.
 *
 */


#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


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
 *Function initializing the parameters of a quadratic equation
 *\param *params - address of structure storing the parameters of a quadratic equation
 */
int init_params(struct Params* params);


/**
 *\brief The main function solving the quadratic equation
 *\param params - structure storing the parameters of a quadratic equation
 *\param *roots - address of structure storing the values of the roots of a quadratic equation
 */
int print_solution(const struct Params params, struct Roots* roots);


/**
 *Function that starts the execution of tests
 *\param *filename - address of the file, name entered by the user
 */
int all_tests(const char* filename);


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


/**
 *\brief Structure storing the test parameters of the quadratic equation, the correct roots and
 *their number
 */
struct test_solve_square
{
    struct Params p;
    struct Roots r;
    int nRootsRef;
};


#endif // HEADER_H_INCLUDED
