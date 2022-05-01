#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Fraction
{
	long up, down, left;
};

int change(int left, int up, int down)
{
	if (left == 0)
		return up;
	else
		return up + down * left;
}

Fraction Add(Fraction a, Fraction b)
{
	Fraction c;
	a.up = change(a.left, a.up, a.down);
	b.up = change(b.left, b.up, b.down);
	c.up = a.up * b.down + a.down * b.up;
	c.down = a.down * b.down;
	return c;
}
Fraction minu(Fraction a, Fraction b)
{
	Fraction c;
	a.up = change(a.left, a.up, a.down);
	b.up = change(b.left, b.up, b.down);
	c.up = a.up * b.down - a.down * b.up;
	c.down = a.down * b.down;
	return c;
}
Fraction multi(Fraction a, Fraction b)
{
	Fraction c;
	a.up = change(a.left, a.up, a.down);
	b.up = change(b.left, b.up, b.down);
	c.up = a.up * b.up;
	c.down = a.down * b.down;
	return c;
}
Fraction divide(Fraction a, Fraction b)
{
	Fraction c;
	a.up = change(a.left, a.up, a.down);
	b.up = change(b.left, b.up, b.down);
	c.up = a.up * b.down;
	c.down = a.down * b.up;
	return c;
}

int main()
{
	Fraction x, y, ans;
	string sign;
	while (cin >> x.left >> x.up >> x.down >> sign >> y.left >> y.up >> y.down)
	{
		if (sign == "+")
			ans = Add(x, y);
		else if (sign == "-")
			ans = minu(x, y);
		else if (sign == "*")
			ans = multi(x, y);
		else
			ans = divide(x, y);
		int gcb = __gcd(ans.up, ans.down);
		ans.left = ans.up / ans.down;
		ans.up = ans.up % ans.down;
		if (ans.up == 0)
			cout << ans.left << endl;
		else
			cout << ans.left << " " << ans.up / gcb << " " << ans.down / gcb << endl;
	}
}
