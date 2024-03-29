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
		cout << "渡褐曖 檜葷擊 殮溘ж撮蹂.\n檜葷 : ";
		while (name == "")
		{
			cin >> name;
		}
		gdata.pdata.SetName(name);
	}

	text[0] = "鱉曖 撮啗縑 橫憮螃撮蹂.";
	text[1] = "渡褐擎 嬴腦夥檜お蒂 鱔п 絲擊 弊 熱 氈戲貊,";
	text[2] = "欽溼擊 鱔п 鬼п韓 熱 氈蝗棲棻.";
	text[3] = "賅萇 遽綠蒂 葆蟻棻賊 鱉曖 薑鼻縑 紫瞪п爾撮蹂.";

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
		case 4: // 鱉
			Tower();
			break;
		case 5: // 跨蝶攪
			Monsters();
			break;
		case 6: // 襪鍔
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
		// 啪歜 贗葬橫
		system("cls");
		system("mode con: cols=51 lines=33");

		// 陛煎 50 x 撮煎 15
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                 忙式忖忙式忖忙式忖忙式忖忙式忖                弛\n");
		printf("弛                忙托成托托成托托成托托成托托成托忖               弛\n");
		printf("弛                戍托扛托托扛托托扛托托扛托托扛托扣               弛\n");
		printf("弛                弛戍成扣戍成扣戍成扣戍成扣戍成扣弛               弛\n");
		printf("弛               忙托成成成成成成成成成成成成成成成托忖              弛\n");
		printf("弛               戍托扛托托扛托托扛扛扛托托扛托托扛托扣              弛\n");
		printf("弛               弛戍成扣戍成扣戍成成成扣戍成扣戍成扣弛              弛\n");
		printf("弛              忙托成成成成成成成成成成成成成成成成成托忖             弛\n");
		printf("弛              戍托扛托托扛托托扛扛扛扛扛托托扛托托扛托扣             弛\n");
		printf("弛              弛戍成扣戍成扣戍成成成成成扣戍成扣戍成扣弛             弛\n");
		printf("弛             忙托成成成成成成成成成成成成成成成成成成成托忖            弛\n");
		printf("弛             戍扣戍扣戍扣戍扣戍扛扛扛扛扛扣戍扣戍扣戍扣戍扣            弛\n");
		printf("弛             戍扣戍扣戍扣戍扣弛     弛戍扣戍扣戍扣戍扣            弛\n");
		printf("弛                                                弛\n");
		printf("弛 ﹥﹥﹥﹥   ﹥﹥    ﹥ ﹥ ﹥  ﹥﹥﹥﹥  ﹥﹥﹥  弛\n");
		printf("弛    ﹥    ﹥    ﹥  ﹥ ﹥ ﹥  ﹥        ﹥    ﹥弛\n");
		printf("弛    ﹥    ﹥    ﹥  ﹥ ﹥ ﹥  ﹥﹥﹥﹥  ﹥﹥﹥  弛\n");
		printf("弛    ﹥    ﹥    ﹥  ﹥ ﹥ ﹥  ﹥        ﹥    ﹥弛\n");
		printf("弛    ﹥      ﹥﹥     ﹥  ﹥   ﹥﹥﹥﹥  ﹥    ﹥弛\n");
		printf("弛                                                弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
		printf("弛                                                弛\n");
		printf("弛                                                弛\n");
		printf("弛                                                弛\n");
		printf("弛                                                弛\n");
		printf("弛                                                弛\n");
		printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
		printf("\n 褻濛徹 : 寞щ酈 / 摹鷗 : Space / 鏃模 : Esc ");

		SetText("啪歜 贗葬橫蒂 蹴ж萄董棲棻.", 12, 24);
		SetText("渡褐檜 鱉擊 薑犒и 陳瞼 : ", 6, 26);
		printf("%2d 喇  %2d 錯", gdata.GetYear(), gdata.GetMonth());

		SetText("", 0, 29);

		gdata.ChangeSecene(3);
	}
}

void InGame::Render()
{
	system("cls");

	// 檜嘐雖 �飛� 餌檜鍔 ( x = 48 , y = 21 ) 瞪羹 ( x = 70 , y = 30 )
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖忙式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                                弛弛                  弛\n");
	printf("弛                                                弛弛                  弛\n");
	printf("弛                                                弛弛                  弛\n");
	printf("弛                                                弛戌式式式式式式式式式式式式式式式式式式戎\n");
	printf("弛                                                弛忙式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                                弛弛                  弛\n");
	printf("弛                                                弛弛 Name :           弛\n");
	printf("弛                                                弛弛                  弛\n");
	printf("弛                                                弛弛 HP   :           弛\n");
	printf("弛                                                弛弛 ATK  :           弛\n");
	printf("弛                                                弛弛 TALK :           弛\n");
	printf("弛                                                弛弛                  弛\n");
	printf("弛                                                弛弛 Gold :           弛\n");
	printf("弛                                                弛弛                  弛\n");
	printf("弛                                                弛戌式式式式式式式式式式式式式式式式式式戎\n");
	printf("弛                                                弛忙式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                                弛弛                  弛\n");
	printf("弛                                                弛弛                  弛\n");
	printf("弛                                                弛弛                  弛\n");
	printf("弛                                                弛弛                  弛\n");
	printf("弛                                                弛弛                  弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎戌式式式式式式式式式式式式式式式式式式戎\n");
	printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	printf("弛                                                                    弛\n");
	printf("弛                                                                    弛\n");
	printf("弛                                                                    弛\n");
	printf("弛                                                                    弛\n");
	printf("弛                                                                    弛\n");
	printf("弛                                                                    弛\n");
	printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");

	// 檜嘐雖
	if (menuState < 4)
	{
		SetText(Img_Village(), 0, 1);
		// 陳瞼
		SetText(to_string(gdata.GetYear()), 53, 2);
		printf(" 珒  %d 篘", gdata.GetMonth());
	}
	else
	{
		// 陳瞼
		SetText("", 53, 2);
		printf("鱉 %d / 9 類", gdata.GetFloor());

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

	// Ы溯檜橫 薑爾
	SetText(gdata.pdata.GetName(), 59, 7);
	SetText(to_string(gdata.pdata.GetNowHP()), 59, 9);
	SetText(to_string(gdata.pdata.GetAttackPower()), 59, 10);
	SetText(to_string(gdata.pdata.GetTalk()), 59, 11);
	SetText(to_string(gdata.pdata.GetGold()), 59, 13);

	// 摹鷗雖
	int menucount = nowMenu[menuState];
	for (int i = 0; i < menucount; i++)
	{
		SetText(Menu[menuState][i], 53, (18 + i), (selectMenu == i));
	}

	// 臢蝶お
	SetText(text[0], 3, 25);
	SetText(text[1], 3, 26);
	SetText(text[2], 3, 27);
	SetText(text[3], 3, 28);

	// 褻濛徹
	SetText(" 褻濛徹 : 寞щ酈 / 摹鷗 : Space / 鏃模 : Esc ", 0, 31);
	printf("\n 啪歜擎 衙 殖檜 衛濛腎賊 濠翕戲煎 盪濰腌棲棻.");
}

void InGame::Release()
{

}

void InGame::Training()
{
	int bonus = rand() % 2;
	switch (selectMenu)
	{
	case 0: // 晦蟾羹溘
		if (gdata.pdata.UpdateGold(-100))
		{
			switch (bonus)
			{
			case 0: // 撩奢
				gdata.pdata.UpdateHP(100);
				text[0] = "檜廓 殖擎 晦蟾羹溘擊 欽溼ж貊 衛除擊 爾麻棻.";
				text[1] = "鼠陪и и 殖檜歷棻.";
				text[2] = "";
				text[3] = "HP陛 100 鼻蝓ц棻.";
				break;
			case 1: // 渠撩奢
				gdata.pdata.UpdateHP(150);
				text[0] = "檜廓 殖擎 晦蟾羹溘擊 欽溼ж貊 衛除擊 爾麻棻.";
				text[1] = "撩奢瞳檣 и 殖檜歷棻.";
				text[2] = "";
				text[3] = "HP陛 150 鼻蝓ц棻.";
				break;
			}
			menuState = 0;
			gdata.UpdateMonth(1);
		}
		else
		{
			text[0] = "絲檜 睡褶м棲棻.";
			text[1] = "";
			text[2] = "";
			text[3] = "";

		}
		break;

	case 1: // 輿詳欽溼
		if (gdata.pdata.UpdateGold(-150))
		{
			switch (bonus)
			{
			case 0: // 撩奢
				gdata.pdata.UpdateAttackPower(10);
				text[0] = "檜廓 殖擎 輿詳擊 欽溼ж貊 衛除擊 爾麻棻.";
				text[1] = "鼠陪и и 殖檜歷棻.";
				text[2] = "";
				text[3] = "奢問溘檜 10 鼻蝓ц棻.";
				break;
			case 1: // 渠撩奢
				gdata.pdata.UpdateHP(50);
				gdata.pdata.UpdateAttackPower(10);
				text[0] = "檜廓 殖擎 輿詳擊 欽溼ж貊 衛除擊 爾麻棻.";
				text[1] = "撩奢瞳檣 и 殖檜歷棻.";
				text[2] = "";
				text[3] = "奢問溘檜 10, HP陛 50 鼻蝓ц棻.";
				break;
			}
			menuState = 0;
			gdata.UpdateMonth(1);
		}
		else
		{
			text[0] = "絲檜 睡褶м棲棻.";
			text[1] = "";
			text[2] = "";
			text[3] = "";
		}
		break;

	case 2: // 殖葬晦
		if (gdata.pdata.UpdateGold(-150))
		{
			switch (bonus)
			{
			case 0: // 撩奢
				gdata.pdata.UpdateTalk(3);
				text[0] = "檜廓 殖擎 疇擊 檗戲貊 衛除擊 爾麻棻.";
				text[1] = "鼠陪и и 殖檜歷棻.";
				text[2] = "";
				text[3] = "樹橫棟溘檜 3 鼻蝓ц棻.";
				break;
			case 1: // 渠撩奢
				gdata.pdata.UpdateHP(50);
				gdata.pdata.UpdateTalk(5);
				text[0] = "檜廓 殖擎 疇擊 檗戲貊 衛除擊 爾麻棻.";
				text[1] = "撩奢瞳檣 и 殖檜歷棻.";
				text[2] = "";
				text[3] = "樹橫棟溘檜 5, HP陛 50 鼻蝓ц棻.";
				break;
			}
			menuState = 0;
			gdata.UpdateMonth(1);
		}
		else
		{
			text[0] = "絲檜 睡褶м棲棻.";
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
	case 0: // 堯濰
		switch (bonus)
		{
		case 0: // 撩奢
			gdata.pdata.UpdateGold(100);
			gdata.pdata.UpdateHP(10);
			text[0] = "檜廓 殖擎 堯濰橾煎 衛除擊 爾麻棻.";
			text[1] = "斜盪 斜楛 衛除擊 爾麻棻.";
			text[2] = "";
			text[3] = "100 埤萄蒂 嫡懊棻. HP陛 10 鼻蝓ц棻.";
			break;
		case 1: // 渠撩奢
			gdata.pdata.UpdateGold(100);
			gdata.pdata.UpdateHP(50);
			text[0] = "檜廓 殖擎 堯濰橾煎 衛除擊 爾麻棻.";
			text[1] = "堯濰橾縑 褻旎 模韓檜 氈擊雖紫...?";
			text[2] = "";
			text[3] = "100 埤萄蒂 嫡懊棻, HP陛 50 鼻蝓ц棻.";
			break;
		}
		menuState = 0;
		gdata.UpdateMonth(1);
		break;

	case 1: // 僭勒寡殖
		switch (bonus)
		{
		case 0: // 撩奢
		{
			gdata.pdata.UpdateGold(50);
			text[0] = "檜廓 殖擎 擠衝薄橾煎 衛除擊 爾麻棻.";
			text[1] = "褒熱陛 號懊棻...";
			text[2] = "";
			text[3] = "50 埤萄蒂 嫡懊棻.";
		}
		break;
		case 1: // 渠撩奢
		{
			gdata.pdata.UpdateGold(150);
			gdata.pdata.UpdateHP(50);
			gdata.pdata.UpdateTalk(2);
			text[0] = "檜廓 殖擎 擠衝薄橾煎 衛除擊 爾麻棻.";
			text[1] = "諫漁и и 殖檜歷棻.";
			text[2] = "";
			text[3] = "150 埤萄蒂 嫡懊棻. HP陛 50 鼻蝓ц棻. 樹橫棟溘檜 2 鼻蝓ц棻.";
		}
		break;
		}
		menuState = 0;
		gdata.UpdateMonth(1);
		gdata.SaveGame();
		break;
	case 2: // 橈擠
		break;
	}
}

void InGame::Travel()
{
	switch (selectMenu)
	{
	case 0: // 鱉 螃腦晦
		menuState = 4;
		text[0] = "鱉縑 紫雜ц棻.";
		text[1] = "";
		text[2] = "陞葡望檜 釭顫陬棻. 橫蛤煎 陞梱?";
		text[3] = "";
		break;
	case 1: // 橈擠
		break;
	case 2: // 橈擠
		break;
	}
}

Monster monster;

void InGame::Tower()
{
	switch (rand() % 2)
	{
	case 0:
		menuState = 5; // 跨蝶攪
		monster.Set((rand() % 10 * 10 + 50), (rand() % 10 + gdata.GetFloor() * 2), 30 * gdata.GetFloor());
		text[0] = "跨蝶攪陛 釭顫陬棻.";
		text[1] = "";
		text[2] = "HP : ";
		text[2] += to_string(monster.GetNowHP());
		text[3] = "Atk : ";
		text[3] += to_string(monster.GetAttackPower());
		break;
	case 1:
		menuState = 6; // 襪鍔
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
	case 0 : // 瞪癱
		if (monster.UpdateNowHP(-1 * gdata.pdata.GetAttackPower()))
		{
			if (!gdata.pdata.UpdateNowHP(-1 * monster.GetAttackPower()))
			{
				// Ы溯檜橫 輿旎
				menuState = 0;
				gdata.UpdateMonth(2);
				gdata.pdata.UpdateGold(-100);

				text[0] = "跨蝶攪縑啪 噙楝螺棻.";
				text[1] = "...";
				text[2] = "煽錳縑憮 舒 殖曖 衛除擊 爾麻棻.";
				text[3] = "煽錳綠煎 100 Gold蒂 餌辨ц棻.";
			}
			else
			{
				text[0] = "跨蝶攪諦 奢問擊 輿堅 嫡懊棻.";
				text[1] = "";
				text[2] = "HP : ";
				text[2] += to_string(monster.GetNowHP());
				text[3] = "Atk : ";
				text[3] += to_string(monster.GetAttackPower());
			}
		}
		else
		{
			//跨蝶攪 輿旎
			text[0] = "碳誰и 跨蝶攪蒂 籀纂ц棻!";
			text[1] = "爾鼻戲煎 ";
			text[1] += to_string(monster.GetResult());
			text[1] += "擊 �卍ぐ�. ";
			text[2] = "";
			text[3] = "棻擠擎 橫蛤煎 陞梱?";
			gdata.UpdateFloor(1);
			menuState = 4;
		}
		break;
	case 1: // 渠��
		if (gdata.pdata.GetTalk() >= rand() % 100) // 樹橫棟溘 % �捕�
		{
			// 撩奢 : 贗葬橫
			text[0] = "渠�降� 鱔ц棻!";
			text[1] = "鼠餌�� 跨蝶攪蒂 雖釭蟻棻.";
			text[2] = "";
			text[3] = "棻擠擎 橫蛤煎 陞梱?";
			gdata.UpdateFloor(1);
			menuState = 4;
		}
		else
		{
			// 褒ぬ : 蜃嬴撿л
			if (gdata.pdata.UpdateNowHP(monster.GetAttackPower()))
			{
				// Ы溯檜橫 輿旎
				menuState = 0;
				gdata.UpdateMonth(2);
				gdata.pdata.UpdateGold(-100);

				text[0] = "跨蝶攪縑啪 噙楝螺棻.";
				text[1] = "...";
				text[2] = "煽錳縑憮 舒 殖曖 衛除擊 爾麻棻.";
				text[3] = "煽錳綠煎 100 Gold蒂 餌辨ц棻.";
			}
		}
		break;
	case 2:
		// Ы溯檜橫 紫蜂
		menuState = 0;
		gdata.UpdateMonth(1);
		gdata.pdata.UpdateGold(-100);

		text[0] = "顫錶縑憮 紫蜂蟻棻.";
		text[1] = "...";
		text[2] = "紫蜂耀 濠褐縑 渠и 濠惚馬縑 и 殖擊 爾麻棻.";
		text[3] = "";
		break;
	}

}

void InGame::Quiz()
{
	if (selectMenu == QuizAnswer[gdata.GetFloor()])
	{
		// 薑港
		text[0] = "薑港檜棻!";
		text[1] = "棻擠擎 橫蛤煎 陞梱?";
		text[2] = "";
		text[3] = "";
		gdata.UpdateFloor(1);
		menuState = 4;
	}
	else
	{
		menuState = 0;
		gdata.UpdateMonth(1);

		text[0] = "襪鍔蒂 ぎ溥憮 鱉縑憮 夷啖陬棻.";
		text[1] = "...";
		text[2] = "...";
		text[3] = "褻旎 渦 奢睡陛 в蹂й 匙 偽棻.";
		// 螃港 << 鱉 夷啖釭堅 и 殖 雖陴
	}
}

string Img_Village()
{
	string Img;
	Img += "弛                                             \n";
	Img += "弛                     忙式忖忙式忖忙式忖               \n";
	Img += "弛                    忙托成托托成托托成托忖              \n";
	Img += "弛                   忙托成成成成成成成成成托忖             \n";
	Img += "弛                   弛戍成扣戍成成成扣戍成扣弛             \n";
	Img += "弛                  忙托成成成成成成成成成成成托忖            \n";
	Img += "弛                  弛戍成扣戍成成成成成扣戍成扣弛            \n";
	Img += "弛                 忙托成成成成成成成成成成成成成成忖           \n";
	Img += "弛                 戍扣戍扣戍戍扛扛扛扛扛扣扣戍扣戍扣           \n";
	Img += "弛                 戍扣戍扣戍弛     弛扣戍扣戍扣           \n";
	Img += "弛 ________________     /                      \n";
	Img += "弛 _____________ /弛    /                       \n";
	Img += "弛            /弛/ 弛   /                        \n";
	Img += "弛           / 弛  弛  /                         \n";
	Img += "弛          /  弛  弛 /                          \n";
	Img += "弛 ________/   弛   /                           \n";
	Img += "弛 成式成扛成式成弛    弛  /                            \n";
	Img += "弛 扛成扛式扛成扛弛    弛 /                             \n";
	Img += "弛 式扛成式成扛式弛     /                              \n";
	Img += "弛 式成扛成扛式成弛    /                               \n";
	Img += "弛 式扛式扛式式扛弛   /                                \n";
 	return Img;
}
           
string Img_Tower()
{
	string Img;
	Img += "弛′                                      ㄞ     \n";
	Img += "弛  ′                                   ㄞ      \n";
	Img += "弛    ′                                ㄞ       \n";
	Img += "弛      ′                             ㄞ        \n";
	Img += "弛        ′                          ㄞ         \n";
	Img += "弛          ′_______________________ㄞ          \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛______________________弛           \n";
	Img += "弛          ㄞ                       ′          \n";
	Img += "弛         ㄞ                          ′        \n";
	Img += "弛        ㄞ                             ′      \n";
	Img += "弛       ㄞ                                ′    \n";
	Img += "弛      ㄞ                                   ′  \n";
	Img += "弛     ㄞ                                      ′\n";
	return Img;
}

string Image_Monster()
{
	string Img;
	Img += "弛′                                      ㄞ     \n";
	Img += "弛  ′                                   ㄞ      \n";
	Img += "弛    ′                                ㄞ       \n";
	Img += "弛      ′                             ㄞ        \n";
	Img += "弛        ′                          ㄞ         \n";
	Img += "弛          ′_______________________ㄞ          \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛     忙式式式式式式式式忖       弛           \n";
	Img += "弛           弛___忙式戎        戌式式式式忖__弛           \n";
	Img += "弛          ㄞ  忙戎               戌忖  ′          \n";
	Img += "弛         ㄞ   弛  ﹥       ﹥    戌式忖  ′        \n";
	Img += "弛        ㄞ   忙戎                   戌忖   ′      \n";
	Img += "弛       ㄞ    弛                     弛     ′    \n";
	Img += "弛      ㄞ     戌式式式式式式式式式式式式式式式式式式式式式戎       ′  \n";
	Img += "弛     ㄞ                                      ′\n";
	return Img;
}
 

string Img_Quiz()
{
	string Img;
	Img += "弛′                                      ㄞ     \n";
	Img += "弛  ′                                   ㄞ      \n";
	Img += "弛    ′                                ㄞ       \n";
	Img += "弛      ′                             ㄞ        \n";
	Img += "弛        ′                          ㄞ         \n";
	Img += "弛          ′_______________________ㄞ          \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛                      弛           \n";
	Img += "弛           弛 忙式式式式式式式式式式式式式式式式式式忖 弛           \n";
	Img += "弛           弛 弛                  弛 弛           \n";
	Img += "弛           弛 弛   Q U I Z        弛 弛           \n";
	Img += "弛           弛 弛       Q U I Z    弛 弛           \n";
	Img += "弛           弛_弛                  弛_弛           \n";
	Img += "弛          ㄞ 戌式式式式式式式式成成式式式式式式式式戎  ′          \n";
	Img += "弛         ㄞ           弛弛             ′        \n";
	Img += "弛        ㄞ            弛弛               ′      \n";
	Img += "弛       ㄞ             弛弛                 ′    \n";
	Img += "弛      ㄞ              戌戎                   ′  \n";
	Img += "弛     ㄞ                                      ′\n";
	return Img;
}