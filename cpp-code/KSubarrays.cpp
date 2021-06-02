#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const ll val = numeric_limits<ll>::min();
const ll max_val = numeric_limits<ll>::max();
const int N=1e+5;
ll dp[N][101][2];
ll arr[N], n, k;

ll recursion(int i, int j, int started)
{
    if(j > k)
        return 0;
    if(i >= n)
        return val;

    ll &ans = dp[i][j][started];

    if(ans != max_val)
        return ans;

    if(started == 0)
    {
        ll l = recursion(i+1, j, 0);    //ignore this element
        ll r = recursion(i, j, 1);      //start from this element
        ans = max(l, r);
    }
    else
    {
        ll l = recursion(i+1, j, 1);    //continue the subarray
        ll r = recursion(i+1, j+1, 0);  //end the subarray here
        ans = max(l, r) + j*1ll*arr[i];
    }
    dp[i][j][started] = ans;
    return ans;
}

void solve()
{
    cin>>n>>k;
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
            dp[i][j][0] = dp[i][j][1] = max_val;
    }
    for(int i=0; i<n; i++)
        cin>>arr[i];
    cout<<recursion(0, 1, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    ll t = 1;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}