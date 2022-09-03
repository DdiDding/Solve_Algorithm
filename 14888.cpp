#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli num[11];
vector<lli> cal;

lli Cal( )
{
	lli temp = num[0];
	int i = 1;
	for (const auto & d : cal)
	{
		
		if (d == 1) temp += num[i]; //add
		if (d == 2) temp -= num[i]; //min
		if (d == 3) temp *= num[i]; //mul
		if (d == 4) temp /= num[i]; //div
		++i;
	}
	return temp;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, t; cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	
	for (int i = 1; i <= 4; ++i)
	{
		cin >> t;
		while (t--)
		{
			cal.push_back(i);
		}
	}

	lli Max = LLONG_MIN, Min = LLONG_MAX;
	do
	{
		lli temp = Cal();
		Max = max(Max, temp);
		Min = min(Min, temp);
	} while (next_permutation(cal.begin(), cal.end()) == true);

	cout << Max << '\n' << Min;

	return 0;
}
/*
���� A1 ~ An �� �ִ�. ������ �ٲ� �� ����.

������ n - 1���� �־�����. �� ���̿� ���������� ��
����, ����, ����, ������ �� �־��� ������ ����
������ �տ������� �����ؾ���

�ִ�� �ּ�

����, ����, ����, ������
������� long int

�׳� �� �غ�??
2 <= n <= 11
�����ڰ� �ִ� 10��

���� arr = a
������ arr = b

������ a[i]�� b[i] �� b[i+1]�� �����Ѵ�.



*/