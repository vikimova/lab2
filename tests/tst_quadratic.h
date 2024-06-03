#include <gtest/gtest.h>
#include <math.h>
#include <stdio.h>

extern "C" {
#include "quadratic.h"
}


TEST(TestNoErrorQudraticRoots, NormalRoots) {
    Roots roots = {1, -3};
    Roots *r = &roots;
    Result expected = {r, 0};
    Result got = calc_sqrt_roots(1, 2, -3);

    printf("%f:%f\n", got.roots->root_1, got.roots->root_2);
    float r1 = got.roots->root_1;

    EXPECT_EQ(got.err, expected.err);
    EXPECT_FLOAT_EQ(expected.roots->root_1, r1);
    EXPECT_FLOAT_EQ(expected.roots->root_2, got.roots->root_2);
}

TEST(TestNoErrorQudraticRoots, EqualRoots) {
    Roots roots = {0, 0};
    Roots *r = &roots;
    Result expected = {r, 0};
	Result got = calc_sqrt_roots(1, -2, 1);

     printf("%f:%f\n", got.roots->root_1, got.roots->root_2);

    EXPECT_EQ(expected.err, got.err);
    EXPECT_FLOAT_EQ(expected.roots->root_1, got.roots->root_1);
    EXPECT_FLOAT_EQ(expected.roots->root_2, got.roots->root_2);
}

TEST(TestQuadraticWithErrorRoots, PositiveOk) {
    Roots roots = {-1, -1};
    Roots *r = &roots;
    Result expected = {r, 1};
	Result got = calc_sqrt_roots(-1, -7, -19);

    EXPECT_EQ(got.err, expected.err);
    EXPECT_DOUBLE_EQ(got.roots->root_1, expected.roots->root_1);
    EXPECT_DOUBLE_EQ(got.roots->root_2, expected.roots->root_2);
}


TEST(TestQuadraticWithWrongArgs, NegativeHugeNum) {
    Result got = calc_sqrt_roots(2e100000, 2e100000, 2e100000);
    EXPECT_EQ(isnan(got.roots->root_2), true);
    EXPECT_EQ(isnan(got.roots->root_1), true);
}
