#include <stdio.h>
#include <stdlib.h>

int compareStrings(const char *s, const char *t)
{
	int i;
	for (i = 0; s[i] != '\0' && t[i] != '\0'; i++)
	{
		if (s[i] > t[i])
		{
			return 1;
		}
		else if (t[i] > s[i])
		{
			return -1;
		}
	}

	if (s[i] > t[i])
	{
		return 1;
	}
	else if (t[i] > s[i])
	{
		return -1;
	}

	return 0;
}

int binarySearch(char** arr, char* s, int l, int r)
{
	while (l <= r)
	{
		int m = l + (r - l) / 2;
		if (compareStrings(arr[m], s) == 0)
		{
			return m;
		}
		else if (compareStrings(arr[m], s) < 0)
		{
			l = m + 1;
		}
		else
		{
			r = m - 1;
		}
	}
	return -1;
}

int main(void)
{
	char* arr[] = { "Daniel", "Edward", "Filip", "Grzegorz", "Henryk", "Ignacy", "Jan" };
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(arr[0]), compareStrings);
	char s[] = "Jan";
	int n = sizeof(arr) / sizeof(arr[0]);

	int indeks = binarySearch(arr, s, 0, n-1);
	printf("Napis %s znajduje sie pod indeksem %d", s, indeks);

	return 0;
}