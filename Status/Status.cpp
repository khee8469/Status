#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion = count;
	*p_MPPotion = count;
}

int main()
{
	int status[4] = { 0, }; // 0 : HP, 1 : MP, 2 : 공격력, 3 : 방어력
	int* hpPostion = 0;
	int* mpPostion = 0;
	int inputNum = 0;

	// HP와 MP 입력
	while (status[0] <= 50 || status[1] <= 50)
	{
		printf("HP와 MP를 입력해주세요 : ");
		if (scanf("%d %d", &status[0], &status[1]) != 2)
		{
			printf("잘못된 입력입니다. 숫자를 입력해주세요.\n");
			while (getchar() != '\n'); // 입력 버퍼 비우기
			continue;
		}

		if (status[0] <= 50 || status[1] <= 50)
		{
			printf("HP나 MP의 값이 너무 작습니다. 다시 입력해주세요.\n");
		}
	}

	while (status[2] <= 0 || status[3] <= 0)
	{
		printf("공격력과 방어력을 입력해주세요 : ");
		if (scanf("%d %d", &status[2], &status[3]) != 2)
		{
			printf("잘못된 입력입니다. 숫자를 입력해주세요.\n");
			while (getchar() != '\n'); // 입력 버퍼 비우기
			continue;
		}
		if (status[2] <= 0 || status[3] <= 0)
		{
			printf("공격력이나 방어력의 값이 너무 작습니다. 다시 입력해주세요.\n");
		}
	}

	printf("포션이 지급되었습니다. (HP, MP 포션 각 5개)\n");
	setPotion(5, hpPostion, mpPostion);

	printf("<스탯 관리 시스템>\n1. HP 회복\n2. MP 회복\n3. HP 강화\n4. MP 강화\n5. 공격 스킬 사용\n");

	while (inputNum != 7)
	{
		printf("번호를 선택해주세요: ");
		if (scanf("%d", &inputNum) != 1)
		{
			printf("잘못된 입력입니다. 1~5 숫자를 입력해주세요.\n");
			while (getchar() != '\n'); // 입력 버퍼 비우기
			continue;
		}

		if (1 <= inputNum && inputNum <= 7)
		{
			switch (inputNum)
			{
			case 1:
			{
				if (0 < *hpPostion) // 0이 아니면
				{
					status[0] += 20;
					*hpPostion -= 1;
					printf("HP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n");
					printf("현재 HP: %d\n남은 포션 수: %d\n", status[0], *hpPostion);
				}
				else
				{
					printf("HP 포션이 부족합니다.\n");
				}
				break;
			}
			case 2:
			{
				if (0 < *mpPostion) // 0이 아니면
				{
					status[1] += 20;
					*mpPostion -= 1;
					printf("MP가 20 회복되었습니다. 포션이 1개 차감됩니다.\n");
					printf("현재 MP: %d\n남은 포션 수: %d\n", status[1], *mpPostion);
				}
				else
				{
					printf("MP 포션이 부족합니다.\n");
				}
				break;
			}
			case 3:
			{
				printf("HP가 2배로 증가되었습니다.\n");
				printf("현재 HP: %d\n", status[0] <<= 1);

				break;
			}
			case 4:
			{
				printf("MP가 2배로 증가되었습니다.\n");
				printf("현재 MP: %d\n", status[1] <<= 1);

				break;
			}
			case 5:
			{
				if (50 <= status[1])
				{
					status[1] -= 50;
					printf("스킬을 사용하여 MP가 50 소모되었습니다.\n");
					printf("현재 MP: %d\n", status[1]);
				}
				else
				{
					printf("MP가 부족하여 스킬 사용이 불가합니다.\n");
				}
			}
			case 6:
			{
				if (1 <= status[1])
				{
					status[1] >>= 1;
					printf("스킬을 사용하여 MP가 50% 소모되었습니다.\n");
					printf("현재 MP: %d\n", status[1]);
				}
				else
				{
					printf("MP가 부족하여 스킬 사용이 불가합니다.\n");
				}
			}
			case 7:
			{
				printf("입력을 종료합니다.\n");
				break;
			}
			}
		}
	}
}