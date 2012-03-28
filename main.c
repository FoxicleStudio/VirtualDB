#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <dirent.h>

void mainmenu(int x);
void create(int x);
void query(int x);
void mainmenufirst(int i);
void mainmenufirst2(int i);
void mainmenufirst3(int i);
void create2(int i);
void createDB();
void createTable(char mode[], char path[]);
void modt();
void deleteTable();
void deleteDB();
int listfile(char path[]);
void readDB(char mode[]);

int i,j,k,c,cursor=1,cursor2=1,cursor3=1;
char input[30],dbList[1000][100];
FILE *fpt;



int main()
{

    char wel[30]= "++++ Welcome to Database ++++";
    char main[30] = "++++ Main Menu ++++";
    system( "color f0");
    printf("\n\t");
    for(i=0; i<30; i++)
    {
        printf("%c",wel[i]);
        if(i==3||i==24)
        {
            printf("%c",178);
        }
        Sleep(50);
    }
    Sleep(50);
    system("cls");
    printf("\n\t");
    for(i=0; i<19; i++)
    {
        printf("%c",main[i]);
        Sleep(50);
    }
    Sleep(300);
    mainmenu(cursor);
    getch();
}

void mainmenufirst(int i)
{
    char key;
    //Detect key UP and DOWN until ENTER is pressed
    do
    {
        key = getch();  //Get the input
        switch(key)
        {
        case 72 :
            mainmenu(--cursor); //Select upper menu
            break;
        case 80 :
            mainmenu(++cursor); //Select lower menu
            break;
        }

    }
    while(key!=13);
    switch(cursor)
    {
    case 1 :
        create(cursor2);
        break;
    case 2 :
        query(cursor3);
        break;
    case 3 :
        system("cls");
        printf("\n\n\n\t==========================================================\n");
        printf("\t|                                                        |\n");
        printf("\t| ++++++++++ +++   +++      +      ++++   +++ +++  ++++  |\n");
        printf("\t| ++++++++++ +++   +++     +++     +++++  +++ +++ ++++   |\n");
        printf("\t|    ++++    +++++++++    ++ ++    +++ ++ +++ +++++++    |\n");
        printf("\t|    ++++    +++++++++   +++++++   +++  +++++ ++++++     |\n");
        printf("\t|    ++++    +++   +++  ++     ++  +++   ++++ +++ +++    |\n");
        printf("\t|    ++++    +++   +++ ++       ++ +++    +++ +++  ++++  |\n");
        printf("\t|                                                        |\n");
        printf("\t|            ++     ++    ++++    +++     +++            |\n");
        printf("\t|             ++   ++   +++  +++  +++     +++            |\n");
        printf("\t|              ++ ++   +++    +++ +++     +++            |\n");
        printf("\t|               +++    +++    +++ +++     +++            |\n");
        printf("\t|               +++     +++  +++   +++   +++             |\n");
        printf("\t|               +++       ++++       +++++               |\n");
        printf("\t|                                                        |\n");
        printf("\t==========================================================");
        Sleep(1000);
        exit(1);    //Exit game
    }
}

void mainmenufirst2(int i)
{
    char key;
    //Detect key UP and DOWN until ENTER is pressed
    do
    {
        key = getch();  //Get the input
        switch(key)
        {
        case 72 :
            create(--cursor2); //Select upper menu
            break;
        case 80 :
            create(++cursor2); //Select lower menu
            break;
        }

    }
    while(key!=13);

    switch(cursor2)
    {
    case 1 :
        createDB();
        break;
    case 2 :
        createTable("","");
        cursor2 = 1;
        mainmenu(cursor2);
        break;
    case 3:
        deleteDB();
        cursor2=7;

        Sleep(400);
        create(cursor2);
        cursor2=1;
        break;
    case 4:
        deleteTable();
        create(cursor2);
        cursor2=1;
        break;
    case 5 :
        cursor2 = 1;
        mainmenu(cursor2);
        break;
    }
}

void mainmenu(int x)
{
    system("cls");

    switch(x)
    {
    case 1 :
        printf("\n\t++++ Main Menu ++++");
        printf("\n\t[*] Create / Modify");
        printf("\n\t[ ] Query");
        printf("\n\t[ ] Exit");
        printf("\n\tUse the arrow keys to select the menu and ENTER to confirm.");
        //printf("%d",cursor);
        break;
    case 2 :
        printf("\n\t++++ Main Menu ++++");
        printf("\n\t[ ] Create / Modify");
        printf("\n\t[*] Query");
        printf("\n\t[ ] Exit");
        printf("\n\tUse the arrow keys to select the menu and ENTER to confirm.");
        break;
    case 3 :
        printf("\n\t++++ Main Menu ++++");
        printf("\n\t[ ] Create / Modify");
        printf("\n\t[ ] Query");
        printf("\n\t[*] Exit");
        printf("\n\tUse the arrow keys to select the menu and ENTER to confirm.");
        break;

    default :
        if(x > 3)
        {
            cursor = x = 1;
            mainmenu(cursor);
        }
        else if(x < 1)
        {
            cursor = x = 3;
            mainmenu(cursor);
        }
    }
    mainmenufirst(cursor);
}


void create(int x)
{
    system("cls");
    switch(x)
    {
    case 1 :
        printf("\n\t++++ Create Menu ++++");
        printf("\n\t[*] New Database ");
        printf("\n\t[ ] New Table");
        printf("\n\t[ ] Delete Database");
        printf("\n\t[ ] Delete Table");
        printf("\n\t[ ] Back to Main menu");
        printf("\n\tUse the arrow keys to select the menu and ENTER to confirm.");
        break;
    case 2 :
        printf("\n\t++++ Create Menu ++++");
        printf("\n\t[ ] New Database ");
        printf("\n\t[*] New Table");
        printf("\n\t[ ] Delete Database");
        printf("\n\t[ ] Delete Table");
        printf("\n\t[ ] Back to Main menu");
        printf("\n\tUse the arrow keys to select the menu and ENTER to confirm.");
        break;
    case 3 :
        printf("\n\t++++ Create Menu ++++");
        printf("\n\t[ ] New Database ");
        printf("\n\t[ ] New Table");
        printf("\n\t[*] Delete Database");
        printf("\n\t[ ] Delete Table");
        printf("\n\t[ ] Back to Main menu");
        printf("\n\tUse the arrow keys to select the menu and ENTER to confirm.");
        break;
    case 4 :
        printf("\n\t++++ Create Menu ++++");
        printf("\n\t[ ] New Database ");
        printf("\n\t[ ] New Table");
        printf("\n\t[ ] Delete Database");
        printf("\n\t[*] Delete Table");
        printf("\n\t[ ] Back to Main menu");
        printf("\n\tUse the arrow keys to select the menu and ENTER to confirm.");
        break;
    case 5 :
        printf("\n\t++++ Create Menu ++++");
        printf("\n\t[ ] New Database ");
        printf("\n\t[ ] New Table");
        printf("\n\t[ ] Delete Database");
        printf("\n\t[ ] Delete Table");
        printf("\n\t[*] Back to Main menu");
        printf("\n\tUse the arrow keys to select the menu and ENTER to confirm.");
        break;
    default :
        if(x > 5)
        {
            cursor2 = x = 1;
            create(cursor2);
        }
        else if(x < 1)
        {
            cursor2 = x = 5;
            create(cursor2);
        }

    }

    mainmenufirst2(cursor2);
}

void query(int x)
{
    system("cls");
    switch(x)
    {
    case 1 :
        printf("\n\t++++ Query Menu ++++");
        printf("\n\t[*] Select ");
        printf("\n\t[ ] Select all ");
        printf("\n\t[ ] Back to Main menu");
        printf("\n\tUse the arrow keys to select the menu and ENTER to confirm.");
        break;
    case 2 :
        printf("\n\t++++ Query Menu ++++");
        printf("\n\t[ ] Select ");
        printf("\n\t[*] Select all ");
        printf("\n\t[ ] Back to Main menu");
        printf("\n\tUse the arrow keys to select the menu and ENTER to confirm.");
        break;
    case 3 :
        printf("\n\t++++ Query Menu ++++");
        printf("\n\t[ ] Select ");
        printf("\n\t[ ] Select all ");
        printf("\n\t[*] Back to Main menu");
        printf("\n\tUse the arrow keys to select the menu and ENTER to confirm.");
        break;
    default :
        if(x > 3)
        {
            cursor3 = x = 1;
            query(cursor3);
        }
        else if(x < 1)
        {
            cursor3 = x = 3;
            query(cursor3);
        }

    }

    mainmenufirst3(cursor3);
}

void mainmenufirst3(int t)
{
    char key;
    //Detect key UP and DOWN until ENTER is pressed
    do
    {
        key = getch();  //Get the input
        switch(key)
        {
        case 72 :
            query(--cursor3); //Select upper menu
            break;
        case 80 :
            query(++cursor3); //Select lower menu
            break;
        }

    }
    while(key!=13);
    switch(cursor3)
    {
    case 1 :
        system("cls");
        readDB("SELECT");
        system("PAUSE");
        query(cursor3);
        break;
    case 2 :
        system("cls");
        readDB("ALL");
        system("PAUSE");
        query(cursor3);
        break;
    case 3 :
        cursor3 = 1;
        mainmenu(cursor3);
    }
}

void deleteDB()
{
    system("cls");
    listfile(".\\db\\");
    char dbn[200] = ".\\db\\";

    printf("\n\n\tWhich database do you want to delete : ");
    scanf("%s",input);
    strcat(dbn,input);
    remove(strcat(dbn,".txt"));
    printf("\n\tDelete Complete");

}

void createDB()
{
    system("cls");
    int i,tableN;
    char DBName[100];
    char DBName2[100];
    char path[100]=".\\db";
    char dbn[200] = ".\\db\\";
    printf("\n\tDatabase Name: ");
    gets(DBName);
    //printf("\n\tHow many tables do you want? : ");
    //scanf("%d",&tableN);
    strcat(dbn,DBName);
    if((fpt = fopen(strcat(dbn,".txt"),"w")) == NULL)
    {
        perror("\n\tError creating new file, please try again or read the manual.");
        system("PAUSE");
        exit(1);
    }
    else
    {
        tableN = 1;
        fprintf(fpt,"TNUM %d\n",tableN);
        if(tableN > 0)
        {
            fclose(fpt);
            //printf("kkkk");
            //for(i = 0; i < tableN; i++)
            //{
                createTable("CREATED",DBName);
            //}
        }
        else
        {
            fclose(fpt);
            printf("\nDatabase Created");
            system("PAUSE");
        }
    }
    i=1;
    mainmenu(i);
}

int listfile(char path[])
{
    int i=0;
    DIR *dir;
    struct dirent *ent;
    dir = opendir (path);
    if (dir != NULL)
    {

        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL)
        {
            //printf ("%s\n", ent->d_name);
            strcpy(dbList[i], ent->d_name);
            i++;
        }
        closedir (dir);
    }
    else
    {
        /* could not open directory */
        perror ("");
        return EXIT_FAILURE;
    }
    i = 2;
    int l;

    printf("\n\t++++ List File name ++++\n");
    while(strcmp(dbList[i], "\0"))
    {
        l = strlen(dbList[i]);
        for(k = l; k > l-5; k--)
        {
            dbList[i][k] = '\0';
        }
        printf("\t%s\n", dbList[i]);
        i++;
    }
}

void deleteTable()
{
    system("cls");
    struct delTable
    {
        char nameTable[30];
        char Attribute[30][200];
        int numAt;
        char row[30][200];
        int numRow;
    } info[10],temp;


    int numTable,i,j;
    char Delwant[30];
    char Tnum[100],x[30];
    char Table[30] = "TABLE";
    char DBName[30];
    char dbn[200] = ".\\db\\";

    listfile(".\\db\\");
    printf("\n\n\tDatabase name to delete : ");
    gets(DBName);
    strcat(dbn,DBName);

    if((fpt = fopen(strcat(dbn,".txt"),"r")) == NULL)
    {
        printf("Error creating new file, please try again or read the manual.");
        system("PAUSE");
        exit(1);
    }
    else
    {
        fscanf(fpt,"%s %d\n",Tnum,&numTable);

        for(i=0; i<numTable; i++)
        {
            fscanf(fpt,"%s\n",info[i].nameTable);
            fscanf(fpt,"%s %d\n",x,&info[i].numAt);
            for(j=0; j<info[i].numAt; j++)
            {
                fscanf(fpt,"%s\n",info[i].Attribute[j]);
            }
            fscanf(fpt,"%s %d\n",x,&info[i].numRow);
            for(j=0; j<info[i].numRow*info[i].numAt; j++)
            {
                fscanf(fpt,"%s",info[i].row[j]);
            }
        }
        fclose(fpt);
        printf("\n\tWhich table do you want to delete : ");
        gets(Delwant);
        strcat(Table,Delwant);
        for(i=0; i<numTable-1; i++)
        {
            if(strcmp(Table,info[i].nameTable)==0)
            {
                temp=info[i];
                info[i]=info[i+1];
                info[i+1]=temp;
            }

        }
        fpt = fopen(dbn,"w");
        fprintf(fpt,"TNUM %d\n",numTable-1);
        for(i=0; i<numTable-1; i++)
        {
            fprintf(fpt,"%s\n",info[i].nameTable);
            fprintf(fpt,"ATTRIBUTE %d\n",info[i].numAt);
            for(j=0; j<info[i].numAt; j++)
            {
                fprintf(fpt,"%s\n",info[i].Attribute[j]);
            }
            fprintf(fpt,"ROW %d\n",info[i].numRow);
            for(j=0; j<info[i].numAt*info[i].numRow; j++)
            {
                fprintf(fpt,"%s ",info[i].row[j]);
                if((j+1)%info[i].numAt==0)
                {
                    fprintf(fpt,"\n");
                }
            }
        }
        fclose(fpt);


    }
    printf("\n\tComplete");
    Sleep(200);
}


void readDB(char mode[])
{

    int i, j, k, n, AttNum, RowNum, TableNum, qNum;
    char DBName[100], table[100][100], db[100][100][100], Attribute[50][100], x[100];
    char b[100];


    listfile(".\\db\\");
    printf("\n\tSelect a Database: ");
    gets(DBName);

    i = k = qNum = 0;
    if(!strcmp(mode,"SELECT"))
    {
        do
        {
            qNum++;
            printf("\n\tWhich table? : ");
            gets(table[i]);
            printf("\n\tJoin another table? [y/n]: ");
            i++;
        }
        while(getche() == 'y');
    }

    char dbn[200] = ".\\db\\";
    strcat(dbn,DBName);


    if((fpt = fopen(strcat(dbn,".txt"),"r")) == NULL)
    {
        //printf("\n%s",path);
        perror("\n\tError reading database, please try again or read the manual.\n\n");
        system("PAUSE");
        exit(1);
    }
    else
    {
        if(!strcmp(mode,"SELECT"))
        {
            for(k = 0; k < qNum; k++)
            {
                rewind(fpt);
                //printf("\nseeked");
                //find the desired table
                char t[100] = "TABLE";

                strcat(t,table[k]);

                while(strcmp(x,t))
                {
                    fscanf(fpt,"%s",x);
                }
                //printf("\nFound Table");

                //Get number of Attribute
                fscanf(fpt,"%s %d\n",x,&AttNum);
                //printf("\nGot AttNum");

                printf("\n");
                //Get Attributes's names
                for(i = 0; i < AttNum; i++)
                {
                    fscanf(fpt,"%s\n",Attribute[i]);
                }

                //Get Number of Row(s)
                fscanf(fpt,"%s %d\n",x,&RowNum);

                //Get Fields
                for(i = 0; i < RowNum; i++)
                {
                    for(j = 0; j < AttNum; j++)
                    {
                        fscanf(fpt,"%s ",db[i][j]);
                    }
                    fscanf(fpt,"\n");
                }
                int l;
                /*l = strlen(table[k]);
                for(i = 0; i < l; i++)
                {
                    table[k][i] = table[k][i+5];
                }
                table[k][l] = ('\0');*/
                printf("\t+++%s+++\n\n",table[k]);
                //Print Attributes
                for(i = 0; i < AttNum; i++)
                {
                    printf("\t");
                    //Extra from NeunG
                    printf("%-16s", Attribute[i]);
                }
                printf("\n\t----------------------------------------------------\n");

                //Prints Rows of Data
                for(i = 0; i < RowNum; i++)
                {
                    for(j = 0; j < AttNum; j++)
                    {
                        printf("\t");
                        //Extra from NeunG
                        printf("%-16s",db[i][j]);
                    }
                    printf("\n");
                }
            }
            fclose(fpt);
        }
        else if(!strcmp(mode,"ALL"))
        {
            //Get number of table(s)
            fscanf(fpt,"%s %d\n",x,&TableNum);
            qNum = TableNum;
            //printf("%d\n",TableNum);


            for(k = 0; k < qNum; k++)
            {
                fscanf(fpt,"%s\n",table[k]);
                int l;
                l = strlen(table[k]);
                for(i = 0; i < l; i++)
                {
                    table[k][i] = table[k][i+5];
                }
                table[k][l] = ('\0');
                //Get number of Attribute
                fscanf(fpt,"%s %d\n",x,&AttNum);
                //printf("\nGot AttNum=%d\n",AttNum);

                printf("\n");
                //Get Attributes's names
                for(i = 0; i < AttNum; i++)
                {
                    fscanf(fpt,"%s\n",Attribute[i]);
                }
                //printf("GotAttName\n");

                //Get Number of Row(s)
                fscanf(fpt,"%s %d\n",x,&RowNum);
                //printf("GotRowNum=%d\n",RowNum);
                //getch();

                //Get Fields

                for(i = 0; i < RowNum; i++)
                {
                    for(j = 0; j < AttNum; j++)
                    {
                        fscanf(fpt,"%s ",db[i][j]);
                        //printf("gotAField\n");
                    }
                    fscanf(fpt,"\n");
                }
                printf("\t+++%s+++\n\n",table[k]);
                //Print Attributes
                for(i = 0; i < AttNum; i++)
                {
                    printf("\t");
                    //Extra from NeunG
                    printf("%-16s", Attribute[i]);
                }
                printf("\n\t----------------------------------------------------\n");

                //Prints Rows of Data
                for(i = 0; i < RowNum; i++)
                {
                    for(j = 0; j < AttNum; j++)
                    {
                        printf("\t");
                        //Extra from NeunG
                        printf("%-16s",db[i][j]);
                    }
                    printf("\n");
                }
            }
            fclose(fpt);
        }

    }
}

void createTable(char mode[], char path[])
{
    system("cls");
    int i, j, k, n, qNum, tableNum, attribute[100], row[100], letterCount=0;
    char table[100][100], attName[100][100][100], field[100][100][100], x[50000];
    char y[100];
    char DBName[100];
    char dbn[200] = ".\\db\\";


    if(strcmp(mode,"CREATED"))
    {
        listfile(".\\db\\");
        printf("\n\tDatabase Name : ");
        //gets(DBName);
        gets(y);
    }
    else if(!strcmp(mode,"CREATED") && strcmp(path," "))
    {
        //gets(DBName);
        strcpy(y,path);
    }
    strcat(dbn,y);

    if((fpt = fopen(strcat(dbn,".txt"),"a")) == NULL)
    {
        perror("\n\tError reading database, please try again or read the manual.\n\n");
        system("PAUSE");
        exit(1);
    }
    i = j = k = qNum = 0;
    do
    {
        qNum++;
        printf("\n\tTable name : ");
        gets(table[i]);

        attribute[i] = 0;
        do
        {
            attribute[i]++;
            printf("\n\tAttribute %d : ", j+1);
            gets(attName[i][j]);
            printf("\n\tAdd more Attribute? [y/n]: ");
            j++;
        }
        while(getche() == 'y');
        row[i] = j = n = 0;
        do
        {
            row[i]++;
            for(k = 0; k < attribute[i]; k++)
            {
                printf("\n\tRow %d's %s  : ", j+1, attName[i][k]);
                gets(field[i][n]);
                n++;
            }
            printf("\n\tAdd another Row? [y/n]: ");
            j++;
        }
        while(getche() == 'y');
        printf("\n\tPress any key to continue . . . ");
        i++;
    }
    while(getche() == 'Y');
    //printf("sssss\n");
    for(i = 0; i < qNum; i++)
    {
        fprintf(fpt,"TABLE%s\n",table[i]);
        fprintf(fpt,"ATTRIBUTE %d\n",attribute[i]);
        for(j = 0; j < attribute[i]; j++)
        {
            fprintf(fpt,"%s\n",attName[i][j]);
        }
        fprintf(fpt,"ROW %d\n",row[i]);
        n = 0;
        for(j = 0; j < row[i]; j++)
        {
            for(k = 0; k < attribute[i]; k++)
            {
                fprintf(fpt,"%s ",field[i][n]);
                n++;
            }
            fprintf(fpt,"\n");
        }
    }
    fclose(fpt);
}
