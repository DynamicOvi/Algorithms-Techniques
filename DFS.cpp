ll dfs(vector<vector<ll> >& g, vector<ll>& mark, ll src)
{
    ll i;
    mark[src]=1;
    for(i=0; i<g[src].size(); i++)
    {
        ll x=g[src][i];
        if(mark[x]==0)
            dfs(g, mark, x);
    }
}
