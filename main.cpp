//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <���������>\n
//! @brief      <������������>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <�����>, <���> (<���> <�����>)
//! @date       <����>
//!
//! @par        ��������������
//!           - (TODO: ������ ��������)
//!
//! @todo     - (TODO: ������ ��������� ������ �� ����� �����)
//!
//! @bug      - (TODO: ������ ��������� ������ � ���� �����)
//!
//! @par        ������� ��������� �����
//!           - ������ 0.01 Alpha
//!             - ������ ��� ��������� ����
//!
//}=======================================================================

#include "TXLib.h"
#include <iostream>


int x=0;
int y=0;
int xr=100;
int yr=100;
int zx=0;
int buttonssquare=1;

HDC mark=txLoadImage ("dev.bmp"); //�����


class print //����� ��� ��������� �����
{
private:

 int x2, y2;



public:

  int draw=0;
  int x=0, y=0;         //������� ����� ����
  int xr=1, yr=1;       //������ ������ ����
  int cvet=TX_WHITE;    //�������� ���� ��������  txEllipse (100, 100, 300, 200);
  int cvetobv=TX_GRAY;  //���� ������� ��������
  int obv=7;            //������ ������� ��������
  int figure=3;         //����� ������ ����� ���������� 0-�������, 1-�����, 2-�������, 3-�����

string name;

int drawsquare()
{
    if (txMouseButtons()==1)
     {

      draw=1;
      x=txMouseX();
      y=txMouseY();
     }

     while(txMouseButtons() == 1)
     {
       txBegin;
      xr=txMouseX();
      yr=txMouseY();
      txSetFillColor(cvet);
      txSetColor(cvetobv, obv);
       cout<<figure<<" ";
      switch ( figure )
      {
         case 2: txRectangle(x, y, xr, yr); break;
          case 3: txEllipse(x, y, xr, yr); break;
          default :;
          }
    txSleep(50);
     txEnd;

     }


 txSetFillColor(cvet);
 txSetColor(cvetobv, obv);

  switch ( figure )
      {
         case 2: txRectangle(x, y, xr, yr); break;
          case 3: txEllipse(x, y, xr, yr); break;
          default :;
          }

}


/*int drawellipse()
{
    if (txMouseButtons()==1)
     {
      figure=3;
      draw=1;
      x=txMouseX();
      y=txMouseY();
     }

     while(txMouseButtons() == 1)
     {
       txBegin;
      xr=txMouseX();
      yr=txMouseY();
      txSetFillColor(cvet);
      txSetColor(cvetobv, obv);
    txEllipse(x, y, xr, yr);
    txSleep(50);
     txEnd;

     }

txSetFillColor(cvet);
txSetColor(cvetobv, obv);
txEllipse(x, y, xr, yr);

}      */

}      ;


class sizeSlider
{
private:
int smw,smh, slx, sly;

public:

     sizeSlider(int sWidth, int sHeight, int slX, int slY)
        {
        smw=sWidth;
        smh=sHeight;
        slx=slX;
        sly=slY;
        }

    int drawSizeSlider()
        {
        txSetFillColor(TX_BLACK);
        txLine(smw, smw, smh, smh);
        }

};

class button
{
private:

int x,y,w,h;

public:


    button(int x1, int y1, int width, int height)
    {
    x=x1;
    y=y1;
    w=width;
    h=height;
    }

        int drawButton()
        {
        txSetFillColor(TX_BLUE);
        txRectangle(x, y, x+w, y+h);
        }

        int click()
        {
        if (txMouseButtons() == 1)
        if (txMouseX() > x && txMouseY() > y && txMouseX() < x+w && txMouseY() < y+h)
        return 1;
        }

};

class paintmenu
{
private:
int mw, mh, bw, bh;

public:

    paintmenu(int mWidth, int mHeight, int buttonsW, int buttonsH)
    {
    mw=mWidth;
    mh=mHeight;
    bw=buttonsW;
    bh=buttonsH;
    }

    int drawMenu()
        {
    txSetFillColor(TX_WHITE);
    txSetColor(TX_BLACK, 5);
    txRectangle(10,10,100,590);
        }

};

int main()
{

    txCreateWindow (800, 600);
    txSetColor     (TX_BLACK);

    paintmenu menu(200,300,2,3); //����
    button b1(20, 20, 25, 30)  ; //�������
    button b2(50, 20, 25, 30)  ; //����
    button b3(80, 20, 10, 30)  ; //��������� ������

    print sq;                    //���������
    int currentObject=2;         //��� ������ �����


while(1)
{
txSetFillColor(TX_BLACK);
txClear();
txBegin();

 menu.drawMenu();
 b1.drawButton();
 b1.click();
 b2.drawButton();
 b2.click();
 b3.drawButton();
 b3.click();


 if (b1.click()) currentObject=2;      // b1.�������
 if (b2.click()) currentObject=3;
 if (b3.click()) currentObject=0;

 if (sq.draw||txMouseButtons()==1) {sq.figure=currentObject; sq.drawsquare();   }




txEnd();
}
    return 0;
    }

