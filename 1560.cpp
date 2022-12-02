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
	bool minus = false;

	int temp = ret.at(0) - '0' - 2;

	if (temp < 0)
	{
		minus = true;
		temp += 10;
	}
	ret.at(0) = temp + '0';
	
	int k = 1;
	while (minus == true)
	{
		temp = ret.at(k) - '0' - 1;

		if (0 <= temp)
		{
			ret.at(k) = temp + '0';
			break;
		}
		//음수일 때
		temp += 10;
		ret.at(k) = temp + '0';

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
/*

70자리의 수를 어떻게 계산하는가?
ULL로 7자리씩 끊어서?

111,999
222,001

333 / 1000


4 + 2
* * * *
. . . .
. . . .
. * * .

5 + 3
* * * * *
# # # # #
# # # # # 
# # . # # 
# * * * #

6 + 4
* * * * * *
# # # # # #
# # # # # #
# # # # # #
# # . . # #
# . . . . #

7 + 5
* * * * * * *
# # # # # # #
# # # # # # #
# # # # # # #
# # # . # # #
# # . . . # #
# . . . . . #

*/