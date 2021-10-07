#include "pch.h"
#include "Plate.h"

TEST(AddConact, CorrectValues) {
	Plate plate;
	EXPECT_EQ(plate.addContact(6, -10, 0), 1);
}

TEST(AddConact, IncorrectValues) {
	Plate plate;
	EXPECT_EQ(plate.addContact(6, -10, 6), -1);
}

TEST(Correctness, BothValues) {
	Plate plate;
	plate.addContact(1, 1, 0);
	plate.addContact(2, 2, 1);
	plate.addLink(0, 1);
	EXPECT_EQ(plate.correctness(0), 1);
	EXPECT_EQ(plate.correctness(1), 1);
}

TEST(Correctness, WithoutConnection) {
	Plate plate;
	plate.addContact(1, 1, 0);
	plate.addContact(2, 2, 1);
	EXPECT_EQ(plate.correctness(0), 2);
	EXPECT_EQ(plate.correctness(1), 2);
}

TEST(AddLink, IncorrectTypes1) {
	Plate plate;
	plate.addContact(1, 1, 1);
	plate.addContact(2, 2, 1);
	plate.addLink(1, 0);
	EXPECT_EQ(plate.correctness(0), 2);
	EXPECT_EQ(plate.correctness(1), 2);
}

TEST(AddLink, IncorrectTypes2) {
	Plate plate;
	plate.addContact(1, 1, 0);
	plate.addContact(2, 2, 1);
	plate.addLink(1, 0);
	EXPECT_EQ(plate.correctness(0), 2);
	EXPECT_EQ(plate.correctness(1), 2);
}

TEST(FindLength, PositiveValues) {
	Plate plate;
	plate.addContact(1, 1, 0);
	plate.addContact(2, 2, 1);
	plate.addLink(0, 1);
	EXPECT_FLOAT_EQ(plate.pathLength(0,1), 1.4142135);
}

TEST(FindLength, NegativeValues) {
	Plate plate;
	plate.addContact(-1, -1, 0);
	plate.addContact(2, 2, 1);
	plate.addLink(0, 1);
	EXPECT_FLOAT_EQ(plate.pathLength(0, 1), 4.24264);
}