Problem Link: https://lightoj.com/problem/curious-robin-hood



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

const ll lx = 1e6 + 7;
const ll mod = 998244353;

ll a[lx], n, q;
ll tree[4*lx];

void build(int node, int b, int e)
{
	if(b == e)
	{
		tree[node] = a[b];
		return;
	}

	int mid = (b+e) >> 1;
	
	build(2*node, b, mid);
	build(2*node+1, mid+1, e);
	
	tree[node] = tree[2*node] + tree[2*node+1];
}

void update(int node, int b, int e, int i, ll value)
{
	if(e < i or b > i) 
		return;
	
	if(b >= i and e <= i)
	{
		tree[node] = value;
		return;
	}
	
	int mid = (b+e) >> 1;
	update(2*node, b, mid, i, value);
	update(2*node+1, mid+1, e, i, value);
	
	tree[node] = tree[2*node] + tree[2*node+1];
}

ll query(int node, int b, int e, int i, int j)
{
	if(i > e or j < b) 
		return 0;
	if(b >= i and e <= j) 
		return tree[node];
	int mid = (b+e) >> 1;
	
	ll p1 = query(2*node, b, mid, i, j);
	ll p2 = query(2*node+1, mid+1, e, i, j);
	
	return p1+p2;
}


void solve()
{
	int t;
	cin >> t;
	for(int cs = 1; cs <= t; cs++)
	{
		cin >> n >> q;
		int i;
		for(i = 1; i <= n; i++) 
		{
			cin >> a[i];
		}
		
		build(1, 1, n);
		
		cout << "Case " << cs << ":\n";
		while(q--)
		{
			int type, idx, l, r;
			ll val;
			cin >> type;
			
			if(type == 1)
			{
				cin >> idx;
				co(a[idx+1]);
				a[idx+1] = 0;
				update(1, 1, n, idx+1, 0);	
			}
			else if(type == 2)
			{
				cin >> idx >> val;
				a[idx+1] += val;
				update(1, 1, n, idx+1, a[idx+1]);
			}
			else
			{
				cin >> l >> r;
				ll ans = query(1, 1, n, l+1, r+1);
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


