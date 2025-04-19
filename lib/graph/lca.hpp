#include <cstdint>
#include <vector>
using namespace std;
using ll = int64_t;
//------------------------------------------------------------------------------

// FYI: https://algo-logic.info/lca/

struct Edge {
   ll to;
};
using Graph = vector<vector<Edge>>;

struct LCA {
   // parent[k][u] := The 2^k-th parent of the node u
   vector<vector<ll>> parents;
   // The distance from the root node
   vector<ll> dists;

   LCA(const Graph &G, ll root = 0) {
      ll V = G.size();
      ll K = 1;
      while ((1LL << K) < V) K++;
      parents.assign(K, vector<ll>(V, -1));
      dists.assign(V, -1);
      dfs(G, root, -1, 0);
      for (ll k = 0; k + 1 < K; k++) {
         for (ll v = 0; v < V; v++) {
            if (parents[k][v] < 0) {
               parents[k + 1][v] = -1;
            } else {
               parents[k + 1][v] = parents[k][parents[k][v]];
            }
         }
      }
   }

   void dfs(const Graph &G, ll v, ll p, ll d) {
      parents[0][v] = p;
      dists[v] = d;
      for (auto e : G[v]) {
         if (e.to != p) dfs(G, e.to, v, d + 1);
      }
   }

   ll query(ll u, ll v) {
      if (dists[u] < dists[v]) swap(u, v);
      ll K = parents.size();

      for (ll k = 0; k < K; k++) {
         if ((dists[u] - dists[v]) >> k & 1) {
            u = parents[k][u];
         }
      }

      if (u == v) return u;
      for (ll k = K - 1; k >= 0; k--) {
         if (parents[k][u] != parents[k][v]) {
            u = parents[k][u];
            v = parents[k][v];
         }
      }

      return parents[0][u];
   }
};
