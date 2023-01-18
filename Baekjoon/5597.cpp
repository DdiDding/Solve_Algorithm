#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	bool ret[31] = { 0, };
	for (int i = 0; i < 28; ++i)
	{
		int temp; cin >> temp;
		ret[temp] = true;
	}

	for (int i = 1; i < 31; ++i)
	{
		if (ret[i] == false) cout << i << endl;
	}
	return 0;
}

/*
제출 안 한 학생 2명 출석 번호 구하기

*/