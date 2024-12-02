/*
 * Math.h
 *
 * Created: 9/10/2024 2:05:15 PM
 *  Author: momen
 */ 


#ifndef MATH_H_
#define MATH_H_

#define SetBit(Reg,Bit)   Reg= (Reg | (1<<Bit))
 
#define ClrBit(Reg,Bit)   Reg= (Reg & (~(1<<Bit)))
 
#define ToggleBit(Reg,Bit)   Reg= (Reg ^ (1<<Bit))

#define GetBit(Reg,Bit)    (1 & (Reg>>Bit))



#endif /* MATH_H_ */