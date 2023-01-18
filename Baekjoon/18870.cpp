#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x[1000005];
vector<int> uni; // unique
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		uni.push_back(x[i]);
	}
	sort(uni.begin(), uni.end());
	uni.erase(unique(uni.begin(), uni.end()), uni.end());
	for (int i = 0; i < n; i++)
		cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' ';
}

//#include <iostream>
//#include <algorithm>
//
//#define MAX 1'000'002
//using namespace std;
//
//pair<int, int> arr[MAX];
//int result[MAX];
//
//bool comp(const pair<int, int> & a, const pair<int, int> & b)
//{
//	return a.second < b.second;
//}
//
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//
//	int N; cin >> N;
//
//	for (int i = 0; i < N; ++i)
//	{
//		cin >> arr[i].first;
//		arr[i].second = i;
//	}
//	sort(arr, arr + N);
//
//	int std = 0; 
//	for (int i = 1; i < N; ++i)
//	{
//		if (arr[i].first != arr[i - 1].first) ++std;
//		result[arr[i].second] = std;
//	}
//	
//	for (int i = 0; i < N; ++i)
//	{
//		cout << result[i]<< " ";
//	}
//		
//	return 0;

//}