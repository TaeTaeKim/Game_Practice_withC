#include<iostream>
#include<stdio.h>
#include<time.h>


int main()
{
	srand((unsigned int)time(0));
	//숫자 입력
	int number[25] = {};
	for (int i = 0; i < 25; i++)
	{
		number[i] = i + 1;
	}


	// 숫자 셔플
	int temp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		temp = number[idx1];
		number[idx1] = number[idx2];
		number[idx2] = temp;
	}

	//첫 화면 출력 화면 출력
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", number[i * 5 + j]);
		}
		printf("\n");
	}

	int bingo, player;
	int numbingo = 0;
	bool tbingo = true;
	while (true)
	{
		bingo = 0;
		printf("\n[종료를 원하면 '0'을 입력하세요 현재 빙고 : %d]\n", numbingo);
		printf("\n\n숫자를 입력하세요 : ");
		scanf_s("%d", &player);
		if (player == 0)
		{
			printf("\n[게임을 종료합니다]\n");
			break;
		}
		else if (player < 1 || player>25)
		{
			printf("\n[1에서 25사이의 값을 입력하세요]\n");
			continue;
		}
		//사용자가 선택한 값을 INT_MAX로 변경.
		//중복도 검사해야함
		bool bAcc = true;
		for (int i = 0; i < 25; i++)
		{
			if (player == number[i])
			{
				bAcc = false;
				number[i] = INT_MAX;
				break;
			}
		}
		if (bAcc) {
			printf("*******없는 값입니다. 다른 수를 입력하세요**********\n");
			continue;
		}
		//값 변경 후 재출력.
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (number[i * 5 + j] == INT_MAX)
				{
					printf("*\t");
				}
				else
				{
					printf("%d\t", number[i * 5 + j]);
				}

			}
			printf("\n");
		}

		//bingo 값 계산
		for (int i = 0; i < 5; i++)
		{
			tbingo = true;
			for (int j = 0; j < 5; j++)//가로축 빙고확인
			{
				if (number[5 * i + j] != INT_MAX)
				{
					tbingo = false;
				}
			}
			if (tbingo)
			{
				bingo++;
			}
			tbingo = true;
			for (int k = 0; k < 5; k++)//세로축 빙고확인
			{
				if (number[5 * k + i] != INT_MAX)
				{
					tbingo = false;
				}
			}
			if (tbingo)
			{
				bingo++;
			}
		}
		tbingo = true;
		for (int i = 0; i < 5; i++)
		{
			if (number[i * 6] != INT_MAX)
			{
				tbingo = false;
			}
		}
		if (tbingo)
		{
			bingo++;
		}
		tbingo = true;
		for (int i = 0; i < 5; i++)
		{
			if (number[(i + 1) * 4] != INT_MAX)
			{
				tbingo = false;
			}
		}
		if (tbingo)
		{
			bingo++;
		}

		numbingo = bingo;
		if (numbingo == 5)
		{
			printf("\n\n<><><><><><>축하합니다 [5빙고] 달성<><><><><><><><>\n\n");
			break;
		}
	}

	return 0;
}