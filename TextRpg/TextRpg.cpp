#include<iostream>
#include<time.h>

using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};
enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};

#define NAME_SIZE 32

struct _tagInventory
{
	int iGold;
};
struct _tagPlayer
{
	char strname[NAME_SIZE];
	char strJob[NAME_SIZE]; //문자열 비교는 시간이 오래걸림. ==> 열거체 생성
	JOB eJob;
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iExp;
	int iLevel;
	_tagInventory tInventory;

};

struct _tagMonster
{
	char strname[NAME_SIZE];
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iLevel;
	int iExp;//획득할 Exp
	int iGoldMax;
	int iGoldMin;
};

int main()
{


	srand((unsigned int)time(0));
	// 게임 시작시 플레이어 정보를 설정하게 함.
	//플레이어 이름 입력받음
	_tagPlayer tPlayer = {};
	cout << "이름 : ";
	cin.getline(tPlayer.strname,NAME_SIZE-1);
	//직업선택하기
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 : ";
		cin >> iJob;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END)//job end를 따로 만들어 쓰는 이유!
		//직업이 추가될 경우 마다 값을 변경해주지 않기 위해서
		{
			iJob = JOB_NONE;
		}
	}


	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJob = (JOB)iJob;  //숫자를 다시 문자열로 바꿔줌.
	tPlayer.tInventory.iGold = 10000;
	switch (tPlayer.eJob)
	{
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJob, "기사");
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMax = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHP = 500;
		tPlayer.iHPMax = 500;
		tPlayer.iMP = 100;
		tPlayer.iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJob, "궁수");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMax = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 15;
		tPlayer.iHP = 400;
		tPlayer.iHPMax = 400;
		tPlayer.iMP = 200;
		tPlayer.iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJob, "마법사");
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMax = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHP = 300;
		tPlayer.iHPMax = 300;
		tPlayer.iMP = 300;
		tPlayer.iMPMax = 300;
		break;
	default:
		break;
	}
	//몬스터를 생성한다.
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	//고블린 생성
	strcpy_s(tMonsterArr[0].strname, "고블린");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMax = 1500;
	tMonsterArr[0].iGoldMin = 500;

	//트롤 생성
	strcpy_s(tMonsterArr[1].strname, "트롤");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMax = 8000;
	tMonsterArr[1].iGoldMin = 6000;

	//드래곤 생성
	strcpy_s(tMonsterArr[2].strname, "드래곤");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMax = 50000;
	tMonsterArr[2].iGoldMin = 20000;
	//메인로비 만들기 인벤토리등 행동 선택화면
	while (true)
	{
		system("cls");
		cout << "========================== 로비 ==========================" << endl;
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		int iMenu;
		cin >> iMenu;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (iMenu == MM_EXIT)
		{
			break;
		}
		switch (iMenu)
		{
		case MM_MAP:
			while (true)
			{
				system("cls");
				cout << "==== 맵선택 =====" << endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;
				cout << "맵을 선택하세요 : ";
				cin >> iMenu;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iMenu == MT_BACK)
				{
					break; //맵 메뉴를 빠져나가는 break
				}
				//선택한 메뉴를 몬스터 배열의 인덱스로 활용
				//해당맵의 몬스터를 생성해준다.
				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				//전투에 들어감
				while (true)
				{
					switch (iMenu)
					{
					case MT_EASY:
						cout << "====  쉬움 =====" << endl;
						break;
					case MT_NORMAL:
						cout << "====  보통  =====" << endl;
						break;
					case MT_HARD:
						cout << "==== 어려움 =====" << endl;
						break;
					}

					//플레이어 정보를 출력
					cout << "======================= Player===================" << endl;
					cout << "이름 : " << tPlayer.strname << "\t직업 : " <<
						tPlayer.strJob << endl;
					cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " <<
						tPlayer.iExp << endl;
					cout << "공격력 : " << tPlayer.iAttackMin << " - " <<
						tPlayer.iAttackMax << "\t방어력 : " << tPlayer.iArmorMin <<
						" - " << tPlayer.iArmorMax << endl;
					cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax <<
						"\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "보유골드 : " << tPlayer.tInventory.iGold << " GOLD" << endl;

					//몬스터 정보 출력
					cout << "======================= Monster ===================" << endl;
					cout << "이름 : " << tMonster.strname << "\t레벨 : " <<
						tMonster.iLevel << endl;
					cout << "공격력 : " << tMonster.iAttackMin << " - " <<
						tMonster.iAttackMax << "\t방어력 : " << tMonster.iArmorMin <<
						" - " << tMonster.iArmorMax << endl;
					cout << "체력 : " << tMonster.iHP << " / " << tMonster.iHPMax <<
						"\t마나 : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "획득경험치 : " << tMonster.iExp << "\t획득골드 : " << tMonster.iGoldMin << " - " <<
						tMonster.iGoldMax << endl;

					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "메뉴를 선택하세요 : " << endl;
					cin >> iMenu;
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}

					else if (iMenu == BATTLE_BACK)
						break;
					switch (iMenu)
					{
					case BATTLE_ATTACK:
					{
						int iAttack = rand() % (tPlayer.iAttackMax - tPlayer.iAttackMin+1) +
							tPlayer.iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) +
							tMonster.iArmorMin;
						int iDamage = iAttack - iArmor;
						//삼항 연산자 : 조건식 ? true일때 값 : false일때 값
						iDamage = iDamage < 1 ? 1 : iDamage;//아머가 너무 높으면 음수가 되지않게 최소 데미지를 1로
						

						//몬스터 HP감소 시킴
						tMonster.iHP -= iDamage;
						cout << tPlayer.strname << " 가 " << tMonster.strname << "에게 " <<
							iDamage << " 만큼의 피해를 입혔습니다." << endl;

						//몬스토가 죽었을 경우 처리
						if (tMonster.iHP <= 0)
						{
							cout << tMonster.strname << "몬스터가 사망하였습니다." << endl;

							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) +
								tMonster.iGoldMin);
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << " 경험치를 획득하였습니다." << endl;
							cout << iGold << " GOLD를 획득하였습니다." << endl;
							system("pause");
							break;
						}
					}
						break;
					}

				}
			}
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		default:
			cout << "잘못 선택하였습니다." << endl;
			break;
		}


	}






	return 0;
}