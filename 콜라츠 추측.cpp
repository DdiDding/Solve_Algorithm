include <bits / stdc++.h>
using namespace std;

int solution(int num) {
	int answer = 0;

	while (++answer <= 500)
	{
		cout << num << endl;
		if (num & 0x1 == 0x1)
			num = num * 3 + 1;
		else
			num /= 2;

		if (num == 1) return answer;
	}
	return -1;
}