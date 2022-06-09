#include <bits/stdc++.h>
using namespace std;
#define int long long
void hocusPocus()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (auto &i : v)
        cin >> i;
    vector<int> pref(n);
    pref[0] = v[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + v[i];
    const auto gib = [&](int l, int r)
    {
        if (l != 0)
            return pref[r] - pref[l - 1];
        return pref[r];
    };

    for (int i = 0; i < q; i++)
    {
        int type;
        cin >> type;
        if (type == 2)
        {
            int l;
            cin >> l;
            l--;
            int rf = 0;
            int mn = LLONG_MAX;
            for (int i = l; i < n; i++)
            {
                int diff = abs(2 * gib(l, i) - pref[n - 1]);
                if (diff < mn)
                {
                    mn = diff;
                    rf = i + 1;
                }
            }
            cout << rf << endl;
            continue;
        }
        int l, r, value;
        cin >> l >> r >> value;
        for (int i = l - 1; i < r; i++)
            v[i] = value;
        pref[0] = v[0];
        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + v[i];
    }
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    hocusPocus();
}