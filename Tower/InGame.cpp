#include "InGame.h"
#include "GameManager.h"

string Img_village();
string Img_NextDay();

#define DELAYTIME 3000

void InGame::Init()
{
	string name;
	cout << "渡褐曖 檜葷擊 殮溘ж撮蹂.\n檜葷 : ";
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
			case 0: // 晦蟾羹溘
				if (gdata.pdata.UpdateGold(-100))
				{
					switch (bonus)
					{
					case 0 : // 撩奢
						gdata.pdata.UpdateHP(100);
						text[0] = "檜廓 殖擎 鼠陪и 衛除擊 爾麻棻.";
						text[1] = "";
						text[2] = "HP陛 100 鼻蝓ц棻.";
						text[3] = "";
						break;
					case 1 : // 渠撩奢
						gdata.pdata.UpdateHP(150);
						text[0] = "檜廓 殖擎 撩奢瞳檣 衛除擊 爾麻棻.";
						text[1] = "";
						text[2] = "HP陛 150 鼻蝓ц棻.";
						text[3] = "";
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
					case 0 : // 撩奢
						gdata.pdata.UpdateAttackPower(10);
						text[0] = "檜廓 殖擎 鼠陪и 衛除擊 爾麻棻.";
						text[1] = "";
						text[2] = "奢問溘檜 10 鼻蝓ц棻.";
						text[3] = "";
						break;
					case 1 : // 渠撩奢
						gdata.pdata.UpdateHP(50);
						gdata.pdata.UpdateAttackPower(10);
						text[0] = "檜廓 殖擎 撩奢瞳檣 衛除擊 爾麻棻.";
						text[1] = "";
						text[2] = "奢問溘檜 10, HP陛 50 鼻蝓ц棻.";
						text[3] = "";
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
						gdata.pdata.UpdateSpeed(1);
						text[0] = "檜廓 殖擎 鼠陪и 衛除擊 爾麻棻.";
						text[1] = "";
						text[2] = "樓紫陛 1 鼻蝓ц棻.";
						text[3] = "";
						break;
					case 1: // 渠撩奢
						gdata.pdata.UpdateHP(50);
						gdata.pdata.UpdateSpeed(1);
						text[0] = "檜廓 殖擎 撩奢瞳檣 衛除擊 爾麻棻.";
						text[1] = "";
						text[2] = "樓紫陛 1, HP陛 50 鼻蝓ц棻.";
						text[3] = "";
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
			break;
		case 2 :
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
						text[0] = "檜廓 殖擎 寡殖橾煎 衛除擊 爾麻棻.";
						text[1] = "寡歎 褒熱陛 號懊棻...";
						text[2] = "";
						text[3] = "50 埤萄蒂 嫡懊棻.";
					}
					break;
				case 1: // 渠撩奢
					{	
						gdata.pdata.UpdateGold(150);
						gdata.pdata.UpdateHP(50);
						gdata.pdata.UpdateSpeed(1);
						text[0] = "檜廓 殖擎 寡殖橾煎 衛除擊 爾麻棻.";
						text[1] = "諫漁и 寡歎擊 檜瑞橫 麻棻.";
						text[2] = "";
						text[3] = "150 埤萄蒂 嫡懊棻. HP陛 50 鼻蝓ц棻. 樓紫陛 1 鼻蝓ц棻.";
					}
					break;
				}
				menuState = 0;
				gdata.UpdateMonth(1);
				break;
			case 2: // 橈擠
				break;
			}
			break;
		case 3:
			switch (selectMenu)
			{
			case 0: // 鱉 螃腦晦

				break;
			case 1: // 橈擠
				break;
			case 2: // 橈擠
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
	printf("弛                                                弛弛 SPD  :           弛\n");
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
	SetText(Img_village(), 0, 1);

	// 陳瞼
	SetText(to_string(gdata.GetYear()), 53, 2);
	printf(" 珒  %d 篘", gdata.GetMonth());

	// Ы溯檜橫 薑爾
	SetText(gdata.pdata.GetName(), 59, 7);
	SetText(to_string(gdata.pdata.GetHP()), 59, 9);
	SetText(to_string(gdata.pdata.GetAttackPower()), 59, 10);
	SetText(to_string(gdata.pdata.GetSpeed()), 59, 11);
	SetText(to_string(gdata.pdata.GetGold()), 59, 13);

	// 摹鷗雖
	for (int i = 0; i < nowMenu[menuState]; i++)	
	{
		SetText(Menu[menuState][i], 53, 18 + i, (selectMenu == i));
	}

	// 臢蝶お
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
           
string Img_NextDay()
{
	string Img;
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	Img += "弛      \n";
	return Img;
}


 