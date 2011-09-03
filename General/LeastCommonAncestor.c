//FileName: LeastCommonAncestor.c
//CONTENTS: 
	//1.LeastCommonAncestor
	//2.LargestBstInBinaryTree ->Incomplete
#include<stdio.h>

typedef struct node node;
struct node{
	int data;
	node *right, *left;
};
node* LeastCommonAncestor(node* root, const int data1, const int data2, int* const status){
    static node* ans = NULL;
    int l_st=0, r_st=0;
    if(root==NULL) return;
    if(root->left != NULL)
		LeastCommonAncestor(root->left, data1, data2, &l_st);
    if(root->right != NULL)
		LeastCommonAncestor(root->right, data1, data2, &r_st);
    if(l_st == 3 || r_st == 3)//if both data already found by subtrees
		return ans;
    if((l_st|r_st)==3){//if one data found in each subtree
        *status = 3; 
        ans=root; 
        return ans;
    }
    if( ((l_st|r_st)==2 && root->data == data1) || ((l_st|r_st)==1 && root->data == data2) ){ 
        //if one data found in subtree and other is root itself
        ans = root; 
        *status =3;}
    else//record if any one data found (case when both data found is catered above) 
        *status |= l_st |= r_st;
    if(root->data == data1)
		*status |= 1;
    if(root->data == data2)
		*status |= 2;
	return ans;
}
inline node* newNode(){
	return (node*)malloc(sizeof(node));
}
node* makeTree(){
	char choice;
	puts("Enter the data of new node..");
	node * mynode = newNode();
	fscanf(stdin, "%d", &mynode->data);
	printf("Left child of %d exists 0/1 ? ", mynode->data);
	fflush(stdin); fscanf(stdin, "%c", &choice);
	mynode->left = (choice!='1')?((node*)0):(makeTree());
	printf("Right child of %d exists 0/1 ? ", mynode->data);
	fflush(stdin); fscanf(stdin, "%c", &choice);
	mynode->right = (choice!='1')?((node*)0):(makeTree());
}
void inOrderTraversal(node* root){
	if(root==NULL)
		return;
	if(root->left != NULL)
		inOrderTraversal(root->left);
	printf("%d ", root->data);
	if(root->right != NULL)
		inOrderTraversal(root->right);
}
void freeTree(node* root){
    if(root == NULL)    return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}
node* findBST(node* root, int* length){//root is not null always
	node *lbst=NULL, *rbst=NULL;
	int lht=0, rht=0;
	if(root->left != NULL)
		lbst = findBST(root->left, &lht);
	if(root->right != NULL)
		rbst = findBST(root->right, &rht);
	if( ((root->left!=NULL)?((root->left == lbst) && (root->data > lbst->data)):(1)) && ((root->right!=NULL)?((root->right == rbst) && (root->data < rbst->data)):(1)) ){//if both sub-trees are BST and root also satifies the property of BST
		*length = 1+((lht>rht)?(lht):(rht));
		return root;
	}
	if(rht>lht){
		*length = rht;
		return rbst;
	}
	*length = lht;//return left subtree if BST of same ht found in each sub-tree of root
	return lbst;
}
node* findLargestBST(node* root){
	if(root==NULL)
		return NULL;
	int ht = 0;
	return (node*)findBST(root, &ht);
}
main(){
	node *head=NULL;
	int flag=1;
    puts("          ----\n          MENU\n          ----\nPress 1 to create new tree\nPress 2 to see Inorder Traversal");
    puts("Press 3 to find Least Common Ancestor\nPress 4 for largest sub-tree as BST\nPress 0 to exit\n-------------------------------------");
	while(flag){
	    char choice;
        printf("Enter your choice..");
        fflush(stdin); fscanf(stdin, "%c", &choice);
        switch(choice){
            case '0':
            flag=0;
            break;
            case '1':{
				char c='y';
				if(head != NULL){
					do{
						fputs("Previously entered tree would be lost. Continue y/n ? ", stdout);
						fflush(stdin);
						scanf("%c", &c);
						char tmp = tolower(c);
						c = tmp;
					}while(c != 'y' || c!='n');
				}
				if(c=='y'){
						freeTree(head);
						head = makeTree();
				}
			}
            break;
            case '2':
            fprintf(stdout, "Inorder Traversal: "); inOrderTraversal(head); puts("");
            break;
            case '3':
            {
            fprintf(stdout, "Enter data of 2 nodes for which to find Least Common Ancestor.. ");
            int d1, d2;
            fflush(stdin); fscanf(stdin, "%d %d", &d1, &d2); 
            int status=0;
            node* ans = LeastCommonAncestor(head, d1, d2, &status);
            fprintf(stdout, "Least Common Ancestor is: "); 
			(ans!=NULL)?fprintf(stdout, "%d\n", ans->data):fputs("<INPUT DATA NOT FOUND>\n", stdout);
            }
			break;
			case '4'://Largest BST
            {
			node *temp_tree = findLargestBST(head);
			if(temp_tree!=NULL){
				fprintf(stdout, "Inorder Traversal of largest BST found: "); 
				inOrderTraversal(temp_tree);
				fputs("\n", stdout);
			}else fputs("Input tree is empty!!\n", stdout);
			}
			
        }
	}
//	getch();
}
