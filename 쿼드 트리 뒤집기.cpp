#include <iostream>
#include <queue>
#include <string>
using namespace std;

queue<char> q;

//현재 레벨 트리의 각 4분면 string을 구하고 재 조합하여 반환한다!
//불변식 : 이전레벨의 x는 없다.
string Solve(int lev)
{
	//base case : 1칸일때, 두 가지 경우가 있다.
	//1)최소레벨일때의 1칸, 2)최소레벨이 되지 않았을 때의 한칸
	if (lev == 0 || q.size() == 1)
	{
		string ret(1, q.front()); q.pop();
		return ret;
	}

	//1. 각 4분면의 문자열 저장
	string temp[4];
	for (int i = 0; i < 4; ++i)
	{
		temp[i] = q.front(); q.pop();
		if (temp[i] == "x") temp[i] += Solve(lev - 1);
	}

	//2. 재 합성후 반환
	return temp[2] + temp[3] + temp[0] + temp[1];
}


int main()
{
	int n; cin >> n;
	while (n--)
	{
		//1. Input value
		queue<char> tq; q = tq;
		string ts; cin >> ts;
		for (auto & d : ts) q.push(d);

		//2. Do solve
		string ret(1, q.front()); q.pop();
		if (ret == "x") ret += Solve(20);
		cout << ret << "\n";
	}
	return 0;
}
/*
주어진 공간을 항상 4개로 분할한다.

2^N * 2^N의 크기의 그림판

모든 픽셀이 검은 색일 경우 = b
모든 픽셀이 흰	색일 경우 = w
같은 색이 아니라면 4등분해 재 압축 하여 합친다.
합치는 순서는 [ x + 좌측상단 + 우측상단 + 좌측하단 + 우측하단 ]이다.

상하반전을 할 필요 없이, 합치는 순서를 다르게 하면 상하반전 처럼 보이지 않을까?
[x + 좌측하단 + 우측하단 + 좌측상단 + 우측상단 ]


*/
