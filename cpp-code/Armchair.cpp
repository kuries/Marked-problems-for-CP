#include<bits/stdc++.h>

#define print_for(x)  for(auto it: x)cout<<it<<" ";cout<<"\n";
#define forn(i, s, n) for(int i=s; i<n; i++)
#define printx(x) cout<<x<<" "

using namespace std;

void solve()
{
    int number;
    cin>>number;
    vector<int> occ, unoc;
    forn(i, 1, number+1)
    {
        int temp;
        cin>>temp;
        if(temp)
            occ.push_back(i);
        else
            unoc.push_back(i);
    }
    int n = occ.size()+1, m =unoc.size()+1;
    if(n==0)
    {
        cout<<0;
        return;
    }
    int arr[n][m];

    forn(i, 0, n)
        forn(j, 0, m)
            arr[i][j] = 0;
    
    forn(i, 1, n)
        forn(j, 0, i)
            arr[i][j] = -1;

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            int fill=arr[i-1][j-1], not_fill=arr[i][j-1], k = abs(occ[i-1] - unoc[j-1]);
            if(fill==-1)
                arr[i][j] = not_fill;
            else if(not_fill == -1)
                arr[i][j] = fill+k;
            else
                arr[i][j] = min(fill+k, not_fill);
        }
    }

    cout<<arr[n-1][m-1];

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
    {
        solve();
        cout<<"\n";
    }
    return 0;
}