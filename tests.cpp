#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "tests.h"


int equate_double_test(const double x, const double y)
{
    assert(isfinite(x));
    assert(isfinite(y));

    return fabs(x - y) < EPS_TEST;
}


int run_test_solve_square(
    const struct test_solve_square t, FILE* tmp, int* correct_answers, int* all_answers)
{
    assert(tmp);
    assert(correct_answers);
    assert(all_answers);
    assert(isfinite(t.p.a));
    assert(isfinite(t.p.b));
    assert(isfinite(t.p.c));
    assert(isfinite(t.r.x1));
    assert(isfinite(t.r.x2));

    if (test_solve(t, tmp, all_answers) == 0)
    {
        printf(CORRECT_COLOR("test passed\n"));
        ++(*correct_answers);
    }
    ++(*all_answers);
    return 0;
}


int test_solve(const struct test_solve_square t, FILE* tmp, int* all_answers)
{
    assert(tmp);
    assert(all_answers);
    assert(isfinite(t.p.a));
    assert(isfinite(t.p.b));
    assert(isfinite(t.p.c));
    assert(isfinite(t.r.x1));
    assert(isfinite(t.r.x2));

    struct Roots x = {};
    int nRoots = solve_square(t.p, &x);

    if (t.nRootsRef != nRoots || !equate_double_test(x.x1, t.r.x1)
        || !equate_double_test(x.x2, t.r.x2))
    {
        printf(ERROR_COLOR("FAILURE TEST %d: a=%lf; b = %lf; c = %lf\n"), *all_answers, t.p.a,
            t.p.b, t.p.c);
        fprintf(tmp,
            "FAILURE TEST №%d: a=%lf; b = %lf; c = %lf\nright x1 = %lf\tright x2 = %lf\tright"
            "number of roots = %d\nprog x1 = %lf\tprog x2 = %lf\tprog number of roots = %d\n\n",
            *all_answers, t.p.a, t.p.b, t.p.c, t.r.x1, t.r.x2, t.nRootsRef, x.x1, x.x2, nRoots);
        return 1;
    }
    else
        return 0;
}


int all_tests(const char* filename)
{
    assert(filename);

    BEGIN_TEST;
    FILE* tmp = fopen(filename, "w");
    TEST_SOLVE_SQUARE(10000, 1, 0, 0, 0, 1);
    TEST_SOLVE_SQUARE(1, 0, 0, 0, 0, 1);
    TEST_SOLVE_SQUARE(0, 0, 1, 0, 0, 0);
    TEST_SOLVE_SQUARE(-1, 0, 0, 0, 0, 1);
    TEST_SOLVE_SQUARE(0, -1, 0, 0, 0, 1);
    TEST_SOLVE_SQUARE(1, 2, -3, -3, 1, 2);
    TEST_SOLVE_SQUARE(1, 2, -4, -3.2361, 1.2361, 2);
    TEST_SOLVE_SQUARE(1, 0, -16, -4, 4, 1);
    fclose(tmp);
    END_TEST;
    return 0;
}
