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


        struct Params params = { 0, 0, 0 }; //{a, b, c}
        struct Roots roots = { 0, 0 };      //{x1, x2}

        char p = 'N';

        printf("Do you want to use uplot?[Y/N] ");
        scanf("%c", &p);
        scanf("%*[^\n]");
        scanf("%*c");

        init_params(&params);

        if (p == 'Y' || p == 'y')
        {
            struct Graph_params graph_params = {0,0,0}; //{left board, right board, step}

            do
            {
                do_read_double(&(graph_params.lx), "left border of the interval x");
                do_read_double(&(graph_params.rx), "right border of the interval x");
                do_read_double(&(graph_params.step), "step");
            } while (graph(params, graph_params) != 0);
        };

        print_solution(params, &roots);
    };
}
