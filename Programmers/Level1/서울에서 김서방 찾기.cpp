#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
	string answer = "김서방은 ";

	int cnt = 0;
	for (const auto & d : seoul)
	{
		if (d == "Kim") break;
		++cnt;
	}

	answer += to_string(cnt) + "에 있다";
	return answer;
}