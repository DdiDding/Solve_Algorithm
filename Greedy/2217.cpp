#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<int> ropeList;
	
	for (int i = 0; i < N; ++i)
	{
		int rope = 0;
		scanf("%d", &rope);
		ropeList.push_back(rope);
	}

	sort(ropeList.begin(), ropeList.end(), greater<>());

	int maxW = 0;
	for (int i = 0; i < ropeList.size(); ++i)
	{
		int temp = ropeList[i] * (i + 1);
		if (maxW <= temp) maxW = temp;
	}
	cout << maxW;
	return 0;
}
