#include<stdio.h>
#include<string.h>
#include<malloc.h>

struct node {
	int val;
	struct node *next;
}*head;

void insert_front(int value)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->val = value;
	if(NULL == head)
		temp->next = NULL;
	else
		temp->next = head;
	head = temp;	
}

void insert_tail(int value)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	struct node *curr;
	temp->val = value;
	temp->next = NULL;
	if(NULL == head) {
		head = temp;
	}
	else{
		curr = head;
		while(curr->next!=NULL)
			curr = curr->next;
		curr->next = temp;
	}
}

void display_list() {
	struct node *temp;
	if(NULL == head)
		printf("The list is empty\n");
	else {
		temp = head;
		while(temp!=NULL)
		{
			printf("%d->",temp->val);
			temp=temp->next;
		}
		printf("=\n");
	}
}

void delete_val(int value) {
	struct node *temp,*prev = NULL;
	int flag =0;
	if(NULL == head) {
		printf("The list is empty\n");
		return;
	}
	else {
		temp = head;
		while(temp!=NULL) {
			if(temp->val == value){
				flag =1;
				if(NULL == prev)
					head = temp->next;
				else
					prev->next = temp->next;
				free(temp);
			}
			else 
				prev = temp;
			temp= temp->next;
		}
	}
	if(flag!=1)
		printf("Number not found\n");
}

void removeAll(int val) {
    struct node *temp;
    struct node *prev = NULL;
    if(NULL == head)
        return;
    else {
        temp =head;
        while(temp!=NULL) {
            if(temp->val == val) {
                if(NULL == prev) 
                    head = temp->next;
                else 
                    prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
    }
}

int main() {
	int choice=0;
	int value;
	while(choice!=8) {
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				printf("1. Display menu\n");
				printf("2. Insert number in the front\n");
				printf("3. Insert number at the tail\n");
				printf("4. Delete a number\n");
				printf("5. Print the list\n");
				printf("7. Exit\n");
				break;
			case 2:
				printf("Enter number to be inserted in front\n");
				scanf("%d",&value);
				insert_front(value);
				break;
			case 3:
				printf("Enter number to be inserted at tail\n");
				scanf("%d",&value);
				insert_tail(value);
				break;
			case 4:
				display_list();
				break;
			case 5:
				printf("Enter the number to be deleted\n");
				scanf("%d",&value);
				delete_val(value);
				break;
			case 7:
				scanf("%d",&value);
				removeAll(value);
				break;
			case 8:
				printf("Exiting the program\n");
				break;
			default:
				printf("Wrong choice\n");
				printf("Enter 1 to see the menu\n");
				break;
		}
	}
}
