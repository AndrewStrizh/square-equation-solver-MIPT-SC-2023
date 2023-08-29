#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>
#include "ses.h"

int main(int argc, char* argv[])
{
    if (argc > 2 && !strcmp(argv[1], "tests") && (access(argv[2], F_OK) == 0))
        all_tests(argv[2]);
    else if (argc > 2)
        printf("No such file in directory\n");
    else
    {
        printf("Square equation solver\n"
               "# (c) STA, 2023\n\n");

        struct Params params = { 0, 0, 0 };
        struct Roots roots = { 0, 0 };

        init_params(&params);
        print_solution(params, &roots);
    };
}
