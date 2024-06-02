#include <gtest/gtest.h>

extern "C" {
#include "quadratic.h"
}

TEST(TestNoErrorQudraticRoots, NormalRoots) {
    Roots roots = {1, -3};
    Roots *r = &roots;
    Result res = {r, 0};
    ASSERT_EQ(calc_sqrt_roots(1, 2, -3), res);
}

TEST(TestNoErrorQudraticRoots, EqualRoots) {
    Roots roots = {0, 0};
    Roots *r = &roots;
    Result res = {r, 0};
    ASSERT_EQ(calc_sqrt_roots(1, -2, 1), res);
}

TEST(TestQuadraticWithErrorRoots, PositiveOk) {
    Roots roots = {-1, -1};
    Roots *r = &roots;
    Result res = {r, 1};
    ASSERT_EQ(calc_sqrt_roots(-1, -7, -19), res);
}
