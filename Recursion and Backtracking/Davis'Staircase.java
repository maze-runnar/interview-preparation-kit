import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

 class Solution {

    public static class Matrix{
    static int n;
     public   Matrix(int n)
        {
            this.n=n;
        }

    static long[][] multiply(long[][] a ,long[][] b)
    {
        long[][] ans=new long[n][n];

        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++){
                ans[i][j]=0;
                for(int k=0;k<n;k++)
                    ans[i][j]+=a[i][k]*b[k][j];
            }
        return ans;
    }
    static void print(long[][] a)
    {
        for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                    System.out.print(a[i][j]+" ");
                System.out.println();
            }
    }
    //Matrix Exponentiation
    static long MatrixExpo(long[][] base ,int power )
    {
       // print(base);

       //base cases
        if(power<=0) return 0;
        if(power==1) return 1;
        if(power==2) return 2;
        if(power==3) return 4;

        power-=3;

        long[][] ans=new long[n][n];

           //Make Answer-matrix
         for(int i=1;i<n;i++)
            for(int j=0;j<n;j++)  ans[i][j]=0;
        ans[0][0]=4;ans[0][1]=2;ans[0][2]=1;

     //Left-handside matrix
     //4 2 1
     //0 0 0
     //0 0 0
            while(power>0)
            {
                if(power%2==1)
                    ans=multiply(ans ,base);
                power=power/2;
                base=multiply(base ,base);

            }
        //return final answer F(n)
        return ans[0][0];
    }


    }
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int s = in.nextInt();
        long[][] m=new long[3][3];
        //1 1 0
        //1 0 1
        //1 0 0
        m[0][0]=m[1][0]=m[2][0]=1;m[0][1]=1;m[0][2]=0;
        m[1][1]=0;m[1][2]=1;m[2][1]=0;m[2][2]=0;

        for(int a0 = 0; a0 < s; a0++){
            int n = in.nextInt();
            Matrix mat= new Matrix(3);
            System.out.println(Matrix.MatrixExpo(m ,n));
        }
    }
}
