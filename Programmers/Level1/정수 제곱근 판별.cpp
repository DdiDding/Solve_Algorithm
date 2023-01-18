#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 50000000000000;

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll BS(ll n)
{
	ll s = 0, e = 10000000;
	ll m;

	while (s < e)
	{
		m = (s + e + 1) / 2;
		cout << "s : " << s << "//e : " << e << "//m : " << m << endl;
		if (m * m == n) return pow(m + 1, 2);
		if (n < (m * m)) e = m - 1;
		else s = m;
	}
	return -1;
}


ll solution(ll n) {

	ll answer = sqrt(n);
	if (answer * answer == n) return pow(answer + 1, 2);
	else return -1;
}
/* 
n에 대해 x의 제곱인가?
*/
