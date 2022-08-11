#include<iostream>
#include<cstdio>
#include<ctime>
int main(void) {
	int L[1000] = { 0 };
	int P[1000] = { 0 };
	int V[1000] = { 0 };
	int N = 0;

	while (1)
	{
		std::cin >> L[N] >> P[N] >> V[N];

		if (L[N] == 0 && P[N] == 0 && V[N] == 0)
			break;
		N++;
	}

	int A[1000] = { 1 };
	int B[1000] = { 0 };
	for (int i = 0; i < N; i++)
	{
		while (1)
		{

			if ((P[i] * A[i] <= V[i]) && (P[i] * (A[i] + 1) > V[i]))
				break;
			A[i]++;
		}
		if (V[i] - A[i] * P[i] > L[i])
			B[i] = A[i] * L[i] + L[i];
		else
			B[i] = A[i] * L[i] + (V[i] - A[i] * P[i]);
		printf("Case %d: %d\n", i + 1, B[i]);
	}
	return 0;
}

//#include <iostream>
//using namespace std;
//typedef long long int lld;
//
//int main()
//{
//	ios::sync_with_stdio(0), cin.tie(0);
//	lld L, P, V;
//
//	for (int i = 1; true ; ++i)
//	{
//		cin >> L >> P >> V;
//		if (L + P + V == 0) return 0;
//
//		lld a, b;
//		a = V / P * L;
//		b = L < (V % P) ? L : (V % P);
//		cout << "Case " << i << ": " << a + b << "\n";
//	}
//
//	return 0;
//}