#include<stdio.h>
#include<time.h>

void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);
void initData();
void printFishes();
void decreaseWater(long timedelta);

int level;
int arrayFish[6]; //전역변수 설정 6개의 원소를 가진 array
int* cursor; //cursor라는 포인터 변수 설정. 물을 주는 사람.


int main(void) {
	//// 포인터
	//
	//// 철수 : 101호 -> 메모리 공간의 주소
	//// 영희 : 201호
	//// 민수 : 301호
	//// 각 문 앞에 '암호'가 걸려있음

	//int 철수 = 1;//pwd
	//int 영희 = 2;
	//int 민수 = 3;

	//
	//

	//printf("address of 철수 : %d, pwd: %d\n", &철수, 철수);//주소(메모리 주소)를 나타내기 위해
	//printf("address of 영희 : %d, pwd: %d\n", &영희, 영희);//변수 앞에 &쓴다 (scanf_s)할당자처럼 !!할당자가 즉 그 메모리 주소에 값을 넣는다는 얘기
	//printf("address of 민수 : %d, pwd: %d\n", &민수, 민수);


	////미션맨의 등장

	////첫번째 : 아파트의 각 집에 방문하여 문에 적힌 암호 확인
	//int* 미션맨;//포인터 변수 선언 with *
	//미션맨 = &철수; // 미션맨의 철수의 주소를 받음
	//printf("미션맨이 방문 하는 곳의 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);//*미션맨으로 해당 주소의 값 확인

	//미션맨 = &영희;
	//printf("미션맨이 방문 하는 곳의 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	//미션맨 = &민수;
	//printf("미션맨이 방문 하는 곳의 주소 : %d, 암호 : %d\n", 미션맨, *미션맨);

	////두번째 미션 : 각 암호에 3을 곱해라
	//미션맨 = &철수;
	//*미션맨 = *미션맨 * 3;
	//printf("미션맨이 암호를 바꾼 곳의 주소 : %d, 바뀐암호 : %d\n", 미션맨, *미션맨);
	//미션맨 = &영희;
	//*미션맨 = *미션맨 * 3;
	//printf("미션맨이 암호를 바꾼 곳의 주소 : %d, 바뀐암호 : %d\n", 미션맨, *미션맨);
	//미션맨 = &민수;
	//*미션맨 = *미션맨 * 3;
	//printf("미션맨이 암호를 바꾼 곳의 주소 : %d, 바뀐암호 : %d\n", 미션맨, *미션맨);


	//// 스파이의 등장
	//// 미션맨이 바꾼 암호에서 2를 빼라!! (미션맨도 모름)
	//int* 스파이 = 미션맨; // 두 포인터 변수가 하나의 같은 메모리 주소를 가르킴
	//printf("\n ...스파이가 미션을 수행하는 중... \n");
	//스파이 = &철수;
	//*스파이 = *스파이 - 2;
	//printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);
	//스파이 = &영희;
	//*스파이 = *스파이 - 2;
	//printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);
	//스파이 = &민수;
	//*스파이 = *스파이 - 2;
	//printf("스파이가 방문하는 곳 주소 : %d, 암호 : %d\n", 스파이, *스파이);

	//printf("\n\n철수 영희 민수는 집에 돌아와 바뀐 암호를 보고 놀람\n\n");

	//printf("address of 철수 : %d, pwd: %d\n", &철수, 철수);
	//printf("address of 영희 : %d, pwd: %d\n", &영희, 영희);
	//printf("address of 민수 : %d, pwd: %d\n", &민수, 민수);
	////여기서 원래랑 다름을 느낌 원래는 x = y후 y = 10해도 바뀌지 않음.
	////포인터 변수는 가르키는 변수의 값을 실시간 공유한다.
	////참고 포인터들도 각자의 메모리 주소가 있다

	//printf("\n\n미션맨이 사는 주소 : %d\n", &미션맨); //위에서는 미션맨 = &철수로 미션맨 값이 주소를 받음.
	//printf("스파이가 사는 주소 : %d\n", &스파이);


	//// 배열과 포인터
	//int arr[3] = { 5,10,15 };
	//int* ptr = arr; //여기서는 포인터에 주소값이 아닌 배열값을 그대로 가져옴.
	//for (int i = 0; i < 3; i++) {
	//	printf("배열 arr[%d] 의 값 : %d\n", i, arr[i]);
	//}
	//for (int i = 0; i < 3; i++) {
	//	printf("포인터 ptr[%d] 의 값 : %d\n", i, ptr[i]);
	//}
	//ptr[0] = 100;
	//ptr[1] = 200;
	//ptr[2] = 300;
	//for (int i = 0; i < 3; i++) {
	//	printf("배열 arr[%d] 의 값 : %d\n", i, arr[i]);
	//	printf("배열 arr[%d] 의 값 : %d\n", i, *(arr+i));//arr주소값에 값을 가져옴 위와 같다.
	//}
	//for (int i = 0; i < 3; i++) {
	//	printf("포인터 ptr[%d] 의 값 : %d\n", i, ptr[i]);
	//}
	////*(arr+i) == arr[i] 똑같은 표현
	//// arr== (arr 배열의 첫번째 값의 주소와 동일) ==&arr[0]
	//printf("arr 주소 %d\n", arr);
	//printf("arr[0]의 주소 : %d\n", &arr);
	//printf("arr 주소가 가지는 실제 값 %d\n", *arr);// == *(arr+0)
	//printf("arr[0] 주소가 가지는 실제 값 %d\n", *&arr[0]);


	////// *& 는 아무것도 없는 것과 같아 &는 주소 *는 주소의값 ==> 상쇄
	////printf("arr[0] 주소가 가지는 실제 값 %d\n", *&*&*&*&*&*&*&*&*&*&*&*&*&*&*&arr[0]);
	////printf("arr[0] 주소가 가지는 실제 값 %d\n", arr[0]);

	//int a = 10;
	//int b = 20;
	//printf("Address of a : %d\n", &a);
	//printf("Address of b : %d\n", &b);
	////a 와 b의 값을 바꾼다 swap
	//printf("Before swaping => a : %d, b = %d\n", a, b);
	//swap(a, b);
	//printf("After swaping => a : %d,b = %d\n\n\n", a, b);

	////값에 의한 복사(Call by value) -> 값만 복사한다는 의미 즉 함수에 던질때 변수가 들어가는게 아닌 값만 준다.
	////주소값을 넘기면?? 메모리 있는 공간의 주소를 넘기면?
	//printf("(주소값 전달) Before swaping => a : %d, b = %d\n", a, b);
	//swap_addr(&a, &b);
	//printf("(주소값 전달) After swaping => a : %d,b = %d\n\n\n", a, b);

	//프로젝트 물고기 만들기
	//물고기 6마리 어항에 사막에 살아서 물이 증발한다.
	// 물이 다 증발하기 전에 부지런히 어항에 물을 줘서 물고기를 살려주세요
	// 물고기는 시간이 지날수록 커지고 물도 점점 빨리 증발


	long starTime = 0; // 게임 시작시간 시간은 long 변수형
	long totalTime = 0;// 총 경과 시간
	long prevTime = 0;//마지막으로 물을 준 시간

	int num; //몇번 어항에 물을 줄 것인지, 사용자 입력
	initData();

	cursor = arrayFish;// cursor가 어레이를 참조해서 마음대로 변경

	starTime = clock(); //현재 시간을 millisecond(1000분의 1초)
	while (1) {
		printFishes();
		printf("몇 번 어항에 물을 주시겠어요? : ");
		scanf_s("%d", &num);

		//입력값 체크
		if (num < 1 || num>6) {
			printf("\n\n입력값이 잘못되었습니다.\n\n");
			continue;
		}

		//총 경과 시간
		totalTime = (clock() - starTime) / CLOCKS_PER_SEC; //초단위로 전환.
		printf("총 경과 시간 : %ld 초\n", totalTime); //시간 변수형은 ld로 호출

		//마지막으로 물을 준 시간 이후로 흐른 시간(얼마만에 물을 줬나)
		prevTime = totalTime - prevTime;
		printf("물 공급 간격 %ld 초\n", prevTime);

		//어항 물 증발시키기
		decreaseWater(prevTime);
		//사용자가 입력한 어항에 물을 준다.
		//1. 어항의 물이 0이면 물을 주지않는다
		if (cursor[num - 1] <= 0) {
			printf("%d 번 물고기는 이미 죽었습니다.. 물을 주지 않습니다.", num);
		}
		//2. 어항에 물이 0이 아니면? 100을 넘지 안도록 줘야함.
		else if (cursor[num - 1] + 1 <= 100) {
			printf("%d 번 어항에 물을 줍니다.\n\n", num);
			cursor[num - 1] += 3;
		}

		//레벨업을 할건지 확인 (20초마다)
		if (totalTime / 20 > level - 1) {
			level++;

			if (level == 5) {
				printf("\n\n 축하합니다. 최고 레벨을 달성하였습니다 게임을 종료합니다.\n\n");
				exit(0);//게임종료는 exit으로 해야함. break로 하면 if문만 빠져나감.
			}
			printf("\n\n*********난이도 업 물 증발 속도가 빨라집니다************[현재 레벨 %d]\n\n", level);

		}
		// 모든 물고기가 죽었는지 확인
		if (checkFishAlive() == 0) {
			printf("\n\n모든 물고기가 죽었습니다 게임을 종료합니다\n\n");
			exit(0);
		}
		prevTime = totalTime;
	}




	return 0;
}




void initData() {
	level = 1; //게임레벨 (1~5)
	for (int i = 0; i < 6; i++) {
		arrayFish[i] = 100;//어항의 물 높이(0~100)
	}
}

void printFishes() //물고기의 어항 상태 보고
{
	printf("\n\n\n%3d번 %3d번 %3d번 %3d번 %3d번 %3d번\n", 1, 2, 3, 4, 5, 6);
	for (int i = 0; i < 6; i++) {
		printf(" %4d ", arrayFish[i]);
	}
}

void decreaseWater(long timedelta) {///물 증발시키는 함수
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

void swap_addr(int* a, int* b) { //두 포인터가 주소값을 넘겨받음.
	printf("Address of pointer a (Inside of func) : %d\n", a);
	printf("Address of pointer b (Inside of func) : %d\n", b);
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("(주소값 전달) Inside of swap func => a : %d,b = %d\n", *a, *b);
}

void changeArray(int* ptr)
{
	ptr[2] = 50;
}
