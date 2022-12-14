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
#include <string>

class text
{
private:

public:

int k=1;
char c;
string s;
int x, y;


   string textdraw()
{
COLORREF CVT=txGetFillColor();
    x=txMouseX();
    y=txMouseY();
    while (k!=13)
    {
        //txBegin();
        k=getch();
        c=k;
        if ( c == '\b')
            {
            s.erase(s.length()-1);
            }
        else s=s+c;
                txTextOut(x, y, s.c_str());
               // txEnd();
                txSleep(200);
                txSetFillColor(TX_WHITE);
                txClear();

    }
    txSetFillColor(CVT);
        return s;
}

};

class sizeSlider
{
private:
int smw,smh, slx, sly;

public:
  int begPX=20, begPY=20, endPX=230, endPY=43, result;

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
        txLine(smw, smw, smh-10, smh+20);//1 линия
        txLine(smw, smw+10, smh+200, smh);//2 линия
        txLine(smw+210, smw, smh+200, smh+20);//3 линия
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
COLORREF color=TX_BLUE;


public:

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
            return 0;
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

COLORREF colormenu()
{
    button red(0,0,100,30);
        red.SetColor(TX_RED);
        red.drawButton();
          if (red.click())
            return TX_RED;
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
    txRectangle(10,10,250,1000);
        }

};


int main()
    {
    txCreateWindow(1920, 1050);
    txSetFillColour(TX_WHITE);
    txClear();

        paintmenu menu(200,300,2,3);
        sizeSlider slider(20,30,25,30);
        button b1(20, 60, 30, 30);
        text t1;

    while(txMouseButtons() != 3)
{
    txBegin();
    menu.drawMenu();
    slider.drawSizeSlider();
    slider.mainSlider();
        b1.PicterAdd("квадрат.bmp",30,30);
        b1.drawButton();
        b1.click();
        string s111;
        if (txMouseButtons() == 1) {s111=t1.textdraw();}
        txTextOut(t1.x,t1.y,s111.c_str());
    txEnd();

       /* if (txMouseButtons() == 1)
        {
        txSleep(100);
        cout<<" "<<txMouseX()<<" ";
        cout<<" "<<txMouseY()<<" ";
        }  */

}

       }
