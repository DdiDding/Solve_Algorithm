#include <string>
#include <vector>

using namespace std;

int solution(int n) {
	int answer = 0;

	int ret = 0;
	int last = n;
	for (int s = n; 0 < s; --s)
	{
		//���� num �߰�
		ret += s;

		//ũ�ų� ������
		if (n <= ret)
		{
			//������ ī����
			if (n == ret) answer++;
			//������ ���� ���� ��, ������ ���� -1
			ret -= last--;
		}
	}

	return answer;
}