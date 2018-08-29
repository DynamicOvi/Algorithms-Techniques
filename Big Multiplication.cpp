string mul(string a, string b)
{
    ll sign=1;
    if(a=="0"||b=="0")
        return "0";
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    if(a.back()=='-')
        sign*=-1,a.pop_back();
    if(b.back()=='-')
        sign*=-1,b.pop_back();
    ll al=a.length(),bl=b.length(),i,j;
    vector<vector<char> > s(bl, vector<char> (al+bl,'0'));
    for(i=0;i<bl;i++)
    {
        for(ll ii=0;ii<i;ii++)
            s[i][ii]='0';
        ll r=0;
        for(j=0;j<al;j++)
        {
            ll p=b[i]-'0';
            ll q=a[j]-'0';
            ll tmp=p*q+r;
            char m=tmp%10+'0';
            r=tmp/10;
            s[i][i+j]=m;
        }
        char R=r+'0';
        s[i][i+al]=R;
    }
    vector<char> sum(al+bl);
    ll r=0;
    for(j=0;j<al+bl;j++)
    {
        ll tot=0;
        for(i=0;i<bl;i++)
            tot+=s[i][j]-'0';
        tot+=r;
        char m=tot%10+'0';
        sum[j]=m;
        r=tot/10;
    }
    string str;
    if(sign==-1)
        str+='-';
    ll f=0;
    for(i=al+bl-1;i>=0;i--)
    {
        if(sum[i]!='0')
            f=1;
        if(f==1)
            str+=sum[i];
    }
    return str;
}
