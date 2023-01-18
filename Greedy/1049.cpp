#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

#define MAX_PRICE 1000

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M; cin >> N >> M;
	int P = MAX_PRICE, I = MAX_PRICE;

	int p, i;
	while (M--)
	{
		cin >> p >> i;
		if (p < P) P = p;
		if (i < I) I = i;
	}

	//낱개가 가성비가 제일 좋으면
	if (I * 6 <= P) cout << I * N;
	//패키지가 더 가성비가 좋으면
	else
	{
		//패키지를 사고 남은 기타줄
		int remainI = I * (N % 6);
		cout << P * (N / 6) + ((P < remainI) ? P : remainI);
	}
	return 0;
}