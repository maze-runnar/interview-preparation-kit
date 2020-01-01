import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.util.Arrays.*;

public class Solution {
	private static final int mod = (int)1e9+7;

	final Random random = new Random(1);
	final IOFast io = new IOFast();

	public void run() throws IOException {
		final char[] cs = io.next();
		final int[][] cnt = new int[cs.length+1][256];
		final int[] xs = new int[256];
		final int[] map = new int[256];
		int n = 0;
		for(int i = 0; i < cs.length; i++) {
			cnt[cs.length][cs[i]]++;
		}
		for(int i = 0; i < 256; i++) {
			if(cnt[cs.length][i] > 0) {
				map[i] = n;
				xs[n++] = i;
			}
		}
		final int[][] pos = new int[n][];
		for(int i = 0; i < n; i++) {
			pos[i] = new int[cnt[cs.length][xs[i]]];
		}
		for(int i = 0; i < cs.length; i++) {
			for(int j = 0; j < n; j++) {
				cnt[i+1][j] = cnt[i][j];
			}
			pos[map[cs[i]]][cnt[i+1][map[cs[i]]]] = i;
			cnt[i+1][map[cs[i]]]++;
		}
//		System.err.println(Arrays.binarySearch(new int[] {1, 2, 3, }, 1));
		final int[] use = new int[n];
		char[] ans = new char[cs.length / 2];
		for(int x = cs.length - 1, idx = 0; idx < ans.length; ) {
			LOOP: for(int i = 0; i < n; i++) if(use[i] * 2 != cnt[cs.length][i]) {
				int p = Arrays.binarySearch(pos[i], x);
				if(p < 0) p = -p - 2;
				if(p < 0) continue;
				for(int j = 0; j < n; j++) if(i != j) {
					final int mid = pos[i][p];
					final int m = cnt[cs.length][j] / 2;
					if(use[j] + cnt[mid][j] < m) {
						continue LOOP;
					}
				}
//				System.err.println(low + " " + high + " " + x + " " + idx + " " + i);
//				System.err.println(x + " " + p + " " + i + " " + Arrays.toString(use) + " " + Arrays.toString(pos[i]));
				{
					ans[idx++] = (char)xs[i];
					use[i]++;
					x = pos[i][p] - 1;
					break;
				}
			}
		}
		io.out.println(new String(ans));
	}

	void main() throws IOException {
		//		IOFast.setFileIO("rle-size.in", "rle-size.out");
		try {
			run();
		}
		catch (EndOfFileRuntimeException e) { }
		io.out.flush();
	}

	public static void main(String[] args) throws IOException {
		new Solution().main();
	}

	static class EndOfFileRuntimeException extends RuntimeException {
		private static final long serialVersionUID = -8565341110209207657L; }

	static
	public class IOFast {
		private BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		private PrintWriter out = new PrintWriter(System.out);

		void setFileIO(String ins, String outs) throws IOException {
			in = new BufferedReader(new FileReader(ins));
			out = new PrintWriter(new FileWriter(outs));
		}

		//		private static final int BUFFER_SIZE = 50 * 200000;
		private static int pos, readLen;
		private static final char[] buffer = new char[1024 * 8];
		private static final char[] str = new char[500000*8*2];
		private static boolean[] isDigit = new boolean[256];
		private static boolean[] isSpace = new boolean[256];
		private static boolean[] isLineSep = new boolean[256];

		static {
			for(int i = 0; i < 10; i++) { isDigit['0' + i] = true; }
			isDigit['-'] = true;
			isSpace[' '] = isSpace['\r'] = isSpace['\n'] = isSpace['\t'] = true;
			isLineSep['\r'] = isLineSep['\n'] = true;
		}

		public int read() throws IOException {
			if(pos >= readLen) {
				pos = 0;
				readLen = in.read(buffer);
				if(readLen <= 0) { throw new EndOfFileRuntimeException(); }
			}
			return buffer[pos++];
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(nextString());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(nextString());
		}

		public char nextChar() throws IOException {
			while(true) {
				final int c = read();
				if(!isSpace[c]) { return (char)c; }
			}
		}

		int reads(char[] cs, int len, boolean[] accept) throws IOException {
			try {
				while(true) {
					final int c = read();
					if(accept[c]) { break; }
					str[len++] = (char)c;
				}
			}
			catch(EndOfFileRuntimeException e) { ; }

			return len;
		}

		public char[] nextLine() throws IOException {
			int len = 0;
			str[len++] = nextChar();
			len = reads(str, len, isLineSep);

			try {
				if(str[len-1] == '\r') { len--; read(); }
			}
			catch(EndOfFileRuntimeException e) { ; }

			return Arrays.copyOf(str, len);
		}

		public String nextString() throws IOException {
			return new String(next());
		}

		public char[] next() throws IOException {
			int len = 0;
			str[len++] = nextChar();
			len = reads(str, len, isSpace);
			return Arrays.copyOf(str, len);
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(nextString());
		}

	}

}
