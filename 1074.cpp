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

//2^n 크기의 [y][x]에 있는 번호를 출력한다.
int solve(int y, int x, int n)
{
	//기저 사례
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
//시작숫자, 길이
//
int solve(int y, int x, int len)

1.find가 0이거나 길이가 1일때 return

2. 찾으려는 좌표가 4분면중 어느 지점에 있는지 확인
그럼 최소값을 가지고 재귀로 들어간다.
(최소값 : (길이 * 길이 / 4) * 사분면)
n = 2 / 4
n = 3 / 16
*/

//옛날 나의 풀이
/*
#include <iostream>
using namespace std;
typedef long long int ll;

int pre[16] = { 1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768 };

//0 : 좌측상단 , 1 : 우측상단, 2 : 좌측하단, 3 : 우측하단
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

	//사분면 알아내기
	ll mid = pre[N] / 2;
	ll q = GetQuadrant(mid <= X, mid <= Y);

	//자기사각형에서의 최대값
	ll std = pre[N-1] * pre[N - 1];
	ll max = std * q;

	ll result = Func(N - 1, X % mid, Y % mid);
	//값 합쳐 반환
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