#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char *argv[])
{
    registerValidation(argc, argv);
    int nodeCount = inf.readInt(2, 1e5, "nodeCount");
    inf.readSpace();
    int edgeCount = inf.readInt(1, 1e5 - 1, "edgeCount");
    inf.readEoln();
    for (int i = 0; i < edgeCount; i++)
    {
        int a = inf.readInt(1, nodeCount, "b");
        inf.readSpace();
        int b = inf.readInt(1, nodeCount, "b");
        inf.readEoln();
    }
    inf.readEof();
}