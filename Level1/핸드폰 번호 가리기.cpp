#include <string>
#include <vector>
using namespace std;

string solution(string p) {
	for (int i = p.size() - 5; 0 <= i; --i)
	{
		p[i] = '*';
	}
	return p;
}