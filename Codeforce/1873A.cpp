#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int cnt_wrong = 0;

		if (s[0] != 'a') ++cnt_wrong;
		if (s[1] != 'b') ++cnt_wrong;
		if (s[2] != 'c') ++cnt_wrong;

		cout << (cnt_wrong == 3 ? "NO" : "YES") << '\n';
	}

	return 0;
}
/*
알파벳 a,b,c 와 함께 세 장의 카드가 있다.

한 번만 다음 작업을 수행할 수 있다.
o 두개의 카드를 고르고 교환하기

작업 후 순서가 abc가 될 수 있습니까? 가능하면 "YES" 아니면 "NO"를 반환하세요.

Input.
첫 줄에는 테스트 케이스의 개수인 한 자리수의 정수가 있습니다. 
각 테스트 케이스의 줄 마다 a,b,c가 구성된 문자열이 들어있습니다.
*/