#include <math.h>

#include "quadratic.h"


struct Roots {
	double root_1;
	double root_2;
};

struct Result {
	struct Roots roots;
	int err;
};


struct Result calc_sqrt_roots(double a, double b, double c) {
	double root_1, root_2;
	double D = pow(b, 2) - 4*a*c;

	struct Roots roots;
	struct Result res;

	if (D == 0) {
		root_1 = b / (2*a);
		root_2 = root_1;
		roots = {root_1, root_2};
		res = {roots, 0};
	} else if (D < 0) {
		roots = {-1, -1};
		res = {roots, 1};
	} else {
		root_1 = (sqrt(D) - b) / (2*a);
		root_2 = (sqrt(D) + b) / (2*a);
		roots = {root_1, root_2};
		res = {roots, 0};
	}

	return res;
}
