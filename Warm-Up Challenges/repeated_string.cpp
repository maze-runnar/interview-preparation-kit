#include <iostream>

using namespace std;

int main(){
    string s;
    cin >> s;
    long n;
    cin >> n;
    int len = s.length() ;
    int count=0 ;
    for(int i=0 ; i<len ; i++) {
        if(s[i]=='a') {
            count++ ;
        }
    }
    if(count==0) {
        cout << "0" << endl ;
    }
    else {
        long long int temp = n/len ;
        long long int ans= temp*count ;
        long long int c = n%len ;
        for(int i=0 ; i<c ; i++) {
            if(s[i]=='a') {
                ans++ ;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
