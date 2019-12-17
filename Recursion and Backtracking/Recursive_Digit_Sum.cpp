#include <iostream>

using namespace std;

int sum_dig( long long int b){
    long long int sum=0;
    while(b/10!=0){
        sum = sum+ b%10;
        b = b/10;
    }//while
    sum = sum+b;
    return sum;
}

int pow_dig( long long int a){
    if(a/10==0){
        return a;
    }
    else{
        return pow_dig(sum_dig(a));
    }
}


int main() {
    string n;
    int k ;
     long long int sum=0;
    cin >> n >> k;
    for(int i=0;i<n.length();++i){
        char z= n[i];
        int x = z-'0';
        //cout << x<< endl;
        sum = sum+x;
    }
     sum = sum*k;
    
    int x= sum_dig(sum);
    int y = pow_dig(x);
    cout << y;
      
    return 0;
}
