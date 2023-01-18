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

	//�빮�� ��ȯ�� ���ÿ� ī����
	for (auto & data : s)
	{
		data = toupper(data);
		++alp[(int)data - DIST].first;
	}

	//����
	sort(alp, alp + 26, greater<>());

	//���
	if (alp[0].first == alp[1].first) cout << '?';
	else cout << (char)(alp[0].second + DIST);

	return 0;
}