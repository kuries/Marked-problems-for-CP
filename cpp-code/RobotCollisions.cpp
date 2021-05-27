#include<bits/stdc++.h>

#define print_for(x)  for(auto it: x)cout<<it<<" ";cout<<"\n";
#define printx(x) cout<<x<<" "

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

void solve()
{
    int n, m;
    vector<pair<int, int>> store; //robot, dist
    cin>>n>>m;
    int times[n+1], direction[n+1];
    for(int i=0; i<n; i++)
    {
        int temp;
        cin>>temp;
        store.push_back(make_pair(i+1, temp));
    }
    direction[0] = 0;
    for(int i=1; i<=n; i++)
    {
        char ch;
        cin>>ch;
        if(ch == 'L')
            direction[i] = 0;
        else
            direction[i] = 1;
        times[i] = 0;
    }

    sort(store.begin(), store.end(), compare);

    stack<pair<int, int>> even, odd;

    // for(auto it: store)
    // {
    //     cout<<it.first<<": "<<it.second<<"\n";
    // }

    // print_for(direction);

    for(auto it: store)
    {
        if(it.second%2 == 0) //even
        {
            if(direction[it.first])
            {
                even.push(it);
            }
            else if(!even.empty())
            {
                pair<int, int> temp = even.top();
                even.pop();
                int t = (it.second-temp.second)/2;
                times[temp.first] += t;
                times[it.first] += t;
            }
            else
            {
                even.push(make_pair(it.first, -it.second));
            }
        }
        else
        {
            if(direction[it.first])
            {
                odd.push(it);
            }
            else if(!odd.empty())
            {
                pair<int, int> temp = odd.top();
                odd.pop();
                int t = (it.second-temp.second)/2;
                times[temp.first] += t;
                times[it.first] += t;
            }
            else
            {
                odd.push(make_pair(it.first, -it.second));
            }
        }
    }

    while(even.size() > 1)
    {
        pair<int, int> fir = even.top(), sec;
        even.pop();
        sec = even.top();
        even.pop();
        fir.second = m + m-fir.second;
        int k = (fir.second - sec.second)/2;
        times[fir.first] += k;
        times[sec.first] += k;
    }
    while(odd.size() > 1)
    {
        pair<int, int> fir = odd.top(), sec;
        odd.pop();
        sec = odd.top();
        odd.pop();
        fir.second = m + m-fir.second;
        int k = (fir.second - sec.second)/2;
        times[fir.first] += k;
        times[sec.first] += k;
    }
    for(int i=1; i<=n; i++)
    {
        if(times[i] > 0)
            cout<<times[i]<<" ";
        else
            cout<<-1<<" ";
    }
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