
//			benim_LCD.c
//Bu LCD surucu dosyasi 2x16 HD44780 uyumlu LCD'ler 
//icin yazilmistir. LCD' ye sadece yazma yapilacagi icin 
//R/W ucu saseye baglanmalidir. LCD baglantisi asagidadir.

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








