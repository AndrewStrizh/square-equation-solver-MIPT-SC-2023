/**
 *\file
 *File read.cpp containing functions that provide input of parameters of a quadratic equation
 *from the console
 */


#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


#define RED_TEXT "\x1b[31m"
#define GREEN_TEXT "\x1b[32m"
#define YELLOW_TEXT "\x1b[33m"
#define RESET_COLOR "\x1b[0m"


#define ERROR_COLOR(str) RED_TEXT str RESET_COLOR
#define CORRECT_COLOR(str) GREEN_TEXT str RESET_COLOR
#define SMALL_ERROR_COLOR(str) YELLOW_TEXT str RESET_COLOR


const int BUFFER_SIZE
    = 102; /**< The size of the buffer storing the characters entered by the user is not more than
              100 + \\n + \0 */


/**
 *Function that provides the translation of the value entered by the user into the double type
 *and handles its errors
 *\param *value - address of the parameter value entered by the user
 *\param *prompt - address of prompt for input
 *\return in case of an error, returns 1
 */
int read_double(double* value, const char* prompt);


/**
 *Wrapper for the read_double function, which gives the user the opportunity to re-enter the
 *parameter
 *in case of an error
 *\param *value - address of the parameter value entered by the user
 *\param *prompt - address of prompt for input
 */
int do_read_double(double* value, const char* prompt);


/**
 *Function initializing the parameters of a quadratic equation
 *\param *params - address of the structure storing the parameters of a quadratic equation
 */
int init_params(struct Params* params);


/**
 *Function that draws a graph according to the specified parameters interval X and step
 *\param p - structure storing the parameters of a quadratic equation
 *\param gp - structure contains the left and right borders for drawing the graph, as well as the step with which the points are marked
 */
int graph(const struct Params p, const struct Graph_params gp);


/**
 *\brief This structure stores the parameters of the quadratic equation
 */
struct Params
{
    double a, b, c;
};


/**
 *\brief This structure contains the left and right borders for drawing the graph,
 *as well as the step with which the points are marked
 */
struct Graph_params
{
    double lx, rx, step;
};


#endif // HEADER_H_INCLUDED
