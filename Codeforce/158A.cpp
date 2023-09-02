#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n, k; cin >> n >> k;
	
	std::vector<int> scores;
	scores.resize(n);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> scores[i];
		if (scores[k - 1] <= scores[i] && 0 < scores[i]) ++cnt;
	}

	cout << cnt;
	return 0;
}


/* k번째의 점수 이상인(1이상) 점수를 획득한 참가자는 다음 라운드에 진출한다.
 * 대회의 총 n명의 참가자가 주어진다, 그리고 당신은 그들의 점수를 알 수 있다.
 * 얼만큼의 참가자가 다음 라운드에 진출하는지 계산하세요

 * Input : 첫 번째 줄의 input은 두개의 정수 n과 k가 빈칸 하나 차이로 들어있다
 * 두 번째 줄은 n개의 정수가 띄어서 들어온다
 */