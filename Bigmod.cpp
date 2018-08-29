ll bigmod(ll a, ll b, ll m)
{
    if(b==0)
        return 1%m;
    ll x=bigmod(a,b/2,m);
    x=(x*x)%m;
    if(b%2==1)
        x=(x*a)%m;
    return x;
}
