Problem Link:   https://lightoj.com/problem/coin-change-iv






// ============================================================================ //
// ||                                                                        || //
// ||             International University of Business Agriculture           || //
// ||                    and Technology, DHaka, Bangladesh                   || //
// ||                           Emrul Hasan Emon                             || //
// ||                                                                        || //
// ============================================================================ //


///              B I S M I L L A H I R  R A H M A N I R  R A H I M


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
#define inp_i(a,n)                for(i=0; i<n ;i++) cin>>a[i]
#define out_i(a, b, c)            for(i=b; i<c; i++) cout<<a[i] spc; cout nl;
#define lp(i,a,b)                 for(i=a;i<b;i++)
#define len(z)                    z.begin(),z.end()
#define faster                    ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define input_txt                 freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define nl                        <<"\n"
#define spc                       <<" "
#define sp                        <<" "<<
#define co(x)                     cout<<x nl
#define sz(a)                     a.size()
#define cy                        cout<<"Yes" nl
#define cn                        cout<<"No" nl
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

const int lx=1e6+123;
const ll mod = 1e8;
int cs;
int a[20];
vector<ll>v1, v2;

void ami_sesh(int idx, int n, ll sum, int turn)
{
    if(idx>n)
    {
        if(turn==1)
            v1.push_back(sum);
        else
            v2.push_back(sum);
        return;
    }
    ami_sesh(idx+1, n, sum, turn);
    ami_sesh(idx+1, n, sum+a[idx], turn);
    ami_sesh(idx+1, n, sum+a[idx]+a[idx], turn);
}

void solve()
{
    v1.clear();
    v2.clear();

    int n, k, i, f=0;
    cin>>n>>k;
    for(i=1; i<=n; i++)
        cin>>a[i];

    ami_sesh(1, n/2, 0, 1);
    ami_sesh(n/2+1, n, 0, 2);

    sort(len(v1));
    sort(len(v2));

    for(i=0; i<v1.size(); i++)
    {
        if(binary_search(len(v2), k-v1[i]))
        {
            f++;
            break;
        }
    }
    cout<<"Case "<<++cs<<": ";
    if(f)
        cy;
    else
        cn;
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
// 1 2 3 2 1
}

//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

