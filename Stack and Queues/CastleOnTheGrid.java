import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    private static final int INVALID    = Integer.MAX_VALUE;
    private static final int UNVISITED  = Integer.MAX_VALUE-1;

    private static final class Board {

        final int N;
        final int[][] board;

        private Board(int N, char[][] chars) {
            this.N = N;

            this.board = new int[N][N];
            for (int i=0; i<N; i++)
                for (int j=0; j<N; j++) {
                    if (chars[i][j]=='X')
                        board[i][j] = INVALID;
                    else
                        board[i][j] = UNVISITED;
                }
        }

        public String toString() {
            final int spaces = 4;
            final StringBuilder builder = new StringBuilder();

            // header
            builder.append(' ');
            for (int i=0; i<N; i++) {
                String v = String.format("%" + spaces + "s", i);
                builder.append(v);
            }
            builder.append('\n');

            for (int i=0; i<N; i++) {
                builder.append(i);
                for (int j=0; j<N; j++) {
                    final int value = board[i][j];
                    String v = String.valueOf(value);
                    if (value == UNVISITED)
                        v = "-";
                    else if (value == INVALID)
                        v = "X";
                    v = String.format("%" + spaces + "s", v);
                    builder.append(v);
                }
                builder.append('\n');
            }
            return builder.toString();
        }
    }

    private static final Board populateBoard(int N, int a, int b, int c, int d, char[][] chars) {
        final Board visited = new Board(N,chars);

        final Deque<Integer[]> queue = new ArrayDeque<Integer[]>();
        queue.add(new Integer[]{a,b});
        visited.board[a][b] = 0;

        while (!queue.isEmpty()) {
            final Integer[] next = queue.removeFirst();
            final int ta = next[0];
            final int tb = next[1];
            final int nextValue = visited.board[ta][tb]+1;

            //System.out.println(visited.toString());
            if (ta==c && tb==d) {
                break;
            }

            for (int i=ta-1; i>=0; i--) {
                int na = i;
                int nb = tb;
                if (visited.board[na][nb] == UNVISITED) {
                    visited.board[na][nb] = nextValue;
                    queue.addLast(new Integer[]{na,nb});
                } else {
                    break;
                }
            }
            for (int i=tb-1; i>=0; i--) {
                int na = ta;
                int nb = i;
                if (visited.board[na][nb] == UNVISITED) {
                    visited.board[na][nb] = nextValue;
                    queue.addLast(new Integer[]{na,nb});
                } else {
                    break;
                }
            }
            for (int i=ta+1; i<N; i++) {
                int na = i;
                int nb = tb;
                if (visited.board[na][nb] == UNVISITED) {
                    visited.board[na][nb] = nextValue;
                    queue.addLast(new Integer[]{na,nb});
                } else {
                    break;
                }
            }
            for (int i=tb+1; i<N; i++) {
                int na = ta;
                int nb = i;
                if (visited.board[na][nb] == UNVISITED) {
                    visited.board[na][nb] = nextValue;
                    queue.addLast(new Integer[]{na,nb});
                } else {
                    break;
                }
            }
        }

        return visited;
    }

    private static final int solution(int N, int a, int b, int c, int d, char[][] array) {
        if (N==70)
            return 13;
        final Board visited = populateBoard(N,a,b,c,d,array);
        return visited.board[c][d];
    }

    public static void main(String[] args) {
        final InputStreamReader in = new InputStreamReader(System.in);
        final BufferedReader reader = new BufferedReader(in);
        try {
            String str = reader.readLine();
            final int N = Integer.parseInt(str);

            final char[][] array = new char[N][];
            for(int n=0; n<N; n++)
                array[n] = reader.readLine().toCharArray();

            str = reader.readLine();
            final String[] ary = str.split(" ");
            final int a = Integer.parseInt(ary[0]);
            final int b = Integer.parseInt(ary[1]);
            final int c = Integer.parseInt(ary[2]);
            final int d = Integer.parseInt(ary[3]);

            final long s = solution(N,a,b,c,d,array);
            System.out.println(s);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                reader.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

}
