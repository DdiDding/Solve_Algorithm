#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string solution(string s) {

	//숫자 하나씩 vector에 삽입
	vector<int> nums;
	string str = "";

	for (const char& t : s)
	{
		if (t == ' ')
		{
			nums.push_back(stoi(str));
			str = "";
		}
		else
		{
			str += t;
		}
	}
	//마지막 미처 저장하지 못한 숫자 저장s
	nums.push_back(stoi(str));

	//오름차순으로 정렬
	sort(nums.begin(), nums.end());

	//vector의 맨앞과 맨뒤를 문자열로 변환하면서 반환
	return to_string(nums.front()) + " " + to_string(nums.back());
}

int main()
{
	solution("14 4 2 3");

	return 0;
}