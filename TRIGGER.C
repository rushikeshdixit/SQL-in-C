/*=============================== TRIGGER ==================================*/
int k,j,i;
char *comp,*table,*tbak,*com,*type,*buff1,*path;
int flag1=0,flag2=0,flag3=0,det,rcnt;
FILE *fp1,*fp2;
long len;


void SCAN_TRIGGER(char com[],char oper[],char table[],char temp[],char temp1[],char buff[],char tname[],FILE *fp,FILE *fp1,int i,char time[],char temp2[])
{
	flag1=0;
	flag2=0;
	buff=(char *)malloc(100);
	temp2=(char *)malloc(100);
	type=(char *)malloc(3);
	tname=(char *)malloc(10);
	tbak=(char *)malloc(50);
	comp=(char *)malloc(12);
	i=0;
	strcpy(type," ");
	sscanf(com,"%s",temp); // CREATE
	strcpy(buff,temp);
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%s",temp);   //DETECT 'OR'|| 'TRIGGER'
	strcat(buff," ");
	strcat(buff,temp);

	if(stricmp(temp,"OR")==0)
	{
		com=strchr(com,' ');
		while(com[0]==' ')
			com++;
		sscanf(com,"%s",temp1);

		if(stricmp(temp1,"REPLACE")!=0)
			ERROR(26);
		strcat(buff," REPLACE");
		flag1=1;

		com=strchr(com,' ');
		while(com[0]==' ')
			com++;
		sscanf(com,"%s",temp);
	}

	if(stricmp(temp,"TRIGGER")!=0)
		ERROR(27);
	strcpy(temp," ");
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%s",tname);  //DETECT TRIGGER NAME

	strcat(buff," ");
	strcat(buff,temp);
	strcat(buff," ");
	strcat(buff,tname);
	strcat(tname,".DAT");
	if(strstr(tname,"\\")==NULL)
	{
		strcpy(path,"C:\\TC\\PROJECT\\TRIGGERS\\");
		strcat(path,tname);
		strcpy(tname,path);
	}


	fp1=fopen(tname,"r");
	if((fp1!=NULL) && flag1==0)
		ERROR(21);
	if (fp1!=NULL)
	{
		fclose(fp1);
		fp1=fopen("C:/TC/PROJECT/SYSTEM/link.dat","r");
		fp2=fopen("C:/TC/PROJECT/SYSTEM/temp.dat","w");
		strcpy(comp,tname);
		while(fgets(temp2,80,fp1))
		{
			i=0;
			strcpy(tbak,temp2);
			while(i<3)
			{
				temp2=strchr(temp2,' ');
				while(temp2[0]==' ')
					temp2++;
				i++;
			}
			while(temp2[0]==' ')
				temp2++;
			sscanf(temp2,"%s",temp2);
			if(stricmp(temp2,comp)!=0)
			{
				fprintf(fp2,"%s",tbak);
			}
		}
		fcloseall();
		remove("C:/TC/PROJECT/SYSTEM/link.dat");
		rename("C:/TC/PROJECT/SYSTEM/temp.dat","C:/TC/PROJECT/SYSTEM/link.dat");
		strcpy(tname,comp);
	}
	else
		flag2=1;
	fcloseall();
	fp=fopen(tname,"w");
	fprintf(fp,"%s\n",buff);
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;

	sscanf(com,"%s",time); //DETECT AFTER || BEFORE
	strcpy(buff,time);
	if(stricmp(time,"BEFORE")!=0 && stricmp(time,"AFTER")!=0)
	{
		remove(tname);
		ERROR(28);
	}
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%s",oper); //DELETE / INSERT / UPDATE
	strcat(buff," ");
	strcat(buff,oper);

	if(stricmp(oper,"INSERT")==0 || stricmp(oper,"DELETE")==0)
	{
		com=strchr(com,' ');
		while(com[0]==' ')
			com++;
		sscanf(com,"%s",temp1);
		if(stricmp(temp1,"ON")!=0)
		{
			remove(tname);
			ERROR(22); //DETECT ON
		}
		strcat(buff," ");
		strcat(buff,temp1);
	}
	else
	if(stricmp(oper,"UPDATE")==0)
	{
		com=strchr(com,' ');
		while(com[0]==' ')
			com++;
		sscanf(com,"%s",temp1);
		if(stricmp(temp1,"OF")!=0)
		{
			remove(tname);
			ERROR(33); //DETECT OF
		}
		strcat(buff," OF");
		com=strchr(com,' ');
		while(com[0]==' ')
			com++;
		sscanf(com,"%s",temp2);
		FIND_FIELD_FILE();
		strcat(buff," ");
		strcat(buff,temp2);
		com=strchr(com,' ');
		while(com[0]==' ')
			com++;
		sscanf(com,"%s",temp1);
		if(stricmp(temp1,"ON")!=0)
		{
			remove(tname);
			ERROR(22); //DETECT ON
		}
		strcat(buff," ");
		strcat(buff,temp1);

	}
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%s",table);
	strcat(buff," ");
	strcat(buff,table);
	fprintf(fp,"%s\n",buff);
	strcat(table,".DAT");
	if(strstr(table,"\\")==NULL)
	{
		strcpy(path,"C:\\TC\\PROJECT\\TABLES\\");
		strcat(path,table);
		strcpy(table,path);
	}


	DOWNLOD_STRUCT();

	buff=(char *)malloc(100);
	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	sscanf(com,"%s",temp1);  //DETECT FOR OR DECLARE
	strcpy(buff,temp1);
	fprintf(fp,"%s",buff);

	if(stricmp(temp1,"FOR")==0)
	{
		com=strchr(com,' ');
		while(com[0]==' ')
			com++;
		sscanf(com,"%s",temp1);
		if(stricmp(temp1,"EACH")!=0)
		{
			remove(tname);
			ERROR(23);
		}
		com=strchr(com,' ');
		while(com[0]==' ')
			com++;
		sscanf(com,"%s",temp1);
		if(stricmp(temp1,"ROW")!=0)
		{
			remove(tname);
			ERROR(24);
		}
		strcpy(temp2,"ROW");
		strcpy(temp1,"EACH ROW");
		fprintf(fp," %s",temp1);
		strcpy(type,"ROW");
	}
	else
		fprintf(fp,"\n");

	if(stricmp(temp1,"BEGIN")!=0)
	{
		com=strchr(com,' ');
		while(com[0]==' ')
			com++;
		sscanf(com,"%[^ ]s",temp1);
		if(stricmp(temp1,"BEGIN")!=0)
		{
			remove(tname);
			ERROR(25);
		}
		fprintf(fp,"\n%s\n",temp1);
	}

	com=strchr(com,' ');
	while(com[0]==' ')
		com++;
	k=0;
	while(1)
	{
		sscanf(com,"%[^( ]s",temp1); //ROLLBACK || OUTPUT || IF
		if(stricmp(temp1,"ELSE")==0)
		{
			if(k==0)
			{
				remove(tname);
				ERROR(31);
			}
			fprintf(fp,"ELSE\n");
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
			sscanf(com,"%[^ (]s",temp1);
		}

		if(stricmp(temp1,"END")==0)
		{
			if(k!=0)
			{
				com=strchr(com,' ');
				while(com[0]==' ')
					com++;
				sscanf(com,"%[^ ;]s",temp1);
				if(stricmp(temp1,"IF")!=0)
				{
					remove(tname);
					ERROR(32);
				}
				com+=strlen(temp1);
				while(com[0]==' ')
					com++;
				if(com[0]!=';')
				{
					remove(tname);
					ERROR(3);
				}
				temp1=" ";
				com++;
				fprintf(fp,"END IF;\n");
				k=0;
			}
			else
				goto L1;
		}

		if(stricmp(temp1,"IF")==0)
		{
			com+=strlen(temp1);
			while(com[0]==' ')
				com++;
			if(com[0]!='(')
			{
				remove(tname);
				ERROR(35);
			}
			com++;
			while(com[0]==' ')
				com++;
			fprintf(fp,"IF(");
			while(1)
			{
				if((com[0]==':' && k==0 )|| (com[0]==':' && k==2))
				{
					if(stricmp(type,"ROW")!=0)
					{
						remove(tname);
						ERROR(26);
					}
					com++;
					sscanf(com,"%[^.]s",temp1);
					if(stricmp(temp1,"OLD")!=0 && stricmp(temp1,"NEW")!=0)
					{
						remove(tname);
						ERROR(27);
					}
					com+=strlen(temp1)+1;
					sscanf(com,"%[^) ]s",temp2);
					FIND_FIELD_STRUCT();
					com+=strlen(temp2);
					while(com[0]==' ')
						com++;
					fprintf(fp," :%s.%s",temp1,temp2);
					k++;
				}

				if(k==1)
				{
					sscanf(com,"%[=<>]s",temp1);
					if(stricmp(temp1,"=")!=0 &&
						stricmp(temp1,"<")!=0 &&
						stricmp(temp1,">")!=0 &&
						stricmp(temp1,"<=")!=0 &&
						stricmp(temp1,">=")!=0)
					{
						remove(tname);
						ERROR(19);
					}
					com+=strlen(temp1);
					fprintf(fp," %s",temp1);
					while(com[0]==' ')
						com++;
					k++;
				}

				if((com[0]!=':' && k==0) || (com[0]!=':' && k==2))
				{
					sscanf(com,"%[0-9]s",temp1);
					sscanf(com,"%[^) ]s",temp2);
					if(strlen(temp1)!=strlen(temp2))
					{
						remove(tname);
						ERROR(29);
					}
					com+=strlen(temp1);
					fprintf(fp," %s",temp1);
					while(com[0]==' ')
						com++;
					k++;
				}

				if(k==3)
				{
					if(com[0]!=')')
					{
						remove(tname);
						ERROR(15);
					}
					com++;
					while(com[0]==' ')
						com++;
					sscanf(com,"%[^ ]s",temp1);
					if(stricmp(temp1,"THEN")!=0)
					{
						remove(tname);
						ERROR(30);
					}
					com=strchr(com,' ');
					while(com[0]==' ')
						com++;
					sscanf(com,"%[^ (]s",temp1);
					fprintf(fp," ) THEN\n");
					break;
				}
			}
		}

//ROLLBACK
		if(stricmp(temp1,"ROLLBACK")==0 || stricmp(temp1,"ROLLBACK;")==0)
		{
			fprintf(fp,temp1);
			if(strstr(temp1,";")==NULL)
			{
				com+=strlen("ROLLBACK");
				while(com[0]==' ')
					com++;
				if(com[0]!=';')
				{
					remove(tname);
					ERROR(3);
				}
				fprintf(fp,";");
			}
			fprintf(fp,"\n");
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
			sscanf(com,"%[^ (]s",temp1);
		}

//OUTPUT           else
		if(stricmp(temp1,"OUTPUT")==0)
		{
			fprintf(fp,temp1);
			i=0;
			while(com!=NULL)
			{
				while(com[0]==' ')
				com++;
				if(i==0)
				{
					com=strchr(com,'(');
					if(com==NULL)
					{
						remove(tname);
						ERROR(11);
					}
					strcpy(buff,"(");
					fprintf(fp,"%s",buff);
					com++;
					while(com[0]==' ')
						com++;
					i++;
				}//IF I == 0

				if(com[0]==':')
				{
					if(stricmp(type,"ROW")!=0)
					ERROR(26);
					sscanf(com,"%[^,)]s",buff);
					if(stricmp(temp2,"ROW")!=0)
					{
						remove(tname);
						ERROR(24);
					}
					com++;
					sscanf(com,"%[^.]s",temp1);

					if(stricmp(temp1,"NEW")!=0 && stricmp(temp1,"OLD")!=0)
					{
						remove(tname);
						ERROR(27);
					}
					com=strchr(com,'.');com++;
					sscanf(com,"%[^,)]s",temp);
					CHK_FILE_INFO(table,temp,tname);
					com+=strlen(temp);
					while(com[0]==' ')
						com++;
					fprintf(fp,"%s",buff);
				} // IF :

				if(com[0]== '\'')
				{
					strcpy(buff,"'");
					com++;
					sscanf(com,"%[^,)]s",temp1);
					i=strlen(temp1);
					if(temp1[i-1]!= '\'')
					{
						remove(tname);
						ERROR(13);
					}
					strcat(buff,temp1);
					fprintf(fp,"%s",buff);
					com=strchr(com,'\'');
					com++;
				} // IF '


				if(com[0]==')')
				{
					com=strchr(com,';');
					if(com[0]!=';')
					{

						remove(tname);
						ERROR(3);
					}
					strcpy(buff,");");
					fprintf(fp,"%s\n",buff);
					com++;
					break;
				} // IF )

				if(com[0]==',')
				{
					com++;
					fprintf(fp,",");
				}

			} //WHILE
			com=strchr(com,' ');
			while(com[0]==' ')
				com++;
		} //OUTPUT

		else
		if(k==0 && stricmp(temp1,"END")==0||stricmp(temp1,"END;")==0)
			break;

		else
		if(k==0)
			break;
	} //WHILE(1)
	L1 : while(com[0]==' ')
		com++;
	sscanf(com,"%[^;]s",temp1);
	while(com[0]==' ')
		com++;
	if(stricmp(temp1,"END")==0)
	{
		com=strchr(com,';');
		if(com==NULL)
		{
			remove(tname);
			ERROR(3);
		}
		com++;
		while(com[0]== ' ')
			com++;
		if(strlen(com)!=0)
		{
			remove(tname);
			ERROR(5);
		}
	}
	strcpy(buff,"END;");
	fprintf(fp,"%s\n",buff);

	fcloseall();
	fp1=fopen("C:/TC/PROJECT/SYSTEM/link.dat","a");
	strcpy(buff,table);
	strcat(buff," ");
	strcat(buff,oper);
	strcat(buff," ");
	strcat(buff,time);
	strcat(buff," ");
	strcat(buff,tname);
	fprintf(fp1,"%s\n",buff);
	fcloseall();

}

SEARCH_TRIGGER(char buff[],char tname[],char oper[],char table[],FILE *fp,char time[])
{
	k=0;
	buff=(char *)malloc(100);
	fp=fopen("C:/TC/PROJECT/SYSTEM/link.dat","r");

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

				if(stricmp(time,"B")==0 && stricmp(tname,"BEFORE")==0
					|| stricmp(time,"A")==0 && stricmp(tname,"AFTER")==0)
				{
					buff=strchr(buff,' ');
					while(buff[0]==' ')
						buff++;
					sscanf(buff,"%s",tname);
					k++;
				}
			}

		}

	}
	if(k!=0)
	{
		if(stricmp(time,"B")==0)
			strcpy(time,"BEFORE");
		if(stricmp(time,"A")==0)
			strcpy(time,"AFTER");
	}
	return time;

}


EXEC_TRIGGER(char buff[],char tname[],FILE *fp,char temp[],char temp1[],char temp2[],char oper[],char time[])
{ 
	int flag=0,flag1=0;
	buff=(char *)malloc(100);
	buff1=(char *)malloc(100);
	com=(char *)malloc(20);
	tbak=(char *)malloc(20);
	fp=fopen(tname,"r");
	tname=(char *)malloc(100);
	printf("\n");
	j=0;
	while(fgets(buff,80,fp))
	{
		j++;
		sscanf(buff,"%[^\n]s",buff);
		if(buff==NULL || strlen(buff)==0)
			break;

		if(stricmp(oper,"UPDATE")==0)
		{
			if(j==2)
			{
				i=0;
				while(i<3)
				{
					buff=strchr(buff,' ');
					while(buff[0]==' ')
						buff++;
					i++;
				}
				sscanf(buff,"%s",temp2);
				FIND_FIELD_STRUCT();
				if(i!=det)
					break;

			}
		}

		if(flag==1)
		{
			if(flag1==1)
			{
				if(stricmp(buff,"END IF;")==0)
					flag1=0;
				if(stricmp(buff,"ELSE")==0)
					flag1=4;
				if(stricmp(buff,"ROLLBACK;")==0)
					goto L2;
				if(strstr(buff,"OUTPUT")==0)
					goto L3;
			}

			else
			if(flag1==2)
			{
				if(stricmp(buff,"END IF;")==0)
					flag1=0;
				else
				if(stricmp(buff,"ELSE")==0)
					flag1=3;
				else
					strcpy(buff," ");
			}

			else
			if(flag1==3)
			{
				if(stricmp(buff,"END IF;")==0)
					flag1=0;
				if(stricmp(buff,"ROLLBACK;")==0)
					goto L2;
				if(strstr(buff,"OUTPUT")==0)
					goto L3;
			}

			else
			if(flag1==4)
			{
				if(stricmp(buff,"END IF;")==0)
					flag1=0;
				strcpy(buff," ");
			}

			else
			if(strstr(buff,"IF")!=NULL)
			{
				buff=strchr(buff,'(');
				buff++;
				sscanf(buff,"%[^)]s",buff);

				while(buff[0]==' ')
					buff++;

				if(buff[0]==':')
				{
					sscanf(buff+1,"%[^.]s",buff1);
					buff=strchr(buff,'.');
					buff++;
					sscanf(buff,"%[^><= ]s",temp2);
					FIND_FIELD_STRUCT();
					buff+=strlen(temp2);
					while(buff[0]==' ')
						buff++;
					sscanf(buff,"%[><=]s",comp);
					buff+=strlen(comp);
					while(buff[0]==' ')
						buff++;

					if(stricmp(oper,"UPDATE")==0)
					{
						while(buff!=NULL)
						{
							if(strlen(buff)==0)
							{
								goto L4;
							}
							if(stricmp(buff1,"OLD")==0)
							{
								flag3=1;
								FIND_FIELD_FILE();
								flag3=0;
							}
							if(stricmp(buff1,"NEW")==0 && det==i)
							{
								strcpy(tbak,temp);
							}

							sscanf(buff+1,"%[^.]s",buff1);
							buff=strchr(buff,'.');
							buff++;
							sscanf(buff,"%[^><= ]s",temp2);
							FIND_FIELD_STRUCT();
						}
					}
					sscanf(buff,"%s",temp2);

					if(stricmp(oper,"DELETE")==0 && stricmp(time,"AFTER")==0)
					{
						sscanf(table,"%[^.]s",table);
						strcat(table,".bak");
					}
					fp1=fopen(table,"r");

					while(fgets(tname,80,fp1))
					{
						if(stricmp(oper,"INSERT")==0)
						{
							len=ftell(fp1);
							CAL_REC();
							fseek(fp1,(rcnt-1)*len,SEEK_SET);
							fgets(tname,200,fp1);
							det=i;
							strcpy(tname,buff1);
						}

						if(tname==NULL || strlen(tname)==0)
							break;
						j=0;
						strcpy(com,tname);

						while(j!=det)
						{
							com=strchr(com,' ');
							while(com[0]==' ')
								com++;
							j++;
						}
						sscanf(com,"%s",tbak);
						j=0;
						strcpy(com,tname);
						while(j!=det)
						{
							com=strchr(com,' ');
							while(com[0]==' ')
								com++;
							j++;
						}

						if(stricmp(oper,"INSERT")==0)
						{
							j=0;
							while(j!=det)
							{
								tname=strchr(tname,' ');
								while(tname[0]==' ')
									tname++;
								j++;
							}
							sscanf(tbak,"%s",tname);
							goto L4;
						}


						if(stricmp(temp,tbak)==0)
						{
							j=0;
							while(j!=i)
							{
								tname=strchr(tname,' ');
								while(tname[0]==' ')
									tname++;
								j++;
							}
							sscanf(tname,"%s",tbak);

							L4: if(stricmp(comp,"=")==0)
							{
								if(stricmp(tbak,temp2)==0)
									flag1=1;
							}

							else
							if(stricmp(comp,">")==0)
							{
								if(atoi(tbak) > atoi(temp2) && atoi(tbak) != atoi(temp2))
									flag1=1;
							}

							else
							if(stricmp(comp,"<")==0)
							{
								if(atoi(tbak) < atoi(temp2) && atoi(tname) != atoi(temp2))
									flag1=1;
							}

							else
							if(stricmp(comp,">=")==0)
							{
								if(atoi(tbak) >= atoi(temp2))
									flag1=1;
							}

							else
							if(stricmp(comp,"<=")==0)
							{
								if(atoi(tbak) <= atoi(temp2))
									flag1=1;
							}
						}
					}
				}
				if (flag1==0)
					flag1=2;
			}

			else
			if(stricmp(buff,"END;")==0)
				break;

			L2: if(stricmp(buff,"ROLLBACK;")==0)
			{
				ROLLBACK();
				printf("\nSUCCESSFULL ROLLBACK");
			}

			L3: if(strstr(buff,"OUTPUT")!=NULL)
			{
				printf("\n");
				buff=strchr(buff,'(');
				buff++;
				strrev(buff);
				buff++;
				buff++;
				strrev(buff);

				while(buff!=NULL)
				{
					while(buff[0]==' ')
						buff++;

					if(buff[0]=='\'')
					{
						buff++;
						sscanf(buff,"%[^']s",buff1);
						printf("%s\t",buff1);
						buff=strchr(buff,'\'');
						buff++;
					}
					else
					if(buff[0]==',')
						buff++;

					else
					if(buff[0]==':')
					{
						buff++;
						sscanf(buff,"%[^.]s",buff1);
						buff=strchr(buff,'.');
						buff++;
						sscanf(buff,"%[^,)]s",temp2);

						if(stricmp(buff1,"NEW")==0 && stricmp(oper,"INSERT")==0 && stricmp(time,"AFTER")==0 || stricmp(time,"AFTER")==0 && stricmp(buff1,"OLD")==0 && stricmp(oper,"DELETE")==0)
						{
							FIND_FIELD_STRUCT();
							FIND_FIELD_FILE();
						}

						if(stricmp(oper,"UPDATE")==0)
						{
							if(stricmp(buff1,"OLD")==0)
							{
								FIND_FIELD_STRUCT();
								FIND_FIELD_FILE();
							}
							else
							{
								FIND_FIELD_STRUCT();
								if(i!=det)
									FIND_FIELD_FILE();
								else
									printf("%s\t",temp);
							}
						}

						buff+=strlen(temp2);
						while(buff[0]==' ')
							buff++;
						j=3;
					}
					else
						break;
				}
			}
		}

		else
		if(stricmp(buff,"BEGIN")==0)
			flag=1;
		sscanf(table,"%[^.]s",table);
		strcat(table,".dat");

	}

	getch();
	fcloseall();
}
