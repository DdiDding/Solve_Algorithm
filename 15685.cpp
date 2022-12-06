#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

//[0] : start X //[1] : start Y //[2] : 시작 방향 //[3] : 세대
vector<vector<int>> dcProp;
set<pii> vertices;
vector<pii> tdc;

pii operator+(const pii & p1, const pii & p2)
{
	return { p1.first + p2.first, p1.second + p2.second };
}
pii operator-(const pii & p1, const pii & p2)
{
	return { p1.first - p2.first, p1.second - p2.second };
}

pii moveSet[4] = { {1, 0},{0, -1},{-1, 0}, {0, 1} };
void MakeDC()
{
	//1. 드래곤 커브를 개수만큼 생성한다.
	for (const auto & d : dcProp)
	{
		//1.1 0세대의 시작, 끝 좌표 저장
		pii s = { d[0], d[1] };
		tdc.push_back(s);
		tdc.push_back(s + moveSet[d[2]]);

		//1.2 1세대이상부터, 입력 세대 만큼 커브 성장
		for (int i = 1; i <= d[3]; ++i)
		{
			pii e = tdc.back();
			int tempSize = tdc.size();

			//1.2.1 끝점 이전의 꼭짓점들 회전 시켜 좌표 기록
			for (int j = tempSize - 2; 0 <= j ; --j)
			{
				pii t = tdc[j] - e;
				tdc.push_back(e + make_pair(t.second * -1, t.first));
			}
		}

		//최종 저장
		for (const auto & d : tdc)
		{
			vertices.insert(d);
		}
		tdc.resize(0);
	}
}

pii checkSet[3] = { {1, 0}, {0, 1}, {1, 1} };
int CheckRect()
{
	int ret = 0;
	//저장한 각 꼭짓점 검사
	for (auto & d : vertices)
	{
		bool isRect = true;
		for (int i = 0; i < 3 && isRect; ++i)
		{
			if (vertices.find(d + checkSet[i]) == vertices.end()) isRect = false;
		}
		if (isRect == true) ++ret;
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	//1. Input values
	int c; cin >> c;
	dcProp.resize(c);
	for (int i = 0; i < c; ++i)
	{
		dcProp[i].resize(4);
		cin >> dcProp[i][0] >> dcProp[i][1] >> dcProp[i][2] >> dcProp[i][3];
	}

	//2. Do calculate & Print result
	MakeDC();
	cout << CheckRect();
	return 0;
}

/*
[이차원 좌표 평면] (uv좌표계)


세 가지 속성
1. 시작 점
2. 시작 방향
3. 세대

특징
1. 길이는 1이다.
2. 다음 세대의 위치
시작점	: 이전 세대의 끝점
끝점		: 첫번째 세대의 시작점을 현재 세대의 시작점을 기준으로 시계방향으로 90도 회전한 위치

크기 100 * 100 maps (zero-based 0 ~ 100)
드래곤 커브 N개

이때 1*1 정사각형의 네꼭짓점이 드래곤 커브의 일부인 경우의 개수 를 구하여라

*/