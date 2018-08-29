#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m=1e9+7,base=137;
ll hs(string s)
{
    ll n=s.length();
    ll tot=0;
    ll bp;
    for(ll i=0; i<n; i++)
    {
        if(i==0)
            bp=1;
        else
        {
            bp*=base;
            bp%=m;
        }
        tot+=(s[i]*bp)%m;
        tot%=m;
    }
    return tot;
}
ll bigmod(ll a, ll b)
{
    if(b==0)
        return 1%m;
    ll x=bigmod(a,b/2);
    x=(x*x)%m;
    if(b%2==1)
        x=(x*a)%m;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll i,j,t,caseno=0;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll n=s.length();
        vector<ll> a(n),b(n);
        for(i=0;i<n;i++)
        {
            if(i==0)
                a[i]=hs(s);
            else
            {
                a[i]=a[i-1];
                a[i]-=s[i-1];
                a[i]%=m;
                if(a[i]<0)
                    a[i]+=m;
                a[i]*=bigmod(base,m-2);
                a[i]%=m;
                ll tmp=s[i-1]*bigmod(base,n-1);
                tmp%=m;
                a[i]+=tmp;
                a[i]%=m;
            }
        }
        reverse(s.begin(),s.end());
        for(i=0;i<n;i++)
        {
            if(i==0)
                b[i]=hs(s);
            else
            {
                b[i]=b[i-1];
                b[i]-=s[i-1];
                b[i]%=m;
                if(b[i]<0)
                    b[i]+=m;
                b[i]*=bigmod(base,m-2);
                b[i]%=m;
                ll tmp=s[i-1]*bigmod(base,n-1);
                tmp%=m;
                b[i]+=tmp;
                b[i]%=m;
            }
        }
        b.push_back(b.front());
        b.erase(b.begin());
        reverse(b.begin(),b.end());
        ll tot=0;
        for(i=0;i<n;i++)
            if(a[i]==b[i])
                tot++;
        cout<<tot<<endl;
    }
}
