#include <bits/stdc++.h>
using namespace std;
#define int long long
class DSU
{
    vector<int> leader;
    vector<int> sz;

public:
    DSU(int n)
    {
        leader.resize(n, -1);
        sz.resize(n, 0);
    }

    void make_set(int node)
    {
        leader[node] = node;
        sz[node] = 1;
    }

    int main_leader(int node)
    {
        if (node == leader[node])
            return node;

        return leader[node] = main_leader(leader[node]);
    }

    void union_set(int u, int v)
    {
        u = main_leader(u);
        v = main_leader(v);
        if (u == v)
            return;
        if (sz[v] < sz[u])
            swap(u, v);

        leader[u] = v;
        sz[v] += sz[u];
    }
};
void hocusPocus()
{
    int n;
    cin >> n;
    DSU daa(n);
}

signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    hocusPocus();
}