#ifndef Interface_H
#define Inrterface_H

void title(){
    char ch;
    printf("\n");
    printf("========================================================================================================================\n");
    printf("        ______                               _          ______                        ____  ____   __    _ ____    \n");
    printf("       / ____/___  ____ _      ______ ___  _( )_____   / ____/___ _____ ___  ___     / __ \\/ __/  / /   (_) __/__  \n");
    printf("      / /   / __ \\/ __ \\ | /| / / __ `/ / / /// ___/  / / __/ __ `/ __ `__ \\/ _ \\   / / / / /_   / /   / / /_/ _ \\ \n");
    printf("     / /___/ /_/ / / / / |/ |/ / /_/ / /_/ / (__  )  / /_/ / /_/ / / / / / /  __/  / /_/ / __/  / /___/ / __/  __/ \n");
    printf("     \\____/\\____/_/ /_/|__/|__/\\__,_/\\__, / /____/   \\____/\\__,_/_/ /_/ /_/\\___/   \\____/_/    /_____/_/_/  \\___/  \n");
    printf("                                    /____/                                                                         \n");
    printf("========================================================================================================================\n");
    printf("\n");
    printf("                                                 Please Wait...\n");
}

char rules(){
    char ch;    
    printf("\n                                                       GAME RULES\n");
    printf("========================================================================================================================\n");
    printf("   1. Births: Each dead cell adjacent to exactly three live neighbors will become live in the next generation.\n");
    printf("   2. Death by isolation: Each live cell with one or fewer live neighbors will die in the next generation.\n");
    printf("   3. Death by overcrowding: Each live cell with four or more live neighbors will die in the next generation. \n");
    printf("   4. Survival: Each live cell with either two or three live neighbors will remain alive for the next generation.\n");
    printf("   5. All rules apply to all cells at the same time. \n"); 
    printf("   6. Cell is defined as 3x3 area of cell around a cell.\n");
    printf("========================================================================================================================\n");
    printf("                                                Press Enter to Continue..."); scanf("%c",&ch);
    return ch;
}

char howto(){
    char ch;    
    printf("\n                                                       HOW TO PLAY\n");
    printf("========================================================================================================================\n");
    printf("   1. Player Input Initial Setup (.txt files) make sure the setup file is in the same folder of this game.\n");
    printf("   2. The Setup Consist of Row number in the first line and Column number in the second line.\n");
    printf("   3. The third and above line consist of the cells setup given by player.\n");
    printf("   4. Any comment on setup files use # and can only be placed under the last row of cells.\n");
    printf("   5. Rules are applied to see what happens in the next generation. \n"); 
    printf("   6. Tick used to continue to next generation while animate used for continuos tick until desired amount.\n");
    printf("   7. Game continue until player choose to quit and didnt want to input another setup.\n");
    printf("========================================================================================================================\n");
    printf("                                                Press Enter to Continue..."); scanf("%c",&ch);
    return ch;
}

char Begin(void){
    char ch;
    printf("\n                                                  Conway's GAME OF LIFE\n");
    printf("========================================================================================================================\n");
    printf("                                                  System By Kelompok 1\n");
    printf("                                        1. Feroz Fernando             13218003\n");
    printf("                                        2. Ratu Raihan Amany          13218012\n");
    printf("                                        3. Reihan Augeetiansyah       13218015\n");
    printf("                                        4. Danu Ihza Pamungkas        13218022\n");
    printf("                                        5. Ilham Rayhan               13218026\n");
    printf("========================================================================================================================\n");
    printf("                                                Press Enter to Continue..."); scanf("%c",&ch);
    return ch;
}

int tampilan_awal(void)
{
    int n;
    printf("\n                      MENU\n");
	printf("=======================================================\n");
	printf("             1. Tick             \n");
	printf("             2. Animate          \n");
	printf("             3. Quit             \n");
	printf("=======================================================\n");
	printf("Enter your choice : "); scanf("%d",&n);
	return n;
}

int close () {
    int n;
	printf("=======================================================\n");
	printf("             Do you want to input new setup? \n");
    printf("             1. Yes             \n");
	printf("             2. No          \n");
	printf("=======================================================\n");
	printf("Enter your choice : "); scanf("%d",&n);
	return n;
}

void thanks(){
    printf("\n");
    printf("========================================================================================================================\n");
    printf("                                 _______ _                 _     __     __                \n");
    printf("                                |__   __| |               | |    \\ \\   / /                \n");
    printf("                                   | |  | |__   __ _ _ __ | | __  \\ \\_/ /__  _   _        \n");
    printf("                                   | |  | '_ \\ / _` | '_ \\| |/ /   \\   / _ \\| | | |       \n");
    printf("                                   | |  | | | | (_| | | | |   <     | | (_) | |_| |_ _ _  \n");
    printf("                                   |_|  |_| |_|\\__,_|_| |_|_|\\_\\    |_|\\___/ \\__,_(_|_|_) \n");
    printf("\n");
    printf("========================================================================================================================\n");
}

#endif