#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

unordered_map<string,string> dogam;


int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; ++i)
	{
		string str; cin >> str;
		dogam.insert({ str, to_string(i) });
		dogam.insert({ to_string(i), str });
	}

	while (m--)
	{
		string str; cin >> str;
		cout << dogam.find(str)->second << '\n';
	}

	return 0;
}

/***
도감에 수록되어 있는 포켓몬의 개수 N, 맞춰야 하는 문제 개수 M
1 <= N,M <= 100'000

포켓몬 번호 1번부터 N번까지의 포켓몬이 입력으로 들어온다.
그리고 문제가 이어서 입력으로 들어온다.

포켓몬 번호 => 이름 출력
포켓몬 이름 => 번호 출력

best는 string저장하고 인덱스가 포켓몬 번호인 경우
아니면 두개를 저장?
string따로, 번호형 따로

근데 이름인지 번호인지 어 떻게?
무식하게다:?
*/