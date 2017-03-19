/*================================== MAIN ==================================*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<dos.h>
#include<string.h>
#include "ERROR.C"
#include "TRIGGER.C"

struct fileinfo
{
	char fname[10];
	char ftype[2];
	int fsize;
}file_info[10];
int fcnt=0;
FILE *fp,*fp1,*fp2;
char
	*sign,*sign1,        //For Storing Signs In Del & Updt.
	*com,*oper,*table,   //For Storing Command,Operation,Table Name
	*temp,*temp1,*temp2, //For Storing Temporary Information
	*buff,*buff2,        //For Reading & Writing From/To The Files
	*tname, 	     //For Storing The Trigger Name
	*time,
	*tbak,
	*path,
	ft[2];
int i,j,l,size,
	det,                //For Storing Location In Del & Updt.
	updt,               //For Storing Location In Updt
	rcnt;               //For Storing Number Of Records Selected

struct var
{
	char varnm[10];
}var[10];
int varcnt=0;
int num=0;

main()
{
	oper=(char *)malloc(10);
	table=(char *)malloc(50);
	temp=(char *)malloc(50);
	temp1=(char *)malloc(50);
	temp2=(char *)malloc(50);
	tname=(char *)malloc(50);
	time=(char *)malloc(10);
	sign= (char *)malloc(5);
	sign1=(char *)malloc(5);
	comp=(char *)malloc(3);
	tbak=(char *)malloc(50);
	buff2=(char*)malloc(200);
	path=(char*)malloc(200);
	clrscr();
//	start_screen();
	help_screen();
	//MENU();

}

start_screen()
{
   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
   printf("\n\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
   printf("\n\tบ\t\t\t\t\t\t\t\tบ");

    printf("\n\tบ\t\t");

    printf("        WELCOME TO MY SYSTEM \t\t\tบ");
      printf("\n\tบ\t\t\t\t\t\t\t\tบ");
   printf("\n\tบ\t\t    STRUCTURED  QUERY  LANGUAGE6\t\tบ");
   printf("\n\tบ\t\t\t\t\t\t\t\tบ");
   printf("\n\tบ\t\t\tMCS(2) PROJECT-WORK\t\t\tบ");
      printf("\n\tบ\t\t\t\t\t\t\t\tบ");
   printf("\n\tบฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑบ");
   printf("\n\tบ\t\t\t\t\t\t\t\tบ");
   printf("\n\tบ\t   	      MADE BY - RAHUL S. JAIN\t\t\tบ");
   printf("\n\tบ\t\t\t\t\t\t\t\tบ");
   printf("\n\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");

   getche();
}
help_screen()
{

   clrscr();
   printf("\nษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
	  printf("\nบ\t\t\t\t\t\t\t\t\t      บ");
	  printf("\nบ\t\t           STRUCTURED  QUERY  LANGUAGE\t\t\t      บ");
      printf("\nบ\t\t\t\t\t\t\t\t\t      บ");
  printf("\nบ\t\t               COMMAND DESCRIPTION\t\t\t      บ");
      printf("\nบ\t\t\t\t\t\t\t\t\t      บ");
       printf("\nบฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑบ");
      printf("\nบ\t\t\t\t\t\t\t\t\t      บ");
   printf("\nบCREATE COMMAND :- This command is  useful for creating table in which \t      บ\nบ\t\t   we are trying to store our valuable data.\t\t      บ");
   printf("\nบ\t\t   SYNTAX :-\t\t\t\t\t\t      บ");
	printf("\nบ\t\t\t\t\t\t\t\t\t      บ");
	  printf( "\nบ\t\t   CREATE TABLE <TableName> (FName1 FType,...,FName_n FType); บ");
		printf("\nบ\t\t\t\t\t\t\t\t\t      บ");
	  printf( "\nบ\t\t   TableName = Does not starts with number\t\t      บ");
	  printf( "\nบ\t\t   FName = Means field name.Does not starts with number\t      บ");
	   printf( "\nบ\t\t   FType = Its a datatype for field.\t\t\t      บ");
printf( "\nบ\t\t   For character = char and for nummeric data = number\t      บ");
		printf("\nบ\t\t\t\t\t\t\t\t\t      บ");
       printf("\nบฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑบ");
      printf("\nบ\t\t\t\t\t\t\t\t\t      บ");
   printf("\nบINSERT COMMAND :- This command is  useful for inserting data in table.\t      บ");
   printf("\nบ\t\t   SYNTAX :-\t\t\t\t\t\t      บ");
	printf("\nบ\t\t\t\t\t\t\t\t\t      บ");
	  printf( "\nบ\t\t   INSERT INTO <TableName> VALUES (FVALUE1,...,FVALUE_N); บ");
		printf("\nบ\t\t\t\t\t\t\t\t\t      บ");
	   printf( "\nบ\t\t   FValue = Means Value for field . ";
	   printf( "\nบ\t\t   If field type is character then write the values in single coats");
	   printf( "\nบ\t\t   If it is numberic field then write numbers only. บ");
printf( "\nบ\t\t   For character = char and for nummeric data = number\t      บ");
		printf("\nบ\t\t\t\t\t\t\t\t\t      บ");
       printf("\nบฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑบ");
      printf("\nบ\t\t\t\t\t\t\t\tบ");

   printf("\nบ\t\t\t\t\t\t\t\tบ");
   printf("\nบ\t   	      MADE BY - RAHUL S. JAIN\t\t\tบ");
   printf("\nบ\t\t\t\t\t\t\t\tบ");
   printf("\nศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");

   getche();
}
MENU()
{

	while(1)
	{
		clrscr();
   printf("\n\tษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป");
   printf("\n\tบ\t\t\t\t\t\t\t\tบ");
   printf("\n\tบ\t\t    STRUCTURED  QUERY  LANGUAGE6\t\tบ");
   printf("\n\tบ\t\t\t\t\t\t\t\tบ");
   printf("\n\tบ\t\t\tMCS(2) PROJECT-WORK\t\t\tบ");
   printf("\n\tบฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑบ");
   printf("\n\tบ\t\t\t\t\t\t\t\tบ");
   printf("\n\tบ\t   	      MADE BY - RAHUL S. JAIN\t\t\tบ");
   printf("\n\tบ\t\t\t\t\t\t\t\tบ");
   printf("\n\tศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ");


			  printf("\n\n\n \tSyntax Rules");
	  printf( "\n\tฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ");
	  printf( "\n\n\t>>>>\t CREATE TABLE <TableName> (FName1 FType,...,FName_n FType);");
	  printf( "\n\n\t>>>>\t INSERT INTO <TableName> VALUES (FVALUE1,...,FVALUE_N);");
	  printf( "\n\n\t>>>>\t UPDATE <TableName> SET FNAME1 <SIGN> FVALUE2 \n\t\t WHERE FNAME1 <SIGN> FVALUE2;");
	  printf( "\n\n\t>>>>\t DELETE FROM <TableName> WHERE FNAME1 <SIGN> FVALUE2;");
	  printf( "\n\n\t>>>>\t SELECT * FROM <TABLENAME>;");
	  printf( "\n\n\t>>>>\t ALTER TRIGGER <TriggerName> (ENABLE || DISABLE);");
  printf( "\n\n\t>>>>\t SHOW (TABLE || TRIGGER) <TNAME>;");
	  printf( "\n\n\t>>>>\t DROP (TABLE || TRIGGER) <TNAME>;");
	  printf( "\n\n\t>>>>\t EXIT (Close)");
	  printf( "\n\n\t>>>>\t SIGN --> = , > , < , <= , >= , LIKE \n");
	  printf( "\n\tฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑฑ\n\n");

		com=(char *)malloc(500);
		fcnt=0;
		rcnt=0;
		textcolor(11);
		cprintf("\n<SQL> ");
		textcolor(7);
		gets(com);                   //ACCEPT COMMAND FROM THE DOS PROMPT
		printf("\n");

		while(com[0]==' ')
			com++;
		sscanf(com,"%[^ ]s",oper);

/*================================= SELECT =================================*/

		if(stricmp(oper,"SELECT")==0)
		{
			OPER_SELECT();       //ANALYSING THE COMMAND
			DOWNLOD_STRUCT();    //DOWNLOADING STRUCT OF THE FILE
			fp=fopen(table,"r"); //OPENING THE REQUIRED TABLE
			i=0;
			if(fp==NULL)
				ERROR(6);
			GET_FILE_SIZE();
			buff=(char *)malloc(size);
			while(fgets(buff,size,fp))
			{
				if(strlen(buff)!=0)
				{
					if(i==0)
					{
						FORMAT_OUTPUT(); //FORMATTING THE FIELD NAMES
						l=18;
						i++;
					}
					printf("%s",buff);
					if(strlen(buff)!=1 && stricmp(buff," \n")!=0)
					{
						rcnt++;               //COUNTS THE NUMBER OF RECORDS READ
						if(rcnt==l)
						{
							textcolor(5);
							cprintf("\nPRESS ANY KEY TO CONTINUE ...");
							textcolor(7);
							l*=2;
							getch();
							clrscr();
							FORMAT_OUTPUT();
						}
					}
				}
			}
			textcolor(5);
			if(rcnt!=1)
				cprintf("\n\n%d ROWS SELECTED",rcnt);
			else
				cprintf("\n\n%d ROW SELECTED",rcnt);
			textcolor(7);

		} //END OF 'SELECT'

/*================================= INSERT =================================*/

		else
		if(stricmp(oper,"INSERT")==0)
		{
			OPER_INSERT();           //ANALYSING THE COMMAND
			DOWNLOD_STRUCT();        //DOWNLOADING STRUCT OF THE FILE
			com++;
			i=0;
			buff=(char *)malloc(100);

			while(com!=NULL)
			{
				if(strlen(com)==0 || com==NULL)
					break;
				sscanf(com,"%[^,) ]s",temp);

				while(temp[0]==' ')
					temp++;
				if(strlen(temp)==0)
					ERROR(38);

				strcpy(ft,file_info[i].ftype);  //GETTING THE FIELD TYPE

				if(stricmp(ft,"I")==0)      //DETECTING AN INTEGER VALUE
				{
					if(strlen(temp)>5)
						ERROR(14);
					if(!isdigit(temp[0]))
						ERROR(38);
					sscanf(com,"%[0-9]s",temp1);
					if(strlen(temp)!=strlen(temp1))
						ERROR(38);

					if(i==0)
					{
						fp=fopen(table,"r");

						/*while(fgets(buff,80,fp))  //CHECK FOR PRIMARY KEY
						{
							sscanf(buff,"%s",buff);
							if(stricmp(temp,buff)==0)
								ERROR(12);
						} */

						fclose(fp);
						strcpy(buff,temp);
						num=1;
					}

					else
					{
						strcat(buff," ");
						sscanf(temp,"%[^ );]s",temp);
						strcat(buff,temp);
						num=1;
					}
				} //END OF 'I'

				else
				if(stricmp(ft,"C")==0)  //DETECTING A CHARACTER VALUE
				{
					j=strlen(temp);

					if(temp[0]!='\'' || temp[j-1]!='\'')
						ERROR(13);
					temp++;
					com++;
					while(temp[0]==' ')
						temp++;
					if(!isalpha(temp[0]))
						ERROR(38);
					sscanf(temp,"%[^']s",temp);
					com++;

					if(strlen(temp)>file_info[i].fsize)
						ERROR(14);

				if (num==0)//first insert the numeric data
				strcpy(buff,"");
					sscanf(temp,"%[^ );]s",temp);
					strcat(buff,temp);
				} //END OF 'C'

				j=strlen(temp);
				while(j<file_info[i].fsize)  //FORMATTING INPUT
				{
					strcat(buff," ");
					j++;
				}

				i++;
				if(fcnt==i)
				{
					com+=strlen(temp);
					while(com[0]==' ')
						com++;
					if(com[0]!=')')
						ERROR(38);
					break;
				}

				com+=strlen(temp);
				while(com[0]==' ')
					com++;
				if(com[0]!=',')
					ERROR(16);

				while(com[0]==' ')
					com++;
				com++;

			} //End Of WHILE

			strcpy(buff2,buff);
			INTIALIZE_TRIGGER();

		} //End Of 'INSERT'

/*================================= DELETE =================================*/

		else
		if(stricmp(oper,"DELETE")==0)
		{
			OPER_DELETE();	 //Analysing The Command
			GET_FILE_SIZE();
			buff=(char *)malloc(size);
			strcat(table,".DAT");
			if(strstr(table,"\\")==NULL)
			{
				strcpy(path,"C:\\TC\\PROJECT\\TABLES\\");
				strcat(path,table);
				strcpy(table,path);
			}
			fp=fopen(table,"r");
			while(fgets(buff,size,fp))
				rcnt++;
			fclose(fp);

			textcolor(5);
			if(rcnt!=1)
				cprintf("\n\n%d ROWS DELETED",rcnt);
			else
				cprintf("\n\n%d ROW DELETED",rcnt);
			fclose(fp);
			fp=fopen(table,"w");
			textcolor(7);

		} //END OF 'DELETE'

/*================================= UPDATE =================================*/

		else
		if(stricmp(oper,"UPDATE")==0)
		{
			OPER_UPDATE();
			UPDATE_RECORD();
		}

/*================================= CREATE =================================*/

		else
		if(stricmp(oper,"CREATE")==0)
		{
			strcpy(buff,com);
			buff=strchr(buff,' ');
			while(buff[0]==' ')
				buff++;
			sscanf(buff,"%s",temp);

			if(stricmp(temp,"TABLE")==0)
			{
				com=strchr(com,' ');
				while(com[0]==' ')
					com++;
				com+=strlen(temp);
				while(com[0]==' ')
					com++;
				sscanf(com,"%[^( ]s",table);
				strcpy(temp,table);
				CHECK_VALID();
				strcpy(table,temp);
				com+=strlen(table);
				strcat(table,".DAT");

				if(strstr(table,"\\")==NULL)
				{
					strcpy(path,"C:\\TC\\PROJECT\\TABLES\\");
					strcat(path,table);
					strcpy(table,path);
				}

				fp=fopen(table,"r");
				if(fp!=NULL)
				{
					fcloseall();
					ERROR(40);
				}

				strcpy(buff,table);
				strcat(buff,"    ");

				while(com[0]==' ')
					com++;
				if(com[0]!='(')
					ERROR(15);
				else
				com++;
				while(com[0]==' ')
					com++;
				CREATE_TABLE();
				textcolor(5);
				cprintf("\n\nTABLE SUCESSFULLY CREATED");
				textcolor(7);
				strcpy(buff," ");
			}
			else
			if(stricmp(temp,"TRIGGER")==0)
			{
				SCAN_TRIGGER(com,oper,table,temp,temp1,buff,tname,fp,fp1,i,time,temp2);
				textcolor(5);
				cprintf("\n\nTRIGGER SUCCESSFULLY CREATED");
				textcolor(7);
			}
			else
				ERROR(34);
		}

/*================================== ALTER =================================*/
		else
		if(stricmp(oper,"ALTER")==0)
		{
			com+=strlen(oper);
			while(com[0]==' ')
				com++;
			sscanf(com,"%s",temp);
			if(stricmp(temp,"TRIGGER")!=0)
				ERROR(40);
			com+=strlen(temp);
			while(com[0]==' ')
				com++;
			sscanf(com,"%s",table);
			strcat(table,".DAT");

			if(strstr(table,"\\")==NULL)
			{
				strcpy(path,"C:\\TC\\PROJECT\\TRIGGERS\\");
				strcat(path,table);
				strcpy(table,path);
			}

			fp=fopen(table,"r");
			if(fp==NULL)
				ERROR(41);
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
			sscanf(com,"%[^; ]s",oper);

			if(stricmp(oper,"DISABLE")==0)
			{
				com+=strlen(oper);
				while(com[0]==' ')
					com++;
				if(com[0]!=';')
					ERROR(3);
				DISABLE_TRIGGER();
				//DEL_TRIGGER_LINK();
				textcolor(5);
				cprintf("\nTRIGGER SUCCESSFULLY DISABLED");
				textcolor(7);
			}
			else
			if(stricmp(oper,"ENABLE")==0)
			{
				com+=strlen(oper);
				while(com[0]==' ')
					com++;
				if(com[0]!=';')
					ERROR(3);
				ENABLE_TRIGGER();
				textcolor(5);
				cprintf("\nTRIGGER SUCCESSFULLY ENABLED");
				textcolor(7);
			}

		}

/*================================== DROP ==================================*/
		else
		if(stricmp(oper,"DROP")==0)
		{
			com+=strlen(oper);
			while(com[0]==' ')
				com++;
			sscanf(com,"%s",temp);

			if(stricmp(temp,"TABLE")==0)
			{
				com+=strlen(temp);
				while(com[0]==' ')
					com++;
				sscanf(com,"%[^; ]s",table);
				com+=strlen(table);
				while(com[0]==' ')
					com++;
				if(com[0]!=';')
					ERROR(3);
				com++;
				while(com[0]==' ')
					com++;
				if(strlen(com)!=0)
					ERROR(5);
				strcat(table,".DAT");

				if(strstr(table,"\\")==NULL)
				{
					strcpy(path,"C:\\TC\\PROJECT\\TABLES\\");
					strcat(path,table);
					strcpy(table,path);
				}

				fp=fopen(table,"r");
				if(fp==NULL)
				{
					fcloseall();
					ERROR(6);
				}
				remove(table);
				sscanf(table,"%[^.]s",temp);
				strcat(temp,".bak");
				remove(temp);
				DEL_TABLE_STRUCT();
				DEL_TABLE_LINK();
				textcolor(5);
				cprintf("\nTABLE SUCCESSFULLY DROPPED");
				textcolor(7);
			}
			else
			if(stricmp(temp,"TRIGGER")==0)
			{
				com+=strlen(temp);
				while(com[0]==' ')
					com++;
				sscanf(com,"%[^; ]s",table);
				com+=strlen(table);
				while(com[0]==' ')
					com++;
				if(com[0]!=';')
					ERROR(3);
				com++;
				while(com[0]==' ')
					com++;
				if(strlen(com)!=0)
					ERROR(5);
				strcat(table,".DAT");

				if(strstr(table,"\\")==NULL)
				{
					strcpy(path,"C:\\TC\\PROJECT\\TRIGGERS\\");
					strcat(path,table);
					strcpy(table,path);
				}

				fp=fopen(table,"r");
				if(fp==NULL)
				{
					fcloseall();
					ERROR(41);
				}
				remove(table);
				sscanf(table,"%[^.]s",temp);
				strcat(temp,".bak");
				remove(temp);
				DEL_TRIGGER_LINK();
				textcolor(5);
				cprintf("\nTRIGGER SUCCESSFULLY DROPPED");
				textcolor(7);
			}
			else
				ERROR(38);
		}

/*================================== SHOW ==================================*/
		else
		if(stricmp(oper,"SHOW")==0)
		{
			com+=strlen(oper);
			while(com[0]==' ')
				com++;
			sscanf(com,"%[a-zA-Z]s",temp);

			if(stricmp(temp,"TABLE")==0)
			{
				com+=strlen(temp);
				while(com[0]==' ')
					com++;
				sscanf(com,"%[a-zA-Z0-9]s",table);
				com+=strlen(table);
				strcat(table,".dat");
				if(strstr(table,"\\")==NULL)
				{
					strcpy(path,"C:\\TC\\PROJECT\\TABLES\\");
					strcat(path,table);
					strcpy(table,path);
				}
				while(com[0]==' ')
					com++;
				if(com[0]!=';')
					ERROR(3);
					com++;
				while(com[0]==' ')
					com++;
				if(strlen(com)!=0)
					ERROR(5);
				fp=fopen(table,"r");
				if(fp==NULL)
					ERROR(6);
				fcloseall();
				fp=fopen("C:/TC/PROJECT/SYSTEM/struct.dat","r");
				buff=(char *)malloc(100);
				while(fgets(buff,100,fp))
				{
					sscanf(buff,"%s",temp);
					if(stricmp(temp,table)==0)
					{
						textcolor(14);
						cprintf("NAME        TYPE\n");
						textcolor(7);
						while(buff!=NULL)
						{
							buff=strchr(buff,'*');
							if(buff==NULL || strlen(buff)==0)
								break;
							buff++;
							sscanf(buff,"%[^( ]s",temp);
							while(strlen(temp)<12)
							{
								strcat(temp," ");
							}
							printf("\n%s",temp);
							buff=strchr(buff,'(');buff++;
							sscanf(buff,"%[^, ]s",temp);
							if(stricmp(temp,"I")==0)
							{
								printf("INTEGER");
							}
							else
							{
								printf("CHARACTER");
								buff=strchr(buff,','); buff++;
								sscanf(buff,"%[^ )]s",temp);
								printf("(%s)",temp);
							}
						}
					}
				}

			}
			if(stricmp(temp,"TRIGGER")==0)
			{
				com+=strlen(temp);
				while(com[0]==' ')
					com++;
				sscanf(com,"%[a-zA-Z0-9]s",table);
				com+=strlen(table);
				strcat(table,".dat");
				if(strstr(table,"\\")==NULL)
				{
					strcpy(path,"C:\\TC\\PROJECT\\TRIGGERS\\");
					strcat(path,table);
					strcpy(table,path);
				}
				while(com[0]==' ')
					com++;
				if(com[0]!=';')
					ERROR(3);
				com++;
				while(com[0]==' ')
					com++;
				if(strlen(com)!=0)
					ERROR(5);
				fp=fopen(table,"r");
				if(fp==NULL)
					ERROR(41);
				fclose(fp);

				fp=fopen(table,"r");
				buff=(char *)malloc(100);
				while(fgets(buff,100,fp))
				{
					printf("%s",buff);
				}
			}

		}

/*================================== EXIT ==================================*/

		else
		if(stricmp(com,"EXIT")==0 || stricmp(com,"QUIT")==0)
		      exit(0);
		else
			ERROR(0);

		getch();
		clrscr();
		fcloseall();
	}
}

/*=============================== FUNCTIONS ================================*/


CHECK_VALID()
{
	char t[10];
	if(!isalpha(temp[0]))
		ERROR(36);
	if(strlen(temp)>8)
		ERROR(14);
	sscanf(temp,"%[0-9a-zA-Z]s",t);
	if(strlen(temp)!=strlen(t))
		ERROR(36);
}

OPER_SELECT()
{
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;

	if(com[0]=='*')                                 //DETECTING '*'
	{
		com=strchr(com,' ');
		while(com[0]==' ')
			com++;
		sscanf(com,"%[^ ]s",temp);

		if(stricmp(temp,"FROM")==0)                //DETECTING 'FROM'
		{
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
			sscanf(com,"%[A-Za-z0-9]s",table);   //EXTRACTING TABLE NAME

			if(strlen(table)==0)
				ERROR(4);
			strcat(table,".dat");
			if(strstr(table,"\\")==NULL)
			{
				strcpy(path,"C:\\TC\\PROJECT\\TABLES\\");
				strcat(path,table);
				strcpy(table,path);
			}

			com=strchr(com,';');                 //DETECTING ';'

			if(com==NULL)
				ERROR(3);
			com++;
			while(com[0]==' ')
				com++;

			if(strlen(com)!=0)
				ERROR(5);
		}
		else
			ERROR(2);
	}
	else
		ERROR(1);
}
   //END OF 'OPER_SELECT'

OPER_INSERT()
{
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%[^ ]s",temp); 					//DETECTING 'INTO'

	if(stricmp(temp,"INTO")!=0)
		ERROR(9);

	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%[^ ]s",table);                 //GETTING TABLE NAME

	if(stricmp(table,"VALUES")==0)
		ERROR(4);
	strcat(table,".dat");
	if(strstr(table,"\\")==NULL)
	{
		strcpy(path,"C:\\TC\\PROJECT\\TABLES\\");
		strcat(path,table);
		strcpy(table,path);
	}

	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%[^ (]s",temp);                 //GETTING 'VALUES'

	if(stricmp(temp,"VALUES")!=0)
		ERROR(10);

	com=strchr(com,'(');                        //DETECTING '('
	if(com==NULL)
		ERROR(11);
	strrev(com);
	while(com[0]==' ')
		com++;
	strrev(com);
	j=strlen(com);
	if(strchr(com,';')==NULL)
		ERROR(3);
	else
	if(com[j-1]!=';')
		ERROR(5);                 //DETECTING ';'
	strrev(com);
	com++;
	while(com[0]==' ')
		com++;
	strrev(com);
	j=strlen(com);
	if(com[j-1]!=')')
		ERROR(15);                //DETECTING ')'

} //END OF 'OPER_INSERT'

INSERT_RECORD()
{
	fp=fopen(table,"a");
	fprintf(fp,"%s\n",buff2);
	fcloseall();
	textcolor(5);
	cprintf("\nRECORD INSERTED");
	textcolor(7);
}

OPER_DELETE()
{
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%[^ ;]s",temp);     //DETECTING 'FROM'

	if(stricmp(temp,"FROM")==0)
	{
		com=strchr(com,' ');
		while(com[0]==' ')
			com++;

		sscanf(com,"%s",table);     //GETTING TABLE NAME
		strcat(table,".dat");
		if(strstr(table,"\\")==NULL)
		{
			strcpy(path,"C:\\TC\\PROJECT\\TABLES\\");
			strcat(path,table);
			strcpy(table,path);
		}


		if(stricmp(table,"WHERE")==0)
			ERROR(4);
		com=strchr(com,' ');
		while(com[0]==' ')
			com++;

		sscanf(com,"%s",temp);     //DETECTING 'WHERE'
		if(stricmp(temp,"WHERE")!=0)
			ERROR(17);
		com=strchr(com,' ');
		while(com[0]==' ')
			com++;

		DOWNLOD_STRUCT();     //DOWNLOADING STRUCTURE OF THE TABLE
		strcpy(temp,com);

		temp=strchr(temp,';');   //DETECTING ';'
		if(temp==NULL || strlen(temp)==0)
			ERROR(3);
		temp++;
		while(temp[0]==' ')
			temp++;
		if(strlen(temp)!=0)
			ERROR(5);

		sscanf(com,"%[^;]s",com);

		CHECK_COND();       //CHECKING THE CONDITION

		INTIALIZE_TRIGGER();

		MENU();
	}


	else				 //DETECTING ABSENCE OF CONDITION
	{
		strcpy(table,temp);
		com+=strlen(table);
		while(com[0]==' ')
			com++;
		if(com[0]!=';' && strchr(com,';')!=NULL)
			ERROR(2);
		else
		if(com[0]!=';')
			ERROR(3);
		com++;
		while(com[0]==' ')
			com++;
		if(strlen(com)!=0)
			ERROR(5);
	}


} //END OF 'OPER_DELETE'

DELETE_RECORD()
{
	i=0;
	fp=fopen(table,"r");
	fp1=fopen("C:/TC/PROJECT/SYSTEM/temp.dat","w");
	buff=(char *)malloc(100);

	while(fgets(buff,80,fp))
	{
		j=0;
		strcpy(com,buff);
		while(j!=det)
		{
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
			j++;
		}

		sscanf(com,"%s",com);

				//CHECKING SIGNS

		if(stricmp(sign,"=")==0 && atoi(com)!=atoi(temp) ||
			stricmp(sign,">")==0 && atoi(com)<=atoi(temp) ||
			stricmp(sign,"<")==0 && atoi(com)>=atoi(temp) ||
			stricmp(sign,">=")==0 && atoi(com)<atoi(temp) ||
			stricmp(sign,"<=")==0 && atoi(com)>atoi(temp) ||
			stricmp(sign,"like")==0 && stricmp(com,temp)!=0)
		{
			fprintf(fp1,"%s",buff);
		}
		else
			i++;

	} //END OF FILE

	textcolor(5);
	if(i==1)
		cprintf("\n\n%d RECORD DELETED\n",i);
	else
		cprintf("\n\n%d RECORDS DELETED\n",i);
	getch();
	fcloseall();        //CLOSING ALL OPENED FILES
	remove(table);      //REMOVING OLD FILE
	strcpy(com,"C:/TC/PROJECT/SYSTEM/TEMP.DAT");
	rename(com,table); //RENAMING NEW FILE WITH THE NAME OF THE OLD FILE
	textcolor(7);

} //END OF 'DELETE_RECORD'

OPER_UPDATE()
{
	j=0;
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%s",table);
	strcat(table,".dat");

	if(strstr(table,"\\")==NULL)
	{
		strcpy(path,"C:\\TC\\PROJECT\\TABLES\\");
		strcat(path,table);
		strcpy(table,path);
	}


	if(stricmp(table,"SET")==0)
		ERROR(4);
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%s",temp);
	if(stricmp(temp,"SET")!=0)
		ERROR(20);
	DOWNLOD_STRUCT();
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%[^; ]s",temp);
	CHECK_COND();
	if(stricmp(sign,"=")!=0 && stricmp(sign,"like")!=0)
		ERROR(19);
	while(temp[0]==' ')
		temp++;
	if(strlen(temp)==0)
		ERROR(38);

	if(stricmp(com,"WHERE")==NULL)
	{
		com+=strlen(temp);
		while(com[0]==' ')
			com++;
		if(com[0]!=';')
			ERROR(3);
		com++;
		while(com[0]==' ')
			com++;
		if(strlen(com)!=0)
			ERROR(5);

		UPDATE_RECORD();
	}

//	while(com[0]==' ')
  //		com++;
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%s",temp2);
	if(stricmp(temp2,"WHERE")!=0)
		ERROR(7);
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%s",temp2);
	for(updt=0;updt<fcnt;updt++)
	{
		if(stricmp(temp2,file_info[updt].fname)==0)
			break;
	}

	if(stricmp(temp2,file_info[updt].fname)!=0)
		ERROR(18);
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%s",sign1);
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%[^;]s",temp1);
	if(stricmp(sign1,"LIKE")==0)
	{
		if(!isalpha(temp1[1]))
			ERROR(13);
		j=strlen(temp1);
		if(temp1[0]!='\''|| temp1[j-1]!='\'')
			ERROR(38);
		sscanf(temp1+1,"%[^' ]s",temp1);
	}
	com=strchr(com,';');
	if(com==NULL)
		ERROR(3);
	com++;
	while(com[0]==' ')
		com++;
	if(strlen(com)!=0)
		ERROR(5);
	INTIALIZE_TRIGGER();
	MENU();
}

DOWNLOD_STRUCT()
{
	buff=(char *)malloc(200);
	fp1=fopen("C:/TC/PROJECT/SYSTEM/struct.dat","r");          //OPENING THE STRUCT.DAT FILE
	while(fgets(buff,200,fp1))
	{
		sscanf(buff,"%[^ ]s",temp);

		if(stricmp(table,temp)==0)       //DETECTING THE FILE NAME
		{
			while(buff!=NULL)
			{
				buff=strchr(buff,'*');
				if(strlen(buff)==0 || buff==NULL)
					break;

				buff++;

				sscanf(buff,"%[^(]s",file_info[fcnt].fname); //GETTING FIELD NAME

				buff=strchr(buff,'(');
				buff++;
				sscanf(buff,"%[^,]s",file_info[fcnt].ftype); //GETTING FIELD TYPE

				buff=strchr(buff,',');
				buff++;
				sscanf(buff,"%[^)]s",temp);
				file_info[fcnt].fsize=atoi(temp);            //GETTING FIELD SIZE

				fcnt++;    //INCREMNTING THE STRUCTURE COUNTER
			}
			break;
		}

	}
	if(fcnt==0)
		ERROR(6);
	fclose(fp2);     //CLOSING ALL THE OPENED FILES
}

FORMAT_OUTPUT()
{
	textcolor(14);
	for(j=0;j<fcnt;j++)
	{
		cprintf("%s ",file_info[j].fname); //PRINTS THE FIELD NAME

		if(strlen(file_info[j].fname)<file_info[j].fsize)
		{
			k=strlen(file_info[j].fname);

			while(k!=file_info[j].fsize)
			{
				printf(" ");             //FILLS UP THE REQUIRED GAPS
				k++;
			}
		}
	}
	printf("\n\n");
	textcolor(7);
}


CHECK_COND()
{
	sscanf(com,"%[^ ]s",temp);
	for(j=0;j<fcnt;j++)
	{
		if(stricmp(temp,file_info[j].fname)==0)
			break;
	}
	if(stricmp(temp,file_info[j].fname)!=0)
		ERROR(18);
	det=j;
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%[^ ]s",sign);
	if(stricmp(sign,"=")!=0 && stricmp(sign,">")!=0 && stricmp(sign,"<")!=0 && stricmp(sign,"<=")!=0 && stricmp(sign,">=")!=0 && stricmp(sign,"like")!=0) ERROR(19);
		com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%[^ ;]s",temp);
	if(file_info[det].ftype=='I' && atoi(temp)==0)
		ERROR(19);
	if(file_info[det].ftype=='C' && atoi(temp)!=0)
		ERROR(19);
	if(stricmp(sign,"LIKE")==0)
	{
		if(stricmp(file_info[det].ftype,"C")!=0)
			ERROR(38);
		j=strlen(temp);
		if(temp[0]!='\'' && temp[j-1]!='\'')
			ERROR(13);
		sscanf(temp+1,"%[^']s",temp);
   //		com+=4;
	}

}

UPDATE_RECORD()
{
	i=0;
	fp=fopen(table,"r");
	fp1=fopen("C:/TC/PROJECT/SYSTEM/temp.dat","w");
	buff=(char *)malloc(100);
	while(fgets(buff,80,fp))
	{
		j=0;
		while(buff!=NULL)
		{
			if(buff==NULL || strlen(buff)==0)
				break;

			if(j!=det)
			{
				sscanf(buff,"%s",temp1);
				while(strlen(temp1)<=file_info[j].fsize)
				{
					strcat(temp1," ");
				}

				if(j==0)
					strcpy(com,temp1);
				else
					strcat(com,temp1);
				buff=strchr(buff,' ');
				while(buff[0]==' ')
					buff++;
			}

			if(j==det)
			{
				sscanf(temp,"%[^;]s",temp1);
				while(strlen(temp1)<=file_info[j].fsize)
				{
					strcat(temp1," ");
				}

				strcat(com,temp1);
				buff=strchr(buff,' ');
				while(buff[0]==' ')
					buff++;
				sscanf(buff,"%[^\n]s",buff);
			}
			j++;
		}
		fprintf(fp1,"%s\n",com);
		i++;
		buff=(char *)malloc(100);
	}

	textcolor(5);
	if(i==1)
		cprintf("\n\n%d RECORD UPDATED",i);
	else
		cprintf("\n\n%d RECORDS UPDATED",i);
	getch();
	fcloseall();
	remove(table);
	strcpy(com,"C:/TC/PROJECT/SYSTEM/TEMP.DAT");
	rename(com,table);
	remove("C:/TC/PROJECT/SYSTEM/temp.dat");
	textcolor(5);
	MENU();
}

UPDATE_WHERE_RECORD()
{
	i=0;
	k=0;
	fp=fopen(table,"r");
	fp1=fopen("C:/TC/PROJECT/SYSTEM/temp.dat","w");
	buff=(char *)malloc(100);

	while(fgets(buff,80,fp))
	{
		j=0;
		strcpy(com,buff);

		while(j!=updt)
		{
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
			j++;
		}

		sscanf(com,"%s",temp2);

		if(stricmp(sign1,"=")==0 || stricmp(sign1,"like")==0)
		{
			if(stricmp(temp1,temp2)==0)
			{
				SIGN();
			}
			else
				strcpy(com,buff);
		}
		else
		if(stricmp(sign1,">")==0)
		{
			if(atoi(temp2)>atoi(temp1))
				SIGN();
		}
		else
		if(stricmp(sign1,"<")==0)
		{
			if(atoi(temp2)<atoi(temp1))
				SIGN();
		}
		else
		if(stricmp(sign1,">=")==0)
		{
			if(atoi(temp2)>=atoi(temp1))
				SIGN();
		}
		else
		if(stricmp(sign1,"<=")==0)
		{
			if(atoi(temp2)<=atoi(temp1))
				SIGN();
		}


		fprintf(fp1,"%s",com);
		buff=(char *)malloc(100);
	}

	textcolor(5);
	if(i==1)
		cprintf("\n\n%d RECORD UPDATED",i);
	else
		cprintf("\n\n%d RECORDS UPDATED",i);
	getch();
	fcloseall();
	remove(table);
	strcpy(com,"C:/TC/PROJECT/SYSTEM/TEMP.DAT");
	rename(com,table);
	remove("C:/TC/PROJECT/SYSTEM/temp.dat");
	textcolor(7);

}

SIGN()
{
	i++;
	k=0;
	while(buff!=NULL)
	{
		if(buff==NULL || strlen(buff)==0)
		{
			strcat(com,"\n");
			break;
		}

		if(k!=det)
		{
			sscanf(buff,"%s",temp2);
			while(strlen(temp2)<=file_info[k].fsize)
				strcat(temp2," ");
			if(k==0)
				strcpy(com,temp2);
			else
				strcat(com,temp2);
		}

		if(k==det)
		{
			while(strlen(temp)<=file_info[k].fsize)
				strcat(temp," ");
			if(k==0)
				strcpy(com,temp);
			else
				strcat(com,temp);
		}
		k++;
		buff=strchr(buff,' ');
		while(buff[0]==' ')
			buff++;
		sscanf(buff,"%[^\n]s",buff);
	}
	if(strstr(com,"\n")==NULL)
		  strcat(com,"\n");

}

CHK_FILE_INFO(char table[],char temp[],char tname[])
{
	for(j=0;j<fcnt;j++)
	{
		if(stricmp(temp,file_info[j].fname)==0)
			break;
	}
	if(stricmp(temp,file_info[j].fname)!=0)
	{
		if((flag1==1 && fp1==NULL) || (flag1==0 && fp1==NULL))
			remove(tname);
		ERROR(18);
	}

}

FIND_FIELD_STRUCT()
{
	for(i=0;i<fcnt;i++)
	{
		if(stricmp(temp2,file_info[i].fname)==0)
			break;
	}
}

FIND_FIELD_FILE()
{

	long len;
	com=(char *)malloc(200);
	if(stricmp(time,"AFTER")==0 && stricmp(oper,"DELETE")==0 || stricmp(time,"AFTER")==0 && stricmp(oper,"UPDATE")==0 && stricmp(buff1,"OLD")==0)
	{
		sscanf(table,"%[^.]s",tbak);
		strcat(tbak,".bak");
		fp1=fopen(tbak,"r");
	}
	else
	if(stricmp(time,"AFTER")==0 && stricmp(oper,"UPDATE")==0 && stricmp(buff1,"NEW")==0)
	{
		fp1=fopen(table,"r");
	}
	else
		fp1=fopen(table,"r");

	buff1=(char *)malloc(200);

	while(fgets(com,200,fp1))
	{
		strcpy(buff1,com);


		if(stricmp(oper,"INSERT")==0)
		{
			len=ftell(fp1);
			CAL_REC();
			fseek(fp1,(rcnt-1)*len,SEEK_SET);
			fgets(com,200,fp1);
			det=i;
			strcpy(com,buff1);
		}


		if(stricmp(oper,"UPDATE")==0)
		{
			j=0;
			while(j!=updt)
			{
				buff1=strchr(buff1,' ');
				while(buff1[0]==' ')
					buff1++;
				j++;
			}
			sscanf(buff1,"%s",buff1);

			if(stricmp(buff1,temp1)==0)
			{
				j=0;
				while(j!=i)
				{
					com=strchr(com,' ');
					while(com[0]==' ')
						com++;
					j++;
				}
				sscanf(com,"%s",com);
				if(flag3==1)
				{
					strcpy(temp2,com);
					break;
				}
				printf("%s\t",com);
				break;
			}
		}

		else
		{
			j=0;
			while(j!=det)
			{
				com=strchr(com,' ');
				while(com[0]==' ')
					com++;
				j++;
			}
		}
		sscanf(com,"%s",com);

		if(stricmp(oper,"INSERT")==0)
		{
			printf("%s\t",com);
			break;
		}


		if(stricmp(com,temp)==0 && stricmp(sign,"=")==0 ||
			atoi(com)>atoi(temp) && stricmp(sign,">")==0 ||
			atoi(com)>=atoi(temp) && stricmp(sign,">=")==0 ||
			atoi(com)<atoi(temp) && stricmp(sign,"<")==0 ||
			atoi(com)<=atoi(temp) && stricmp(sign,"<=")==0||
			stricmp(com,temp)==0 && stricmp(sign,"LIKE")==0)
		{
			j=0;
			while(j!=i)
			{
				buff1=strchr(buff1,' ');
				while(buff1[0]==' ')
					buff1++;
				j++;
			}
			sscanf(buff1,"%s",buff1);
			printf("%s\t",buff1);
		}
	}

}

CREATE_BAK()
{
	buff=(char *)malloc(100);
	fp=fopen(table,"r");
	sscanf(table,"%[^.]s",tbak);
	strcat(tbak,".bak");
	fp1=fopen(tbak,"w");
	while(fgets(buff,80,fp))
	{
		fprintf(fp1,"%s",buff);
	}
	fcloseall();
}

GET_TRIGGER_NM()
{
	buff=(char *)malloc(100);
	fp=fopen("C:/TC/PROJECT/SYSTEM/LINK.DAT","r");
	j=0;

	while(fgets(buff,80,fp))
	{
		sscanf(buff,"%s",tname);
		if(stricmp(tname,table)==0)
		{
			buff=strchr(buff,' ');while(buff[0]==' ')buff++;
			sscanf(buff,"%s",tname);

			if(stricmp(tname,oper)==0)
			{
				buff=strchr(buff,' ');
				while(buff[0]==' ')
					buff++;
				sscanf(buff,"%s",tname);

				if(stricmp(time,"BEFORE")==0 && stricmp(tname,"BEFORE")==0
					|| stricmp(time,"AFTER")==0 && stricmp(tname,"AFTER")==0)
				{
					j++;
					if((j-1)==l)
					{
						strcpy(time,tname);
						buff=strchr(buff,' ');
						while(buff[0]==' ')
							buff++;
						sscanf(buff,"%s",temp2);

					 }
				}
			}

		}

	}
	strcpy(tname,temp2);
	fcloseall();
}

ROLLBACK()
{
	temp2=(char *)malloc(200);
	fp2=fopen(table,"w");
	sscanf(table,"%[^.]s",tbak);
	strcat(tbak,".bak");
	fp1=fopen(tbak,"r");

	while(fgets(temp2,200,fp1))
	{
		fprintf(fp2,"%s",temp2);
	}
}

GET_FILE_SIZE()
{
	size=0;
	for(j=0;j<fcnt;j++)
	{
		size+=file_info[j].fsize;
		size++;
	}
}

INTIALIZE_TRIGGER()
{
	strcpy(time,"B");
	time=SEARCH_TRIGGER(buff,tname,oper,table,fp,time);//SEARCH FOR BEFORE
	if(stricmp(time,"BEFORE")==0)
	{
		l=0;
		while(l<k)
		{
			GET_TRIGGER_NM();
			EXEC_TRIGGER(buff,tname,fp,temp,temp1,temp2,oper,"BEFORE");
			l++;
		}
	}

	CREATE_BAK();

	if (stricmp(oper,"DELETE")==0)
		DELETE_RECORD();    //ACTUALLY DELETING THE RECORD SPECIFIED

	if (stricmp(oper,"INSERT")==0)
		INSERT_RECORD();    //ACTUALLY INSERTING THE RECORD SPECIFIED

	if (stricmp(oper,"UPDATE")==0)
		UPDATE_WHERE_RECORD();    //ACTUALLY UPDATING THE RECORD SPECIFIED


	strcpy(time,"A");
	time=SEARCH_TRIGGER(buff,tname,oper,table,fp,time);//SEARCH FOR AFTER

	if(stricmp(time,"AFTER")==0)
	{
		l=0;
		while(l<k)
		{
			GET_TRIGGER_NM();
			sscanf(table,"%[^.]s",tbak);
			strcat(tbak,".bak");
			EXEC_TRIGGER(buff,tname,fp,temp,temp1,temp2,oper,"AFTER");
			l++;
		}
	}
}

CAL_REC()
{
	rcnt=0;
	buff1=(char *)malloc(100);
	fp2=fopen(table,"r");
	while(fgets(buff1,80,fp2))
		rcnt++;
	fclose(fp2);
}

CREATE_TABLE()
{
	i=0;
	k=0;
	varcnt=0;
	while(com!=NULL)
	{
		k++;
		while(com[0]==' ')
			com++;

		if(com[0]==')')
		{
			if(i==1)
				ERROR(38);
			com++;
			while(com[0]==' ')
				com++;
			if(com[0]!=';')
				ERROR(3);
			com++;
			while(com[0]==' ')
				com++;
			if(strlen(com)!=0)
				ERROR(5);
			break;
		}

		sscanf(com,"%[0-9a-zA-Z,]s",temp); //Field Name

		if(com[0]==',')
		{
			com++;
			i=1;
			goto L5;
		}

		com+=strlen(temp);
		while(com[0]==' ')
			com++;
		sscanf(com,"%[^,() ]s",temp1);

		if(stricmp(temp1,"NUMBER")==0)
		{
			if(k!=1 && i==0)
				ERROR(16);
			i=0;
			CHECK_VALID();
			CHECK_VAR_COND();
			UPDATE_VAR();
			com+=strlen(temp1);

			strcat(buff,"*");
			strcat(buff,temp);
			strcat(buff,"(I,5)");
			strcat(buff,"    ");
		}

		else
		if(stricmp(temp1,"CHAR")==0)
		{
			if(k!=1 && i==0)
				ERROR(16);
			i=0;
			CHECK_VALID();
			CHECK_VAR_COND();
			UPDATE_VAR();

			strcat(buff,"*");
			strcat(buff,temp);

			sscanf(com,"%[^, ]s",temp1);

			if(strchr(temp1,'(')==NULL)
			{
				com+=4;
				strcat(buff,"(C,10)");
				strcat(buff,"    ");
			}

			else
			{
				while(com[0]==' ')
					com++;
				temp1+=4;
				com+=4;
				while(temp1[0]==' ')
					temp1++;

				if(temp1[0]!='(')
					ERROR(11);
				else
					temp1++;
				com++;

				while(temp1[0]==' ')
					temp1++;

				sscanf(temp1,"%[^) ]s",temp);
				sscanf(temp1,"%[0-9]s",temp2);

				if(strlen(temp)!=strlen(temp2) || atoi(temp)>1000)
					ERROR(35);

				temp1+=strlen(temp);
				com+=strlen(temp);

				while(temp1[0]==' ')
					temp1++;
				if(temp1[0]!=')')
					ERROR(15);

				temp1++;
				com++;

				strcat(buff,"(C,");
				strcat(buff,temp);
				strcat(buff,")");
				strcat(buff,"    ");
			}

		}

		else
			ERROR(38);

		L5: continue;
	}
	fp=fopen("C:/TC/PROJECT/SYSTEM/struct.dat","a");
	fprintf(fp,"%s\n",buff);
	fcloseall();
	fp=fopen(table,"w");
	fcloseall();
}

CHECK_VAR_COND()
{
	for(j=0;j<varcnt;j++)
	{
		if(stricmp(temp,var[j].varnm)==0)
			ERROR(39);
	}
}

UPDATE_VAR()
{
	strcpy(var[varcnt].varnm,temp);
	varcnt++;
}

DEL_TABLE_STRUCT()
{
	buff=(char *)malloc(100);
	fp=fopen("C:/TC/PROJECT/SYSTEM/struct.dat","r");
	fp1=fopen("C:/TC/PROJECT/SYSTEM/temp.dat","w");
	while(fgets(buff,80,fp))
	{
		sscanf(buff,"%s",temp);
		if(stricmp(temp,table)!=0)
			fprintf(fp1,"%s",buff);

	}
	fcloseall();
	remove("C:/TC/PROJECT/SYSTEM/struct.dat");
	rename("C:/TC/PROJECT/SYSTEM/temp.dat","C:/TC/PROJECT/SYSTEM/struct.dat");

}

DEL_TABLE_LINK()
{
	buff=(char *)malloc(100);
	fp=fopen("C:/TC/PROJECT/SYSTEM/link.dat","r");
	fp1=fopen("C:/TC/PROJECT/SYSTEM/temp.dat","w");
	while(fgets(buff,80,fp))
	{
		sscanf(buff,"%s",temp);
		if(stricmp(temp,table)!=0)
			fprintf(fp1,"%s",buff);
	}
	fcloseall();
	remove("C:/TC/PROJECT/SYSTEM/link.dat");
	rename("C:/TC/PROJECT/SYSTEM/temp.dat","C:/TC/PROJECT/SYSTEM/link.dat");

	fp=fopen("C:/TC/PROJECT/SYSTEM/disable.dat","r");
	fp1=fopen("C:/TC/PROJECT/SYSTEM/temp.dat","w");
	while(fgets(buff,80,fp))
	{
		sscanf(buff,"%s",temp);
		if(stricmp(temp,table)!=0)
			fprintf(fp1,"%s",buff);
	}
	fcloseall();
	remove("C:/TC/PROJECT/SYSTEM/disable.dat");
	rename("C:/TC/PROJECT/SYSTEM/temp.dat","C:/TC/PROJECT/SYSTEM/disable.dat");

}

DEL_TRIGGER_LINK()
{
	buff=(char *)malloc(100);
	fp=fopen("C:/TC/PROJECT/SYSTEM/link.dat","r");
	fp1=fopen("C:/TC/PROJECT/SYSTEM/temp.dat","w");

	while(fgets(buff,80,fp))
	{
		j=0;
		strcpy(com,buff);
		while(j<3)
		{
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
			j++;
		}
		sscanf(com,"%s",temp);
		if(stricmp(temp,table)!=0)
			fprintf(fp1,"%s",buff);
	}
	fcloseall();
	remove("C:/TC/PROJECT/SYSTEM/link.dat");
	rename("C:/TC/PROJECT/SYSTEM/temp.dat","C:/TC/PROJECT/SYSTEM/link.dat");

	fp=fopen("C:/TC/PROJECT/SYSTEM/disable.dat","r");
	fp1=fopen("C:/TC/PROJECT/SYSTEM/temp.dat","w");

	while(fgets(buff,80,fp))
	{
		j=0;
		strcpy(com,buff);
		while(j<3)
		{
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
			j++;
		}
		sscanf(com,"%s",temp);
		if(stricmp(temp,table)!=0)
			fprintf(fp1,"%s",buff);
	}
	fcloseall();
	remove("C:/TC/PROJECT/SYSTEM/DISABLE.dat");
	rename("C:/TC/PROJECT/SYSTEM/temp.dat","C:/TC/PROJECT/SYSTEM/DISABLE.dat");
}

DISABLE_TRIGGER()
{

	buff=(char *)malloc(100);
	fp=fopen("C:/TC/PROJECT/SYSTEM/link.dat","r");
	fp1=fopen("C:/TC/PROJECT/SYSTEM/disable.dat","a");
	while(fgets(buff,80,fp))
	{
		j=0;
		strcpy(com,buff);
		while(j<3)
		{
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
			j++;
		}
		sscanf(com,"%s",temp);
		if(stricmp(temp,table)==0)
		{
			fprintf(fp1,"%s\n",buff);
			break;
		}

	}
	fp=fopen("C:/TC/PROJECT/SYSTEM/link.dat","r");
	fp1=fopen("C:/TC/PROJECT/SYSTEM/temp.dat","w");
	while(fgets(buff,80,fp))
	{
		j=0;
		strcpy(com,buff);
		while(j<3)
		{
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
			j++;
		}
		sscanf(com,"%s",temp);
		if(stricmp(temp,table)!=0)
		{
			fprintf(fp1,"%s\n",buff);
			break;
		}

	}
	fcloseall();
	remove("C:/TC/PROJECT/SYSTEM/link.dat");
	rename("C:/TC/PROJECT/SYSTEM/temp.dat","C:/TC/PROJECT/SYSTEM/link.dat");

}

ENABLE_TRIGGER()
{
	buff=(char *)malloc(100);
	fp=fopen("C:/TC/PROJECT/SYSTEM/disable.dat","r");
	fp1=fopen("C:/TC/PROJECT/SYSTEM/link.dat","a");
	while(fgets(buff,80,fp))
	{
		j=0;
		strcpy(com,buff);
		while(j<3)
		{
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
			j++;
		}
		sscanf(com,"%s",temp);
		if(stricmp(temp,table)==0)
		{
			fprintf(fp1,"%s\n",buff);
			break;
		}
	}
	fcloseall();
	fp=fopen("C:/TC/PROJECT/SYSTEM/disable.dat","r");
	fp1=fopen("C:/TC/PROJECT/SYSTEM/temp.dat","w");
	while(fgets(buff,80,fp))
	{
		j=0;
		strcpy(com,buff);
		while(j<3)
		{
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
			j++;
		}
		sscanf(com,"%s",temp);
		if(stricmp(temp,table)!=0)
		{
			fprintf(fp1,"%s\n",buff);
			break;
		}
	}
	fcloseall();
	remove("C:/TC/PROJECT/SYSTEM/disable.dat");
	rename("C:/TC/PROJECT/SYSTEM/temp.dat","C:/TC/PROJECT/SYSTEM/disable.dat");
}
