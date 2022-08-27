#include <iostream>

#define MAX 50
using namespace std;

int N;
int result = 0;
//b는 인덱스는 각 열의 위치를 의미한다.
//값은 이 열에 놓였는지를 뜻한다. true면 놓여있는 것
bool b1[MAX];
//값은 대각선'/'의 판별 식은 a + i
bool b2[MAX];
//값은 대각선'\'의 판별 식은 a - i + n //n을 더해주는것은 음수가 나오지 않게 하기 위해
bool b3[MAX];

void Solve(const int  & a)
{
	if (a == N)
	{
		result++;
		return;
	}

	//i가 어느 열위치에 놓이려고 하는지를 뜻함
	for (int i = 0; i < N; ++i)
	{
		if (b1[i] == true || b2[a + i] == true || b3[a - i + N] == true) continue;

		b1[i] = true;
		b2[a + i] = true;
		b3[a - i + N] = true;
		Solve(a + 1);
		b1[i] = false;
		b2[a + i] = false;
		b3[a - i + N] = false;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N;
	Solve(0);
	cout << result;
	return 0;
}