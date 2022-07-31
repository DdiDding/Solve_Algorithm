#include <stdio.h>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int T;
	scanf("%d ", &T);

	vector<string> result;
	char temp;
	int leftCnt = 0, rightCnt = 0;

	for (int i = 0; i < T; )
	{
		temp = getchar();

		if (temp == '(') ++leftCnt;
		else if (temp == ')') ++rightCnt;
		
		if (leftCnt < rightCnt)
		{
			string line;
			getline(std::cin, line);
			result.push_back("NO");
			leftCnt = 0;
			rightCnt = 0;
			++i;
		}
		else if (temp == '\n')
		{
			if (leftCnt == rightCnt)
				result.push_back("YES");
			else
				result.push_back("NO");
			leftCnt = 0;
			rightCnt = 0;
			++i;
		}
	}

	for (const auto & data : result)
	{
		cout << data<<'\n';
	}

	return 0;
}