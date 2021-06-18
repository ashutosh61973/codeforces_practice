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
bool check(vector<vector<int>> &v, vector<vector<int>> &mat)
{
    map<int, int> mp;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if ((mat[i][j] < 1 or mat[i][j] > 9))
            {
                return false;
            }
            if (mp.count(mat[i][j]) != 0)
            {
                return false;
            }
            mp[mat[i][j]] = 1;
        }
    }

    //col check
    int val = mat[0][0] + mat[1][0];
    if (val != v[1][0])
    {
        return false;
    }
    val = mat[0][1] + mat[1][1];
    if (val != v[1][1])
    {
        return false;
    }
    //diagonal
    val = mat[0][0] + mat[1][1];
    if (val != v[2][0])
    {
        return false;
    }
    val = mat[0][1] + mat[1][0];
    if (val != v[2][1])
    {
        return false;
    }
    return true;
}
void print(vector<vector<int>> &mat)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return;
}
int f = 0;
void bf(int row, vector<vector<int>> &v, vector<vector<int>> &mat)
{
    if (row == 2)
    {

        if (check(v, mat))
        {
            print(mat);
            f = 1;
            return;
        }
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        mat[row][0] = i;
        mat[row][1] = v[0][row] - i;
        bf(row + 1, v, mat);
        mat[row][0] = 0;
        mat[row][1] = 0;
        if (f == 1)
        {
            return;
        }
    }
    return;
}
void solve(vector<vector<int>> &v)
{
    vector<vector<int>> mat(2, vector<int>(2));
    bf(0, v, mat);
    if (!f)
    {
        cout << -1 << endl;
    }
    return;
}
int main()
{
    vector<vector<int>> v(3, vector<int>(2, 0));
    for (int i = 0; i <= 2; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i][0] = x;
        v[i][1] = y;
    }
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << v[i][0] << " " << v[i][1] << endl;
    // }
    solve(v);
}
