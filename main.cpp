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
    assert(argv);

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

        char p = 'N';

        printf("Do you want to use uplot?[Y/N] ");
        scanf("%c", &p);
        scanf("%*[^\n]");
        scanf("%*c");

        init_params(&params);

        if (p == 'Y' || p == 'y')
        {
            double lx = 0, rx = 0, step = 0;
            do
            {
                do_read_double(&lx, "left border of the interval x");
                do_read_double(&rx, "right border of the interval x");
                do_read_double(&step, "step");
            } while (graph(params, lx, rx, step) != 0);
        };

        print_solution(params, &roots);
    };
}
