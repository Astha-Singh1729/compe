/* someone remind me , need to fix few stuff in this in future*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
class segU
{
    struct element
    {
        int value;
    };

public:
    segU(int n)
    {
        this->t.resize(4 * n, this->null);
        this->n = n;
    }

    element prayge(int l, int r)
    {
        return prayge(1, 0, n - 1, l, r);
    }

    void update(int pos, int value)
    {
        update(1, 0, n - 1, pos, value);
    }

private:
    vector<element> t;
    int n;
    element null = {0};
    element prayge(int v, int tl, int tr, int l, int r)
    {
        if (l > r)
            return null;
        if (l == tl && r == tr)
        {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return merge(prayge(v * 2, tl, tm, l, min(r, tm)), prayge(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
    void update(int v, int tl, int tr, int pos, int new_val)
    {
        if (tl == tr)
        {
            t[v].value = new_val;
        }
        else
        {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = merge(t[v * 2], t[v * 2 + 1]);
        }
    }
    element merge(element l, element r)
    {
        element ans = {l.value + r.value};
        return ans;
    }
};