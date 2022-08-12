#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

#define MAX_PRICE 1000

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N, M; cin >> N >> M;
	int P = MAX_PRICE, I = MAX_PRICE;

	int p, i;
	while (M--)
	{
		cin >> p >> i;
		if (p < P) P = p;
		if (i < I) I = i;
	}

	//������ ������ ���� ������
	if (I * 6 <= P) cout << I * N;
	//��Ű���� �� ������ ������
	else
	{
		//��Ű���� ��� ���� ��Ÿ��
		int remainI = I * (N % 6);
		cout << P * (N / 6) + ((P < remainI) ? P : remainI);
	}
	return 0;
}