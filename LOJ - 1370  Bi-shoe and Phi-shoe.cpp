Problem Link: https://lightoj.com/problem/bi-shoe-and-phi-shoe

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

const int lx = 2e6 + 7;
const ll mod = 998244353;

int phi[lx];
int m[lx];

void Euler()
{
	phi[1] = 0;
	
	for(int i = 2; i < lx; i++)
	{
		if(phi[i] > 0) continue;
		phi[i] = i-1;
		
		for(int j = i+i; j < lx; j += i)
		{
			if(phi[j] == 0) phi[j] = j;
			phi[j] -= phi[j]/i;
		}
	}
	
	for(int i = 1; i < lx; i++) m[i] = 1e8;
	
	for(int i = 1; i < lx; i++)
	{
		m[phi[i]] = min(m[phi[i]], i);
	}
	
	int mnm = m[lx-1];
	
	for(int i = lx-1; i ; i--)
	{
		m[i] = min(m[i], mnm);
		mnm = min(m[i], mnm);
	}
	
	//for(int i = 0; i <= 10; i++) co(v[i] sp m[v[i]]);
}

void solve()
{
	Euler();
    int t;
    cin >> t;
    for(int c = 1; c <= t; c++)
    {
    	int n, x;
        ll ans = 0;
    	cin >> n;
    	while(n--)
    	{
    		cin >> x;
    		ans += m[x];
    	}
    	cout << "Case " << c << ": " << ans << " Xukha\n";
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


