/* Copyleft 2019 Zeng Xiangfei
 *
 * 线性表的合并和反转操作
 */

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int * merge_array(int * a, size_t naitems, int * b, size_t nbitems)
{
	int * dst = malloc((naitems + nbitems) * sizeof(int));
	size_t cur_a = 0, cur_b = 0, cur_dst = 0;
	while (cur_a < naitems && cur_b < nbitems)
	{
		if (a[cur_a] < b[cur_b])
		{
			dst[cur_dst++] = a[cur_a++];
		}
		else
		{
			dst[cur_dst++] = b[cur_b++];
		}
	}
	if (cur_a == naitems)
	{
		memcpy(dst + cur_dst, b + cur_b, sizeof(int) * (nbitems - cur_b));
	}
	else
	{
		memcpy(dst + cur_dst, a + cur_a, sizeof(int) * (naitems - cur_a));
	}
	return dst;
}

void reverse(int * array, size_t size)
{
	for (int i = 0; i < size / 2; i++)
	{
		int t = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = t;
	}
}

int main(int argc, char const *argv[])
{
	int a[] = { 1,3,5,7,9 };
	int b[] = { 2,4,6,8,10,12,23,45 };
	size_t naitems = sizeof a / sizeof a[0];
	size_t nbitems = sizeof b / sizeof b[0];
	int *c = merge_array(a, naitems, b, nbitems);
	reverse(c, naitems + nbitems);
	for (int i = 0; i < naitems + nbitems; i++)
	{
		printf("%d ", c[i]);
	}
	free(c);
	return 0;
}
