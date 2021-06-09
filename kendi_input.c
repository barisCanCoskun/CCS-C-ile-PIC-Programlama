#include <ctype.h>

byte hex_oku1()
{
	char karakter;
	
	karakter = getch();
	
	putc(karakter);
	
	if(karakter <= '9')
		return (karakter - '0');
	else
		return (toupper(karakter) - 'A') + 10;
	
}

byte hex_oku2()
{
	int high, low;
	
	high = hex_oku1();
	low = hex_oku1();
	
	return (high * 16 + low);
}




