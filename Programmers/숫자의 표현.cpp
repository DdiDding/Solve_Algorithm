#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	int ret = 0;
	int last = n;
	for (int s = n; 0 < s; --s)
	{
		//시작 num 추가
		ret += s;

		//크거나 같으면
		if (n <= ret)
		{
			//같으면 카운팅
			if (n == ret) answer++;
			//마지막 숫자 제거 후, 마지막 숫자 -1
			ret -= last--;
		}
	}

	return answer;
}