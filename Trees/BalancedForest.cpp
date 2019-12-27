#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

const int sz=1<<21+1;

struct node
{
    long long s; //c[i].s - sum of values in subtree rooted in i
    int u;  //time when dfs arrived in i-th node
    int o; //time when dfs leave i-th node ( all children are marked)
};

long long mini,sum;

node c[sz];
long long a[sz];
int tim,x,y,n;

vector <int> v[sz];
map <long long, int> mi,ma,mi1,ma1;


void clear_everything()
{
   sum=0;
   tim=0;

   for (int i=1;i<=n;i++)
    v[i].clear();

   ma.clear();
   ma1.clear();
   mi.clear();
   mi1.clear();
}

void dfs(int x, int pred)
{
    tim++;
    c[x].u=tim;
    c[x].s=a[x];

     for (int i=0;i<v[x].size();i++)
        if (v[x][i]!=pred)
    {
        dfs(v[x][i],x);
        c[x].s+=c[v[x][i]].s;
    }
     c[x].o=tim;

  return;
}


void do_it(int x)
{
   long long add=3*c[x].s-sum;

   if (mi[c[x].s]!=ma[c[x].s]) mini=min(mini,add); else
   if (mi[c[x].s-add] && (c[mi1[c[x].s-add]].u<c[x].u || c[mi1[c[x].s-add]].u>c[x].o)) mini=min(mini,add); else
   if (ma[c[x].s-add] && (c[ma1[c[x].s-add]].u<c[x].u || c[ma1[c[x].s-add]].u>c[x].o)) mini=min(mini,add); else
   if (mi[2*c[x].s-add]) mini=min(mini,add); else
   if (mi[2*c[x].s]) mini=min(mini,add);

   return ;
}

void uradi(int x)
{
  if ((sum-c[x].s)%2==0)
  {
      long long p=(sum-c[x].s)/2;
      if (ma[p] && (c[ma1[p]].u>c[x].u || c[ma1[p]].o<c[x].u)) mini=min(mini,p-c[x].s); else
      if (mi[p] && (c[mi1[p]].u>c[x].u || c[mi1[p]].o<c[x].u)) mini=min(mini,p-c[x].s); else
      if (mi[p+c[x].s] && c[mi1[p+c[x].s]].u<c[x].u && c[mi1[p+c[x].s]].o>=c[x].u) mini=min(mini,p-c[x].s); else
      if (ma[p+c[x].s] && c[ma1[p+c[x].s]].u<c[x].u && c[ma1[p+c[x].s]].o>=c[x].u) mini=min(mini,p-c[x].s);

      return ;
  }
}

void solve()
{
    scanf("%d",&n);

    clear_everything();
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }

       for (int i=1;i<n;i++)
           {
               scanf("%d%d",&x,&y);
               v[x].push_back(y);
               v[y].push_back(x);
           }

        dfs(1,0);

       for (int i=1;i<=n;i++)
            if (!mi[c[i].s])
        {
            mi[c[i].s]=c[i].u;
            ma[c[i].s]=c[i].u;
            mi1[c[i].s]=i;
            ma1[c[i].s]=i;
        } else
        {
           if (mi[c[i].s]>c[i].u)
           {
               mi[c[i].s]=c[i].u;
               mi1[c[i].s]=i;
           }
           if (ma[c[i].s]<c[i].u)
           {
               ma[c[i].s]=c[i].u;
               ma1[c[i].s]=i;
           }
          }

        mini=1e15;
        if (sum%2==0 && ma[sum/2])  mini=sum/2;

        for (int i=1;i<=n;i++)
            if (3*c[i].s<=sum) uradi(i); else
                if (2*c[i].s<sum) do_it(i);

      if (mini==1e15) printf("-1\n"); else
          printf("%lld\n",mini);

          return ;
    }
int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
        solve();

        return 0;
}

