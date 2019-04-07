#include <stdio.h>

struct
{
	int data, next;
} input[100000];

int all_addr[100000];

int main()
{
	int head, n;
	scanf ("%d%d", &head, &n);

	for (int i = 0; i < n; i++)
	{
		int addr, data, next;
		scanf ("%d%d%d", &addr, &data, &next);
		input[addr].data = data;
		input[addr].next = next;
	}

	n = 0;
	for (int cur = head; cur != -1; cur = input[cur].next)
	{
		all_addr[n++] = cur;
	}

	head = all_addr[n - 1];

	for (int i = 0; i < n / 2; i++)
	{
		input[all_addr[n - i - 1]].next = all_addr[i];
		input[all_addr[i]].next = all_addr[n - (i + 1) - 1];
	}

	input[all_addr[n % 2 == 0 ? (n / 2 - 1) : (n / 2)]].next = -1;

	for (int cur = head; cur != -1; cur = input[cur].next)
	{
		printf (input[cur].next == -1 ? "%05d %d %d\n" : "%05d %d %05d\n", cur, input[cur].data, input[cur].next);
	}

	return 0;
	
}
