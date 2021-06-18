#include "bits/stdc++.h"

#define all(x) (x).begin(), (x).end()
using namespace std;
#define inti long long
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n % 2)
        {
            cout << "Bob" << endl;
        }
        else
        {
            int cnt = 0;
            while (n % 2 == 0)
            {
                n = n / 2;
                cnt++;
            }
            if (n > 1)
            {
                cout << "Alice" << endl;
            }
            else
            {
                if (cnt % 2)
                {
                    cout << "Bob" << endl;
                }
                else
                {
                    cout << "Alice" << endl;
                }
            }
        }
    }
}
