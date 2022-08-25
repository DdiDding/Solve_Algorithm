#include <iostream>
#include <unordered_set>

using namespace std;
unordered_set<int> S;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;
	int temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		S.insert(temp);
	}

	int M, F; cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> F;
		cout << ((S.find(F) == S.end()) ? 0 : 1) << "\n";
	}

	return 0;
}

//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//int arr[100'002];
//
//int BinarySearch(const int * arr, const int & size, const int & f)
//{
//	int s = 0, e = size - 1, m;
//
//	while (s <= e)
//	{
//		m = (s + e) / 2;
//
//		if (arr[m] == f) return 1;
//		if (arr[m] < f) s = m + 1;
//		else e = m - 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//	
//	int N; cin >> N;
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> arr[i];
//	}
//	sort(arr, arr + N);
//
//	int M,F; cin >> M;
//	for (int i = 0; i < M; ++i)
//	{
//		cin >> F;
//		cout << BinarySearch(arr, N, F) << "\n";
//	}
//
//	return 0;
//}