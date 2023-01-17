#include <bits/stdc++.h>
using namespace std;

int solve(int n)
{
	//���� ���
	if (n == 0) return 1;

	int t1 = 0, t2 = 0;
	t1 = solve(n - 1);
	if (2 <= n) t2 = solve(n - 2);
	return t1 + t2;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout << solve(n) << '\n';
	}

	return 0;
}

/*
2 * n ũ���� �簢�� �� 2 * 1ũ���� �簢������ ä��� ����� ��

1. ���� Ž��?

//2 * n���� Ÿ�Ͽ��� ���� �� �ִ� ��� ����� ���� ��ȯ
solve(n)
{
	n�� 0�̸� return

	1.���η� �Ѱ��� �д�. + solve(n - 1)
	2.���η� �ΰ��� �д�. + solve(n - 2)

	return 1 + 2
}

f(1) = 1
f(2) = 2
f(3) = 3
f(4) = 5
f(5) = 8
||||
||��
|��|
��||
����


*/