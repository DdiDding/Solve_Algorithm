#include <bits/stdc++.h>
using namespace std;

map <string, set<string>> m;
map <string, int> mm;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
	vector<int> answer;

	int idx;
	string a, b;
	for (const auto & d : report)
	{
		a = d.substr(0, idx = d.find(" "));
		b = d.substr(idx = d.find(" ") + 1);

		m[b].insert(a);
	}

	for (auto d : m)
	{
		//cout<<"신고당한 "<<d.first<<", 누적 횟수는 "<<d.second.size()<<endl;
		if (k <= d.second.size())
		{//처리메일을 보낼 사람을 저장한다.
			for (auto e : d.second)
			{
				++mm[e];
			}
		}
	}

	for (auto d : id_list)
	{
		if (mm[d] == 0) answer.push_back(0);
		else answer.push_back(mm[d]);
	}

	return answer;
}

/*
게시판 불량 이용자 신고 처리결과를 메일로 발송
유저는 한명의 유저에 대한 신고 스택을 1만 쌓을 수 있다.
신고는 여러명에게 가능

k번 신고 된 유저는 이용정지하고 정지메일 발송(취합???), 신고한 모든 유저에게 정지 사실을 메일로 발송

모든 이용자 id_list, 각 이용자가 신고한 id정보 report, 신고기준횟수 k
"처리결과 메일을 받은 횟수", 정지메일이아닌 정지 처리 메일임!!

1.먼저 정지 유저를 알아야함

2.그 정지유저를 누가 신고했는지 리스트가 있어야함

3.쭉 돌면서 각 유저별로 map에 카운팅함.

4.카운팅한 맵을 id_list키로 순서대로 출력

report는 중복을 제거 할 필요가 있다.

report를 순차적으로 돌면서
신고당한자, 신고를 한자- size가 곧 횟수 (뭉치기!)
map<string, set<string>>

for(auto d : report)
{
	m[신고당한자].insert(신고한자);
}

mm
for(auto d : m)
{
	++mm[d.fisrt];
}

신고를 한자들의 목록에
map<string, int>하면 됨
*/