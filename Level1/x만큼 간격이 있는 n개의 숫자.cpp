#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

vector<long long> solution(int x, int n) {
	vector<ll> answer = { x };

	while (--n)
		answer.push_back(answer.back() + x);

	return answer;
}