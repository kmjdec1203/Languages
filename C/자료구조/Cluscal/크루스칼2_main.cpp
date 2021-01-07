// ������ ����ġ ������ �������� �����Ѵ�
// ������ ��� �߰��� ���¿��� �ּ� ����ġ�� ������ ���ʷ� �߰��Ѵ�
// �߰��� �������� ���Ͽ� ������ �������� �ʵ��� �Ѵ�
// ������ ���� [������ - 1]�� �����Ͽ��� �Ѵ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cluscal_2.h"

enum { A, B, C, D, E, F, G, H, I, J };

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
	for (a = 0; a < SU1; a++) {
		insertEdge(G1, edgeAddr[a]); entry[a] = 0;
	}

	//-------------------------------------------------------------- ������ ���� ��� ���
	printf("\n G1�� �������� ����Ʈ\n"); printGraph(G1); printf("\n");

	//-------------------------------------------------------------- ���� �ڷ� �������� ����
	sorting(edgeAddr, ASCEND, SU1);

	//-------------------------------------------------------------- �� �׷��� �����Ͽ�
	EdgeType* G2 = (EdgeType*)malloc(sizeof(EdgeType));
	createGraph(G2, V1); for (a = 0; a < V1; a++) insertVertex(G2, a);

	//---------------- ������ ����ġ�� ���� �ͺ��� �׷����� �߰�. ��ȯ���� �ʵ���
	int* Chk_Vertex = (int*)malloc(sizeof(int) * V1 * 2);	//-- ���� ���� �迭
	memset(Chk_Vertex, 0, sizeof(int) * V1 * 2);
	int from, to, hap = 0, Dcnt = 0; // ���� ��

	//-------------------------------------------------------------- �߰��� ��� ������ ���Ͽ�
	for (a = 0; a < SU1; a++) {
		p = edgeAddr[a]; from = p->v_from; to = p->v_to;
		if (Dcnt + 1 >= V1) break;
		++Chk_Vertex[from]; ++Chk_Vertex[to + V1];	// �ϴ� �߰��� ��
		if (Except(Chk_Vertex, V1, Dcnt + 1)) {		// �������ǿ� �ش�Ǹ� �߰� ���
			--Chk_Vertex[from]; --Chk_Vertex[to + V1];
		}
		else {										// �׷��� ������ �߰� Ȯ��
			printf("\n(%c, %c) %d �߰�", from + 65, to + 65, p->cost);
			insertEdge(G2, p); entry[a] = 1; Dcnt++; hap = hap + p->cost;
		}
	} printf("\n");
	printf("\n==========================");
	printf("\n �ּ� ��� ����ġ: %3d\n", hap);
	printf("\n\n G2�� �������� ����Ʈ\n"); printGraph(G2); printf("\n");
}