#include "bits/stdc++.h"

#define all(x) (x).begin(), (x).end()
using namespace std;
#define inti long long
#define ll long long
#define rep(a, b, c) for (int a = b; a <= c; ++a)
#define per(a, b, c) for (int a = b; a >= c; --a)
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

///////////////////////////////////////////////////////////////////////
map<pair<ll, ll>, ll> mp;
ll last_set_bit(ll num)
{
    ll cnt = 0;
    while (num)
    {
        cnt++;
        num = num >> (1 * 1ll);
    }
    return cnt;
}
void set_by_lca(ll u, ll v, ll w)
{
    while (u != v)
    {
        ll depth_of_u = last_set_bit(u);
        ll depth_of_v = last_set_bit(v);
        if (depth_of_u > depth_of_v)
        {
            swap(u, v);
        }
        mp[{v, v / 2}] += w;
        mp[{v / 2, v}] += w;
        v = v / 2;
    }
}
void get_by_lca(ll u, ll v)
{
    ll sum = 0;
    while (u != v)
    {
        ll depth_of_u = last_set_bit(u);
        ll depth_of_v = last_set_bit(v);
        if (depth_of_u > depth_of_v)
        {
            swap(u, v);
        }
        if (mp.count({v, v / 2}) != 0)
        {
            sum += mp[{v, v / 2}];
        }
        v = v / 2;
    }
    cout << sum << endl;
}
int main()
{
    ll q;
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        ll u, v, w;
        if (type == 1)
        {
            cin >> u >> v >> w;
            set_by_lca(u, v, w);
        }
        else
        {
            cin >> u >> v;
            get_by_lca(u, v);
        }
    }
}
