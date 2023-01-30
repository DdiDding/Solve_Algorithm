//https://algospot.com/judge/problem/read/PI
#include <bits/stdc++.h>
using namespace std;
static const int MAX = 50'000;

//dp[n] = str[n]���� �����ϴ� �ּ��� ���̵�
int dp[10'005];
string str;

int GetHard(int s, int len)
{
	//���̵� 1 �˻�
	string std = str.substr(s, len);
	if (std == string(std.size(), std[0])) return 1; 

	//���̵� 2 �˻�
	bool bIsArter = true;
	int temp = std[1] - std[0];
	for (int i = 0; i < std.size() - 1 && bIsArter; ++i)
	{
		if (std[i] + temp != std[i + 1]) bIsArter = false; 
	}
	if (bIsArter && temp * temp == 1) return 2;

	//���̵� 4 �˻�
	bool bIsFour = true;
	for (int i = 2; i < std.size() && bIsFour; ++i)
	{
		if (std[i] != std[i % 2]) bIsFour = false;
	}
	if (bIsFour == true) return 4;

	//���̵� 5 �˻�
	if (bIsArter == true) return 5;

	//������ ���̵�
	return 10;
}

//���� S�� �ּ� ���̵��� ��ȯ�Ѵ�.
int solve(int n)//n�� �ε���
{
	//1. ������� : a.n���� �����ϴ� �κм����� ���̰� < 3 �϶� 50'000�� ��ȯ
	//				b.n���� �����ϴ� �κм����� ���̰� 3 ~5�� �� ���̵� ����Ͽ� ��ȯ
	if (str.end() - (str.begin() + n) < 3) return MAX;
	if (str.end() - (str.begin() + n) < 6) return GetHard(n, str.size());

	//�޸����̼�
	if (dp[n] != MAX) return dp[n];

	int & ret = dp[n] = MAX;
	for (int i = 3; i <= 5; ++i) //i�� ����
	{
		if (3 <= str.end() - (str.begin() + i))
		{
			ret = min(ret, GetHard(n, i) + solve(n + i));
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	string s; s.reserve(10'005);
	while(t--)
	{
		cin >> str;
		fill_n(dp, sizeof(dp) / sizeof(int), MAX);
		cout << solve(0) << '\n';
	}

	return 0;
}

/*
������ 3 ~ 5�ڸ��� ���� �� �ִ�.
�κ� ������ �ּ� ���̵� ���� ���ض�

����

�κ� ����1, �κ� ����2, ..., �κ� ����n

�κ� ������ �ּ� ��

�����ϰ�? ���� ������ �Ẹ�� ���Ѵ�.
���̰� 7�� ������ 2������ �������ִ�.
�ִ� ���̰� 10000�̹Ƿ� 7�� ������ 1428���� ����,
�̶� �ּ� ������ �ִ� ���� 2^1428�̹Ƿ� �Ұ����ϴ�.

DP?
������ ó���� 3, 4, 5�� ������.
�׷�
3 + ������ ����
4 + ������ ����
5 + ������ ����, �ε�
������ ������ �����ظ� ���Ҷ� ���� ��� �ɰ����� ���������
������ ������ �����ط� ���� �հ� ���� ������ �����ذ� ������ ������
���� �κ� ������ ������ �ִ�.

//n���� �����ϴ� �ּ� ���̵�
solve(int n) = �ɰ� �պκ��� ���̵� + min(solve(n + 3,4,5))
//���̺�ȭ
dp[n] = �ɰ� �պκ��� ���̵� + min(solve(n + 3,4,5))

solve(����)
{
				//a���� -1�� ��ȯ�ϸ� �ּ� ���� ã�� ������ ����.
				//������ ū������ ��ȯ�ؾ��� 10000���ڿ��� ���ü� �ִ� �ִ� ���̵�
				//��� 3���γ������� �� ���̵� 10 = 33330, 50000�����ϸ� ������
	1. ������� : a. n���� �����ϴ� �κм����� ���̰� < 3 �϶� 50'000�� ��ȯ
				 b. n���� �����ϴ� �κм����� ���̰� 3 ~ 5�� �� ���̵� ����Ͽ� ��ȯ


	2. �պκ��� 3,4,5�� �ɰ��� = S.
	ret = 50'000
	for (int i = 3; i <= 5; ++i)
	{
		2-1. S�� ���̵��� ���Ѵ�. 2-2. solve(�ɰ� ������ ����)
		ret = min(ret, GetHard(n , n + i) + solve(n + i))
		2-3. 2-1�� 2-2�� ���ϰ� ��� �ּҰ��� ã�´�.
	}
	3. return ret
}

*/

//�迭�� �ε��� ����, std�� ���ؾ��Ұ� str�� ���� ö�� ���� ����;;

//����Ž�� Ǯ��
/*
#include <bits/stdc++.h>
using namespace std;
static const int MAX = 987654321;

int GetHard(const string& s)
{
	//���̵� 1 �˻�
	char std = s[0];
	bool isPass = true;
	for (int i = 1; i < s.size() && isPass; ++i)
	{
		if (std != s[i]) isPass = false;
	}
	if (isPass == true) return 1;

	//���̵� 2 �˻�
	isPass = true;
	int sign = s[0] < s[1] ? 1 : -1;
	for (int i = 0; i < s.size() - 1 && isPass; ++i)
	{
		if (s[i] + sign != s[i + 1]) isPass = false;
	}
	if (isPass == true) return 2;

	//���̵� 4 �˻�
	isPass = true;
	bool bSwitch = false;
	char stdarr[2]; stdarr[0] = s[0]; stdarr[1] = s[1];
	for (int i = 2; i < s.size() && isPass; ++i)
	{
		if (stdarr[bSwitch] != s[i]) isPass = false;
		bSwitch = !bSwitch;
	}
	if (isPass == true) return 4;

	//���̵� 5 �˻�
	isPass = true;
	int diff = s[1] - s[0];
	for (int i = 1; i < s.size() - 1 && isPass; ++i)
	{
		if (s[i] + diff != s[i + 1]) isPass = false;
	}
	if (isPass == true) return 5;

	//������ ���̵��� 10
	return 10;
}

//���� S�� �ּ� ���̵��� ��ȯ�Ѵ�.
int solve(string s)
{
	//������� : ������ �ڸ��� 2������ ��, 5������ ��
	if (s.size() <= 2)  return MAX;
	if (s.size() <= 5)  return GetHard(s);

	//�ƴ϶�� 3, 4, 5�� �ɰ���.
	int front, back, ret = MAX;
	for (int i = 3; i <= 5; ++i)
	{
		if (3 <= s.size() - i)
		{
			front = solve(s.substr(0, i));
			back = solve(s.substr(i));
			//cout << s.substr(0, i) << "(" << front << ")�� " << s.substr(i) << "(" << back << ")�� ���� ��� " << front + back << "�� ���Խ��ϴ�\n";
			ret = min(ret, front + back);
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	string s; s.reserve(10'005);
	while(t--)
	{
		string str; cin >> str;
		cout << "����" << solve(str) << '\n';
	}

	return 0;
}

*/