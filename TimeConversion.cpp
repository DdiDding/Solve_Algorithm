//Given a time in 12 - hour AM / PM format, convert it to military(24 - hour) time.
//12시간과 Am/Pm으로 이루어진 시간이 주어집니다. 이를 24시간 포맷으로 변환하세요

//Note: -12 : 00 : 00AM on a 12 - hour clock is 00 : 00 : 00 on a 24 - hour clock. - 12 : 00 : 00PM on a 12 - hour clock is 12 : 00 : 00 on a 24 - hour clock.
//메모: 12Am은 0시로, 12pm은 12시 입니다.

//Function Description
//Complete the timeConversion function in the editor below.It should return a new string representing the input time in 24 hour format.
//함수설명
//timeConversion 함수를 완성하세요. 이는 반환합니다. 24시간 포멧으로 이루어진 새로운 string을 반환해야합니다.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//존나 만만하게봤다가 존~~~나 오래걸린 문제..
//설계 대충하고 풀다가 지랄났었다..
//쉽다고 대충 풀지말자...

#include <bits/stdc++.h>

using namespace std;

void tokenizerTimeformat(vector<string> & time, bool & isAm, string & str)
{
	string tempStr = str;
	const string delimiter = ":";
	size_t pos = 0;

	string tempdegit = "";
	for (int i = 0; i < str.length(); ++i)
	{
		if (isdigit(str[i]) == 0)
		{//is character not degit
			if (tempdegit.length() != 0)
			{
				time.push_back(tempdegit);
				tempdegit = "";
			}
		}
		else
		{
			tempdegit += str[i];
		}
	}

	if (tempStr[8] == 'A') isAm = true;
	if (tempStr[8] == 'P') isAm = false;
}


string timeConversion(string s)
{
	vector<string> time_s(0);
	vector<int> time_i(0);
	bool isAm = false;
	tokenizerTimeformat(time_s, isAm, s);
	cout << "isAM : " << isAm << endl;

	for (auto data : time_s)
	{
		time_i.push_back(stoi(data));
	}

	if (isAm == false)
	{//isPM
		time_i[0] += 12;
		if (24 <= time_i[0])
		{
			time_i[0] -= 12;
		}
	}
	if (isAm == true)
	{
		if (12 <= time_i[0])
		{
			time_i[0] = 0;
		}
	}

	time_s[0] = to_string(time_i[0]);
	if (time_s[0].length() < 2)
	{
		time_s[0] = "0" + time_s[0];
	}

	return time_s[0] + ":" + time_s[1] + ":" + time_s[2];
}

int main()
{
	ofstream fout(getenv("OUTPUT_PATH"));

	string s;
	getline(cin, s);

	string result = timeConversion(s);

	fout << result << "\n";

	fout.close();

	return 0;
}
