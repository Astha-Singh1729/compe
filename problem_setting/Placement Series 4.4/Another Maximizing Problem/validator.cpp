#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    int nodeCount = inf.readInt(1, 1e5, "nodeCount");
    inf.readEoln();
    for (int i = 0; i < nodeCount; i++)
    {
        long long value = inf.readLong((long long)-1e9, 1e9, "value");
        if (i != nodeCount - 1)
            inf.readSpace();
    }
    inf.readEoln();
    for (int i = 0; i < nodeCount - 1; i++)
    {
        int u = inf.readInt(1, nodeCount, "u");
        inf.readSpace();
        int v = inf.readInt(1, nodeCount, "v");
        inf.readSpace();
        int x = inf.readInt(0, 1, "x");
        inf.readEoln();
    }
    inf.readEof();
}