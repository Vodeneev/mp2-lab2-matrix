#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, can_create_vector_with_max_size)
{
    ASSERT_NO_THROW(TVector<int> v(MAX_VECTOR_SIZE));
}

TEST(TVector, can_create_vector_with_zero_size)
{
    ASSERT_NO_THROW(TVector<int> v(0));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v(10);
	TVector<int> s(v);
	EXPECT_EQ(v,s);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> s(5), v(s);
	s[0] = 15;
	EXPECT_NE(s[0], v[0]);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> s(10);

	ASSERT_ANY_THROW(s[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> s(10);

	ASSERT_ANY_THROW(s[11]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	TVector<int> s(10);

	s[0] = 1;
	TVector<int> s1(s);
	s = s;
	EXPECT_EQ(s, s1);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	TVector<int> s(10), s1(10);
	s[0] = 1;
	s1 = s;
	EXPECT_EQ(s, s1);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> s(5), s1(10);
	s1 = s;
	EXPECT_EQ(s.GetSize(), s1.GetSize());
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	TVector<int> s(10), s1(5);
	s[0] = 1;
	s1 = s;
	EXPECT_EQ(s, s1);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> s(10), s1(s);
	EXPECT_TRUE(s == s1);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> s(10);
	EXPECT_TRUE(s == s);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> s(10), s1(5);
	EXPECT_TRUE(s != s1);
}

TEST(TVector, can_add_scalar_to_vector)
{
	TVector<int> s(10),s1(10), res(10);
	res = s + 2;
	for (int i = 0; i < 10; i++)
		s1[i] = 2;
	EXPECT_EQ(res, s1);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	TVector<int> s(10), s1(10), res(10);
	res = s -2;
	for (int i = 0; i < 10; i++)
		s1[i] = -2;
	EXPECT_EQ(res, s1);
}


TEST(TVector, can_multiply_scalar_by_vector)
{
	TVector<int> v1(5), v2(5), v3;
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
		v2[i] = 2;
	}
	v3 = v1 * 2;
	EXPECT_EQ(v2, v3);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5), v3(5);
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
		v2[i] = 1;
	}
	v3 = v1 + v2;
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 2;
	}
	EXPECT_EQ(v1, v3);
	
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> s(10), s1(5);
	ASSERT_ANY_THROW(s + s1);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5), v3(5);
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 2;
		v2[i] = 1;
	}
	v3 = v1 - v2;
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
	}
	EXPECT_EQ(v1, v3);

}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> s(10), s1(5);
	ASSERT_ANY_THROW(s - s1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(5), v2(5);
	int res;
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
		v2[i] = 1;
	}
	res = v1 * v2;
	
	EXPECT_EQ(5, res);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> s(10), s1(5);
	ASSERT_ANY_THROW(s * s1);
}

