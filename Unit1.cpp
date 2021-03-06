//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPoints *Points;

          int ImmgW, ImmgH;

          int Linia, Ln1=0, Ln2=0, Ln3=0,   A1A, A2A, A3A;

          int LL1_1, PP1_1, LL1_2, PP1_2, AA1, w1 ;

          int xxx1,  yyy1,   xxx2, yyy2;
          int x2xx1, y2yy1,  x2xx2, y2yy2;
          int x3xx1, y3yy1,  x3xx2, y3yy2;

          int xr1, xr2, yr1, yr2, zz;
          int rA, rB, rC, rD,   rE, rF;

          int xrrr1, yrrr1,  xrrr2, yrrr2;
          int xrrr2x, yrrr2x;

          int XX1, YY1, AAA;

//---------------------------------------------------------------------------
__fastcall TPoints::TPoints(TComponent* Owner)
        : TForm(Owner)
{
      DoubleBuffered = true;      // --
}
//---------------------------------------------------------------------------

void __fastcall TPoints::FormCreate(TObject *Sender)
{
       DoubleBuffered = true;     // --

   Points->Width = 402 ;
   Points->Height = 505 ;

  ComboBox1->Items->Add("1");
  ComboBox1->Items->Add("2");
  ComboBox1->Items->Add("3");

    Panel7->Height = 3;
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Button1Click(TObject *Sender)
{
       Canvas->Pen->Color = clMoneyGreen;
       Canvas->Pen->Width = 6;
       Canvas->Brush->Color = clMoneyGreen;
       Canvas->Rectangle(0, 0, ClientWidth, ClientHeight);


                      // -- line 1
          Canvas->Pen->Color = clWhite;

             xxx1 = 10;  yyy1 = 50;
             xxx2 = 10;  yyy2 = 50;
          PP1_1 = xxx1;   PP1_2 = xxx2;
          LL1_1 = yyy1;   LL1_2 = yyy2;
                     A1A = 1;
          Canvas->MoveTo(PP1_1, LL1_1);
          Canvas->LineTo(PP1_2, LL1_2);


                   // -- line 2
          Canvas->Pen->Color = clBlue;

             x2xx1 = 250;  y2yy1 =  10;
             x2xx2 = 250;  y2yy2 =  10;
            PP1_1 = x2xx1;   PP1_2 = x2xx2;
            LL1_1 = y2yy1;   LL1_2 = y2yy2;
                       A2A = 1;
          Canvas->MoveTo(PP1_1, LL1_1);
          Canvas->LineTo(PP1_2, LL1_2);


                   // -- line 3
          Canvas->Pen->Color = clRed;

            x3xx1 = 151;  y3yy1 =  11;
            x3xx2 = 151;  y3yy2 =  11;
          PP1_1 = x3xx1;   PP1_2 = x3xx2;
          LL1_1 = y3yy1;   LL1_2 = y3yy2;
                      A3A = 1;
          Canvas->MoveTo(PP1_1, LL1_1);
          Canvas->LineTo(PP1_2, LL1_2);


            Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TPoints::Timer1Timer(TObject *Sender)
{
       ImmgW = ClientWidth - 5;
       ImmgH = ClientHeight - 5;

       int Height;

   Height = (ClientHeight + 255) / 250 ;

   for(int Row = 0; Row <= 250 ; Row++)
   {
      Canvas->Brush->Color =(TColor) RGB(0, 255-Row, 0 );
      Canvas->FillRect(Rect(0, Row * Height, ClientWidth, (Row + 1) * Height)) ;
   }


             // --  line 1  ------
                  Linia = 1;
                  AA1 = A1A ;      w1 = 4;
         PP1_1 = xxx1;    PP1_2 = xxx2;
         LL1_1 = yyy1;    LL1_2 = yyy2;

         Canvas->Pen->Color = clWhite;
                Button3->Click();
                  A1A =  AA1;
        xxx1 =  PP1_1  ;   xxx2 = PP1_2  ;
        yyy1 =  LL1_1  ;   yyy2 = LL1_2  ;


             // --  line 2  -----
                   Linia = 2;
                  AA1 = A2A ;       w1 = 4;
         PP1_1 = x2xx1;   PP1_2 = x2xx2;
         LL1_1 = y2yy1;   LL1_2 = y2yy2;
         Canvas->Pen->Color = clBlue;
                Button3->Click();
                   A2A =  AA1;
        x2xx1 =  PP1_1  ;   x2xx2 = PP1_2  ;
        y2yy1 =  LL1_1  ;   y2yy2 = LL1_2  ;


             // --  line 3  -----
                   Linia = 3;
                  AA1 = A3A ;       w1 = 4;
         PP1_1 = x3xx1;   PP1_2 = x3xx2;
         LL1_1 = y3yy1;   LL1_2 = y3yy2;
         Canvas->Pen->Color = clRed;
                Button3->Click();
                    A3A =  AA1;
        x3xx1 =  PP1_1  ;   x3xx2 = PP1_2  ;
        y3yy1 =  LL1_1  ;   y3yy2 = LL1_2  ;

}
//---------------------------------------------------------------------------

void __fastcall TPoints::Button2Click(TObject *Sender)
{
     rE = 0;  rF = 0;     rA = 0;  rB = 0;  rC = 0;  rD = 0;

     if(PP1_1 <= xr1)   rE = 1;
     if(PP1_1 >= xr2)   rE = 2;
     if(LL1_1 <= yr1)   rF = 1;
     if(LL1_1 >= yr2)   rF = 2;

     if(PP1_2 >= xr1)  {  rA = 1;     }
     if(LL1_2 >= yr1)  {  rB = 1;     }
     if(PP1_2 <= xr2)  {  rC = 1;     }
     if(LL1_2 <= yr2)  {  rD = 1;     }

  if ((rA + rB + rC + rD) == 4 )  if (rE == 1)  if ( AA1 == 1 )   AA1 = 2;   //
  if ((rA + rB + rC + rD) == 4 )  if (rE == 1)  if ( AA1 == 4 )   AA1 = 3;   //
  if ((rA + rB + rC + rD) == 4 )  if (rE == 2)  if ( AA1 == 2 )   AA1 = 1;   //
  if ((rA + rB + rC + rD) == 4 )  if (rE == 2)  if ( AA1 == 3 )   AA1 = 4;   //

  if ((rA + rB + rC + rD) == 4 )  if (rF == 1)  if ( AA1 == 1 )   AA1 = 4;   //
  if ((rA + rB + rC + rD) == 4 )  if (rF == 1)  if ( AA1 == 2 )   AA1 = 3;   //
  if ((rA + rB + rC + rD) == 4 )  if (rF == 2)  if ( AA1 == 3 )   AA1 = 2;   //
  if ((rA + rB + rC + rD) == 4 )  if (rF == 2)  if ( AA1 == 4 )   AA1 = 1;   //

}
//---------------------------------------------------------------------------
void __fastcall TPoints::Button3Click(TObject *Sender)
{

           Canvas->MoveTo(PP1_1, LL1_1);
           Canvas->LineTo(PP1_2, LL1_2);

         //  --- for 1 rec
     xrrr1 = Panel1->Left ;                      yrrr1 = Panel1->Top ;
     xrrr2 = Panel1->Width + Panel1->Left ;     yrrr2 = Panel1->Height + Panel1->Top ;

         // -- 1 rec --
  xr1= xrrr1;  yr1= yrrr1;  xr2= xrrr2;  yr2= yrrr2;
                Button2->Click();  //

         // -- 2 rec --
  xr1= Panel2->Left;  yr1= Panel2->Top;  xr2= Panel2->Width+Panel2->Left;  yr2= Panel2->Height+Panel2->Top;
                Button2->Click();  //

         // -- 3 rec --
   xr1= Panel3->Left;  yr1= Panel3->Top;  xr2= Panel3->Width+Panel3->Left;  yr2= Panel3->Height+Panel3->Top;
               Button2->Click();  //

         // -- 4 rec --
   xr1= Panel4->Left;  yr1= Panel4->Top;  xr2= Panel4->Width+Panel4->Left;  yr2= Panel4->Height+Panel4->Top;
                 Button2->Click();  //

   xr1= Panel5->Left; yr1= Panel5->Top; xr2= Panel5->Width + Panel5->Left;  yr2= Panel5->Height + Panel5->Top;
                 Button2->Click();  //

   xr1= Panel6->Left; yr1= Panel6->Top; xr2= Panel6->Width + Panel6->Left;  yr2= Panel6->Height + Panel6->Top;
                 Button2->Click();  //

  yr1= Panel7->Top;

                 Button4->Click();  //

                 PP1_1 = PP1_2;
                 LL1_1 = LL1_2;

                        // -- for frame

        if ( PP1_2 >= ImmgW )  if ( AA1 == 1 )   AA1 = 2;
        if ( PP1_2 >= ImmgW )  if ( AA1 == 4 )   AA1 = 3;
        if ( LL1_2 >= ImmgH )  if ( AA1 == 2 )   AA1 = 3;
        if ( LL1_2 >= ImmgH )  if ( AA1 == 1 )   AA1 = 4;

        if ( PP1_2 <= 0  ) if ( AA1 == 3 )   AA1 = 4;
        if ( PP1_2 <= 0  ) if ( AA1 == 2 )   AA1 = 1;
        if ( LL1_2 <= 31 ) if ( AA1 == 4 )   AA1 = 1;
        if ( LL1_2 <= 31 ) if ( AA1 == 3 )   AA1 = 2;

                         //  --  direct
  if ( AA1 == 1 ) {  PP1_2 = PP1_2 + w1;   LL1_2 = LL1_2 + w1;    }  //   down and right
  if ( AA1 == 2 ) {  PP1_2 = PP1_2 - w1;   LL1_2 = LL1_2 + w1;    }  //   down and left
  if ( AA1 == 3 ) {  PP1_2 = PP1_2 - w1;   LL1_2 = LL1_2 - w1;    }  //   up and left
  if ( AA1 == 4 ) {  PP1_2 = PP1_2 + w1;   LL1_2 = LL1_2 - w1;    }  //   up and right
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Button6Click(TObject *Sender)
{
       Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Button9Click(TObject *Sender)
{
     Timer1->Enabled = true;        
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Panel3MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
         ReleaseCapture();
         SendMessage(Panel3->Handle, WM_SYSCOMMAND, 0xF012, 0);
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Panel2MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
         ReleaseCapture();
         SendMessage(Panel2->Handle, WM_SYSCOMMAND, 0xF012, 0);    
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Panel4MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
         ReleaseCapture();
         SendMessage(Panel4->Handle, WM_SYSCOMMAND, 0xF012, 0);    
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
         ReleaseCapture();
         SendMessage(Panel1->Handle, WM_SYSCOMMAND, 0xF012, 0);
}
//---------------------------------------------------------------------------

void __fastcall TPoints::FormPaint(TObject *Sender)
{
    int Height;       // green background //

   Height = (ClientHeight + 255) / 250 ;

   for (int Row = 0; Row <= 250 ; Row++)
   {
      Canvas->Brush->Color =(TColor) RGB(0, 255-Row, 0 );

      Canvas->FillRect(Rect(0, Row * Height, ClientWidth, (Row + 1) * Height)) ;
   }   
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Button4Click(TObject *Sender)
{
      rE = 0;  rF = 0;     rA = 0;  rB = 0;  rC = 0;  rD = 0;

      if(LL1_2 >= yr1)  {  rB = 1;     }
      if(LL1_2 <= yr1)  {  rB = 2;     }

   if(rB == 1  )  if(Linia == 1)  if(Ln1 == 0)   {  Ln1 = 1;   }
   if(rB == 1  )  if(Linia == 2)  if(Ln2 == 0)   {  Ln2 = 1;   }
   if(rB == 1  )  if(Linia == 3)  if(Ln3 == 0)   {  Ln3 = 1;   }

   if(rB == 2  )  if(Linia == 1)  if(Ln1 == 1)   {  Ln1 = 0;   }
   if(rB == 2  )  if(Linia == 2)  if(Ln2 == 1)   {  Ln2 = 0;   }
   if(rB == 2  )  if(Linia == 3)  if(Ln3 == 1)   {  Ln3 = 0;   }  

         if ( Ln1 + Ln2 + Ln3 == 3 )
         {
             Panel8->Show();
             Timer1->Enabled = false;

             Ln1 = 0; Ln2 = 0; Ln3 = 0;
             rE = 0;  rF = 0;     rA = 0;  rB = 0;  rC = 0;  rD = 0;
         }
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Panel10Click(TObject *Sender)
{
     Button1->Click();

     Panel8->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Panel11Click(TObject *Sender)
{
     Button6->Click();
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Panel10MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    Panel10->Color =  clGreen;
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Panel10MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
   Panel10->Color = clAqua;
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Panel11MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
      Panel11->Color =  clYellow;
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Panel11MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
      Panel11->Color =  clRed; 
}
//---------------------------------------------------------------------------

void __fastcall TPoints::ComboBox1Change(TObject *Sender)
{
      String como1;
      como1 = ComboBox1->Items->Strings[ComboBox1->ItemIndex];

      if (como1 ==  "1" ) {  Panel5->Width = 160;  Panel6->Left = 230;  }
      if (como1 ==  "2" ) {  Panel5->Width = 188;  Panel6->Left = 198;  }
      if (como1 ==  "3" ) {  Panel5->Width = 196;  Panel6->Left = 195;  }
}
//---------------------------------------------------------------------------

void __fastcall TPoints::SpeedButton1Click(TObject *Sender)
{
  Panel83->Top = Points->ClientHeight/2 - (Points->Panel83->Height / 2 );
  Panel83->Left = Points->ClientWidth/2 - (Points->Panel83->Width / 2 );

      Panel83->Show();
      Panel83->BringToFront();
}
//---------------------------------------------------------------------------

void __fastcall TPoints::Panel84Click(TObject *Sender)
{
   Panel83->Hide();
   Panel83->BringToFront();
}
//---------------------------------------------------------------------------

