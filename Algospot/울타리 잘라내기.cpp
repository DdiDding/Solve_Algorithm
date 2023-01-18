#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

//l ~ r ������ ���� ū ���簢���� ��ȯ�Ѵ�.
int solve(int l, int r, const vector<int> & h)
{
	if (l == r) return h[l];

	int m = (l + r) / 2;
	int ret = max(solve(l, m, h), solve(m + 1, r, h));


	//��ġ�� �簢��
	int lo = m, hi = m + 1;
	int height = min(h[lo], h[hi]);

	//��ġ�� �����ڰ� ���� Ŭ ����� ó��
	ret = max(ret, height * 2);

	while (l < lo || hi < r)
	{
		if (hi < r && (lo == l || h[lo - 1] < h[hi + 1]))
		{
			height = min(height, h[++hi]);
		}
		else
		{
			height = min(height, h[--lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
	}

	return ret;
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> h;
		for (int i = 0; i < n; ++i)
		{
			int temp; cin >> temp;
			h.push_back(temp);
		}
		cout << solve(0, h.size() - 1, h) << '\n';
	}
	return 0;
}
/*
���� Ž�� ���
int solve(const vector<int>& h)
{
	int ret = 0;
	int n = h.size();

	for (int left = 0; left < n; ++left)
	{
		int height = h[left];

		for (int right = left; right < n; ++right)
		{
			height = min(height, h[right]);
			ret = max(ret, (right - left + 1) * height);
		}
	}
	return ret;
}

int main()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> h;
		for (int i = 0; i < n; ++i)
		{
			int temp; cin >> temp;
			h.push_back(temp);
		}

	}
	return 0;
}
*/