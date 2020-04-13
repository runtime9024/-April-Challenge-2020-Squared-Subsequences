# -April-Challenge-2020-Squared-Subsequences
Code


#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dpL[100001];
ll dpR[100001];

int main()
{
    
    ll t;cin>>t;
    while(t--)
    {    
        memset(dpL,0,sizeof(dpL));
        memset(dpR,0,sizeof(dpR));
        ll n;cin>>n;
        ll a[n];
        
        for(ll i=0;i<n;i++)
        cin>>a[i];

        for(ll i=0;i<n;i++)
        {
            if(a[i]%4==0)
            a[i]=4;
            else if(a[i]%2==0)
            a[i]=2;
            else 
            a[i]=1;
            
        }
        
        ll prev=0;
        for(ll i=0;i<n;i++)
        {
            if(a[i]==2)
            {
                dpL[i]=i-prev;
                prev=i+1;
            }
            else if(a[i]==4)
            prev=i+1;
        }
        
        prev=n-1;
        for(ll i=n-1;i>=0;i--)
        {
            if(a[i]==2)
            {
                dpR[i]=prev-i;
                prev=i-1;
            }
            else if(a[i]==4)
            prev=i-1; 
        } 
        
        ll sum=0;
        for(ll i=0;i<n;i++)
        {
            if(a[i]==2)
            sum+=(dpL[i]+1)*(dpR[i]+1);
        }
        
        ll ans=n*(n+1)/2;
        
        cout<<ans-sum<<"\n";
        

    }
    return 0;
}
