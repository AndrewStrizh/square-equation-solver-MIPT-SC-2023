/**
 *\file
 * File test.cpp a file storing functions for testing
 */


#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#define ERROR_COLOR(str) RED_TEXT str RESET_COLOR

#define CORRECT_COLOR(str) GREEN_TEXT str RESET_COLOR

#define SMALL_ERROR_COLOR(str) YELLOW_TEXT str RESET_COLOR


/// Macro that creates the test_solve_square structure and starts testing
#define TEST_SOLVE_SQUARE(a, b, c, x1, x2, nRoots)                                                 \
    (                                                                                              \
        {                                                                                          \
            struct test_solve_square t = { { a, b, c }, { x1, x2 }, nRoots };                      \
            run_test_solve_square(t, &correct_answers, &all_answers, filename);                    \
        })


/// Macro that creates variables for the number of all tests and valid tests
#define BEGIN_TEST                                                                                 \
    int correct_answers = 0;                                                                       \
    int all_answers = 0;


/// Macro that outputs variable numbers of all tests and valid tests to the console
#define END_TEST                                                                                   \
    printf(GREEN_TEXT "passed %d tests out of %d" RESET_COLOR, correct_answers, all_answers);


#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define YELLOW_TEXT "\x1b[33m"
#define RESET_COLOR "\x1b[0m"


const double EPS_TEST = 1e-3; /**< Accuracy of numeric data type in test comparisons */


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
 *\param *r - structure storing the values of the roots of a quadratic equation
 */
ROOT_KEYS solve_square(const struct Params p, struct Roots* r);


/**
 *Function for solving a quadratic equation
 *\param p - structure stores the parameters of the quadratic equation
 *\param *r - structure storing the values of the roots of a quadratic equation
 */
ROOT_KEYS solve_linear(const double b, const double c, double* x1);


/**
 *Function for comparing two answers (the correct answer and the answer of the function) of type
 *double
 *\param x,y are the numbers being compared
 */
int equate_double_test(const double x, const double y);


/**
 *Function that checks whether the test results match the results of the solve_square function
 *\param t - structure storing the test parameters of the quadratic equation, the correct roots and
 *their number
 *\param *filename - address of the file, name entered by the user
 *\param *all_answers - address of the number of all tests
 */
int test_solve(const struct test_solve_square t, const char* filename, int* all_answers);


/**
 *Function that outputs information about the test to the console
 *\param t - structure storing the test parameters of the quadratic equation, the correct roots and
 *their number
 *\param *correct_answers - address of the number of valid tests
 *\param *all_answers - address of the number of all tests
 *\param *filename - address of the file, name entered by the use
 */
int run_test_solve_square(const struct test_solve_square t, int* correct_answers, int* all_answers, const char* filename);


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
