#include <bits/stdc++.h>
using namespace std;
#define int long long
void hocusPocus()
{

    int n;
    cin >> n;
    vector<int> values(n);
    for (int &i : values)
        cin >> i;
    struct data
    {
        int value;
        data *left;
        data *right;
        int mx;
        int mx_used;
        data(int val)
        {
            value = val;
            left = nullptr;
            right = nullptr;
            mx = LLONG_MIN;
            mx_used = 0;
        }
    };
    int ans = LLONG_MIN;
    vector<data *> eh(n);
    for (int i = 0; i < n; i++)
        eh[i] = new data(values[i]), ans = max(ans, values[i]);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        --u, --v;
        (x ? eh[u]->right : eh[u]->left) = eh[v];
    }
    const auto mx = [&](data *node)
    {
        return node ? node->mx : 0LL;
    };
    const auto mx_used = [&](data *node)
    {
        return node ? node->mx_used : 0LL;
    };
    const auto hmm = [&](auto &self, data *root) -> void
    {
        if (root == nullptr)
            return;
        self(self, root->left);
        self(self, root->right);

        root->mx = root->value + max(mx(root->left), mx(root->right));
        root->mx = max(root->value, root->mx);
        root->mx_used = max({mx(root->left), mx(root->right), root->value + max(mx_used(root->left), mx_used(root->right)), root->mx_used});
        ans = max({ans, root->mx, root->value + mx(root->left) + mx(root->right), root->mx_used});
        ans = max({ans, root->value + max(mx_used(root->left) + mx(root->right), mx(root->left) + mx_used(root->right)), mx(root->left) + mx(root->right)});
    };
    hmm(hmm, eh[0]);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(false), cin.tie(NULL);
    hocusPocus();
}