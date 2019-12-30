import java.io.*;
import java.util.*;

public class Solution {

	public Solution () {
		int N = sc.nextInt();
		int [] P = new int [N];
		for (int i : rep(N))
			P[i] = sc.nextInt();

		int [] A = new int [N];
		int [] B = new int [N];
		boolean [] Z = new boolean [N];
		List<Integer> C = new ArrayList<>();
		List<Integer> pC = new ArrayList<>();

		for (int i : rep(N)) {
			A[i] = i-1;
			B[i] = i+1;
			C.add(i);
			pC.add(A[i]);
		}

		int res = 0;
		for (;;) {
			List<Integer> D = new ArrayList<>();
			List<Integer> pD = new ArrayList<>();
			boolean more = false;
			for (int i : rep(C.size())) {
				int x = C.get(i), px = pC.get(i);
				if (!Z[x]) {
					int s = A[x], t = B[x];
					if (x > 0 && P[x] > P[px]) {
						B[s] = t;
						if (t < N) {
							A[t] = s;
							D.add(t);
							pD.add(s);
						}
						more = Z[x] = true;
					}
				}
			}
			C = D; pC = pD;
			if (more)
				++res;
			else
				break;
		}

		print(res);
	}

	private static final boolean ONE_TEST_CASE = true;

	private static int [] rep(int N) { return rep(0, N); }
	private static int [] rep(int S, int T) { if (T <= S) return new int [0]; int [] res = new int [T-S]; for (int i = S; i < T; ++i) res[i-S] = i; return res; }
	////////////////////////////////////////////////////////////////////////////////////
	static Scanner sc = new Scanner(System.in);
	//private final static IOUtils.MyScanner sc = new IOUtils.MyScanner();
	private static void print (Object o, Object ... A) { IOUtils.print(o, A); }
	private static class IOUtils {
		private static String build(Object o, Object ... A) { return buildDelim(" ", o, A); }
		private static String buildDelim(String delim, Object o, Object ... A) {
			StringBuilder b = new StringBuilder();
			append(b, o, delim);
			for (Object p : A)
				append(b, p, delim);
			return b.substring(delim.length());
		}
		private static void append(StringBuilder b, Object o, String delim) {
			if (o.getClass().isArray()) {
				int len = java.lang.reflect.Array.getLength(o);
				for (int i = 0; i < len; ++i)
					append(b, java.lang.reflect.Array.get(o, i), delim);
			} else if (o instanceof Iterable<?>)
				for (Object p : (Iterable<?>) o)
					append(b, p, delim);
			else {
				if (o instanceof Double)
					o = new java.text.DecimalFormat("#.############").format(o);
				b.append(delim).append(o);
			}
		}
		private static java.io.PrintWriter pw = new java.io.PrintWriter(System.out);
		private static void print(Object o, Object ... A) { pw.println(build(o, A)); }
		private static void err(Object o, Object ... A) { System.err.println(build(o, A)); }
		private static void exit() {
			IOUtils.pw.close();
			System.out.flush();
			err("------------------");
			err(IOUtils.time());
			System.exit(0);
		}
		private static long t;
		private static long millis() { return System.currentTimeMillis(); }
		private static String time() { return "Time: " + (millis() - t) / 1000.0; }
		private static void run(int N) {
			for (int n = 1; n <= N; ++n)
				new Solution();
			exit();
		}
	}
	public static void main(String[] args) throws IOException {
		int N = ONE_TEST_CASE ? 1 : sc.nextInt();
		IOUtils.run(N);
	}
}
