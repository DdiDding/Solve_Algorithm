#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
	string answer = "";
	string day[7] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
	int month[13] = { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int sum = 0;
	for (int i = 0; i < a; i++) {
		sum += month[i];
	}
	sum += b - 1;
	answer = day[sum % 7];
	return answer;
}

#include <bits/stdc++.h>

using namespace std;

string solution(int a, int b) {
	string answer[7] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };

	int mon = 0;
	if (0 < --a)
	{
		mon = a / 2 * 61;
		mon += a % 2 * 31;
		if (2 <= a) --mon;
	}

	return answer[(mon + b - 1) % 7];;
}

