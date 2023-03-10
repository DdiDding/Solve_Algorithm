#include <bits/stdc++.h>
using namespace std;

int arr[1001];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n, l; cin >> n >> l;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);

	int cnt = 0;
	int end = 0;
	for (int i = 0; i < n; ++i)
	{
		//테이프 붙인다.
		end = arr[i] + l;
		++cnt;
		//다음 구멍에도 막을 수 있는지 확인
		while(arr[i + 1] < end && arr[i + 1] != 0)
		{
			++i;
		}
	}

	cout << cnt;
	return 0;
}

/*
품질
가장 왼쪽에서 정수만큼 떨어진 거리에 물이 샌다.
길이가 L인 테이프를 무한개 소유
테이프를 이용해서 물을 막으려고 함
그 위치의 좌우 0.5만큼 간격을 줘야 물이 안샘

물이새는곳의 위치, 가지고있는 테이프 길이 L
필요한 테이프 개수

테이프는 자를 수 없고, 겹쳐서 붙이기가 가능하다.
겹치는게 의미가 있을까?

최대한 한번에 많이 메꿔야한다. - 그리디

0 < 물이 새는 위치 < 1000


//
물이 새는 위치를 정렬해야할것이고

처음 물이 새는 위치 부터 테이프의 왼쪽 끝을 붙인다.
그 안에 속하는 물이새는 위치를 체크한다.
체크하면 index ++;

주의 할거는 시작 인덱스의 -0.5부터 시작하기 때문에
다음 인덱스 < 시작 인덱스 + L 일때만 카운팅한다.

//시간은
O(NlogN + N) 으로 sort할때 가장 많이 나오겠다.
*/
