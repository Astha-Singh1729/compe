#include <bits/stdc++.h>
using namespace std;
#define int long long
class asthaSegU
{
    struct element
    {
        int value;
    };
    int n;
    vector<element> t;
    element null = {0};
    vector<bool> isNeecheJaana;
    vector<element> toGib;
    void point_update(int v, int l, int r, element value, int pos)
    {
        if (isNeecheJaana[v])
            neeche_ja_ra(v, l, r);

        if (pos < l || pos >= r)
            return;

        if (r - l == 1)
        {
            t[v] = value;
            return;
        }

        int mid = (l + r) / 2;
        point_update(v * 2, l, mid, value, pos),
            point_update(v * 2 + 1, mid, r, value, pos);
        t[v] = merge(t[2 * v], t[2 * v + 1]);
    }

    void range_update(int v, int l, int r, int idhar, int udhar, element value)
    {
        if (isNeecheJaana[v])
            neeche_ja_ra(v, l, r);

        if (l >= udhar || r <= idhar)
            return;

        if (l >= idhar && r <= udhar)
        {
            isNeecheJaana[v] = true, toGib[v] = value;
            neeche_ja_ra(v, l, r);
            return;
        }

        int mid = (l + r) / 2;
        range_update(v * 2 + 1, mid, r, idhar, udhar, value),
            range_update(v * 2, l, mid, idhar, udhar, value);

        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }

    void neeche_ja_ra(int v, int l, int r)
    {
        t[v].value = (r - l) * toGib[v].value;
        isNeecheJaana[v] = false;
        if (r - l == 1)
            return;

        toGib[v * 2].value = toGib[v].value;
        toGib[v * 2 + 1].value = toGib[v].value;
        isNeecheJaana[v * 2] = true;
        isNeecheJaana[v * 2 + 1] = true;
    }

    element ans_chahiye(int l, int r, int ql, int qr, int v)
    {
        if (isNeecheJaana[v])
            neeche_ja_ra(v, l, r);
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
    asthaSegU(int n)
    {
        this->n = n;
        t.resize(4 * n, null);
        isNeecheJaana.resize(4 * n, false);
        toGib.resize(4 * n, null);
    }

    void point_update(int pos, int value)
    {
        point_update(1, 0, n, {value}, pos);
    }

    void range_update(int l, int r, int value)
    {
        range_update(1, 0, n, l, r, {value});
    }

    element ans_chahiye(int ql, int qr)
    {
        return ans_chahiye(0, n, ql, qr, 1);
    }
};