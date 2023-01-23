//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "game.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int x=-8;
int y=-8;
int to_win = 14;



bool collision (TImage * ball, TImage * brick)
{
   if (ball-> Left >= brick->Left-ball->Width  &&
       ball->Left <= brick-> Left+brick -> Width &&
       ball -> Top >= brick -> Top - ball -> Height &&
       ball -> Top <= brick -> Top+brick->Height)
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
void __fastcall TForm1::Timer_ballTimer(TObject *Sender)
{
    //ball track

    ball -> Left += x;
    ball -> Top += y;

    //ball bounce off the left wall

    if (ball ->Left-5 <=background->Left) x= -x;

    //ball bounce off the top wall

    if (ball ->Top-5 <=background->Top) y= -y;

    //ball bounce off the right wall

    if (ball ->Left-5 + ball -> Width + 5 >=background->Width) x= -x;

    //user fail

    if (ball ->Top >= paddle -> Top +paddle -> Height +15)
    {
    Timer_ball -> Enabled = false;
    ball -> Visible = false;
    Button1->Caption="Failure! Play again?";
    Button1->Visible=true;
    }
    else if (ball->Left > paddle->Left-ball->Width/2 &&
    ball->Left < paddle->Left+paddle->Width &&
    ball ->Top+ball->Height>paddle->Top)
    {
      if (y>0) y =-y;
    }
    if (to_win <=0)
    {
      Timer_ball->Enabled = false;
      ball->Visible=false;
       Button1->Caption="Win! Play again?";
      Button1->Visible=true;
    }
    // ball collision with brick
 if (collision (Image1, ball) && Image1->Visible ==true)
    {
    x=-x; y=-y;
    Image1->Visible = false;
    to_win--;
    }

     if (collision (Image2, ball) && Image2->Visible ==true)
    {
    x=-x; y=-y;
    Image2->Visible = false;
    to_win--;
    }
     if (collision (Image3, ball) && Image3->Visible ==true)
    {
    x=-x; y=-y;
    Image3->Visible = false;
    to_win--;
    }
     if (collision (Image4, ball) && Image4->Visible ==true)
    {
    x=-x; y=-y;
    Image4->Visible = false;
    to_win--;
    }
     if (collision (Image5, ball) && Image5->Visible ==true)
    {
    x=-x; y=-y;
    Image5->Visible = false;
    to_win--;
    }
     if (collision (Image6, ball) && Image6->Visible ==true)
    {
    x=-x; y=-y;
    Image6->Visible = false;
    to_win--;
    }
     if (collision (Image7, ball) && Image7->Visible ==true)
    {
    x=-x; y=-y;
    Image7->Visible = false;
    to_win--;
    }
     if (collision (Image8, ball) && Image8->Visible ==true)
    {
    x=-x; y=-y;
    Image8->Visible = false;
    to_win--;
    }
     if (collision (Image9, ball) && Image9->Visible ==true)
    {
    x=-x; y=-y;
    Image9->Visible = false;
    to_win--;
    }
     if (collision (Image10, ball) && Image10->Visible ==true)
    {
    x=-x; y=-y;
    Image10->Visible = false;
    to_win--;
    }
     if (collision (Image11, ball) && Image11->Visible ==true)
    {
    x=-x; y=-y;
    Image11->Visible = false;
    to_win--;
    }
    if (collision (Image12, ball) && Image12->Visible ==true)
    {
    x=-x; y=-y;
    Image12->Visible = false;
    to_win--;
    }

    if (collision (Image13, ball) && Image13->Visible ==true)
    {
    x=-x; y=-y;
    Image13->Visible = false;
    to_win--;
    }

    if (collision (Image14, ball) && Image14->Visible ==true)
    {
    x=-x; y=-y;
    Image14->Visible = false;
    to_win--;
    }


}

//---------------------------------------------------------------------------
void __fastcall TForm1::P_leftTimer(TObject *Sender)
{
   if (paddle->Left >4) paddle->Left -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::P_rightTimer(TObject *Sender)
{
   if (paddle->Left + paddle-> Width <background->Width -4) paddle->Left +=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
      //paddle control
{
      if (Key == VK_LEFT ) P_left-> Enabled = true;
      if (Key==VK_RIGHT) P_right -> Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
      if (Key == VK_LEFT ) P_left ->Enabled = false;
      if (Key==VK_RIGHT) P_right ->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
     ball-> Left = 100;
     ball->Top=100;
     ball->Visible=true;
     x=-8; y=-8;
     Timer_ball->Enabled = true;
     Button1->Visible = false;
     to_win=14;
     Image1->Visible=true; Image6->Visible=true; Image11->Visible=true;
     Image2->Visible=true; Image7->Visible=true; Image12->Visible=true;
     Image3->Visible=true; Image8->Visible=true; Image13->Visible=true;
     Image4->Visible=true; Image9->Visible=true; Image14->Visible=true;
     Image5->Visible=true; Image10->Visible=true;
     }
//---------------------------------------------------------------------------
