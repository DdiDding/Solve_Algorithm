#include <string>
#include <vector>

using namespace std;

string solution(int n) {
	string answer = "";
	for (int i = 0; i < n / 2; ++i)
	{
		answer += "����";
	}
	if (n & 0x1 == 0x1) answer += "��";
	return answer;
}