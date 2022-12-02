#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	string n; cin >> n;

	//1.Check One & Zero
	if (n == "0" || n == "1")
	{
		cout << n;
		return 0;
	}

	//2. Calculate n + n
	string ret;
	bool plus = false;
	while (0 < n.size())
	{
		int a = n.back() - '0';
		n.pop_back();

		a = plus ? a + a + 1 : a + a;
		plus = 9 < a ? true : false;

		ret += to_string(a % 10);
	}
	if (plus == true) ret += '1';

	//3. And then ret minus 2
	int k = 0;
	while (true)
	{
		if (k == 0) ret.at(k) -= 2;
		else ret.at(k) -= 1;

		//양수면
		if ('0' <= ret.at(k)) break;

		//음수일 때
		ret.at(k) += 10;
		++k;
	}

	//3. Print
	if(ret.back() != '0') cout << ret.back();
	for (int i = ret.size() - 2; -1 < i; --i)
	{
		cout << ret.at(i);
	}
	return 0;
}
