/******************************************************************************
*  Writing characters using a LCD based on the Hitachi HD44780 controller
*
* Filename:		main.c
* Author:		Kreoware
* Revision:		1.0
* Last Updated: 
*
* Description:	Main File for the DEMOJM Board (Freescale MC9S08JM60)
* Notes: 
*
* See my_lcd.c for more info on LCD setup (created by freescale)...
*  4-bit LCD display connected to:
*  E   - PTA0
*  RS  - PTA1
*  DB4 - PTA2
*  DB5 - PTA3
*  DB6 - PTA4
*  DB7 - PTA5		
*******************************************************************************/
#include <hidef.h> /* for EnableInterrupts macro */
#include "derivative.h" /* include peripheral declarations */
#include "hcs08.h"	  	// this is our definition file
//LCD
#define BUS_CLOCK 8000
#include "my_lcd.c"

void main(void){
  SOPT1 = bBKGDPE;		// configure SOPT1 register, enable pin BKGD for BDM
  MCGSC = NVFTRIM;		// configure FTRIM value
  MCGTRM = NVMCGTRM;		// configure TRIM value
  MCGC2 = 0;			// ICSOUT = DCOOUT / 1
  LCD_init(DISPLAY_8X5|_2_LINES,DISPLAY_ON|CURSOR_OFF|CURSOR_NOBLINK);  
  LCD_pos_xy(0,0);          // set cursor to the first column of the first line
  LCD_write_string("Kreoware!"); // write on the display
  LCD_pos_xy(1,0);          // set cursor to the first column of the second line
  LCD_write_string("OpenSource!"); // write on the display 
}
