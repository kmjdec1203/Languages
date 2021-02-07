#include <stdio.h>
#include <stdlib.h>
#define MX 5

typedef struct _que {
	int Arr[MX];
	int rear, front;
} Queue;

void StackInit(Queue* Q) {
	Q->rear = 0;
	Q->front = 0;
}

int isEmpty(Queue* Q) {
	if (Q->front < 0)
		return 1;
	else
		return 0;
}

int isFull(Stack* S) {
	if (S->sp + 1 >= MX)
		return 1;
	else
		return 0;
}

void Push(Stack* S, int x) {
	if (isFull(S)) {
		printf("Stack is Full!\n");
		exit(0);
	}
	else
		S->Arr[++(S->sp)] = x;
}

int Pop(Stack* S) {
	int tmp;
	if (isEmpty(S)) {
		printf("  Stack is Empty!\n");
		exit(0);
	}
	else {
		tmp = S->Arr[S->sp];
		S->sp--;
		return tmp;
	}
}

int main() {
	Stack* S = (Stack*)malloc(sizeof(Stack));
	int tmp;

	StackInit(S);

	printf("1"); Push(S, 6);
	printf("2"); Push(S, 5);
	printf("3"); Push(S, 4);
	printf("4"); Push(S, 3);
	printf("5"); Push(S, 2);
	//printf("6"); Push(S, 1);

	tmp = Pop(S); printf("%3d", tmp);
	tmp = Pop(S); printf("%3d", tmp);
	tmp = Pop(S); printf("%3d", tmp);
	tmp = Pop(S); printf("%3d", tmp);
}