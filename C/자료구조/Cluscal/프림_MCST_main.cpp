// 임의의 정점 하나를 추가하고
// 그 정점에 연결된 간선 중 최소 간선을 선택하여 추가한다
// 추가된 간선에 포함된 각각의 정점에 연결된 최소 간선을 선택하여 추가한다
// 간선의 수는 [정점수 - 1]을 만족하여야 한다
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Prim_MCST.h"

enum {A, B, C, D, E, F, G, H, I};
#define START	F			//------------- 최소 시작 정점을 F로 정했을 때

int main(void) {
	int SU1;
	Edge edge[] =
	{ {A,F,11},{A,D,8},{A,C,12},{A,B,9},{B,C,2},{C,E,7},{C,D,6},{D,F,4},{D,E,3},{E,F,13} };

	SU1 = sizeof(edge) / sizeof(Edge);		//----------------- 간선 개수 구하기
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
	} V1 = vx + 1;			//----------------- 정점 개수 구하기

//------------------------------------------------- 그래프 생성하여 정점 추가
	EdgeType* G1 = (EdgeType*)malloc(sizeof(EdgeType));
	int* Ent_Vertex = (int*)malloc(V1 * sizeof(int));

	memset(Ent_Vertex, 0, V1 * sizeof(int));
	CreateGraph(G1);
	for (a = 0; a < V1; a++) {
		if (!Ent_Vertex[a]) {
			InsertVertex(G1, a, V1); Ent_Vertex[a] = 1;
		}
	}

//------------------------------------------------- 간선 추가
	int* Ent_eg = (int*)malloc(SU1 * sizeof(int));

	memset(Ent_eg, 0, SU1 * sizeof(int));
	for (a = 0; a < SU1; a++) {
		InsertEdge(G1, edgeAddr[a]); Ent_eg[a] = 1;
	}

//------------------------------------------------- 정점별 인접 노드 출력
	printf("\n G1의 인접정점 리스트\n");	PrintGraph(G1);		printf("\n");

//------------------------------------------------- 새 그래프 생성하여
	int pos, Cnt_branch = 0, hap = 0;
	EdgeType* G2 = (EdgeType*)malloc(sizeof(EdgeType));
	CreateGraph(G2);

	memset(Ent_Vertex, 0, V1 * sizeof(int));
	for (a = 0; a < V1; a++) {			//--------------------------- 정점만 설정
		if (!Ent_Vertex[a]) InsertVertex(G2, a, V1);
	}

//------- 어떤 정점 추가하고 그 정점에 연결된 첫번째 최소 간선을 그래프에 추가
	Ent_Vertex[START] = 1;
	pos = MinEdge(edgeAddr, SU1, Ent_eg, Ent_Vertex);
	p = edgeAddr[pos]; InsertEdge(G2, p); Cnt_branch++;
	from = p->v_from; to = p->v_to; cost = p->cost;

	G2->Chk_Vertex[from]++;	G2->Chk_Vertex[to]++;
	Ent_Vertex[from] = 1;	Ent_Vertex[to] = 1;	Ent_eg[pos] = 0;
	hap += cost;
	printf("\n			%2d> 간선(%c%c%3d) 추가", pos, from + 65, to + 65, cost);

	while (Cnt_branch + 1 < V1) {		//--------- 두번째 이후의 연결점 최소 간선을 추가한 후
		pos = MinEdge(edgeAddr, SU1, Ent_eg, Ent_Vertex);
		p = edgeAddr[pos]; Cnt_branch++;
		from = p->v_from; to = p->v_to; cost = p->cost;

		G2->Chk_Vertex[from]++; G2->Chk_Vertex[to]++;
		Ent_Vertex[from] = 1;	Ent_Vertex[to] = 1;	Ent_eg[pos] = 0;
		hap += cost;
		printf("\n			%2d> 간선(%c%c%3d) 추가", pos, from + 65, to + 65, cost);

		if (Except(G2, Cnt_branch)) {	//----- 순환이 발생하는 간선일 경우 추가 취소
			printf("\n			%2d> 간선(%c%c%3d) 제거", pos, from + 65, to + 65, cost);
			(G2->Chk_Vertex[from])--;	(G2->Chk_Vertex[to])--;
			Ent_eg[pos] = -1;	Cnt_branch--;	hap -= cost;
		}
		else							//----- 추가 가능한 간선을 추가 확정
			InsertEdge(G2, p);
	}
	printf("\n====================================");
	printf("\n최소비용가중치:%3d\n", hap);

	printf("\n\n G2의 인접정점 리스트\n");		PrintGraph(G2);		printf("\n");
}