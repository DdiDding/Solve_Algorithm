#include <bits/stdc++.h>
using namespace std;

/*
���� �� : 9 * 9
ä��� �ִ°� ä��� 
�𸣴°� ���� ��ͷ� ?
*/

int m[9][9];

typedef pair<int, int> pii;
vector<pii> zero;
#define X first
#define Y second

int BT(int n)
{

	//ä��� �ִ°� ä��,
	vector<int>a;
	
	return 0;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			cin >> m[i][j];
			if (m[i][j] == 0) zero.push_back({ j,i });
		}
	}



	return 0;
}