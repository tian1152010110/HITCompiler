#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>

//�ؼ���
#define BREAK 1
#define CONTINUE 2
#define CHAR 3
#define CASE 69
#define DEFINE 4
#define DO 67
#define ELSE 5
#define ELSEIF 6
#define FLOAT 7
#define FOR 8
#define INCLUDE 9
#define INT 10
#define IF 11
#define MAIN 12
#define PRINTF 13
#define RETURN 14
#define SCANF 66
#define STRING 15
#define STRUCT 16
#define SWITCH 70
#define THEN 17
#define VOID 18
#define WHILE 19


//��������
#define INTEGER_TYPE 20
#define CHAR_TYPE 21
#define FLOAT_TYPE 22
#define STRING_TYPE 23

//��������
#define ID 23

//�����
//���������
#define ADD 24 //+
#define ADDD 25 //++
#define ADDX 26 //+=
#define SUB  27//-
#define SUBB 28 // --
#define SUBX 29 // -=
#define MULTI 30 // *
#define MULTIX 59 // *=
#define DIV 31 // /

//��ϵ����
#define SMALL 32// <
#define ESMALL 33 // <=
#define BIG 34 // >
#define EBIG 35 // >=
#define EEQUAL 36 //=
#define EQUAL 37 // ==
#define NOT 38 //!
#define NOTEQUAL 39 // !=
//�߼������
#define ADDRESS 65//&
#define AND 40 // &&
#define OR 41 // ||
#define WENHAO 42 // ?  =

//�ֽ��
#define DOUHAO 43 //,
#define MAOHAO 44 //:
#define FENHAO 45 //;
#define LINE_ZHUSHI 46 // //
#define L_ZHUSHI 47 // /*
#define R_ZHUSHI 48 // */
#define L_S_KUOHAO 49 //(
#define R_S_KUOHAO 50 //)
#define L_B_KUOHAO 51 //{
#define R_B_KUOHAO 52 //}
#define L_M_KUOHAO 53 //[
#define R_M_KUOHAO 54 //]
#define PERCENT 64//%
#define D_YINHAO 55 //"
#define S_YINHAO 56 //'

#define HONGDINGYI 57//#define
#define DIAOYONG 58 //#include

//using namespace std

//#define L_JIANJIAO 60 //<
//���#���治�������֣�����
//���&���治��&������
//���|���治��|������
// /* */�Ƕ�Ӧ�ģ������費��Ҫ��Ӧ
//����֮��ǿո�
//�ڴʷ������������ֵĴ洢��int����string�������������һ��integer_type ��123
//�ֱ��ظ� ����Ҳ��char string��
//elseif Ӧ����if���Ӧ
// ����//�ļ�ĩ���ǻ��з�\n ���һ���ǡ� ��
//��Ǻ�С�ڵ�����
typedef struct WORD
{
	int code;
	//void *;
	char *word_meaning; 

}WORD;

WORD * wordScanner(FILE * file);
#endif
