// main.cpp
#include <class1.h>
#include <gtest/gtest.h>
#include "class1.h"

namespace {

// The fixture for testing class Class1.
class Class1Test : public ::testing::Test {
 protected:
  // You can remove any or all of the following functions if its body
  // is empty.

  Class1Test() {
    // You can do set-up work for each test here.
	cl1 = new Class1();
  }

  virtual ~Class1Test() {
    // You can do clean-up work that doesn't throw exceptions here.
	delete cl1;
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }

  // Objects declared here can be used by all tests in the test case for Class1.
	Class1* cl1{nullptr};
};

// Tests that the Class1::IsOkay() method returns correct default value.
TEST_F(Class1Test, MethodIsOkayDefaultFalse) {
  Class1 f;
  EXPECT_EQ(false, f.IsOkay());
}

// Tests that the Class1::SetOkay() method works.
TEST_F(Class1Test, MethodSetOkayWorks) {
  EXPECT_EQ(false, cl1->IsOkay());
  cl1->SetOkay(EAnswer::YES);
  EXPECT_EQ(true, cl1->IsOkay());
  cl1->SetOkay(EAnswer::NO);
  EXPECT_EQ(false, cl1->IsOkay());
}

}  // namespace

int main(int argc, char **argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
	return 0;
}