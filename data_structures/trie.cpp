#include <bits/stdc++.h>
using namespace std;
#define int long long
class trie
{
    struct xqcm
    {
        int tata;
        vector<xqcm *> dabba;
        xqcm()
        {
            tata = false;
            dabba.resize(26);
        }
    };

    xqcm *ultra;
    trie()
    {
        this->ultra = new xqcm();
    }

    void insert(string s)
    {
        int n = s.size();
        xqcm *crawl = ultra;
        for (int i = 0; i < n; i++)
        {
            if (crawl->dabba[s[i] - 'a'] == nullptr)
                crawl->dabba[s[i] - 'a'] = new xqcm();
            crawl = crawl->dabba[s[i] - 'a'];
        }
        crawl->tata = true;
    }

    bool search(string s)
    {
        int n = s.size();
        xqcm *crawl = ultra;
        for (int i = 0; i < n; i++)
        {
            if (crawl->dabba[s[i] - 'a'] == nullptr)
                return false;
            crawl = crawl->dabba[s[i] - 'a'];
        }
        return crawl->tata;
    }
};