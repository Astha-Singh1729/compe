#include <bits/stdc++.h>
using namespace std;
#define int long long
mt19937 rng((unsigned int)chrono::steady_clock::now().time_since_epoch().count());
class Treap
{

    struct Raimund
    {
        Raimund(int key)
        {
            this->left = nullptr;
            this->right = nullptr;
            this->key = key;
            this->priority = rng();
        }
        Raimund *left, *right;
        int key, priority;
    };
    Raimund *ultra;
    Treap()
    {
        this->ultra = nullptr;
    }
    void split(Raimund *root, int key, Raimund *&l, Raimund *&r)
    {
        if (key == root->key)
            l = root->left, r = root;
        else if (key < root->key)
        {
            Raimund *splitL, *splitR;
            split(root->left, key, splitL, splitR);
            l = splitL;
            root->left = splitR;
            r = root;
        }
        else
        {
            Raimund *splitL, *splitR;
            split(root->right, key, splitL, splitR);
            r = splitR;
            root->right = splitL;
            l = root;
        }
    }
    Raimund *merge(Raimund *l, Raimund *r)
    {
        if (r->priority < l->priority)
        {
            l->right = merge(l->right, r);
            return l;
        }
        else
        {
            r->left = merge(l, r->left);
            return r;
        }
    }
    void insert(int key)
    {
        Raimund *toInsert = new Raimund(key);
        Raimund *left, *right;
        split(ultra, key, left, right);
        ultra = merge(left, toInsert);
        ultra = merge(ultra, right);
    }
    void erase(int key)
    {
        Raimund *left, *right;
        Raimund *leftAgain, *rightAgain;
        split(ultra, key, left, right);
        split(right, key + 1, leftAgain, rightAgain);
        ultra = merge(left, rightAgain);
    }
};
/*
key ke about split

*/