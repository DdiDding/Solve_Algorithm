#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
priority_queue<int,vector<int>,greater<int>> p;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	int s, e;
	for (int i = 0; i < n; ++i)
	{
		cin >> s >> e;
		v.push_back({ s, e });
	}
	sort(v.begin(), v.end());

	size_t answer = 1;
	p.push(0);
	for (const auto & d : v)
	{
		if (p.top() <= d.first)
		{
			p.pop();
		}
		p.push(d.second);

		answer = max(answer, p.size());
	}

	cout << answer;
	return 0;
}

/*
수강신청
N개의 수업
수업 시간 : Si ~ Ti

최소의 강의실을 사용해서 모든 수업을 가능하게?

1	2	3	4	5		//0개
	2	3	4			//1개
		3	4	5		//1개
			4	5	6	7	8
				5	6g
					6	7
					6	7	8

7
1 5
2 4
3 5
4 8
5 6
6 7
6 8

3
1 2
2 3
3 4
				
-
5
5
8

두개는 겹치는지 확인 가능
시작시간이 스택 끝이상이다 하면 바꿔

일단 S를 오름차순 정렬

최대로 겹치는게 답이 아닐까? 
겹치는 수업은 
if(겹치는 조건 == true)

해당 수업 = X
X의 끝 시간과 시작시간이 같은 수업까지 찾는다.

기준을 잡는다.

끝시간이 

수업시간이 적은것부터?

*/