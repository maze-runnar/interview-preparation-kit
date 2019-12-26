#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int n, fron1 = 0, rear1 = 0, initr, initc, finr, finc, en = 0, cnt = 0, minpath = 10201;
char ch;
struct grid
{
    char acc;
    int status;
    int pos;
};

struct d2
{
    int r;
    int c;
};

grid dot[102][102];
d2 que1[10201], item, orig[10201], store[10201];
int dir1[4] = {0, 1, 0, -1};
int dir2[4] = {1, 0, -1, 0};

void statcheck(int a, int b);
int pathfind();

int main()
{
    int path;
    //cout << "Enter the size of grid: ";
    cin >> n;
    //cout << "\nEnter the grid: \n";

    for(int i = 0; i <= 101; i++)
    {
        for(int j = 0; j <= 101; j++)
        {
            dot[i][j].status = 0;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> dot[i][j].acc;
            if(dot[i][j].acc != 'X')
                dot[i][j].status = 1;
        }
        //cout << endl;
    }

   // cout << "\n\n";


        //cout << "Enter the initial and final points: ";
        cin >> initr >> initc >> finr >> finc;

    for(int y = 0; y <= 3; y++)
    {
        fron1 = 0; rear1 = 0; en = 0; cnt = 0;
        fron1++;
        rear1++;
        if(y == 0)
        {
            initr++; initc++; finr++; finc++;
        }
        que1[rear1].r = finr;
        que1[rear1].c = finc;
        orig[cnt].r = 0;
        orig[cnt].c = 0;
        store[cnt].r = que1[rear1].r;
        store[cnt].c = que1[rear1].c;
        dot[que1[rear1].r][que1[rear1].c].pos = cnt;
        cnt++;

        //cout << endl << flag1 << " " << flag2;


        while(en != 1 && fron1 != 0)
        {
            ////cout << "\n" << fron1 << " " << rear1;

            item.r = que1[fron1].r;
            item.c = que1[fron1].c;

            if(fron1 == rear1)
            {
                fron1 = 0; rear1 = 0;
            }
            else if(fron1 == 10200)
                fron1 = 1;
            else
                fron1++;

            dot[item.r][item.c].status = 3;
            //cout << "\n" << item.r << " " << item.c;
            statcheck(dir1[y], dir2[y]);
        }


      /*  for(int a = 0; a < cnt; a++)
        {
            cout << "(" << orig[a].r << ", " << orig[a].c << ") ";
        }
        cout << endl;

        for(int a = 0; a < cnt; a++)
        {
            cout << "(" << store[a].r << ", " << store[a].c << ") ";
        } */


        path = pathfind();
        if(minpath > path)
            minpath = path;

         for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if(dot[i][j].acc != 'X')
                    dot[i][j].status = 1;
            }
        //cout << endl;
        }
    }
        cout << minpath;

        return 0;
}

void statcheck(int a, int b)
{
    for(int i = 1; i < n; i++)
    {

        if(dot[item.r + i*a][item.c + i*b].status == 1)
        {
            if(fron1 == 0)
            {
                fron1++; rear1++;
            }
            else if(rear1 == 10200)
                rear1 = 1;
            else
                rear1++;
            que1[rear1].r = item.r + i*a;
            que1[rear1].c = item.c + i*b;
            orig[cnt].r = item.r;
            orig[cnt].c = item.c;
            store[cnt].r = que1[rear1].r;
            store[cnt].c = que1[rear1].c;
            dot[item.r + i*a][item.c + i*b].pos = cnt;
            cnt++;
            dot[item.r + i*a][item.c + i*b].status = 2;
            //cout << "\n" << que1[rear1].r << " " << que1[rear1].c;
            if(que1[rear1].r == initr && que1[rear1].c == initc)
            {
                en = 1;
                return;
            }
            //cout << "\n" << fron1 << " " << rear1;

        }
        else
            break;
    }

    for(int i = 1; i < n; i++)
    {

        if(dot[item.r + i*b][item.c + i*a].status == 1)
        {
            if(fron1 == 0)
            {
                fron1++; rear1++;

            }
            else if(rear1 == 10200)
                rear1 = 1;
            else
                rear1++;
            que1[rear1].r = item.r + i*b;
            que1[rear1].c = item.c + i*a;
            orig[cnt].r = item.r;
            orig[cnt].c = item.c;
            store[cnt].r = que1[rear1].r;
            store[cnt].c = que1[rear1].c;
            dot[item.r + i*b][item.c + i*a].pos = cnt;
            cnt++;
            dot[item.r + i*b][item.c + i*a].status = 2;
            if(que1[rear1].r == initr && que1[rear1].c == initc)
            {
                en = 1;
                return;
            }
            //cout << "\n" << fron1 << " " << rear1;
        }
        else
            break;
    }

    for(int i = 1; i < n; i++)
    {

        if(dot[item.r - i*a][item.c - i*b].status == 1)
        {
            if(fron1 == 0)
            {
                fron1++; rear1++;
            }
            else if(rear1 == 10200)
                rear1 = 1;
            else
                rear1++;
            que1[rear1].r = item.r - i*a;
            que1[rear1].c = item.c - i*b;
            orig[cnt].r = item.r;
            orig[cnt].c = item.c;
            store[cnt].r = que1[rear1].r;
            store[cnt].c = que1[rear1].c;
            dot[item.r - i*a][item.c - i*b].pos = cnt;
            cnt++;
            dot[item.r - i*a][item.c - i*b].status = 2;
            if(que1[rear1].r == initr && que1[rear1].c == initc)
            {
                en = 1;
                return;
            }

            //cout << "\n" << fron1 << " " << rear1;
        }
        else
            break;
    }

    for(int i = 1; i < n; i++)
    {
        if(dot[item.r - i*b][item.c - i*a].status == 1)
        {
            if(fron1 == 0)
            {
                fron1++; rear1++;
            }
            else if(rear1 == 10200)
                rear1 = 1;
            else
                rear1++;
            que1[rear1].r = item.r - i*b;
            que1[rear1].c = item.c - i*a;
            orig[cnt].r = item.r;
            orig[cnt].c = item.c;
            store[cnt].r = que1[rear1].r;
            store[cnt].c = que1[rear1].c;
            dot[item.r - i*b][item.c - i*a].pos = cnt;
            cnt++;
            dot[item.r - i*b][item.c - i*a].status = 2;
            if(que1[rear1].r == initr && que1[rear1].c == initc)
            {
                en = 1;
                return;
            }

            //cout << "\n" << fron1 << " " << rear1;
        }
        else
            break;
    }

}




int pathfind()
{
    int n = cnt-1, m = n, x = m, length = 1, save;
    
   if(fron1 != 0)
  {      

   while(store[m].r != finr || store[m].c != finc)
    {


        if(store[x].r != store[n].r && store[x].c != store[n].c)
        {
            x = save;
            length++;
        }

        n = dot[orig[n].r][orig[n].c].pos;


        save = m;
        m = n;

        //cout << "\n" << length;

        //cout << "\n" << orig[m].r << " " << orig[m].c;
    }

    if(store[x].r != store[m].r && store[x].c != store[m].c)
            length++;
            //cout << "\n" << length;
  }
    else
        length = 10201;

    return length;
}
