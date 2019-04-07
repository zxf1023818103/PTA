/* Copyleft 2019 Zeng Xiangfei
 *
 * 链表创建、释放、合并和反转操作。
 */

#include <stdio.h>
#include <stdlib.h>

struct list_node
{
	int data;
	struct list_node * next;
};

/// 递归创建链表
struct list_node * create_list(int * data_array, size_t item_size)
{
	if (item_size == 0)
	{
		return NULL;
	}

	struct list_node * head = malloc(sizeof(struct list_node));
	head->data = data_array[0];
	head->next = create_list(data_array + 1, item_size - 1);
	return head;
}

/// 递归释放链表
void release_list(struct list_node * head)
{
	if (head == NULL)
	{
		return;
	}

	release_list(head->next);
	free(head);
}

/// for 循环输出链表
void print_list(struct list_node * head)
{
	struct list_node * cur;
	for (cur = head; cur != NULL; cur = cur->next)
	{
		printf(cur->next == NULL ? "%d\n" : "%d ", cur->data);
	}
}

/// 递归合并链表
struct list_node * inplace_merge_list(struct list_node * a, struct list_node * b)
{
	/// 第一种情况，至少有一条空链表
	if (a == NULL)
	{
		return b;
	}
	else if (b == NULL)
	{
		return a;
	}

	/// 第二种情况，一个单节点和一条多节点链表
	if (a->next == NULL || b->next == NULL)
	{
		struct list_node * src;
		struct list_node * node;

		if (a->next == NULL)
		{
			src = b;
			node = a;
		}
		else
		{
			src = a;
			node = b;
		}

		if (node->data < src->data)
		{
			node->next = src;

			return node;
		}
		else
		{
			struct list_node * insert_after;

			struct list_node * cur = src;
			while (cur != NULL && cur->data <= node->data)
			{
				insert_after = cur;
				cur = cur->next;
			}
			insert_after->next = node;
			node->next = cur;

			return src;
		}
	}

	/// 第三种情况，也就是一般情况，两条链表都至少有多个节点
	struct list_node * greater_head; // 首元素较大的一条链表
	struct list_node * less_head; // 首元素较小的一条链表
	struct list_node * insert_after; // 首元素大的链表头节点将被插入在该节点后，换句话说就是开始合并链表的位置

	if (a->data < b->data)
	{
		greater_head = b;
		less_head = a;
	}
	else
	{
		greater_head = a;
		less_head = b;
	}

	struct list_node * cur = less_head;
	while (cur != NULL && cur->data <= greater_head->data)
	{
		insert_after = cur;
		cur = cur->next;
	}

	/// 确定了链表头节点的插入位置，也就是合并位置之后，我们可以把合并位置之后的链表节点当作一个子链表。
	/// 如此往复操作，当不能再进行合并时，我们就可以把这第三种情况归并为第一种情况和第二种情况。
	/// 最后，层层递归返回的就是全部合并完成的链表。
	insert_after->next = inplace_merge_list(insert_after->next, greater_head);

	return less_head;
}

/// 递归反转链表
struct list_node * reverse_list(struct list_node * head)
{
	if (head == NULL)
	{
		return NULL;
	}

	if (head->next == NULL)
	{
		return head;
	}

	struct list_node * old_head_next = head->next;
	struct list_node * new_head = reverse_list(old_head_next);
	old_head_next->next = head;
	head->next = NULL;
	return new_head;
}

int main()
{
	int a_array[] = { 1,3,5,7,9 };
	int b_array[] = { 2,4,6,8,10,12,24,54,56 };
	struct list_node * a = create_list(a_array, sizeof a_array / sizeof(int));
	struct list_node * b = create_list(b_array, sizeof b_array / sizeof(int));
	print_list(a);
	print_list(b);
	struct list_node * result = inplace_merge_list(a, b);
	result = reverse_list(result);
	print_list(result);
	release_list(result);
	return 0;
}
