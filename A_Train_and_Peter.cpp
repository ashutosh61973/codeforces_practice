#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

void checker()
{
    ll n = 1e18;
    string nn = to_string(n);
    ll cnt = 0;
    while (n > 0)
    {
        //function to check time complexity
        cnt++;
        n = n - (double(n) / (10));
    }
    cout << "loops runs  (" << cnt << ") times for n=" << nn << endl;
}

///////////////////////////////////////////////////////////////////////
int check(string s, string a, string b)
{
    int found = s.find(a);
    int ff = 0;
    if (found != -1)
    {
        int n = s.length();
        if (found + a.length() < n)
        {
            string temp = s.substr(found + a.length(), n - 1 - found);
            found = temp.find(b);
            if (found != -1)
            {
                ff = 1;
            }
        }
    }
    if (ff)
    {
        return 1;
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    string a, b;
    cin >> s >> a >> b;

    int ff = 0, fb = 0;
    ff = check(s, a, b);
    reverse(s.begin(), s.end());
    fb = check(s, a, b);
    if (ff and fb)
    {
        cout << "both" << endl;
    }
    else if (ff)
    {
        cout << "forward" << endl;
    }
    else if (fb)
    {
        cout << "backward" << endl;
    }
    else
    {
        cout << "fantasy" << endl;
    }
}
