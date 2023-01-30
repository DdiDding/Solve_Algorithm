//https://algospot.com/judge/problem/read/PI
#include <bits/stdc++.h>
using namespace std;
static const int MAX = 50'000;

//dp[n] = str[n]에서 시작하는 최소의 난이도
int dp[10'005];
string str;

int GetHard(int s, int len)
{
	//난이도 1 검사
	string std = str.substr(s, len);
	if (std == string(std.size(), std[0])) return 1; 

	//난이도 2 검사
	bool bIsArter = true;
	int temp = std[1] - std[0];
	for (int i = 0; i < std.size() - 1 && bIsArter; ++i)
	{
		if (std[i] + temp != std[i + 1]) bIsArter = false; 
	}
	if (bIsArter && temp * temp == 1) return 2;

	//난이도 4 검사
	bool bIsFour = true;
	for (int i = 2; i < std.size() && bIsFour; ++i)
	{
		if (std[i] != std[i % 2]) bIsFour = false;
	}
	if (bIsFour == true) return 4;

	//난이도 5 검사
	if (bIsArter == true) return 5;

	//나머지 난이도
	return 10;
}

//수열 S의 최소 난이도를 반환한다.
int solve(int n)//n은 인덱스
{
	//1. 기저사례 : a.n으로 시작하는 부분수열의 길이가 < 3 일때 50'000을 반환
	//				b.n으로 시작하는 부분수열의 길이가 3 ~5일 때 난이도 계산하여 반환
	if (str.end() - (str.begin() + n) < 3) return MAX;
	if (str.end() - (str.begin() + n) < 6) return GetHard(n, str.size());

	//메모리제이션
	if (dp[n] != MAX) return dp[n];

	int & ret = dp[n] = MAX;
	for (int i = 3; i <= 5; ++i) //i는 길이
	{
		if (3 <= str.end() - (str.begin() + i))
		{
			ret = min(ret, GetHard(n, i) + solve(n + i));
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
		cin >> str;
		fill_n(dp, sizeof(dp) / sizeof(int), MAX);
		cout << solve(0) << '\n';
	}

	return 0;
}

/*
수열을 3 ~ 5자리씩 끊을 수 있다.
부분 수열의 최소 난이도 합을 구해라

수열

부분 수열1, 부분 수열2, ..., 부분 수열n

부부 수열의 최소 합

무식하게? 답의 하한을 써보며 구한다.
길이가 7인 수열은 2가지로 나눌수있다.
최대 길이가 10000이므로 7인 수열은 1428개가 들어가며,
이때 최소 나눌수 있는 수는 2^1428이므로 불가능하다.

DP?
어차피 처음은 3, 4, 5로 나뉜다.
그럼
3 + 나머지 수열
4 + 나머지 수열
5 + 나머지 수열, 인데
나머지 수열의 최적해를 구할때 앞을 어떻게 쪼갰는지 상관없으며
나머지 수열의 최적해로 인해 앞과 합한 수열의 최적해가 나오기 때문에
최적 부분 구조를 가지고 있다.

//n으로 시작하는 최소 난이도
solve(int n) = 쪼갠 앞부분의 난이도 + min(solve(n + 3,4,5))
//테이블화
dp[n] = 쪼갠 앞부분의 난이도 + min(solve(n + 3,4,5))

solve(수열)
{
				//a에서 -1을 반환하면 최소 값을 찾는 로직에 방해.
				//적당히 큰값으로 반환해야함 10000글자에서 나올수 있는 최대 난이도
				//모두 3으로나누었을 때 난이도 10 = 33330, 50000정도하면 괜찮음
	1. 기저사례 : a. n으로 시작하는 부분수열의 길이가 < 3 일때 50'000을 반환
				 b. n으로 시작하는 부분수열의 길이가 3 ~ 5일 때 난이도 계산하여 반환


	2. 앞부분을 3,4,5로 쪼갠다 = S.
	ret = 50'000
	for (int i = 3; i <= 5; ++i)
	{
		2-1. S의 난이도를 구한다. 2-2. solve(쪼갠 나머지 수열)
		ret = min(ret, GetHard(n , n + i) + solve(n + i))
		2-3. 2-1과 2-2를 더하고 계속 최소값을 찾는다.
	}
	3. return ret
}

*/

//배열의 인덱스 참조, std와 비교해야할걸 str로 쓰는 철자 문제 ㅅㅂ;;

//완전탐색 풀이
/*
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

*/