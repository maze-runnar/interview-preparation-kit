#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n,h,max=-1,time;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        {
           scanf("%d",&h);
        if(max<h)
            {
            max=h;
            time=1;
        }
        else
            {
            if(max==h)
             time++;   
        }
    }
    printf("%d\n",time);
    return 0;
}
