// black_friday.c
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(void) {
	// 3D 포인터 선언
	int*** inventory; // 물건

	// 차원 정의
	int stores = 2; // 매장 수
	int depts = 3;  // 부서 수
	int items = 4;  // 항목당 수

	printf("============= BLACK FRIDAY INVENTORY SYSTEM ==============\n\n");

	// 1D 할당: 매장 포인터 할당
	inventory = (int***)malloc(stores * sizeof(int**));
	printf("[단계 1] 매장 포인터 할당 (2D)\n");

	// 2D 할당: 각 매장의 부서 포인터 할당
	for (int i = 0; i < stores; i++) {
		inventory[i] = (int**)malloc(depts * sizeof(int*));
	}
	printf("[단계 2] 각 매장의 부서 (2 * 3 = 6 포인터)\n");

	// 3D 할당: 각 부서의 항목 포인터 할당
	for (int i = 0; i < stores; i++) {
		for (int j = 0; j < depts; j++) {
			inventory[i][j] = (int*)malloc(items * sizeof(int));
		}
	}
	printf("[단계 3] 각 부서의 항목 할당 (2 * 3 * 4 = 24 포인터)\n");
	printf("총 메모리: 24 * %lu bytes = %lu bytes\n\n",
		sizeof(int), 24 * sizeof(int));

	// 샘플 데이터 (세일 가격!)
	int sample_prices[2][3][4] = {
		// 매장 1: Emart
		{
			{299, 149, 79, 199}, // 전자제품 (TV, Headphones, USB, 
			{39, 59, 29, 49}, // 의류 (Pants, Shirt, Socks, Hat)
			{89, 129, 49 ,59} // 가정용품 (...)
		},
		// 매장 2: costco
		{
			{329, 159, 89, 179}, // 전자제품 (TV, Headphones, USB, 
			{35, 55, 25, 45}, // 의류 (Pants, Shirt, Socks, Hat)
			{99, 119, 59 ,69} // 가정용품 (...)
		},
	};

	// 동적 할당된 메모리에 데이터 복사
	for (int i = 0; i < stores; i++) {
		for (int j = 0; j < depts; j++) {
			for (int k = 0; k < items; k++) {
				inventory[i][j][k] = sample_prices[i][j][k];
			}
		}
	}

	printf("============= Inventory Data ==============\n\n");

	char* dept_names[] = { " Electronics ", " Clothing ", " HOME " };

	// 동적 할당된 메모리에 데이터 복사
	for (int i = 0; i < stores; i++) {
		printf(" [ Store %d ] \n", i + 1);
		for (int j = 0; j < depts; j++) {
			printf("  - %s: ", dept_names[j]);
			for (int k = 0; k < items; k++) {
				printf("$%d ", inventory[i][j][k]);
				if (k < items - 1) printf("| ");
			}
			printf("\n");
		}
		printf("\n");
	}

	printf("============= Inventory Data ==============\n\n");

	// 3D 배열부터...
	for (int i = 0; i < stores; i++) {
		for (int j = 0; j < depts; j++) {
			free(inventory[i][j]);
			printf("[해제] 매장 %d, 부서 %d의 항목 배열 해제\n",
				i + 1, j + 1);
		}
	}
	printf("\n");

	// 2D 배열부터...
	for (int i = 0; i < stores; i++) {
			free(inventory[i]);
			printf("[해제] 매장 %d, 부서 배열 해제\n", i + 1);
	}
	printf("\n");

	// 1D...
	free(inventory);
	printf("[해제] 매장 배열 해제\n");

	printf("모든 메모리가 안전하게 해제되었습니다!\n");

	return 0;
}