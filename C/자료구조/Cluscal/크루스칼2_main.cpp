// 간선을 가중치 순으로 오름차순 정렬한다
// 정점을 모두 추가한 상태에서 최소 가중치의 간선을 차례로 추가한다
// 추가된 간선으로 인하여 루프가 형성되지 않도록 한다
// 간선의 수는 [정점수 - 1]을 만족하여야 한다
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cluscal_2.h"

enum { A, B, C, D, E, F, G, H, I, J };

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
	for (a = 0; a < SU1; a++) {
		insertEdge(G1, edgeAddr[a]); entry[a] = 0;
	}

	//-------------------------------------------------------------- 정점별 인접 노드 출력
	printf("\n G1의 인접정점 리스트\n"); printGraph(G1); printf("\n");

	//-------------------------------------------------------------- 간선 자료 오림차순 정렬
	sorting(edgeAddr, ASCEND, SU1);

	//-------------------------------------------------------------- 새 그래프 생성하여
	EdgeType* G2 = (EdgeType*)malloc(sizeof(EdgeType));
	createGraph(G2, V1); for (a = 0; a < V1; a++) insertVertex(G2, a);

	//---------------- 간선의 가중치가 작은 것부터 그래프에 추가. 순환되지 않도록
	int* Chk_Vertex = (int*)malloc(sizeof(int) * V1 * 2);	//-- 연결 정점 배열
	memset(Chk_Vertex, 0, sizeof(int) * V1 * 2);
	int from, to, hap = 0, Dcnt = 0; // 간선 수

	//-------------------------------------------------------------- 추가할 모든 간선에 대하여
	for (a = 0; a < SU1; a++) {
		p = edgeAddr[a]; from = p->v_from; to = p->v_to;
		if (Dcnt + 1 >= V1) break;
		++Chk_Vertex[from]; ++Chk_Vertex[to + V1];	// 일단 추가한 후
		if (Except(Chk_Vertex, V1, Dcnt + 1)) {		// 배제조건에 해당되면 추가 취소
			--Chk_Vertex[from]; --Chk_Vertex[to + V1];
		}
		else {										// 그렇지 않으면 추가 확정
			printf("\n(%c, %c) %d 추가", from + 65, to + 65, p->cost);
			insertEdge(G2, p); entry[a] = 1; Dcnt++; hap = hap + p->cost;
		}
	} printf("\n");
	printf("\n==========================");
	printf("\n 최소 비용 가중치: %3d\n", hap);
	printf("\n\n G2의 인접정점 리스트\n"); printGraph(G2); printf("\n");
}