#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string str; cin >> str;

	int result = 0;
	for (const auto & d : str)
	{
		if (d <= 'C') result += 3;
		else if (d <= 'F') result += 4;
		else if (d <= 'I') result += 5;
		else if (d <= 'L') result += 6;
		else if (d <= 'O') result += 7;
		else if (d <= 'S') result += 8;
		else if (d <= 'V') result += 9;
		else if (d <= 'Z') result += 10;
	}

	cout << result;
	return 0;
}
/*
1은 2초 2는 3초

영어 A부터 0 B는 1

a b c d e f g h i j k l m n o p q r s t u v w x y z
2 2	2 3 3 3 4 4 4 5 5 5 6 6 6 7 7 7 7 8 8 8 9 9 9 9
*/