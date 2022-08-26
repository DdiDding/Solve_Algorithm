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