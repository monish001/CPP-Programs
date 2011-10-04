/* FileName: SortLinkList.c
 * Question1: Write a method to combine two two sorted linked list into one in sorted form with out using temporary Node.
 * void mergeSorted(Node* list1,Node* list2)
 * Question2: Sort using Insertion Sort
 * node* insertionSort(node* head)
 * Question3: Given a singly linked list, swap every two elements (e.g. a->b->c->d->e->f->null should become b->a->d->c->f->e->null).
 * node* swapAdjacentNodes(node* head)
 */
#include<stdio.h>
typedef struct node node;
typedef int T;
struct node{
	T data;
	node* next;
};
node* createNode(T val){
	node* tmp = (node*)malloc(sizeof(node));
	tmp->data = val;
	tmp->next = NULL;
	printf("Node created with data %d\n", val);
	return tmp;
}
node* createSinglyLinkList(){
	int val=0;
	node *head = NULL;
	fflush(stdin);
	scanf("%d", &val);
	if(val==0)
		return NULL;
	node* tmp = createNode(val);
	head = tmp;
	do{
		fflush(stdin);
		scanf("%d", &val);
		if(val==0)
			break;
		tmp->next = createNode(val);
		tmp = tmp->next;
	}while(1);
	
	return head;
}
/*
 *Input lists are altered.
 */
node* mergeSorted(node*l1, node*l2){//assuming lists are ascending
	node *ans;
	if(l1==NULL){
		ans = l1 = l2;
	}else if(l2==NULL){
		ans = l2 = l1;
	}else{
		node *ptr;
		if(l1->data > l2->data){
			ptr = ans = l2;
			l2 = l2->next;
		}else{
			ptr = ans = l1;
			l1 = l1->next;
		}
		do{
			if(l1->data > l2->data){
				ptr->next = l2;
				l2 = l2->next;
			}else{
				ptr->next = l1;
				l1 = l1->next;
			}
			ptr = ptr->next;
		}while(l1 != NULL && l2 != NULL);
		ptr->next = mergeSorted(l1, l2);
	}
	return ans;
}
void printLinkedList(node* head){
	while(head != NULL){
		printf("%d ", head->data);
		head = head->next;
	}
	puts("");
}
node* _insert(node *head, node *aNode){//head is never NULL
	if(head->data > aNode->data){
		aNode->next=head;
		return aNode;
	}
	node* start = head;
	while(head->next != NULL && head->next->data <= aNode->data){
		head = head->next;
	}
	aNode->next = head->next;
	head->next = aNode;
	return start;
}
node* insertionSort(node* head){//insertion sort
	if(head==NULL || head->next == NULL)
		return head;
	node* tmpHead = head;
	tmpHead = tmpHead->next;
	head->next = NULL;
	while(tmpHead!=NULL){
		node* aNode = tmpHead;
		tmpHead=tmpHead->next;
		aNode->next = NULL;
		head = _insert(head, aNode);
	}
	return head;
}
int _swapNextTwoNodes(node* head){//swaps nodes pointed by head->next and head->next->next
	if(head==NULL || head->next==NULL || head->next->next == NULL)
		return 0;
	node* tmp=head->next, *tmp2 = head->next->next;
	head->next = tmp2;
	tmp->next = tmp2->next;
	tmp2->next = tmp;
	return 1;
}
node* swapAdjacentNodes(node* head){
	if(head == NULL || head->next == NULL)
		return head;
	node* tmp = head->next;
	//swap first two nodes and make head point to 2nd node in list after the swap
	head->next = tmp->next;
	tmp->next = head;
	while(_swapNextTwoNodes(head))
		head = head->next->next;
	return tmp;
}
int main(){
/*	puts("Press 0 to exit. Enter positive values for link list 1");
	node* l1 = createSinglyLinkList();
	l1=insertionSort(l1);
	printLinkedList(l1);

	puts("Press 0 to exit. Enter positive values for link list 2");
	node* l2 = createSinglyLinkList();
	l2=insertionSort(l2);
	printLinkedList(l2);
	
	printLinkedList(mergeSorted(l1, l2));*/


	puts("Press 0 to exit. Enter positive values for link list");
	node* l3 = createSinglyLinkList();
	printLinkedList(swapAdjacentNodes(l3));
	
	getch();
	return 0;
}
