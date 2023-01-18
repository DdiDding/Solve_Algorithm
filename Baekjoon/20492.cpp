#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n; cin >> n;
	cout << n / 100 * 78 << " "<< n - ((n / 100 * 20) / 100 * 22);

	return 0;
}

/*
최종 상금 : 상금 - 제세공과금

제세공과금 : 전체 금액의 22%

상금의 80%가 경비라면
20%의 22%를 제세공과금으로 인정

*/