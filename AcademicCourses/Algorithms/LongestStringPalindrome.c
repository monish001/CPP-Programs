//Time Complexity: Linear to the size of input string
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
// Simple linked list functions
typedef struct Node Node;
struct Node {
	int len;
	Node* next;
};
Node* insertNode(Node* head, Node* node) {
	node->next = head->next;
	head->next = node;
	return node;
}
Node* createNode(int len) {
	Node* newNode = (Node*) malloc(sizeof(Node));
	newNode->len = len;
	return newNode;
}
Node* insertNum(Node* head, int len) {
	return insertNode(head, createNode(len));
}
void printReverse(Node* node) {
	if (node != NULL) {
		printReverse(node->next);
		printf("%d ", node->len);
	}
}
void printReverseList(Node* head) {
	printReverse(head->next);
	printf("\n");
}
void cleanList(Node* head) {
	Node* curr = head;
	while (curr != NULL) {
		Node* next = curr->next;
		free(curr);
		curr = next;
	}
}
int main(int argc, char* argv[]) {
	char a[50]={0};
	scanf("%s", a);
	int n = 0;
	int len = strlen(a);
	int currTail = 0; // length of the longest tail palindrome
	Node* centers = createNode(0);
	centers->next = NULL;
	while (n < len) {
		if (n != currTail && a[n - currTail - 1] == a[n]) {
			n++;
			currTail += 2;
			continue;
		} 
		Node* center = centers->next;
		insertNum(centers, currTail);
		int centerDist = currTail;
		while (centerDist != 0 && center != NULL && centerDist - 1 != center->len) {
			centerDist--;
			insertNum(centers, center->len > centerDist ? centerDist : center->len);
			center = center->next;
		}
		if (centerDist == 0) {
			n++;
			currTail = 1;
		} else {
			currTail = center->len;
		}
	}
	Node* center = centers->next;
	insertNum(centers, currTail);
	while (currTail != 0) {
		currTail--;
		insertNum(centers, center->len > currTail ? currTail : center->len);
		center = center->next;
	}
	printReverseList(centers);
	cleanList(centers);
	return 0;
}
