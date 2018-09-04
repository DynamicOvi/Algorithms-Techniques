#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> iPair;
void dijkstra(vector<vector<iPair>>& g, vector<ll>& distance, ll n, ll src)
{
    ll i,j;
    priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
    pq.push(make_pair(src,0));
    distance[src]=0;
    while(pq.empty()==0)
    {
        ll u=pq.top().second;
        pq.pop();
        for(auto in:g[u])
        {
            ll v=in.first;
            ll weight=in.second;
            if(distance[v]>distance[u]+weight)
            {
                distance[v]=distance[u]+weight;
                pq.push(make_pair(distance[v],v));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n,e,i,j;
    cin>>n>>e;
    vector<vector<iPair>> g(n+1);
    for(i=0;i<e;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    vector<ll> distance(n+1,INT_MAX);
    dijkstra(g,distance,n,1);
    for(i=1;i<=n;i++)
    {
        cout<<i<<": ";
        cout<<distance[i]<<endl;
    }
}
