import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    private static class Point {

        public int x;
        public int y;
        public Point(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object o) {

            // If the object is compared with itself then return true
            if (o == this) {
                return true;
            }

            /* Check if o is an instance of Complex or not
              "null instanceof [type]" also returns false */
            if (!(o instanceof Point)) {
                return false;
            }

            // typecast o to Complex so that we can compare data members
            Point c = (Point) o;

            // Compare the data members and return accordingly
            return (this.x == c.x && this.y == c.y);
        }

        public int hashCode()
        {
            return (x+y)*17;
        }

        @Override
        public String toString() {
            return "(" + x + ", " + y + ")";
        }
    }

    // get locations of all 1's
    private static Set<Point> get1s(int[][] matrix) {
        Set<Point> ones = new HashSet<Point>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 1) {
                    ones.add(new Point(i, j));
                }
            }
        }
        return ones;
    }


    // helper function to get indices of neighbors in a matrix
    private static Set<Point> getNeighbors(int row, int col, int[][] matrix) {
        Set<Point> neighbors = new HashSet<Point>();

        // booleans to know if the point is at an edge
        boolean isLeft = true;
        boolean isRight = true;
        boolean isTop = true;
        boolean isBottom = true;

        // get neighbors to the left
        if (col != 0) {
            neighbors.add(new Point(row, col-1));
            isLeft = false;
        }

        // get neighbors to the right
        if (col != matrix[0].length - 1) {
            neighbors.add(new Point(row, col + 1));
            isRight = false;
        }

        // get neighbors to the top
        if (row != 0) {
            neighbors.add(new Point(row - 1, col));
            isTop = false;
        }

        // get neighbors to the bottom
        if (row != matrix.length - 1) {
            neighbors.add(new Point(row + 1, col));
            isBottom = false;
        }

        // get top left
        if (!isTop && !isLeft) {
            neighbors.add(new Point(row - 1, col -1));
        }
        // get top right
        if (!isTop && !isRight) {
            neighbors.add(new Point(row - 1, col + 1));
        }

        // get bottom left
        if (!isBottom && !isLeft) {
            neighbors.add(new Point(row + 1, col -1));
        }
        // get bottom right
        if (!isBottom && !isRight) {
            neighbors.add(new Point(row + 1, col + 1));
        }

        return neighbors;
    }

    public static int getBiggestRegion(int[][] matrix) {
        // keep region lengths
        PriorityQueue<Integer> regionLengths = new PriorityQueue<Integer>(5, Collections.reverseOrder());
        Set<Point> visitedPoints = new HashSet<Point>();
        Set<Point> unvisited1s = get1s(matrix); // set of all unvisited ones

        if (unvisited1s.size() == 0) {
            return 0;
        }

        // dfs throughout matrix starting with top left
        Stack<Point> stack = new Stack<Point>();

        // get an unvisited 1 location
        for (Point p : unvisited1s) {
            stack.push(p);
            break;
        }

        Set<Point> regionVisited = new HashSet<Point>(); // points visited in current region
        while (!stack.isEmpty()) {
            Point p = stack.pop();
            visitedPoints.add(p);
            regionVisited.add(p);
            unvisited1s.remove(p); // we have now visited this 1
            Set<Point> neighbors = getNeighbors(p.x, p.y, matrix);
            // push unvisited neighbors (that aren't 0's) onto stack
            for (Point neighbor : neighbors) {
                if (!visitedPoints.contains(neighbor) && matrix[neighbor.x][neighbor.y] != 0) {
                    stack.push(neighbor);
                }
            }
            if (stack.isEmpty()) {
                regionLengths.add(regionVisited.size());
                regionVisited.clear();
                // start from an unvisited 1 if possible
                for (Point one : unvisited1s) {
                    stack.push(one);
                    break;
                }
            }
        }


        // get max from region lengths
        return regionLengths.peek();
    }



    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int m = in.nextInt();
        int grid[][] = new int[n][m];
        for(int grid_i=0; grid_i < n; grid_i++){
            for(int grid_j=0; grid_j < m; grid_j++){
                grid[grid_i][grid_j] = in.nextInt();
            }
        }
        System.out.println(getBiggestRegion(grid));
    }
}
