#include<iostream>
using namespace std;

/*Question 2. Write an algorithm that if inorder and postorder of a tree are given then find its preorder traversal.
Test case:
 	char *post = "bca", *in = "bac";
	findPreorder(post, 0, in, 0, 3);
Output:
    abc
Test case:
    char *post="ba", *in="ba";
    findPreorder(post, 0, in, 0, 2);
Output:
    ab
Test case:
    char *post="ba", *in="ab";
    findPreorder(post, 0, in, 0, 2);
Output:
    ab
Test case:
    char *post="debfca", *in="dbeafc";
    findPreorder(post, 0, in, 0, 6);
Output:
    ab
*/
void findPreorder(char* post, int post_beg, char* in, int in_beg, int count){
	if(count==0)
		return;
	char root_val=post[post_beg+count-1];
	cout<<root_val;//getchar();
	if(count==1)
		return;
	int in_root_index = strchr(in, root_val)-in;
	findPreorder(post, post_beg, in, in_beg, in_root_index-in_beg);//left sub-tree
	findPreorder(post, in_root_index, in, in_root_index+1, in_beg+count-in_root_index-1);//right sub-tree
}