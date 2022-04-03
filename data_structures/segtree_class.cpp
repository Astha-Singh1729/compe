#include <bits/stdc++.h>
using namespace std;
#define int long long
class segU
{
    struct element
    {
        int value;
    };
    int n;
    vector<element> t;
    element null = {0};

    void point_update(int v, int l, int r, element value, int pos)
    {

        if (r - l == 1)
        {
            t[v] = value;
            return;
        }

        int mid = (l + r) / 2;
        if (pos < mid)
            point_update(v * 2, l, mid, value, pos);
        else
            point_update(v * 2 + 1, mid, r, value, pos);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    element ans_chahiye(int l, int r, int ql, int qr, int v)
    {
        if (l >= ql && r <= qr)
            return t[v];
        if (r <= ql || qr <= l)
            return null;
        int mid = (l + r) / 2;
        return merge(ans_chahiye(l, mid, ql, qr, v * 2), ans_chahiye(mid, r, ql, qr, v * 2 + 1));
    }

    element merge(element a, element b)
    {
        element c;
        c.value = a.value + b.value;
        return c;
    }

public:
    segU(int n)
    {
        this->n = n;
        t.resize(4 * n, null);
    }

    void point_update(int pos, int value)
    {
        point_update(1, 0, n, {value}, pos);
    }

    element ans_chahiye(int ql, int qr)
    {
        return ans_chahiye(0, n, ql, qr, 1);
    }
};