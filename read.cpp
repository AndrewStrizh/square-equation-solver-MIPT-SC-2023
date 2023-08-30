#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "read.h"


int read_double(double* value, const char* prompt)
{
    assert(value);
    assert(prompt);
    assert(isfinite(*value));

    size_t length = 0;
    char* end = NULL;
    char buf[BUFFER_SIZE] = "";

    printf("%s: ", prompt);

    /* Read to buffer */
    if (!fgets(buf, sizeof(buf), stdin))
        return 1;

    /* Deleting a newline character */
    length = strlen(buf);

    if (buf[length - 1] == '\n')
    {
        buf[--length] = '\0';

        /* Conversion from string to number */
        errno = 0;
        *value = strtod(buf, &end);

        if (length == 0)
        {
            fprintf(stderr, SMALL_ERROR_COLOR("Error: An empty string was entered.\n"));
            return 1;
        }
        if (errno != 0 || *end != '\0')
        {
            fprintf(stderr, SMALL_ERROR_COLOR("Error: Invalid character.\n"));
            fprintf(stderr, SMALL_ERROR_COLOR("\t%s\n"), buf);
            fprintf(stderr, SMALL_ERROR_COLOR("\t%*c\n"), (int)(end - buf) + 1, '^');
            return 1;
        }
    }
    else
    {
        /* The line is not fully read, skip the rest of the line */

        /* The * symbol means that we want to read the variable from the stream,
           but we don't want to save it anywhere.
           The characters [^\n] mean that we want to read exactly the line and exactly
           to the end, to the newline character. */

        scanf("%*[^\n]");
        scanf("%*c");

        fprintf(stderr, SMALL_ERROR_COLOR("Error: do not enter more than %d character(s).\n"),
            BUFFER_SIZE - 2);
        /* BUFFER_SIZE - 2 because the buffer also stores the newline character and the null byte */
        return 1;
    }
    return 0;
}


int do_read_double(double* value, const char* prompt)
{
    assert(value);
    assert(prompt);
    assert(isfinite(*value));

    int status = 0;
    do
    {
        char enter[100] = "Enter the ";
        status = read_double(value, strcat(enter, prompt));
        if (status != 0)
        {
            printf(SMALL_ERROR_COLOR("\aPlease try again.\n"));
        }
    } while (status != 0);
    return 0;
}


int init_params(struct Params* params)
{
    assert(params);
    assert(isfinite(params->a));
    assert(isfinite(params->b));
    assert(isfinite(params->c));

    do_read_double(&(params->a), "parameter a");
    do_read_double(&(params->b), "parameter b");
    do_read_double(&(params->c), "parameter c");
    printf("--> You have entered: a = %lf; b = %lf; c = %lf\n", params->a, params->b, params->c);
    return 0;
}


int graph(const struct Params p, const struct Graph_params gp)
{
    assert(isfinite(gp.lx));
    assert(isfinite(gp.rx));
    assert(isfinite(gp.step));
    assert(isfinite(p.a));
    assert(isfinite(p.b));
    assert(isfinite(p.c));

    if (gp.lx < gp.rx && gp.step < gp.rx - gp.lx && gp.step > 0)
    {
        FILE* tmp = fopen("params.tsv", "w");
        for (double i = gp.lx; i <= gp.rx; i += gp.step)
        {
            fprintf(tmp, "%.4fl\t%.4fl\n", i, p.a * (i * i) + p.b * (i) + p.c);
        }
        fclose(tmp);
        system("uplot line -w 80 -h 50 -c green params.tsv");
        return 0;
    }
    else
    {
        printf("wrong borders or step\n");
        return 1;
    }
}
