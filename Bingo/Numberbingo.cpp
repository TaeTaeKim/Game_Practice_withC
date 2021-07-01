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
	//�����Է�
	int number[25] = {};
	int ainumber[25] = {};
	for (int i = 0; i < 25; i++)
	{
		number[i] = i + 1;
		ainumber[i] = i + 1;
	}
	// ���� ����
	int temp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		temp = number[idx1];
		number[idx1] = number[idx2];
		number[idx2] = temp;

		///AI ���ڵ� �����ش�.
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

	//���� ������ AI ���̵� ����.
	while (true)
	{
		printf("1. Easy\n");
		printf("2. Hard\n");
		printf("AI ��带 �����ϼ��� :");
		scanf_s("%d", &iAIMode);
		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
		{
			break;
		}
	}
	//ù ȭ�� ��� ȭ�� ���
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
	// ���þȵ� �迭 ���
	int iNoneselect[25] = {};
	// ���þȵ� ���� ������ ����
	int iNoneselectCount = 0;
	char retry;

	while (true)
	{
		printf("\n[���Ḧ ���ϸ� '0'�� �Է��ϼ���]\n");
		printf("\n[�� ���� %d] [AI ���� %d]\n", bingo, aibingo);
		printf("\n\n���ڸ� �Է��ϼ��� : ");
		scanf_s("%d", &iInput);
		if (iInput == 0)
		{
			printf("\n[������ �����մϴ�]\n");
			break;
		}
		else if (iInput < 1 || iInput>25)
		{
			printf("\n[1���� 25������ ���� �Է��ϼ���]\n");
			continue;
		}
		//����ڰ� ������ ���� INT_MAX�� ����.
		//�ߺ��� �˻��ؾ���
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
		//����� ������ AI���� �ݿ�
		for (int i = 0; i < 25; i++)
		{
			if (iInput == ainumber[i])
			{				
				ainumber[i] = INT_MAX;
				break;
			}
		}
		//AI�� ������ �Ѵ�. AI�� �����ϴ� ���� ��忡 ���� �ٸ�
		int starcount[12] = {};
		int max, lineCount, prCount,selectline,emptycount;
		int candiline[12] = {};
		int prline[4] = { 2,7,10,11 };
		int candivalue[5] = {};
		bool noprbool = true;
		switch (iAIMode)
		{
		case AM_EASY:
			//AI Easy��� : AI ���� ����� *�� �ٲ��� ���� ���� ����� ���� �������� �ϳ��� ����
			iNoneselectCount = 0;
			for (int i = 0; i < 25; i++) {
				if (ainumber[i] != INT_MAX)
				{
					iNoneselect[iNoneselectCount] = ainumber[i];
					iNoneselectCount++;
				}
			}//���þȵ� ��ϰ� ��ϰ���(INoneselectCount)�� ��ȯ.
			iInput = iNoneselect[rand() % iNoneselectCount];
			break;
		case AM_HARD:
			//AI Hard��� : ������ �� �� �߿��� ���� ���ɼ��� ���� ���� ����.
			//���� ������ �ϼ� ���ɼ��� ���� ���� ���� �����ؼ� �� �� ������ �ϳ��� ����.
			//���� 5���� ���� ���� �ϰ� *�� ���� ���� ���� ����

			//�켱 ���� �߾��� ����.
			if (ainumber[12] != INT_MAX)
			{
				iInput = ainumber[12];
			}
			else
			{
				//�߾��� ������ �ȵ������� �� ������ ������ �� ������ ���.
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
				starcount[11] = stars;//�� ���κ� star���� ä��� ��.
				//5���� ������ �ʰ� 0����
				for (int i = 0; i < 12; i++)
				{
					if (starcount[i] == 5) {
						starcount[i] = 0;
					}
				}
				//����ū��ã��
				max = starcount[0];
				for (int i = 0; i < 12; i++)
				{
					if (max < starcount[i])
					{
						max = starcount[i];
					}
				}//max�� �� ���� ���� ������.
				lineCount = 1;
				for (int i = 0; i < 12; i++)
				{
					if (starcount[i] == max)
					{
						candiline[lineCount - 1] = i;
						lineCount++;
					}
				}//���� ���� ���� ���� line�� �ε����� Candiline�� linecountũ�⸸ŭ �� �ִ�.
				//�ϳ��� ���� ���� �ϴµ� ���� �ű⿡ H3,V3,LR,RL�� �ϳ��� ������ �켱 ������ �տ� ��ġ��
				//�켱 ���� �߿��� ���� �ƴҽ� ��ü ���� ���Ƿ� �ϳ� ����.
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
				//selectline�� ���� ������ �� ����. 0~4�� ��� �����࿡�� INT_MAX�� �ƴ� �ϳ�
				//5~9�ϰ�� �����࿡�� �ϳ� 10�ϰ�� �޿����� �ϳ� 11�ϰ�� ���޿��� �ϳ�.
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
		//AI�� ���ڰ� ���õǾ��� �÷��̾�� AI�� ���ڸ� *�� �ٲ��ش�.
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
			printf("*******���� ���Դϴ�. �ٸ� ���� �Է��ϼ���**********\n");
			continue;
		}
		
		//�� ����� �� ���� �� �����.
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
			printf("\n\n============[Player �¸�]================\n\n");
			break;
		}
		else if (aibingo >= 5&& aibingo>bingo)
		{
			printf("\n\n============[AI �¸�]================\n\n");
			break;
		}
		else if (bingo == 5 && aibingo == 5)
		{
			printf("\n\n============== ���º� ==================\\n\n");			
		}
	}
	return 0;
}