import java.io.*;
import java.util.*;

public class Solution {

    private static final int NUMBER_OF_LINES = 6;
    
    private static int array[][]   = new int[NUMBER_OF_LINES][NUMBER_OF_LINES];
    private static Scanner input   = new Scanner(System.in);
    private static int result      = 0;
    
    private static String line;
    private static String arrayLine[];
    private static int temp;
    
    public static void main(String[] args) {
        for(int i=0;i<NUMBER_OF_LINES;i++)
        {
            line = input.nextLine();
            arrayLine = line.split(" ");
            for(int j=0; j<NUMBER_OF_LINES; j++)
                array[i][j] = Integer.valueOf(arrayLine[j]);
        }
        
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            {
                temp = doHourglassMath(array,i,j);
                if(i==0 && j==0)
                    result = temp;
                result = temp>result?temp:result;
            }     
        
        System.out.println(result);
    }
    
    private static int doHourglassMath(int array[][], int i, int j)
    {
        return array[i][j] + array[i][j+1] + array[i][j+2]
                           + array[i+1][j+1]
              +array[i+2][j]+array[i+2][j+1]+array[i+2][j+2];
    }
}