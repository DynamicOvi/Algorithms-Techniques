#include<bits/stdc++.h>
using namespace std;
#define ll long long
void primeDivisor(vector<ll>& sieveArr,vector<ll>& divList,vector<ll>& primeDivList, ll n)
{
    ll i,j;
    for(ll i=0;i<divList.size();i++)
        if(sieveArr[divList[i]]==0)
            primeDivList.push_back(divList[i]);
}
void sieve(vector<ll>& sieveArr, vector<ll>& primeList, ll n)
{
    ll i,j;
    sieveArr[1]=1;
    for(ll i=2;i<=sqrt(n);i++)
        for(ll j=i+i;j<=n;j+=i)
            sieveArr[j]=1;
    for(ll i=1;i<=n;i++)
        if(sieveArr[i]==0)
            primeList.push_back(i);
}
void allDivisor(vector<ll>& divList,ll n)
{
    ll i,j;
    for(ll i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
            divList.push_back(i);
        if(n%i==0 && i!=n/i)
            divList.push_back(n/i);
    }
    sort(divList.begin(),divList.end());
}
void properties(vector<ll>& divList,vector<ll>& sieveArr,vector<ll>& primeList,vector<ll>& primeDivList,ll n)
{
    ll i,j;
    cout<<"Is n prime?: ";
    if(sieveArr[n]==0)
        cout<<"YES";
    else
        cout<<"NO";
    cout<<endl;
    cout<<"Primes upto n: ";
    for(i=0;i<primeList.size();i++)
        cout<<primeList[i]<<" ";
    cout<<endl;
    cout<<"Divisors of n: ";
    for(i=0;i<divList.size();i++)
        cout<<divList[i]<<" ";
    cout<<endl;
    cout<<"Prime Divisors: ";
    for(i=0;i<primeDivList.size();i++)
        cout<<primeDivList[i]<<" ";
    cout<<endl;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll i,j;
    ll n;
    cin>>n;
    vector<ll> sieveArr(n+1),primeList,divList,primeDivList;
    sieve(sieveArr,primeList,n);
    allDivisor(divList,n);
    primeDivisor(sieveArr,divList,primeDivList,n);
    properties(divList,sieveArr,primeList,primeDivList,n);
}
