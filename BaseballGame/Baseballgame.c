#include<stdio.h>
#include<time.h>

int main(void) {
	printf("<><><><><><>������ �����մϴ�<><><><><><>\n");
	printf("0 0 0�� �Է��ϸ� ������ ����˴ϴ�\n\n\n");
	printf("7ȸ �ȿ� ���� ���߼��� * * *");
	srand(time(NULL));
	int number[9] = { 1,2,3,4,5,6,7,8,9 };
	int temp, idx1, idx2;
	///suffle 
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 9;
		idx2 = rand() % 9;
		temp = number[idx1];
		number[idx1] = number[idx2];
		number[idx2] = temp;
	}
	int answer[3] = { number[0],number[1],number[2] };
	int time = 0;

	//printf("[[[Answer : %d %d %d]]]", answer[0], answer[1], answer[2]);
	int g1 = 0;
	int g2 = 0;
	int g3 = 0;
	int guess[3] = { g1,g2,g3 };
	while (answer != guess) {
		int strike = 0;
		int ball = 0;
		time++;
		printf("\n\n\n=====Input your guess [1~9]====");
		scanf_s("%d %d %d", &g1, &g2, &g3);
		if (g1 > 9 || g2 > 9 || g3 > 9) {
			printf("\n[Warning]�� �ڸ��� ���� �Է��ϼ���\n");
			time--;
			continue;
		}
		if (g1 == 0 && g2 == 0 && g3 == 0) {
			printf("\n\nQuit the Game\n");
			printf("The answer was %d %d %d\n\n\n", answer[0], answer[1], answer[2]);
			break;
		}
		int guess[3] = { g1,g2,g3 };
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (guess[i] == answer[j]) {
					if (i == j) {
						strike++;
					}
					else {
						ball++;
					}
				}
			}
		}
		if (strike == 3) {
			printf("\n\n*********<><><><><><><>!! 3 strike !!<><><><><><><>*********\n\n");
			printf("You catch in %d times\n", time);
			break;
		}
		else if (time >= 7) {
			printf("\n\n --------Game over-----------\n\n");
			printf("7ȸ�ȿ� ���� ���߽��ϴ�.\n");
			break;
		}
		else {
			printf("\n\n||| %d strike ||| %d ball ||| %d��° �õ�\n\n", strike, ball, time);
		}

	}
	return 0;
}