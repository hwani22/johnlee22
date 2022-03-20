#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int arr[]);  // 함수선언

int main()
{
	int array[6]; // 배열선언
	int ifinal;   // 변수선언

	printf("원하는 값들을 전부 입력하세요: ");
	scanf("%d, %d, %d, %d, %d, %d", &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);

	ifinal = sum(array);
	printf("입력한 값들의 합은 %d입니다", ifinal);
}

int sum(int arr[])
{
	int icount, itotal; // 변수선언
	icount = 0, itotal = 0; // 초기화
	for (icount = 0; icount < 6; icount++)
	{
		itotal += arr[icount];
	}

	return itotal;
}