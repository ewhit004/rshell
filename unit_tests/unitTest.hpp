#ifndef __UNIT_TEST_HPP__
#define __UNIT_TEST_HPP__
#include "gtest/gtest.h"
#include "../src/Execute.hpp"
#include "../src/ExecuteAND.hpp"
#include "../src/ExecuteOR.hpp"
#include "../src/ExecuteSEMI.hpp"

TEST(ExecuteTest, ExecuteLS) {
	vector<string> str1 = {"ls", "-a"};
	Execute* exec = new Execute(str1);
	EXPECT_EQ(exec->execute(), true);
}

TEST(ExecuteTest, ExecuteEcho) {
	vector<string> str2 = {"echo", "hello world"};
	Execute* execEcho = new Execute(str2);
	EXPECT_EQ(execEcho->execute(), true);
}

TEST(ExecuteTest, ExecuteEch) {  //test that SHOULD fail; improper testing of "echo"
	vector<string> str3 = {"ech", "hello world"};
	Execute* execEch = new Execute(str3);
	EXPECT_EQ(execEch->execute(), false);
}

TEST(ExecuteTest, ExecuteGit) {
	vector<string> str4 = {"git", "status"}
	Execute* execGit = new Execute(str4);
	EXPECT_EQ(execGit->execute(), true);
}

TEST(ExecuteTest, ExecuteConAnd) {
	vector<string> str5 = //create left execute and right execute and perculate down
	Execute* execConAnd = new Execute(str5);
	EXPECT_EQ(execConAnd->execute(), true);
}

TEST(ExecuteTest, ExecuteConOr) {
	vector<string> str6 = //create left execute and right execute and perculate down
	Execute* execConOr = new Execute(str6);
	EXPECT_EQ(execConOr->execute(), true);
}
#endif
