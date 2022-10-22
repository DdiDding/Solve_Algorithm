#include <bits/stdc++.h>

using namespace std;

string solution(string answer, int n)
{
	for (auto & data : answer)
	{
		char stdChar;

		//If character is white space
		if (data <= ' ') continue;
			
		//If character is upper or lower
		stdChar = data <= 'Z' ? 'A' : 'a';

		data = (data - stdChar + n) % 26 + stdChar;
	}

	return answer;
}