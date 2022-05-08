#include<bits/stdc++.h>
using namespace std;
long long tim(long long n)
{   long long a=2,b=2,d=1;
    while(d==1)
    {
        a=(a*a+1) %n;
        b=(b*b+1) %n;
        b=(b*b+1)%n;
        d=__gcd(abs(a-b),n);
        if(1<d && d<n)
             return d;
        else if(d==n)
            return 0;
    }
}
int main()
{   long long n;
    cin>>n;
    cout<<tim(n);
}
