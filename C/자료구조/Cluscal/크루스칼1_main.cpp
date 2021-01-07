#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cluscal_1.h"

enum {A, B, C, D, E, F, G, H, I, J};

//-------------------------------------------------------------- main()
int main() {
	Edge edge[] =
	{ {A,F,11},{A,D,8},{A,C,12},{A,B,9},{B,C,2},{C,E,7},{C,D,6},{D,F,4},{D,E,3},{E,F,13} };

//-------------------------------------------------------------- 간선 개수 구하기
	int SU1 = sizeof(edge) / sizeof(Edge);		//-- 최대 간선 수
	int* entry = (int*)malloc(sizeof(int) * SU1);
	memset(entry, 0, sizeof(int) * SU1);

//-------------------------------------------------------------- 정점 개수 구하기
	Edge** edgeAddr = (Edge**)malloc(SU1 * sizeof(Edge*)), * p;
	int a, V1;

	for (a = 0; a < SU1; a++) edgeAddr[a] = &edge[a];
	V1 = Cnt_Vertex(edgeAddr, SU1);		//-- 최대 정점 수

//-------------------------------------------------------------- 그래프 생성하여 정점 추가
	EdgeType* G1 = (EdgeType*)malloc(sizeof(EdgeType));
	createGraph(G1, V1);

	for (a = 0; a < V1; a++) insertVertex(G1, a);

//-------------------------------------------------------------- 그래프에 모든간선 추가
	int* Chk_Vertex = (int*)malloc(sizeof(int) * V1 * 2);	//-- 연결 정점 배열
	memset(Chk_Vertex, 0, sizeof(int) * V1 * 2);
	int from, to, Dcnt = 0; // 간선 수
	for (a = 0; a < SU1; a++) {
		p = edgeAddr[a]; from = p->v_from; to = p->v_to;
		Chk_Vertex[from]++; Chk_Vertex[to + V1]++;
		insertEdge(G1, p); entry[a] = 1; Dcnt++;
	}
//-------------------------------------------------------------- 정점별 인접 노드 출력
	printf("\n G1의 인접정점 리스트\n"); printGraph(G1); printf("\n");

//-------------------------------------------------------------- 간선 자료 내림차순 정렬
	sorting(edgeAddr, DSCEND, SU1);

//---------- 간선의 가중치가 큰 것부터 그래프에서 제외. 고립 정점 생기지 않도록
	for (a = 0; a < SU1; a++) {
		if (Dcnt < V1) break;		// 최소 간선수(Dcnt) = 정점수(V1) - 1
		p = edgeAddr[a]; from = p->v_from; to = p->v_to;
		--Chk_Vertex[from]; --Chk_Vertex[to + V1];		// 일단 제외한 후
		if (Except(Chk_Vertex, V1)) {	// 제외 대상이면 제외 확정하고
			printf("\n (%c, %c) %d 제외", from + 65, to + 65, p->cost);
			entry[a] = 0;
			Dcnt--;
		}
		else {							// 그렇지 않으면 제외 복원
			++Chk_Vertex[from]; ++Chk_Vertex[to + V1];
		}
	} printf("\n");

//-------------------------------------------------------------- 새 그래프 생성하여
	EdgeType* G2 = (EdgeType*)malloc(sizeof(EdgeType));
	createGraph(G2, V1); for (a = 0; a < V1; a++) insertVertex(G2, a);

//-------------------------------------------------------------- 제외되지 않은 간선만 그래프에 추가
	int hap = 0;
	for (a = 0; a < SU1; a++) 
		if (entry[a]) {
			p = edgeAddr[a]; insertEdge(G2, p);
			from = p->v_from; to = p->v_to;
			printf("\n 간선 (%c, %c) 가중치 %3d", from + 65, to + 65, p->cost);
			hap = hap + p->cost;
		}
	printf("\n==========================");
	printf("\n 최소 비용 가중치: %3d\n", hap);
	printf("\n\n G2의 인접정점 리스트\n"); printGraph(G2); printf("\n");
}