import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";

	void solve()
	{
		for(int T = ni();T > 0;T--){
			int n = ni();
			int[] a = na(n);
			int[] from = new int[n - 1];
			int[] to = new int[n - 1];
			for (int i = 0; i < n - 1; i++) {
				from[i] = ni() - 1;
				to[i] = ni() - 1;
			}
			int[][] g = packU(n, from, to);
			int[][] pars = parents3(g, 0);
			int[] par = pars[0], ord = pars[1], dep = pars[2];
			int[][] rs = makeRights(g, par, 0);
			int[] iord = rs[1], right = rs[2];
			int[][] spar = logstepParents(par);

			long[] des = new long[n];
			for(int i = n-1;i >= 0;i--){
				int cur = ord[i];
				des[cur] += a[cur];
				if(i > 0)des[par[cur]] += des[cur];
			}

			long W = des[0];

			long ret = Long.MAX_VALUE;
			// t=u
			{
				long[] dd = Arrays.copyOf(des, n);
				Arrays.sort(dd);
				for(int i = 0;i < n-1;i++){
					if(dd[i] == dd[i+1] && W-2*dd[i] <= dd[i] && W-2*dd[i] >= 0){
						ret = Math.min(ret, dd[i]-(W-2*dd[i]));
					}
				}
			}

			// s=t
			{
				long[][] poss = new long[n][];
				for(int i = 0;i < n;i++){
					poss[i] = new long[]{des[i], iord[i]};
				}
				Arrays.sort(poss, new Comparator<long[]>() {
					public int compare(long[] a, long[] b) {
						if(a[0] != b[0])return Long.compare(a[0], b[0]);
						return Long.compare(a[1], b[1]);
					}
				});
				long[] posv = new long[n];
				for(int i = 0;i < n;i++)posv[i] = poss[i][0];
				for(int i = 0;i < n;i++){
					long t = des[i];
					long u = W-2L*t;
					if(u >= 0 && t >= u){
						int lb = lowerBound(posv, u);
						int ub = lowerBound(posv, u+1);
						if(lb < ub){
							if((int)poss[lb][1] < iord[i]){
								ret = Math.min(ret, t-u);
							}
							if((int)poss[ub-1][1] > right[iord[i]]){
								ret = Math.min(ret, t-u);
							}
						}
					}
				}
			}

			// ireko
			// t=u
			{
				for(int i = 0;i < n;i++){
					long u = des[i];
					long s = W-u*2;
					if(s >= 0 && s <= u){
						int cur = i;
						for(int h = spar.length-1;h >= 0;h--){
							int anc = spar[h][cur];
							if(anc == -1)continue;
							if(des[anc] <= 2*u){
								cur = anc;
							}
						}
						if(des[cur] == 2*u){
							ret = Math.min(ret, u-s);
						}
					}
				}
			}

			// s=u
			{
				for(int i = 0;i < n;i++){
					long u = des[i];
					long t = W-u*2;
					if(t >= 0 && t <= u){
						int cur = i;
						for(int h = spar.length-1;h >= 0;h--){
							int anc = spar[h][cur];
							if(anc == -1)continue;
							if(des[anc] <= t+u){
								cur = anc;
							}
						}
						if(des[cur] == t+u){
							ret = Math.min(ret, u-t);
						}
					}
				}
			}
			// s=t
			{
				for(int i = 0;i < n;i++){
					long u = des[i];
					if((W-u)%2 != 0)continue;
					long t = (W-u)/2;
					if(t >= 0 && t >= u){
						int cur = i;
						for(int h = spar.length-1;h >= 0;h--){
							int anc = spar[h][cur];
							if(anc == -1)continue;
							if(des[anc] <= t+u){
								cur = anc;
							}
						}
						if(des[cur] == t+u){
							ret = Math.min(ret, t-u);
						}
					}
				}
			}
			if(ret == Long.MAX_VALUE){
				out.println(-1);
			}else{
				out.println(ret);
			}
		}
	}

	public static int lowerBound(long[] a, long v)
	{
		int low = -1, high = a.length;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h] >= v){
				high = h;
			}else{
				low = h;
			}
		}
		return high;
	}


	public static int[] sortByPreorder(int[][] g, int root){
		int n = g.length;
		int[] stack = new int[n];
		int[] ord = new int[n];
		BitSet ved = new BitSet();
		stack[0] = root;
		int p = 1;
		int r = 0;
		ved.set(root);
		while(p > 0){
			int cur = stack[p-1];
			ord[r++] = cur;
			p--;
			for(int e : g[cur]){
				if(!ved.get(e)){
					stack[p++] = e;
					ved.set(e);
				}
			}
		}
		return ord;
	}

	public static int[][] makeRights(int[][] g, int[] par, int root)
	{
		int n = g.length;
		int[] ord = sortByPreorder(g, root);
		int[] iord = new int[n];
		for(int i = 0;i < n;i++)iord[ord[i]] = i;

		int[] right = new int[n];
		for(int i = n-1;i >= 0;i--){
			int v = i;
			for(int e : g[ord[i]]){
				if(e != par[ord[i]]){
					v = Math.max(v, right[iord[e]]);
				}
			}
			right[i] = v;
		}
		return new int[][]{ord, iord, right};
	}


	public static int lca2(int a, int b, int[][] spar, int[] depth) {
		if (depth[a] < depth[b]) {
			b = ancestor(b, depth[b] - depth[a], spar);
		} else if (depth[a] > depth[b]) {
			a = ancestor(a, depth[a] - depth[b], spar);
		}

		if (a == b)
			return a;
		int sa = a, sb = b;
		for (int low = 0, high = depth[a], t = Integer.highestOneBit(high), k = Integer
				.numberOfTrailingZeros(t); t > 0; t >>>= 1, k--) {
			if ((low ^ high) >= t) {
				if (spar[k][sa] != spar[k][sb]) {
					low |= t;
					sa = spar[k][sa];
					sb = spar[k][sb];
				} else {
					high = low | t - 1;
				}
			}
		}
		return spar[0][sa];
	}

	protected static int ancestor(int a, int m, int[][] spar) {
		for (int i = 0; m > 0 && a != -1; m >>>= 1, i++) {
			if ((m & 1) == 1)
				a = spar[i][a];
		}
		return a;
	}

	public static int[][] logstepParents(int[] par) {
		int n = par.length;
		int m = Integer.numberOfTrailingZeros(Integer.highestOneBit(n - 1)) + 1;
		int[][] pars = new int[m][n];
		pars[0] = par;
		for (int j = 1; j < m; j++) {
			for (int i = 0; i < n; i++) {
				pars[j][i] = pars[j - 1][i] == -1 ? -1 : pars[j - 1][pars[j - 1][i]];
			}
		}
		return pars;
	}


	public static int[][] parents3(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		depth[0] = 0;

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int nex : g[cur]) {
				if (par[cur] != nex) {
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] { par, q, depth };
	}

	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
	}


	void run() throws Exception
	{
		is = INPUT.isEmpty() ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
	}

	public static void main(String[] args) throws Exception { new E().run(); }

	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;

	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}

	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }

	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }

	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}

	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}

	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}

	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}

		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}

		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}

	private static void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
}
