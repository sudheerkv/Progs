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

/*Removing all duplicates in a single linked list*/
void remove_duplicates() {
	
	/*Two pointers, one(curr) iterates through whole linked list, other(prev) pointer iterates till curr finding a duplicate node*/
	struct node *curr, *prev;

	/*Temp pointer to store the node previous to node that is to be deleted*/
	struct node *temp;

	/*If linked list is empty return, do nothing*/
	if(NULL == head) {
		printf("linked list is empty\n");
		return;
	}

	/*Initialize curr to head and iterate through whole linked list*/
	curr = head;
	while(curr!=NULL) {
	
		/*Each time current pointer proceeds to next node, initialize prev pointer to head and temp to NULL*/
		prev = head;
		temp = NULL;

		/*Iterate the previous pointer till current pointer to find the duplicate node*/
		while(prev!=curr) {

			/*If duplicate is found delete it*/
			if(prev->val == curr->val) {

				/*If head node is to be deleted*/
				if(NULL == temp)
					head = prev->next;
				else
					temp->next = prev->next;
				free(prev);
			}
			else
				temp=prev;
			prev=prev->next;
		}
		curr= curr->next;
	}
}

/*Finding nth to last element of a singly linked list*/
int NthToLast(int n) {
	int count =0;
	struct node *curr,*currN;

	if(NULL==head)
	{
		printf("Linked list is empty\n");
		return -1;
	}
	
	curr=head;
	while(curr!=NULL) {
		if(count==n-1 || n==0)
			currN=head;
		else if(count>n)
			currN=currN->next;
		count++;
		curr=curr->next;
	}
	if(count<=n)
	{
		printf("Linked list size is only %d\n",count);
		return -1;
	}
	else
		return currN->val;
}

int main() {
	int choice=0;
	int value;
	while(choice!=15) {
		printf("Enter your choice\n");
		scanf("%d",&choice);
		switch(choice) {
			case 1:
				printf("1. Display menu\n");
				printf("2. Insert number in the front\n");
				printf("3. Insert number at the tail\n");
				printf("4. Print the list\n");
				printf("5. Delete a number\n");
				printf("6. Remove duplicates\n");
				printf("7. Remove all occurences of a value\n");
				printf("8. Find nth to last element\n");
				printf("15. Exit\n");
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
			case 6:
				printf("Removing duplicates\n");
				remove_duplicates();
				display_list();
				break;
			case 7:
				scanf("%d",&value);
				removeAll(value);
				break;
			case 8:
				printf("Enter N value\n");
				scanf("%d",&value);
				printf("Nth To Last element is %d\n",NthToLast(value));
				break;
			case 15:
				printf("Exiting the program\n");
				break;
			default:
				printf("Wrong choice\n");
				printf("Enter 1 to see the menu\n");
				break;
		}
	}
}
