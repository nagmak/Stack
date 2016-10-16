#include <stdio.h>
#include <stdlib.h>
#include "StackInterface.h"

int main(void){
	Stack S;
	InitializeStack(&S);

	if(!isEmpty(&S)){
		isEmpty(&S);
	}

	int returnValue, removedItem;
	returnValue = pop(&S, &removedItem);

	if (!isEmpty(&S) && returnValue){
		printf("You've successfully removed the top item from the stack.\n");
	}
	else{
		printf("Error. You tried removing an item from an empty stack.\n");
	}

	for (int i = 7; i > 0; i--){
		returnValue = push(i, &S);
		if (returnValue){
			printf("Success! You've added %i to the stack\n", i);
		}
		else{
			printf("Error! You were unable to add %i to the stack.\n", i);
		}
	}

	for (int i = 7; i > 0; i--){
		returnValue = pop(&S, &removedItem);

		if(returnValue){
			printf("Success! You've removed %i from the stack\n", removedItem);
		}
		else{
			printf("Error! You were unable to remove the top item from the stack.\n");
		}
	}
}