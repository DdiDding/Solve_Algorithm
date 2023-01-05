#include <bits/stdc++.h>
using namespace std;

string w, s;
int dp[101][101];

//w가 s에 매칭이 되는지 bool형을 반환
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
파일 이름의 일부만으로 파일 이름을 지정하는 방법
?혹은 *특수 문자 포함

?는 어떤 글자와 비교해도 일치한다.
*는 0 글자 이상의 어떤 문자열에도 일치한다. (없어도 된다는뜻)

와일드카드 문자열 w
파일명의 개수 n

f[pw][ps] = 

*/

//완전 탐색 방법
/*
#include <bits/stdc++.h>
using namespace std;

//w가 s에 매칭이 되는지 bool형을 반환
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