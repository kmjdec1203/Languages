#include <stdio.h>
#include "Cluscal_2.h"

//----------------------------------------------------------------- 그래프 초기화
void createGraph(EdgeType* g, int V1) {
	int v;

	g->n = 0;
	for (v = 0; v < V1; v++)
		g->adjList_H[v] = NULL;
}

//----------------------------------------------------------------- 그래프에 정점 추가
void insertVertex(EdgeType* g, int v)
{
	if ((g->n) + 1 > MXV)
		printf("\n 그래프 정점의 개수를 초과하였습니다");
	else
		(g->n)++;
}

//----------------------------------------------------------------- 정점 개수 구하기
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

//----------------------------------------------------------------- 그래프에 간선 추가
void insertEdge(EdgeType* g, Edge* p)
{
	Edge* edge;
	if (p->v_from >= g->n || p->v_to >= g->n)
		printf("\n 그래프에 없는 정점입니다");
	else {
		p->Link = g->adjList_H[p->v_from];
		g->adjList_H[p->v_from] = p;
	}
}

//----------------------------------------------------------------- 그래프 출력
void printGraph(EdgeType* g)
{
	int a;
	Edge* p;

	for (a = 0; a < g->n; a++) {
		printf("\n 정점 %c의 인접 리스트 : %c", a + 65, a + 65);
		p = g->adjList_H[a];
		while (p) {
			printf(" -> %c(%d)", p->v_to + 65, p->cost);
			p = p->Link;
		}
	}
}

//----------------------------------------------------------------- 제외 대상 점검
int Except(int* Chk_Vertex, int V1, int Edgecnt)
{
	int a, Cnt_node = 0;

	for (a = 0; a < V1; a++) {
		Cnt_node += (Chk_Vertex[a] || Chk_Vertex[V1 + a]);	// 그래프에 포함된 정점 수
	}
	return (Cnt_node == Edgecnt);	// 간선 추가 후 정점과 간선수 비교
}

//----------------------------------------------------------------- 간선의 가중치에 따라 정렬
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