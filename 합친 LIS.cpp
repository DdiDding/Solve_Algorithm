#include <bits/stdc++.h>
using namespace std;

//JLIS의 길이를 출력한다.
int solve(vector<int> a, vector<int> b)
{


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	return 0;
}

/*
두개의 증가 부분 수열을 합치고 오름차순 정렬한게 합친 증가 부분 수열,
그중 가장 긴 수열을 합친 LIS.
중복 원소는 제거 된다.

1) 수열 A,B 에서 LIS를 찾는다.

LIS를 합친다고 가장 길지는 않다!
모든 증가 부분 수열을 더해봐야함!

"슈도 코드"
1. for(A의 f(1 ~n)으로 끝나는 증가 부분 수열
{
	1-1.for(B의 f(1 ~ n)으로 끝나는 증가 부분 수열)
		{
			합하여 최대 값 업데이트
		}
}


*/