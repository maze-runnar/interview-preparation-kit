#include <ios>
#include <iostream>

long long int dp[25][300005] = {};
long long int nm[300005] = {};

long long int cnt(int d, int s)
{
	if (d == -1 && s == 0)
		return 1;
	else if (d == -1)
		return 0;
	else if (dp[d][s] == -1)
	{
		dp[d][s] = 0;
		for (int i = 0; i <= 9 && (1 << d)*i <= s; i++)
			dp[d][s] += cnt(d-1, s-((1 << d)*i));
	}
	return dp[d][s];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	for (int i = 0; i < 25; i++)
		for (int j = 0; j < 300005; j++)
			dp[i][j] = -1;
	for (int i = 0; i < 300005; i++)
		nm[i] = cnt(24, i);
	for (int i = 1; i < 300005; i++)
		nm[i] += nm[i-1];
	int q, lo, hi, ans;
	long long int x;

	std::cin >> q;
	while (q--)
	{
		std::cin >> x;
		if (x == 1)
			std::cout << 0 << '\n';
		else
		{
			lo = 0;
			hi = 300004;
			while (lo <= hi)
			{
				int mid = (lo+hi)/2;
				if (nm[mid] >= x)
				{
					ans = mid;
					hi = mid-1;
				}
				else
					lo = mid+1;
			}

			long long int g = x-nm[ans-1];
			long long int s = ans;
			long long int val;
			int d;

			for (int i = -1; cnt(i, s) < g; i++)
				d = i;
			d++;

			while (d >= 0)
			{
				val = 0;
				for (int i = 0; i <= 9; i++)
				{
					if ((s - (1 << d)*i) >= 0)
						val += cnt(d-1, s-(1 << d)*i);
					if (val >= g)
					{
						std::cout << i;
						g -= val-cnt(d-1, s-(1 << d)*i);
						s -= (1 << d)*i;
						break;
					}
				}
				d--;
			}
			std::cout << '\n';
		}
	}
}