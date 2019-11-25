#ifndef __UNIT_TEST_HPP__
#define __UNIT_TEST_HPP__
#include "gtest/gtest.h"
#include "/class/classes/jmari016/assignment-rshell/src/Execute.hpp"
#include "/class/classes/jmari016/assignment-rshell/src/ExecuteAND.hpp"
#include "/class/classes/jmari016/assignment-rshell/src/ExecuteOR.hpp"
#include "/class/classes/jmari016/assignment-rshell/src/ExecuteSEMI.hpp"

TEST(ExecuteTest, ExecuteExit) {
	char* arr[] = {"ls", "-a", NULL};
	Execute* exec = new Execute(arr);
	EXPECT_EQ(exec->execute(), true);
}

TEST(ExecuteTest, ExecuteEcho) {
	char* arr[] = {"echo", NULL};
	Execute* execEcho = new Execute(arr);
	EXPECT_EQ(execEcho->execute(), true);
}

TEST(ExecuteTest, Execute) {
}

#endif
