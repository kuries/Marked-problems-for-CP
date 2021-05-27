#include<bits/stdc++.h>

using ll = long long;

using namespace std;

void solve()
{
    ll n, m, count=0;
    cin>>n>>m;
    vector<ll> vec(n+1, 1);
    for(int i=2; i<=n; i++)
    {
        ll temp = m%i;
        count+=vec[temp];
        for(ll j=temp; j<=n; j+=i)
        {
            vec[j]++;
        }
    }
    cout<<count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}