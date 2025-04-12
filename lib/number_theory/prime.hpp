#include <vector>
using namespace std;

//------------------------------------------------------------------------------

/**
 * @note 1 and n are not included in the result.
 * @note O(sqrt(N))
 */
template <typename T>
vector<T> factorize(T n) {
   vector<T> v;
   for (T i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
         v.push_back(i);
         if (i * i < n) {
            v.push_back(n / i);
         }
      }
   }
   return v;
}

/**
 * @return The pairs of prime and its exponent value
 * @note O(sqrt(N))
 */
template <typename I, typename T>
vector<pair<T, I>> prime_factorize(T n) {
   if (n == 1) return {};

   vector<pair<T, I>> v;
   for (T i = 2; i * i <= n; ++i) {
      I e = 0;
      while (n % i == 0) {
         ++e;
         n /= i;
      }
      if (e > 0) {
         v.push_back({i, e});
      }
   }
   if (n > 1) {
      v.push_back({n, 1});
   }
   return v;
}

/**
 * @note O(sqrt(N))
 */
template <typename T>
bool is_prime(T n) {
   for (T i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
         return false;
      }
   }
   return true;
}

/**
 * @return The list of prime numbers in the range [2, n]
 */
template <typename T>
vector<T> sieve(T n) {
   vector<T> primes;

   vector<bool> is_prime(n + 1, true);
   is_prime[0] = false;
   is_prime[1] = false;
   for (T i = 2; i <= n; ++i) {
      if (is_prime[i]) {
         primes.push_back(i);
         for (T j = 2 * i; j <= n; j += i) {
            is_prime[j] = false;
         }
      }
   }
   return primes;
}
