#include <gtest/gtest.h>
#include "three.h"

TEST(ThreeInit, FillConstructorNotZero)
{
	// Arrange
	Three three(500);
	size_t size = three.getSize();
	size_t expectedSize = 6;
	unsigned char* threeArray = three.getThreeArray();
	unsigned char expectedArray[] = {'2', '1', '1', '0', '0', '2'};

	// Assert
    ASSERT_EQ(size, expectedSize);
	for (size_t i = 0; i < size; i++) 
		ASSERT_EQ(threeArray[i], expectedArray[i]);
}

TEST(ThreeInit, FillConstructorZero)
{
	// Arrange
	Three three(0);
	size_t size = three.getSize();
	size_t expectedSize = 1;
	unsigned char* threeArray = three.getThreeArray();
	unsigned char expectedArray[] = {'0'};

	// Assert
    ASSERT_EQ(size, expectedSize);
	for (size_t i = 0; i < size; i++) 
		ASSERT_EQ(threeArray[i], expectedArray[i]);
}

TEST(ThreeInit, DefaultConstructor)
{
	Three three;
	size_t size = three.getSize();
	size_t expectedSize = 0;
	unsigned char* threeArray = three.getThreeArray();

	ASSERT_EQ(size, 0);
	ASSERT_EQ(threeArray, nullptr);
}

TEST(ThreeInit, CopyStringConstructorNotZero)
{
	Three three("10");
	size_t size = three.getSize();
	size_t expectedSize = 2;
	unsigned char* threeArray = three.getThreeArray();
	unsigned char expectedArray[] = {'0', '1'};

	ASSERT_EQ(size, expectedSize);
	for (size_t i = 0; i < size; i++) 
		ASSERT_EQ(threeArray[i], expectedArray[i]);
}

TEST(ThreeInit, CopyStringConstructorZero)
{
	Three three("0");
	size_t size = three.getSize();
	size_t expectedSize = 1;
	unsigned char* threeArray = three.getThreeArray();
	unsigned char expectedArray[] = {'0'};

	ASSERT_EQ(size, expectedSize);
	for (size_t i = 0; i < size; i++) 
		ASSERT_EQ(threeArray[i], expectedArray[i]);
}

TEST(ThreeInit, CopyStringConstructorInvalidArgument)
{
	EXPECT_THROW(Three three("101001310010"), std::invalid_argument);
}

TEST(ThreeInit, InitializerListConstructorNotZero) {
	Three three {'1', '2', '0'};
	size_t size = three.getSize();
	size_t expectedSize = 3;
	unsigned char* threeArray = three.getThreeArray();
	unsigned char expectedArray[] = {'0', '2', '1'};

	// Assert
    ASSERT_EQ(size, expectedSize);
	for (size_t i = 0; i < size; i++) 
		ASSERT_EQ(threeArray[i], expectedArray[i]);
}

TEST(ThreeInit, InitializerListConstructorZero) {
	Three three {'0'};
	size_t size = three.getSize();
	size_t expectedSize = 1;
	unsigned char* threeArray = three.getThreeArray();
	unsigned char expectedArray[] = {'0'};

	// Assert
    ASSERT_EQ(size, expectedSize);
	for (size_t i = 0; i < size; i++) 
		ASSERT_EQ(threeArray[i], expectedArray[i]);
}

TEST(ThreeInit, CopyConstructor) {
	Three three1(500);
	Three three(three1);
	size_t size = three.getSize();
	size_t expectedSize = 6;
	unsigned char* threeArray = three.getThreeArray();
	unsigned char expectedArray[] = {'2', '1', '1', '0', '0', '2'};

	// Assert
    ASSERT_EQ(size, expectedSize);
	for (size_t i = 0; i < size; i++) 
		ASSERT_EQ(threeArray[i], expectedArray[i]);
}

TEST(ThreeInit, MoveConstructor) {
	Three three1(500);
	Three three(std::move(three1));
	size_t size = three.getSize();
	size_t expectedSize = 6;
	unsigned char* threeArray = three.getThreeArray();
	unsigned char expectedArray[] = {'2', '1', '1', '0', '0', '2'};

	// Assert
    ASSERT_EQ(size, expectedSize);
	for (size_t i = 0; i < size; i++) 
		ASSERT_EQ(threeArray[i], expectedArray[i]);
}

TEST(ThreeOperators, OperatorPlus) {
	// Arrange
	Three three1("1010101");
	Three three2("101010");
	unsigned char expectedArray[] = {'1', '1', '1', '1', '1', '1', '1'};

	// Act
	Three three3 = three1 + three2;
	unsigned char* threeArray = three3.getThreeArray();

	// Assert
	for (size_t i = 0; i < three3.getSize(); i++) 
		ASSERT_EQ(threeArray[i], expectedArray[i]);

}

TEST(ThreeOperators, OperatorPlusThree) {
	// Arrange
	Three three1("1010101");
	Three three2("202020");
	unsigned char expectedArray[] = {'1', '2', '1', '2', '1', '2', '1'};

	// Act
	Three three3 = three1 + three2;
	unsigned char* threeArray = three3.getThreeArray();

	// Assert
	for (size_t i = 0; i < three3.getSize(); i++) 
		ASSERT_EQ(threeArray[i], expectedArray[i]);

}

TEST(ThreeOperators, OperatorMinus) {
	// Arrange
	Three three1("1111");
	Three three2("1111");
	unsigned char expectedArray[] = {'0'};

	// Act
	Three three3 = three1 - three2;
	unsigned char* threeArray = three3.getThreeArray();

	// Assert
	for (size_t i = 0; i < three3.getSize(); i++) 
		ASSERT_EQ(threeArray[i], expectedArray[i]);

}

TEST(ThreeOperators, OperatorsCompare) {
	// Arrange
	Three three1("1110");
	Three three2("1111");
	Three three3("1111");

	// Assert
	ASSERT_TRUE(three2 > three1);
	ASSERT_TRUE(three1 < three2);
	ASSERT_TRUE(three2 == three3);
	ASSERT_TRUE(three2 != three1);

	ASSERT_FALSE(three2 < three1);
	ASSERT_FALSE(three1 > three2);
	ASSERT_FALSE(three2 == three1);
	ASSERT_FALSE(three2 != three3);

}

TEST(ThreePrint, DefaultPrint) {
	
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}