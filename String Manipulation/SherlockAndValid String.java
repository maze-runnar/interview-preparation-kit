import java.util.HashMap;
import java.util.Scanner;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
/**
 *
 * @author Robert Nabil
 */
public class ValidString {

    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();

        HashMap<Character, Integer> h = new HashMap<Character, Integer>();
        for (char i : s.toCharArray()) {
            if (!h.containsKey(i)) {
                h.put(i, 0);
            }
            h.put(i, h.get(i) + 1);
        }

        boolean isValid = true;
        int n = h.get(s.charAt(0));
        for (int i : h.values()) {
            if (i != n) {
                isValid = false;
            }
        }

        if(isValid){
            System.out.println("YES");
            return;
        }


        for (int i = 0; i < s.length(); i++) {
            isValid = true;
            h.put(s.charAt(i), h.get(s.charAt(i)) - 1);
            n = h.get(s.charAt(0));
            for (int t : h.values()) {
                if (t != n && t > 0) {
                    isValid = false;
                }
            }
            h.put(s.charAt(i), h.get(s.charAt(i)) + 1);

            if(isValid){
               System.out.println("YES");
                return;
            }
        }

        System.out.println("NO");
    }
}
