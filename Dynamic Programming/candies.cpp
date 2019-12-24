#include <cstdio>
#include <string>
using namespace std;

typedef long long ll;

int a[100005],b[100005];

inline int maxi(int x,int y) {
	return (x>y)?x:y;
}

int main() {
int i,j,n;
ll ans;

	scanf("%d",&n);
	for (i=1;i<=n;++i) {
		scanf("%d",&a[i]);
	}
	a[0]=a[1];
	a[n+1]=a[n];
	for (i=1;i<=n;++i) {
		if ((a[i]<=a[i+1]) && (a[i]<=a[i-1])) {
			b[i]=1;
			for (j=i-1;j && (a[j]>a[j+1]);--j) {
				b[j]=b[j+1]+1;
			}
			for (;i<n && (a[i+1]>a[i]);++i) {
				b[i+1]=b[i]+1;
			}
		}
	}
	ans=0;
	for (i=1;i<=n;++i) {
		if ((a[i]>a[i-1]) && (a[i]>a[i+1])) {
			b[i]=maxi(b[i-1],b[i+1])+1;
		}
		ans+=b[i];
	}
	printf("%Ld\n",ans);
	return 0;

}
