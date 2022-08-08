#include <iostream>
#include <string>
using namespace std;

//길이가 10 이상이면 축약해라
//어떻게? => 첫번째 글자 + 그안의 글자수 + 마지막 글자

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;
	string str;
	for (int i = 0; i < N; ++i)
	{
		cin >> str;
		if (10 <= str.length()) cout << str[0] << str.length() - 2 << str[str.length() - 1] << endl;
		else cout << str << "\n";
	}

	return 0;
}

#include <iostream>
#include <string>
using namespace std;

int main() {
	int n, len;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		len = str.size();
		if (len > 10) cout << str[0] << len - 2 << str[len - 1] << "\n";
		else cout << str << "\n";
	}
}