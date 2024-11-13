/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_case_z)
{
	Password my_password;
	bool rslt = my_password.has_mixed_case("Zz");
	ASSERT_EQ(true, rslt);
}

TEST(PasswordTest, mixed_case_a)
{
	Password my_password;
	bool rslt = my_password.has_mixed_case("Aa");
	ASSERT_EQ(true, rslt);
}

TEST(PasswordTest, non_mixed_case_lower)
{
	Password my_password;
	bool rslt = my_password.has_mixed_case("password");
	ASSERT_EQ(false, rslt);
}

TEST(PasswordTest, non_mixed_case_upper)
{
	Password my_password;
	bool rslt = my_password.has_mixed_case("PASSWORD");
	ASSERT_EQ(false, rslt);
}

TEST(PasswordTest, mixed_case_long)
{
	Password my_password;
	bool rslt = my_password.has_mixed_case("LEKNFdsflknLEKNFslkdfLSDNFKKLKFLKnseknflksmdflklKFNlkfNLKNFDLdksNF");
	ASSERT_EQ(true, rslt);
}

TEST(PasswordTest, mixed_case_with_special_chars)
{
	Password my_password;
	bool rslt = my_password.has_mixed_case(";:_*&^%$#@%^&*()");
	ASSERT_EQ(false, rslt);
}

TEST(PasswordTest, mixed_case_with_special_chars_and_true)
{
	Password my_password;
	bool rslt = my_password.has_mixed_case(";:_*&^%$#@%^&*()Aa");
	ASSERT_EQ(true, rslt);
}