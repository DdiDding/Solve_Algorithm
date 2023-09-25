#include <string>
#include <vector>
#include <bitset>
using namespace std;

vector<int> solution(string s) {
	vector<int> ans;
	int cnt_roop = 0, cnt_zero = 0;

	while (s != "1")
	{
		int cnt_one = 0;
		for (const auto& t : s)
		{
			if (t == '1') ++cnt_one;
		}
		cnt_zero += s.size() - cnt_one;


		s = bitset<150'005>(cnt_one).to_string();
		s = s.substr(s.find('1'));
		++cnt_roop;
	}

	ans.push_back(cnt_roop);
	ans.push_back(cnt_zero);

	return ans;
}