#include "InGame.h"
#include "GameManager.h"
#include "Monster.h"
#include "Title.h"

string Img_Village();
string Img_Tower();
string Image_Monster();
string Img_Quiz();

void InGame::Init()
{
	system("mode con: cols=71 lines=33");

	gdata.LoadGame();
	system("cls");
	if (gdata.pdata.GetName() == "")
	{
		string name;
		cout << "당신의 이름을 입력하세요.\n이름 : ";
		while (name == "")
		{
			cin >> name;
		}
		gdata.pdata.SetName(name);
	}

	text[0] = "탑의 세계에 어서오세요.";
	text[1] = "당신은 아르바이트를 통해 돈을 벌 수 있으며,";
	text[2] = "단련을 통해 강해질 수 있습니다.";
	text[3] = "모든 준비를 마쳤다면 탑의 정상에 도전해보세요.";

	Render();
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
		switch (menuState)
		{
		case 0 :
			menuState = selectMenu + 1;
			break;
		case 1 :
			Training();
			break;
		case 2 :
			Work();
			break;
		case 3:
			Travel(); 
			break;
		case 4: // 탑
			Tower();
			break;
		case 5: // 몬스터
			Monsters();
			break;
		case 6: // 퀴즈
			Quiz();
			break;
		}
		selectMenu = 0;
	}

	// ESC
	if (getKeyCode == 27)
	{
		if (menuState < 4)
		{
			menuState = 0;
			selectMenu = 0;
		}
	}

	if (getKeyCode == 'z' || gdata.GetFloor() >= 9)
	{
		// 게임 클리어
		system("cls");
		system("mode con: cols=51 lines=33");

		// 가로 50 x 세로 15
		printf("┌────────────────────────────────────────────────┐\n");
		printf("│                 ┌─┐┌─┐┌─┐┌─┐┌─┐                │\n");
		printf("│                ┌┼┬┼┼┬┼┼┬┼┼┬┼┼┬┼┐               │\n");
		printf("│                ├┼┴┼┼┴┼┼┴┼┼┴┼┼┴┼┤               │\n");
		printf("│                │├┬┤├┬┤├┬┤├┬┤├┬┤│               │\n");
		printf("│               ┌┼┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┼┐              │\n");
		printf("│               ├┼┴┼┼┴┼┼┴┴┴┼┼┴┼┼┴┼┤              │\n");
		printf("│               │├┬┤├┬┤├┬┬┬┤├┬┤├┬┤│              │\n");
		printf("│              ┌┼┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┼┐             │\n");
		printf("│              ├┼┴┼┼┴┼┼┴┴┴┴┴┼┼┴┼┼┴┼┤             │\n");
		printf("│              │├┬┤├┬┤├┬┬┬┬┬┤├┬┤├┬┤│             │\n");
		printf("│             ┌┼┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┬┼┐            │\n");
		printf("│             ├┤├┤├┤├┤├┴┴┴┴┴┤├┤├┤├┤├┤            │\n");
		printf("│             ├┤├┤├┤├┤│     │├┤├┤├┤├┤            │\n");
		printf("│                                                │\n");
		printf("│ ■■■■   ■■    ■ ■ ■  ■■■■  ■■■  │\n");
		printf("│    ■    ■    ■  ■ ■ ■  ■        ■    ■│\n");
		printf("│    ■    ■    ■  ■ ■ ■  ■■■■  ■■■  │\n");
		printf("│    ■    ■    ■  ■ ■ ■  ■        ■    ■│\n");
		printf("│    ■      ■■     ■  ■   ■■■■  ■    ■│\n");
		printf("│                                                │\n");
		printf("└────────────────────────────────────────────────┘\n");
		printf("┌────────────────────────────────────────────────┐\n");
		printf("│                                                │\n");
		printf("│                                                │\n");
		printf("│                                                │\n");
		printf("│                                                │\n");
		printf("│                                                │\n");
		printf("└────────────────────────────────────────────────┘\n");
		printf("\n 조작법 : 방향키 / 선택 : Space / 취소 : Esc ");

		SetText("게임 클리어를 축하드립니다.", 12, 24);
		SetText("당신이 탑을 정복한 날짜 : ", 6, 26);
		printf("%2d 년  %2d 월", gdata.GetYear(), gdata.GetMonth());

		SetText("", 0, 29);

		gdata.ChangeSecene(3);
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
	printf("│                                                ││ TALK :           │\n");
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
	if (menuState < 4)
	{
		SetText(Img_Village(), 0, 1);
		// 날짜
		SetText(to_string(gdata.GetYear()), 53, 2);
		printf(" 年  %d 月", gdata.GetMonth());
	}
	else
	{
		// 날짜
		SetText("", 53, 2);
		printf("탑 %d / 9 층", gdata.GetFloor());

		switch (menuState)
		{
		case 4 :
			SetText(Img_Tower(), 0, 1);
			break;
		case 5 :
			SetText(Image_Monster(), 0, 1);
			break;
		case 6 :
			SetText(Img_Quiz(), 0, 1);
			break;
		default:
			break;
		}
	}

	// 플레이어 정보
	SetText(gdata.pdata.GetName(), 59, 7);
	SetText(to_string(gdata.pdata.GetNowHP()), 59, 9);
	SetText(to_string(gdata.pdata.GetAttackPower()), 59, 10);
	SetText(to_string(gdata.pdata.GetTalk()), 59, 11);
	SetText(to_string(gdata.pdata.GetGold()), 59, 13);

	// 선택지
	int menucount = nowMenu[menuState];
	for (int i = 0; i < menucount; i++)
	{
		SetText(Menu[menuState][i], 53, (18 + i), (selectMenu == i));
	}

	// 텍스트
	SetText(text[0], 3, 25);
	SetText(text[1], 3, 26);
	SetText(text[2], 3, 27);
	SetText(text[3], 3, 28);

	// 조작법
	SetText(" 조작법 : 방향키 / 선택 : Space / 취소 : Esc ", 0, 31);
	printf("\n 게임은 매 달이 시작되면 자동으로 저장됩니다.");
}

void InGame::Release()
{

}

void InGame::Training()
{
	int bonus = rand() % 2;
	switch (selectMenu)
	{
	case 0: // 기초체력
		if (gdata.pdata.UpdateGold(-100))
		{
			switch (bonus)
			{
			case 0: // 성공
				gdata.pdata.UpdateHP(100);
				text[0] = "이번 달은 기초체력을 단련하며 시간을 보냈다.";
				text[1] = "무난한 한 달이었다.";
				text[2] = "";
				text[3] = "HP가 100 상승했다.";
				break;
			case 1: // 대성공
				gdata.pdata.UpdateHP(150);
				text[0] = "이번 달은 기초체력을 단련하며 시간을 보냈다.";
				text[1] = "성공적인 한 달이었다.";
				text[2] = "";
				text[3] = "HP가 150 상승했다.";
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
			case 0: // 성공
				gdata.pdata.UpdateAttackPower(10);
				text[0] = "이번 달은 주먹을 단련하며 시간을 보냈다.";
				text[1] = "무난한 한 달이었다.";
				text[2] = "";
				text[3] = "공격력이 10 상승했다.";
				break;
			case 1: // 대성공
				gdata.pdata.UpdateHP(50);
				gdata.pdata.UpdateAttackPower(10);
				text[0] = "이번 달은 주먹을 단련하며 시간을 보냈다.";
				text[1] = "성공적인 한 달이었다.";
				text[2] = "";
				text[3] = "공격력이 10, HP가 50 상승했다.";
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
				gdata.pdata.UpdateTalk(3);
				text[0] = "이번 달은 책을 읽으며 시간을 보냈다.";
				text[1] = "무난한 한 달이었다.";
				text[2] = "";
				text[3] = "언어능력이 3 상승했다.";
				break;
			case 1: // 대성공
				gdata.pdata.UpdateHP(50);
				gdata.pdata.UpdateTalk(5);
				text[0] = "이번 달은 책을 읽으며 시간을 보냈다.";
				text[1] = "성공적인 한 달이었다.";
				text[2] = "";
				text[3] = "언어능력이 5, HP가 50 상승했다.";
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
}

void InGame::Work()
{
	int bonus = rand() % 2;
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
			text[0] = "이번 달은 음식점일로 시간을 보냈다.";
			text[1] = "실수가 많았다...";
			text[2] = "";
			text[3] = "50 골드를 받았다.";
		}
		break;
		case 1: // 대성공
		{
			gdata.pdata.UpdateGold(150);
			gdata.pdata.UpdateHP(50);
			gdata.pdata.UpdateTalk(2);
			text[0] = "이번 달은 음식점일로 시간을 보냈다.";
			text[1] = "완벽한 한 달이었다.";
			text[2] = "";
			text[3] = "150 골드를 받았다. HP가 50 상승했다. 언어능력이 2 상승했다.";
		}
		break;
		}
		menuState = 0;
		gdata.UpdateMonth(1);
		gdata.SaveGame();
		break;
	case 2: // 없음
		break;
	}
}

void InGame::Travel()
{
	switch (selectMenu)
	{
	case 0: // 탑 오르기
		menuState = 4;
		text[0] = "탑에 도착했다.";
		text[1] = "";
		text[2] = "갈림길이 나타났다. 어디로 갈까?";
		text[3] = "";
		break;
	case 1: // 없음
		break;
	case 2: // 없음
		break;
	}
}

Monster monster;

void InGame::Tower()
{
	switch (rand() % 2)
	{
	case 0:
		menuState = 5; // 몬스터
		monster.Set((rand() % 10 * 10 + 50), (rand() % 10 + gdata.GetFloor() * 2), 30 * gdata.GetFloor());
		text[0] = "몬스터가 나타났다.";
		text[1] = "";
		text[2] = "HP : ";
		text[2] += to_string(monster.GetNowHP());
		text[3] = "Atk : ";
		text[3] += to_string(monster.GetAttackPower());
		break;
	case 1:
		menuState = 6; // 퀴즈
		text[0] = QuizData[gdata.GetFloor()][0];
		text[1] = QuizData[gdata.GetFloor()][1];
		text[2] = QuizData[gdata.GetFloor()][2];
		text[3] = QuizData[gdata.GetFloor()][3];
		break;
	}
}

void InGame::Monsters()
{
	switch (selectMenu)
	{
	case 0 : // 전투
		if (monster.UpdateNowHP(-1 * gdata.pdata.GetAttackPower()))
		{
			if (!gdata.pdata.UpdateNowHP(-1 * monster.GetAttackPower()))
			{
				// 플레이어 주금
				menuState = 0;
				gdata.UpdateMonth(2);
				gdata.pdata.UpdateGold(-100);

				text[0] = "몬스터에게 쓰러졌다.";
				text[1] = "...";
				text[2] = "병원에서 두 달의 시간을 보냈다.";
				text[3] = "병원비로 100 Gold를 사용했다.";
			}
			else
			{
				text[0] = "몬스터와 공격을 주고 받았다.";
				text[1] = "";
				text[2] = "HP : ";
				text[2] += to_string(monster.GetNowHP());
				text[3] = "Atk : ";
				text[3] += to_string(monster.GetAttackPower());
			}
		}
		else
		{
			//몬스터 주금
			text[0] = "불쌍한 몬스터를 처치했다!";
			text[1] = "보상으로 ";
			text[1] += to_string(monster.GetResult());
			text[1] += "을 훔쳤다. ";
			text[2] = "";
			text[3] = "다음은 어디로 갈까?";
			gdata.UpdateFloor(1);
			menuState = 4;
		}
		break;
	case 1: // 대화
		if (gdata.pdata.GetTalk() >= rand() % 100) // 언어능력 % 확률
		{
			// 성공 : 클리어
			text[0] = "대화가 통했다!";
			text[1] = "무사히 몬스터를 지나쳤다.";
			text[2] = "";
			text[3] = "다음은 어디로 갈까?";
			gdata.UpdateFloor(1);
			menuState = 4;
		}
		else
		{
			// 실패 : 맞아야함
			if (gdata.pdata.UpdateNowHP(monster.GetAttackPower()))
			{
				// 플레이어 주금
				menuState = 0;
				gdata.UpdateMonth(2);
				gdata.pdata.UpdateGold(-100);

				text[0] = "몬스터에게 쓰러졌다.";
				text[1] = "...";
				text[2] = "병원에서 두 달의 시간을 보냈다.";
				text[3] = "병원비로 100 Gold를 사용했다.";
			}
		}
		break;
	case 2:
		// 플레이어 도망
		menuState = 0;
		gdata.UpdateMonth(1);
		gdata.pdata.UpdateGold(-100);

		text[0] = "타워에서 도망쳤다.";
		text[1] = "...";
		text[2] = "도망친 자신에 대한 자괴감에 한 달을 보냈다.";
		text[3] = "";
		break;
	}

}

void InGame::Quiz()
{
	if (selectMenu == QuizAnswer[gdata.GetFloor()])
	{
		// 정답
		text[0] = "정답이다!";
		text[1] = "다음은 어디로 갈까?";
		text[2] = "";
		text[3] = "";
		gdata.UpdateFloor(1);
		menuState = 4;
	}
	else
	{
		menuState = 0;
		gdata.UpdateMonth(1);

		text[0] = "퀴즈를 틀려서 탑에서 쫒겨났다.";
		text[1] = "...";
		text[2] = "...";
		text[3] = "조금 더 공부가 필요할 것 같다.";
		// 오답 << 탑 쫒겨나고 한 달 지남
	}
}

string Img_Village()
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
           
string Img_Tower()
{
	string Img;
	Img += "│＼                                      ／     \n";
	Img += "│  ＼                                   ／      \n";
	Img += "│    ＼                                ／       \n";
	Img += "│      ＼                             ／        \n";
	Img += "│        ＼                          ／         \n";
	Img += "│          ＼_______________________／          \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │______________________│           \n";
	Img += "│          ／                       ＼          \n";
	Img += "│         ／                          ＼        \n";
	Img += "│        ／                             ＼      \n";
	Img += "│       ／                                ＼    \n";
	Img += "│      ／                                   ＼  \n";
	Img += "│     ／                                      ＼\n";
	return Img;
}

string Image_Monster()
{
	string Img;
	Img += "│＼                                      ／     \n";
	Img += "│  ＼                                   ／      \n";
	Img += "│    ＼                                ／       \n";
	Img += "│      ＼                             ／        \n";
	Img += "│        ＼                          ／         \n";
	Img += "│          ＼_______________________／          \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │     ┌────────┐       │           \n";
	Img += "│           │___┌─┘        └────┐__│           \n";
	Img += "│          ／  ┌┘               └┐  ＼          \n";
	Img += "│         ／   │  ■       ■    └─┐  ＼        \n";
	Img += "│        ／   ┌┘                   └┐   ＼      \n";
	Img += "│       ／    │                     │     ＼    \n";
	Img += "│      ／     └─────────────────────┘       ＼  \n";
	Img += "│     ／                                      ＼\n";
	return Img;
}
 

string Img_Quiz()
{
	string Img;
	Img += "│＼                                      ／     \n";
	Img += "│  ＼                                   ／      \n";
	Img += "│    ＼                                ／       \n";
	Img += "│      ＼                             ／        \n";
	Img += "│        ＼                          ／         \n";
	Img += "│          ＼_______________________／          \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │                      │           \n";
	Img += "│           │ ┌──────────────────┐ │           \n";
	Img += "│           │ │                  │ │           \n";
	Img += "│           │ │   Q U I Z        │ │           \n";
	Img += "│           │ │       Q U I Z    │ │           \n";
	Img += "│           │_│                  │_│           \n";
	Img += "│          ／ └────────┬┬────────┘  ＼          \n";
	Img += "│         ／           ││             ＼        \n";
	Img += "│        ／            ││               ＼      \n";
	Img += "│       ／             ││                 ＼    \n";
	Img += "│      ／              └┘                   ＼  \n";
	Img += "│     ／                                      ＼\n";
	return Img;
}