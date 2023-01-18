#include <iostream>

#define MAX 22
using namespace std;

int N, S;
int arr[MAX];

int result = 0;
//length는 현재 자신이 들어갈 인덱스임 , 첫번째숫자면 0임
void Solve(const int & total, const int & length, int level)
{
	if (1 <= level && total == S)
	{
		++result;
	}

	for (int i = length + 1; i < N; ++i)
	{
		Solve(total + arr[i], i, level + 1);
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N >> S;

	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		if (arr[i] == S) ++result;
	}
	Solve(0, -1, -1);
	cout << result;
	return 0;
}