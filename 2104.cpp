#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	return 0;
}

/*
a[i] + ... + a[j] * min(a[i] ~ a[j])

완탐 - 모든 부분배열구해서 최대 점수 


3 1 6 = 10 * 1 = 10 
4 5 2 = 11 * 2 = 11

부분배열마다 맨 왼쪽, 맨 오른쪽을 가지고 있다.
다음 만나는게 최대 값

최소 값이 올라갈 경우

아니면 최대 값부터?

*/

//분할정복
//시간 복잡도 : O(n log n + n)
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll arr[100'005];

ll solve(int s, int e)
{
	//기저사례
	if (s == e) return arr[s] * arr[s];

	//1. 반갈죽했을 때 양쪽중 큰 점수 저장
	int mid = (s + e) / 2;
	ll ret = max(solve(s, mid), solve(mid + 1, e));

	//2. 최소로 중간에 걸친 경우의 점수 구하기
	int l = mid, r = mid + 1;
	ll std = arr[l] + arr[r];
	ll m = arr[l] < arr[r] ? arr[l] : arr[r];
	ret = max(ret, std * m);

	//3. 중간에 걸친 경우에서 확장해 나가며 점수 구하기
	while (s < l || r < e)
	{
		//각 왼쪽, 오른쪽으로 확장 했을 때의 점수 저장
		ll lv = s < l ? std * min(arr[l - 1], m) : -1;
		ll rv = r < e ? std * min(arr[r + 1], m) : -1;

		//오른쪽으로 확장했을 때 더 높은 경우
		if (lv < rv)
		{
			std += arr[++r];
			m = min(m, arr[r]);
		}
		//왼쪽으로 확장했을 때 더 높은 경우
		else
		{
			std += arr[--l];
			m = min(m, arr[l]);
		}

		//값 업데이트
		ret = max(ret, std * m);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << solve(0, n - 1);
	return 0;
}
*/