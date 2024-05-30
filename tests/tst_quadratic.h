#include <gtest/gtest.h>

extern "C" {
#include "quadratic.h"
}

TEST(tst_quadratic, PositiveOk) {
	ASSERT_EQ(calc_sqrt_roots(1, 2, -3), Roots{1, -3});
}
