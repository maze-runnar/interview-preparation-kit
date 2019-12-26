import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    static int count;

    // Complete the alternatingCharacters function below.
    static int alternatingCharacters(String s) 
    {
        char a ='A';
        char b= 'B';
        count=0;
        int len = s.length();

        for(int i=0;i<len-1;i++)
        {
            char ch1 = s.charAt(i);
            char ch2 = s.charAt(i+1);

            if(ch1==a && ch2!=b)
            {
                count++;
            }
            else if(ch1==b && ch2!=a)
            {
                count++;
            }
        }

        return count;



    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            int result = alternatingCharacters(s);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}
