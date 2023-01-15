#include <bits/stdc++.h>
using namespace std;
vector<int> p;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		//1. Get input value
		int n; cin >> n;
		int s; cin >> s;
		p.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> p[i];
		}
		
		//2. 
	}

	return 0;
}

/*
손실압축

1000이하의 자연수들로 구성된 수열 최대 S종류의 값만을 사용하도록 양자화 하고싶다.
= 그럼 사용하는게 S이하의 종류도 된다는 말?
오차 제곱의 합

1. 완전탐색
	1 ~ 1000까지 10개를 뽑는 경우 O(1억6천) + 3개중 가장 오차작은거 찾으면 되니까 O(n) (n<100임
불가능

2. DP
	넘 많은데?

정렬후
각 묶음으로 나눈다.
solve(묶음) = 묶음의 오차 제곱의 최소 합


	
*/