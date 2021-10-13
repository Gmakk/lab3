#include "pch.h"
#include "Plate.h"
TEST(PlatePlusPlate, correct) {
	Contact array1[3] = {
		{0,5,6,INT_MAX},
		{0,-5,-5,2},
		{1,50,50,1}
	};
	Contact array2[3] = {
		{1,2,3,INT_MAX},
		{0,-9,-4,7},
		{1,5,42,34}
	};
	Plate plate1(3, array1);
	Plate plate2(3, array2);
	Plate* result;
	result = plate1 + plate2;
	EXPECT_EQ(result->getArr()[0].x, 5);
	EXPECT_EQ(result->getArr()[0].y, 6);
	EXPECT_EQ(result->getArr()[0].type, 0);
	EXPECT_EQ(result->getArr()[0].number, INT_MAX);
	EXPECT_EQ(result->getArr()[4].x, -9);
	EXPECT_EQ(result->getArr()[4].y, -4);
	EXPECT_EQ(result->getArr()[4].type, 0);
	EXPECT_EQ(result->getArr()[4].number, 7);
}

TEST(Equating,Array){
	Contact array[3] = {
			{0,5,6,INT_MAX},
			{0,-5,-5,2},
			{1,50,50,1}
	};
	Plate plate1, plate2(3,array);
	plate1 = plate2;
	EXPECT_EQ(plate1.getArr()[1].x, -5);
	EXPECT_EQ(plate1.getArr()[1].y, -5);
	EXPECT_EQ(plate1.getArr()[1].type, 0);
	EXPECT_EQ(plate1.getArr()[1].number, 2);
}

TEST(Index,FirstElement) {
	Plate plate(5, 7, 0);
	EXPECT_EQ(plate[0].x, 5);
	EXPECT_EQ(plate[0].y, 7);
	EXPECT_EQ(plate[0].type, 0);
	EXPECT_EQ(plate[0].number, INT_MAX);
}

TEST(PlatePlusPlate, incorrect) {
	Contact array1[Size] = { 0 };
	Contact array2[3] = {
		{1,2,3,INT_MAX},
		{0,-9,-4,7},
		{1,5,42,34}
	};
	Plate plate1(3, array1);
	Plate plate2(3, array2);
	Plate* result;
	try {
		result = plate1 + plate2;
	}
	catch (std::exception ex) {
		ASSERT_STREQ(ex.what(), "Not enough space\n");
	}
}

TEST(PlusEqually, correct) {
	Plate plate;
	plate += 1;
	EXPECT_EQ(plate.getArr()[0].x, 0);
	EXPECT_EQ(plate.getArr()[0].y, 0);
	EXPECT_EQ(plate.getArr()[0].type, 0);
	EXPECT_EQ(plate.getArr()[0].number, INT_MAX);
}

TEST(PlusEqually, incorrect) {
	Plate plate;
	try {
		plate += 11;
	}
	catch (std::exception ex) {
		ASSERT_STREQ(ex.what(), "Not enough space\n");
	}
}

TEST(MinusEqually, correct) {
	Plate plate;
	plate += 1;
	plate -= 1;
	EXPECT_EQ(plate.deleteContact(), -1);
}

TEST(MinusEqually, incorrect) {
	Plate plate;
	try {
		plate -= 1;
	}
	catch (std::exception ex) {
		ASSERT_STREQ(ex.what(), "Not enough elements\n");
	}
}

TEST(Inequality, correct) {
	Plate plate1, plate2;
	ASSERT_FALSE(plate1 != plate2);
}

TEST(Inequality, incorrect) {
	Plate plate1, plate2;
	plate1++;
	ASSERT_TRUE(plate1 != plate2);
}

TEST(Equality, correct) {
	Plate plate1, plate2;
	ASSERT_TRUE(plate1 == plate2);
}

TEST(Equality, incorrect) {
	Plate plate1, plate2;
	plate1++;
	ASSERT_FALSE(plate1 == plate2);
}

TEST(Less, correct) {
	Plate plate1, plate2;
	++plate1;
	ASSERT_TRUE(plate2 < plate1);
}

TEST(Less, incorrect) {
	Plate plate1, plate2;
	++plate1;
	ASSERT_FALSE(plate1 < plate2);
}

TEST(More, correct) {
	Plate plate1, plate2;
	++plate1;
	ASSERT_FALSE(plate2 > plate1);
}

TEST(More, incorrect) {
	Plate plate1, plate2;
	++plate1;
	ASSERT_TRUE(plate1 > plate2);
}

TEST(LessEqually, correct) {
	Plate plate1, plate2;
	++plate1;
	ASSERT_TRUE(plate2 <= plate1);
}

TEST(LessEqually, equally) {
	Plate plate1, plate2;
	++plate1;
	++plate2;
	ASSERT_TRUE(plate2 <= plate1);
}

TEST(LessEqually, incorrect) {
	Plate plate1, plate2;
	++plate1;
	ASSERT_FALSE(plate1 <= plate2);
}

TEST(MoreEqually, correct) {
	Plate plate1, plate2;
	++plate1;
	ASSERT_FALSE(plate2 >= plate1);
}

TEST(MoreEqually, Equally) {
	Plate plate1, plate2;
	++plate1;
	++plate2;
	ASSERT_TRUE(plate2 >= plate1);
}

TEST(MoreEqually, incorrect) {
	Plate plate1, plate2;
	++plate1;
	ASSERT_TRUE(plate1 >= plate2);
}


TEST(PlusPlus, prefix) {
	Plate plate;
	++plate;
	EXPECT_EQ(plate.getArr()[0].x, 0);
	EXPECT_EQ(plate.getArr()[0].y, 0);
	EXPECT_EQ(plate.getArr()[0].type, 0);
	EXPECT_EQ(plate.getArr()[0].number, INT_MAX);
}

TEST(PlusPlus, postfix) {
	Plate plate;
	plate++;
	EXPECT_NE(plate.getArr()[0].x, 0);
	EXPECT_NE(plate.getArr()[0].y, 0);
	EXPECT_NE(plate.getArr()[0].type, 0);
	EXPECT_NE(plate.getArr()[0].number, INT_MAX);
}

TEST(MinusMinus, postfix) {
	Plate plate;
	++plate;
	plate--;
	EXPECT_EQ(plate.deleteContact(), -1);
}

TEST(MinusMinus, prefix) {
	Plate plate;
	++plate;
	--plate;
	EXPECT_EQ(plate.deleteContact(), -1);
}