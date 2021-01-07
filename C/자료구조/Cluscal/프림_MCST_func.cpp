#include <stdio.h>
#include <string.h>
#include "Prim_MCST.h"

void CreateGraph(EdgeType* g)
{
	int v;

	g->Cnt_vertex = 0;
	for (v = 0; v < MX; v++) g->adjList_H[v] = NULL;
	memset(g->Chk_Vertex, 0, MX * 2 * sizeof(int));
}

void InsertVertex(EdgeType* g, int v, int V1)
{
	if ((g->Cnt_vertex) + 1 > V1) printf("\n �׷��� ������ ������ �ʰ��Ͽ����ϴ�");
	else	(g->Cnt_vertex)++;
}

void InsertEdge(EdgeType* g, Edge* p)
{
	if (p->v_from >= g->Cnt_vertex || p->v_to >= g->Cnt_vertex)
		printf("\n �׷����� ���� �����Դϴ�");
	else {
		p->Link = g->adjList_H[p->v_from];		g->adjList_H[p->v_from] = p;
	}
}

void PrintGraph(EdgeType* g)
{
	int a;
	Edge* p;

	for (a = 0; a < g->Cnt_vertex; a++) {
		printf("\n ���� %c�� ���� ����Ʈ: %c", a + 65, a + 65);
		p = g->adjList_H[a];
		while (p) {
			printf(" -> %c(%d)", p->v_to + 65, p->cost);
			p = p->Link;
		}
	}
}

int MinEdge(Edge* pos[], int SU1, int* Ent_eg, int* Ent_Vertex)
{
	int sel = 0, min = MIN, a;
	Edge* p = NULL;

	for (a = 0; a < SU1; a++) {
		p = pos[a];
		// �׷����� �߰��� ������ �����ִ� ������� ���� ������ ���Ͽ�
		if ((Ent_Vertex[p->v_from] || Ent_Vertex[p->v_to]) && (Ent_eg[a] == 1)) {
			if (p->cost < min) {
				sel = a; min = p->cost;
			}
		}
	} p = pos[sel];		// �ּ� ����ġ ������ �߰��ϰ� �� ��ȣ(sel)�� �����Ѵ�.
	return sel;
}

int Except(EdgeType* g, int Cnt_branch)
{
	int a, Cnt_node = 0;

	for (a = 0; a < MX; a++)
		if (g->Chk_Vertex[a] || g->Chk_Vertex[a]) Cnt_node++;

	return Cnt_node == Cnt_branch;
}

// ���� �˰��� ���� �ּ� ��� ���� Ʈ�� ���ϱ� ���α׷��Դϴ�