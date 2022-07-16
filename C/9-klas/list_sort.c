// sorts list

struct list
{
	struct list* next;
	unsigned data;
};
enum bool{ false, true };

struct list* list_cat(struct list* a, struct list* b)
{
	if (!a)return b;
	if (!b)return a;
	struct list* n = a;
	while (n->next)
		n = n->next;
	n->next = b;
	return a;
}

enum bool create(struct list** stack)
{
	*stack = 0;
}

enum bool push(struct list** a, int elem)
{
	void* p = malloc(sizeof * *a);
	if (!p)return false;
	struct list* rem_last = *a;
	*a = p;
	(*a)->data = elem;
	(*a)->next = rem_last;
	return true;
}

struct list* sort_list(struct list* unsorted, unsigned mask)
{
	if (!mask || !unsorted)
		return unsorted;

	struct list* list1, * list0;
	create(&list1);
	create(&list0);
	for (; unsorted; unsorted = unsorted->next)
	{
		if (unsorted->data & mask) push(&list1, unsorted->data);
		else push(&list0, unsorted->data);
	}
	return list_cat(sort_list(list0, mask >> 1), sort_list(list1, mask >> 1));
}

void main()
{
	struct list a1 = { 0, 001 }, a2 = {&a1, 101}, a3 = { &a2, 111}, a4 = { &a3, 101}, a5 = { &a4, 011}, a6 = { &a5, 100};
	sort_list(&a4, 1u << 3 * sizeof(unsigned) - 1);
}