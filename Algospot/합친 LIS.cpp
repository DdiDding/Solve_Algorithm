#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int n, m;
int A[101], B[101];

//JLIS�� ���̸� ����Ѵ�.
int solve(int a, int b)
{
	int ret = 0;
	ll aa = (a == -1 ? -1 : A[a]);
	ll bb = (b == -1 ? -1 : B[b]);
	ll maxValue = max(aa, bb);

	for (int nextA = a + 1; nextA < n; nextA++)
	{
		if (maxValue < A[nextA])
		{
			ret = max(ret, solve(nextA, b) + 1);
		}
	}
	for (int nextB = b + 1; nextB < m; nextB++)
	{
		if (maxValue < B[nextB])
		{
			ret = max(ret, solve(a, nextB) + 1);
		}
	}
	return ret;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int c; cin >> c;
	for (int k = 0; k < c; k++)
	{
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> A[i];
		for (int i = 0; i < m; i++) cin >> B[i];

		solve(0, 0);
	}

	return 0;
}

/*
�ΰ��� ���� �κ� ������ ��ġ�� �ߺ����� �������� �����Ѱ� ��ģ ���� �κ� ����,
=��ĥ���� �ڵ����� ���ĵǰ� �ߺ����� ���޴� �����̳� Set �̿�


LIS�� ��ģ�ٰ� ���� ������ �ʴ�!
��� ���� �κ� ������ ���غ�����! - ��¥?

Ž�������� �ѹ� �����غ��� ���� ������?

�� ���ҷ� ������ �ִ� ���� �κ� ������ �����ص� �������� ������?

"���� �ڵ�"
1. for(A[0] ~ A[n]���� ������ �ִ� ���� �κ� ���� aa)
{
	1-1.for(B[0] ~ B[n] ���� ������ ���� �κ� ���� bb)
		{
			1-1-1. aa + bb ���� ����
		}
}


*/