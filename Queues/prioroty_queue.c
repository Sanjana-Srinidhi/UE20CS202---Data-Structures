void enqueue(node **head, int data, int p)
{
	node *start = *head;
	node *temp = init(temp, d, p);
	if((*head)->p > p)
	{
		temp->next = *head;
		*head = temp;
	}
	else
	{
		while(start->next->p < p && start->next!=NULL)
		{
			start = start->next;
		}
		temp->next = start->next;
		start->next = temp;
}