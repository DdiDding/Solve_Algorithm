//Given a time in 12 - hour AM / PM format, convert it to military(24 - hour) time.
//12�ð��� Am/Pm���� �̷���� �ð��� �־����ϴ�. �̸� 24�ð� �������� ��ȯ�ϼ���

//Note: -12 : 00 : 00AM on a 12 - hour clock is 00 : 00 : 00 on a 24 - hour clock. - 12 : 00 : 00PM on a 12 - hour clock is 12 : 00 : 00 on a 24 - hour clock.
//�޸�: 12Am�� 0�÷�, 12pm�� 12�� �Դϴ�.

//Function Description
//Complete the timeConversion function in the editor below.It should return a new string representing the input time in 24 hour format.
//�Լ�����
//timeConversion �Լ��� �ϼ��ϼ���. �̴� ��ȯ�մϴ�. 24�ð� �������� �̷���� ���ο� string�� ��ȯ�ؾ��մϴ�.

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//���� �����ϰԺôٰ� ��~~~�� �����ɸ� ����..
//���� �����ϰ� Ǯ�ٰ� ����������..
//���ٰ� ���� Ǯ������...

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
