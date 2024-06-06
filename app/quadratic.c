#include "quadratic.h"              

#include <math.h>
#include <stdio.h>

struct Result calc_sqrt_roots(float a, float b, float c) {
    int err;
	char *err_mes;
    float root_1, root_2;

	// дискриминант
    struct Roots roots;
    struct Roots *rp = &roots;
    struct Result res;

	if (a == 0) {
		// не квадратное уравнение
		root_1 = -1.0;
		root_2 = -1.0;
		err = 1;
		err_mes = "not a qudratic equation";
	} else {
		float D = b*b - 4*a*c;

		if (D == 0.) {
			// корни одинаковые
			root_1 = b / 2.*a;
			root_2 = b / 2.*a;
			err = 0;
			err_mes = "";
		} else if (D < 0.) {
			// нет действительных корней
			root_1 = -1.0;
			root_2 = -1.0;
			err = 1;
			err_mes = "no real roots";
		} else {
			// корни разные
			root_1 = (sqrt(D) - b) / 2.*a;
			root_2 = (-sqrt(D) - b) / 2.*a;
			err = 0;
			err_mes = "";
		}
	}


    roots.root_1 = root_1;
    roots.root_2 = root_2;

    res.roots = rp;
    res.err = err;
	res.err_mes = err_mes;

	return res;
}

