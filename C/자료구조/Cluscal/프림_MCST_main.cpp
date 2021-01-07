// ������ ���� �ϳ��� �߰��ϰ�
// �� ������ ����� ���� �� �ּ� ������ �����Ͽ� �߰��Ѵ�
// �߰��� ������ ���Ե� ������ ������ ����� �ּ� ������ �����Ͽ� �߰��Ѵ�
// ������ ���� [������ - 1]�� �����Ͽ��� �Ѵ�
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Prim_MCST.h"

enum {A, B, C, D, E, F, G, H, I};
#define START	F			//------------- �ּ� ���� ������ F�� ������ ��

int main(void) {
	int SU1;
	Edge edge[] =
	{ {A,F,11},{A,D,8},{A,C,12},{A,B,9},{B,C,2},{C,E,7},{C,D,6},{D,F,4},{D,E,3},{E,F,13} };

	SU1 = sizeof(edge) / sizeof(Edge);		//----------------- ���� ���� ���ϱ�
	Edge** edgeAddr = (Edge**)malloc(SU1 * sizeof(Edge*)), * p;

	int a, from, to, cost, sum, vx = 0, V1;

	for (a = 0; a < SU1; a++) {
		p = &edge[a];
		from = p->v_from; to = p->v_to; sum = from + to;
		if (from > to) {
			p->v_from = sum - from;
			p->v_to = sum - to;
		}
		vx = p->v_to > vx ? p->v_to : vx;
		edgeAddr[a] = p;
	} V1 = vx + 1;			//----------------- ���� ���� ���ϱ�

//------------------------------------------------- �׷��� �����Ͽ� ���� �߰�
	EdgeType* G1 = (EdgeType*)malloc(sizeof(EdgeType));
	int* Ent_Vertex = (int*)malloc(V1 * sizeof(int));

	memset(Ent_Vertex, 0, V1 * sizeof(int));
	CreateGraph(G1);
	for (a = 0; a < V1; a++) {
		if (!Ent_Vertex[a]) {
			InsertVertex(G1, a, V1); Ent_Vertex[a] = 1;
		}
	}

//------------------------------------------------- ���� �߰�
	int* Ent_eg = (int*)malloc(SU1 * sizeof(int));

	memset(Ent_eg, 0, SU1 * sizeof(int));
	for (a = 0; a < SU1; a++) {
		InsertEdge(G1, edgeAddr[a]); Ent_eg[a] = 1;
	}

//------------------------------------------------- ������ ���� ��� ���
	printf("\n G1�� �������� ����Ʈ\n");	PrintGraph(G1);		printf("\n");

//------------------------------------------------- �� �׷��� �����Ͽ�
	int pos, Cnt_branch = 0, hap = 0;
	EdgeType* G2 = (EdgeType*)malloc(sizeof(EdgeType));
	CreateGraph(G2);

	memset(Ent_Vertex, 0, V1 * sizeof(int));
	for (a = 0; a < V1; a++) {			//--------------------------- ������ ����
		if (!Ent_Vertex[a]) InsertVertex(G2, a, V1);
	}

//------- � ���� �߰��ϰ� �� ������ ����� ù��° �ּ� ������ �׷����� �߰�
	Ent_Vertex[START] = 1;
	pos = MinEdge(edgeAddr, SU1, Ent_eg, Ent_Vertex);
	p = edgeAddr[pos]; InsertEdge(G2, p); Cnt_branch++;
	from = p->v_from; to = p->v_to; cost = p->cost;

	G2->Chk_Vertex[from]++;	G2->Chk_Vertex[to]++;
	Ent_Vertex[from] = 1;	Ent_Vertex[to] = 1;	Ent_eg[pos] = 0;
	hap += cost;
	printf("\n			%2d> ����(%c%c%3d) �߰�", pos, from + 65, to + 65, cost);

	while (Cnt_branch + 1 < V1) {		//--------- �ι�° ������ ������ �ּ� ������ �߰��� ��
		pos = MinEdge(edgeAddr, SU1, Ent_eg, Ent_Vertex);
		p = edgeAddr[pos]; Cnt_branch++;
		from = p->v_from; to = p->v_to; cost = p->cost;

		G2->Chk_Vertex[from]++; G2->Chk_Vertex[to]++;
		Ent_Vertex[from] = 1;	Ent_Vertex[to] = 1;	Ent_eg[pos] = 0;
		hap += cost;
		printf("\n			%2d> ����(%c%c%3d) �߰�", pos, from + 65, to + 65, cost);

		if (Except(G2, Cnt_branch)) {	//----- ��ȯ�� �߻��ϴ� ������ ��� �߰� ���
			printf("\n			%2d> ����(%c%c%3d) ����", pos, from + 65, to + 65, cost);
			(G2->Chk_Vertex[from])--;	(G2->Chk_Vertex[to])--;
			Ent_eg[pos] = -1;	Cnt_branch--;	hap -= cost;
		}
		else							//----- �߰� ������ ������ �߰� Ȯ��
			InsertEdge(G2, p);
	}
	printf("\n====================================");
	printf("\n�ּҺ�밡��ġ:%3d\n", hap);

	printf("\n\n G2�� �������� ����Ʈ\n");		PrintGraph(G2);		printf("\n");
}