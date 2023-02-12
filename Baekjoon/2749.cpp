#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
#define MOD 1'000'000
#define MAX 1'000'000'000'000'000'000

lli dp[5] = { 0,1,1,2,3 };

int solve(int n)
{
	if (n < 5) return dp[n];

	lli div = n / 2;
	lli a = solve(div) % MOD; a = a * a % MOD;
	lli b = 0;
	lli c = 0;
	lli d = 0;
	//È¦¼ö¸é
	if (n & 1)
	{
		b = solve(div + 1) % MOD; b = b * b % MOD;
	}
	//Â¦¼ö¸é
	else
	{
		b = solve(div) % MOD;
		c = b * solve(div - 1) % MOD;
		d = c * 2 % MOD;
	}

	lli e = (a + d) % MOD;
	return e;
}
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	lli n; cin >> n;
/*
	for (int i = 6; i < 1000; ++i)
	{
		cout << i<<"¹øÂ° : "<<solve(i) << endl;
	}*/

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
