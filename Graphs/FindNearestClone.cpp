#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    map<int, vector<int>> c; // graph implementation using map
    vector<bool> v(graph_nodes+1); // vector to check if vertex is  covered or not
    vector<int> dist(graph_nodes+1,INT_MAX);

    for(int i=0; i< graph_nodes-1; i++)
    {
        c[graph_from[i]].push_back(graph_to[i]); // building graph
        c[graph_to[i]].push_back(graph_from[i]); // indirected edge
    }
    for(int clone=1; clone<=graph_nodes; clone++) //BFS to find the shortest path
    {
        queue<int> s;

        if(!v[clone] && ids[clone-1]==val)//check if that edge is the color to analyze
        {
            s.push(clone);
            v[clone]=true;
            dist[clone] = 0;
            while(!s.empty())
            {
                int visit = s.front();
                s.pop();
                for(auto connected: c[visit])
                {
                    if(!v[connected])
                    {
                        v[connected]=true;
                        s.push(connected);
                        dist[connected] = dist[visit] + 1;

                        if(ids[connected-1] == val)
                        {
                            return dist[connected];
                        }
                    }
                }
            }

        }
    }
    return -1;
    // solve here

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
