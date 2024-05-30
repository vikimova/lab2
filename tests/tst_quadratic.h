#include <gtest/gtest.h>

extern "C" {
#include "quadratic.h"
}

TEST(TestNoErrorQudraticRoots, NormalRoots) {
    ASSERT_EQ(calc_sqrt_roots(1, 2, -3), {1, -3, 0});
}

TEST(TestNoErrorQudraticRoots, EqualRoots) {
	ASSERT_EQ(calc_sqrt_roots(1, -2, 1), {0, 0, 0});
}

TEST(TestQuadraticWithErrorRoots, PositiveOk) {
	ASSERT_EQ(calc_sqrt_roots(-1, -7, -19), {-1, -1, 1});
}
