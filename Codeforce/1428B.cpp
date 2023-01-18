#include <iostream>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(0), cin.tie(0);
	long t; cin >> t;
	while (t--) 
	{
		long n; cin >> n;
		//���� �Է� �ް�
		string s; cin >> s;
		bool left(true), right(true);
		//���ɹ氳��
		long cnt(0);

		//�氳����ŭ �ݺ�
		for (long p = 0; p < n; p++) 
		{
			//�翷�߿� ������������� ����
			if ((s[(n + p - 1) % n] == '-') || (s[p % n] == '-'))
			{
				++cnt; 
			}

			//�ѹ������� ��ΰ������� üũ
			if (s[p] == '<') { right = false; }
			else if (s[p] == '>') { left = false; }
		}

		//��� �ѹ������� ��ΰ����ϸ� �氳����ŭ ����
		if (left || right) { cnt = n; }
		cout << cnt << endl;
	}
	return 0;
}

//
////���ʿ� ������� �ִ��� Ȯ��
//int returnRoom = 0;
//if (1)
//{
//
//}
//else
//{
//	//4. n(�氳��)��ŭ �ݺ�
//	char sign; int temp;
//	for (int i = 0; i < N; ++i)
//	{
//		temp = i;
//		//�������� ������.
//		do
//		{
//			sign = belt[i];
//			++temp;
//			if (temp % N != 0)
//			{
//				returnRoom++;
//				break;
//			}
//		} while (sign != '<');
//		//���������� ������.
//	}
//}