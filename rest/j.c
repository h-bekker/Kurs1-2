#include <stdio.h>

main()
{
	int a[250000];
	int used[250000];
	int length, i, j, rans = 0, lans = 0, diff = 0;
	int k, n, l = 1, r = 0;

	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	length = n;
	for (i = 1; i <= 250000; ++i)
		used[i] = 0;
	while (r < n)
	{	
		while ((diff < k) && (r < n))
		{
			r++;
			used[a[r]]++;
			if (used[a[r]] == 1)
				diff++;
		}

		while ((diff == k) && (l <= n))
		{
			if ((r - l) < length)
			{
				length = r - l;
				lans = l;
				rans = r;
			}
			used[a[l]]--;
			if (used[a[l]] == 0)
				diff--;
			l++;
		}
	}	
	printf("%d %d\n", lans, rans);
}