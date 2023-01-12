#include <bits/stdc++.h>
using namespace std;
static const int MAX = 987654321;

int GetHard(const string& s)
{
	//난이도 1 검사
	char std = s[0];
	bool isPass = true;
	for (int i = 1; i < s.size() && isPass; ++i)
	{
		if (std != s[i]) isPass = false;
	}
	if (isPass == true) return 1;

	//난이도 2 검사
	isPass = true;
	int sign = s[0] < s[1] ? 1 : -1;
	for (int i = 0; i < s.size() - 1 && isPass; ++i)
	{
		if (s[i] + sign != s[i + 1]) isPass = false;
	}
	if (isPass == true) return 2;

	//난이도 4 검사
	isPass = true;
	bool bSwitch = false;
	char stdarr[2]; stdarr[0] = s[0]; stdarr[1] = s[1];
	for (int i = 2; i < s.size() && isPass; ++i)
	{
		if (stdarr[bSwitch] != s[i]) isPass = false;
		bSwitch = !bSwitch;
	}
	if (isPass == true) return 4;

	//난이도 5 검사
	isPass = true;
	int diff = s[1] - s[0];
	for (int i = 1; i < s.size() - 1 && isPass; ++i)
	{
		if (s[i] + diff != s[i + 1]) isPass = false;
	}
	if (isPass == true) return 5;

	//나머지 난이도는 10
	return 10;
}

//수열 S의 최소 난이도를 반환한다.
int solve(string s)
{
	//기저사례 : 조각의 자리가 2이하일 때, 5이하일 때
	if (s.size() <= 2)  return MAX;
	if (s.size() <= 5)  return GetHard(s);

	//아니라면 3, 4, 5씩 쪼갠다.
	int front, back, ret = MAX;
	for (int i = 3; i <= 5; ++i)
	{
		if (3 <= s.size() - i)
		{
			front = solve(s.substr(0, i));
			back = solve(s.substr(i));
			//cout << s.substr(0, i) << "(" << front << ")와 " << s.substr(i) << "(" << back << ")을 합쳐 결과 " << front + back << "이 나왔습니다\n";
			ret = min(ret, front + back);
		}
	}
	
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	string s; s.reserve(10'005);
	while(t--)
	{
		string str; cin >> str;
		cout << "정답" << solve(str) << '\n';
	}

	return 0;
}

/*
수열을 3 ~ 5자리씩 끊을 수 있다.
부분 수열의 난이도 합을 구해라

https://algospot.com/judge/problem/read/PI


*/