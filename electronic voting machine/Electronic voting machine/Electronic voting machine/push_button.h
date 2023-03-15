/*
 * push_button.h
 *
 * Created: 2/8/2023 6:26:06 PM
 *  Author: 20100
 */ 

#include "DIO.h"
#ifndef PUSH_BUTTON_H_
#define PUSH_BUTTON_H_
void button_vInt(unsigned char portname,unsigned char pinnumber);

unsigned char  button_u8read(unsigned char portname,unsigned char pinnumber);


#endif /* PUSH_BUTTON_H_ */