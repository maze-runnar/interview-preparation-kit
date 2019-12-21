import java.io.*;
import java.util.*;


public class HourRank4qB {

	static int pos[], arr[];
	
	public static void main(String args[]) {
		InputReader in = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);

		int t = in.nextInt();
		
		while(t-- > 0 ){
		
			int n = in.nextInt();
	
			int a[] = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = in.nextInt() - 1;
			
			int op = 0;
			boolean yes = true;
			
			pos = new int[n];
			arr = new int[n];
			for(int i = 0; i < n; i++)
				arr[i] = pos[i] = i;
			
			for(int i = 0; i < n; i++){
				if(pos[a[i]] - i > 2){
					yes = false;
					break;
				}
				while(pos[a[i]] > i){
					swap(pos[a[i]], pos[a[i]] - 1);
					op++;
				}
			}
			
			w.println(yes ? op : "Too chaotic");
		}
		w.close();
	}
	
	static void swap(int i,int j){
		//swap ith and jth position
		pos[arr[i]] = j;
		pos[arr[j]] = i;
		int t = arr[i];
		arr[i] = arr[j];
		arr[j] = t;
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[8192];
		private int curChar, snumChars;
		private SpaceCharFilter filter;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int snext() {
			if (snumChars == -1)
				throw new InputMismatchException();
			if (curChar >= snumChars) {
				curChar = 0;
				try {
					snumChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (snumChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int nextInt() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long nextLong() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = snext();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = snext();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public String readString() {
			int c = snext();
			while (isSpaceChar(c))
				c = snext();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = snext();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public interface SpaceCharFilter {
			public boolean isSpaceChar(int ch);
		}
	}
}