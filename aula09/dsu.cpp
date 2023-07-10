#include <bits/stdc++.h>

using namespace std;

const inx MAXN = 1e5 + 5;

int dsu[MAXN], sz[MAXN];

void init(int n) {
    for (int i = 0; i < n; i++) {
        dsu[i] = i;
        sz[i] = 1;
    }
}

int find(int u) {
    if (dsu[u] == u) return u;
    return dsu[u] = find(dsu[u]);
}

void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;
    if (sz[u] < sz[v]) swap(u, v);
    dsu[v] = u;
    sz[u] += sz[v];
}