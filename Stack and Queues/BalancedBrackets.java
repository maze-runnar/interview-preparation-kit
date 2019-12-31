import java.io.*;
import java.util.*;

public class Solution {
    private char smallOpen = '(';
    private char smallClose = ')';

    private char midOpen = '[';
    private char midClose = ']';

    private char bigOpen = '{';
    private char bigClose = '}';

    List<Character> oList = Arrays.asList(smallOpen, midOpen, bigOpen);
    Map<Character, Character> openToCloseMap = new HashMap<>();

    {
        openToCloseMap.put(smallOpen, smallClose);
        openToCloseMap.put(midOpen, midClose);
        openToCloseMap.put(bigOpen, bigClose);
    }

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Solution sol = new Solution();

        sol.process();
    }

    public void process() {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        sc.nextLine();

        for (int i = 0; i < N; i++) {
            String s = sc.nextLine();
            System.out.println(process(s)? "YES" : "NO");
        }
    }

    public boolean process(String s) {
        Deque<Character> deque = new ArrayDeque<>();

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (oList.contains(c)) {
                deque.push(c);
            } else {
                if (deque.isEmpty()) {
                    return false;
                }

                char pop = deque.pop();
                if (openToCloseMap.get(pop) != c) {
                    return false;
                }
            }
        }

        return deque.isEmpty();
    }
}
