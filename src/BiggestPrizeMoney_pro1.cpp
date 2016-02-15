#include <iostream>
using namespace std;

int sol;
int ns;
int state[10][800];

int Swap(int x, int i, int j)
{
	int na[10] = { 0 };

	for (int k = ns - 1; k > -1; k--)
	{
		na[k] = x % 10;
		x /= 10;
	}

	int t = na[i];
	na[i] = na[j];
	na[j] = t;

	x = 0;
	for (int k = 0; k < ns; k++)
	{
		x = x * 10 + na[k];
	}
	return x;
}

void findmax(int x, int s)
{
	for (int i = 0; i < 800; i++)
	{
		if (state[s][i] == 0)
		{
			state[s][i] = x;
			break;
		}
		else if (state[s][i] == x) return;
	}

	if (s == 0)
	{
		if (x > sol) sol = x;
	}
	else
	{
		for (int i = 0; i < ns-1; i++)
			for (int j = i + 1; j < ns; j++)
			{
				findmax(Swap(x, i, j), s - 1);
			}
	}
}

int main()
{
	int n;
	cin >> n;

	for (int tc = 1; tc < 11; tc++)
	{
		sol = ns = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 800; j++)
				state[i][j] = 0;

		int x, s;
		cin >> x >> s;

		int t = x;
		while (t)
		{
			t /= 10;
			ns++;
		}

		findmax(x, s);
		cout << "#" << tc << " " << sol << endl;
	}
        return 0;
}
