//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=-8;
int y=-8;
int to_win=12;

bool collision (TImage*sphere, TImage*brick)
{
if (sphere->Left >= brick->Left - sphere->Width &&
    sphere->Left <= brick->Left + brick->Width &&
    sphere->Top >= brick->Top - sphere -> Height &&
    sphere->Top <= brick->Top + brick->Height )
    {
    return true;
    }
         else return false;

}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::T_ballTimer(TObject *Sender)
{
  ball->Left += x;
  ball->Top += y;

 //bounce off the left wall
  if (ball->Left-5 <= background->Left) x = -x;

  //bounce off the right wall
  if (ball->Left- + ball-> Width + 5 >= background->Width) x = -x;

  //bounce off the top wall
  if (ball->Top-5 <= background->Top) y = -y;

  //user failure
  if (ball->Top >= paddle->Top + paddle->Height +15)
  {
  T_ball -> Enabled = false;
  ball->Visible = false;
  Button->Caption="GAME OVER. Click to play again";
  Button->Visible=true;
  }
  else if
   (ball->Left > paddle->Left-ball ->Width/2 &&
   ball->Left < paddle->Left+paddle->Width &&
   ball->Top + ball->Height > paddle->Top)
   {
   if (y>0) y = -y;
   }

  if (to_win <=0)
  {
    T_ball ->Enabled = false;
    ball->Visible = false;
    Button->Caption="YOU WIN! Click to play again";
    Button->Visible=true;
  }

   //collision with  brick nr 1
   if (collision (Image1, ball) && Image1->Visible==true)
   {
   x=-x;
   y=-y;
   Image1->Visible = false;
   to_win--;
   }
   //collision with  brick nr 2
   if (collision (Image2, ball) && Image2->Visible==true)
   {
   x=-x;
   y=-y;
   Image2->Visible = false;
   to_win--;
   }
   //collision with  brick nr 3
   if (collision (Image3, ball) && Image3->Visible==true)
   {
   x=-x;
   y=-y;
   Image3->Visible = false;
   to_win--;
   }
   //collision with  brick nr 4
   if (collision (Image4, ball) && Image4->Visible==true)
   {
   x=-x;
   y=-y;
  Image4->Visible = false;
   to_win--;
   }
   //collision with  brick nr 5
   if (collision (Image5, ball) && Image5->Visible==true)
   {
   x=-x;
   y=-y;
   Image5->Visible = false;
   to_win--;
   }
   //collision with  brick nr 6
   if (collision (Image6, ball) && Image6->Visible==true)
   {
   x=-x;
   y=-y;
   Image6->Visible = false;
   to_win--;
   }
   //collision with  brick nr 7
   if (collision (Image7, ball) && Image7->Visible==true)
   {
   x=-x;
   y=-y;
   Image7->Visible = false;
   to_win--;
   }
   //collision with  brick nr 8
   if (collision (Image8, ball) && Image8->Visible==true)
   {
   x=-x;
   y=-y;
   Image8->Visible = false;
   to_win--;
   }
   //collision with  brick nr 9
   if (collision (Image9, ball) && Image9->Visible==true)
   {
   x=-x;
   y=-y;
   Image9->Visible = false;
   to_win--;
   }
   //collision with  brick nr 10
   if (collision (Image10, ball) && Image10->Visible==true)
   {
   x=-x;
   y=-y;
   Image10->Visible = false;
   to_win--;
   }
   //collision with  brick nr 11
   if (collision (Image11, ball) && Image11->Visible==true)
   {
   x=-x;
   y=-y;
   Image11->Visible = false;
   to_win--;
   }

   //collision with  brick nr 12
   if (collision (Image12, ball) && Image12->Visible==true)
   {
   x=-x;
   y=-y;
   Image12->Visible = false;
   to_win--;
   }


  }
//---------------------------------------------------------------------------
void __fastcall TForm1::left_pTimer(TObject *Sender)
{
if (paddle->Left>5) paddle->Left -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::right_pTimer(TObject *Sender)
{
if (paddle->Left + paddle->Width < background->Width -5) paddle->Left +=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_LEFT) left_p -> Enabled = true;
if (Key == VK_RIGHT) right_p -> Enabled = true;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key == VK_LEFT) left_p -> Enabled = false;
if (Key == VK_RIGHT) right_p -> Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ButtonClick(TObject *Sender)
{
    ball->Left=300;
    ball->Top==400;
    ball->Visible=true;
    x=-8; y=-8;
    T_ball->Enabled = true;
    Button->Visible=false;
    to_win=12;
    Image1->Visible=true;  Image2->Visible=true;  Image3->Visible=true;
    Image4->Visible=true;  Image5->Visible=true;  Image6->Visible=true;
    Image7->Visible=true;  Image8->Visible=true;  Image9->Visible=true;
    Image10->Visible=true; Image11->Visible=true; Image12->Visible=true;
}
//---------------------------------------------------------------------------
