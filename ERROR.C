
/********************************* ERRORS **********************************/

void ERROR(int code)
  {
	 textcolor(4+128);
	 cprintf("\nERROR : ");
	 textcolor(9);
	 switch(code)
	 {
		case 0 : cprintf("INVALID OPERATION");break;
		case 1 : cprintf("MISSING CHARACTER '*' AFTER 'SELECT'");break;
		case 2 : cprintf("MISSING WORD 'FROM'");break;
		case 3 : cprintf("MISSING SEMICOLON ';'");break;
		case 4 : cprintf("MISSING TABLE NAME");break;
		case 5 : cprintf("CHARACTER NOT ALLOWED AFTER SEMICOLON ';'");break;
		case 6 : cprintf("TABLE DOES NOT EXISTS");break;
		case 7 : cprintf("MISSING WORD 'WHERE'");break;
		case 8 : cprintf("MISSING CONDITION");break;
		case 9 : cprintf("MISSING WORD 'INTO'");break;
		case 10 : cprintf("MISSING WORD 'VALUES'");break;
		case 11 : cprintf("MISSING CHARACTER '('");break;
		case 12 : cprintf("PRIMARY KEY VIOLATION");break;
		case 13 : cprintf("MISSING QUOTES");break;
		case 14 : cprintf("SIZE VIOLATION");break;
		case 15 : cprintf("MISSING CHARACTER ')'");break;
		case 16 : cprintf("MISSING CHARACTER ','");break;
		case 17 : cprintf("MISSING WORD 'WHERE'");break;
		case 18 : cprintf("INVALID FIELD NAME");break;
		case 19 : cprintf("INVALID SIGN");break;
		case 20 : cprintf("MISSING WORD 'SET'");break;
		case 21 : cprintf("TRIGGER NAME ALREADY IN USE");break;
		case 22 : cprintf("MISSING WORD 'ON'");break;
		case 23 : cprintf("MISSING WORD 'EACH'");break;
		case 24 : cprintf("MISSING WORD 'ROW'");break;
		case 25 : cprintf("MISSING WORD 'BEGIN'");break;
		case 26 : cprintf("INVALID REFERENCE IN STATEMENT LEVEL TRIGGER");break;
		case 27 : cprintf("INVALID REFERENCE");break;
		case 28 : cprintf("INVALID TIME REFERENCE");break;
		case 29 : cprintf("INVALID CHARACTERS IN OPERAND");break;
		case 30 : cprintf("MISSING WORD 'THEN'");break;
		case 31 : cprintf("'ELSE' WITHOUT 'IF'");break;
		case 32 : cprintf("MISSING 'END IF'");break;
		case 33 : cprintf("MISSING WORD 'OF'");break;
		case 34 : cprintf("SYNTAX ERROR");break;
		case 35 : cprintf("INVALID USE OF VARIABLES");break;
		case 36 : cprintf("INVALID TABLE NAME");break;
		case 37 : cprintf("MISSING TERM AFTER ','");break;
		case 38 : cprintf("INVALID EXPRESSION");break;
		case 39 : cprintf("INVALID REDECLARATION OF VARIABLE");break;
		case 40 : cprintf("TABLE NAME ALREADY EXISTS");break;
		case 41 : cprintf("TRIGGER DOES NOT EXISTS");break;
	 }
//		sound(440);
		getch();
		nosound();
		textcolor(7);
		MENU();
  }