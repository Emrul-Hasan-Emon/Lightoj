
///              B I S M I L L A H I R  R A H M A N I R  R A H I M


#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef bool                      boo;
typedef int                       li;
typedef long long int             ll;
typedef unsigned long long int    lu;
typedef double                    db;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef vector < li >                   vli;
typedef vector < ll >                   vll;
typedef set < li >                      sli;
typedef set < ll >                      sll;
typedef pair < pair<li, li>, li>        PLL;
typedef pair < ll, ll >                 pll;
typedef map < li,li >                   mli;
typedef map < ll,ll >                   mll;
typedef vector < pair < li, li > >      vpi;
typedef vector < pair < ll, ll > >      vpl;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#define tc                        int t;cin>>t;while(t--)
#define inp_i(a,n)                for(i=0; i<n ;i++) cin>>a[i]
#define out_i(a, b, c)            for(int i=b; i<c; i++) cout<<a[i] spc; cout nl;
#define lp(i,a,b)                 for(i=a;i<b;i++)
#define len(z)                    z.begin(),z.end()
#define faster                    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define input_txt                 freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define nl                        <<"\n"
#define spc                       <<" "
#define sp                        <<" "<<
#define co(x)                     cout<<x nl
#define sz(a)                     a.size()
#define cy                        cout<<"YES" nl
//#define cn                        cout<<"NO" nl
#define pb                        push_back
#define F                         first
#define S                         second
#define pi                        2*acos(0.0)
#define clr(z)                    z.clear()
#define rn                        return
#define gcd(a,b)                  __gcd(a,b)
#define mem(b,z)                  memset(b,z,sizeof(b))
#define fixed(x)                  fixed<<setprecision(x)

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//template<typename T>
//using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

typedef tree<pair<int,int>,null_type,less<pair<int,int>>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

const double inf = 0.0000;
const int lx = 1e6 + 10;
const int mod = 1000003;
const int hs = 3797;

inline bool checkBit (int  n, int i) { return n&(1LL<<i); }
inline int  setBit (int n, int i) { return n|(1LL<<i);; }
inline int resetBit (int n, int i) { return n&(~(1LL<<i)); }

ll two[lx], five[lx];

void precal()
{
	for(int i = 2; i < lx; i++) {
		int x = i;
		while(x % 2 == 0) {
			x /= 2;
			two[i] += 1;
		}
		while(x % 5 == 0) {
			x /= 5;
			five[i] += 1;
		}
		two[i] += two[i - 1];
		five[i] += five[i - 1];
	}
}

void solve() 
{
	precal();
	int t;
	cin >> t;
	for(int cs = 1; cs <= t; cs++) {
		ll n, r, p, q;
		cin >> n >> r >> p >> q;
		
		ll Two = two[n] - two[n - r] - two[r];
		ll Five = five[n] - five[n - r] - five[r];
		
		ll _two = 0, _five = 0;
		while(p % 2 == 0) {
			p /= 2;
			_two += 1;
		}
		while(p % 5 == 0) {
			p /= 5;
			_five += 1;
		} 
		_two *= q;
		_five *= q;
		Two += _two;
		Five += _five;
		cout << "Case " << cs << ": " << min(Two, Five) << endl;
	}
}

void init_code()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
}

int main()
{
    faster
	
    solve();
// A L H A M D U L I L L A H
// 1 2 3 2 1
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
 *ll ext_gcd (ll A, ll B, ll &X, ll &Y )
{
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1;
    y2 = 0;
    x1 = 0;
    y1 = 1;
    for (r2 = A, r1 = B; r1 != 0; r2 = r1, r1 = r, x2 = x1, y2 = y1, x1 = x, y1 = y )
    {
        q = r2 / r1;
        r = r2 % r1;
        x = x2 - (q * x1);
        y = y2 - (q * y1);
    }
    X = x2;
    Y = y2;
    return r2;
}

ll modInv_general ( ll a, ll m ) {
    ll x, y;
    ext_gcd( a, m, x, y );

    
    x %= m;
    if ( x < 0 ) x += m;
    return x;
}
* 
bool mark[lx];
vector<int> primes;

void sieve()
{
    mark[0] = mark[1] = true;
    
    for(int i = 3; i*i <= lx; i++)
    {
	if(!mark[i])
	{
	    for(int j = i*i; j < lx; j += i)
		mark[j] = true;
	}
    }
    
    primes.push_back(2);
    for(int i = 3; i < lx; i += 2)
    {
	if(!mark[i])
	{
	    primes.push_back(i);
	}
    }
}
* 
ll Big_Mod(ll a, ll b)
{
	if(!b) return 1;
	ll ans = Big_Mod(a, b/2);
	ans %= mod;
	ans *= ans;
	ans %= mod;
	
	if(b&1)
	{
		a %= mod;
		ans *= a;
		ans %= mod;
	}
	return ans;
}
* 
ll fact(ll n)
{
    ll ans=1;
    for(ll i=1; i<=n; i++)
        ans=(ans*i)%mod;
    return ans;
}

ll nCr(ll n, ll k)
{
    return fact(n)*1ll*Big_Mod(fact(k), mod-2)%mod*1ll*Big_Mod(fact(n-k), mod-2)%mod;
}

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

void number_of_divisors(li n)
{
    //Number of divisors of every number between 1 to n
    for(li i = 1; i*i <= n; i++)
    {
        for(li j = i*i; j <= n; j += i)
        {
            if(i*i == j)
                a[j]++;
            else
                a[j] += 2;
        }
    }
}

void sum_of_divisor()
{
    for(li i = 1; i * i <= 1e7; i++)
    {
        for(li j = i*i; j < 1e7; j += i)
        {
            if(j == i*i)
                a[j] += i;
            else
                a[j] += i+(j/i);
        }
    }
}
*/



