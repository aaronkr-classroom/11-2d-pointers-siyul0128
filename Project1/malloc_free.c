// malloc_free.c
#include <stdio.h>

void Test() {
	// 합에 200바이트 할당함
	short* p = (short*)malloc(100);
	// free(p); // 실수로 메모리 할당을 해제 안 하면...
}

int main(void) {
	int i;
	// 메모리가 100 바이트씩 100번 동적 할당됨
	for (i = 0; i < 100; i++) Test();
	return 0;
}