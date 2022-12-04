#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int C, N;
double ret;
bool check[10];
double m[10][10];

//idx : 현재 있는 나라
//temp : 중간 결과 값
//cnt : 방문한 나라, 처음에 1을 넣어 시작한다.
void Count(int idx, double temp, int cnt)
{
	//기저 사례
	if (cnt == N)
	{
		ret = min(ret, temp);
		return;
	}
	
	//1.방문하지 않은 나라를 모두 탐색
	check[idx] = true;
	for (int i = 0; i < N; ++i)
	{
		//1-1. 방문하지 않은 나라여야하고, 현재나라가 아니어야한다.
		if (check[i] == false && i != idx)
		{
			check[i] = true;
			Count(i, temp + m[idx][i], cnt + 1);
			check[i] = false;
		}
	}
	check[idx] = false;
}

int main()
{
	cin >> C;
	while (C--)
	{
		//1. input,init value
		cin >> N;
		ret = 1.7976931348623158e+308;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				cin >> m[i][j];
			}
		}

		//2. Calculate
		for (int i = 0; i < N; ++i)
		{
			Count(i, 0.0, 1);
		}
		cout << fixed << setprecision(10);
		cout << ret << endl;
	}
	return 0;
}

/*

완전탐색사용 , 시간은 O(8!)로 시간적으로 여유.
재귀 사용

방문했는지 체크해야함.


*/






//
//
//#include <iostream>
//#include <algorithm>
//#include <limits>
//using namespace std;
//
//int C;
//int N;
//int start;
//double ret = DBL_MAX;
//bool check[10];
//double m[10][10];
//
////idx : 현재 있는 나라
////temp : 중간 결과 값
////cnt : 방문한 나라 카운트 처음에 1넣야ㅏ하 
//void Count(int idx, double temp, int cnt)
//{
//	//기저 사례
//	if (cnt == N)
//	{
//		ret = min(ret, temp + m[idx][start]);
//		cout << "후보 값 : " << temp + m[idx][start] << endl;
//		return;
//	}
//
//	check[idx] = true;
//
//	//1.방문하지 않은 나라를 모두 탐색
//	for (int i = 0; i < N; ++i)
//	{
//		//1-1. 방문하지 않은 나라여야하고, 현재나라가 아니어야한다.
//		if (check[i] == false && i != idx)
//		{
//			check[i] = true;
//			cout << idx << "나라에서 " << i << "나라로 이동" << endl;
//			cout << m[idx][i] << "을 더해 현재 중간 값 " << temp + m[idx][i] << "입니다.\n\n";
//			Count(i, temp + m[idx][i], cnt + 1);
//			check[i] = false;
//		}
//	}
//}
//
//int main()
//{
//	cin >> C;
//	while (C--)
//	{
//		//1. input,init value
//		cin >> N;
//		memset(check, 0, sizeof(check));
//		for (int i = 0; i < N; ++i)
//		{
//			for (int j = 0; j < N; ++j)
//			{
//				cin >> m[i][j];
//			}
//		}
//
//		//2.
//		for (int i = 0; i < N; ++i)
//		{
//			Count(i, 0.0, 1);
//		}
//
//		cout << ret << endl;
//	}
//
//	return 0;
//}
//
///*
//
//완전탐색사용 , 시간은 O(8!)로 시간적으로 여유.
//재귀 사용
//
//방문했는지 체크해야함.
//
//
//*/