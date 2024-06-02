#include "quadratic.h"              
#include <math.h>

struct Result calc_sqrt_roots(double a, double b, double c) {
    int err;
    double root_1, root_2;
        // дискриминант
        double D = pow(b, 2) - 4*a*c;

    struct Roots roots;
    struct Roots *rp = &roots;
    struct Result res;

        if (D == 0) {
                // корни одинаковые
                root_1 = b / (2*a);
                root_2 = root_1;
        err = 0;
        } else if (D < 0) {
                // нет действительных корней
        root_1 = -1;
        root_2 = -1;
        err = 1;
        } else {
                // корни разные
                root_1 = (sqrt(D) - b) / (2*a);
                root_2 = (sqrt(D) + b) / (2*a);
        err = 0;
    }

    roots.root_1 = root_1;
    roots.root_2 = root_2;
    res.roots = rp;
    res.err = err;

        return res;
}

