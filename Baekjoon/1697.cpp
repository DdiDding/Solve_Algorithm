#include <iostream>
#include <queue>
using namespace std;
#define MAX 100'000
bool arr[100'001] = { 0, };
int N,K;

queue<pair<int,int>> q;
int BFS(const int & start)
{
	if (N == K) return 0;

	q.push({ start, 0});

	int A, B, C;
	while (q.empty() == false)
	{
		int data = q.front().first;
		int time = q.front().second + 1;

		A = data - 1;	B = data + 1;	C = data * 2;

		if (0 < A && arr[A] == false)
		{
			q.push({ A, time });
			arr[A] = true;
		}
		if (B < MAX && arr[B] == false)
		{
			q.push({B, time });
			arr[B] = true;
		}
		if (C <= MAX && arr[C] == false)
		{
			q.push({C, time });
			arr[C] = true;
		}
	
		if (A == K || B == K || C == K) return time;
		q.pop();
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> K;
	cout << BFS(N);

	return 0;
}