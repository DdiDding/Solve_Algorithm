//#include<iostream>
//#include<vector>
//#define MAX 1'001
//
//typedef unsigned int integer;
//using namespace std;
//
//int main()
//{
//	integer N;
//	cin >> N;
//	
//	vector<integer> sequence[MAX];
//	sequence[0].push_back(MAX);
//	integer topIndex = 0;
//	integer temp = 0;
//
//	integer dp[MAX];
//
//	//[��� �迭�� �ѹ� ���� �ݺ���] ���� ������ ���ʰ� �� ���� �����Ѵ�. 
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> temp;
//		if (temp <= sequence[topIndex][0])
//		{
//			sequence[++topIndex].push_back(temp);
//		}
//		else
//		{
//			for (int j = 1; j <= topIndex; ++j)
//			{
//				if (sequence[topIndex].back() < temp)
//					sequence[topIndex].push_back(temp);
//			}
//		}
//	}
//
//	
//	for (int i = 0, temp = 0; i <= topIndex; ++i)
//	{
//		if (temp < sequence[i].size()) temp = sequence[i].size();
//	}
//
//	cout <<temp;
//	return 0;
//}
//
//
////
////#include<iostream>
////typedef unsigned int integer;
////using namespace std;
////
////int main()
////{
////	integer N, max = 0, temp = 0, result = 0;
////	cin >> N;
////	for (int i = 0; i < N; ++i)
////	{
////		cin >> temp;
////		if (max < temp)
////		{
////			max = temp;
////			++result;
////		}
////	}
////
////	cout << result;
////	return 0;
////}
