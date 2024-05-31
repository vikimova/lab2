#ifndef ROOTS
#define ROOTS
struct Roots {
	double root_1;
	double root_2;
	// структура для хранения корней уравнения
};
#endif

#ifndef RESULT
#define RESULT
struct Result {
    struct Roots *roots;
	int err;
	// структура для хранения результата вычисления и ошибки
};
#endif


// функция вычисления корней квадратного уравнения
struct Result calc_sqrt_roots(double a, double b, double c);
