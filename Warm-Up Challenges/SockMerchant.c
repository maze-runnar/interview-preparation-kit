#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
int n;
    scanf("%d",&n);
    int a[n],i,j,s=0;
    for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
    }
    
    for(i=0;i<n-1;i++)
        {
        for(j=i+1;j<n;j++)
            {
            if(a[i]==a[j]&&a[i]!=0&&a[j]!=0)
               { s++;
                a[i]=0;
                a[j]=0;}
        }
    }printf("%d",s);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
