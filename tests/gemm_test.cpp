#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include "gemm.h"
}

// Basic simple test with 1x1 matrices
TEST(GemmTest, SimpleGemm) {
    double a[] = {1};
    double b[] = {2};
    double gemm_sol[] = {0};
    
    double sol[] = {2};
    
    gemm(1, gemm_sol, a, b);

    EXPECT_THAT(gemm_sol, testing::Pointwise(testing::DoubleNear(1e-14), sol));
}

// Test major ordering with non-symmetric 2x2 matrices
TEST(GemmTest, RowMajor) {
    double a[] = {1, 2, 3, 4};
    double b[] = {5, 6, 7, 8};
    double gemm_sol[] = {0, 0, 0, 0};
    
    double sol[] = {19, 22, 43, 50};
    
    gemm(2, gemm_sol, a, b);

    EXPECT_THAT(gemm_sol, testing::Pointwise(testing::DoubleNear(1e-14), sol));
}

// Test higher dimension matrices, negative and fractional numbers
TEST(GemmTest, HigherDimNeg) {
    double a[] = {1, 2, 3, 4, 5.1, 6, 7, 8, -1, -2, -3, -4, -5.1, -6, -7, -8};
    double b[] = {8, 6, 7, 5.1, -4, -2, -3, -1, -8, -6, -7, -5.1, 4, 2, 3, 1};
    double gemm_sol[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    
    double sol[] = {-8, -8, -8, -8.2, -7.2, -7.4, -7.3, -7.69, 8, 8, 8, 8.2, 7.2, 7.4, 7.3, 7.69};
    
    gemm(4, gemm_sol, a, b);

    EXPECT_THAT(gemm_sol, testing::Pointwise(testing::DoubleNear(1e-14), sol));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
