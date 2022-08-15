#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> pos; //양수 저장
	vector<int> neg; //음수 저장
	vector<int> zero; //0 저장
	vector<int> ans; //출력 = ans벡터의 원소의 총합
	int num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (num > 0) {
			if (num == 1) {
				ans.push_back(num);
			}
			else {
				pos.push_back(num);
			}
		}
		else if (num < 0) {
			neg.push_back(num);
		}
		else { //num==0
			zero.push_back(num);
		}
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	/*양수*/
	int pSize = pos.size();
	if (pSize % 2 != 0) {
		ans.push_back(pos[0]);
	}
	for (int i = pSize - 1; i > 0; i -= 2) {
		int big = pos[i];
		int small = pos[i - 1];
		int mul = big * small;
		ans.push_back(mul);
	}

	/*음수*/
	int nSize = neg.size();
	if (nSize % 2 != 0) {
		if (zero.size() > 0) {
			zero.pop_back();
		}
		else {
			ans.push_back(neg[nSize - 1]);
		}
	}
	for (int i = 0; i < nSize - 1; i += 2) {
		int small = neg[i];
		int big = neg[i + 1];
		int mul = small * big;
		ans.push_back(mul);
	}

	/*출력 = ans벡터의 원소의 총합*/
	int sum = 0;
	for (int i = 0; i < ans.size(); i++) {
		sum += ans[i];
	}
	cout << sum;


	return 0;
}


//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <functional>
//#include <vector>
//#include <queue>
//#include <stack>
//using namespace std;
//
//vector<int>arr;
//int result = 0;
//int i;
//int temp;
//
//int main()
//{
//	//1. Get input & sorting
//	ios::sync_with_stdio(0), cin.tie(0);
//	
//	int N; cin >> N;
//	int minUnit = 0;
//	
//	for (int i = 0; i < N; ++i) 
//	{
//		cin >> temp;
//		
//		//if input is one, add to result immediately
//		if (temp == 1) ++result;
//		else
//		{
//			//include zero in the count
//			if (temp <= 0) ++minUnit;
//			arr.push_back(temp);
//		}
//	}
//	sort(arr.begin(), arr.end(), less<int>());
//
//	//2. Loop
//	//negative part
//	if (minUnit != 0)
//	{
//		//홀수면
//		if (minUnit & 0x1 == 0x1)
//		{
//			result += arr[--minUnit];
//		}
//		if (2 <= minUnit)
//		{
//			for (i = 0; i < minUnit; i += 2)
//			{
//				result += arr[i] * arr[i + 1];
//			}
//		}
//	}
	
	//positive part
	/*if (2 <= (N - minUnit))
	{
		for (i = N - 1; minUnit <= i; i -= 2)
		{
			result += arr[i] * arr[i - 1];
		}
		if (minUnit == i) result += arr[i];
	}*/

	cout << result;
	return 0;
}