#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;

	int cnt = 0;
	int i = 665;
	string str;
	while (cnt != n)
	{
		++i;
		str = to_string(i);
		int c = 0;
		for (int j = 1; j < str.size(); ++j)
		{
			if (str[j] == '6' && str[j - 1] == '6') ++c;
			else c = 0;

			if (c == 2)
			{
				++cnt;
				break;
			}
		}
	}
	cout << i;
	return 0;
}

#include <stdio.h>
int N, r = 666;
int main() {

	scanf("%d", &N);

	for (int i = 0; i <= 3000; i++) 
	{
		int k = 1;
		//j는 10씩 곱합, k는 10씩 곱하고 1을 더함
		for (int j = 10; j <= 10000; j *= 10, k = k * 10 + 1) 
		{

			if (i % j != k * 6) 
			{
				N -= j / 10;

				if (N <= 0) 
				{
					r += (k / 10 * 3 + N);
					break;
				}
				break;
			}
		}

		if (N <= 0) break;
		r += 1000;
	}
	printf("%d", r);
}

/*
666은 종말을 나타내는 숫자
작은 종말의 숫자 666 그다음 1666 그 다음 2666 ...

9666

10666
11666
16661

5 * 10000 = 50000쌉가능이긴함
정수를 문자로 변환?

int i  = 666;
while(cnt != n)
{
	여기서 검사?

	++i;
}

*/