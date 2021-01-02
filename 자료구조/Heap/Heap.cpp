#include <stdio.h>
#include <stdlib.h>

#define Len_Heap	20

void Pout(int* a, int N) {
	int p;
	for(p = 1; p < N; p++)
		printf("%3d", *(a+p));

	printf("\n");
}

void Make_Heap(int* A, int* B, int N) {
	int a, b, key;

	B[1] = A[1];
	for (a = 2; a < N; a++) {
		key = A[a]; b = a;
		while (b > 1 && key > B[b / 2]) {	//최대힙, 최소힙 구분
			B[b] = B[b / 2];
			b = b / 2;
		}
		B[b] = key;
		Pout(B, a);
	}
	printf("\n");
}

void Heap_Sort(int* B, int* A, int N) {
	int a, b, b_next, Key, Su;
	for (a = 1; a < N; a++) {
		A[a] = B[1];
		Key = B[N - a];
		b = 1; b_next = 2 * b;
		while (Su = (b_next < N - a) + (b_next + 1 < N - a)) {
			if (Su == 2)
				b_next = b_next + (B[b_next] < B[b_next + 1] ? 1 : 0);
			if (B[b_next] <= Key)
				break;
			B[b] = B[b_next];
			b = b_next; b_next = 2 * b;
		}
		B[b] = Key;
	}
}

int main(void) {
	int A[] = { 0, 6, 8, 9, 12, 7, 4, 3, 1, 20, 14,19, 27, 16, 18, 14 };
	int sz = sizeof(A)/sizeof(int);
	int* B = (int*)malloc(sizeof(int)*sz);

	printf("원 자료 :  ");	Pout(A, sz);
	Make_Heap(A, B, sz);
	printf("힙 자료 :  ");	Pout(B, sz);
	Heap_Sort(B, A, sz);
	printf("정렬자료 : "); Pout(A, sz);
}