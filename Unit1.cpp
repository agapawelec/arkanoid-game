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
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
    b->Left += x;
    b->Top += y;
    if(b->Left-5 <=tlo->Left) x= -x;
    if(b->Top-5 <=tlo->Top) y= -y;
    if(b->Left+b->Width+5 >=tlo->Width) x= -x;

    if (b->Top >=pad->Top+pad ->Height+15)
    {
     Timer_pilka->Enabled = false;
     b->Visible = false;
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm1::lewoTimer(TObject *Sender)
{
   if(pad->Left>10)
   {
   pad->Left -=10;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::prawoTimer(TObject *Sender)
{
if (pad ->Left+pad->Width < tlo->Width -10)
 {
  pad->Left +=10;
  }
}
//-------------------------------------------------------- -------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key ==VK_LEFT) lewo -> Enabled = true;
   if (Key ==VK_RIGHT) prawo -> Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if (Key ==VK_LEFT) lewo -> Enabled = false;
   if (Key ==VK_RIGHT) prawo -> Enabled = false;
}
//---------------------------------------------------------------------------

