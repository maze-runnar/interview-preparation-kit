import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.regex.*;

public class Solution {

    // Complete the checkMagazine function below.
    static void checkMagazine(String[] magazine, String[] note) {
        HashMap<String, Integer> freqMap = new HashMap<>();
        int flag=0;
        for(String magazineWord : magazine)
        {
            if(freqMap.containsKey(magazineWord))
            {
                int freq = freqMap.get(magazineWord)+1;
                freqMap.put(magazineWord, freq);
            }
            else
                freqMap.put(magazineWord, 1);
        }
        for(String noteWord : note)
        {
            if(freqMap.containsKey(noteWord))
            {
                int freq = freqMap.get(noteWord)-1;
                if(freq==0)
                    freqMap.remove(noteWord);
                else
                    freqMap.put(noteWord, freq);
            }
            else
            {
                System.out.println("No");
                flag=1;
                break;
            }
        }
        if(flag==0)
            System.out.println("Yes");
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String[] mn = scanner.nextLine().split(" ");

        int m = Integer.parseInt(mn[0]);

        int n = Integer.parseInt(mn[1]);

        String[] magazine = new String[m];

        String[] magazineItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < m; i++) {
            String magazineItem = magazineItems[i];
            magazine[i] = magazineItem;
        }

        String[] note = new String[n];

        String[] noteItems = scanner.nextLine().split(" ");
        scanner.skip("(\r\n|[\n\r\u2028\u2029\u0085])?");

        for (int i = 0; i < n; i++) {
            String noteItem = noteItems[i];
            note[i] = noteItem;
        }

        checkMagazine(magazine, note);

        scanner.close();
    }
}
