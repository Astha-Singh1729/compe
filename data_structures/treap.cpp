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
            this->kuch_to_pass_karaungi();
        }
        Raimund *left, *right;
        int key, priority;
        int cnt;
        void kuch_to_pass_karaungi()
        {
            cnt = 1;
            cnt += left == nullptr ? 0 : left->cnt;
            cnt += right == nullptr ? 0 : right->cnt;
        }
    };
    Raimund *ultra;

    Treap()
    {
        this->ultra = nullptr;
    }

    void split(Raimund *root, int key, Raimund *&l, Raimund *&r)
    {
        if (root == nullptr)
        {
            l = nullptr;
            r = nullptr;
            return;
        }
        if (key < root->key)
        {
            Raimund *splitL, *splitR;
            split(root->left, key, splitL, splitR);
            l = splitL;
            root->left = splitR;
            root->kuch_to_pass_karaungi();
            r = root;
        }
        else
        {
            Raimund *splitL, *splitR;
            split(root->right, key, splitL, splitR);
            r = splitR;
            root->right = splitL;
            root->kuch_to_pass_karaungi();
            l = root;
        }
    }
    Raimund *merge(Raimund *l, Raimund *r)
    {
        if (l == nullptr)
            return r;
        if (r == nullptr)
            return l;
        if (r->priority < l->priority)
        {
            l->right = merge(l->right, r);
            l->kuch_to_pass_karaungi();
            return l;
        }
        else
        {
            r->left = merge(l, r->left);
            r->kuch_to_pass_karaungi();
            return r;
        }
    }

public:
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
    int gib_answer(int l, int r)
    {
        int ans = 0;
        Raimund *left, *right;
        split(ultra, l, left, right);
        Raimund *leftAgain, *rightAgain;
        split(right, r + 1, leftAgain, rightAgain);
        ans = leftAgain->cnt;
        ultra = merge(merge(left, leftAgain), rightAgain);
        return ans;
    }
};

/*
key ke about split

*/