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

ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
bool prime[100000]; //primes under 10^5
//////////////////////////////////seive for prime/////////////////////////////
/*
void primes() 
{ 
  int n=100000;
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
  
        // Print all prime numbers 
           // for (int p=2; p<=n; p++) 
        // if (prime[p]) 
         // cout << p << " "; 
} 
*/
//////////////////////////////////////////////////////////////////////////////

//////////////////////////////////NCR////////////////////////////////////////
/*const int N=5000;
 
#define NCR
#define PRIME	M
inti pw(inti a,inti p=M-2,inti MOD=M){
    inti result = 1;
    while (p > 0) {
        if (p & 1)
            result = a * result % MOD;
        a = a * a % MOD;
        p >>= 1;
    }
    return result;
}
inti fact[N],invfact[N];
void init(){
    inti p=PRIME;
    fact[0]=1;
    inti i;
    for(i=1;i<N;i++){
        fact[i]=i*fact[i-1]%p;
    }
    i--;
    invfact[i]=pw(fact[i],p-2,p);
    for(i--;i>=0;i--){
        invfact[i]=invfact[i+1]*(i+1)%p;
    }
}
inti ncr(inti n,inti r){
    if(r > n || n < 0 || r < 0)return 0;
    return fact[n]*invfact[r]%PRIME*invfact[n-r]%PRIME;
}*/
///////////////////////////////////////////////////////////////////////////////

////\\//////\\/////////\\///////////\\\////////\\/////////////\\\/////
/*
ll power(ll a, ll b) //time complexity is  o(log(b));
{
  if (a == 0)
    return 0;
  ll ans = 1;
  a = a % mod;
  while (b > 0)
  {
    if ((b & 1) == 1)
      ans = (ans * a) % mod;
    b = b >> 1;
    a = (a * a) % mod;
  }
  return ans;
}*/
//\\////\\//////\\//////\//////\\///////\\//////////\\/////\\///
/*bool isPrime(int n) {
 
  if (n == 1) {
    return false;
  }
 
  for (int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false;
  }
 
  return true;
}*/
//////////////\\\\\\\\////////\\\\\\\\\\//////////\\\\////

///////////////////////////////////////////////////////////////////////

/*
//sort string by there length ==>

sort(v.begin(), v.end(), [&] (const string &s, const string &t) {
        return s.size() < t.size();
    });
*/
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
int solve(int l, int r, vector<vector<int>> &dpp, vector<vector<int>> &dsp, vector<int> &v, int n)
{
    int cnt = 0;
    while (1)
    {
        if ((v[l] == v[r]) and ((dpp[l][v[l]] + dsp[r][v[r]]) >= 3))
        {
            cnt += dpp[l][v[l]] + dsp[r][v[r]];
            l = l - dpp[l][v[l]];
            r = r + dsp[r][v[r]];
        }
        else
        {
            break;
        }
        if (l < 0 or r >= n)
            break;
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // memset(prime, true, sizeof(prime));
    //primes(); // primes under 1lakh

    /*
  #ifdef NCR
        init();
    #endif
*/
    int n, k, x;
    cin >> n >> k >> x;
    vector<vector<int>> dsp(n + 10, vector<int>(k + 10, 0)), dpp(n + 10, vector<int>(k + 10, 0));
    vector<int> v(n + 10);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        dsp[i][v[i]] = 1 + dsp[i + 1][v[i]];
    }
    dpp[0][v[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        dpp[i][v[i]] = 1 + dpp[i - 1][v[i]];
    }

    int cnt = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != x)
        {
            continue;
        }
        int tot_ball = dsp[i][v[i]];
        if ((tot_ball + 1) < 3)
        {
            continue;
        }

        int l = i - 1;
        int r = i + tot_ball;
        cnt = tot_ball;
        ans = max(cnt, ans);
        if (v[i - 1] != v[i + tot_ball])
        {
            continue;
        }
        int val = solve(l, r, dpp, dsp, v, n);
        cnt += val;
        ans = max(ans, cnt);
        cnt = 0;
        i = i + tot_ball;
    }
    cout << ans << endl;
}
