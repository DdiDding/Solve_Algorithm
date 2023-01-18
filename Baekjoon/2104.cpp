#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	return 0;
}

/*
a[i] + ... + a[j] * min(a[i] ~ a[j])

��Ž - ��� �κй迭���ؼ� �ִ� ���� 


3 1 6 = 10 * 1 = 10 
4 5 2 = 11 * 2 = 11

�κй迭���� �� ����, �� �������� ������ �ִ�.
���� �����°� �ִ� ��

�ּ� ���� �ö� ���

�ƴϸ� �ִ� ������?

*/

//��������
//�ð� ���⵵ : O(n log n + n)
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll arr[100'005];

ll solve(int s, int e)
{
	//�������
	if (s == e) return arr[s] * arr[s];

	//1. �ݰ������� �� ������ ū ���� ����
	int mid = (s + e) / 2;
	ll ret = max(solve(s, mid), solve(mid + 1, e));

	//2. �ּҷ� �߰��� ��ģ ����� ���� ���ϱ�
	int l = mid, r = mid + 1;
	ll std = arr[l] + arr[r];
	ll m = arr[l] < arr[r] ? arr[l] : arr[r];
	ret = max(ret, std * m);

	//3. �߰��� ��ģ ��쿡�� Ȯ���� ������ ���� ���ϱ�
	while (s < l || r < e)
	{
		//�� ����, ���������� Ȯ�� ���� ���� ���� ����
		ll lv = s < l ? std * min(arr[l - 1], m) : -1;
		ll rv = r < e ? std * min(arr[r + 1], m) : -1;

		//���������� Ȯ������ �� �� ���� ���
		if (lv < rv)
		{
			std += arr[++r];
			m = min(m, arr[r]);
		}
		//�������� Ȯ������ �� �� ���� ���
		else
		{
			std += arr[--l];
			m = min(m, arr[l]);
		}

		//�� ������Ʈ
		ret = max(ret, std * m);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}
	cout << solve(0, n - 1);
	return 0;
}
*/