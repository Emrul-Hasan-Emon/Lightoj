Problem Link: https://lightoj.com/problem/aladdin-and-the-return-journe



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

const int lx = 30000 + 10;
const int mx = 2*lx;
const ll mod = 998244353;
int a[lx], s[lx], e[lx], parent[lx], level[lx], cnt, cs;
int LCA[lx][22];

ll fen[mx];

vector<int> adj[lx];

void update(int idx, int value)
{
	while(idx < mx)
	{
		fen[idx] += value;
		idx += idx & -idx;
	}
}

ll query(int idx)
{
	ll s = 0;
	while(idx > 0)
	{
		s += fen[idx];
		idx -= idx & -idx;
	}
	return s;
}

void lca_form(int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < 22; j++)
			LCA[i][j] = 0;
	}
	
	for(int i = 0; i < n; i++)
	{
		LCA[i][0] = parent[i];
	}
	
	for(int j = 1; j < 22; j++)
	{
		for(int i = 0; i < n; i++)
		{
			LCA[i][j] = LCA[LCA[i][j-1]][j-1];
		}
	}
}

int Ancestor(int p, int q, int n)
{
	if(level[p] < level[q]) swap(p, q);
	
	for(int i = 21; i >= 0; i--)
	{
		int x = level[LCA[p][i]];
		if(x >= level[q])
		{
			p = LCA[p][i];
		}
	}
	if(p == q) return p;
	
	for(int i = 21; i >= 0; i--)
	{
		if(LCA[p][i] != LCA[q][i])
		{
			p = LCA[p][i];
			q = LCA[q][i];
		}
	} 
	return parent[p];
}

void dfs(int node, int p, int l)
{
	parent[node] = p;
	level[node] = l;
	
	s[node] = ++cnt;
	
	for(int c : adj[node])
	{
		if(c != p)
			dfs(c, node, l+1);
	}
	e[node] = ++cnt;
}

void solve()
{
    int n, i;
    cin >> n;
    for(i = 0; i <= n+2; i++) 
    {
    	adj[i].clear();
    }
    
    for(i = 0; i < mx; i++) fen[i] = 0;
    for(i = 0; i < n; i++) cin >> a[i];
    
    for(i = 1; i < n; i++)
    {
    	int u, v;
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }
    
    cnt = 0;
    dfs(0, 0, 1);
    lca_form(n);
    
    for(i = 0; i < n; i++)
    {
    	update(s[i], a[i]);
    	update(e[i], -a[i]);
    }
    
//   for(i = 0; i < n; i++) co(s[i] sp e[i]); cout nl;
	
	cout << "Case " << ++cs << ":\n";
	    
    int q;
    cin >> q;
    while(q--)
    {
    	int type, l, r, idx, val;
    	cin >> type;
    	if(type == 0)
    	{
    		cin >> l >> r;
    		
    		int sl = s[l], el = e[l];
    		int sr = s[r], er = e[r];
    		
    		int Parent = Ancestor(l, r, n);
    	//	co(Parent);
    		
    	//	co(query(sl) sp query(sr) sp query(s[Parent]));
    		ll ans = query(sl) + query(sr) - 2*query(s[Parent]) + a[Parent];
    		co(ans);
    		
    	}
    	else
    	{
    		cin >> idx >> val;
    		int x = val - a[idx];
    		
    		update(s[idx], x);
    		update(e[idx], -x);
    		
    		a[idx] = val;
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
    tc
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


