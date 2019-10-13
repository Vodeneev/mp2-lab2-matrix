#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> s(5);
	TMatrix<int> v(s);
	EXPECT_EQ(v, s);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> s(5), v(s);
	s[0][0] = 15;
	EXPECT_NE(s[0][0], v[0][0]);

}

TEST(TMatrix, can_get_size)
{
	TMatrix <int> s(3);

	EXPECT_EQ(3, s.GetSize());
  
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix <int> s(5);

	s[0][0] = 2;
	EXPECT_EQ(2, s[0][0]);


}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> s (10);
	
	ASSERT_ANY_THROW(s[-1][0]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> s(10);

	ASSERT_ANY_THROW(s[11][0]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix<int> s(10);
	
	s[0][0] = 1;
	TMatrix<int> s1(s);
	s = s;
	EXPECT_EQ(s,s1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix<int> s(10),s1(10);
	s[0][0] = 1;
	s1 = s;
	EXPECT_EQ(s, s1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> s(5), s1(10);
	s1 = s;
	EXPECT_EQ(s.GetSize(), s1.GetSize());
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix<int> s(10), s1(5);
	s[0][0] = 1;
	s1 = s;
	EXPECT_EQ(s, s1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> s(10), s1(s);
	EXPECT_TRUE (s == s1);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> s(10);
	EXPECT_TRUE(s == s);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> s(10), s1(5);
	EXPECT_TRUE(s != s1);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{

	TMatrix<int> s(10), s1(10), s2(10);
	s[0][0] = 1;
	s2 = s1 + s;
	
	EXPECT_EQ(s2[0][0], 1);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> s(10), s1(5);
	ASSERT_ANY_THROW(s + s1);

}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> s(10), s1(10), s2(10);
	s[0][0] = 2;
	s2 = s + s1;

	EXPECT_EQ(s2[0][0], 2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> s(10), s1(5);
	ASSERT_ANY_THROW(s - s1);
}

