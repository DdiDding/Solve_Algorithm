/*
�� ��, ���� ���ڵ��� ������ �ƹ�Ÿ�� �Ƹ��ٿ� ���� ������ �̿��ߴ�.
�� ������ ��� ���⿡ ������ ���� ���ϱ� �� ��ƴ�.

�۳�, hero�� �������� �����̿� �ٻ��� ä���� ��������.
�� ��, �׵��� ���� ��ȭ�߰� �ᱹ �¶��� Ŀ���� �Ǿ���.

������ ����, �״� �׳ฦ ���ǿ��� �������µ� �׳�� ������ �����̿���!
hero�� ���� ����� �ٽ� ����ϱ� ������°� �Ǿ���.
�׷��� �״� �׵��� �г����� ���� �׵��� ������ �˾ƺ� �� �ִ� ����� �����س½��ϴ�.

�̰��� ���� ����Դϴ�.
	���� �� ������ �г����� ���� ���ڰ� Ȧ�����, �����Դϴ�.
	�ƴϸ� �����Դϴ�.

��ſ��� ������ �г����� ��Ÿ���� String�� �־����ϴ�,
hero�� ����� ����� hero�� ���� �� �������� ������ �����ּ���
*/


/*
Input	:ù �ٿ� ������� String�� ����ֽ��ϴ�.(���� �ҹ��ڷθ� �̷����)
		 ���� ���� 100�� ���� �Դϴ�.
Output	:������ ��� "CHAT WITH HER!", ������ ��� "IGNORE HIM!" �� ����ϼ���
*/
#include <iostream>
#include <string>
using namespace std;



int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	//1. Get Input & Initializing value
	int chars[30]; memset(chars, 0, sizeof(chars));
	string s; cin >> s;
	int num = 0;
	
	//2. Calculate number of distinct character
	for (char& temp : s)
	{
		if (chars[temp - 'a'] == false)
		{
			chars[temp - 'a'] = true;
			++num;
		}
	}

	//3. Get result
	cout << (num & 0x1 ? "IGNORE HIM!" : "CHAT WITH HER!");
	return 0;
}

