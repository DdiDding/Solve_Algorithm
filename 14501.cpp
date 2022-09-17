#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii consult[30]{ };
int e;
int answer = 0;

//day : ���� ��¥ //pay : ���� ��¥�� �Ѿ�
void BT(int day, int pay)
{
	int cd = day + consult[day].first;
	int cp = pay + consult[day].second;

	//���糯¥�� ����� ��������� �̷������ �ִ°�?
	if (e + 1 < cd)
	{
		return;
	}

	//�̷������ �ִ밪 ����
	answer = max(answer, cp);

	//���� ����� ã�ƺ�
	for (int i = cd; i <= e; ++i)
	{
		BT(i, cp);
	}
	return;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	cin >> e;
	for (int i = 1; i <= e; ++i)
	{
		cin >> consult[i].first >> consult[i].second;
	}

	for (int i = 1; i <= e; ++i)
	{
		BT(i, 0);
	}

	cout << answer;
	return 0;
}

/*
N + 1�Ǵ³� ���
���� N�� ���� ���� ���

���Ⱓ Ti
���� �� �ִ� �ݾ�  Pi


//dp[i] = ��¥ i�� ���� ���� ���� �� �ִ� �ݾ�
dp[i] = dp[0] ~ dp[i - 1]

*/

#include <cstdio>
int n, arr[20][2], max;
void f(int day, int pay) {
	if (day == n + 1) {
		if (pay > max) max = pay;
		return;
	}
	if (day > n + 1) return;
	f(day + arr[day][0], pay + arr[day][1]);
	f(day + 1, pay);
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", &arr[i][0], &arr[i][1]);
	}
	f(1, 0);
	printf("%d", max);
	return 0;
}