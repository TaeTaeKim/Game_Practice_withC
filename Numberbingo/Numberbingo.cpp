#include<iostream>
#include<stdio.h>
#include<time.h>


int main()
{
	srand((unsigned int)time(0));
	//���� �Է�
	int number[25] = {};
	for (int i = 0; i < 25; i++)
	{
		number[i] = i + 1;
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
	}

	//ù ȭ�� ��� ȭ�� ���
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
		printf("\n[���Ḧ ���ϸ� '0'�� �Է��ϼ��� ���� ���� : %d]\n", numbingo);
		printf("\n\n���ڸ� �Է��ϼ��� : ");
		scanf_s("%d", &player);
		if (player == 0)
		{
			printf("\n[������ �����մϴ�]\n");
			break;
		}
		//����ڰ� ������ ���� INT_MAX�� ����.
		for (int i = 0; i < 25; i++)
		{
			if (player == number[i])
			{
				number[i] = INT_MAX;
			}
		}
		//�� ���� �� �����.
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

		//bingo �� ���
		for (int i = 0; i < 5; i++)
		{
			tbingo = true;
			for (int j = 0; j < 5; j++)//������ ����Ȯ��
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
			for (int k = 0; k < 5; k++)//������ ����Ȯ��
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
			printf("\n\n<><><><><><>�����մϴ� [5����] �޼�<><><><><><><><>\n\n");
			break;
		}
	}

	return 0;
}