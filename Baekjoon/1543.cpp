#include <iostream>
#include <string>

using namespace std;

string str;
string f_str;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0);

	getline(std::cin, str);
	getline(std::cin, f_str);

	int d_length = str.length();
	int f_length = f_str.length();

	int cnt = 0;
	int result;
	while ((result = str.find(f_str)) != string::npos)
	{
		++cnt;
		str = str.substr(result + f_length, d_length);
	}
	cout << cnt;
	return 0;
}

//더 나은 다른사람의 코드
//int a;
//int main() 
//{
//	string s, y;
//	getline(cin, s); getline(cin, y); 
//	auto pos = s.find(y); 
//	
//	while (pos != string::npos)
//	{
//		a++;
//		cout << "pos + y.size() 값은 : " << pos + y.size() << endl;
//		pos = s.find(y, pos + y.size());
//		cout << pos << "이다." << endl<<endl;
//	}
//	cout << a; 
//}