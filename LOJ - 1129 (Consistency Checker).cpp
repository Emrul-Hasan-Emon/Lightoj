Problem Link: https://lightoj.com/problem/consistency-checker


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

const ll lx = 2e6 + 7;
const ll mod = 998244353;

struct Node
{
	Node *child[10];
	int pref;
	Node()
	{
		for(int i = 0; i < 10; ++i)
			child[i] = nullptr;
		pref = 0; 
	}
};

void del(Node* cur)
{
    for (int i = 0; i < 10; i++)
        if (cur->child[i])
            del(cur->child[i]);
    delete (cur);
}

void update(Node *root, string s)
{
	Node *node = root;
	for(int i = 0; i < s.size(); i++)
	{
		int x = s[i]-'0';
		if(!node->child[x])
		{
			node->child[x] = new Node();
		}
		node = node->child[x];
		node->pref++;
	}
}

int answer(Node *root, string s)
{
	Node *node = root;
	for(int i = 0; i < s.size(); i++)
	{
		int x = s[i]-'0';
		if(!node->child[x]) 
			return false;
		node = node->child[x];
		
	}
//	co(s sp node->pref);
	if(node->pref > 1) return true;
	return false;
}

void solve()
{
	int t;
	cin >> t;
	for(int cs = 1; cs <= t; cs++)
	{
		int n, i;
		Node *root = new Node();
		cin >> n;
		bool ok = false;
		string s[n];
		
		for(i = 0; i < n; i++)
		{
			cin >> s[i];
			update(root, s[i]);
		}
		
		for(i = 0; i < n; i++)
		{
			if(answer(root, s[i])) ok = true;
		}
		cout << "Case " << cs << ": ";
		if(ok) cout << "NO\n";
		else cout << "YES\n";
		
		del(root);
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


