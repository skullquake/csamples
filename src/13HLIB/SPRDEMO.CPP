/*
Sprdemo.cpp : Demo of Sprite capabilities in Mode13hLib.
*/

//Includes
#include "13hlib.h"
#include <stdio.h>
#include <dos.h>
#include <stdlib.h>

//Defines
#define WIDTH 48
#define HEIGHT 48

//Function declarations
void GrabSprites();
void MoonWalk();
void KillSprites();
void CloseDown(char *message);

//Globals
Mode13hLib Mode13h;
Sprite Spaceman[4];

void main()
{
 if(Mode13h.DetectVGA() == FAILURE) CloseDown("You need a VGA card to run this program.");
 Mode13h.SetMode13h();
 if(Mode13h.SetUpPage() == FAILURE) CloseDown("Not enough memory to allocate virtual screen page.");
 Mode13h.ClearScreen(0);
 //Mode13h.LoadPCXFile("spaceman.pcx");
 GrabSprites();
 MoonWalk();
 KillSprites();
 Mode13h.ClosePage();
 Mode13h.CloseMode13h();
}

void GrabSprites()
{
 Mode13h.LoadPalette("space.pal");
 Spaceman[1] = Mode13h.ReadSpriteFromDisk("space1.m13");
 Spaceman[2] = Mode13h.ReadSpriteFromDisk("space2.m13");
 Spaceman[3] = Mode13h.ReadSpriteFromDisk("space3.m13");

 //Error checking code.
 if((Spaceman[1] == NULL) || (Spaceman[2] == NULL) || (Spaceman[3] == NULL))
   CloseDown("Can't load Sprites.\nCheck for the files space1.m13, space2.m13 and space3.m13.\n");
 /*
 Spaceman[1] = Mode13h.GetSprite(192, 0, WIDTH, HEIGHT);
 Spaceman[2] = Mode13h.GetSprite(240, 0, WIDTH, HEIGHT);
 Spaceman[3] = Mode13h.GetSprite(0, 48, WIDTH, HEIGHT);

 Mode13h.WriteSpriteToDisk("space1.m13", WIDTH, HEIGHT, Spaceman[1]);
 Mode13h.WriteSpriteToDisk("space2.m13", WIDTH, HEIGHT, Spaceman[2]);
 Mode13h.WriteSpriteToDisk("space3.m13", WIDTH, HEIGHT, Spaceman[3]);
 */
}

void KillSprites()
{
 KillSprite(Spaceman[1]);
 KillSprite(Spaceman[2]);
 KillSprite(Spaceman[3]);
}

void MoonWalk()
{
 Sprite BackSpr;
 int currtextx = 15;
 int currmod = 1;
 int spacex = 250, spacey = 150;
 int curr_sprite = 2;
 int timedel;
 int currsprdelay = 2;       //Current Sprite delay value.
 struct time time1;
 struct time time2;     //Used for video card profiling
 randomize();
 gettime(&time1);
 for(int j = 0; j<=175; j++)  Mode13h.PlotPixel(random(320), random(200), 239);

 //Start title bar
 Mode13h.Bar(1, 1, 318, 20, 7);
 Mode13h.Rectangle(1, 1, 318, 20, 15);
 Mode13h.HorizontalLine(1, 21, 318, 8);
 Mode13h.VerticalLine(319, 2, 19, 8);
 Mode13h.BltText("-- Sprdemo by Pri$m --", 16, 8, 16);
 Mode13h.BltText("-- Sprdemo by Pri$m --", 15, 7, 31);
 Mode13h.PlotPixel(319, 1, 7);
 Mode13h.PlotPixel(1, 21, 7);
 BackSpr = Mode13h.GetSprite(spacex, spacey, WIDTH, HEIGHT);
 Mode13h.DrawSprite(spacex, spacey, WIDTH, HEIGHT, Spaceman[1]);
 gettime(&time2);

 //Profiling calcs
 if(time1.ti_hund > time2.ti_hund) timedel = 10 * (100 - time1.ti_hund + time2.ti_hund);
  else timedel = 10 * (time1.ti_hund - time2.ti_hund);
 //That's why we had the 10x loop - we now have a fairly accurate
 //account of how fast it would do the loop in milliseconds.
 //We want around 30fps. So ... we minus this value from 33 millisecs. (1000 / 30 = 33)
 timedel = 33 - timedel;
 //Profiling complete! Now it will run at the same speed on all video cards.
 //Each time it calculates it's own delay.
 //This is useful for games - but then it should be stored in some sort of
 //configuration file, so that it's only done once.

 for(int k =0; k <=500; k++)
 {
  currtextx += currmod;
  if(currtextx == 143 || currtextx == 5)
   currmod = currmod * -1;
  else
   {
    Mode13h.Bar(currtextx-1, 6, 177, 14, 7);
    Mode13h.BltText("-- Sprdemo by Pri$m --", currtextx + 1, 8, 16);
    Mode13h.BltText("-- Sprdemo by Pri$m --", currtextx, 7, 31);
   }
 if(currsprdelay == 0)
 {
 Mode13h.DrawSpriteNoTrans(spacex, spacey, WIDTH, HEIGHT, BackSpr);
  if(spacex != 0) spacex -= 10;
   else{
    spacex = 270;
    spacey -= 20;
    }
  KillSprite(BackSpr);
  BackSpr = Mode13h.GetSprite(spacex, spacey, WIDTH, HEIGHT);
  Mode13h.DrawSprite(spacex, spacey, WIDTH, HEIGHT, Spaceman[curr_sprite]);
   if(curr_sprite == 1)
     curr_sprite = 3;
   else curr_sprite -= 1;
   currsprdelay = 2;
  }
   else currsprdelay -= 1;
   delay(timedel);
   Mode13h.WaitVerticalRetrace();
   Mode13h.CopyPageToScreen();
 }
}

void CloseDown(char *message)
{
 Mode13h.CloseMode13h();
 Mode13h.ClosePage();
 delete Spaceman[1];
 delete Spaceman[2];
 delete Spaceman[3];
 puts(message);
 abort();
}