Problem Link: https://lightoj.com/problem/horrible-queries


///              B I S M I L L A H I R  R A H M A N I R  R A H I M

// ============================================================================ //
// ||                                                                        || //
// ||             International University of Business Agriculture           || //
// ||                    and Technology, Dhaka, Bangladesh                   || //
// ||                           Emrul Hasan Emon                             || //
// ||                                                                        || //
// ============================================================================ //

#include<bits/stdc++.h>
#include<vector>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef bool                      boo;
typedef int                       li;
typedef long long int             ll;
typedef unsigned long long int    l1;
typedef double                    db;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

typedef vector < li >                   vli;
typedef vector < ll >                   vll;
typedef set < li >                      sli;
typedef set < ll >                      sll;
typedef pair < li, li >                pli;
typedef pair < ll, li >                pll;
typedef map < li,li >                  mli;
typedef map < ll,ll >                  mll;
typedef vector < pair < li, li > >     vpi;
typedef vector < pair < ll, ll > >     vpl;

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

#define tc                        int t;cin>>t;while(t--)
#define inp_i(a,n)                for(int ii = 0; ii < n ; ii++) cin >> a[ii]
#define out_i(a, b, c)            for(int ii = b; ii < c; ii++) cout << a[ii] spc; cout nl;
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
#define cn                        cout<<"NO" nl
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

const ll lx = 1e5 + 7;
const ll mod = 998244353;

struct Node
{
	ll sum;
	ll prop;
	
	Node()
	{
		sum = 0;
		prop = 0;
	}
};

ll a[lx];
Node tree[4*lx];

void update(int node, int b, int e, int i, int j, ll carry)
{
	if(i > e or j < b)
		return;
		
	if(b >= i and e <= j)
	{
		tree[node].sum += (e-b+1)*carry;
		tree[node].prop += carry;
		return;
	}
	
	ll l, r, m;
	m = (b+e)/2;
	l = node*2;
	r = node*2+1;
	
	update(l, b, m, i, j, carry);
	update(r, m+1, e, i, j, carry);
	
	tree[node].sum = tree[l].sum + tree[r].sum + (e-b+1)*tree[node].prop;
}

ll query(int node, int b, int e, int i, int j, ll carry)
{
	if(i > e or j < b) 
		return 0;
	if(b >= i and e <= j)
		return tree[node].sum + carry*(e-b+1);
	
	int l, r, m;
	m = (b+e)/2;
	l = node*2;
	r = node*2+1;
	
	return query(l, b, m, i, j, carry+tree[node].prop) + query(r, m+1, e, i, j, carry+tree[node].prop);
}

void solve()
{
    int t;
    cin >> t;
    for(int cs = 1; cs <= t; cs++)
    {
    	int n, m, i;
    	cin >> n >> m;
    	for(i = 1; i <= n; i++) a[i] = 0;
    	for(i = 0; i <= n*4; i++)
    	{
    		tree[i].sum = 0;
    		tree[i].prop = 0;
    	}
    	
    	cout << "Case " << cs << ":\n";
    	while(m--)
    	{
    		int type, x, y, v;
    		cin >> type >> x >> y;
    		x++; y++;
    		
    		if(type == 0)
    		{
    			cin >> v;
    			update(1, 1, n, x, y, v);
    		}
    		else
    		{
    			ll ans = query(1, 1, n, x, y, 0);
    			co(ans);
    		}
    	}
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
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 2 3 4 5....
// Emrul Hasan Emon
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*

ll f[lx];

ll Big_Mod(ll a, ll b)
{
    if(b==0)
        return 1;

    ll ans;
    ans=Big_Mod(a, b/2);
    ans=(ans*ans)%mod;

    if(b&1)
        ans=(ans*a)%mod;

    return ans;
}

void fact()
{
    ll ans=1; 
    f[0]=1;
    for(ll i=1; i<lx; i++)
    {
        ans=(ans*i)%mod;
        f[i]=ans;
    }
}

ll nCr(ll n, ll k)
{
    return f[n]*1ll*Big_Mod(f[k], mod-2)%mod*1ll*Big_Mod(f[n-k], mod-2)%mod;
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


