#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
using namespace std;

const long N = 100000;
long uf[N];

long find(long x)
{
  while (uf[x] >= 0) {
    if (uf[uf[x]] >= 0)
      uf[x] = uf[uf[x]];
    x = uf[x];
  }
  return x;
}

int main()
{
  cin.sync_with_stdio(0);
  cin.tie(0);
  long cases, n, m, lib, road, u, v;
  for (cin >> cases; cases--; ) {
    cin >> n >> m >> lib >> road;
    fill_n(uf, n, -1);
    while (m--) {
      cin >> u >> v;
      u = find(u-1);
      v = find(v-1);
      if (u != v) {
        uf[u] += uf[v];
        uf[v] = u;
      }
    }
    u = lib <= road ? n : count_if(uf, uf+n, bind(less<long>(), placeholders::_1, 0));
    cout << u*lib+(n-u)*road << endl;
  }
}
