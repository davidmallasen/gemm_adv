#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include "gemm.h"
}

// Basic simple test with 1x1 matrices
TEST(GemmTest, SimpleGemm) {
    int a[] = {1};
    int b[] = {2};
    int gemm_sol[] = {0};
    
    int sol[] = {2};
    
    gemm(1, gemm_sol, a, b);

    EXPECT_THAT(gemm_sol, testing::ContainerEq(sol));
}

// Test major ordering with non-symmetric 2x2 matrices
TEST(GemmTest, RowMajor) {
    int a[] = {1, 2, 3, 4};
    int b[] = {5, 6, 7, 8};
    int gemm_sol[] = {0, 0, 0, 0};
    
    int sol[] = {19, 22, 43, 50};
    
    gemm(2, gemm_sol, a, b);

    EXPECT_THAT(gemm_sol, testing::ContainerEq(sol));
}

// Test higher dimension matrices and negative numbers
TEST(GemmTest, HigherDimNeg) {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, -1, -2, -3, -4, -5, -6, -7, -8};
    int b[] = {8, 6, 7, 5, -4, -2, -3, -1, -8, -6, -7, -5, 4, 2, 3, 1};
    int gemm_sol[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    int sol[] = {-8, -8, -8, -8, -8, -8, -8, -8, 8, 8, 8, 8, 8, 8, 8, 8};
    
    gemm(4, gemm_sol, a, b);

    EXPECT_THAT(gemm_sol, testing::ContainerEq(sol));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
