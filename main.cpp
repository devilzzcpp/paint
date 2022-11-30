//========================================================================
//! @file       Main.cpp
//{=======================================================================
//!
//! @brief      <Заголовок>\n
//! @brief      <Подзаголовок>
//!
//! @version    [Version 0.01 alpha, build 1]
//! @author     Copyright (C) <Автор>, <Год> (<Имя> <Почта>)
//! @date       <Дата>
//!
//! @par        Протестировано
//!           - (TODO: список платформ)
//!
//! @todo     - (TODO: список ближайших планов по этому файлу)
//!
//! @bug      - (TODO: список найденных ошибок в этом файле)
//!
//! @par        История изменений файла
//!           - Версия 0.01 Alpha
//!             - Только что созданный файл
//!
//}=======================================================================

#include "TXLib.h"
#include <iostream>
#include <list>
 using namespace std;

int x=0;
int y=0;
int xr=100;
int yr=100;
int zx=0;
int buttonssquare=1;
int bbs;
int cvet=TX_WHITE;
int cvetobv=TX_GRAY;
int obv=7;


class print //класс для рисования фигур
{
private:

 int x2, y2;

public:

  int draw=0;
  int x=0, y=0;         //верхний левый угол
  int xr=1, yr=1;       //нижний правый угол
  int cvet=TX_WHITE;    //основной цвет квадрата  txEllipse (100, 100, 300, 200);
  int cvetobv=TX_GRAY;  //цвет обводки квадрата
  int obv=7;            //размер обводки квадрата
  int figure=3;         //какая фигура будет рисоваться 0-никакая, 1-линия, 2-квадрат, 3-элипс

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

        txBegin();
        xr=txMouseX();
        yr=txMouseY();
       // txSetFillColor(cvet);
        //txSetColor(cvetobv, obv);

        switch ( figure )
            {
            case 2: txRectangle(x, y, xr, yr); break;
            case 3: txEllipse(x, y, xr, yr); break;
            default :;
            }


        txSleep(50);
        txEnd();

        }


            //txSetFillColor(cvet);
            //txSetColor(cvetobv, obv);

  switch (figure)
            {
            case 0: txEllipse(x, y, xr, yr); break;
            case 2: txRectangle(x, y, xr, yr); break;
            case 3: txEllipse(x, y, xr, yr); break;
            default :;
            }



}

    int draws()
    {

        switch (figure)
            {
            case 2: txRectangle(x, y, xr, yr); break;
            case 3: txEllipse(x, y, xr, yr); break;
            default :;
            }


    }

};

class sizeSlider
{
private:
int smw,smh, slx, sly;

public:
  int begPX=20, begPY=20, endPX=85, endPY=43, result;


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
        txLine(smw, smw, smh-10, smh+10);
        txLine(smw, smw+10, smh+55, smh);
        txLine(smw+65, smw, smh+55, smh+10);
        }

    int mainSlider()
            {
            txSetFillColor(TX_BLACK);
            txLine(slx,sly,slx,sly+10);
                if (txMouseX() > begPX && txMouseY() > begPY && txMouseX() < endPX && txMouseY() < endPY)
                    if (txMouseButtons() == 1)
                            slx=txMouseX();
                                 result=(slx-begPX)/5;
                                    std::stringstream ss;
                                    ss << result;
                                    std::string s = ss.str();
                                        txTextOut(72, 53, s.c_str());
                                            return result;

            }

};

class button
{
private:

int x,y,w,h;

public:
COLORREF color=TX_WHITE;


string pic;
int picterVisible=0;
int picterW, picterH;

HDC picter;



    button(int x1, int y1, int width, int height)
    {
    x=x1;
    y=y1;
    w=width;
    h=height;
    }

        int drawButton()
        {
        txSetFillColor(color);
        txRectangle(x, y, x+w, y+h);

        if (picterVisible)
                    {
                    txBitBlt (txDC(), x, y, picterW, picterH, picter);
                    }

        }

        int click()
        {
        if (txMouseButtons() == 1)
        if (txMouseX() > x && txMouseY() > y && txMouseX() < x+w && txMouseY() < y+h)
        return 1;
        }


        int clickr()
        {
        if (txMouseButtons() == 2)
        if (txMouseX() > x && txMouseY() > y && txMouseX() < x+w && txMouseY() < y+h)
        return 2;
        }

        int SetColor(COLORREF C)
                {
                color=C;
                }



        int PicterAdd(string Pic, int picW, int picH)
                        {
                        picter = txLoadImage (Pic.c_str());

                        picterVisible=1;
                        picterW=picW;
                        picterH=picH;
                        }

};
struct  colormenuCvet
{COLORREF cvt1;
COLORREF cvt2;} ;

colormenuCvet colormenu()
{colormenuCvet x;
x.cvt1=TX_TRANSPARENT;
x.cvt2=TX_TRANSPARENT;
    button white(20,100,30,30);
        white.SetColor(TX_WHITE);
        white.drawButton();

          if (white.click())
            {
            x.cvt1=TX_WHITE;
            }

            if (white.clickr())
            {
             x.cvt2=TX_WHITE;
            }




            button black(60,100,30,30);
        black.SetColor(TX_BLACK);
        black.drawButton();

          if (black.click())
            {
            x.cvt1=TX_BLACK;
            }

            if (black.clickr())
            {
          x.cvt2=TX_BLACK;
            }


        button red(20,140,30,30);
        red.SetColor(TX_RED);
        red.drawButton();

          if (red.click())
            {
            x.cvt1=TX_RED;
            }

            if (red.clickr())
            {
            x.cvt2=TX_RED;
            }

            button yellow(60,140,30,30);
        yellow.SetColor(TX_YELLOW);
        yellow.drawButton();

          if (yellow.click())
            {
            x.cvt1=TX_YELLOW;
            }

            if (yellow.clickr())
            {
            x.cvt2=TX_YELLOW;
            }

             button blue(20,180,30,30);
        blue.SetColor(TX_BLUE);
        blue.drawButton();

          if (blue.click())
            {
            x.cvt1=TX_BLUE;
            }

            if (blue.clickr())
            {
            x.cvt2=TX_BLUE;
            }

            return x;
/*
            button lightgray(60,180,30,30);
        lightgray.SetColor(TX_LIGHTGRAY);
        lightgray.drawButton();

          if (lightgray.click())
            {
            return TX_LIGHTGRAY;
            }

            if (lightgray.clickr())
            {
          //cvetobv=TX_LIGHTGRAY;
            return TX_LIGHTGRAY;
            }
*/
           // return TX_TRANSPARENT;

}

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

    txCreateWindow (1900, 1000);
    txSetColor (TX_WHITE);

    paintmenu menu(200,300,2,3); //меню
    button b1(20, 60, 30, 30); //квадрат
    b1.PicterAdd("квадрат.bmp",30,30);

    button b2(60, 60, 30, 30); //круг
    b2.PicterAdd("круг.bmp",30,30);
    //button b3(80, 60, 10, 30); //свободный курсор

   // button b3(20, 220, 30, 30); //кисть
    //b3.PicterAdd("кисть.bmp",30,30);

     button b4(20, 240, 30, 30);



    sizeSlider slider(20,30,25,30);
    print sq;//рисовалка
    int currentObject=2;//для выбора фигур
    int obvodka;



    list <print> qs;


    while(1)
    {
        txSetFillColor(TX_WHITE);
        txClear();



        txBegin();

            for (print k:qs)
            {

            txSetFillColor(k.cvet);
            txSetColor(k.cvetobv, k.obv);

            k.draws();
               }

        menu.drawMenu();

        slider.drawSizeSlider();
        slider.mainSlider();




         colormenuCvet cvetT=colormenu();

         if (cvetT.cvt1!=TX_TRANSPARENT){sq.cvet=cvetT.cvt1;}


         if (cvetT.cvt2!=TX_TRANSPARENT)sq.cvetobv=cvetT.cvt2;




         b1.drawButton();
         b1.click();
         b2.drawButton();
         b2.click();
        // b3.drawButton();
        // b3.click();
         b4.drawButton();
         b4.click();

         if (b1.click()) currentObject=2;// b1.выбрана
         if (b2.click()) currentObject=3;//sq.figure=currentObject;
         //if (b3.click()) currentObject=3; //bbs=slider.result;
         if (b4.click()) { if(!qs.empty()) qs.pop_back(); if(!qs.empty()) qs.pop_back();}


         sq.drawsquare();
         if (sq.draw && txMouseX()>=200 )

                {
            sq.figure=currentObject;

            sq.obv=slider.result;
            qs.push_back(sq);
            //cout<<" "<<qs.size()<<" ";
            sq.draw=0;
            //auto p=qs.begin();


                }
                sq.draw=0;


        txEnd();
            }

        return 0;

        }

