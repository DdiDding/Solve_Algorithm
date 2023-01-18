#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

pair<int,int> alp[27];
static const int DIST = 65;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	string s; cin >> s;

	for (int i = 0; i < 26; ++i)
	{
		alp[i].second = i;
	}

	//대문자 변환과 동시에 카운팅
	for (auto & data : s)
	{
		data = toupper(data);
		++alp[(int)data - DIST].first;
	}

	//정렬
	sort(alp, alp + 26, greater<>());

	//출력
	if (alp[0].first == alp[1].first) cout << '?';
	else cout << (char)(alp[0].second + DIST);

	return 0;
}