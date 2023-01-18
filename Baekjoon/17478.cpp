#include <iostream>
#include <string>
using namespace std;

string uBar = "____";

void Solve(const int & s, const int & e)
{
	string bar;
	for (int i = 0; i < s; ++i)
	{
		bar += uBar;
	}
	cout << bar << "\"����Լ��� ������?\""<<"\n";
	if (s < e)
	{
		cout << bar << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���." << "\n";
		cout << bar << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���." << "\n";
		cout << bar << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"" << "\n";

		Solve(s + 1, e);
	}
	else cout << bar << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"" << "\n";

	cout << bar << "��� �亯�Ͽ���." << "\n";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int e; cin >> e;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������." << "\n";
	Solve(0, e);
	return 0;
}