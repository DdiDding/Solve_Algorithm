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

//2명씩 짝지어서 능력치 확인
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
	cout <<"총 능력치 : "<< total << endl << endl;
}

//최대 번호
//앞으로 몇명을 뽑아야 하는지
//vector 뽑은 사람 번호
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

	//보드 입력
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}

	//몇명씩 팀을 나누어야 하는지
	vector<int> team{ 0 };
	GetTeam(n, n / 2, team);
	return 0;
}

/*
총 N명, N은 짝수
N/2로 팀을 나누어 축구 시합.

팀의 능력치 모든 쌍의 Sij의 합

1.팀이 될 수 있는 모든 경우의수 찾기
2.그 팀마다 2명씩 모든 경우의 수로 능력치 합하기

https://velog.io/@skyepodium/%EB%B0%B1%EC%A4%80-14889-%EC%8A%A4%ED%83%80%ED%8A%B8%EC%99%80-%EB%A7%81%ED%81%AC
*/

