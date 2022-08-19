#include <iostream>
#include <algorithm>

using namespace std;

double grade[1001];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	int N; cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> grade[i];
	}
	sort(grade, grade + N);

	double result = 0;
	for (int i = 0; i < N; ++i)
	{
		result += (grade[i] / grade[N-1]) * 100;
	}

	cout << result / N;
	return 0;
}