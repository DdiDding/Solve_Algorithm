#include <bits/stdc++.h>

using namespace std;

int solution(vector<vector<int>> sizes) {

	int max_r = 0, t_r;
	int max_c = 0, t_c;
	for (const auto & d : sizes)
	{
		if (d[0] < d[1]) t_r = d[1], t_c = d[0];
		else t_r = d[0], t_c = d[1];

		max_r = max(max_r, t_r);
		max_c = max(max_c, t_c);
	}

	return max_r * max_c;
}

/*
회사에서 만드는 지갑의 크기를 정한다.
모든 명함을 수납할 수 있는 가장 최소 크기

가로세로 상관 없이, 큰걸 가로로 작은걸 세로로 설정하면 편하지 않을까?
카드를 섞으고 한쪽방향으로 모두 통일할때, 가장 큰 카드의 사이즈가 모두 담기는걸 상상할 수 있다.

어떻게?

sizes를 순차 탐색하면서 큰수들 중에서의 max값, 작은 수들 중에서의 max값
O(n) 쌉가능
*/