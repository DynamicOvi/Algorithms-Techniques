void bfs(vector<vector<ll> >& g, vector<ll>& mark, vector<ll>& level, vector<ll>& parent, queue<ll>& q, ll src)
{
    ll i,j;
    q.push(src),level[src]=0,mark[src]=1,parent[src]=-1;
    while(q.empty()==0)
    {
        ll p=q.front();
        q.pop();
        for(i=0; i<g[p].size(); i++)
        {
            ll x=g[p][i];
            if(mark[x]==0)
            {
                q.push(x);
                mark[x]=1;
                level[x]=level[p]+1;
                parent[x]=p;
            }
        }
    }
}
