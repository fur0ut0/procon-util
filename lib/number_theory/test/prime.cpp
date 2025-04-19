#include "../prime.hpp"
#include <gtest/gtest.h>

TEST(is_prime, positive_small) { ASSERT_EQ(is_prime(99991LL), true); }
TEST(is_prime, positive_medium) { ASSERT_EQ(is_prime(524287LL), true); }
TEST(is_prime, positive_large) { ASSERT_EQ(is_prime(472194691LL), true); }
TEST(is_prime, negative_0) { ASSERT_EQ(is_prime(2013LL), false); }
TEST(is_prime, negative_1) { ASSERT_EQ(is_prime(2023LL), false); }

// TODO: sieve
