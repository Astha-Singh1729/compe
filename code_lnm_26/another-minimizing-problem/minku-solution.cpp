#include <bits/stdc++.h>
using namespace std;
#define int long long

struct SegTreeItem
{
    int element;
};

class LazySegTree
{
public:
    LazySegTree(int n)
    {
        this->nodes.resize(4 * n + 5, this->null);
        this->lazy.resize(4 * n + 5, {0});
        this->pendingLazy.resize(4 * n + 5, false);
        this->size = n;
    }
    void pointUpdate(int x, SegTreeItem val, int index, int l, int r)
    {
        if (pendingLazy[index])
            propagateLazy(index, l, r);
        if (x < l || x >= r)
            return;
        if (l == x && r == x + 1)
        {
            nodes[index] = val;
            return;
        }
        pointUpdate(x, val, 2 * index, l, (r + l) / 2);
        pointUpdate(x, val, 2 * index + 1, (r + l) / 2, r);
        nodes[index] = merge(nodes[2 * index], nodes[2 * index + 1]);
    }
    void rangeUpdate(int x, int y, SegTreeItem val, int index, int l, int r)
    {
        if (pendingLazy[index])
            propagateLazy(index, l, r);
        if (y <= l || x >= r)
            return;
        if (l >= x && r <= y)
        {
            pendingLazy[index] = true;
            lazy[index] = val;
            propagateLazy(index, l, r);
            return;
        }
        rangeUpdate(x, y, val, 2 * index, l, (r + l) / 2);
        rangeUpdate(x, y, val, 2 * index + 1, (r + l) / 2, r);
        nodes[index] = merge(nodes[2 * index], nodes[2 * index + 1]);
    }
    SegTreeItem query(int x, int y, int index, int l, int r)
    {
        if (pendingLazy[index])
            propagateLazy(index, l, r);
        if (y <= l || x >= r)
            return this->null;
        if (l >= x && r <= y)
            return nodes[index];
        return merge(query(x, y, 2 * index, l, (r + l) / 2), query(x, y, 2 * index + 1, (r + l) / 2, r));
    }
    void pointUpdate(int x, int val)
    {
        pointUpdate(x, {val}, 1, 0, size);
    }
    void rangeUpdate(int x, int y, int val)
    {
        rangeUpdate(x, y, {val}, 1, 0, size);
    }
    SegTreeItem query(int x, int y)
    {
        return query(x, y, 1, 0, size);
    }

private:
    vector<SegTreeItem> nodes, lazy;
    vector<bool> pendingLazy;
    SegTreeItem null = {0};
    int size;
    void propagateLazy(int index, int l, int r)
    {
        if (l != r - 1)
        {
            pendingLazy[2 * index] = true;
            pendingLazy[2 * index + 1] = true;
            lazy[2 * index].element = lazy[index].element;
            lazy[2 * index + 1].element = lazy[index].element;
        }
        nodes[index].element = lazy[index].element * (r - l);
        lazy[index].element = 0;
        pendingLazy[index] = false;
    }
    SegTreeItem merge(SegTreeItem a, SegTreeItem b)
    {
        SegTreeItem result;
        result.element = a.element + b.element;
        return result;
    }
};

void solveCase()
{
    int n = 0, q = 0;
    cin >> n >> q;
    LazySegTree st(n);
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        cin >> x;
        st.pointUpdate(i, x);
    }

    while (q--)
    {
        int t = 0;
        cin >> t;
        if (t == 2)
        {
            int lf = 0;
            cin >> lf;
            lf--;

            int pref = st.query(0, lf).element;
            const auto calc = [&](int x) -> int
            {
                return abs(pref + st.query(x, n).element - st.query(lf, x).element);
            };

            int l = lf + 1, r = n;
            while (l < r - 2)
            {
                int mid1 = l + (r - l) / 3;
                int mid2 = r - (r - l) / 3;

                int c1 = calc(mid1), c2 = calc(mid2);
                if (c1 > c2)
                    l = mid1 + 1;
                else if (c2 > c1)
                    r = mid2 - 1;
                else
                    r = mid2;
            }

            int ans = INT64_MAX, rf = 0;
            for (int i = l; i <= r; i++)
                if (ans > calc(i))
                    rf = i, ans = calc(i);
            cout << rf << '\n';
        }
        else
        {
            int l = 0, r = 0, x = 0;
            cin >> l >> r >> x;
            st.rangeUpdate(l - 1, r, x);
        }
    }
}

int32_t main()
{
    mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
    if (rng() % 100000 == 0)
        assert(false);

    ios::sync_with_stdio(false), cin.tie(NULL);
    solveCase();
}