#include<iostream>
#include<time.h>
#include<stdio.h>

enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};
enum LINE
{
	H1,
	H2,
	H3,
	H4,
	H5,
	V1,
	V2,
	V3,
	V4,
	V5,
	LR,
	RL
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
			printf("?\t");
		}
		printf("\n");
	}
	// 선택안된 배열 목록
	int iNoneselect[25] = {};
	// 선택안된 숫자 개수를 저장
	int iNoneselectCount = 0;
	char retry;

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
		int starcount[12] = {};
		int max, lineCount, prCount,selectline,emptycount;
		int candiline[12] = {};
		int prline[4] = { 2,7,10,11 };
		int candivalue[5] = {};
		bool noprbool = true;
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

			//우선 가장 중앙을 선택.
			if (ainumber[12] != INT_MAX)
			{
				iInput = ainumber[12];
			}
			else
			{
				//중앙이 선택이 안되있으면 각 가능한 라인의 별 개수를 계산.
				int hstars, vstars;
				for (int i = 0; i < 5; i++)
				{
					hstars = vstars = 0;
					for (int j = 0; j < 5; j++)
					{
						if (ainumber[i * 5 + j] == INT_MAX)
						{
							hstars++;
						}
					}
					starcount[i] = hstars;

					for (int h = 0; h < 5; h++)
					{
						if (ainumber[h * 5 + i] == INT_MAX)
						{
							vstars++;
						}
					}
					starcount[i + 5] = vstars;
				}
				int stars;
				stars = 0;
				for (int i = 0; i < 25; i += 6)
				{
					if (ainumber[i] == INT_MAX)
					{
						stars++;
					}
				}
				starcount[10] = stars;

				stars = 0;
				for (int i = 4; i < 21; i += 4)
				{
					if (ainumber[i] == INT_MAX)
					{
						stars++;
					}
				}
				starcount[11] = stars;//각 라인별 star개수 채우기 끝.
				//5개면 뽑히지 않게 0으로
				for (int i = 0; i < 12; i++)
				{
					if (starcount[i] == 5) {
						starcount[i] = 0;
					}
				}
				//가장큰값찾기
				max = starcount[0];
				for (int i = 0; i < 12; i++)
				{
					if (max < starcount[i])
					{
						max = starcount[i];
					}
				}//max는 즉 가장 많은 별개수.
				lineCount = 1;
				for (int i = 0; i < 12; i++)
				{
					if (starcount[i] == max)
					{
						candiline[lineCount - 1] = i;
						lineCount++;
					}
				}//가장 많은 별을 가진 line의 인덱스가 Candiline의 linecount크기만큼 들어가 있다.
				//하나의 라인 선택 하는데 만약 거기에 H3,V3,LR,RL이 하나라도 있으면 우선 라인은 앞에 배치후
				//우선 라인 중에서 선택 아닐시 전체 에서 임의로 하나 뽑음.
				prCount = 0;
				for (int i = 0; i < lineCount; i++)
				{
					if (candiline[i] == H3 || candiline[i] == V3 || candiline[i] == LR || candiline[i] == RL)
					{
						noprbool = false;
						for (int j = 0; j < 4; j++)
						{
							if (candiline[i] == prline[j])
							{
								candiline[prCount] = prline[j];
								prCount++;
								continue;
							}
						}

					}
				}
				if (noprbool == false)
				{
					selectline = candiline[rand() % prCount];
				}
				if (noprbool)
				{
					selectline = candiline[rand() % lineCount];
				}
				//selectline에 쁩을 라인이 들어가 있음. 0~4일 경우 가로축에서 INT_MAX가 아닌 하나
				//5~9일경우 세로축에서 하나 10일경우 왼오에서 하나 11일경우 오왼에서 하나.
				if (selectline >= 0 && selectline <= 4)
				{
					emptycount = 0;
					for (int i = 0; i < 5; i++)
					{
						if (ainumber[selectline * 5 + i] != INT_MAX)
						{
							candivalue[emptycount] = ainumber[selectline * 5 + i];
							emptycount++;
						}
					}
					iInput = candivalue[rand() % emptycount];
				}
				else if (selectline >= 5 && selectline <= 9)
				{
					emptycount = 0;
					for (int i = 0; i < 5; i++)
					{
						if (ainumber[(selectline - 5) + (i * 5)] != INT_MAX)
						{
							candivalue[emptycount] = ainumber[(selectline - 5) + (i * 5)];
							emptycount++;
						}
					}
					iInput = candivalue[rand() % emptycount];
				}
				else if (selectline == 10)
				{
					emptycount = 0;
					for (int i = 0; i < 25; i += 6)
					{
						if (ainumber[(selectline - 10) + i] != INT_MAX)
						{
							candivalue[emptycount] = ainumber[(selectline - 10) + i];
							emptycount++;
						}
					}
					iInput = candivalue[rand() % emptycount];
				}
				else
				{
					emptycount = 0;
					for (int i = 4; i < 21; i += 4)
					{
						if (ainumber[(selectline - 11) + i] != INT_MAX)
						{
							candivalue[emptycount] = ainumber[(selectline - 11) + i];
							emptycount++;
						}
					}
					iInput = candivalue[rand() % emptycount];
				}
			}
			

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
					printf("?\t");
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
		if (bingo >= 5&& bingo>aibingo)
		{
			printf("\n\n============[Player 승리]================\n\n");
			break;
		}
		else if (aibingo >= 5&& aibingo>bingo)
		{
			printf("\n\n============[AI 승리]================\n\n");
			break;
		}
		else if (bingo == 5 && aibingo == 5)
		{
			printf("\n\n============== 무승부 ==================\\n\n");			
		}
	}
	return 0;
}