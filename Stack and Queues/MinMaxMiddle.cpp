#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;

    int a[n];
    for(i=0;i<n;++i) {
        cin>>a[i];
    }

    stack<int> s;
    int left[n],right[n],ans[n+1],len;

    for(i=0;i<n;++i) {
        left[i]=-1,right[i]=n;
    }

    for(i=0;i<n;++i) {
        while(!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if(!s.empty()) {
            left[i]=s.top();
        }
        s.push(i);
    }

    while(!s.empty()) {
        s.pop();
    }

    for(i=n-1;i>=0;--i) {
        while(!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        if(!s.empty()) {
            right[i]=s.top();
        }
        s.push(i);
    }

    memset(ans, 0, sizeof ans);
    for(i=0;i<n;++i) {
        len = right[i]-left[i]-1;
        ans[len]=max(ans[len], a[i]);
    }

    for(i=n-1;i>=1;--i) {
        ans[i]=max(ans[i], ans[i+1]);
    }

    for(i=1;i<=n;++i) {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
