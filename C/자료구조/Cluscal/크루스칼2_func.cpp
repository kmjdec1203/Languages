#include <stdio.h>
#include "Cluscal_2.h"

//----------------------------------------------------------------- �׷��� �ʱ�ȭ
void createGraph(EdgeType* g, int V1) {
	int v;

	g->n = 0;
	for (v = 0; v < V1; v++)
		g->adjList_H[v] = NULL;
}

//----------------------------------------------------------------- �׷����� ���� �߰�
void insertVertex(EdgeType* g, int v)
{
	if ((g->n) + 1 > MXV)
		printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�");
	else
		(g->n)++;
}

//----------------------------------------------------------------- ���� ���� ���ϱ�
int Cnt_Vertex(Edge* edgeAddr[], int SU1)
{
	int a, sum, from, to, V1 = 0;
	Edge* p;

	for (a = 0; a < SU1; a++) {
		p = edgeAddr[a]; from = p->v_from; to = p->v_to;
		sum = from + to;

		if (from > to) {
			p->v_from = sum - from;
			p->v_to = sum - to;
		}
		V1 = V1 > p->v_to ? V1 : p->v_to;
	}
	return V1 + 1;
}

//----------------------------------------------------------------- �׷����� ���� �߰�
void insertEdge(EdgeType* g, Edge* p)
{
	Edge* edge;
	if (p->v_from >= g->n || p->v_to >= g->n)
		printf("\n �׷����� ���� �����Դϴ�");
	else {
		p->Link = g->adjList_H[p->v_from];
		g->adjList_H[p->v_from] = p;
	}
}

//----------------------------------------------------------------- �׷��� ���
void printGraph(EdgeType* g)
{
	int a;
	Edge* p;

	for (a = 0; a < g->n; a++) {
		printf("\n ���� %c�� ���� ����Ʈ : %c", a + 65, a + 65);
		p = g->adjList_H[a];
		while (p) {
			printf(" -> %c(%d)", p->v_to + 65, p->cost);
			p = p->Link;
		}
	}
}

//----------------------------------------------------------------- ���� ��� ����
int Except(int* Chk_Vertex, int V1, int Edgecnt)
{
	int a, Cnt_node = 0;

	for (a = 0; a < V1; a++) {
		Cnt_node += (Chk_Vertex[a] || Chk_Vertex[V1 + a]);	// �׷����� ���Ե� ���� ��
	}
	return (Cnt_node == Edgecnt);	// ���� �߰� �� ������ ������ ��
}

//----------------------------------------------------------------- ������ ����ġ�� ���� ����
void sorting(Edge* e[], int asds, int SU1)
{
	int a, b, gijun, p;
	Edge* t;

	for (a = 0; a < SU1 - 1; a++) {
		gijun = e[a]->cost; p = a;

		for (b = a + 1; b < SU1; b++) {
			if ((e[b]->cost < gijun) == asds) {
				gijun = e[b]->cost; p = b;
			}
		}
		t = e[a]; e[a] = e[p]; e[p] = t;
	}
}