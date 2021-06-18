#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

/////////**********************---/|\---************************///////////
/////////**********************---\|/---***********************///////////

void buildSegmentTree(int idx, int l, int r, vector<pair<int, pair<int, int>>> &seg, vector<int> &arr)
{
    if (l == r)
    {
        seg[idx].first = 0;
        seg[idx].second = {arr[l], arr[r]};
        return;
    }
    //recursive intuition
    int mid = (l + r) / 2;
    buildSegmentTree(2 * idx + 1, l, mid, seg, arr);
    buildSegmentTree(2 * idx + 2, mid + 1, r, seg, arr);
    int temp = seg[2 * idx + 1].second.second ^ seg[2 * idx + 2].second.first;
    if (temp == 0)
    {
        seg[idx].first = seg[2 * idx + 1].first + seg[2 * idx + 2].first + 2;
        seg[idx].second.first = seg[2 * idx + 1].second.first;
        seg[idx].second.second = seg[2 * idx + 2].second.second;
    }
    else
    {
        seg[idx].first = seg[2 * idx + 1].first + seg[2 * idx + 2].first + 1;
        seg[idx].second.first = seg[2 * idx + 1].second.first;
        seg[idx].second.second = seg[2 * idx + 2].second.second;
    }
    return;
}

int sum_query(int idx, int ql, int qr, int l, int r, vector<pair<int, pair<int, int>>> &seg)
{
    // if (qr < l || ql > r)
    // {
    //     return 0;
    // }
    // if (ql <= l && qr >= r)
    //     return seg[idx].first;
    // int mid = (l + r) / 2;
    // int x = sum_query(2 * idx + 1, ql, qr, l, mid, seg);
    // int y = sum_query(2 * idx + 2, ql, qr, mid + 1, r, seg);
    // return x + y;
    return seg[idx].first;
}
void update(int idx, int l, int r, int pos, int val, vector<pair<int, pair<int, int>>> &seg)
{
    if (l == r)
    {
        seg[idx].first = 0;
        seg[idx].second.first = val ^ seg[idx].second.first;
        seg[idx].second.second = val ^ seg[idx].second.second;
        return;
    }
    int mid = (l + r) / 2;
    if (mid >= pos)
    {
        update(2 * idx + 1, l, mid, pos, val, seg);
    }
    else
    {
        update(2 * idx + 2, mid + 1, r, pos, val, seg);
    }
    int temp = seg[2 * idx + 1].second.second ^ seg[2 * idx + 2].second.first;
    if (temp == 0)
    {
        seg[idx].first = seg[2 * idx + 1].first + seg[2 * idx + 2].first + 2;
        seg[idx].second.first = seg[2 * idx + 1].second.first;
        seg[idx].second.second = seg[2 * idx + 2].second.second;
    }
    else
    {
        seg[idx].first = seg[2 * idx + 1].first + seg[2 * idx + 2].first + 1;
        seg[idx].second.first = seg[2 * idx + 1].second.first;
        seg[idx].second.second = seg[2 * idx + 2].second.second;
    }

    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n;
        cin >> q;
        string s;
        cin >> s;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = s[i] - '0';
        }

        vector<pair<int, pair<int, int>>> seg(4 * n); //to store the node of the segment tree
        //befor building of segment tree you have to know two things
        //first-what each node is repersent ..in here it is sum of the rnage
        //second-how to merge
        buildSegmentTree(0, 0, n - 1, seg, arr);

        while (q--)
        {

            int pos;
            cin >> pos;
            pos = pos - 1;
            int val = 1;
            update(0, 0, n - 1, pos, val, seg);
            cout << sum_query(0, 0, n - 1, 0, n - 1, seg) << endl;
        }
    }
}