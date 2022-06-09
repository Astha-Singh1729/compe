#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
pair<int, vector<pair<int, int>>> readAndCheckAnswer(InStream &in)
{
    int a = in.readInt();
    vector<pair<int, int>> vp;
    for (int i = 0; i < a; i++)
    {
        int u = in.readInt();
        int v = in.readInt();
        vp.push_back({u, v});
    }
    return {a, vp};
}
int main(int argc, char *argv[])
{
    registerTestlibCmd(argc, argv);
    int n = inf.readInt();
    int m = inf.readInt();
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        setTestCase(i + 1);
        int u = inf.readInt();
        int v = inf.readInt();
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    pair<int, vector<pair<int, int>>> ja = readAndCheckAnswer(ans);
    pair<int, vector<pair<int, int>>> pa = readAndCheckAnswer(ouf);
    if (ja.first != pa.first)
    {
        quitf(_wa, "wrong minimum number of moves");
    }
    vector<int> check(n);
    int dia = ja.first;
    const auto ans = [&](int u, int &dia) -> void
    {
        int one = -1;
        int mx = -1;
        int two = -1;
        vector<int> visited(n);
        const auto dfs = [&](auto &self, int u, int &node, int d) -> void
        {
            check[u] = true;
            visited[u] = true;
            if (d > mx)
                mx = d, node = u;
            for (int v : adj[u])
                if (!visited[v])
                    self(self, v, node, d + 1);
        };
        dfs(dfs, u, one, 0);
        mx = -1;
        fill(visited.begin(), visited.end(), 0);
        dfs(dfs, one, two, 0);
        dia += mx;
    };
    for (int i = 0; i < n; i++)
        if (!check[i])
            ans(i, dia);
    fill(check.begin(), check.end(), 0);
    for (auto [a, b] : pa.second)
    {
        --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int dia2 = 0;
    ans(0, dia2);
    if (dia != dia2)
    {
        quitf(_wa, "wrong connection of edges");
    }
    for (auto i : check)
        if (!i)
            quitf(_wa, "wrong connection of edges");
    quitf(_ok, "Correct Answer");
}