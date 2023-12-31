#include "Header.h"  
#include "gtest/gtest.h"

TEST(MatrixTest, Addition) {
    
    Matrix matrix1(2, 2);
    matrix1.fillMatrix();

    Matrix matrix2(2, 2);
    matrix2.fillMatrix();

    
    Matrix result = matrix1 + matrix2;

  
    EXPECT_EQ(result, expectedMatrix);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

