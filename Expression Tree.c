#include <stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct BTnode BTnode_t;
struct BTnode{
	int value;
	BTnode_t	*left;
	BTnode_t	*right;
	BTnode_t	*parent;
};

typedef struct BST {   BTnode_t* root; } BST_t;

enum {PLUS, MINUS, MULT, DIV};

BTnode_t* create_node(int val) {



 BTnode_t* newNode = (BTnode_t*) malloc(sizeof(BTnode_t));



 newNode->value = val;



 newNode->left = NULL;



 newNode->right = NULL;



 newNode->parent = NULL;







 return newNode;



}


BST_t* create_BST() {
   BST_t* tree = (BST_t*) malloc(sizeof(BST_t));
   tree->root = NULL;   
   return tree; 
}  
BTnode_t* find(BST_t* tree, int item) 
{   
	BTnode_t* current = tree->root;   
	while (current!=NULL)   
	{     
		if (current->value == item)
	       return current;     
		if (current->value > item)       
			current = current->left;     
		else       
			current = current->right;   
	}   // item not found   
	return NULL; 
}




void preOrder(BTnode_t* root) {



 if (root == NULL)



 return;



  



 printf("%d ", root->value);



 preOrder(root->left);



 preOrder(root->right);



}







void inOrder(BTnode_t* root) {



 if (root == NULL)



 return;



  



 inOrder(root->left);



 printf("%d ", root->value);



 inOrder(root->right);



}







void postOrder(BTnode_t* root) {



 if (root == NULL)



 return;



  



 postOrder(root->left);



 printf("%d ", root->value);



 postOrder(root->right);



}

char* stringToInt(int val){
	char arr[15];
	sprintf(arr,"%d",val);
	char* str=(char*)malloc(sizeof(char)*(strlen(arr)+1));
	sprintf(str,"%d",val);
	return str;
}
char* get_arithmetic_expression(BTnode_t* expression) {
	if(expression==NULL)
		return "";
	if(expression->left==NULL && expression->right==NULL){
		return stringToInt(expression->value);
	}
	char *left=get_arithmetic_expression(expression->left);
	char *right=get_arithmetic_expression(expression->right);
	int leftLen=strlen(left);
	int rightLen=strlen(right);
	int i=0,count=1;
	char* string = (char*)malloc(sizeof(char)*(leftLen+rightLen+8));
	string[0]='(';
	string[count++]=' ';
	for(i=0;i<leftLen;i++){
		// string[count++]=' ';
		string[count++]=left[i];
	}
	string[count++]=' ';
	if(expression->value==MULT)
	string[count++]='*';
	else if(expression->value==MINUS)
	string[count++]='-';
	else if(expression->value==PLUS)
	string[count++]='+';
	else if(expression->value==DIV)
	string[count++]='/';
	string[count++]=' ';
	for(i=0;i<rightLen;i++){
		string[count++]=right[i];
		// string[count++]=' ';
	}
	string[count++]=' ';
	string[count++]=')';
	string[count]='\0';
	return string;
}


int main(){



 BTnode_t* n125 = create_node(125);





 n125->parent = NULL;

 n125->left = NULL;

 n125->right = NULL;

 char correct_ans[] = "125";



 char* str = get_arithmetic_expression(n125);

 if (strcmp(str, correct_ans) == 0)  {

  printf("Q3-2 - ok\n");

  return true;

 }

 else {

  printf("Q3-2 - error\n");

  return true;

 }

}