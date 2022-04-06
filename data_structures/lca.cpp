#include <bits/stdc++.h>
using namespace std;
#define int long long
void hocusPocus()
{
    int n, q;
    cin >> n >> q;
    const auto LOG2 = [&](int n)
    {
        for (int i = 60; i > 0; i--)
            if ((n >> i) & 1)
                return i;
        return 0LL;
    };
    int sz = LOG2(n) + 1;
    set<int> s;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        --x;
        adj[i + 1].push_back(x);
        adj[x].push_back(i + 1);
    }
    vector<vector<int>> ancestors(n, vector<int>(sz + 1));
    vector<int> tin(n);
    vector<int> tout(n);
    int tc = 0;
    const auto dfs = [&](auto &self, int u, int p) -> void
    {
        tc++;
        tin[u] = tc;
        ancestors[u][0] = p;
        for (int i = 1; i <= sz; i++)
            ancestors[u][i] = ancestors[ancestors[u][i - 1]][i - 1];
        for (auto v : adj[u])
            if (p != v)
                self(self, v, u);
        tout[u] = tc;
    };
    dfs(dfs, 0, 0);
    const auto is_ancestor = [&](int a, int b)
    {
        return (tin[a] <= tin[b] && tout[a] >= tout[b]);
    };
    const auto gib_ancestor = [&](auto &self, int a, int b) -> int
    {
        if (is_ancestor(a, b))
            return a;
        if (is_ancestor(b, a))
            return b;

        int ind = -1;
        for (int i = 0; i <= sz && ind == -1; i++)
            if (is_ancestor(ancestors[a][i], b))
                ind = i;

        if (ind == 0)
            return ancestors[a][0];
        return self(self, ancestors[a][ind - 1], b);
    };
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        int prayge = gib_ancestor(gib_ancestor, u - 1, v - 1) + 1;
        cout << prayge << endl;
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    hocusPocus();
}