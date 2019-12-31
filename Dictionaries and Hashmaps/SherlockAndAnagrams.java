import java.io.*;
import java.util.*;
public class Solution
{
    public static void main(String[] args)
    {
        int m,n;
        String s="",temp="";
        Scanner in = new Scanner(System.in);
        m = in.nextInt();
        while(m!=0)
        {
            s = in.next();
            n = s.length();
            int p = 0,t=0;
            int z = (n*n)-(((n*n)-n)/2);
            String posi[] = new String[z];
            for(int x=0;x<n;x++)
            {
                for(int y=0;y<n;y++)
                {
                    if(x<=y)
                    {
                        temp = s.substring(x,y+1);
                        char c[] = temp.toCharArray();
                        Arrays.sort(c);
                        temp = new String(c);
                        posi[p] = temp;
                        p++;
                    }
                }
            }
            for(int i=0;i<z;i++)
            {
                for(int j=i+1;j<z;j++)
                {
                    if(posi[i].equals(posi[j]))
                    {
                        t++;
                    }
                }
            }
            System.out.println(t);
            m--;
        }
    }
}
