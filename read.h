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
 *\param param - parameter name (a,b,c)
 *\return in case of an error, returns 1
 */
int read_double(double* value, const char* prompt, const char param);


/**
 *Wrapper for the read_double function, which gives the user the opportunity to re-enter the
 *parameter
 *in case of an error
 *\param *value - address of the parameter value entered by the user
 *\param param - parameter name (a,b,c)
 */
int do_read_double(double* value, const char param);


/**
 *Function initializing the parameters of a quadratic equation
 *\param *params - address of the structure storing the parameters of a quadratic equation
 */
int init_params(struct Params* params);


/**
 *\brief This structure stores the parameters of the quadratic equation
 */
struct Params
{
    double a, b, c;
};


#endif // HEADER_H_INCLUDED
