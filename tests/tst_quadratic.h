#include <gtest/gtest.h>

#include <stdio.h>

extern "C" {
#include "quadratic.h"
}

//TEST(TestNoErrorQudraticRoots, NormalRoots) {
//    Roots roots = {1, -3};
//    Roots *r = &roots;
//    Result expected = {r, 0};
//    Result got = calc_sqrt_roots(1, 2, -3);
//
//    ASSERT_EQ(got.err, expected.err);
//    ASSERT_EQ(expected.roots->root_1, got.roots->root_1);
//    ASSERT_EQ(expected.roots->root_2, got.roots->root_2);
//}
//
//TEST(TestNoErrorQudraticRoots, EqualRoots) {
//    Roots roots = {0, 0};
//    Roots *r = &roots;
//    Result expected = {r, 0};
//	Result got = calc_sqrt_roots(1, -2, 1);
//
//    ASSERT_EQ(expected.err, got.err);
//    ASSERT_EQ(expected.roots->root_1, got.roots->root_1);
//    ASSERT_EQ(expected.roots->root_2, got.roots->root_2);
//}
//
//TEST(TestQuadraticWithErrorRoots, PositiveOk) {
//    Roots roots = {-1, -1};
//    Roots *r = &roots;
//    Result expected = {r, 1};
//	Result got = calc_sqrt_roots(-1, -7, -19);
//
//    ASSERT_EQ(got.err, expected.err);
//    ASSERT_EQ(got.roots->root_1, expected.roots->root_1);
//    ASSERT_EQ(got.roots->root_2, expected.roots->root_2);
//}
