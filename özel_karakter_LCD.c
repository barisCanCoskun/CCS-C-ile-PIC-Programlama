
//			�zel_karakter_LCD.c
//Bu LCD s�rucu dosyasi 2x16 HD44780 uyumlu LCD'ler 
//icin yazilmistir. LCD' ye sadece yazma yapilacagi icin 
//R/W ucu saseye baglanmalidir. LCD baglantisi asagidadir.
//Bu LCD dosyas� ile �zel karakterler de LCD' de g�sterilebilir.

//RB0 -> LCD' nin D4 ucuna
//RB1 -> LCD' nin D5 ucuna
//RB2 -> LCD' nin D6 ucuna
//RB3 -> LCD' nin D7 ucuna
//RB4 -> LCD' nin RS ucuna
//RB5 -> LCD' nin E ucuna
//R/W ucu direkt saseye baglanacak

#define e pin_b5
#define rs pin_b4

void lcd_komut(byte komut)
{
	output_b(komut >> 4);
	output_low(rs);
	delay_cycles(1);
	output_high(e);
	delay_cycles(1);
	output_low(e);
	delay_ms(2);
	
	output_b(komut & 0x0F);
	output_low(rs);
	delay_cycles(1);
	output_high(e);
	delay_cycles(1);
	output_low(e);
	delay_ms(2);
}

void lcd_veri(byte veri)
{
	if(veri == '�')	veri = 0;
	if(veri == '�')	veri = 1;
	if(veri == '�')	veri = 2;
	if(veri == '�')	veri = 3;
	if(veri == '�')	veri = 4;
	if(veri == '�')	veri = 5;
	if(veri == 'I')	veri = 6;
	if(veri == '^')	veri = 7;
	
	
	output_b(veri >> 4);
	output_high(rs);
	delay_cycles(1);
	output_high(e);
	delay_cycles(1);
	output_low(e);
	delay_ms(2);
	
	output_b(veri & 0x0F);
	output_high(rs);
	delay_cycles(1);
	output_high(e);
	delay_cycles(1);
	output_low(e);
	delay_ms(2);
}

void imlec(byte satir, byte sutun)
{
	if(satir == 1)
		lcd_komut(0x80 | (sutun - 1));
	
	if(satir == 2)
		lcd_komut(0x80 | (0x40 + (sutun - 1)));
}

void lcd_hazirla()
{
	int i;
	output_low(rs);
	output_low(e);
	delay_ms(30);
	
	for(i = 1; i <= 3; i++){
		lcd_komut(0x03);
		delay_ms(5);
	}
	
	lcd_komut(0x20);
	delay_ms(1000);
	lcd_komut(0x28);
	delay_ms(1000);
	lcd_komut(0x08);
	delay_ms(1000);
	lcd_komut(0x0C);
	delay_ms(1000);
	lcd_komut(0x06);
	delay_ms(1000);
	lcd_komut(0x01);
	
}

void ozel_karakterler()
{
	//CGRAM' de 0. Adrese "�" Karakteri Kaydediliyor:
	lcd_komut(0x40);	lcd_veri(14);
	lcd_komut(0x41);	lcd_veri(17);
	lcd_komut(0x42);	lcd_veri(16);
	lcd_komut(0x43);	lcd_veri(16);
	lcd_komut(0x44);	lcd_veri(16);
	lcd_komut(0x45);	lcd_veri(21);
	lcd_komut(0x46);	lcd_veri(14);
	lcd_komut(0x47);	lcd_veri(0);
	
	//CGRAM' de 1. Adrese "�" Karakteri Kaydediliyor:
	lcd_komut(0x48);	lcd_veri(14);
	lcd_komut(0x49);	lcd_veri(0);
	lcd_komut(0x4A);	lcd_veri(15);
	lcd_komut(0x4B);	lcd_veri(16);
	lcd_komut(0x4C);	lcd_veri(19);
	lcd_komut(0x4D);	lcd_veri(17);
	lcd_komut(0x4E);	lcd_veri(15);
	lcd_komut(0x4F);	lcd_veri(0);
	
	//CGRAM' de 2. Adrese "�" Karakteri Kaydediliyor:
	lcd_komut(0x50);	lcd_veri(4);
	lcd_komut(0x51);	lcd_veri(0);
	lcd_komut(0x52);	lcd_veri(4);
	lcd_komut(0x53);	lcd_veri(4);
	lcd_komut(0x54);	lcd_veri(4);
	lcd_komut(0x55);	lcd_veri(4);
	lcd_komut(0x56);	lcd_veri(4);
	lcd_komut(0x57);	lcd_veri(0);
	
	//CGRAM' de 3. Adrese "�" Karakteri Kaydediliyor:
	lcd_komut(0x58);	lcd_veri(10);
	lcd_komut(0x59);	lcd_veri(0);
	lcd_komut(0x5A);	lcd_veri(14);
	lcd_komut(0x5B);	lcd_veri(17);
	lcd_komut(0x5C);	lcd_veri(17);
	lcd_komut(0x5D);	lcd_veri(17);
	lcd_komut(0x5E);	lcd_veri(14);
	lcd_komut(0x5F);	lcd_veri(0);
	
	//CGRAM' de 4. Adrese "�" Karakteri Kaydediliyor:
	lcd_komut(0x60);	lcd_veri(14);
	lcd_komut(0x61);	lcd_veri(17);
	lcd_komut(0x62);	lcd_veri(16);
	lcd_komut(0x63);	lcd_veri(14);
	lcd_komut(0x64);	lcd_veri(1);
	lcd_komut(0x65);	lcd_veri(21);
	lcd_komut(0x66);	lcd_veri(14);
	lcd_komut(0x67);	lcd_veri(0);
	
	//CGRAM' de 5. Adrese "�" Karakteri Kaydediliyor:
	lcd_komut(0x68);	lcd_veri(10);
	lcd_komut(0x69);	lcd_veri(0);
	lcd_komut(0x6A);	lcd_veri(17);
	lcd_komut(0x6B);	lcd_veri(17);
	lcd_komut(0x6C);	lcd_veri(17);
	lcd_komut(0x6D);	lcd_veri(17);
	lcd_komut(0x6E);	lcd_veri(14);
	lcd_komut(0x6F);	lcd_veri(0);
	
	//CGRAM' de 6. Adrese "I" Karakteri Kaydediliyor:
	lcd_komut(0x70);	lcd_veri(4);
	lcd_komut(0x71);	lcd_veri(4);
	lcd_komut(0x72);	lcd_veri(4);
	lcd_komut(0x73);	lcd_veri(4);
	lcd_komut(0x74);	lcd_veri(4);
	lcd_komut(0x75);	lcd_veri(4);
	lcd_komut(0x76);	lcd_veri(4);
	lcd_komut(0x77);	lcd_veri(0);
	
	//CGRAM' de 7. Adrese "^" Karakteri Kaydediliyor:
	lcd_komut(0x78);	lcd_veri(12);
	lcd_komut(0x79);	lcd_veri(18);
	lcd_komut(0x7A);	lcd_veri(18);
	lcd_komut(0x7B);	lcd_veri(12);
	lcd_komut(0x7C);	lcd_veri(0);
	lcd_komut(0x7D);	lcd_veri(0);
	lcd_komut(0x7E);	lcd_veri(0);
	lcd_komut(0x7F);	lcd_veri(0);
	
	
	
}








