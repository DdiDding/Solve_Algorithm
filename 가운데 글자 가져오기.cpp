
2
3
4
5
6
7
8
9
10
11
12
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	if (s.size() & 0x1 == 0x1) answer += s[s.size() / 2];
	else answer += s.substr(s.size() / 2 - 1, 2);
	return answer;
}