#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    char* s = (char *)malloc(512000 * sizeof(char));
    scanf("%s",s);
    long n,c=0; 
    scanf("%ld",&n);
    int len=strlen(s);
    if(n<len)
        {
        int i;
        for(i=0;i<n;i++)
            {
              if(s[i]=='a')
                  c++;
            }
        printf("%ld",c);
    }
    else
        {
         int i;
        for(i=0;i<len;i++)
            {
              if(s[i]=='a')
                  c++;
            }
        long int x=n/len;
        c*=x;
        for(i=0;i<n%len;i++)
            {
              if(s[i]=='a')
                  c++;
            }
        printf("%ld",c);
    }
    return 0;
