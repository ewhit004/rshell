#ifndef __UNIT_TEST_HPP__
#define __UNIT_TEST_HPP__
#include "gtest/gtest.h"
#include "../src/Execute.hpp"
#include "../src/ExecuteAND.hpp"
#include "../src/ExecuteOR.hpp"
#include "../src/ExecuteSEMI.hpp"

TEST(ExecuteTest, ExecuteExit) {
	//char* arr[] = {"ls", "-a"};
	//Execute* exec = new Execute(arr, 2);
	//EXPECT_EQ(exec->execute(), true);
}

TEST(ExecuteTest, ExecuteEcho) {
	vector<string> str = {"echo", NULL};
	Execute* execEcho = new Execute(str);
	EXPECT_EQ(execEcho->execute(), true);
}

TEST(ExecuteTest, Execute) {
}

#endif
