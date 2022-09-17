#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> v;
priority_queue<int,vector<int>,greater<int>> p;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	int s, e;
	for (int i = 0; i < n; ++i)
	{
		cin >> s >> e;
		v.push_back({ s, e });
	}
	sort(v.begin(), v.end());

	size_t answer = 1;
	p.push(0);
	for (const auto & d : v)
	{
		if (p.top() <= d.first)
		{
			p.pop();
		}
		p.push(d.second);

		answer = max(answer, p.size());
	}

	cout << answer;
	return 0;
}

/*
������û
N���� ����
���� �ð� : Si ~ Ti

�ּ��� ���ǽ��� ����ؼ� ��� ������ �����ϰ�?

1	2	3	4	5		//0��
	2	3	4			//1��
		3	4	5		//1��
			4	5	6	7	8
				5	6g
					6	7
					6	7	8

7
1 5
2 4
3 5
4 8
5 6
6 7
6 8

3
1 2
2 3
3 4
				
-
5
5
8

�ΰ��� ��ġ���� Ȯ�� ����
���۽ð��� ���� ���̻��̴� �ϸ� �ٲ�

�ϴ� S�� �������� ����

�ִ�� ��ġ�°� ���� �ƴұ�? 
��ġ�� ������ 
if(��ġ�� ���� == true)

�ش� ���� = X
X�� �� �ð��� ���۽ð��� ���� �������� ã�´�.

������ ��´�.

���ð��� 

�����ð��� �����ͺ���?

*/