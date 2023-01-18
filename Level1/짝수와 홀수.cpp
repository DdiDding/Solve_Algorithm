#include <string>
#include <vector>

using namespace std;

string solution(int num) {
	return (num & 0x1 == 0x01) ? "Odd" : "Even";
}