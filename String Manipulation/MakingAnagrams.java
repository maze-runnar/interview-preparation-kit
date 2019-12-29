import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the makeAnagram function below.
    static int makeAnagram(String a, String b) {
        int hash[] = new int[27];
        char c[] = a.toCharArray();
        char d[] = b.toCharArray();
        for(int i=0; i<c.length; i++ ){
            hash[(int)c[i] - 97]++;
        }
        for(int i=0; i<d.length; i++ ){
            hash[(int)d[i] - 97]--;
        }

        for(int i=0; i<26; i++ ){
            if(hash[i]>0)
                hash[26] += hash[i];
            else
                hash[26] -= hash[i];
        }
    return hash[26];
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String a = scanner.nextLine();

        String b = scanner.nextLine();

        int res = makeAnagram(a, b);

        bufferedWriter.write(String.valueOf(res));
        bufferedWriter.newLine();

        bufferedWriter.close();

        scanner.close();
    }
}

