#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int arr[]);  // �Լ�����

int main()
{
	int array[6]; // �迭����
	int ifinal;   // ��������

	printf("���ϴ� ������ ���� �Է��ϼ���: ");
	scanf("%d, %d, %d, %d, %d, %d", &array[0], &array[1], &array[2], &array[3], &array[4], &array[5]);

	ifinal = sum(array);
	printf("�Է��� ������ ���� %d�Դϴ�", ifinal);
}

int sum(int arr[])
{
	int icount, itotal; // ��������
	icount = 0, itotal = 0; // �ʱ�ȭ
	for (icount = 0; icount < 6; icount++)
	{
		itotal += arr[icount];
	}

	return itotal;
}