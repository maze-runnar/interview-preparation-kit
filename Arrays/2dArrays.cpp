#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector< vector<int> > arr(6,vector<int>(6));
    for(int arr_i = 0;arr_i < 6;arr_i++)
    {
       for(int arr_j = 0;arr_j < 6;arr_j++)
       {
          cin >> arr[arr_i][arr_j];
       }
    }
    int maxsum=-64;  
    int hoursum;   
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            hoursum=arr[i+1][j+1];    
            for(int k=0;k<3;k++)
                {                   
                    hoursum = hoursum + arr[i][j+k] + arr[i+2][j+k]; 
                }             
            if(hoursum > maxsum)         
                maxsum = hoursum;       
        }      
    }     
    cout<<maxsum;
    return 0;
}

