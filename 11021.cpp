#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	int N; cin >> N;
	int A, B;
	for (int i = 1; i <= N; ++i)
	{
		cin >> A >> B;
		cout << "Case #" << i << ": " << A + B << "\n";
	}
	return 0;
}