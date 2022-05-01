#include <iostream>
#include <string>
using namespace std;
string fuc(string a, string b, string c)
{
	string L = "0";
	string sum;
	sum = a + b + c;
	if (sum > L)
		L = sum;
	sum = a + c + b;
	if (sum > L)
		L = sum;
	sum = b + a + c;
	if (sum > L)
		L = sum;
	sum = b + c + a;
	if (sum > L)
		L = sum;
	sum = c + a + b;
	if (sum > L)
		L = sum;
	sum = c + b + a;
	if (sum > L)
		L = sum;
	return L;
}
int main()
{
	string a, b, c;
	while (cin >> a >> b >> c)
	{
		cout << fuc(a, b, c) << endl;
	}
}
