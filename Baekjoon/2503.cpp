#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define Strike first
#define Ball second

pii Check(string t, string ask)
{
	int cnt_s = 0;
	int cnt_b = 0;

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (t[i] == ask[j])
			{
				if (i == j) ++cnt_s;
				if (i != j) ++cnt_b;
				break;
			}
		}
	}
	return { cnt_s, cnt_b };
}

string ask[101];
pii sb[101];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int answer = 0;
	int n; cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> ask[i] >> sb[i].Strike >> sb[i].Ball;
	}

	string temp;
	pii tsb;
	int i, j;
	for (i = 123; i < 988; ++i)
	{
		temp = to_string(i);
		if (temp[0] == temp[1] || temp[0] == temp[2] || temp[1] == temp[2]) continue;
		if (temp[0] == '0' || temp[1] == '0' || temp[2] == '0') continue;

		for (j = 0; j < n; ++j)
		{
			tsb = Check(temp, ask[j]);
			if (sb[j] != tsb) break;
		}
		if (j == n) ++answer;
	}
	cout << answer;
	return 0;
}

/*
숫자야구게임
서로다른 세 자리 수
같은 숫자,동일한 자리에 위치하면 스트라이크 + 1
같은 숫자,다른 자리면 볼 + 1

1 2 3 4 5 6 7 8 9
o o o
    o o o
  o o       o
      o       o o

1,2,3,4,5,7

100개의 질문
123
12

확실히 아닌거나, 맞는거 찾아서 그 나머지의 경우의수 찾기?

내가 맞다고 생각한 경우의 수들이
민혁의 input이 맞다 가정하에
=>내코드=>
영수의 모든 질문에 맞는 출력이 되어야함

가지치기?
123 ~ 999 안에 나오는게 소름

대략 900번
900 * 100개 = 90'000 쌉가능이죠
*/