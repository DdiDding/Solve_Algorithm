#include <bits/stdc++.h>
using namespace std;
vector<int> p;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t; cin >> t;
	while (t--)
	{
		//1. Get input value
		int n; cin >> n;
		int s; cin >> s;
		p.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> p[i];
		}
		
		//2. 
	}

	return 0;
}

/*
�սǾ���

1000������ �ڿ������ ������ ���� �ִ� S������ ������ ����ϵ��� ����ȭ �ϰ�ʹ�.
= �׷� ����ϴ°� S������ ������ �ȴٴ� ��?
���� ������ ��

1. ����Ž��
	1 ~ 1000���� 10���� �̴� ��� O(1��6õ) + 3���� ���� ���������� ã���� �Ǵϱ� O(n) (n<100��
�Ұ���

2. DP
	�� ������?

������
�� �������� ������.
solve(����) = ������ ���� ������ �ּ� ��


	
*/