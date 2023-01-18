#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
#include <map>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;

	string S, T;
	int result;
	int S_one;
	int S_question;
	int T_one;
	for (int k = 1; k <= N; ++k)
	{
		result = 0;
		S_one = 0; S_question = 0;
		T_one = 0;

		//각 일의 개수 구하기
		cin >> S >> T;
		for (int i = 0; i < S.length(); ++i)
		{
			if (S[i] == '1') ++S_one;
			else if (S[i] == '?') ++S_question;
			if (T[i] == '1') ++T_one;
		}

		//변환이 가능한지 확인
		if (T_one < S_one)
		{
			cout << "Case " << k << ": -1\n";
			continue;
		}

		//각 인덱스를 모두 탐색
		for (int i = 0; i < S.length(); ++i)
		{
			//S가 1일때 다른 경우
			if (S[i] == '1' && T[i] == '0')
			{
				//뒤의 0일때 다른 경우의 인덱스와 변경한다.
				for (int j = i; j < S.length(); ++j)
				{
					if (S[j] == '0' && T[j] == '1')
					{
						S[i] = '0'; S[j] = '1'; ++result;
						break;
					}
				}
				//뒤에 0이고 다른 경우가 없으면 T의 1과 맞물리는 물음표와 변경한다.
				if (S[i] == '1')
				{
					for (int j = 0; j < S.length(); ++j)
					{
						if (S[j] == '?' && T[j] == '1')
						{
							S[i] = '0'; S[j] = '1'; result += 2; --S_question;
							break;
						}
					}
				}
			}
			//S가 0일때 다른 경우
			else if (S[i] == '0' && T[i] == '1') 
			{
				//뒤의 1일때 다른 경우의 인덱스와 변경한다.
				for (int j = i; j < S.length(); ++j)
				{
					if (S[j] == '1' && T[j] == '0')
					{
						S[i] = '1'; S[j] = '0'; ++result;
						break;
					}
				}
				//못 찾을 경우
				if (S[i] == '0')
				{
					S[i] = '1'; ++result;
				}
			}
		}

		cout << "Case " << k << ": "<<result + S_question<<"\n";
	}
	return 0;
}