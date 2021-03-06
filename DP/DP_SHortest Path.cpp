#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define MP make_pair
#define llu unsigned long long
#define U unsigned int
#define ff first
#define ss second
#define b(n) cout<<"bug "<<n<<endl;
#define en cout<<endl;
#define SIZE 100005
#define pie 3.14159265358979323
#define minuss 1e-6
#define pii pair<ll,ll>
#define fast_cin ios_base::sync_with_stdio(false);cin.tie(NULL)
#define BIG 1000000000
#define INF 1000000000000005
#define N 100000
ll mod=10000007;


//cout<<fixed<<setprecision(1)<<VALUE NAME<<endl;
vector<pii>weight[N];
ll dp[100006];

ll shortest(ll i,ll n)
{
    if(dp[i]!=-1)
        return dp[i];

    ll child=BIG;
    for(int j=0; j<weight[i].size(); j++)
       child=min(child,shortest(weight[i][j].ff,n)+weight[i][j].ss);

     if(child==BIG)
        return dp[i]=0;

    return dp[i]=child;
}

int main()
{
    fast_cin;


    ll lock=0,sum=0,co=0,ans=BIG,a=0,b=0,c=0;
    ll n,m,k,mx=-BIG,mn=BIG;
    ll fir=0,sec=0;
    cin>>n>>m;
    memset(dp,-1,sizeof dp);

    for(int i=0; i<m; i++)
    {
        cin>>a>>b>>c;
         weight[a].push_back({b,c});
    }
    for(int i=0;i<=n;i++)
    {
        if(dp[i]==-1)
            ans=min(ans,shortest(i,n));
    }
    cout<<ans<<endl;

}
/*

4 6
0 3 1
0 1 2
3 1 3
1 4 9
1 2 1
2 4 3

*/

