#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        unordered_map<int,vector<int> > m;
        vector<int> dist;
        vector<bool> visit;

        Graph(int n) {
            dist.resize(n,-1);
            visit.resize(n,0);

            for(int i=0;i<n;i++){
                m.insert(make_pair(i,vector<int>()));
            }
        }

        void add_edge(int u, int v) {
            m[u].push_back(v);
            m[v].push_back(u);
        }

        vector<int> shortest_reach(int start) {
            queue< pair<int,int> > q;
            q.push(make_pair(start,0));
            int e,d,i;
            visit[start]=1;

            while(!q.empty()){
                e=q.front().first;
                d=q.front().second;

                q.pop();

                for(i=0;i<m[e].size();i++){
                    if(visit[(m[e])[i]]==0){
                        visit[(m[e])[i]]=1;
                        dist[(m[e])[i]] = (d+1)*6;
                        q.push(make_pair( (m[e])[i],d+1 ));
                    }
                }
            }
            return dist;
        }

};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
