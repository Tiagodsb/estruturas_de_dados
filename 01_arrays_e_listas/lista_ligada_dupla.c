#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	int value;
	struct node *next;
	struct node *prev;
} node;

void add(node **head, int value);
void rmv(node **head, int value);
node* find(node *head, int value);
void show_reverse(node *head);
void show(node *head);

void add(node **head, int value) {
	node *new_node = malloc(sizeof(node));

	if(!new_node){
        printf("add(%d): erro na alocação de memória\n", value);
        return;
    }
	
	new_node->value = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	
	if(*head == NULL) {
		*head = new_node;
        printf("add(%d): valor inserido\n", value);
		return;
	}

	node *current = *head;

	//find the last item
	while(current->next != NULL) {
		current = current->next;
	}
	new_node->prev = current;	
	current->next = new_node;
    printf("add(%d): valor inserido\n", value);
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
	
	if(head == NULL) {
        puts("[vazia]");
        return;
    }

	while(head->next != NULL) {
		printf("%d\n", head->value);
		head = head->next; 
	}
	printf("%d\n", head->value);
}

node* find(node *head, int value) {
    node *result;
    result = head;

    while(result != NULL && result->value != value) {
        result = result->next;
    }
    return result;
}

void rmv(node **head, int value) {
    node *target = find(*head, value);
    if(!target) {
        printf("rmv(%d): valor não encontrado\n", value);
        return;
    }
    node *prev = target->prev;
    node *next = target->next;

    if(target == *head) {
        *head = next;
    }

    if(prev) {
        prev->next = next;
    }

    if(next) {
        next->prev = prev;
    }

    free(target);
    printf("rmv(%d): valor removido\n", value);
}

int main(void) {
	node *head = NULL;
	add(&head, 10);	
	add(&head, 20);
	add(&head, 30);
	add(&head, 50);
	show(head);
	show_reverse(head);

    node *result = find(head, 20);
    if(result) puts("find(20): encontrado"); else puts("find(20): não encontrado");

    result = find(head, 42);
    if(result) puts("find(42): encontrado"); else puts("find(42): não encontrado");

    rmv(&head, 42);
    add(&head, 42);
    show(head);
    rmv(&head, 42);
    show(head);
    rmv(&head, 10);
    rmv(&head, 20);
    rmv(&head, 30);
    rmv(&head, 50);
    rmv(&head, 42);
    show(head);
}

