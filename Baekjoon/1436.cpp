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
		//j�� 10�� ����, k�� 10�� ���ϰ� 1�� ����
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
666�� ������ ��Ÿ���� ����
���� ������ ���� 666 �״��� 1666 �� ���� 2666 ...

9666

10666
11666
16661

5 * 10000 = 50000�԰����̱���
������ ���ڷ� ��ȯ?

int i  = 666;
while(cnt != n)
{
	���⼭ �˻�?

	++i;
}

*/