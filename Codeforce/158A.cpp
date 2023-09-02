#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int n, k; cin >> n >> k;
	
	std::vector<int> scores;
	scores.resize(n);
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> scores[i];
		if (scores[k - 1] <= scores[i] && 0 < scores[i]) ++cnt;
	}

	cout << cnt;
	return 0;
}


/* k��°�� ���� �̻���(1�̻�) ������ ȹ���� �����ڴ� ���� ���忡 �����Ѵ�.
 * ��ȸ�� �� n���� �����ڰ� �־�����, �׸��� ����� �׵��� ������ �� �� �ִ�.
 * ��ŭ�� �����ڰ� ���� ���忡 �����ϴ��� ����ϼ���

 * Input : ù ��° ���� input�� �ΰ��� ���� n�� k�� ��ĭ �ϳ� ���̷� ����ִ�
 * �� ��° ���� n���� ������ �� ���´�
 */