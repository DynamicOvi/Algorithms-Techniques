ll b2d(string s)
{
    reverse(s.begin(),s.end());
    ll n=0;
    ll i,j;
    for(i=0; i<s.size(); i++)
    {
        ll tmp=s[i]-'0';
        ll r=i;
        while(r--)
            tmp*=2;
        n+=tmp;
    }
    return n;
}
