#define PROBLEM \
   "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include <bits/stdc++.h>
#include "../prime.hpp"
using namespace std;
using ll = int64_t;
using ull = uint64_t;
using ld = long double;
template <typename T, typename V>
void chmax(T& target, const V& cand) {
   target = max(target, static_cast<T>(cand));
}
template <typename T, typename V>
void chmin(T& target, const V& cand) {
   target = min(target, static_cast<T>(cand));
}
#define fae(type, var, from, to) \
   for (type var = static_cast<type>(from); var < static_cast<type>(to); ++var)
#define fai(type, var, from, to) \
   for (type var = static_cast<type>(from); var <= static_cast<type>(to); ++var)
#define fdi(type, var, from, to) \
   for (type var = static_cast<type>(from); var >= static_cast<type>(to); --var)
template <typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
int main() {
   ll N;
   cin >> N;
   auto res = prime_factorize<ll, ll>(N);

   cout << N << ":";
   for (auto [p, e] : res) {
      fae(ll, j, 0, e) { cout << " " << p; }
   }
   cout << "\n";
   return 0;
}
