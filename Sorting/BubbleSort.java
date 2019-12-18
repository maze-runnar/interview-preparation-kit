import static java.lang.Integer.parseInt;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.StringTokenizer;

public class Day20_Sorting {

	static int MB = 1 << 20;
	static BufferedReader BR = new BufferedReader( new InputStreamReader(System.in, StandardCharsets.US_ASCII), 20 * MB);
	
	static StringTokenizer st;
	static String lastLine;
	
	static void newLine() throws IOException {
		lastLine = BR.readLine();
		st = new StringTokenizer(lastLine);
	}
	
	public static void main(String[] args) throws IOException {
		newLine();
		int N = parseInt(st.nextToken());
		
		newLine();
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = parseInt(st.nextToken());
		}

		int numberOfSwapps = bubbleSort(N, A);
		int firstElement = A[0];
		int lastElement = A[N-1];
		print(numberOfSwapps, firstElement, lastElement);
	}

	private static void print(int numberOfSwapps, int firstElement, int lastElement) {
		StringBuilder sb = new StringBuilder();
		
		sb.append("Array is sorted in ").append(numberOfSwapps).append(" swaps.\n");
		sb.append("First Element: ").append(firstElement).append('\n');
		sb.append("Last Element: ").append(lastElement).append('\n');
		
		System.out.print(sb);
	}

	private static int bubbleSort(int N, int[] A) {
		int cnt = 0;
		
		for (int i = 0; i < N; i++) {
		    // Track number of elements swapped during a single array traversal
		    int numberOfSwaps = 0;
		    
		    for (int j = 0; j < N - 1; j++) {
		        // Swap adjacent elements if they are in decreasing order
		        if (A[j] > A[j + 1]) {
		            swap(A, j , j + 1);
		            numberOfSwaps++;
		        }
		    }
		    cnt += numberOfSwaps;
		    
		    // If no elements were swapped during a traversal, array is sorted
		    if (numberOfSwaps == 0) {
		        break;
		    }
		}
		
		return cnt;
	}

	private static void swap(int[] a, int i, int j) {
		int tmp = a[i];
		a[i] = a[j];
		a[j] = tmp;
	}

}