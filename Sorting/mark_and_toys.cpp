#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

int maximumToys(vector<int> prices, int k) {
    
    int n;
    int temp;
    int toys;
    int budget;
    int smallest_index;
    
    n = prices.size();
    toys = 0;
    budget = k;
    smallest_index=n-1;
    
    while(budget>0){
        for(int i = 0; i < smallest_index; i++){
            if(prices[i] < prices[i+1]){
                temp        = prices[i+1];
                prices[i+1] = prices[i];
                prices[i]   = temp;
            }
        }
        
        if(budget >= prices[smallest_index]){
            budget-=prices[smallest_index];
            toys++;
        }else{
            budget = -1;
        }
        smallest_index--;

    }
    
    return toys;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string prices_temp_temp;
    getline(cin, prices_temp_temp);

    vector<string> prices_temp = split_string(prices_temp_temp);

    vector<int> prices(n);

    for (int i = 0; i < n; i++) {
        int prices_item = stoi(prices_temp[i]);

        prices[i] = prices_item;
    }

    int result = maximumToys(prices, k);

    fout << result << "\n";

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