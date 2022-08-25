#include <iostream>
#include <unordered_set>

using namespace std;
unordered_set<int> S;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);
	
	int N; cin >> N;
	int temp;
	for (int i = 0; i < N; ++i)
	{
		cin >> temp;
		S.insert(temp);
	}

	int M,F; cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> F;
		cout << ((S.find(F) == S.end()) ? 0 : 1) << "\n";
	}

	return 0;
}