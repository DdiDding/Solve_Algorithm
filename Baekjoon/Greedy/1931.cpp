#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int N, end, begin;

	vector<pair<int, int>>schedule;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> begin >> end;
		schedule.push_back(make_pair(end, begin));
	}

	sort(schedule.begin(), schedule.end());

	int endTime = schedule[0].first;
	int count = 1;
	for (int i = 1; i < N; ++i)
	{
		if (endTime <= schedule[i].second)
		{
			endTime = schedule[i].first;
			++count;
		}
	}

	cout << count;

	return 0;
}

//
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <vector>
//
//using namespace std;
//typedef unsigned long ulong;
//ulong ulong_max = 4294967296;
//
//struct UsingTime
//{
//	ulong startTime;
//	ulong endTime;
//};
//
////������ ȸ�ǰ� �����ϴ��� Ȯ���ϰ� ���� ª�� ȸ�ǽð� �ε����� ��ȯ
//int IsConferenceExist(const ulong & startTime, const vector<UsingTime> & list, int & index)
//{
//	ulong tempMax = ulong_max;
//	int i = 0;
//	int resultIndex = -1;
//	for (auto & data : list)
//	{
//		if (startTime <= data.startTime)
//		{
//			if (data.endTime - startTime < tempMax)
//			{
//				tempMax = data.endTime - startTime;
//				resultIndex = i;
//			}
//		}
//		++i;
//	}
//	index = resultIndex;
//	return resultIndex;
//}
//
//
//int main()
//{
//	//ȸ�� �ð� �Է�
//	ulong startTime = 0;
//	int index = 0;
//	int result = 0;
//	int n;
//	scanf("%d", &n);
//
//	//�� ȸ�� �Է�
//	vector<UsingTime> list(n);
//	for (auto & data : list)
//	{
//		scanf("%lu %lu", &(data.startTime), &(data.endTime));
//	}
//
//	while (-1 < IsConferenceExist(startTime, list, index))
//	{
//		++result;
//		startTime = list[index].endTime;
//	}
//	
//	printf("%d", result);
//
//	return 0;
//}
//
