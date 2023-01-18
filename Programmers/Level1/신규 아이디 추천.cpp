#include <bits/stdc++.h>
using namespace std;

bool myUnique(const int & a, const int & b)
{
	if (a == '.') return a == b;
	return false;
}

string solution(string new_id) {
	string answer = "";

	for (auto & d : new_id)
	{
		if ('A' <= d && d <= 'Z')
			answer += tolower(d);
		else if (d == '-' || d == '_' || d == '.' || ('0' <= d && d <= '9') || ('a' <= d && d <= 'z'))
			answer += d;
	}

	answer.erase(unique(answer.begin(), answer.end(), myUnique), answer.end());

	if (answer.front() == '.') answer.erase(answer.begin());
	if (answer.back() == '.') answer.pop_back();

	if (answer.size() == 0) answer = "a";

	if (16 <= answer.size()) answer.resize(15);
	if (answer.back() == '.') answer.erase(answer.end() - 1);

	while (answer.size() <= 2) answer += answer.back();

	return answer;
}