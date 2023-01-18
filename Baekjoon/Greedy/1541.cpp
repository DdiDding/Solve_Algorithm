#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

//Greedy적으로 접근하면 맨 처음부터 시작하여 나오는 -뒤로 +가 나온다면 괄호를 쳐서 붙여준다
//가장 처음과 마지막 문자는 숫자이다.

void GetNum(const string & str, vector<int> & numList)
{
	string element;
	for (const auto & data : str)
	{
		
		if (data == 43 || data == 45)
		{
			numList.push_back(stoi(element));
			element = data;
		}
		else element += data;
		
	}
	numList.push_back(stoi(element));
}

int main()
{
	string input;
	cin >> input;

	vector<int> numList;
	GetNum(input, numList);
	
	int result = 0;
	bool transSwitch = false;
	for (auto & data : numList)
	{
		if (data < 0) transSwitch = true;
		if (transSwitch == true && 0 < data) data *= -1;
		result += data;
	}

	cout << result;

	return 0;
}
