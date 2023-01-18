#include <string>
#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;
typedef pair<double, int> pdi;

bool cmp(const pdi & a, const pdi & b)
{
	if (a.first == b.first) return a.second < b.second;
	return a.first > b.first;

}

vector<int> solution(int N, vector<int> stages) {

	vector<int> answer;
	sort(stages.begin(), stages.end());

	pdi p[501];

	int start = 0;
	for (int i = 0; i < stages.size(); ++i)
	{
		if (stages[i] != stages[i + 1] || i + 1 == stages.size())
		{
			cout << stages[i] << "와" << stages[i + 1] << "의 경계 계산" << endl;
			cout << "스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 : " << i + 1 - start << endl;
			cout << "스테이지에 도달한 플레이어 수 : " << stages.size() - start << endl;
			p[stages[i]] = make_pair((double)(i + 1 - start) / (stages.size() - start), stages[i]);
			start = i + 1;
		}
		if (N + 1 == stages[i + 1]) break;
	}

	for (int i = 1; i < N + 1; ++i)
	{
		if (p[i].second == 0) p[i].second = i;
	}

	sort(p + 1, p + N + 1, cmp);

	for (int i = 1; i < N + 1; ++i)
	{
		answer.push_back(p[i].second);
	}

	for (auto & d : p)
	{
		cout << d.second << "의 실패율 " << d.first << endl;
	}

	return answer;
}

/*
실패율 : 스테이지에 도달했으나 아직 클리어하지 못한 플레이어의 수 / 스테이지에 도달한 플레이어 수

1. stages를 오름차순 정렬 후 탐색
2. 스테이지가 바뀌면 스테이지 실패율 계산후 pair에 저장
3. pair가 든 vector 정렬 후 스테이지만 뽑아 답 출력

 00033
 01234
l-----l
 11122

 1 = 2 / 5
 2 = 2 / 2

*/