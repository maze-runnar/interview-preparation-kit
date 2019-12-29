#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int num,i,valley=0;
    scanf("%d",&num);
    char steps[num];
    scanf("%s",steps);
    int sea=0;
    for(i=0;i<num;i++)
        {
        if(sea==0 && steps[i]=='D')
            valley++;
        if(steps[i]=='U')
            sea++;
        else
            sea--;
        //printf("%d ",sea);
    }
    printf("%d",valley);
    return 0;
}
