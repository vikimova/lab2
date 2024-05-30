#include <math.h>

#include "quadratic.h"


struct Roots {
	double root_1;
	double root_2;
};


struct Roots calc_sqrt_roots(double a, double b, double c) {
	double root_1, root_2;
	double D = pow(b, 2) - 4*a*c;

	if (D == 0) {
		root_1 = b / (2*a);
		root_2 = root_1;
	} else {
		root_1 = (sqrt(D) - b) / (2*a);
		root_2 = (sqrt(D) + b) / (2*a);
	}

	struct Roots roots = {root_1, root_2};

	return roots;
}
