#include <iostream>

#define MAX 50
using namespace std;

int N;
int result = 0;
//b�� �ε����� �� ���� ��ġ�� �ǹ��Ѵ�.
//���� �� ���� ���������� ���Ѵ�. true�� �����ִ� ��
bool b1[MAX];
//���� �밢��'/'�� �Ǻ� ���� a + i
bool b2[MAX];
//���� �밢��'\'�� �Ǻ� ���� a - i + n //n�� �����ִ°��� ������ ������ �ʰ� �ϱ� ����
bool b3[MAX];

void Solve(const int  & a)
{
	if (a == N)
	{
		result++;
		return;
	}

	//i�� ��� ����ġ�� ���̷��� �ϴ����� ����
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