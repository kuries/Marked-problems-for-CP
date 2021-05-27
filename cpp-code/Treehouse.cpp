//partially solved
#include<bits/stdc++.h>

using namespace std;

using ll = long long;

const long long M = 1e+7;

class thouse{

vector<vector<int>> store;
public:

    int pre(int x, int p)
    {
        int score=1, temp=1;
        vector<int> vec;
        for(auto it: store[x])
        {
            if(it != p)
            {
                vec.push_back(pre(it, x));
            }
        }

        if(vec.empty())
            return 1;
        
        sort(vec.begin(), vec.end(), greater<int>{});
        
        for(auto it: vec)
        {
            score = (score+(temp*it))%M;
            temp++;
        }
        
        return score;    
    }

    void solve()
    {
        int n, x;
        cin>>n>>x;
        for(int i=0; i<=n; i++)
        {
            vector<int> temp;
            store.push_back(temp);
        }
        for(int i=1; i<n; i++)
        {
            int u, v;
            cin>>u>>v;
            store[u].push_back(v);
            store[v].push_back(u);
        }
        int result = pre(1, -1)%M;
        result = (result*x)%M;
        cout<<result;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    cin>>t;
    while(t--)
    {
        thouse obj;
        obj.solve();
        cout<<"\n";
    }
    return 0;
}