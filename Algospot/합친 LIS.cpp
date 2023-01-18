#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, m;
int A[101], B[101];

//JLIS의 길이를 출력한다.
int solve(int a, int b)
{
	int ret = 0;
	ll aa = (a == -1 ? -1 : A[a]);
	ll bb = (b == -1 ? -1 : B[b]);
	ll maxValue = max(aa, bb);

	for (int nextA = a + 1; nextA < n; nextA++)
	{
		if (maxValue < A[nextA])
		{
			ret = max(ret, solve(nextA, b) + 1);
		}
	}
	for (int nextB = b + 1; nextB < m; nextB++)
	{
		if (maxValue < B[nextB])
		{
			ret = max(ret, solve(a, nextB) + 1);
		}
	}
	return ret;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int c; cin >> c;
	for (int k = 0; k < c; k++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> A[i];
		for (int i = 0; i < m; i++) cin >> B[i];

		solve(0, 0);
	}

	return 0;
}

/*
두개의 증가 부분 수열을 합치고 중복없이 오름차순 정렬한게 합친 증가 부분 수열,
=합칠때는 자동으로 정렬되고 중복값을 못받는 컨테이너 Set 이용


LIS를 합친다고 가장 길지는 않다!
모든 증가 부분 수열을 더해봐야함! - 진짜?

탐욕적으로 한번 생각해볼수 있지 않을까?

각 원소로 끝나는 최대 증가 부분 수열만 선택해도 괜찮을거 같은데?

"슈도 코드"
1. for(A[0] ~ A[n]으로 끝나는 최대 증가 부분 수열 aa)
{
	1-1.for(B[0] ~ B[n] 으로 끝나는 증가 부분 수열 bb)
		{
			1-1-1. aa + bb 길이 구함
		}
}


*/