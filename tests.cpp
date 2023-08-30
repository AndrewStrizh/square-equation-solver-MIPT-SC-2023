#include <assert.h>
#include <math.h>
#include <stdio.h>
#include "solve.h"


int equate_zero(const double x)
{
    assert(isfinite(x));

    return fabs(x - 0) < EPS_ALL;
}


ROOT_KEYS solve_square(const struct Params p, struct Roots* r)
{
    assert(isfinite(p.a));
    assert(isfinite(p.b));
    assert(isfinite(p.c));
    assert(r);
    assert(isfinite(r->x1));
    assert(isfinite(r->x2));

    if (equate_zero(p.a))
        return solve_linear(p, r);
    else
    {
        double aa = p.a * 2;
        const double discr = p.b * p.b - 4 * p.a * p.c;
        if (equate_zero(discr))
        {
            if (equate_zero(p.b))
                r->x1 = p.b;
            else
                r->x1 = -p.b / aa;
            return ONE_ROOT;
        }
        else if (discr > EPS_ALL)
        {
            const double sq_discr = sqrt(discr);
            r->x1 = (-p.b - sq_discr) / aa;
            r->x2 = (-p.b + sq_discr) / aa;
            return TWO_ROOTS;
        }
        else
            return ZERO_ROOTS;
    }
}


ROOT_KEYS solve_linear(const struct Params p, struct Roots* r)
{
    assert(r);
    assert(isfinite(r->x1));
    assert(isfinite(p.b));
    assert(isfinite(p.c));

    if (equate_zero(p.b))
    {
        if (equate_zero(p.c))
            return INF_ROOTS;
        else
            return ZERO_ROOTS;
    }
    else
    {
        if (equate_zero(p.c))
            r->x1 = p.c;
        else
            r->x1 = -p.c / p.b;
        return ONE_ROOT;
    }
}


int print_solution(const struct Params params, struct Roots* roots)
{
    assert(roots);
    assert(isfinite(params.a));
    assert(isfinite(params.b));
    assert(isfinite(params.c));
    assert(isfinite(roots->x1));
    assert(isfinite(roots->x2));

    int nRoots = solve_square(params, roots);
    switch (nRoots)
    {
        case ZERO_ROOTS:
            printf(SMALL_ERROR_COLOR("There are no roots\n"));
            break;

        case ONE_ROOT:
            printf(CORRECT_COLOR("x = %lf\n"), roots->x1);
            break;

        case TWO_ROOTS:
            printf(CORRECT_COLOR("x1 = %lf\tx2 = %lf\n"), roots->x1, roots->x2);
            break;

        case INF_ROOTS:
            printf(SMALL_ERROR_COLOR("Number of roots: infinity\n"));
            break;

        default:
            break;
    }

    return 0;
}
