#define PROBLEM \
   "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C"

#include <bits/stdc++.h>
#include "../lca.hpp"
using namespace std;
// using ll = int64_t;
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
   Graph G(N);
   fae(ll, i, 0, N) {
      ll K;
      cin >> K;
      fae(ll, j, 0, K) {
         ll C;
         cin >> C;
         G[i].push_back({C});
      }
   }

   LCA lca(G);

   ll Q;
   cin >> Q;
   fae(ll, i, 0, Q) {
      ll U, V;
      cin >> U >> V;
      cout << lca.query(U, V) << "\n";
   }

   return 0;
}
