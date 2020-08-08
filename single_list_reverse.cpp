//单链表反转

struct TNode
{
	int val;
	struct TNode* next;
};


int reverse(struct TNode** head)
{
	if(*head == NULL) return 0;
		
	struct TNode* left = *head;
	struct TNode* cur = left->next;
	
	struct TNode* right = NULL;
	if(cur != NULL) right = cur->next;
	
	while(cur != NULL)
	{
		cur->next = left;
		left = cur;
		cur = right;
		
		if(right != NULL) right = right->next;
	}
	
	*head->next = NULL;
	*head = left;
	
	return 0;
}