#include <bits/stdtr1c++.h>

#define MAX 100010
#define clr(ar) memset(ar, 0, sizeof(ar))
#define read() freopen("lol.txt", "r", stdin)
#define dbg(x) cout << #x << " = " << x << endl

using namespace std;

typedef pair<int, int> Pair;
typedef pair<int, Pair> dPair;

set <dPair> S;
vector <Pair> v;
int n, ar[MAX], R[MAX];

int main(){
    int i, j, k, l, r, c, d, x, y;

    while (scanf("%d", &n) != EOF){
        for (i = 0; i < n; i++) scanf("%d", &ar[i]);

        S.clear();
        for (i = 0; i < n; i++) R[i] = i + 1;
        for (i = 0; (i + 1) < n; i++){
            S.insert(dPair(ar[i] - ar[i + 1], Pair(i, i + 1)));
        }

        int counter = 0;
        while (!S.empty()){
            dPair cur = *(S.begin());
            if (cur.first >= 0) break;

            counter++;
            v.clear();
            for (auto it: S){
                if (it.first >= 0) break;

                l = (it.second).first;
                r = (it.second).second;
                v.push_back(Pair(r, l));
            }
            sort(v.begin(), v.end());

            int len = v.size();
            for (i = len - 1; i >= 0; i--){
                l = v[i].second, r = v[i].first;

                S.erase(dPair(ar[l] - ar[r], Pair(l, r)));
                int next_r = R[r];
                if (next_r != n){
                    S.erase(dPair(ar[r] - ar[next_r], Pair(r, next_r)));
                    S.insert(dPair(ar[l] - ar[next_r], Pair(l, next_r)));
                }
                R[l] = next_r;
            }
        }

        printf("%d\n", counter);
    }
    return 0;
}
