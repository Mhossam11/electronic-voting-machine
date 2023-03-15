/*
 * button.c
 *
 * Created: 2/8/2023 6:25:51 PM
 *  Author: 20100
 */ 
void button_vInt(unsigned char portname,unsigned char pinnumber)
{
	DIO_vsetPINDir(portname,pinnumber,0);
}
unsigned char  button_u8read(unsigned char portname,unsigned char pinnumber)
{
	unsigned char x;
	x= DIO_u8read(portname,pinnumber);
	return x;
}