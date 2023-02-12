#include <bits/stdc++.h>
using namespace std;
#define MOD 1'000'000
#define MAX 1'000'000'000'000'000'000
//1000000000000000000
map<long long int, long long int> dp;

long long int solve(long long int n)
{
	//±âÀú»ç·Ê & ¸Þ¸ð¸®Á¦ÀÌ¼Ç
	if (dp.find(n) != dp.end())	return dp[n];

	long long int div = n / 2;
	long long int a = solve(div) % MOD; a = a * a % MOD;
	long long int b = 0;

	//È¦¼ö¸é
	if (n & 1)
	{
		b = solve(div + 1) % MOD; b = b * b % MOD;
	}
	//Â¦¼ö¸é
	else
	{
		b = ((solve(div) % MOD) * (solve(div - 1) % MOD) * 2 % MOD);
	}

	return dp[n] = (a + b) % MOD;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	long long int n; cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;

	cout << solve(n);
	return 0;
}

//
//n = 10 / k = 5
//0	1	2	3	4	5	6	7	8	9	10	11	12	13	14	
//0	1	1	2	3	5	8	13	21	34	55	89	144	233	377
//

//9¸é 4 * 4 + 5 * 5
//È¦¼ö´Â (div * div) + (div + 1) * (div + 1)

//10ÀÌ¸é 5 * 5  + (5 * 4 * 2)
//Â¦¼ö´Â (div) * (div) + (div *  div - 1) * 2

