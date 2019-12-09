#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
double getMedian(vector<int> occur, int elements);

int activityNotifications(vector<int> exp, int d) {
    
    int n;
    int count;
    int old_exp;
    vector<int>  occur(201);
    queue <int>  transaction_queue;
    double median;
    
    count = 0;
    n = exp.size();
    
    for(int i =0; i< d;i++)
        occur[exp[i]]++;
    
    
    for(int i =0; i< d;i++)
        transaction_queue.push(exp[i]);
    
    
    for(int i = d; i< n;i++){
        median = getMedian(occur, d);
        if(exp[i] >= 2.0*median){
            count++;
        }
        old_exp = transaction_queue.front();
        occur[old_exp]--;
        transaction_queue.pop();
        
        transaction_queue.push(exp[i]);
        occur[exp[i]]++;
    }
    
    
    return count;
}

double getMedian(vector<int> occur, int elements){
    
    int i;
    int j;
    bool isEven;
    int count;
    double median;
    
    i = 0;
    isEven = (elements % 2 == 0);
    count = 0;
    
    if(isEven){
        count = elements/2;
        
        while(count > 0){
            count -= occur[i];
            i++;
        }
        i--;
        if(count < 0){
            median = (double) i;
        }else{
            j = i+1;
            while(occur[j] == 0){
                j++;
            }
            
            median = (double) (i+j)/(2);
        }
    }else{
        count = floor(elements/2);
        while(count >= 0){
            count -= occur[i];
            i++;
        }
        i--;
        
        median = (double) (i);
    }
    
    return median;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nd_temp;
    getline(cin, nd_temp);

    vector<string> nd = split_string(nd_temp);

    int n = stoi(nd[0]);

    int d = stoi(nd[1]);

    string expenditure_temp_temp;
    getline(cin, expenditure_temp_temp);

    vector<string> expenditure_temp = split_string(expenditure_temp_temp);

    vector<int> expenditure(n);

    for (int i = 0; i < n; i++) {
        int expenditure_item = stoi(expenditure_temp[i]);

        expenditure[i] = expenditure_item;
    }

    int result = activityNotifications(expenditure, d);

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