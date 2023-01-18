#include <bits/stdc++.h>
using namespace std;

string w, s;
int dp[101][101];

//w�� s�� ��Ī�� �Ǵ��� bool���� ��ȯ
bool solve(int pw, int ps)
{
	int & ret = dp[pw][ps];
 	if (ret != -1) return ret;

	while (pw < w.size() && ps < s.size() && (w[pw] == '?' || w[pw] == s[ps]))
	{
		++pw, ++ps;
	}

	if (pw == w.size()) return ret = (ps == s.size());

	if (w[pw] == '*')
	{
		for (; ps <= s.size(); ++ps)
		{
			if (solve(pw + 1, ps) == 1) return ret = 1;
		}
	}

	return ret = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		cin >> w;
		int n; cin >> n;

		vector<string> ret;
		for(int i = 0; i < n; ++i)
		{
			cin >> s;
			memset(dp, -1, sizeof(dp));
			if (solve(0, 0) == true) ret.push_back(s);
		}

		sort(ret.begin(), ret.end(), less<string>());
		for (auto & d : ret)
		{
			cout << d << '\n';
		}
	}
	return 0;
}

/*
���� �̸��� �Ϻθ����� ���� �̸��� �����ϴ� ���
?Ȥ�� *Ư�� ���� ����

?�� � ���ڿ� ���ص� ��ġ�Ѵ�.
*�� 0 ���� �̻��� � ���ڿ����� ��ġ�Ѵ�. (��� �ȴٴ¶�)

���ϵ�ī�� ���ڿ� w
���ϸ��� ���� n

f[pw][ps] = 

*/

//���� Ž�� ���
/*
#include <bits/stdc++.h>
using namespace std;

//w�� s�� ��Ī�� �Ǵ��� bool���� ��ȯ
bool solve(string w, string s)
{
	int pos;
	for (pos = 0; pos < w.size(); ++pos)
	{
		if (w[pos] == '?') continue;
		else if (w[pos] == '*')
		{
			for (int skip = 0; pos + skip <= s.size(); ++skip)
			{
				if (solve(w.substr(pos + 1), s.substr(pos + skip)) == true) return true;
			}
		}

		if (w[pos] != s[pos]) return false;
	}

	if (pos == s.size()) return true;
	else return false;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	vector<string> s;

	while (t--)
	{
		string w; cin >> w;
		int n; cin >> n;
		s.resize(n,"");
		for(int i = 0; i < n; ++i)
		{
			cin >> s[i];
		}

		vector<string> ret;
		for (auto & d : s)
		{
			if (solve(w, d) == true) ret.push_back(d);
		}

		sort(ret.begin(), ret.end(), less<string>());
		for (auto & d : ret)
		{
			cout << d << '\n';
		}
	}
	return 0;
}
*/