//  
//  prog2.c
//  OS_Problem-2
//

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include "node.c"

int x;
int j = 0;
char c[1000];
char s[200];
char savedstrings[1000];
//int sn = 0;
FILE* fp;

// reads the input file and places into c[n] array
void parse(char* filename){
	char line[20];
	FILE* fp;
	int n = 0;
	int i = 0;

	fp = fopen(filename, "r");

	//printf("Each Node saved in c[n] array: \n");
	while(fgets(line, 20, fp) != NULL){
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

tree_node rNode(tree_node *tn, int cn, char left, char right)
{
		//Pipes may be added but will
		//prevent 
		
	// if tree node has no children sleep and return *tn
	if(!tn->children_no){
		sleep(3);
		tn->left = NULL;
		tn->right = NULL;
		printf(" - - SLEEPING - - HIT LEAF NODE - - SLEEPING - -\n");
		
		return *tn;
	}
	// If tree node has children fork
	else if(tn->children_no){
		pid_t piddy = fork();
		//fork error
		if(piddy<0){
			perror("fork() error");
			exit(-1);
		}
		//PARENT PROCESS: wait on child
		if(piddy!=0){
			printf("I'm in the parent %d, my child is %d\n", getpid(), piddy);
			wait(NULL);
		//CHILD PROCESS: execute recursive code
		}else{
			printf("I'm the child %d, my parent is %d\n", getpid(), getppid());
		if(tn->children_no == 1){
			//printf("entered node with 1 child  %c:\n\n", tn->name);
			fgets(s, 10, fp);
			x = s[2] - '0';
			tn->left = newNode(x,left);
			//printf("%c's LEFT node created: %c\n", tn->name, tn->left->name);
			tn->right = NULL;
			rNode(tn->left, x, s[4], s[6]); 
		}
		else if(tn->children_no == 2){
			//printf("entered node with 2 children  %c:\n\n", tn->name);
			fgets(s, 10, fp);
			x = s[2] - '0';
			tn->left = newNode(x, left);
			//printf("%c's LEFT node created: %c\n", tn->name, tn->left->name);
			rNode(tn->left, x, s[4], s[6]); 
			pid_t piddy = fork();
		//fork error
		if(piddy<0){
			perror("fork() error");
			exit(-1);
		}
		//PARENT PROCESS: wait on child
		if(piddy!=0){
			//printf("I'm in the parent %d, my child is %d\n", getpid(), piddy);
			wait(NULL);
		//CHILD PROCESS: execute recursive code
		}else{
			//printf("I'm the child %d, my parent is %d\n", getpid(), getppid());
			//printf("%c's RIGHT node created: %c\n", tn->name, tn->right->name);
			fgets(s, 10, fp);
			x = s[2] - '0';
			tn->right = newNode(x, right);
			rNode(tn->right, x, s[4], s[6]); 
		}
		}
		}
	}
}

void print_tree(tree_node * tree){
	if(tree->left == NULL && tree->right == NULL){
		printf(" <-[%c | %d]-> \n", tree->name, tree->children_no);
	}else if(tree->left && tree->right == NULL){
		printf("%c <-[%c | %d]-> \n", tree->left->name,tree->name, tree->children_no);
		print_tree(tree->left);
	}else if(tree->left == NULL && tree->right){
		printf(" <-[%c | %d]-> %c\n", tree->name, tree->children_no, tree->right->name);
		print_tree(tree->right);
	}else if(tree->left && tree->right){
		printf("%c <-[%c | %d]-> %c\n", tree->left->name, tree->name, tree->children_no, tree->right->name);
		print_tree(tree->left);
		print_tree(tree->right);
	}
}

int main()
{
	fp = fopen("input2.txt", "r");
	parse("input2.txt");
	tree_node *root = NULL;

	//traverse through the input array to find numbers
	/*while(c[n]){
		//printf("%c\n", c[n]);
		if(isdigit(c[n])){
			int x = c[n] - '0';
			printf("NUMBER: %d\n", x);
			root = newNode(x,c[n-1]);
			if(x=2){
			rNode(root,x,c[n+1],c[n+2]);
			}else if(x=1){
			rNode(root,x,c[n+1],' ');
			}else if(x=0){
			rNode(root,x,' ',' ');
			}
			}
		n++;
	}*/

		fgets(s, 150, fp);
		x = s[2] - '0';

		//printf("FIRST:%C CN: %d LEFT: %c RIGHT: %c\n", s[0], x, s[4], s[6]);
			//Creates tree if no root yet
			if(!root){
				printf("\nTREE BEING CREATED:\n");
				root = newNode(x,s[0]);
				rNode(root, x, s[4], s[6]);
			}
				printf("\nTerminating Ptree:\n");
				//printf("===========FORMAT=============:\n");
				//printf("left<-[Name | Original Children]->right\n");
				print_tree(root);
		//}
	
	fclose(fp);
}
