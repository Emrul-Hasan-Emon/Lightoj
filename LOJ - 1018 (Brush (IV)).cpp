Problem Link: https://lightoj.com/problem/brush-4


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

const int lx = 65536 + 7;
const ll mod = 998244353;

int dx[] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 0, 1, -1, 1, -1, 1, -1};

int x[20], y[20], c;
int same[20][20];
int dp[lx];
int n;

int Set(int mask, int pos)
{
	return (mask | (1 << pos));
}

bool SameLine(int i, int j, int k)
{
	return ((y[i] - y[j]) * (x[j] - x[k])) == ((x[i] - x[j]) * (y[j] - y[k]));
}

bool Check(int mask, int pos)
{
	return (bool)((mask >> pos) & 1);
}

int answer(int mask)
{
	if(dp[mask] != -1) return dp[mask];
	
	if(mask == (1 << n)-1) return dp[mask] = 0;
	
	int ans = 8;
	
	int cnt = __builtin_popcount(mask);
	
	if(cnt == n-1 or cnt == n-2) return dp[mask] = 1;
	
	for(int i = 0; i < n; i++)
	{
		if(Check(mask, i)) continue;
		for(int j = i+1; j < n; j++)
		{
			if(Check(mask, j)) continue;
			
			ans = min(ans, 1 + answer(mask | same[i][j]));
		}
		break;
	}
	return dp[mask] = ans;
}

void solve()
{
	int i, j, k;
	cin >> n;
	
	memset(dp, -1, sizeof(dp));
	
	for(i = 0; i < n; i++) 
	{
		cin >> x[i] >> y[i];
	}	
	
	for(i = 0; i < n; i++)
	{
		for(j = i+1; j < n; j++)
		{
			int temp = 0;
			temp = Set(temp, i);
			temp = Set(temp, j);
			
			for(k = 0; k < n; k++)
			{
				if(SameLine(i, j, k))
				{
					temp = Set(temp, k);
				}
			}
			same[i][j] = temp;
		}
	}
	int ans = answer(0);
	cout << "Case " << ++c << ": " << ans << '\n';
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


