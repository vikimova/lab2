#ifdef ROOTS
#define ROOTS
struct Roots {
	double root_1;
	double root_2;
};
#endif

#ifndef RESULT
#define RESULT
struct Result {
	struct Roots roots;
	int err;
};
#endif // !RESULT


struct Result calc_sqrt_roots(double a, double b, double c);
