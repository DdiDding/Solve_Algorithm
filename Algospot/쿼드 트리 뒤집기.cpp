#include <iostream>
#include <queue>
#include <string>
using namespace std;

string str;

//���� ���� Ʈ���� �� 4�и� string�� ���ϰ� �� �����Ͽ� ��ȯ�Ѵ�!
//�Һ��� : ���������� x�� ����.
string Solve(string::iterator& it, int lev)
{
	//base case : 1ĭ�϶�, �� ���� ��찡 �ִ�.
	//1)�ּҷ����϶��� 1ĭ, 2)�ּҷ����� ���� �ʾ��� ���� ��ĭ
	if (lev == 0 || it + 1 == str.end())
	{
		return string(1, *(it++));
	}

	//1. �� 4�и��� ���ڿ� ����
	string temp[4];
	for (int i = 0; i < 4; ++i)
	{
		temp[i] = *(it++);
		if (temp[i] == "x")
		{
			temp[i] += Solve(it, lev - 1);
		}
	}

	//2. �� �ռ��� ��ȯ
	return temp[2] + temp[3] + temp[0] + temp[1];
}


int main()
{
	int n; cin >> n;
	while (n--)
	{
		//1. Input value
		cin >> str;

		//2. Do solve
		string::iterator it= str.begin();
		string ret(1, *(it++));
		if (ret[0] == 'x') ret += Solve(it, 20);
		cout << ret << "\n";
	}
	return 0;
}
/*
�־��� ������ �׻� 4���� �����Ѵ�.

2^N * 2^N�� ũ���� �׸���

��� �ȼ��� ���� ���� ��� = b
��� �ȼ��� ��	���� ��� = w
���� ���� �ƴ϶�� 4����� �� ���� �Ͽ� ��ģ��.
��ġ�� ������ [ x + ������� + ������� + �����ϴ� + �����ϴ� ]�̴�.

���Ϲ����� �� �ʿ� ����, ��ġ�� ������ �ٸ��� �ϸ� ���Ϲ��� ó�� ������ ������?
[x + �����ϴ� + �����ϴ� + ������� + ������� ]


*/
