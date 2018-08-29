vector<vector<ll> > matMul(vector<vector<ll> >& a, vector<vector<ll> >& b)
{
    ll i,j,k;
    vector<vector<ll> > c(a.size(), vector<ll> (b[0].size()));
    for(i=0; i<a.size(); i++)
    {
        for(k=0; k<b[0].size(); k++)
        {
            ll tmp=0;
            for(j=0; j<a[i].size(); j++)
            {
                tmp+=a[i][j]*b[j][k];
                tmp%=m;
                c[i][k]=tmp;
            }
        }
    }
    return c;
}
vector<vector<ll> > matPow(vector<vector<ll> > a, ll p)
{
    ll i,j;
    ll n=a.size();
    if(p==0)
    {
        vector<vector<ll> > singular(n,vector<ll> (n));
        for(i=0; i<n; i++)
            for(j=0; j<n; j++)
                if(i==j)
                    singular[i][j]=1;
        return singular;
    }
    vector<vector<ll> > x(n,vector<ll> (n));
    x=matPow(a,p/2);
    x=matMul(x,x);
    if(p%2==1)
        x=matMul(x,a);
    return x;
}
