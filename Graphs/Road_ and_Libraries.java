import java.io.IOException;
import java.io.InputStream;
import java.util.InputMismatchException;

public class WCS8_3{

	void solve()
	{
		int Q = ni();
		while(Q-->0)
		{
			int n = ni();
			int m = ni();
			long cl = ni();
			long cr = ni();
			DJSet set = new DJSet(n);
			while(m-->0)
				set.union(ni()-1,ni()-1);
			long ans = 0;
			for(int i=0;i<n;i++)
			{
				if(set.head[i])
				{
					ans += Math.min(cl + (set.sizeOfSet(i)-1)*cr, set.sizeOfSet(i)*cl);
				}
			}
			System.out.println(ans);
		}
	}

	static class DJSet {

		int[] root;
		int[] size;
		boolean[] head;

		DJSet(int n)
		{
			root = new int[n];
			size = new int[n];
			head = new boolean[n];
			for(int i=0;i<n;i++)
			{
				root[i] = i;
				size[i] = 1;
				head[i] = true;
			}
		}

		public int root(int x)
		{
			while(root[x]!=x)
				x = root[root[x]];
			return x;
		}

		public void union(int x,int y)
		{
			int a = root(x);
			int b = root(y);

			if(a==b)
				return;

			if(size[a]<size[b])
			{
				head[a] = false;
				root[a] = b;
				size[b] += size[a];
			}
			else
			{
				head[b] = false;
				root[b] = a;
				size[a] += size[b];
			}
		}

		public boolean find(int x,int y)
		{
			return root(x)==root(y);
		}

		public int sizeOfSet(int x)
		{
			return size[root(x)];
		}

	}


	public static void main(String[] args){new WCS8_3().solve();}

	private byte[] bufferArray = new byte[1024];
	private int bufLength = 0;
	private int bufCurrent = 0;
	InputStream inputStream = System.in;

	int nextByte()
	{
		if(bufLength==-1)
			throw new InputMismatchException();
		if(bufCurrent>=bufLength)
		{
			bufCurrent = 0;
			try
			{bufLength = inputStream.read(bufferArray);}
			catch(IOException e)
			{ throw new InputMismatchException();}
			if(bufLength<=0)
				return -1;
		}
		return bufferArray[bufCurrent++];
	}

	boolean isSpaceChar(int x)
	{return (x<33 || x>126);}

	boolean isDigit(int x)
	{return (x>='0' && x<='9');}

	int nextNonSpace()
	{
		int x;
		while((x=nextByte())!=-1 && isSpaceChar(x));
		return x;
	}

	int ni()
	{
		int ans = 0;
		int sign = 1;
		int x = nextNonSpace();
		if(x=='-')
		{
			sign = -1;
			x = nextByte();
		}
		while(!isSpaceChar(x))
		{
			if(isDigit(x))
			{
				ans = ans*10 + x -'0';
				x = nextByte();
			}
			else
				throw new InputMismatchException();
		}
		return sign*ans;
	}

	long nl()
	{
		long ans = 0;
		long sign = 1;
		int x = nextNonSpace();
		if(x=='-')
		{
			sign = -1;
			x = nextByte();
		}
		while(!isSpaceChar(x))
		{
			if(isDigit(x))
			{
				ans = ans*10 + x -'0';
				x = nextByte();
			}
			else
				throw new InputMismatchException();
		}
		return sign*ans;
	}

	String ns()
	{
		StringBuilder sb = new StringBuilder();
		int x = nextNonSpace();
		while(!isSpaceChar(x))
		{
			sb.append((char)x);
			x = nextByte();
		}
		return sb.toString();
	}

	String nL()
	{
		StringBuilder sb = new StringBuilder();
		int x = nextNonSpace();
		while(x==32 || !isSpaceChar(x))
		{
			sb.append((char)x);
			x = nextByte();
		}
		return sb.toString();
	}

	char nc()
	{ return (char)nextNonSpace();}

	double nd()
	{ return (double)Double.parseDouble(ns()); }

	char[] ca()
	{ return ns().toCharArray();}

	char[] ca(int n)
	{
		char[] ans = new char[n];
		int p =0;
		int x = nextNonSpace();
		while(p<n)
		{
			ans[p++] = (char)x;
			x = nextByte();
		}
		return ans;
	}

	int[] ia(int n)
	{
		int[] ans = new int[n];
		for(int i=0;i<n;i++)
			ans[i]=ni();
		return ans;
	}

	long[] la(int n)
	{
		long[] ans = new long[n];
		for(int i=0;i<n;i++)
			ans[i] = nl();
		return ans;
	}

}
