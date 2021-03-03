#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C" {
#include "gemm.h"
}

TEST(GemmTest, SimpleGemm) {
    int eye[] = {1, 0, 0, 1};
    int incr[] = {1, 2, 3, 4};
    int gemm_sol[] = {0, 0, 0, 0};
    
    int sol[] = {1, 2, 3, 4};
    
    gemm(2, gemm_sol, incr, eye);

    EXPECT_THAT(gemm_sol, testing::ContainerEq(sol));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
