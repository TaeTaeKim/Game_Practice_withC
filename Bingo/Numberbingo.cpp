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
			printf("%d\t", ainumber[i * 5 + j]);
		}
		printf("\n");
	}
	// ���þȵ� �迭 ���
	int iNoneselect[25] = {};
	// ���þȵ� ���� ������ ����
	int iNoneselectCount = 0;


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
			int iLine, iStarCount;
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
			printf("\n\n============[Player �¸�]================\n\n");
			break;
		}
		else if (aibingo >= 5)
		{
			printf("\n\n============[AI �¸�]================\n\n");
			break;
		}
	}



	return 0;
}