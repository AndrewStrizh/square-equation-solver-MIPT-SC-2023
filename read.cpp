#include <errno.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "read.h"


int read_double(double* value, const char* prompt, const char param)
{
    assert(value);
    assert(prompt);
    assert(isfinite(*value));

    size_t length = 0;
    char* end = NULL;
    char buf[BUFFER_SIZE] = "";

    printf("%s%c: ", prompt, param);

    /* Read to buffer */
    if (!fgets(buf, sizeof(buf), stdin))
        return 1;

    /* Deleting a newline character */
    length = strlen(buf);

    if (length == 0)
    {
        fprintf(stderr, SMALL_ERROR_COLOR("Error: An empty string was entered.\n"));
        return 1;
    }

    if (buf[length - 1] == '\n')
    {
        buf[--length] = '\0';

        /* Conversion from string to number */
        errno = 0;
        *value = strtod(buf, &end);

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


int do_read_double(double* value, const char param)
{
    assert(value);
    assert(isfinite(*value));

    int status = 0;
    do
    {
        status = read_double(value, "Enter the parameter ", param);
        if (status != 0)
        {
            printf(SMALL_ERROR_COLOR("Please try again.\n"));
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

    do_read_double(&(params->a), 'a');
    do_read_double(&(params->b), 'b');
    do_read_double(&(params->c), 'c');
    printf("--> You have entered: a = %lf; b = %lf; c = %lf\n", params->a, params->b, params->c);
    return 0;
}
