// IMPORTANT: LCDWIKI_SPI LIBRARY MUST BE SPECIFICALLY
// CONFIGURED FOR EITHER THE TFT SHIELD OR THE BREAKOUT BOARD.

//This program is a demo of how to display scroll.

//when using the BREAKOUT BOARD only and using these hardware spi lines to the LCD,
//the SDA pin and SCK pin is defined by the system and can't be modified.
//if you don't need to control the LED pin,you can set it to 3.3V and set the pin definition to -1.
//other pins can be defined by youself,for example
//pin usage as follow:
//                 CS  A0/DC  RESET  SDA  SCK  LED    VCC     GND
//ESP8266 D1 nimi  D1   D3     D2    D7   D5   D4   5V/3.3V   GND

//Remember to set the pins to suit your display module!
/********************************************************************************
  @attention

  THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  TIME. AS A RESULT, QD electronic SHALL NOT BE HELD LIABLE FOR ANY
  DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
**********************************************************************************/
#include <LCDWIKI_GUI.h> //Core graphics library
#include <LCDWIKI_SPI.h> //Hardware-specific library
#include "font.h"
#include "cat.h"
#include "kitty.h"

//paramters define
#define MODEL SSD1283A
#define CS   D1
#define CD   D3
//#define SDA  A2   //if you use the hardware spi,this pin is no need to set
//#define SCK  A1   //if you use the hardware spi,this pin is no need to set
#define RST  D2
#define LED  D4   //if you don't need to control the LED pin,you should set it to -1 and set it to 3.3V

//the definiens of hardware spi mode as follow:
//if the IC model is known or the modules is unreadable,you can use this constructed function
LCDWIKI_SPI my_lcd(MODEL, CS, CD, RST, LED);

#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

char *color_name[] = { "BLUE", "GREEN", "RED", "WHITE" , "CYAN", "MAGENTA", "YELLOW"};
uint16_t color_mask[] = { 0x001F, 0x07E0, 0xF800, 0xFFFF, 0x07FF, 0xF81F, 0xFFE0 };
// covert images
// http://www.rinkydinkelectronics.com/_t_doimageconverter565.php

void show_pic(void)
{
  int i;
    my_lcd.Set_Addr_Window(0, 0, 129 , 129);
    my_lcd.Push_Any_Color((uint16_t*)kitty, 16900, 1, 1);
  //  my_lcd.Set_Addr_Window(0, 0, 9, 9);
  //  my_lcd.Push_Any_Color((uint8_t*)ran, 10000, 1, 1);
//  my_lcd.Draw_Bit_Map( 0, 0, 160, 160, cat, 1);
  //        my_lcd.Draw_Rectangle(20, 40, 80, 80);

}







void setup()
{
  Serial.begin(9600);
  my_lcd.Init_LCD();
  my_lcd.Fill_Screen(BLACK);
  show_pic();
}

void loop()
{

}
