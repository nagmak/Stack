#include <stdio.h>                     
#include <stdlib.h>          
#include "StackInterface.h"

void SystemError(char *errorMsg) {
	fprintf(stderr, "%s\n", errorMsg);
}

void InitializeStack(Stack *S){
	S->Front = NULL;
}

int isEmpty(Stack *S){
	return (S->Front == NULL);
}

int push(ItemType I, Stack *S){
	StackNode *Temp;

	Temp = (StackNode *) malloc(sizeof(StackNode));

	if (Temp == NULL){
		SystemError("System storage is exhausted! Uh-oh");
		return 0;
	}
	else{
		Temp->Item = I;
		if (S->Front == NULL){
			S->Front = Temp;
			S->Front->Next = NULL;
		}
		else{
			Temp->Next = S->Front;
			S->Front = Temp;
		}
	}
	return 1;
}

int pop(Stack *S, ItemType *R){
	StackNode *Temp;

	if (S->Front == NULL){
		SystemError("Attempt to remove from an empty Stack!");
		return 0;
	}
	else{
		*R = S->Front->Item;
		Temp = S->Front;
		S->Front = S->Front->Next;
		free(Temp);
		return 1;
	}
}