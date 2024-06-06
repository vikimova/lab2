#include <gtest/gtest.h>
#include <math.h>
#include <stdio.h>

extern "C" {
#include "quadratic.h"
}


TEST(TestNoErrorQudraticRoots, NormalRoots) {
    Roots roots = {1., -3.};
    Roots *r = &roots;
    Result expected = {r, 0, ""};
    Result got = calc_sqrt_roots(1.0, 2.0, -3.0);

    printf("?%d: %f == %f \n",
           expected.roots->root_1 == got.roots->root_1,
           got.roots->root_1,
           expected.roots->root_1
    );
    printf("?%d: %f == %f \n",
           expected.roots->root_2 == got.roots->root_2,
           got.roots->root_2,
           expected.roots->root_2
    );
    EXPECT_EQ(got.err, expected.err);
    EXPECT_FLOAT_EQ(expected.roots->root_1, got.roots->root_1);
}

TEST(TestNoErrorQudraticRoots, EqualRoots) {
    Roots roots = {0.0, 0.0};
    Roots *r = &roots;
    Result expected = {r, 0, ""};
    Result got = calc_sqrt_roots(1.0, -2.0, 1.0);

    EXPECT_EQ(expected.err, got.err);
    EXPECT_FLOAT_EQ(expected.roots->root_2, got.roots->root_2);
}

TEST(TestNoErrorQudraticRoots, ZeroKoefficients) {
    Roots roots = {-1.0, -1.0};
    Roots *r = &roots;
    Result expected = {r, 0, ""};
    Result got = calc_sqrt_roots(0., 0., 0.);

    EXPECT_EQ(expected.err, got.err);
    EXPECT_FLOAT_EQ(expected.roots->root_2, got.roots->root_2);
}

TEST(TestQuadraticWithErrorRoots, NonValidRoots) {
    Roots roots = {-1, -1};
    Roots *r = &roots;
    Result expected = {r, 1, ""};
	Result got = calc_sqrt_roots(-1, -7, -19);

    printf("%f:%f\n", got.roots->root_1, got.roots->root_2);

    EXPECT_EQ(got.err, expected.err);
    EXPECT_FLOAT_EQ(got.roots->root_2, expected.roots->root_2);
}


TEST(TestQuadraticWithWrongArgs, NegativeHugeNum) {
    Result got = calc_sqrt_roots(2e100000, 2e100000, 2e100000);
    EXPECT_EQ(isnan(got.roots->root_1), true);
}
