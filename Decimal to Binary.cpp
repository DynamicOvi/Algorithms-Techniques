string d2b(ll n)
{
    string s;
    while(n!=0)
    {
        s.push_back(n%2+'0');
        n/=2;
    }
    reverse(s.begin(),s.end());
    return s;
}
