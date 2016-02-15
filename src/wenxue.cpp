#include <iostream>

using namespace std;

int countelement(int* first, int* last, int elem)
{
	int count = 0;
	while (first < last)
	{
		if (*first == elem)
			count++;
		first++;
	}
	return count;
}
int countmax(int* first, int* last, int& max)
{
	int* iter = first;
	max = *first;
	int count = 1;
	while (++iter < last)
	{
		if (*iter > max)
		{
			count = 1;
			max = *iter;

		}
		else if (*iter == max)
		{
			count++;
		}
	}
	return count;
}
int collectfromtail(int* b, int* last, int swapcount, int max)
{
	int result = 0;
	last--;
	for (int i = 0; i < swapcount; i++)
	{
		while (*last == max)
			last--, result++;
		b[i] = *last;
		*last = max;
		last--;
		result++;
	}
	return result;
}
void sort(int count, int* data)
{
	for (int i = 0; i < count-1; i++)
		for (int j = 0; j < count-1-i; j++)
			if (data[j]>data[j+1])
			{
				int tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
}
void replace(int swapcount, int* b, int* a, int max)
{
	while (swapcount-- > 0)
	{
		while (*a != max) a++;
		*(a++) = *(b++);
	}
}
void fill(int *first, int *last, int val)
{
	while (first < last)
		*(first++) = val;
}
int finddup(int* first, int* last)
{
	int count[10];
	fill(count, count + 10, 0);
	while (first < last)
	{
		if (*first < 10 && *first >= 0)
			count[*first]++;
		if (count[*first]>1)
			return true;
		first++;
	}
	return false;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int caseno, a[10], b[10], n, count = 0, dup=false;
		cin >> a[0] >> n;
		while (a[count]>0)
		{
			a[count + 1] = a[count] / 10;
			a[count] = a[count] % 10;
			count++;
		}
		int tail = count;
		while (n>0 && tail>0)
		{
			int max, mcount=countmax(a, a+tail, max);
			int mcountinc = countelement(a + tail - mcount, a + tail, max);
			if (mcount > 1) dup=true;
			int swapcount = mcount - mcountinc;
			if (swapcount > n) swapcount = n;
			if (swapcount > 0)
			{
				int tailcount = collectfromtail(b, a + tail, swapcount, max);
				sort(swapcount, b);
				replace(swapcount, b, a, max);

				n -= swapcount;
				tail -= tailcount;
			}
			else
				tail -= mcountinc;
		}
		if (n % 2)
		{
			if (a[0] < a[1])
			{
				if (!dup)
					if (!finddup(a, a + tail))
					{
						int tmp = a[0];
						a[0] = a[1];
						a[1] = tmp;
					}
			}
		}
		cout << "#" << test_case << ' ';
		for (int i = 0; i<count; i++)
			cout << a[count - 1 - i];
		cout << endl;
	}

	return 0;
}
