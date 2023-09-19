#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string solution(string s) {

	//���� �ϳ��� vector�� ����
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
	//������ ��ó �������� ���� ���� ����s
	nums.push_back(stoi(str));

	//������������ ����
	sort(nums.begin(), nums.end());

	//vector�� �Ǿհ� �ǵڸ� ���ڿ��� ��ȯ�ϸ鼭 ��ȯ
	return to_string(nums.front()) + " " + to_string(nums.back());
}

int main()
{
	solution("14 4 2 3");

	return 0;
}