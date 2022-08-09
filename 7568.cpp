#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

#define WEIGHT first.first
#define HEIGHT first.second
#define GRADE second.second
#define ORDER second.first

//오름차순으로 정렬해야함
bool CompOrder(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
{
	return a.ORDER < b.ORDER;
}

pair<pair<int, int>, pair<int, int>> arr[51];
int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;
	int x, y;
	for (int i = 0; i < N; ++i)
	{
		cin >> x >> y;
		arr[i].first = make_pair(x, y);
		arr[i].second = make_pair(i, 1);
	}
	sort(arr, arr + N,greater<>());

	int grade;
	for (int i = 1; i < N; ++i)
	{
		grade = 1;
		for (int j = 0; j < i; ++j)
		{
			if (arr[i].HEIGHT < arr[j].HEIGHT && arr[i].WEIGHT < arr[j].WEIGHT)
			{
				++grade;
			}
		}
		arr[i].GRADE = grade;
	}
	sort(arr, arr + N, CompOrder);

	for (int i = 0; i < N; ++i)
	{
		cout << arr[i].GRADE << " ";
	}

	return 0;
}