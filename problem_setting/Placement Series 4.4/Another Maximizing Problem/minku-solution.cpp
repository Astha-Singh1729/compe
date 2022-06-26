#include <bits/stdc++.h>
using namespace std;
#define int long long

void solveCase()
{
    int n = 0;
    cin >> n;
    struct node
    {
        int val;
        node *l, *r;
        int res, res2;
        node(int v) : val(v), l(nullptr), r(nullptr), res(LLONG_MIN), res2(0)
        {
        }
    };
    vector<node *> nodes(n);
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        nodes[i] = new node(x);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u = 0, v = 0, d = 0;
        cin >> u >> v >> d;
        u--, v--;
        (d ? nodes[u]->r : nodes[u]->l) = nodes[v];
    }

    int ans = 0;
    const auto getr = [&](node *u) -> int
    { return u ? u->res : 0; };
    const auto getr2 = [&](node *u) -> int
    { return u ? u->res2 : 0; };
    const auto dfs = [&](const auto &self, node *u) -> void
    {
        if (!u)
            return;

        self(self, u->l);
        self(self, u->r);

        u->res = u->val + max({0LL, getr(u->l), getr(u->r)});
        u->res2 = max({0LL, getr(u->l), getr(u->r), u->val + max(getr2(u->l), getr2(u->r))});

        ans = max({ans, u->res, u->val + getr(u->l) + getr(u->r)});
        ans = max({ans, getr(u->l) + getr(u->r), u->val + max(getr2(u->l) + getr(u->r), getr(u->l) + getr2(u->r))});
    };
    dfs(dfs, nodes[0]);

    cout << ans;
}

int32_t main()
{
    mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
    if (rng() % 100000 == 0)
        assert(false);

    ios::sync_with_stdio(false), cin.tie(NULL);
    solveCase();
}
