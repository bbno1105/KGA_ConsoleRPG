#include "InGame.h"
#include "GameManager.h"

string Img_village();
string Img_NextDay();

#define DELAYTIME 3000

void InGame::Init()
{
	string name;
	cout << "당신의 이름을 입력하세요.\n이름 : ";
	cin >> name;
	gdata.pdata.SetName(name);
}

void InGame::Update()
{
	srand(time(nullptr));

	int getKeyCode = _getch();

	if (getKeyCode == 224)
	{
		int button = _getch();
		switch (button)
		{
		case 72:
			if (selectMenu == 0) return;
			selectMenu--;
			break;
		case 80:
			if (selectMenu >= nowMenu[menuState] - 1) return;
			selectMenu++;
			break;
		}
	}

	if (getKeyCode == 32)
	{
		int bonus = rand() % 2;
		switch (menuState)
		{
		case 0 :
			menuState = selectMenu + 1;
			Sleep(100);
			break;

		case 1 :
			switch (selectMenu)
			{
			case 0: // 기초체력
				if (gdata.pdata.UpdateGold(-100))
				{
					switch (bonus)
					{
					case 0 : // 성공
						gdata.pdata.UpdateHP(100);
						text[0] = "이번 달은 무난한 시간을 보냈다.";
						text[1] = "";
						text[2] = "HP가 100 상승했다.";
						text[3] = "";
						break;
					case 1 : // 대성공
						gdata.pdata.UpdateHP(150);
						text[0] = "이번 달은 성공적인 시간을 보냈다.";
						text[1] = "";
						text[2] = "HP가 150 상승했다.";
						text[3] = "";
						break;
					}
					menuState = 0;
					gdata.UpdateMonth(1);
				}
				else
				{
					text[0] = "돈이 부족합니다.";
					text[1] = "";
					text[2] = "";
					text[3] = "";

				}
				break;

			case 1: // 주먹단련
				if (gdata.pdata.UpdateGold(-150))
				{
					switch (bonus)
					{
					case 0 : // 성공
						gdata.pdata.UpdateAttackPower(10);
						text[0] = "이번 달은 무난한 시간을 보냈다.";
						text[1] = "";
						text[2] = "공격력이 10 상승했다.";
						text[3] = "";
						break;
					case 1 : // 대성공
						gdata.pdata.UpdateHP(50);
						gdata.pdata.UpdateAttackPower(10);
						text[0] = "이번 달은 성공적인 시간을 보냈다.";
						text[1] = "";
						text[2] = "공격력이 10, HP가 50 상승했다.";
						text[3] = "";
						break;
					}
					menuState = 0;
					gdata.UpdateMonth(1);
				}
				else
				{
					text[0] = "돈이 부족합니다.";
					text[1] = "";
					text[2] = "";
					text[3] = "";
				}
				break;

			case 2: // 달리기
				if (gdata.pdata.UpdateGold(-150))
				{
					switch (bonus)
					{
					case 0: // 성공
						gdata.pdata.UpdateSpeed(1);
						text[0] = "이번 달은 무난한 시간을 보냈다.";
						text[1] = "";
						text[2] = "속도가 1 상승했다.";
						text[3] = "";
						break;
					case 1: // 대성공
						gdata.pdata.UpdateHP(50);
						gdata.pdata.UpdateSpeed(1);
						text[0] = "이번 달은 성공적인 시간을 보냈다.";
						text[1] = "";
						text[2] = "속도가 1, HP가 50 상승했다.";
						text[3] = "";
						break;
					}
					menuState = 0;
					gdata.UpdateMonth(1);
				}
				else
				{
					text[0] = "돈이 부족합니다.";
					text[1] = "";
					text[2] = "";
					text[3] = "";
				}
				break;
			}
			break;
		case 2 :
			switch (selectMenu)
			{
			case 0: // 농장
				switch (bonus)
				{
				case 0: // 성공
					gdata.pdata.UpdateGold(100);
					gdata.pdata.UpdateHP(10);
					text[0] = "이번 달은 농장일로 시간을 보냈다.";
					text[1] = "그저 그런 시간을 보냈다.";
					text[2] = "";
					text[3] = "100 골드를 받았다. HP가 10 상승했다.";
					break;
				case 1: // 대성공
					gdata.pdata.UpdateGold(100);
					gdata.pdata.UpdateHP(50);
					text[0] = "이번 달은 농장일로 시간을 보냈다.";
					text[1] = "농장일에 조금 소질이 있을지도...?";
					text[2] = "";
					text[3] = "100 골드를 받았다, HP가 50 상승했다.";
					break;
				}
				menuState = 0;
				gdata.UpdateMonth(1);
				break;

			case 1: // 물건배달
				switch (bonus)
				{
				case 0: // 성공
					{
						gdata.pdata.UpdateGold(50);
						text[0] = "이번 달은 배달일로 시간을 보냈다.";
						text[1] = "배송 실수가 많았다...";
						text[2] = "";
						text[3] = "50 골드를 받았다.";
					}
					break;
				case 1: // 대성공
					{	
						gdata.pdata.UpdateGold(150);
						gdata.pdata.UpdateHP(50);
						gdata.pdata.UpdateSpeed(1);
						text[0] = "이번 달은 배달일로 시간을 보냈다.";
						text[1] = "완벽한 배송을 이루어 냈다.";
						text[2] = "";
						text[3] = "150 골드를 받았다. HP가 50 상승했다. 속도가 1 상승했다.";
					}
					break;
				}
				menuState = 0;
				gdata.UpdateMonth(1);
				break;
			case 2: // 없음
				break;
			}
			break;
		case 3:
			switch (selectMenu)
			{
			case 0: // 탑 오르기

				break;
			case 1: // 없음
				break;
			case 2: // 없음
				break;
			}
			break;
		}
		selectMenu = 0;
	}

	if (getKeyCode == 27)
	{
		menuState = 0;
		selectMenu = 0;
	}
}

void InGame::Render()
{
	system("cls");

	// 이미지 화면 사이즈 ( x = 48 , y = 21 ) 전체 ( x = 70 , y = 30 )
	printf("┌────────────────────────────────────────────────┐┌──────────────────┐\n");
	printf("│                                                ││                  │\n");
	printf("│                                                ││                  │\n");
	printf("│                                                ││                  │\n");
	printf("│                                                │└──────────────────┘\n");
	printf("│                                                │┌──────────────────┐\n");
	printf("│                                                ││                  │\n");
	printf("│                                                ││ Name :           │\n");
	printf("│                                                ││                  │\n");
	printf("│                                                ││ HP   :           │\n");
	printf("│                                                ││ ATK  :           │\n");
	printf("│                                                ││ SPD  :           │\n");
	printf("│                                                ││                  │\n");
	printf("│                                                ││ Gold :           │\n");
	printf("│                                                ││                  │\n");
	printf("│                                                │└──────────────────┘\n");
	printf("│                                                │┌──────────────────┐\n");
	printf("│                                                ││                  │\n");
	printf("│                                                ││                  │\n");
	printf("│                                                ││                  │\n");
	printf("│                                                ││                  │\n");
	printf("│                                                ││                  │\n");
	printf("└────────────────────────────────────────────────┘└──────────────────┘\n");
	printf("┌────────────────────────────────────────────────────────────────────┐\n");
	printf("│                                                                    │\n");
	printf("│                                                                    │\n");
	printf("│                                                                    │\n");
	printf("│                                                                    │\n");
	printf("│                                                                    │\n");
	printf("│                                                                    │\n");
	printf("└────────────────────────────────────────────────────────────────────┘\n");

	// 이미지
	SetText(Img_village(), 0, 1);

	// 날짜
	SetText(to_string(gdata.GetYear()), 53, 2);
	printf(" 年  %d 月", gdata.GetMonth());

	// 플레이어 정보
	SetText(gdata.pdata.GetName(), 59, 7);
	SetText(to_string(gdata.pdata.GetHP()), 59, 9);
	SetText(to_string(gdata.pdata.GetAttackPower()), 59, 10);
	SetText(to_string(gdata.pdata.GetSpeed()), 59, 11);
	SetText(to_string(gdata.pdata.GetGold()), 59, 13);

	// 선택지
	for (int i = 0; i < nowMenu[menuState]; i++)	
	{
		SetText(Menu[menuState][i], 53, 18 + i, (selectMenu == i));
	}

	// 텍스트
	SetText(text[0], 3, 25);
	SetText(text[1], 3, 26);
	SetText(text[2], 3, 27);
	SetText(text[3], 3, 28);
}

void InGame::Release()
{

}

string Img_village()
{
	string Img;
	Img += "│                                             \n";
	Img += "│                     ┌─┐┌─┐┌─┐               \n";
	Img += "│                    ┌┼┬┼┼┬┼┼┬┼┐              \n";
	Img += "│                   ┌┼┬┬┬┬┬┬┬┬┬┼┐             \n";
	Img += "│                   │├┬┤├┬┬┬┤├┬┤│             \n";
	Img += "│                  ┌┼┬┬┬┬┬┬┬┬┬┬┬┼┐            \n";
	Img += "│                  │├┬┤├┬┬┬┬┬┤├┬┤│            \n";
	Img += "│                 ┌┼┬┬┬┬┬┬┬┬┬┬┬┬┬┬┐           \n";
	Img += "│                 ├┤├┤├├┴┴┴┴┴┤┤├┤├┤           \n";
	Img += "│                 ├┤├┤├│     │┤├┤├┤           \n";
	Img += "│ ________________     /                      \n";
	Img += "│ _____________ /│    /                       \n";
	Img += "│            /│/ │   /                        \n";
	Img += "│           / │  │  /                         \n";
	Img += "│          /  │  │ /                          \n";
	Img += "│ ________/   │   /                           \n";
	Img += "│ ┬─┬┴┬─┬│    │  /                            \n";
	Img += "│ ┴┬┴─┴┬┴│    │ /                             \n";
	Img += "│ ─┴┬─┬┴─│     /                              \n";
	Img += "│ ─┬┴┬┴─┬│    /                               \n";
	Img += "│ ─┴─┴──┴│   /                                \n";
 	return Img;
}
           
string Img_NextDay()
{
	string Img;
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	Img += "│      \n";
	return Img;
}


 