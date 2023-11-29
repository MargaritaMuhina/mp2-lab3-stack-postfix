#include "..\mp2-lab3-stack-postfix\Stack.h"

#include "gtest.h"

TEST(TStack, can_create_empty_stack_with_positive_length)
{
	ASSERT_NO_THROW(TStack<int> stack);
}

TEST(TStack, throws_when_create_stack_with_negative_length)
{
	ASSERT_ANY_THROW(TStack<int> stack(-2));
}

TEST(TStack, can_push_element)
{
	TStack<int> stack(2);
	stack.Push(28);
	EXPECT_EQ(stack.GetSize(), 1);
}


TEST(TStack, can_pop_element)
{
	TStack<int> stack(2);
	stack.Push(1);
	stack.Push(2);
	EXPECT_EQ(stack.Pop(), 2);
}

TEST(TStack, can_not_pop_element_when_stack_is_empty)
{
	TStack<int> stack(2);
	stack.Push(16);
	stack.Pop();
	ASSERT_ANY_THROW(stack.Pop());
}
TEST(TStack, can_check_if_stack_is_full)
{
	TStack<int> stack(2);
	stack.Push(3);
	stack.Push(3);
	EXPECT_EQ(stack.IsFull(), true);

}

TEST(TStack, can_check_if_stack_is_empty)
{
	TStack<int> stack;
	EXPECT_EQ(stack.IsEmpty(), true);
	stack.Push(3);
	EXPECT_EQ(stack.IsEmpty(), false);
	stack.Pop();
	EXPECT_EQ(stack.IsEmpty(), true);
}

TEST(TStack, can_delete_all_elements)
{
	TStack<int> stack;
	stack.Push(15);
	stack.Push(-3);
	stack.Clear();
	EXPECT_EQ(stack.IsEmpty(), true);
}

TEST(TStack, can_get_Value_element)
{
	TStack<int> stack;
	stack.Push(5);
	stack.Push(12);
	EXPECT_EQ(stack.Top(), 12);
}