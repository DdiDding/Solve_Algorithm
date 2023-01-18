#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
typedef unsigned int total;
typedef unsigned short us;

int i, j;
int main()
{
	us n; scanf("%hu", &n);
	us d,p;
	//first : day, second : pay
	vector<pair<us, us>> lectures;
	for (i = 0; i < n; ++i)
	{
		scanf("%hu %hu", &p, &d);
		lectures.push_back(make_pair(d, p));
	}
	sort(lectures.begin(), lectures.end());

	priority_queue<us, vector<us>, greater<int>> pq;
	for (i = 0; i < n; ++i)
	{
		pq.push(lectures[i].second);
		if (lectures[i].first < pq.size())
		{
			pq.pop();
		}
	}

	total result = 0;
	while (pq.empty() == false)
	{
		result += pq.top();
		pq.pop();
	}
	printf("%u", result);
	return 0;
}