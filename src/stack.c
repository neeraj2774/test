#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
	int num;
	struct Node* next;
} NODE;

NODE*hdptr = NULL;
NODE* top = NULL;
NODE* copy = NULL;
NODE* New_Node;
int pop();
void Push(int);
void display();
void delstack();
int main() {

	int ch = 0, ele, m;
	while (1) {
		printf("\n1.PUSH\n2.POP\n3.DISPLAY STACK\n4.DELETE STACK\n5.EXIT\n");
		scanf("%d", &ch);
		if (ch == 1) {
			printf("\nEnter the element to push to stack : ");
			scanf("%d", &ele);
			Push(ele);
		} else if (ch == 2) {
			m = pop();
			if (m == -1) {
				printf("\nUnderflow SORRY! Stack is empty");
			} else
				printf("Popped element is : %d", m);

		} else if (ch == 3) {
			display();
		} else if (ch == 4) {
			delstack();
		} else if(ch==5)
		{
			printf("Thank you");
			return 0;
		}else
		{
			printf("INVALID SELECTION");
			return 0;
		}

	}
	return 0;
}
void Push(int value) {
	New_Node = (struct Node *) malloc(sizeof(struct Node));
	if (New_Node != NULL) {
		New_Node->num = value;
		New_Node->next = NULL;

		if (hdptr == NULL) {

			top = New_Node;
			hdptr = New_Node;
			copy = hdptr;
		} else {
			top->next = New_Node;
			top = New_Node;

		}
		printf("\n%d is pushed to stack\n", top->num);

	}
}
int pop() {
	struct Node* temp;
	temp = top;
	if (temp == copy) {
		if (hdptr == NULL) {

			return -1;
		} else {
			//printf("\nPopped element is %d",temp->num);
			//free(temp);
			top = NULL;
			hdptr = NULL;
			copy = hdptr;
		}

	} else {
		while (copy->next != temp) {
			copy = copy->next;
		}
		copy->next = NULL;
		//printf("\nPopped element is %d",temp->num);
		//free(temp);
		top = copy;
		copy = hdptr;
	}
	return temp->num;
}
void display() {
	struct Node* temp;
	temp = top;
	if (copy == NULL) {
		printf("\nNothing is there to show");
	}
	while (copy != temp) {

		while (copy->next != temp) {
			copy = copy->next;
		}
		printf("\n%d", temp->num);
		temp = copy;
		copy = hdptr;
	}
	if (copy != NULL) {

		printf("\n%d", copy->num);
		copy = hdptr;
		//free(temp);
	}
}
void delstack() {
	if (copy == NULL) {
		printf("\nNothing is there to delete");
	} else {

		struct Node* temp;
		temp = top;
		while (copy != temp) {

			while (copy->next != temp) {
				copy = copy->next;
			}
			temp = copy;
			//free(temp);
		}
		//free(temp);
		top = NULL;
		hdptr = NULL;
		copy = hdptr;
		printf("\nWhole stack is deleted");

	}
}











