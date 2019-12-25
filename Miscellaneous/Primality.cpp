#include <bits/stdc++.h>
#include <math.h>

using namespace std;

string primality(int n) {

int c=0;
for(int i=2; i<=sqrt(n);i++)
{
    if(n%i==0){
        c=1;
        break;
    }
    
}
if(c==1||n==1)
    return("Not prime");
else
{return("Prime");}


}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int p_itr = 0; p_itr < p; p_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string result = primality(n);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
