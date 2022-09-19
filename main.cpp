#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 50000000000000;

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


ll solution(ll n) {

	ll answer = sqrt(n);
	if (answer * answer == n) return pow(answer + 1, 2);
	else return -1;
}
/*
n에 대해 x의 제곱인가?
*/

int BS(int n)
{
	ll s = 0, e = 5000000;
	ll m;

	while (s < e)
	{
		m = (s + e + 1) / 2;
		cout << "s : " << s << "//e : " << e << "//m : " << m << endl;
		if (m * m == n) return m + 1;
		if (n < (m * m)) e = m - 1;
		else s = m;
	}
	return -1;
}

int main()
{
	cout << "정답" <<BS(1);
	return 0;
}
