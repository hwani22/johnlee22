#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int array[6];
	int icount, iuse, isum, temp;
	printf("���ϴ� ���� 6���� �Է��ϼ���.");
	for (icount = 0; icount < 6; icount++)
	{
		scanf("%d", &array[icount]);
	}
		for (iuse = 0; iuse < 5; iuse++)
		{
			for(isum=0; isum<5; isum++)
			{ 
			if (array[isum] > array[isum + 1])
			{
				temp = array[isum];
				array[isum] = array[isum + 1];
				array[isum + 1] = temp;
			}
		}
	}
	printf("%d, %d, %d, %d, %d, %d", array[0], array[1], array[2], array[3], array[4], array[5]);

}
