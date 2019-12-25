#include<iostream>
#include<cstdio>
#include<cmath>
#include <limits.h>
using namespace std;
typedef long long int ll;
ll queryformax(ll b,ll e,ll a[],ll m[],ll n);
ll minval(ll a[],ll i,ll j)
{
	if(i==-1) return j;
	if(j==-1) return i;

	return (a[i]<a[j])?i:j;
}
ll rmq(ll node,ll b,ll e,ll a[],ll m[],ll i,ll j,ll n)
{
	if(j>=e && i<=b)
	{
		return m[node];
	}
	if(e<i || b>j)
	{
		return -1;
	}
	return minval(a,rmq(2*node+1,b,(b+e)/2,a,m,i,j,n),rmq(2*node+2,(b+e)/2+1,e,a,m,i,j,n));
}
ll initialise(ll node,ll b,ll e,ll a[],ll m[],ll n)
{
	if(b==e)
	{
		m[node]=b;
		return m[node];
	}
	m[node]=minval(a,initialise(2*node+1,b,(b+e)/2,a,m,n),initialise(2*node+2,(b+e)/2+1,e,a,m,n));
	return m[node];
}
ll queryformax(ll l,ll r,ll a[],ll m[],ll n)
{
	if(l==r)
	{
		return a[l];
	}
	if(l>r)
		return INT_MIN;
	ll m1=rmq(0,0,n-1,a,m,l,r,n);
	return max(a[m1]*(r-l+1),max(queryformax(l,m1-1,a,m,n),queryformax(m1+1,r,a,m,n)));
}
ll m[1000000];
int main()
{
	ll n,i;
	scanf("%lld",&n);
		
		ll a[n];
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
		}
		ll x=ceil(log2(n));
		x=2*pow(2,x)-1;
		for(i=0;i<x;i++)
		{
			m[i]=-1;
		}
		initialise(0,0,n-1,a,m,n);
		ll sum=queryformax(0,n-1,a,m,n);
		cout<<sum<<endl;

}
