/*
 * Electronic_voting_machine.c
 *
 * Created: 3/13/2023 11:23:52 PM
 *  Author: 20100
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LCD.h"
#include "push_button.h"

unsigned char  counter1 = 0;
unsigned char  counter2 = 0;
unsigned char  counter3 = 0;
unsigned char  counter4 = 0;


int main(void)
{
	LCD_vInt();				 //initialize LCD
	button_vInt('D',0);		//initialize buttons A,B,C,D,RESET
	button_vInt('D',1);
	button_vInt('D',2);
	button_vInt('D',3);
	button_vInt('D',4);
	
	LCD_vSend_cmd(DISPLAY_ON_CURSOR_OFF);	//to hide cursor
	
	LCD_vSend_String("A=0");		//printing voting names and number of votes 
	LCD_vMove_Cursor(1,13);			
	LCD_vSend_String("B=0");
	LCD_vMove_Cursor(2,1);
	LCD_vSend_String("C=0");
	LCD_vMove_Cursor(2,13);
	LCD_vSend_String("D=0");
    while(1)
    {	
		if(button_u8read('D',0) == 1)  //read the value of button A
		{
			if(counter1<9)				//to print if number of votes less than 10
			{
			counter1++;
			LCD_vMove_Cursor(1,3);
			LCD_vSend_char(counter1+48); //to send ASCI code to the LCD
			}
			else if(counter1<100)				//to print if number of votes less than 100
			{
				counter1++;
				LCD_vMove_Cursor(1,3);
				LCD_vSend_char(counter1/10+48);//to send ASCI code of tens place to the LCD
				LCD_vSend_char(counter1%10+48);//to send ASCI code of units place to the LCD
			}			
		}
	
	else if(button_u8read('D',1) == 1)  //read the value of button B
	{
		if(counter2<9)				//to print if number of votes less than 10
		{
			counter2++;
			LCD_vMove_Cursor(1,15);
			LCD_vSend_char(counter2+48); //to send ASCI code to the LCD
		}
		else if(counter2<100)				//to print if number of votes less than 100
		{
			counter2++;
			LCD_vMove_Cursor(1,15);
			LCD_vSend_char(counter2/10+48);//to send ASCI code of tens place to the LCD
			LCD_vSend_char(counter2%10+48);//to send ASCI code of units place to the LCD
		}
	}
	
	else if(button_u8read('D',2) == 1)  //read the value of button C
	{
		if(counter3<9)				//to print if number of votes less than 10
		{
			counter3++;
			LCD_vMove_Cursor(2,3);
			LCD_vSend_char(counter3+48); //to send ASCI code to the LCD
		}
		else if(counter3<100)				//to print if number of votes less than 100
		{
			counter3++;
			LCD_vMove_Cursor(2,3);
			LCD_vSend_char(counter3/10+48);//to send ASCI code of tens place to the LCD
			LCD_vSend_char(counter3%10+48);//to send ASCI code of units place to the LCD
		}
	}
		
	else if(button_u8read('D',3) == 1)  //read the value of button D
	{
		if(counter4<9)				//to print if number of votes less than 10
		{
			counter4++;
			LCD_vMove_Cursor(2,15);
			LCD_vSend_char(counter4+48); //to send ASCI code to the LCD
		}
		else if(counter4<100)				//to print if number of votes less than 100
		{
			counter4++;
			LCD_vMove_Cursor(2,15);
			LCD_vSend_char(counter4/10+48);//to send ASCI code of tens place to the LCD
			LCD_vSend_char(counter4%10+48);//to send ASCI code of units place to the LCD
		}
	}
	
	else if(button_u8read('D',4) == 1)
	{
		LCD_vSend_cmd(CLR_SCREEN);
		counter1=counter2=counter3=counter4=0; //to start count from beggining 
		LCD_vMove_Cursor(1,1);
		LCD_vSend_String("A=0");		//printing voting names and number of votes
		LCD_vMove_Cursor(1,13);
		LCD_vSend_String("B=0");
		LCD_vMove_Cursor(2,1);
		LCD_vSend_String("C=0");
		LCD_vMove_Cursor(2,13);
		LCD_vSend_String("D=0");	
	}
	_delay_ms(200);	
    }
}