#include <stdio.h>
#include <stdlib.h>
#include "StackInterface.h"

void pushReturnValueCheck(int returnValue, int value);
void popReturnValueCheck(Stack *S, int returnValue);

int main(void){
	
	/* Initialize empty stack */
	Stack S;
	InitializeStack(&S);

	if(!isEmpty(&S)){
		isEmpty(&S);
	}

	int returnValue, removedItem;
	returnValue = pop(&S, &removedItem);
	popReturnValueCheck(&S, returnValue);

	for (int i = 7; i > 0; i--){
		returnValue = push(i, &S);
		pushReturnValueCheck(returnValue, i);
	}

	for (int i = 7; i > 0; i--){
		returnValue = pop(&S, &removedItem);
		popReturnValueCheck(&S, returnValue);
	}
}

void pushReturnValueCheck(int returnValue, int value){
	if (returnValue){
		printf("Success! You've added %i to the stack\n", value);
	}
	else{
		printf("Error! You were unable to add %i to the stack.\n", value);
	}
}

void popReturnValueCheck(Stack *S, int returnValue){
	if (!isEmpty(S) && returnValue){
		printf("You've successfully removed the top item from the stack.\n");
	}
	else{
		printf("Error. You tried removing an item from an empty stack.\n");
	}
}