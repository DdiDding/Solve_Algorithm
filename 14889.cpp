#include <bits/stdc++.h>
using namespace std;

int board[21][21];
int result = 2100;


void Print(vector<int> & team)
{
	for (auto d : team)
	{
		cout << d << " ";
	}
	cout << endl;
}

//2�� ¦��� �ɷ�ġ Ȯ��
void CalStat(vector<int> & team)
{
	int total = 0;
	for (int i = 1; i < team.size(); ++i)
	{
		for (int j = i + 1; j < team.size(); ++j)
		{
			total += board[team[i]][team[j]] + board[team[j]][team[i]];
		}
	}
	cout <<"�� �ɷ�ġ : "<< total << endl << endl;
}

//�ִ� ��ȣ
//������ ����� �̾ƾ� �ϴ���
//vector ���� ��� ��ȣ
void GetTeam(int lim, int toPick, vector<int> & team)
{
	if (toPick == 0)
	{
		CalStat(team);
		return;
	}

	for (int i = team.back() + 1; i <= lim; ++i)
	{
		team.push_back(i);
		GetTeam(lim, toPick - 1, team);
		team.pop_back();
	}
}


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;

	//���� �Է�
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}

	//��� ���� ������� �ϴ���
	vector<int> team{ 0 };
	GetTeam(n, n / 2, team);
	return 0;
}

/*
�� N��, N�� ¦��
N/2�� ���� ������ �౸ ����.

���� �ɷ�ġ ��� ���� Sij�� ��

1.���� �� �� �ִ� ��� ����Ǽ� ã��
2.�� ������ 2�� ��� ����� ���� �ɷ�ġ ���ϱ�

https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-14889-%EC%8A%A4%ED%83%80%ED%8A%B8%EC%99%80-%EB%A7%81%ED%81%AC
*/

