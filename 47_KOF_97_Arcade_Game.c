#include <stdio.h>
#include <time.h>
#include <windows.h>
int main() 
{
    int P1_HP = 100, P2_HP = 100;
    int P1_weapon, P2_weapon, P1_action, P2_action;
    int weapon_damage[4] = {15, 20, 25, 30};
    printf("Welcome to THE KING OF FIGHTERS '97\n");
    Sleep(1000);
    printf("PRODUCED BY SNK CORP. OF AMERICA 1997\n\n");
    printf("MATCH WILL START NOW IN\n");
    Sleep(1000);
    printf("3\n");
    Sleep(1000);
    printf("2\n");
    Sleep(1000);
    printf("1\n");
    Sleep(1000);
    printf("GO!\n");
    Sleep(500);
    srand(time(0));
    while (P1_HP > 0 && P2_HP > 0) 
	{
        printf("\nPLAYER 1, CHOOSE AN ACTION:\n1. ATTACK!!\n2. DEFEND!\nChoose: ");
        scanf("%d", &P1_action);
        if (P1_action == 1) 
		{
            printf("PLAYER 1, CHOOSE A WEAPON:\n");
            printf("1. Master Blaster\n2. Grunt\n3. Hunter\n4. Polar Crusher\nChoose: ");
            scanf("%d", &P1_weapon);
            if (P1_weapon < 1 || P1_weapon > 4)
			{
                printf("Invalid choice! Skipping turn.\n");
                continue;
            }
            int damage = weapon_damage[P1_weapon - 1] + (rand() % 6);
            Sleep(1000);
            printf("PLAYER 1 ATTACKS! Causes %d damage!\n\n", damage);
            P2_HP -= damage;
        } 
		else 
		{
			Sleep(1000);
            printf("PLAYER 1 DEFENDS! Damage will be reduced next turn.\n\n");
        }
        if (P2_HP <= 0) 
		{
            printf("\nPLAYER 1 WINS! FINAL SCORE: P1 HP = %d, P2 HP = %d\n", P1_HP, P2_HP);
            break;
        }
        printf("\nPLAYER 2, CHOOSE AN ACTION:\n1. ATTACK!\n2. DEFEND!\nChoose: ");
        scanf("%d", &P2_action);

        if (P2_action == 1) 
		{
            printf("PLAYER 2, CHOOSE A WEAPON:\n");
            printf("1. Magma Cannon\n2. Slicer\n3. Overlocker\n4. Frosty Fraggins\nChoose: ");
            scanf("%d", &P2_weapon);
            if (P2_weapon < 1 || P2_weapon > 4) 
			{
				Sleep(1000);
                printf("Invalid choice! Skipping turn.\n");
                continue;
            }
            int damage = weapon_damage[P2_weapon - 1] + (rand() % 6);
            Sleep(1000);
            printf("PLAYER 2 ATTACKS! Causes %d damage!\n\n", damage);
            P1_HP -= damage;
        } else 
		{
            printf("PLAYER 2 DEFENDS! Damage will be reduced next turn.\n\n");
			Sleep(1000);        
		}
        if (P1_HP <= 0) 
		{
            printf("\nPLAYER 2 WINS! FINAL SCORE: P1 HP = %d, P2 HP = %d\n", P1_HP, P2_HP);
            break;
        }
        printf("\nCURRENT HEALTH: PLAYER 1 = %d | PLAYER 2 = %d\n", P1_HP, P2_HP);
    }
    printf("Thank You!!\n");
}
