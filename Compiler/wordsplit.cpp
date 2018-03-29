#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"scanner.h"
char *keyword[] = {"123","1234"};
int match_code(char *word)
{
	for(int i=0;i<48;i++)
	{
		if(strcmp(word,keyword[i]) == 0)
		{
			return i+1;
		}
	}
	return ID;

}

void file_write(char *word)
{
	FILE * file;
	file = fopen("out.txt","a");
	fprintf(file,"%s",word);
	fclose(file);
}
WORD * wordScanner(FILE * file)
{
	//int i;
	char a[10000]; //∂®“Âtxt◊™ªØÀ˘”–µƒŒƒ±æ
	//int num[100][100];
	//char letter[100][100];
	WORD *ret = new WORD();
	char ch = NULL;
	char variable[25] ;
	char *des;//¥Ê¥¢description√Ë ˆ
	int state = 0;
	int n = 0;
	while(ch != EOF)
	{
		ch =  fgetc(file);

		//¥¶¿Ì◊¢ Õ 46
		if(ch == '/') 
		{
			ch = fgetc(file);
			if(ch == '/')
			{
				//Œƒº˛ƒ©≤ª «ªª––∑˚\n
				while(  ch != '\n')//ch!= ' ' &&
				{
					ch = fgetc(file);
					//nothing happen				
				}
				ret->code = LINE_ZHUSHI;
				ret->word_meaning = "//";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
			}
			//◊¢ Õ∑÷∏Ó47+48
					
			else if(ch == '*')
			{
				ch = fgetc(file);
				ret->code = L_ZHUSHI;
				ret->word_meaning = "/*";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				while(1)
				{
					while( ch != '*')
					{
						ch = fgetc(file);					
					}
					ch = fgetc(file);
					if(ch == '/')
					{
						ret->code = R_ZHUSHI;
						ret->word_meaning = "*/";
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
						//return /* ∫Õ */
						break;	
					}
				}
			}
			else //31
			{
				ret->code = DIV;
				ret->word_meaning = "/";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				fseek(file,-1,1);
				//return ≥˝∫≈
			}
		}
		
		//◊÷∑˚πÿº¸◊÷
		else if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_')
		{
			n = 0; //◊÷Õ∑÷∏’Î
			state = 0;//◊÷∑˚±‰¡ø
			if(ch == 'b')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if(ch == 'r')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 'e')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if(ch == 'a')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if(ch == 'k')
							{
								ch = fgetc(file);
								if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										variable[n++] = ch;
										ch = fgetc(file);
									}
									des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
									memcpy(des,variable,n);
									des[n] = '\0';
									fseek(file,-1,1);
									ret->code = ID;
									ret->word_meaning = des;
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
								else
								{
									fseek(file,-1,1);
									//return break;
									ret->code = BREAK;
									ret->word_meaning = "break";
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
							}
							else
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
			}
			
			else if(ch == 'c')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if( ch == 'a')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if( ch == 's')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if( ch == 'e')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
							else
							{
								fseek(file,-1,1);
												
								ret->code = CASE;
								ret->word_meaning = "case";
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else if(ch == 'o')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 'n')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if( ch == 't')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if( ch == 'i')
							{
								variable[n++] = ch;
								ch = fgetc(file);
								if( ch == 'n')
								{
									variable[n++] = ch;
									ch = fgetc(file);
									if( ch == 'u')
									{
										variable[n++] = ch;
										ch = fgetc(file);
										if( ch == 'e')
										{
											variable[n++] = ch;
											ch = fgetc(file);
											if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
											{
												while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
												{
													variable[n++] = ch;
													ch = fgetc(file);
												}
												des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
												memcpy(des,variable,n);
												des[n] = '\0';
												fseek(file,-1,1);
												ret->code = ID;
												ret->word_meaning = des;
												char str[100];
												sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
												file_write(str);
											}
											else
											{
												fseek(file,-1,1);
												
												ret->code = CONTINUE;
												ret->word_meaning = "continue";
												char str[100];
												sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
												file_write(str);
											}
										}
										else
										{
											while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
											{
												variable[n++] = ch;
												ch = fgetc(file);
											}
											des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
											memcpy(des,variable,n);
											des[n] = '\0';
											fseek(file,-1,1);
											ret->code = ID;
											ret->word_meaning = des;
											char str[100];
											sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
											file_write(str);
										}
									}
									else
									{
										while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
										{
											variable[n++] = ch;
											ch = fgetc(file);
										}
										des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
										memcpy(des,variable,n);
										des[n] = '\0';
										fseek(file,-1,1);
										ret->code = ID;
										ret->word_meaning = des;
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
								}
								else
								{
									while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										variable[n++] = ch;
										ch = fgetc(file);
									}
									des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
									memcpy(des,variable,n);
									des[n] = '\0';
									fseek(file,-1,1);
									ret->code = ID;
									ret->word_meaning = des;
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
							}
							else
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else if(ch == 'h')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 'a')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if(ch == 'r')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
							else
							{
								fseek(file,-1,1);
								//return break;
								ret->code = CHAR;
								ret->word_meaning = "char";
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}

				}
				else
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
			}

			//define
			else if( ch == 'd')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if( ch == 'o')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
					else
					{
						fseek(file,-1,1);
												
						ret->code = DO;
						ret->word_meaning = "do";
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else if( ch == 'e')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 'f')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if(ch == 'i')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if( ch =='n')
							{
								variable[n++] = ch;
								ch = fgetc(file);
								if( ch == 'e')
								{
									variable[n++] = ch;
									ch = fgetc(file);
									if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
										{
											variable[n++] = ch;
											ch = fgetc(file);
										}
										des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
										memcpy(des,variable,n);
										des[n] = '\0';
										fseek(file,-1,1);
										ret->code = ID;
										ret->word_meaning = des;
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
									else
									{
										fseek(file,-1,1);
										ret->code = DEFINE;
										ret->word_meaning = "define";
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
								}
								else
								{
									while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										variable[n++] = ch;
										ch = fgetc(file);
									}
									des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
									memcpy(des,variable,n);
									des[n] = '\0';
									fseek(file,-1,1);
									ret->code = ID;
									ret->word_meaning = des;
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
							}
							else
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
			}

			// ELSE ∫Õ ELSEIF
			else if(ch == 'e')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if( ch == 'l')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if( ch == 's')
					{
						variable[n++] = ch ;
						ch = fgetc(file);
						if( ch == 'e')
						{
							variable[n++] = ch ;
							ch = fgetc(file);
							if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
							else if(ch == ' ')
							{
								ch = fgetc(file);
								if(ch =='i')
								{
									ch = fgetc(file);
									if( ch == 'f')
									{
										ret->code = ELSEIF;
										ret->word_meaning = "else if";
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
									else
									{
										fseek(file,-2,1);
										ret->code = ELSE;
										ret->word_meaning = "else";
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
								}
								else
								{
									fseek(file,-1,1);
									ret->code = ELSE;
									ret->word_meaning = "else";
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
							}
							else
							{
								fseek(file,-1,1);
								ret->code = ELSE;
								ret->word_meaning = "else";
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
				
			}

			//float
			else if(ch == 'f')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if( ch == 'l')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 'o')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if(ch == 'a')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if(ch == 't')
							{
								variable[n++] = ch;
								ch = fgetc(file);
								if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										variable[n++] = ch;
										ch = fgetc(file);
									}
									des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
									memcpy(des,variable,n);
									des[n] = '\0';
									fseek(file,-1,1);
									ret->code = ID;
									ret->word_meaning = des;
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
								else
								{
									fseek(file,-1,1);
									ret->code = FLOAT;
									ret->word_meaning = "float";
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
							}
							else
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else if( ch == 'o')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if( ch == 'r')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
						else
						{
							fseek(file,-1,1);
							ret->code = FOR;
							ret->word_meaning = "for";
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
				
			}
			//include && int && if
			else if(ch == 'i')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if(ch == 'n')
				{
					ch = fgetc(file);
					if(ch == 't')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
						else
						{
							fseek(file,-1,1);
							ret->code = INT;
							ret->word_meaning = "int";
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
						//return int 
					}
					else if(ch == 'c')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if(ch == 'l')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if(ch == 'u')
							{
								variable[n++] = ch;
								ch = fgetc(file);
								if(ch == 'd')
								{
									variable[n++] = ch;
									ch = fgetc(file);
									if( ch == 'e')
									{
										variable[n++] = ch;
										ch = fgetc(file);
										if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
										{
											while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
											{
												variable[n++] = ch;
												ch = fgetc(file);
											}
											des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
											memcpy(des,variable,n);
											des[n] = '\0';
											fseek(file,-1,1);
											ret->code = ID;
											ret->word_meaning = des;
											char str[100];
											sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
											file_write(str);
										}
										else
										{
											fseek(file,-1,1);
											ret->code = INCLUDE;
											ret->word_meaning = "include";
											char str[100];
											sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
											file_write(str);
										}
									}
									else
									{
										while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
										{
											variable[n++] = ch;
											ch = fgetc(file);
										}
										des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
										memcpy(des,variable,n);
										des[n] = '\0';
										fseek(file,-1,1);
										ret->code = ID;
										ret->word_meaning = des;
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}

								}
								else
								{
									while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										variable[n++] = ch;
										ch = fgetc(file);
									}
									des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
									memcpy(des,variable,n);
									des[n] = '\0';
									fseek(file,-1,1);
									ret->code = ID;
									ret->word_meaning = des;
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
							}
							else
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else if(ch == 'f')
				{
					ret->code = IF;
					ret->word_meaning = "if";
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
					//return if
				}
				else 
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
			}

			//main
			else if( ch == 'm')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if( ch == 'a')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 'i')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if( ch == 'n')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
							else
							{
								fseek(file,-1,1);
								ret->code = MAIN;
								ret->word_meaning = "main";
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
			}

			//printf
			else if( ch == 'p')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if( ch == 'r')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 'i')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if( ch == 'n')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if( ch == 't')
							{
								variable[n++] = ch;
								ch = fgetc(file);
								if( ch == 'f')
								{
									variable[n++] = ch;
									ch = fgetc(file);
									if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
										{
											variable[n++] = ch;
											ch = fgetc(file);
										}
										des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
										memcpy(des,variable,n);
										des[n] = '\0';
										fseek(file,-1,1);
										ret->code = ID;
										ret->word_meaning = des;
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
									else
									{
										fseek(file,-1,1);
										ret->code = PRINTF;
										ret->word_meaning = "printf";
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
								}
								else
								{
									while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										variable[n++] = ch;
										ch = fgetc(file);
									}
									des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
									memcpy(des,variable,n);
									des[n] = '\0';
									fseek(file,-1,1);
									ret->code = ID;
									ret->word_meaning = des;
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
							}
							else
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
			}

			//return
			else if( ch == 'r')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if( ch == 'e')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 't')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if( ch == 'u')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if( ch == 'r')
							{
								variable[n++] = ch;
								ch = fgetc(file);
								if( ch == 'n')
								{
									variable[n++] = ch;
									ch = fgetc(file);
									if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
										{
											variable[n++] = ch;
											ch = fgetc(file);
										}
										des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
										memcpy(des,variable,n);
										des[n] = '\0';
										fseek(file,-1,1);
										ret->code = ID;
										ret->word_meaning = des;
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
									else
									{
										fseek(file,-1,1);
										ret->code = RETURN;
										ret->word_meaning = "return";
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
								}
								else
								{
									while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										variable[n++] = ch;
										ch = fgetc(file);
									}
									des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
									memcpy(des,variable,n);
									des[n] = '\0';
									fseek(file,-1,1);
									ret->code = ID;
									ret->word_meaning = des;
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
							}
							else
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
			}

			//string ∫Õ struct
			else if( ch == 's')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if( ch == 't')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 'r')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if( ch == 'i')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if( ch == 'n')
							{
								variable[n++] = ch;
								ch = fgetc(file);
								if( ch == 'g')
								{
									variable[n++] = ch;
									ch = fgetc(file);
									if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
										{
											variable[n++] = ch;
											ch = fgetc(file);
										}
										des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
										memcpy(des,variable,n);
										des[n] = '\0';
										fseek(file,-1,1);
										ret->code = ID;
										ret->word_meaning = des;
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
									else
									{
										fseek(file,-1,1);
										ret->code = STRING;
										ret->word_meaning = "string";
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
								}
								else
								{
									while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										variable[n++] = ch;
										ch = fgetc(file);
									}
									des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
									memcpy(des,variable,n);
									des[n] = '\0';
									fseek(file,-1,1);
									ret->code = ID;
									ret->word_meaning = des;
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
							}
							else
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else if( ch == 'u')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if( ch == 'c')
							{
								variable[n++] = ch;
								ch = fgetc(file);
								if( ch == 't')
								{
									variable[n++] = ch;
									ch = fgetc(file);
									if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
										{
											variable[n++] = ch;
											ch = fgetc(file);
										}
										des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
										memcpy(des,variable,n);
										des[n] = '\0';
										fseek(file,-1,1);
										ret->code = ID;
										ret->word_meaning = des;
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
									else
									{
										fseek(file,-1,1);
										ret->code = STRUCT;
										ret->word_meaning = "struct";
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
								}
								else
								{
									while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										variable[n++] = ch;
										ch = fgetc(file);
									}
									des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
									memcpy(des,variable,n);
									des[n] = '\0';
									fseek(file,-1,1);
									ret->code = ID;
									ret->word_meaning = des;
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
							}
							else
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}

						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				if( ch == 'w')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 'i')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if( ch == 't')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if( ch == 'c')
							{
								variable[n++] = ch;
								ch = fgetc(file);
								if( ch == 'h')
								{
									variable[n++] = ch;
									ch = fgetc(file);
									if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
										{
											variable[n++] = ch;
											ch = fgetc(file);
										}
										des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
										memcpy(des,variable,n);
										des[n] = '\0';
										fseek(file,-1,1);
										ret->code = ID;
										ret->word_meaning = des;
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
									else
									{
										fseek(file,-1,1);
										ret->code = SWITCH;
										ret->word_meaning = "switch";
										char str[100];
										sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
										file_write(str);
									}
								}
								else
								{
									while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										variable[n++] = ch;
										ch = fgetc(file);
									}
									des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
									memcpy(des,variable,n);
									des[n] = '\0';
									fseek(file,-1,1);
									ret->code = ID;
									ret->word_meaning = des;
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
							}
							else
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else if( ch == 'c')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if( ch == 'a')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if( ch == 'n')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if( ch == 'f')
							{
								variable[n++] = ch;
								ch = fgetc(file);
								if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										variable[n++] = ch;
										ch = fgetc(file);
									}
									des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
									memcpy(des,variable,n);
									des[n] = '\0';
									fseek(file,-1,1);
									ret->code = ID;
									ret->word_meaning = des;
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
								else
								{
									fseek(file,-1,1);
									ret->code = SCANF;
									ret->word_meaning = "scanf";
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
							}
							else
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
			}

			//THEN
			//main
			else if( ch == 't')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if( ch == 'h')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 'e')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if( ch == 'n')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
							else
							{
								fseek(file,-1,1);
								ret->code = THEN;
								ret->word_meaning = "then";
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
			}

			//void
			else if( ch == 'v')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if( ch == 'o')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 'i')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if( ch == 'd')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
							else
							{
								fseek(file,-1,1);
								ret->code = MAIN;
								ret->word_meaning = "main";
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
			}

			//while
			//define
			else if( ch == 'w')
			{
				variable[n++] = ch;
				ch = fgetc(file);
				if( ch == 'h')
				{
					variable[n++] = ch;
					ch = fgetc(file);
					if(ch == 'i')
					{
						variable[n++] = ch;
						ch = fgetc(file);
						if(ch == 'l')
						{
							variable[n++] = ch;
							ch = fgetc(file);
							if( ch =='e')
							{
								variable[n++] = ch;
								ch = fgetc(file);
								if((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
									{
										variable[n++] = ch;
										ch = fgetc(file);
									}
									des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
									memcpy(des,variable,n);
									des[n] = '\0';
									fseek(file,-1,1);
									ret->code = ID;
									ret->word_meaning = des;
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
								else
								{
									fseek(file,-1,1);
									ret->code = WHILE;
									ret->word_meaning = "while";
									char str[100];
									sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
									file_write(str);
								}
								
							}
							else
							{
								while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
								{
									variable[n++] = ch;
									ch = fgetc(file);
								}
								des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
								memcpy(des,variable,n);
								des[n] = '\0';
								fseek(file,-1,1);
								ret->code = ID;
								ret->word_meaning = des;
								char str[100];
								sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
								file_write(str);
							}
						}
						else
						{
							while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
							{
								variable[n++] = ch;
								ch = fgetc(file);
							}
							des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
							memcpy(des,variable,n);
							des[n] = '\0';
							fseek(file,-1,1);
							ret->code = ID;
							ret->word_meaning = des;
							char str[100];
							sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
							file_write(str);
						}
					}
					else
					{
						while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
						{
							variable[n++] = ch;
							ch = fgetc(file);
						}
						des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
						memcpy(des,variable,n);
						des[n] = '\0';
						fseek(file,-1,1);
						ret->code = ID;
						ret->word_meaning = des;
						char str[100];
						sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
						file_write(str);
					}
				}
				else
				{
					while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
					{
						variable[n++] = ch;
						ch = fgetc(file);
					}
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = ID;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
				}
			}

			//Œ¥ÃÌº”»Ù∏…«Èøˆ
			
			else
			{
				while((ch >= 'a' && ch <= 'z') || (ch >='A' && ch <='Z') || ch == '_' || (ch >= '0' && ch <= '9'))
				{
					variable[n++] = ch;
					ch = fgetc(file);
				}
				des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
				memcpy(des,variable,n);
				des[n] = '\0';
				fseek(file,-1,1);
				ret->code = ID;
				ret->word_meaning = des;
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//return πÿº¸◊÷
			}
		}
		
		// ˝◊÷¿‡–Õ
		else if(ch >= '0' && ch <= '9')
		{
			n=0;
			int isFloat = 0;
			while( ch>= '0' && ch <='9')
			{
				variable[n++] = ch;
				ch = fgetc(file);
			}

			//float
			if (ch == '.') 
			{
				//return  float
                isFloat = 1;
                variable[n++] = ch;
                ch = fgetc(file);
                if (ch >= '0' && ch <= '9') 
				{
                    while (ch >= '0' && ch <= '9' )
					{
                        variable[n++] = ch;
                        ch = fgetc(file);
                    }
					des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
					memcpy(des,variable,n);
					des[n] = '\0';
					fseek(file,-1,1);
					ret->code = FLOAT_TYPE;
					ret->word_meaning = des;
					char str[100];
					sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
					file_write(str);
                }
				else
				{
					fseek(file,-1,1);
					//±®¥Ì
                    isFloat = -1;      //≥ˆ¥Ì£¨-1±Ì æ –° ˝µ„∫Û√ª”– ˝◊÷.
                }
            }
			else if(ch == ' ' || ch =='+' || ch =='-'|| ch =='*'|| ch == '/' || ch == ';' || ch == '\t' || ch == '\r' || ch == '\n' || ch == ')' || ch == ']' || ch =='}')
			{
				//return “ª∏ˆ’˚ ˝
				des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
				memcpy(des,variable,n);
				des[n] = '\0';
				fseek(file,-1,1);
				ret->code = INTEGER_TYPE;
				ret->word_meaning = des;
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);

			}
			else
			{
				state = -1;
				//return wrong!
			}
			/*
			des = (char*)malloc(sizeof(char)*(n+1));//¥Ê¥¢description√Ë ˆ
			memcpy(des,variable,n);
			des[n] = '\0';
			if(isFloat == 1)
			{
				int case1 = 2;
				//return des «“ª∏ˆfloat–Õ
				//CODE HERE
			}
			else if( isFloat  == 0)
			{
				int case2 = 3;
				//const ≥£ ˝
				//CODE HERE
			}
			*/
		}

		//ªª–– ”Îø’∏Ò
		else if(ch == ' ' || ch == '\t' || ch == '\r' || ch == '\n' )
		{
			//ch = fgetc(file);
			//nothing happen
		}

		//∫Í≥£¡ø ∫Õ Õ∑Œƒº˛ 57+58
		else if(ch == '#')
		{
			ch = fgetc(file);
			if(ch == 'd')
			{
				fseek(file,-1,1);
				ret->code = HONGDINGYI;
				ret->word_meaning = "#";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
			}
			else if(ch == 'i')
			{
				fseek(file,-1,1);
				ret->code = DIAOYONG;
				ret->word_meaning = "#";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
			}
			else
			{
				fseek(file,-1,1);
			}

		}

		// * ≥À∫≈ 30
		else if(ch == '*')
		{
			ch = fgetc(file);
			if(ch == '=')
			{
				ret->code = MULTIX;
				ret->word_meaning = "*=";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
			}
			else
			{
				fseek(file,-1,1);
				ret->code = MULTI;
				ret->word_meaning = "*";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//return *  «≥À∫≈ 
			}
		}
		
		//  >= or > 34+35
		else if (ch =='>')
		{
			ch = fgetc(file);
			if(ch == '=')
			{
				ret->code = EBIG;
				ret->word_meaning = ">=";
				char str[100];
				//printf("1");
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//ch = fgetc(file);
				//return ret;
				//return >=
			}
			else
			{
				ret->code = BIG;
				ret->word_meaning = ">";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				//printf("%s",str);
				//printf("2");
				file_write(str);
				//return >
				fseek(file,-1,1);
				//ch÷∏’ÎªÿÕÀ“ª≤Ω
				//return ret;
			}	
		}

		// < or <= 32+33
		else if (ch =='<')
		{
			ch = fgetc(file);
			if(ch == '=')
			{
				ret->code = ESMALL;
				ret->word_meaning = "<=";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//return <=
			}
			else
			{
				ret->code = SMALL;
				ret->word_meaning = "<";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//return <
				fseek(file,-1,1);
				//ch÷∏’ÎªÿÕÀ“ª≤Ω
			}		
		}

		//∏≥÷µ ∫Õ ±»Ωœ 36+37
		else if (ch =='=')
		{
			printf("3");
			ch = fgetc(file);
			if(ch == '=')
			{
				ret->code = EQUAL;
				ret->word_meaning = "==";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//return <=
			}
			else
			{
				ret->code = EEQUAL;
				ret->word_meaning = "=";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//return <s
				//ch÷∏’ÎªÿÕÀ“ª≤Ω
				fseek(file,-1,1);
			}		
		}

		// + ∫Õ += ∫Õ ++ 24+25+26
		else if (ch =='+')
		{
			ch = fgetc(file);
			if(ch == '=')
			{
				ret->code = ADDX;
				ret->word_meaning = "+=";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//return +=
			}
			else if(ch == '+')
			{
				ret->code = ADDD;
				ret->word_meaning = "++";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//return ++
			}
			else
			{
				ret->code = ADD;
				ret->word_meaning = "+";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//return +
				//ch÷∏’ÎªÿÕÀ“ª≤Ω
				fseek(file,-1,1);
			}
		}

		// - ∫Õ -= ∫Õ --27+28+29
		else if (ch =='-')
		{
			ch = fgetc(file);
			if(ch == '=')
			{
				ret->code = SUBX;
				ret->word_meaning = "-=";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//return -=
			}
			else if(ch == '-')
			{
				ret->code = SUBB;
				ret->word_meaning = "--";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//return --
			}
			else
			{
				ret->code = SUB;
				ret->word_meaning = "-";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//return -
				//ch÷∏’ÎªÿÕÀ“ª≤Ω
				fseek(file,-1,1);
			}	
		}

		// £° or != 38+39
		else if (ch =='!')
		{
			ch = fgetc(file);
			if(ch == '=')
			{
				ret->code = NOTEQUAL;
				ret->word_meaning = "!=";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
				//ch = fgetc(file);
				//return ret;
				//return >=
			}
			else
			{
				ret->code = NOT;
				ret->word_meaning = "!";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				//printf("%s",str);
				file_write(str);
				//return >
				fseek(file,-1,1);
				//ch÷∏’ÎªÿÕÀ“ª≤Ω
				//return ret;
			}	
		}
		
		// &&40
		else if(ch == '&')
		{
			ch = fgetc(file);
			if(ch == '&')
			{
				ret->code = AND;
				ret->word_meaning = "&&";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
			}
			else
			{
				fseek(file,-1,1);
				ret->code = ADDRESS;
				ret->word_meaning = "&";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
			}
		}

		// || or 41
		else if(ch == '|')
		{
			ch = fgetc(file);
			if(ch == '|')
			{
				ret->code = OR;
				ret->word_meaning = "||";
				char str[100];
				sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
				file_write(str);
			}
			else
			{
				fseek(file,-1,1);
			}
		}

		// £øŒ ∫≈42
		else if(ch == '?')
		{			
			ret->code = WENHAO;
			ret->word_meaning = "?";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
			
		}

		// ;∑÷∫≈45
		else if(ch == ';')
		{
			ret->code = FENHAO;
			ret->word_meaning = ";";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
		}

		// :√∞∫≈44
		else if(ch == ':')
		{
			ret->code = MAOHAO;
			ret->word_meaning = ":";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
		}
		// ,∂∫∫≈43
		else if(ch == ',')
		{
			ret->code = MAOHAO;
			ret->word_meaning = ",";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
		}

		//#define L_S_KUOHAO 49 //(
		else if(ch == '(')
		{
			ret->code = L_S_KUOHAO;
			ret->word_meaning = "(";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
		}

		//#define R_S_KUOHAO 50 //)
		else if(ch == ')')
		{
			ret->code = R_S_KUOHAO;
			ret->word_meaning = ")";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
		}

		//#define L_B_KUOHAO 51 //{
		else if(ch == '{')
		{
			ret->code = L_B_KUOHAO;
			ret->word_meaning = "{";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
		}

		//#define R_B_KUOHAO 52 //}
		else if(ch == '}')
		{
			ret->code = R_B_KUOHAO;
			ret->word_meaning = "}";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
		}

		//#define L_M_KUOHAO 53 //[
		else if(ch == '[')
		{
			ret->code = L_M_KUOHAO;
			ret->word_meaning = "[";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
		}

		//#define R_M_KUOHAO 54 //]
		else if(ch == ']')
		{
			ret->code = L_M_KUOHAO;
			ret->word_meaning = "]";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
		}

		//#define D_YINHAO 55
		else if(ch == '"')
		{
			ret->code = D_YINHAO;
			ret->word_meaning = "\"";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
		}

		//#define D_YINHAO 55 //"
		//#define S_YINHAO 56 //'

		else if(ch == '\'')
		{
			ret->code = D_YINHAO;
			ret->word_meaning = "\'";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
		}
		
		#define PERCENT 64//%
		else if(ch == '%')
		{
			ret->code = PERCENT;
			ret->word_meaning = "%";
			char str[100];
			sprintf(str, "%d---%s\n", ret->code,ret->word_meaning);
			file_write(str);
		}


		//#define HONGDINGYI 57//#

		//end
		else if(ch == '$')
		{
			return ret;
		}
	}
	
}