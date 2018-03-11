//  
//  prog2.c
//  OS_Problem-2
//

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include "node.c"

int x;
char c[200];
char s[200];
FILE* fp;

// reads the input file and places into c[n] array
void parse(char* filename){
	char line[10];
	FILE* fp;
	int n = 0;
	int i = 0;

	fp = fopen(filename, "r");

	//printf("Each Node saved in c[n] array: \n");
	while(fgets(line, 10, fp) != NULL){
		int z = -1;
		while(++z < strlen(line)){
			if((c[i] = line[z]) != ' '){
			i++;
			}
		}
	}
}

// every node
void first(char* filename){
	char line[10];
	FILE* fp;
	int n = 0;
	int i = 0;

	fp = fopen(filename, "r");
	//printf("Each Node saved in s[n] array: \n");
	while(fgets(line, 10, fp) != NULL){
		int z = -1;
		while(++z < strlen(line)){
			if((s[i] = line[z]) != ' '){
			i++;
			break;
			}
		}
	}

	/*while(s[n]){
		printf("%c\n", s[n]);
		n++;
	}*/
}

void rNode(tree_node *tn, int cn, char left, char right)
{
	
	printf("rloop start\n");
	if(tn->children_no == 0){
		printf("entered child 0\n");
		return;
	}
	else if(tn->children_no == 1){
		printf("entered child 1\n");
		fgets(s, 10, fp);
		x = s[2] - '0';
		tn->left = newNode(x,left);
		printf("%c's left node created: %c\n", tn->name, tn->left->name);
		tn->right = NULL;
		rNode(tn->left, x, s[4], s[6]); 
	}
	else if(tn->children_no == 2){
		printf("entered child 2\n");
		fgets(s, 10, fp);
		x = s[2] - '0';
		tn->left = newNode(x, left);
		printf("%c's left node created: %c\n", tn->name, tn->left->name);
		rNode(tn->left, x, s[4], s[6]); 
		fgets(s, 10, fp);
		x = s[2] - '0';
		tn->right = newNode(x, right);
		printf("%c's right node created: %c\n", tn->name, tn->right->name);
		rNode(tn->right, x, s[4], s[6]); 
	}
	printf("\none recursive loop\n");
}

void print_inorder(tree_node * tree) {
 if (tree) {
     print_inorder(tree->left);
     if (tree->left == NULL || tree->right == NULL)
       return;
     printf("%s<-[ %s]-> %s\n",tree->left->name,tree->name, tree->right->name);
     print_inorder(tree->right);
   }
}

int main()
{
	fp = fopen("input2.txt", "r");
	int n = 0;
	//values = malloc(100000*sizeof(int));
	//parse("input2.txt");
	//first("input2.txt");
	
	tree_node *root = NULL;
	//root = newNode(2,'A');
	//root->left = newNode(0, 'B');
	//printf("%c\n", root->left->name);
	//rNode(*root);
	//root = newNode(c[1],c[0]);
	//printf("children: %d nodename: %c\n", root->children_no,root->name);

	//traverse through the input array to find numbers
	while(c[n]){
		//printf("%c\n", c[n]);
		if(isdigit(c[n])){
			int x = c[n] - '0';
			printf("NUMBER: %d\n", x);
			//recursivenode()
			}
		n++;
	}
	// goes through c[n] array
	// recursively calls everytime sees ' '
/*
	while(c[n]){
		if(c[n] == '\n'){
			printf("new node\n");
			n++;
		}
		n++;
	}
*/
	int i = 0;

	while(!feof(fp)){
		fgets(s, 150, fp);
		x = s[2] - '0';
		printf("FIRST:%C CN: %d LEFT: %c RIGHT: %c\n", s[0], x, s[4], s[6]);
			if(!root){
				printf("\nroot created\n");
				root = newNode(x,s[0]);
				rNode(root, x, s[4], s[6]);
				printf("\nexits recursion ROOT\n");
			}
			else
				printf("root tree already exists\n");
				//print_inorder(root);
		}
	

	fclose(fp);
}
