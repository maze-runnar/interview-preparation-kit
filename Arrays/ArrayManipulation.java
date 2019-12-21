import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc=new Scanner(System.in);
				
				long N=sc.nextLong();
				long M=sc.nextLong();
				
				long A[]=new long[(int)N+1];
				for(int i=1;i<=N;i++) A[i]=0;
				
				long max=0,sum=0;;
				
				long a;
				long b;
				long k;
				
				for(int i=1;i<=M;i++)
					{
						a=sc.nextLong();
						b=sc.nextLong();
						k=sc.nextLong();
						A[(int)a]+=k;
						if(b<N)A[(int)b+1]-=k;
					}
				
				
				
				
				
				for(int i=1;i<=N;i++) 
					{
						sum+=A[i];
						if(sum>max) max=sum;
					}
				System.out.println(max);
    }
}