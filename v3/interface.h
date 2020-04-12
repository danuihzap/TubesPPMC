#ifndef Interface_H
#define Inrterface_H

void title(){
printf("==============================================================================================================\n");
printf("   ______                               _          ______                        ____  ____   __    _ ____    \n");
printf("  / ____/___  ____ _      ______ ___  _( )_____   / ____/___ _____ ___  ___     / __ \\/ __/  / /   (_) __/__  \n");
printf(" / /   / __ \\/ __ \\ | /| / / __ `/ / / /// ___/  / / __/ __ `/ __ `__ \\/ _ \\   / / / / /_   / /   / / /_/ _ \\ \n");
printf("/ /___/ /_/ / / / / |/ |/ / /_/ / /_/ / (__  )  / /_/ / /_/ / / / / / /  __/  / /_/ / __/  / /___/ / __/  __/ \n");
printf("\\____/\\____/_/ /_/|__/|__/\\__,_/\\__, / /____/   \\____/\\__,_/_/ /_/ /_/\\___/   \\____/_/    /_____/_/_/  \\___/  \n");
printf("                               /____/                                                                         \n");
printf("==============================================================================================================\n");
printf("\n");
printf("                                            Please Wait...\n");
}

int Begin(void){
    char ch;
    printf("\n             Conway's GAME OF LIFE\n");
	printf("=======================================================\n");
    printf("                System By Kelompok 1\n");
    printf("        1. Feroz Fernando           13218003\n");
    printf("        2. Ratu Raihan Amany        13218012\n");
    printf("        3. Reihan Augeetiansyah     13218015\n");
    printf("        4. Danu Ihza Pamungkas      13218022\n");
    printf("        5. Ilham Rayhan             13218026\n");
    printf("=======================================================\n");
    printf("Press Enter to Continue..."); scanf("%c",&ch);
    return ch;
}

int tampilan_awal(void)
{
    int n;
    printf("\n                      Menu\n");
	printf("=======================================================\n");
	printf("             1. Tick             \n");
	printf("             2. Animate          \n");
	printf("             3. Quit             \n");
	printf("=======================================================\n");
	printf("Enter your choice : "); scanf("%d",&n);
	return n;
}


void thanks(){
    printf("=================================================================\n");
    printf("   _______ _                 _     __     __                \n");
    printf("  |__   __| |               | |    \\ \\   / /                \n");
    printf("     | |  | |__   __ _ _ __ | | __  \\ \\_/ /__  _   _        \n");
    printf("     | |  | '_ \\ / _` | '_ \\| |/ /   \\   / _ \\| | | |       \n");
    printf("     | |  | | | | (_| | | | |   <     | | (_) | |_| |_ _ _  \n");
    printf("     |_|  |_| |_|\\__,_|_| |_|_|\\_\\    |_|\\___/ \\__,_(_|_|_) \n");
    printf("=================================================================\n");
}

#endif