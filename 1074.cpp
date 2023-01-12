#include <iostream>
using namespace std;

int pre[16] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384 };
int GetQuad(const bool & bOverY, const bool & bOverX)
{
	if (bOverY == true)
	{
		if (bOverX == true) return 3;
		else return 2;
	}
	else
	{
		if (bOverX == true) return 1;
		else return 0;
	}
}

//2^n ũ���� [y][x]�� �ִ� ��ȣ�� ����Ѵ�.
int solve(int y, int x, int n)
{
	//���� ���
	if (n == 0) return 0;

	int mid = pre[n - 1];
	int quad = GetQuad(mid <= y, mid <= x);
	int mini = pre[n - 1] * pre[n - 1];

	return quad * mini + solve(y % mid, x % mid, n - 1);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, y, x; cin >> n >> y >> x;
	
	cout << solve(y, x, n);

	return 0;
}

/*
//���ۼ���, ����
//
int solve(int y, int x, int len)

1.find�� 0�̰ų� ���̰� 1�϶� return

2. ã������ ��ǥ�� 4�и��� ��� ������ �ִ��� Ȯ��
�׷� �ּҰ��� ������ ��ͷ� ����.
(�ּҰ� : (���� * ���� / 4) * ��и�)
n = 2 / 4
n = 3 / 16
*/

//���� ���� Ǯ��
/*
#include <iostream>
using namespace std;
typedef long long int ll;

int pre[16] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768 };

//0 : ������� , 1 : �������, 2 : �����ϴ�, 3 : �����ϴ�
int GetQuadrant(const bool & X, const bool & Y)
{
	if (X == true)
	{
		if (Y == true) return 3;
		else return 1;
	}
	else
	{
		if (Y == true) return 2;
		else return 0;
	}
}

ll Func(ll N, ll X, ll Y)
{
	if (N == 0) return 0;

	//��и� �˾Ƴ���
	ll mid = pre[N] / 2;
	ll q = GetQuadrant(mid <= X, mid <= Y);

	//�ڱ�簢�������� �ִ밪
	ll std = pre[N-1] * pre[N - 1];
	ll max = std * q;

	ll result = Func(N - 1, X % mid, Y % mid);
	//�� ���� ��ȯ
	return max + result;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	ll N, Y, X; cin >> N >> Y >> X;

	cout << Func(N, X, Y);

	return 0;
}
*/