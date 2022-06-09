#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    int n = inf.readInt(1, 1e5, "n");
    inf.readSpace();
    int q = inf.readInt(1, 1e5, "q");
    inf.readEoln();
    for (int i = 0; i < n; i++)
    {
        long long a = inf.readLong(1LL, 1e9, "a");
        if (i != n - 1)
            inf.readSpace();
    }
    inf.readEoln();
    for (int i = 0; i < q; i++)
    {
        int type = inf.readInt();
        inf.readSpace();
        if (type == 1)
        {
            int l = inf.readInt(1, n, "l");
            inf.readSpace();
            int r = inf.readInt(l, n, "r");
            inf.readSpace();
            long long x = inf.readLong(1LL, 1e9, "x");
        }
        else
        {
            int l = inf.readInt(1, n, "l");
        }
        inf.readEoln();
    }
    inf.readEof();
}