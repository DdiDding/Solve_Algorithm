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

		//�� ���� ���� ���ϱ�
		cin >> S >> T;
		for (int i = 0; i < S.length(); ++i)
		{
			if (S[i] == '1') ++S_one;
			else if (S[i] == '?') ++S_question;
			if (T[i] == '1') ++T_one;
		}

		//��ȯ�� �������� Ȯ��
		if (T_one < S_one)
		{
			cout << "Case " << k << ": -1\n";
			continue;
		}

		//�� �ε����� ��� Ž��
		for (int i = 0; i < S.length(); ++i)
		{
			//S�� 1�϶� �ٸ� ���
			if (S[i] == '1' && T[i] == '0')
			{
				//���� 0�϶� �ٸ� ����� �ε����� �����Ѵ�.
				for (int j = i; j < S.length(); ++j)
				{
					if (S[j] == '0' && T[j] == '1')
					{
						S[i] = '0'; S[j] = '1'; ++result;
						break;
					}
				}
				//�ڿ� 0�̰� �ٸ� ��찡 ������ T�� 1�� �¹����� ����ǥ�� �����Ѵ�.
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
			//S�� 0�϶� �ٸ� ���
			else if (S[i] == '0' && T[i] == '1') 
			{
				//���� 1�϶� �ٸ� ����� �ε����� �����Ѵ�.
				for (int j = i; j < S.length(); ++j)
				{
					if (S[j] == '1' && T[j] == '0')
					{
						S[i] = '1'; S[j] = '0'; ++result;
						break;
					}
				}
				//�� ã�� ���
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