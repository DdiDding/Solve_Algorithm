#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;

lli num[11];
vector<lli> cal;

lli Cal( )
{
	lli temp = num[0];
	int i = 1;
	for (const auto & d : cal)
	{
		
		if (d == 1) temp += num[i]; //add
		if (d == 2) temp -= num[i]; //min
		if (d == 3) temp *= num[i]; //mul
		if (d == 4) temp /= num[i]; //div
		++i;
	}
	return temp;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n, t; cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}
	
	for (int i = 1; i <= 4; ++i)
	{
		cin >> t;
		while (t--)
		{
			cal.push_back(i);
		}
	}

	lli Max = LLONG_MIN, Min = LLONG_MAX;
	do
	{
		lli temp = Cal();
		Max = max(Max, temp);
		Min = min(Min, temp);
	} while (next_permutation(cal.begin(), cal.end()) == true);

	cout << Max << '\n' << Min;

	return 0;
}
/*
수열 A1 ~ An 이 있다. 순서는 바꿀 수 없다.

연산자 n - 1개가 주어진다. 각 사이에 끼워넣으란 뜻
덧셈, 뺄셈, 곱셈, 나눗셈 각 주어진 개수가 있음
무조건 앞에서부터 진행해야함

최대와 최소

덧셈, 뺄샘, 곱셈, 나눗셈
사이즈는 long int

그냥 다 해봐??
2 <= n <= 11
연산자가 최대 10개

수열 arr = a
연산자 arr = b

연산자 a[i]는 b[i] 와 b[i+1]을 연산한다.



*/