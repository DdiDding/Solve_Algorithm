#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> number) {
	int answer = 0;

	int i, j, k;
	for (i = 0; i < number.size(); ++i)
	{
		for (j = i + 1; j < number.size(); ++j)
		{
			for (k = j + 1; k < number.size(); ++k)
			{
				if (number.at(i) + number.at(j) + number.at(k) == 0) ++answer;
			}
		}
	}

	return answer;
}

//이거 재귀 만들어보기

//int result = 0;
//void Make(int floor, int start, int total, int max, const vector<int> & num)
//{
//	//cout << floor << "층, Total : " << total << endl;
//	if (floor == 3)
//	{
//		if (total == 0) ++result;
//		return;
//	}
//
//	++floor;
//	for (int i = start; i < max; ++i)
//	{
//		Make(floor, i + 1, total + num[i], max, num);
//	}
//	return;
//}

//밑의 재귀도 성공시켜보기!
int result = 0;
void Make(int floor, int start, int total, const vector<int> & num, vector<int> & debug)
{
	++floor;
	if (floor == 3)
	{
		total += num[start];
		cout << total << endl;
		if (total == 0) ++result;
		return;
	}

	for (int i = start; i < num.size(); ++i)
	{
		//현재정보를 넘기는거임
		Make(floor, i, total, num, debug);
	}
	return;
}

//int main()
//{
//	Make(0, 0, 0, number, debug);
//	return 0;
//}
