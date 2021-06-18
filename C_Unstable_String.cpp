#include "bits/stdc++.h"

using namespace std;
#define inti long long
#define ll long long
const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t mod = 1e9 + 7;
const int32_t MM = 998244353;

bool prime[100000]; //primes under 10^5
//////////////////////////////////seive for prime/////////////////////////////
/*
void primes() 
{ 
  ll n=100000;
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
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll n = s.length();
        ll dp[n + 10][2];
        memset(dp, 0, sizeof(dp));
        if (s[0] == '?')
        {
            dp[0][0] = 1;
            dp[0][1] = 1;
        }
        if (s[0] == '1')
        {
            dp[0][1] = 1;
            dp[0][0] = 0;
        }
        if (s[0] == '0')
        {
            dp[0][0] = 1;
            dp[0][1] = 0;
        }

        for (ll i = 1; i < n; i++)
        {
            if (s[i] - '0' == 1)
            {
                dp[i][0] = 0;
                dp[i][1] = 1 + dp[i - 1][0];
            }
            else if (s[i] - '0' == 0)
            {
                dp[i][1] = 0;
                dp[i][0] = 1 + dp[i - 1][1];
            }
            else
            {
                dp[i][1] = 1 + dp[i - 1][0];
                dp[i][0] = 1 + dp[i - 1][1];
            }
        }

        ll cnt = 0;
        for (ll i = 0; i < n; i++)
        {
            cnt = cnt + max(dp[i][0], dp[i][1]);
        }
        cout << cnt << endl;
    }
}
