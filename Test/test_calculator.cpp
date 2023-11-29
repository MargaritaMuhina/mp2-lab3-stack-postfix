#include "gtest.h"

#include "..\mp2-lab3-stack-postfix\Calculator.h"



TEST(TCalculator, can_create_calculator)
{
	ASSERT_NO_THROW(TCalculator c);
}

TEST(TCalculator, can_SetInfix_with_non_equal_count_brakets)
{
	TCalculator TCR;
	ASSERT_ANY_THROW(TCR.SetInfix(")((12+(2-5+3+1))"));
}

TEST(TCalculator, can_SetInfix_with_equal_count_brakets)
{
	TCalculator TCR;
	ASSERT_NO_THROW(TCR.SetInfix("((8+(2-5+1)))"));
}

TEST(TCalculator, can_SetInfix_void_TCalculator)
{
	TCalculator TCR;
	ASSERT_NO_THROW(TCR.SetInfix(""));
}

TEST(TCalculator, right_postfix_SetInfix)
{
	TCalculator TCR;
	TCR.SetInfix("1+2");
	TCR.ToPostfix();
	string tmp;
	tmp = ("1 2+");
	ASSERT_EQ(TCR.GetPostfix(), tmp);
}

TEST(TCalculator, can_ToPostfix_empty_string)
{
	TCalculator TCR;
	TCR.SetInfix("");
	ASSERT_NO_THROW(TCR.ToPostfix());
}

TEST(TCalculator, can_ToPostfix_string_with_equal_brackets)
{
	TCalculator TCR;
	TCR.SetInfix("(1+2+(3-4)+5)");
	ASSERT_NO_THROW(TCR.ToPostfix());
}

TEST(TCalculator, right_Calculation)
{
	TCalculator TCR;
	TCR.SetInfix("3+2");
	TCR.ToPostfix();
	ASSERT_EQ(TCR.Calculate(), 5);
}

