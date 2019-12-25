#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

long minimumPasses(long m, long w, long p, long n) {
    long passes = 0;
    long candy = 0;
    long run = LLONG_MAX;
    long step;

    while (candy < n) {
        step = (m > LLONG_MAX/w) ? 0 : (p - candy) / (m * w);

        if (step <= 0) {
            long mw = candy / p;

            if (m >= w + mw) {
                w += mw;
            } else if (w >= m + mw) {
                m += mw;
            } else {
                long total = m + w + mw;
                m = total / 2;
                w = total - m;
            }

            candy %= p;
            step = 1;
        }

        passes += step;

        if (step * m > LLONG_MAX / w) {
            candy = LLONG_MAX;
        } else {
            candy += step * m * w;
            run = min(run, long(passes + ceil((n - candy) / (m * w * 1.0))));
        }
    }

  return min(passes, run);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string mwpn_temp;
    getline(cin, mwpn_temp);

    vector<string> mwpn = split_string(mwpn_temp);

    long m = stol(mwpn[0]);

    long w = stol(mwpn[1]);

    long p = stol(mwpn[2]);

    long n = stol(mwpn[3]);

    long result = minimumPasses(m, w, p, n);

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
