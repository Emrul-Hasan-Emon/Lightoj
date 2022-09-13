Problem Link: https://lightoj.com/problem/collecting-gold
Tutorial Resource: http://basicjahid.blogspot.com/2015/01/techniques-to-solve-problem-lightoj-1057.html



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
typedef unsigned long long int    lu;
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

const int lx = (1 << 16) + 5;
const ll mod = 998244353;

int r, c, n, cs;
pair<int, int> p[20];
int a[20][20];
int dp[20][lx];

int answer(int idx, int mask)
{
	int k = (1 << (n+1)) - 1;
	if(mask == k) return a[idx][0];
	if(dp[idx][mask] != -1) return dp[idx][mask];
	
	int ans = INT_MAX;
	for(int j = 1; j <= n; j++)
	{
		if(!((mask >> j) & 1))
		{
			ans = min(ans, a[idx][j] + answer(j, mask | (1 << j)));
		}
	}
	return dp[idx][mask] = ans;
}

void solve()
{
    cin >> r >> c;
    n = 0;
    for(int i = 0; i < r; i++)
    {
    	for(int j = 0; j < c; j++)
    	{
    		char ch; cin >> ch;
    		if(ch == 'x') p[0] = {i, j};
    		else if(ch == 'g') p[++n] = {i, j};
    	}
    }
    
    for(int i = 0; i <= n; i++)
    {
    	for(int j = 0; j <= n; j++)
    	{
    		a[i][j] = max(abs(p[i].F - p[j].F) , abs(p[i].S - p[j].S));
    	}
    }
    
    memset(dp, -1, sizeof(dp));
    int ans = answer(0, 1);
    cout << "Case " << ++cs << ": " << ans << '\n';
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
