//flag=imp

// JRun
// Copyright (C) 2018-2019 M.Anish <aneesh25861@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Affero General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Affero General Public License for more details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

/* JRun is a simple C program developed by M.Anish to avoid boring javac <Filename>.java & java <filename> commands
   It helps a bit to avoid command prompt for beginners. */
   
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to detect java and javac on windows.
void detect()
{
    printf("\nJava Version Installed:\n\n");
    if(system("java -version")!=0)
    {
        system("cls");
        printf("\nJava not Detected!\n");
        system("timeout 10");
        exit(0);
    }
    printf("\nJavac Version Installed:\n\n");
    if(system("javac -version")!=0)
    {
        system("cls");
        printf("\nJavac not Detected!\n");
        system("timeout 10");
        exit(0);
    }
}
void main()
{
    char file[100],extsn[20],cmd[150],buff[100],cmd2[150];
    int i=0,j=0,flag=0;
    FILE *f;
    system("title JRun: Run Java Programs Smoothly!");
    detect();
    system("cls");
    printf("\n Enter Filename:");
    scanf("%s",file);
	
	//loop to get extension of file entered.
    for(i=0;file[i]!='\0';i++)
    {
        buff[i]=file[i];
        if(file[i]=='.')
        {
            buff[i]='\0';
            ++i;
            flag=1;
            for(j=0;file[i]!='\0';i++,j++)
            {
                extsn[j]=file[i];
            }
            extsn[j]='\0';
            break;

        }

    }
    if(flag==0)
    {
        buff[i]='\0';
        strcat(file,".java");
        strcpy(extsn,"java");
    }

    // To check if a File is valid java source file or not based on extension.
    if(strcmpi(extsn,"java")!=0)
    {
        printf("\nSorry This is not a valid Java File!\n");
        system("pause");
        exit(0);
    }
	
	// To check if the entered file exists or not.
    f=fopen(file,"r");
    if(f==NULL)
    {
        printf("\nERROR: File Not Found!\n");
        system("pause");
        exit(0);
    }
    fclose(f);

    //code to compile java source code with javac .
    printf("\n===== Compiling Java Program =====\n\n");
    strcpy(cmd,"javac ");
    strcat(cmd,file);
    if(system(cmd)!=0)
    {
        printf("\n\n===== Program Compilation Failed =====\n\n");
        system("pause");
        exit(0);
    }

    //code to run java program.
    system("cls");
    printf("\n===== Java Program Output ===== \n\n");
    strcpy(cmd2,"java ");
    strcat(cmd2,buff);
    system(cmd2);
    printf("\n====== Program Execution Finished Successfully =====\n\n");
    system("pause");

}
