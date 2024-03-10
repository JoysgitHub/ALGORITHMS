#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct node{ 
	int num;
	struct node *next;
}node;

node *list = NULL;

void exitFreeList(){
	node *ptr = list;
	while (ptr != NULL) {
		node *next = ptr->next;
		free(ptr);
		ptr = next;
	}
}

void findItem(){
	printf("-----Find-Item------\n");
	node *tmp = list;
	if (tmp == NULL) {
		printf("[*] List Empty\n");
	}else {
		int ind = 0;
		int number = 0;
		printf("Item > ");
		scanf("%d", &number);
		
		for (node *tmp = list ; tmp!=NULL; tmp = tmp->next) {
			if (tmp->num == number) {
			printf("[+] Found: %d\n", number);	
			printf("\t\\\n\t -->Index: %i -> %i \n", ind , tmp->num);
			}	
			ind++;
		}
	}

	printf("-----Find-Item------\n");
}


void displayList(){
	printf("-----Display-------\n");
	node *tmp = list;
	if (tmp == NULL) {
		printf("[*] List Empty\n");
	}else {
		int ind = 0;
		for (node *tmp = list ; tmp!=NULL; tmp = tmp->next) {
			printf("Index: %i -> %i \n", ind , tmp->num);
			ind++;
		}
	}

	printf("-----Display-------\n");
}

void delete(){

	printf("-----Delete-----\n");
	int number;
	node *tmp = list;
	
	if (tmp == NULL) {
		printf("[*] List Empty\n");
		printf("-----Delete-----\n");
	}else {
		int ind = 0;
		//Print the Indexes with value
		for (node *tmp = list ; tmp!=NULL; tmp = tmp->next) {
			printf("Index: %i -> %i \n", ind , tmp->num);
			ind++;
		}
		tmp = list;
		printf("Index: > ");
		scanf("%d", &number);
		if ( number == 0) {
			node *second = tmp->next;
			free(tmp);
			list = second;

		printf("-----Delete-----\n");
		}else {
			int index = 0;
			/* node *second = list->next; */
			for (node *tmp = list;tmp != NULL; tmp = tmp->next) {
				if (number == (index + 1)) {
					node *current = tmp;
					node *delete = current->next;
					node *after = delete->next;
					current->next = after;
					free(delete);


				}

				index++;
			}

		}	
	}
	printf("-----Delete-----\n");
}

void addItem(){
	printf("----Add----\n");	
	int number;
	printf("Item > ");
	scanf("%d", &number);

	node *n = malloc(sizeof(node));
	if (n == NULL) {
		printf("[-] Error: Failed to allocate memory\n");
		exit(1);	
	}
	n->num = number;
	n->next = NULL;

	n->next = list;
	list = n;

	
	printf("----Add----\n\n");	
	
}

void displayMenu(){

		printf("-------------------\n");
		printf("Menu: \n"
				"-------------------\n"
				"1. Display Items\n"
				"2. Add Item\n"
				"3. Find Item\n"	
				"4. Delete Item\n"	
				"5. Exit\n"
				);
		printf("-------------------\n");
}


int getChoice(){
	int choice = 0;

	displayMenu();
	printf("> ");
	scanf("%d", &choice);
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
	return choice;	
}

int main(void)
{
	bool mainLoop = true;

	while (mainLoop) {
		int choice = getChoice();
		switch (choice) {
			case 1:
				displayList();
				break;
			case 2:
				addItem();
				break;
			case 3:
				findItem();
				break;
			case 4:
				delete();
				break;
			case 5:
				exitFreeList();
				exit(0);
				break;
		}
	}

	return 0;
}
