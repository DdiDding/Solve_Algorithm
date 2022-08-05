#include <iostream>
#include <string>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N;
	cin >> N;

	//string?
	int temp;
	for (int i = 1; i < N; ++i)
	{
		temp = i
			+ i / 1'000'000
			+ i % 1'000'000 / 100'000
			+ i % 100'000 / 10'000
			+ i % 10'000 / 1'000
			+ i % 1'000 / 100
			+ i % 100 / 10
			+ i % 10;

		if (temp == N)
		{
			cout << i;
			return 0;
		}
	}

	cout << 0;
	return 0;
}


int n, i, s, p, t; 
main() 
{
	for (scanf("%d", &n); ++i < n && !p; s = p = s + i - n ? 0 : i)
		for (t = i; t; t /= 10)s += t % 10; printf("%d", p); 
}

main()
{
	int N, a = 0, i, s, j;
	std::cin >> N; 

	for (s = i = ((N - 54) ? N - 54 : 1); i < N;) 
	{
		for (j = i; j; j /= 10)
		{
			s += (j % 10);
		}
		(N == s) ? N = a = i : s = ++i; 
	}
	std::cout << a; 
}