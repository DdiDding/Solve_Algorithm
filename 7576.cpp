#include <iostream>
#include <queue>

#define MAX 1001
#define X second
#define Y first
using namespace std;

pair<int, int> pre[4] = {{1,0},{0,1},{-1,0},{0,-1}};
int arr[MAX][MAX] = { 0, };
int zeroUnit = 0;

queue<pair<int, int>> q;
int BFS(const int & sizeY, const int & sizeX)
{
	//������ �丶�䰡 ������ �ٷ� 0 ��ȯ
	if (zeroUnit == 0) return 0;

	int cX, cY, nX, nY;
	int day = 0;
	while (q.empty() == false)
	{
		++day;

		//ť�� ���� ��ŭ(�Ϸ� ��ŭ)
		int tempSize = q.size();
		for (int i = 0; i < tempSize; ++i)
		{
			cX = q.front().X;
			cY = q.front().Y;
			q.pop();

			for (int j = 0; j < 4; ++j)
			{
				nX = cX + pre[j].X;
				nY = cY + pre[j].Y;

				//�������� ��������
				if (nY < 0 || sizeY <= nY || nX < 0 || sizeX <= nX) continue;

				//���� �丶�䳪 ��ֹ��̸� �н�
				if (arr[nY][nX] != 0) continue;

				//������ �丶��� ������ ť�� ����
				arr[nY][nX] = 1;
				q.push({ nY,nX });
				--zeroUnit;
			}
		}

		//������ �丶�� ��� �;�����
		if (zeroUnit == 0) return day;
	}
	return -1;
}

int main()
{
	//1. Get input value
	ios::sync_with_stdio(0), cin.tie(0);
	int x, y; cin >> x >> y;

	for (int i = 0; i < y; ++i)
	{
		for (int j = 0; j < x; ++j)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push({i,j});
			if (arr[i][j] == 0) ++zeroUnit;
		}
	}

	//2. Do BFS
	cout << BFS(y, x);
	return 0;
}