#include "Title.h"
#include "GameManager.h"

void Title::Init()
{
	system("mode con: cols=51 lines=31");

	Render();
}

void Title::Update()
{
	int getKeyCode = _getch();

	if (getKeyCode == 224)
	{
		int button = _getch();
		switch (button)
		{
		case 72 :
			if (nowMenu == 0) return;
			nowMenu--;
			break;
		case 80:
			if (nowMenu == 2) return;
			nowMenu++;
			break;
		}
	}

	if (getKeyCode == 32)
	{
		switch (nowMenu)
		{
		case Title::NEW: // 신규 게임
			gdata.pdata.Init(); // 플레이어 데이터 초기화
			gdata.SaveGame(); // 저장파일 생성
			gdata.ChangeSecene(2);
			break;
		case Title::LOAD: // 불러오기
			if (gdata.LoadGame()) // 파일이 있는가
			{
				// 파일 로드
				gdata.ChangeSecene(2);
			}
			else
			{
				SetText("                      ", 13, 24);
				SetText("저장된 데이터가 없습니다.", 13, 25);
				SetText("                      ", 13, 26);
				SetText("", 0, 29);

				Sleep(2000);
			}

			break;
		case Title::EXIT:
			gdata.ChangeSecene(3);
			break;
		}
	}

}

void Title::Render()
{
	system("cls");

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

	SetText(newGame[nowLocale], 20, 24, (nowMenu == NEW));
	SetText(loadGame[nowLocale], 20, 25, (nowMenu == LOAD));
	SetText(exitGame[nowLocale], 20, 26, (nowMenu == EXIT));

	SetText("조작법 : 방향키 / 선택 : Space / 취소 : Esc ", 0, 29);

}

void Title::Release()
{

}