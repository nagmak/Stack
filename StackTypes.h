typedef int ItemType;

typedef struct StackNodeTag{
	ItemType Item;
	struct StackNodeTag *Next;
}StackNode;

typedef struct{
	StackNode *Front;
}Stack;