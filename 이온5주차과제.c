#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void Get_Array(int* ar, int len);
void Get_Commands(int** ca, int len);
int* Solution(int* ar, int** ca, int len);
int Sort_Find(int* sr, int srlen, int g_index);

int main()
{
	int arrlen, comlen;

	do
	{
		printf("배열의 길이를 적어주세요 : ");
		scanf("%d", &arrlen);
	} while (arrlen < 1 || arrlen > 100);

	int* array;
	array = (int*)malloc(sizeof(int) * arrlen);

	Get_Array(array, arrlen);

	do
	{
		printf("명령 수를 적어주세요 : ");
		scanf("%d", &comlen);
	} while (comlen < 1 || comlen > 50);

	int** commands;
	commands = (int**)malloc(sizeof(int*) * comlen);
	for (int iCount = 0; iCount < comlen; iCount++)
	{
		commands[iCount] = (int*)malloc(sizeof(int) * 3);
	}

	Get_Commands(commands, comlen);

	int* result_array;
	result_array = (int*)malloc(sizeof(int) * comlen);

	result_array = Solution(array, commands, comlen);

	printf("결과입니다.\n[");
	for (int ic = 0; ic < comlen - 1; ic++)
	{
		printf("%d, ", result_array[ic]);
	}
	printf("%d]", result_array[comlen - 1]);

	free(array);
	free(commands);
	free(result_array);

	return 0;
}

void Get_Array(int* ar, int len)
{
	int ic = 0;

	do
	{
		printf("정수를 입력하세요 : ");
		scanf("%d", ar + ic);
		if (*(ar + ic) >= 1 && *(ar + ic) <= 100)
		{
			ic++;
		}
		else
		{
			printf("[오류]다시 입력해주세요\n");
		}
	} while (ic < len);

	printf("입력하신 배열은 [");
	for (ic = 0; ic < len - 1; ic++)
	{
		printf("%d, ", *(ar + ic));
	}
	printf(" %d] 입니다.\n\n", *(ar + len - 1));

}

void Get_Commands(int** ca, int len)
{
	int ic = 0;

	do
	{
		printf("%d번째 명령입니다.\n", ic + 1);
		printf("시점을 입력해 주세요 : ");
		scanf("%d", ca[ic]);


		do
		{
			printf("종점을 입력해 주세요 : ");
			scanf("%d", ca[ic] + 1);
			if (ca[ic][0] > ca[ic][1])
			{
				printf("시점이 종점보다 뒤에 있습니다.\n");
			}
		} while (ca[ic][0] > ca[ic][1]);

		do
		{
			printf("몇번째 수를 원하는지 입력해주세요 : ");
			scanf("%d", ca[ic] + 2);
			if (ca[ic][2] > ca[ic][1] - ca[ic][0] + 1)
			{
				printf("구간을 벗어납니다.\n");
			}
		} while (ca[ic][2] > ca[ic][1] - ca[ic][0] + 1);

		ic++;

	} while (ic < len);

	printf("입력하신 명령입니다.\n");
	for (ic = 0; ic < len; ic++)
	{
		printf("%d번째 명령 : [%d, %d, %d]\n", ic + 1, ca[ic][0], ca[ic][1], ca[ic][2]);
	}
	printf("\n");
}

int* Solution(int* ar, int** ca, int len)
{
	int* result_arr;
	result_arr = (int*)malloc(sizeof(int) * len);

	int ic1, ic2;

	for (ic1 = 0; ic1 < len; ic1++)
	{
		int slen;
		slen = ca[ic1][1] - ca[ic1][0] + 1;

		int* sarr;
		sarr = (int*)malloc(sizeof(int) * slen);

		for (ic2 = 0; ic2 < slen; ic2++)
		{
			sarr[ic2] = ar[ca[ic1][0] - 1 + ic2];
		}

		result_arr[ic1] = Sort_Find(sarr, slen, ca[ic1][2] - 1);

		free(sarr);

	}

	return result_arr;
}

int Sort_Find(int* sr, int srlen, int g_index)
{
	int ic1, ic2, temp;


	for (ic1 = 0; ic1 < srlen - 1; ic1++)
	{
		for (ic2 = 0; ic2 < srlen - 1 - ic1; ic2++)
		{
			if (sr[ic2] > sr[ic2 + 1])
			{
				temp = sr[ic2];
				sr[ic2] = sr[ic2 + 1];
				sr[ic2 + 1] = temp;
			}
		}
	}

	return sr[g_index];
}