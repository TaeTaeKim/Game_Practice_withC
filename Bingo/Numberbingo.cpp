#include<iostream>
#include<time.h>
#include<stdio.h>

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};
enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

int main()
{
	srand((unsigned int)time(0));
	//숫자입력
	int number[25] = {};
	int ainumber[25] = {};
	for (int i = 0; i < 25; i++)
	{
		number[i] = i + 1;
		ainumber[i] = i + 1;
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

		///AI 숫자도 섞어준다.
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		temp = ainumber[idx1];
		ainumber[idx1] = ainumber[idx2];
		ainumber[idx2] = temp;
	}

	

	int bingo = 0, aibingo = 0;
	int iInput;
	int numbingo = 0;
	bool tbingo = true;
	int iAIMode;

	//게임 시작전 AI 난이도 선택.
	while (true)
	{
		printf("1. Easy\n");
		printf("2. Hard\n");
		printf("AI 모드를 선택하세요 :");
		scanf_s("%d", &iAIMode);
		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
		{
			break;
		}
	}
	//첫 화면 출력 화면 출력
	system("cls");
	printf("\n\n============== Player ================\n\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", number[i * 5 + j]);
		}
		printf("\n");
	}
	printf("\n\n============== AI ================\n\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%d\t", ainumber[i * 5 + j]);
		}
		printf("\n");
	}
	// 선택안된 배열 목록
	int iNoneselect[25] = {};
	// 선택안된 숫자 개수를 저장
	int iNoneselectCount = 0;


	while (true)
	{
		printf("\n[종료를 원하면 '0'을 입력하세요]\n");
		printf("\n[내 빙고 %d] [AI 빙고 %d]\n", bingo, aibingo);
		printf("\n\n숫자를 입력하세요 : ");
		scanf_s("%d", &iInput);
		if (iInput == 0)
		{
			printf("\n[게임을 종료합니다]\n");
			break;
		}
		else if (iInput < 1 || iInput>25)
		{
			printf("\n[1에서 25사이의 값을 입력하세요]\n");
			continue;
		}
		//사용자가 선택한 값을 INT_MAX로 변경.
		//중복도 검사해야함
		bool bAcc = true;
		for (int i = 0; i < 25; i++)
		{
			if (iInput == number[i])
			{
				bAcc = false;
				number[i] = INT_MAX;
				break;
			}
		}
		//사용자 선택을 AI에도 반영
		for (int i = 0; i < 25; i++)
		{
			if (iInput == ainumber[i])
			{				
				ainumber[i] = INT_MAX;
				break;
			}
		}
		//AI가 선택을 한다. AI가 선택하는 것은 모드에 따라 다름
		switch (iAIMode)
		{
		case AM_EASY:
			//AI Easy모드 : AI 숫자 목록중 *로 바뀌지 않은 숫자 목록을 만들어서 랜덤으로 하나를 선택
			iNoneselectCount = 0;
			for (int i = 0; i < 25; i++) {
				if (ainumber[i] != INT_MAX)
				{
					iNoneselect[iNoneselectCount] = ainumber[i];
					iNoneselectCount++;
				}
			}//선택안된 목록과 목록개수(INoneselectCount)가 반환.
			iInput = iNoneselect[rand() % iNoneselectCount];
			break;
		case AM_HARD:
			//AI Hard모드 : 빙고가능 한 줄 중에서 빙고 가능성이 높은 줄을 선택.
			//현재 빙고줄 완성 가능성이 가장 높은 줄을 선택해서 그 줄 숫자중 하나를 선택.
			//별이 5개인 줄을 제외 하고 *이 가장 많은 줄을 선택
			int iLine, iStarCount;
			break;
		}
		//AI의 숫자가 선택되었음 플레이어와 AI의 숫자를 *로 바꿔준다.
		for (int i = 0; i < 25; i++)
		{
			if (number[i] == iInput)
			{
				number[i] = INT_MAX;
				break;
			}
		}
		for (int i = 0; i < 25; i++)
		{
			if (ainumber[i] == iInput)
			{
				ainumber[i] = INT_MAX;
				break;
			}
		}

		if (bAcc) {
			printf("*******없는 값입니다. 다른 수를 입력하세요**********\n");
			continue;
		}
		
		//둘 모두의 값 변경 후 재출력.
		system("cls");
		printf("\n\n============== Player ================ \n\n");
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
		printf("\n\n==============   AI ==================  \n\n");
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (ainumber[i * 5 + j] == INT_MAX)
				{
					printf("*\t");
				}
				else
				{
					printf("%d\t", ainumber[i * 5 + j]);
				}

			}
			printf("\n");
		}


		bingo = aibingo =0;
		int istar1 = 0, istar2 = 0;
		int iaistar1 = 0, iaistar2 = 0;
		for (int i = 0; i < 5; i++)
		{
			istar1 = istar2 = 0;
			iaistar1 = iaistar2 = 0;
			for (int j = 0; j < 5; j++)
			{
				if (number[i * 5 + j] == INT_MAX)
				{
					istar1++;
				}
				if (number[j * 5 + i] == INT_MAX)
				{
					istar2++;
				}
				if (ainumber[i * 5 + j] == INT_MAX)
				{
					iaistar1++;
				}
				if (ainumber[j * 5 + i] == INT_MAX)
				{
					iaistar2++;
				}
			}
			if (istar1 == 5)
				bingo++;
			if (istar2 == 5)
				bingo++;
			if (iaistar1 == 5)
				aibingo++;
			if (iaistar2 == 5)
				aibingo++;
		}
		istar1 = iaistar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (number[i] == INT_MAX)
			{
				istar1++;
			}
			if (ainumber[i] == INT_MAX)
			{
				iaistar1++;
			}
		}
		if (istar1 == 5)
			bingo++;
		if (iaistar1 == 5)
			aibingo++;
		istar2 = iaistar2 = 0;
		for (int i = 1;i<=5;i++)
		{
			if (number[i*4] == INT_MAX)
			{
				istar2++;
			}
			if (ainumber[i * 4] == INT_MAX)
			{
				iaistar2++;
			}
		}
		if (istar2 == 5)
			bingo++;
		if (iaistar2 == 5)
			aibingo++;



		if (bingo >= 5)
		{
			printf("\n\n============[Player 승리]================\n\n");
			break;
		}
		else if (aibingo >= 5)
		{
			printf("\n\n============[AI 승리]================\n\n");
			break;
		}
	}



	return 0;
}