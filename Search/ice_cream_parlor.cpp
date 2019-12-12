#include <bits/stdc++.h>

using namespace std;
const int INDEX = 0;
const int PRICE = 1;

static bool sortFn(vector<int> a, vector<int> b){return a[PRICE] < b[PRICE];};
vector<string> split_string(string);

void whatFlavors(vector<int> cost, int money) {
    int n = cost.size();
    vector< vector<int> > cwi(n, vector<int>(2));
    for(int i = 0; i < n; i++){
        cwi[i][INDEX] = i;
        cwi[i][PRICE] = cost[i];
    }
    
    sort(cwi.begin(), cwi.end(), sortFn );
    int  l = 0, r = n-1, sum;
    while(l < r){
        sum = cwi[l][PRICE] + cwi[r][PRICE];
        if(sum > money)
            r--;
        else if(sum < money)
            l++;
        else
            break;
    }
    int p1 = min(cwi[l][INDEX]+1 ,cwi[r][INDEX]+1 );
    int p2 = max(cwi[l][INDEX]+1 ,cwi[r][INDEX]+1 );
    
    cout << p1 << " " << p2 <<endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int money;
        cin >> money;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split_string(cost_temp_temp);

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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