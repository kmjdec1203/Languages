#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cluscal_1.h"

enum {A, B, C, D, E, F, G, H, I, J};

//-------------------------------------------------------------- main()
int main() {
	Edge edge[] =
	{ {A,F,11},{A,D,8},{A,C,12},{A,B,9},{B,C,2},{C,E,7},{C,D,6},{D,F,4},{D,E,3},{E,F,13} };

//-------------------------------------------------------------- ���� ���� ���ϱ�
	int SU1 = sizeof(edge) / sizeof(Edge);		//-- �ִ� ���� ��
	int* entry = (int*)malloc(sizeof(int) * SU1);
	memset(entry, 0, sizeof(int) * SU1);

//-------------------------------------------------------------- ���� ���� ���ϱ�
	Edge** edgeAddr = (Edge**)malloc(SU1 * sizeof(Edge*)), * p;
	int a, V1;

	for (a = 0; a < SU1; a++) edgeAddr[a] = &edge[a];
	V1 = Cnt_Vertex(edgeAddr, SU1);		//-- �ִ� ���� ��

//-------------------------------------------------------------- �׷��� �����Ͽ� ���� �߰�
	EdgeType* G1 = (EdgeType*)malloc(sizeof(EdgeType));
	createGraph(G1, V1);

	for (a = 0; a < V1; a++) insertVertex(G1, a);

//-------------------------------------------------------------- �׷����� ��簣�� �߰�
	int* Chk_Vertex = (int*)malloc(sizeof(int) * V1 * 2);	//-- ���� ���� �迭
	memset(Chk_Vertex, 0, sizeof(int) * V1 * 2);
	int from, to, Dcnt = 0; // ���� ��
	for (a = 0; a < SU1; a++) {
		p = edgeAddr[a]; from = p->v_from; to = p->v_to;
		Chk_Vertex[from]++; Chk_Vertex[to + V1]++;
		insertEdge(G1, p); entry[a] = 1; Dcnt++;
	}
//-------------------------------------------------------------- ������ ���� ��� ���
	printf("\n G1�� �������� ����Ʈ\n"); printGraph(G1); printf("\n");

//-------------------------------------------------------------- ���� �ڷ� �������� ����
	sorting(edgeAddr, DSCEND, SU1);

//---------- ������ ����ġ�� ū �ͺ��� �׷������� ����. �� ���� ������ �ʵ���
	for (a = 0; a < SU1; a++) {
		if (Dcnt < V1) break;		// �ּ� ������(Dcnt) = ������(V1) - 1
		p = edgeAddr[a]; from = p->v_from; to = p->v_to;
		--Chk_Vertex[from]; --Chk_Vertex[to + V1];		// �ϴ� ������ ��
		if (Except(Chk_Vertex, V1)) {	// ���� ����̸� ���� Ȯ���ϰ�
			printf("\n (%c, %c) %d ����", from + 65, to + 65, p->cost);
			entry[a] = 0;
			Dcnt--;
		}
		else {							// �׷��� ������ ���� ����
			++Chk_Vertex[from]; ++Chk_Vertex[to + V1];
		}
	} printf("\n");

//-------------------------------------------------------------- �� �׷��� �����Ͽ�
	EdgeType* G2 = (EdgeType*)malloc(sizeof(EdgeType));
	createGraph(G2, V1); for (a = 0; a < V1; a++) insertVertex(G2, a);

//-------------------------------------------------------------- ���ܵ��� ���� ������ �׷����� �߰�
	int hap = 0;
	for (a = 0; a < SU1; a++) 
		if (entry[a]) {
			p = edgeAddr[a]; insertEdge(G2, p);
			from = p->v_from; to = p->v_to;
			printf("\n ���� (%c, %c) ����ġ %3d", from + 65, to + 65, p->cost);
			hap = hap + p->cost;
		}
	printf("\n==========================");
	printf("\n �ּ� ��� ����ġ: %3d\n", hap);
	printf("\n\n G2�� �������� ����Ʈ\n"); printGraph(G2); printf("\n");
}