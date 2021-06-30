#include<stdio.h>
#include<time.h>

void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);
void initData();
void printFishes();
void decreaseWater(long timedelta);

int level;
int arrayFish[6]; //�������� ���� 6���� ���Ҹ� ���� array
int* cursor; //cursor��� ������ ���� ����. ���� �ִ� ���.


int main(void) {
	//// ������
	//
	//// ö�� : 101ȣ -> �޸� ������ �ּ�
	//// ���� : 201ȣ
	//// �μ� : 301ȣ
	//// �� �� �տ� '��ȣ'�� �ɷ�����

	//int ö�� = 1;//pwd
	//int ���� = 2;
	//int �μ� = 3;

	//
	//

	//printf("address of ö�� : %d, pwd: %d\n", &ö��, ö��);//�ּ�(�޸� �ּ�)�� ��Ÿ���� ����
	//printf("address of ���� : %d, pwd: %d\n", &����, ����);//���� �տ� &���� (scanf_s)�Ҵ���ó�� !!�Ҵ��ڰ� �� �� �޸� �ּҿ� ���� �ִ´ٴ� ���
	//printf("address of �μ� : %d, pwd: %d\n", &�μ�, �μ�);


	////�̼Ǹ��� ����

	////ù��° : ����Ʈ�� �� ���� �湮�Ͽ� ���� ���� ��ȣ Ȯ��
	//int* �̼Ǹ�;//������ ���� ���� with *
	//�̼Ǹ� = &ö��; // �̼Ǹ��� ö���� �ּҸ� ����
	//printf("�̼Ǹ��� �湮 �ϴ� ���� �ּ� : %d, ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);//*�̼Ǹ����� �ش� �ּ��� �� Ȯ��

	//�̼Ǹ� = &����;
	//printf("�̼Ǹ��� �湮 �ϴ� ���� �ּ� : %d, ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);

	//�̼Ǹ� = &�μ�;
	//printf("�̼Ǹ��� �湮 �ϴ� ���� �ּ� : %d, ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);

	////�ι�° �̼� : �� ��ȣ�� 3�� ���ض�
	//�̼Ǹ� = &ö��;
	//*�̼Ǹ� = *�̼Ǹ� * 3;
	//printf("�̼Ǹ��� ��ȣ�� �ٲ� ���� �ּ� : %d, �ٲ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);
	//�̼Ǹ� = &����;
	//*�̼Ǹ� = *�̼Ǹ� * 3;
	//printf("�̼Ǹ��� ��ȣ�� �ٲ� ���� �ּ� : %d, �ٲ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);
	//�̼Ǹ� = &�μ�;
	//*�̼Ǹ� = *�̼Ǹ� * 3;
	//printf("�̼Ǹ��� ��ȣ�� �ٲ� ���� �ּ� : %d, �ٲ��ȣ : %d\n", �̼Ǹ�, *�̼Ǹ�);


	//// �������� ����
	//// �̼Ǹ��� �ٲ� ��ȣ���� 2�� ����!! (�̼Ǹǵ� ��)
	//int* ������ = �̼Ǹ�; // �� ������ ������ �ϳ��� ���� �޸� �ּҸ� ����Ŵ
	//printf("\n ...�����̰� �̼��� �����ϴ� ��... \n");
	//������ = &ö��;
	//*������ = *������ - 2;
	//printf("�����̰� �湮�ϴ� �� �ּ� : %d, ��ȣ : %d\n", ������, *������);
	//������ = &����;
	//*������ = *������ - 2;
	//printf("�����̰� �湮�ϴ� �� �ּ� : %d, ��ȣ : %d\n", ������, *������);
	//������ = &�μ�;
	//*������ = *������ - 2;
	//printf("�����̰� �湮�ϴ� �� �ּ� : %d, ��ȣ : %d\n", ������, *������);

	//printf("\n\nö�� ���� �μ��� ���� ���ƿ� �ٲ� ��ȣ�� ���� ���\n\n");

	//printf("address of ö�� : %d, pwd: %d\n", &ö��, ö��);
	//printf("address of ���� : %d, pwd: %d\n", &����, ����);
	//printf("address of �μ� : %d, pwd: %d\n", &�μ�, �μ�);
	////���⼭ ������ �ٸ��� ���� ������ x = y�� y = 10�ص� �ٲ��� ����.
	////������ ������ ����Ű�� ������ ���� �ǽð� �����Ѵ�.
	////���� �����͵鵵 ������ �޸� �ּҰ� �ִ�

	//printf("\n\n�̼Ǹ��� ��� �ּ� : %d\n", &�̼Ǹ�); //�������� �̼Ǹ� = &ö���� �̼Ǹ� ���� �ּҸ� ����.
	//printf("�����̰� ��� �ּ� : %d\n", &������);


	//// �迭�� ������
	//int arr[3] = { 5,10,15 };
	//int* ptr = arr; //���⼭�� �����Ϳ� �ּҰ��� �ƴ� �迭���� �״�� ������.
	//for (int i = 0; i < 3; i++) {
	//	printf("�迭 arr[%d] �� �� : %d\n", i, arr[i]);
	//}
	//for (int i = 0; i < 3; i++) {
	//	printf("������ ptr[%d] �� �� : %d\n", i, ptr[i]);
	//}
	//ptr[0] = 100;
	//ptr[1] = 200;
	//ptr[2] = 300;
	//for (int i = 0; i < 3; i++) {
	//	printf("�迭 arr[%d] �� �� : %d\n", i, arr[i]);
	//	printf("�迭 arr[%d] �� �� : %d\n", i, *(arr+i));//arr�ּҰ��� ���� ������ ���� ����.
	//}
	//for (int i = 0; i < 3; i++) {
	//	printf("������ ptr[%d] �� �� : %d\n", i, ptr[i]);
	//}
	////*(arr+i) == arr[i] �Ȱ��� ǥ��
	//// arr== (arr �迭�� ù��° ���� �ּҿ� ����) ==&arr[0]
	//printf("arr �ּ� %d\n", arr);
	//printf("arr[0]�� �ּ� : %d\n", &arr);
	//printf("arr �ּҰ� ������ ���� �� %d\n", *arr);// == *(arr+0)
	//printf("arr[0] �ּҰ� ������ ���� �� %d\n", *&arr[0]);


	////// *& �� �ƹ��͵� ���� �Ͱ� ���� &�� �ּ� *�� �ּ��ǰ� ==> ���
	////printf("arr[0] �ּҰ� ������ ���� �� %d\n", *&*&*&*&*&*&*&*&*&*&*&*&*&*&*&arr[0]);
	////printf("arr[0] �ּҰ� ������ ���� �� %d\n", arr[0]);

	//int a = 10;
	//int b = 20;
	//printf("Address of a : %d\n", &a);
	//printf("Address of b : %d\n", &b);
	////a �� b�� ���� �ٲ۴� swap
	//printf("Before swaping => a : %d, b = %d\n", a, b);
	//swap(a, b);
	//printf("After swaping => a : %d,b = %d\n\n\n", a, b);

	////���� ���� ����(Call by value) -> ���� �����Ѵٴ� �ǹ� �� �Լ��� ������ ������ ���°� �ƴ� ���� �ش�.
	////�ּҰ��� �ѱ��?? �޸� �ִ� ������ �ּҸ� �ѱ��?
	//printf("(�ּҰ� ����) Before swaping => a : %d, b = %d\n", a, b);
	//swap_addr(&a, &b);
	//printf("(�ּҰ� ����) After swaping => a : %d,b = %d\n\n\n", a, b);

	//������Ʈ ����� �����
	//����� 6���� ���׿� �縷�� ��Ƽ� ���� �����Ѵ�.
	// ���� �� �����ϱ� ���� �������� ���׿� ���� �༭ ����⸦ ����ּ���
	// ������ �ð��� �������� Ŀ���� ���� ���� ���� ����


	long starTime = 0; // ���� ���۽ð� �ð��� long ������
	long totalTime = 0;// �� ��� �ð�
	long prevTime = 0;//���������� ���� �� �ð�

	int num; //��� ���׿� ���� �� ������, ����� �Է�
	initData();

	cursor = arrayFish;// cursor�� ��̸� �����ؼ� ������� ����

	starTime = clock(); //���� �ð��� millisecond(1000���� 1��)
	while (1) {
		printFishes();
		printf("�� �� ���׿� ���� �ֽðھ��? : ");
		scanf_s("%d", &num);

		//�Է°� üũ
		if (num < 1 || num>6) {
			printf("\n\n�Է°��� �߸��Ǿ����ϴ�.\n\n");
			continue;
		}

		//�� ��� �ð�
		totalTime = (clock() - starTime) / CLOCKS_PER_SEC; //�ʴ����� ��ȯ.
		printf("�� ��� �ð� : %ld ��\n", totalTime); //�ð� �������� ld�� ȣ��

		//���������� ���� �� �ð� ���ķ� �帥 �ð�(�󸶸��� ���� �ᳪ)
		prevTime = totalTime - prevTime;
		printf("�� ���� ���� %ld ��\n", prevTime);

		//���� �� ���߽�Ű��
		decreaseWater(prevTime);
		//����ڰ� �Է��� ���׿� ���� �ش�.
		//1. ������ ���� 0�̸� ���� �����ʴ´�
		if (cursor[num - 1] <= 0) {
			printf("%d �� ������ �̹� �׾����ϴ�.. ���� ���� �ʽ��ϴ�.", num);
		}
		//2. ���׿� ���� 0�� �ƴϸ�? 100�� ���� �ȵ��� �����.
		else if (cursor[num - 1] + 1 <= 100) {
			printf("%d �� ���׿� ���� �ݴϴ�.\n\n", num);
			cursor[num - 1] += 3;
		}

		//�������� �Ұ��� Ȯ�� (20�ʸ���)
		if (totalTime / 20 > level - 1) {
			level++;

			if (level == 5) {
				printf("\n\n �����մϴ�. �ְ� ������ �޼��Ͽ����ϴ� ������ �����մϴ�.\n\n");
				exit(0);//��������� exit���� �ؾ���. break�� �ϸ� if���� ��������.
			}
			printf("\n\n*********���̵� �� �� ���� �ӵ��� �������ϴ�************[���� ���� %d]\n\n", level);

		}
		// ��� ����Ⱑ �׾����� Ȯ��
		if (checkFishAlive() == 0) {
			printf("\n\n��� ����Ⱑ �׾����ϴ� ������ �����մϴ�\n\n");
			exit(0);
		}
		prevTime = totalTime;
	}




	return 0;
}




void initData() {
	level = 1; //���ӷ��� (1~5)
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100;//������ �� ����(0~100)
	}
}

void printFishes() //������� ���� ���� ����
{
	printf("\n\n\n%3d�� %3d�� %3d�� %3d�� %3d�� %3d��\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf(" %4d ", arrayFish[i]);
	}
}

void decreaseWater(long timedelta) {///�� ���߽�Ű�� �Լ�
	for (int i = 0; i < 6; i++) {
		arrayFish[i] -= (level * 3 * (int)timedelta);
		if (arrayFish[i] < 0) {
			arrayFish[i] = 0;
		}
	}
}

int checkFishAlive() {
	for (int i = 0; i < 6; i++) {
		if (arrayFish[i] > 0) {
			return 1;
		}
	}
	return 0;
}

void swap(int a, int b) {
	printf("Address of a (Inside of func) : %d\n", &a);
	printf("Address of b (Inside of func) : %d\n", &b);
	int temp = a;
	a = b;
	b = temp;
	printf("Inside of swap func => a : %d,b = %d\n", a, b);
}

void swap_addr(int* a, int* b) { //�� �����Ͱ� �ּҰ��� �Ѱܹ���.
	printf("Address of pointer a (Inside of func) : %d\n", a);
	printf("Address of pointer b (Inside of func) : %d\n", b);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("(�ּҰ� ����) Inside of swap func => a : %d,b = %d\n", *a, *b);
}

void changeArray(int* ptr)
{
	ptr[2] = 50;
}
