#ifndef ROOTS
#define ROOTS
struct Roots {
	float root_1;
	float root_2;
	// структура для хранения корней уравнения
};
#endif

#ifndef RESULT
#define RESULT
struct Result {
    struct Roots *roots;
	int err;
	char *err_mes;
	// структура для хранения результата вычисления и ошибки
};
#endif


// функция вычисления корней квадратного уравнения
struct Result calc_sqrt_roots(float a, float b, float c);
