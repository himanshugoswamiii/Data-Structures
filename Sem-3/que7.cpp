#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{ 
    int n;
    cin>>n;
    vector<pair<int, int>>time(n);
    for(int i=0;i<n;i++){
        cin>>time[i].first;
        cin>>time[i].second;
    }
      
  
    sort(time.begin(),time.end());
  

    int ans=0;
    priority_queue<int,vector<int>,greater<int>>pq;
    int i=0;
    while(i<n)
    {
        while((!pq.empty())&&(time[i].first>=pq.top()))
        {
            pq.pop();
        }
        pq.push(time[i].second);
        ans=max(ans,(int)pq.size());
        i++;
    }
    cout<<ans<<"\n";
}
