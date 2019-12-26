import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {
    // Complete the sherlockAndAnagrams function below.
    static int sherlockAndAnagrams(String s) {
        LinkedList<String> myList = new LinkedList<>();
        int occurrences = 0;
        int t1 = s.length();
        for (int i = 0; i < t1; i++){
            for (int j = t1; j > i; j--){
                char[] temp = s.substring(i,j).toCharArray();
                Arrays.sort(temp);
                myList.add(new String(temp));
            }
        }
        for (String o : myList){
            for (String i : myList){
                if (o == i)
                    continue;
                if (o.equals(i))
                    occurrences++;
            }
        }
        return occurrences/2;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int q = scanner.nextInt();
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int qItr = 0; qItr < q; qItr++) {
            String s = scanner.nextLine();

            int result = sherlockAndAnagrams(s);

            bufferedWriter.write(String.valueOf(result));
            bufferedWriter.newLine();
        }

        bufferedWriter.close();

        scanner.close();
    }
}