void sievePhi(vector<ll>& phi, ll n)
{
    ll i,j;
    vector<ll> mark(n+1);
    for(i=1;i<=n;i++)
        phi[i]=i;
    for(ll i=2;i<=n;i++)
        if(mark[i]==0)
            for(ll j=i;j<=n;j+=i)
                phi[j]=(phi[j]/i)*(i-1),mark[j]=1;
}
