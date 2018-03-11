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

int shmid;
int *values;
int size;
char c[200];
char s[200];

// reads the input file and places into c[n] array
void parse(char* filename){
	char line[10];
	FILE* fp;
	int n = 0;
	int i = 0;

	fp = fopen(filename, "r");

	//printf("Each Node saved in c[n] array: \n");
	while(fgets(line, 10, fp) != NULL){
		int x = -1;
		while(++x < strlen(line)){
			if((c[i] = line[x]) != ' '){
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
		int x = -1;
		while(++x < strlen(line)){
			if((s[i] = line[x]) != ' '){
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


//void traverse(char c){

void rNode(tree_node tn, int cn, char left, char right)
{
	printf("enters recursion\n");
	//printf("%d\n", tn.children_no);
	//printf("%c\n", tn.left->name);
	//printf("%d\n", tn.left->children_no);
	
	if(tn.children_no == 0){
		printf("entered child 0\n");
		return;
	}
	else if(tn.children_no == 1){
		printf("entered child 1\n");
		tn.left = newNode(cn, left);
		tn.right = NULL;
		//rNode(*tn.left); 
	}
	else if(tn.children_no == 2){
		printf("entered child 2\n");
		tn.left = newNode(cn, left);
		tn.right = newNode(cn, right);
		//rNode(*tn.left); 
		//rNode(*tn.right);
	}
	printf("exits recursion\n");
}

int main()
{
	FILE* fp;
	fp = fopen("input2.txt", "r");
	int n = 0;
	//values = malloc(100000*sizeof(int));
	parse("input2.txt");
	first("input2.txt");
	
	tree_node *root = NULL;
	//root = newNode(2,'A');
	//root->left = newNode(0, 'B');
	//printf("%c\n", root->left->name);
	//rNode(*root);
/*	//root = newNode(c[1],c[0]);
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

	while(c[n]){
		if(c[n] == '\n'){
			printf("new node\n");
			n++;
		}
		else if(c[n] == 'A'){
			printf("A is retreived\n");
			n++;
		}
		else if(c[n] == '1'){
			printf("number is seen\n");
			n++;
		}
		n++;
	}
*/

	char s[150];
	int i = 0;

	while(!feof(fp)){
		fgets(s, 150, fp);
		int x = s[2] - '0';
		printf("FIRST:%C CN: %d LEFT: %c RIGHT: %c\n", s[0], x, s[4], s[6]);
			if(root){
				printf("\nchild created\n");
				rNode(*root, x, s[4], s[6]);
			}
			else{
				printf("\nroot created\n");
				root = newNode(x,s[0]);
				rNode(*root, x, s[4], s[6]);
			}
	}

	
	fclose(fp);
}
