#include<stdio.h>
#include<malloc.h>

struct snode {
	int data;
	struct snode *next;
}*head1,*head2;

void push(struct snode **head, int value) {
	struct snode *temp= (struct snode*)malloc(sizeof(struct snode));
	temp->data = value;
	temp->next = NULL;

	if((*head)!=NULL)
		temp->next = (*head);
	(*head)=temp;
}

int pop(struct snode **head) {
	struct snode *temp;
	struct snode *topofstack = *head;
	int value;

	if(NULL==topofstack){
		printf("Stack is Empty\n");
		value = -1;
	}
	else {
		value = topofstack->data;
		temp = topofstack->next;
		free(topofstack);
		*head = temp;
	}
	return value;
}

void PrintStack(struct snode **head) {
	int value;
	while((value=pop(head))!=-1)
		printf("%d\n",value);
}

int main() {
	int choice=0;
        int value;
        while(choice!=15) {
                printf("Enter your choice: ");
                scanf("%d",&choice);
                switch(choice) {
                        case 1:
                                printf("1. Display menu\n");
                                printf("2. Push into stack\n");
                                printf("3. Pop from stack\n");
                                printf("4. Print the contents of stack\n");
                                printf("15. Exit\n");
                                break;
			case 2:
				printf("Enter number to be pushed into stack:");
				scanf("%d",&value);
				push(&head1,value);
				break;
			case 3:
				value = pop(&head1);
				printf("Popped number from stack: %d\n",value);
				break;
			case 4:
				printf("Contents of stack, Stack would be empty after this operation\n");
				PrintStack(&head1);
				break;			
			case 15:
				printf("Exiting program\n");
				break;
			default:
				printf("Entered wrong choice, try again\n");
				break;
		}
	}
}
