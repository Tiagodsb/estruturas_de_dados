#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int value;
	struct node *next;
	struct node *prev;
} node;

void add(node **head, int value);
void rmv(node **head, int value);
void find(node **head, int value);
void show_reverse(node *head);
void show(node *head);

void add(node **head, int value) {
	node *new_node = malloc(sizeof(node));

	if(!new_node) return;
	
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	if(*head == NULL) {
		*head = new_node;
		return;
	}

	node *current = *head;

	//find the last item
	while(current->next != NULL) {
		current = current->next;
	}
	new_node->prev = current;	
	current->next = new_node;
}

void show_reverse(node *head) {
	printf("Ordem reversa\n");
	if(head == NULL) return;
	
	node *last = head;
	while(last->next != NULL) {
		last = last->next;		
	}

	while(last->prev != NULL) {
		printf("%d\n", last->value);
		last = last->prev;
	}
	printf("%d\nfim da lista\n", last->value);
}

void show(node *head) {
	printf("List content\n");
	
	if(head == NULL) return;

	while(head->next != NULL) {
		printf("%d\n", head->value);
		head = head->next; 
	}
	printf("%d\n", head->value);
}

int main(void) {
	node *head = NULL;
	add(&head, 10);	
	add(&head, 20);
	add(&head, 30);
	add(&head, 50);
	show(head);
	show_reverse(head);
}

