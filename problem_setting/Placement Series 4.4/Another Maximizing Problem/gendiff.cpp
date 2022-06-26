#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int n = rnd.next(1000, (int)1e5);
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        long long a = rnd.next((long long)-1e9, (long long)1e9);
        cout << a;
        if (i != n - 1)
            cout << " ";
    }
    cout << endl;

    struct data
    {
        int u;
        int v;
        int x;
    };
    random_device rd;
    mt19937 g(rd());

    const auto generateBinaryTree = [&]()
    {
        int x = rnd.next(0, 1);
        vector<int> options = {0, 1, 2};
        map<int, int> mp;
        queue<int> q;
        q.push(1);
        vector<data> v;
        vector<int> flag(n, -1);
        int count = 1;
        mp[1] = 1;
        while (!q.empty() or count < n)
        {
            int front;

            if (!q.empty())
                front = q.front(), q.pop();

            int numberOfChilds = options[rnd.next((int)0, (int)options.size() - 1)];

            if (count >= n)
                continue;

            while (numberOfChilds--)
            {
                int child = rnd.next(1, n);
                while (mp[child])
                {
                    child++;
                    if (child > n)
                        child = 1;
                }
                count++;
                mp[child] = 1;
                if (flag[front - 1] == -1)
                    v.push_back({front, child, x}), flag[front - 1] = x;
                else
                    flag[front - 1] ^= 1, v.push_back({front, child, flag[front - 1]});
                q.push(child);
                if (count == n)
                    break;
            }
        }

        shuffle(v.begin(), v.end(), g);
        return v;
    };
    vector<data> v = generateBinaryTree();

    for (auto [u, v, x] : v)
        cout << u << " " << v << " " << x << endl;
}
