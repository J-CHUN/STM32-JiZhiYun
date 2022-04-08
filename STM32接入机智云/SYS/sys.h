#ifndef __SYS_H
#define __SYS_H

#include "stm32f10x.h"


/*����0x4001 080C�ĵ�8λ�����Կ���LED����,PA8ODR�Ĵ����ĵ�8λ*/
/*BITBAND(addr, bitnum) ����һ��λ������ַ���ܵõ���Ӧ�ı�����ַ��
 MEM_ADDR(addr)  *((volatile unsigned long *) (addr))  �ѱ�������ַת���ɵ�Ƭ����ʶ��ĵ�ַ
  MEM_ADDR (BITBAND(addr, bitnum)) ����һ��λ�������ܵõ���Ӧ�ĵ�Ƭ����ʶ��ı�����ַ 
  BIT_ADDR(addr,bitnum) addr:λ�������ֽڵ�ַ��bitnumλ������λ��
  */
  
#define BITBAND(addr, bitnum)       ((addr & 0xF0000000)+0x02000000+((addr &0x00FFFFFF)<<5)+(bitnum<<2))
#define MEM_ADDR(addr)               *((volatile unsigned long *) (addr))
#define BIT_ADDR(addr,bitnum)        MEM_ADDR (BITBAND(addr, bitnum)) 
	
//I0�ڵ�ַӳ��
#define GPIOA_ODR_Addr     (GPIOA_BASE+12)   //0x4001080C
#define GPIOB_ODR_Addr     (GPIOB_BASE+12)   //0x40010C0C
#define GPIOC_ODR_Addr     (GPIOC_BASE+12)   //0x4001100C
#define GPIOD_ODR_Addr     (GPIOD_BASE+12)   //0x4001140C
#define GPIOE_ODR_Addr     (GPIOE_BASE+12)  //0x4001180C
#define GPIOF_ODR_Addr     (GPIOF_BASE+12)  //0x40011A0C
#define GPIOG_ODR_Addr     (GPI0G_BASE+12)  //0x40011E0C

#define GPIOA_IDR_Addr     (GPIOA_BASE+8)   //0x40010808
#define GPIOB_IDR_Addr     (GPIOB_BASE+8)   //0x40010C08
#define GPIOC_IDR_Addr     (GPIOC_BASE+8)   //0x40011008
#define GPIOD_IDR_Addr     (GPIOD_BASE+8)    //0x40011408
#define GPIOE_IDR_Addr     (GPIOE_BASE+8)   //0x40011808
#define GPIOF_IDR_Addr     (GPIOF_BASE+8)    //0x40011A08
#define GPIOG_IDR_Addr     (GPIOG_BASE+8)   //0x40011E08


//I0�ڲ���,ֻ�Ե�һ��I0��!
#define PAout(n)  BIT_ADDR (GPIOA_ODR_Addr,n)  //���
#define PAin(n)   BIT_ADDR (GPIOA_IDR_Addr,n)  //����

#define PBout(n)  BIT_ADDR (GPIOB_ODR_Addr,n)  //���
#define PBin(n)   BIT_ADDR (GPIOB_IDR_Addr,n)  //����

#define PCout(n)  BIT_ADDR (GPIOC_ODR_Addr,n)  //���
#define PCin(n)   BIT_ADDR (GPIOC_IDR_Addr,n)  //����

#define PDout(n)  BIT_ADDR (GPIOD_ODR_Addr,n)  //���
#define PDin(n)   BIT_ADDR (GPIOD_IDR_Addr,n)  //����

#define PEout(n)  BIT_ADDR (GPIOE_ODR_Addr,n)  //���
#define PEin(n)   BIT_ADDR (GPIOE_IDR_Addr,n)  //����

#define PFout(n)  BIT_ADDR (GPIOF_ODR_Addr,n)  //���
#define PFin(n)   BIT_ADDR (GPIOF_IDR_Addr,n)  //����

#define PGout(n)  BIT_ADDR (GPIOG_ODR_Addr,n)  //���
#define PGin(n)   BIT_ADDR (GPIOG_IDR_Addr,n)  //����

#endif




