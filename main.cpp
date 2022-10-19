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

class sizeSlider
{
private:
int smw,smh, slx, sly;

public:
  int begPX=20, begPY=20, endPX=85, endPY=43;

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
                                int result=(slx-begPX)/5;
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
    //int widSlider;
    txCreateWindow(800, 600);
    txSetFillColour(TX_WHITE);
    txClear();

        paintmenu menu(200,300,2,3);
        //button b1(100,300,30,30);
        sizeSlider slider(20,30,25,30);

    while(txMouseButtons() != 3)
{
    txBegin();
    //b1.drawButton();
    //b1.click();
    menu.drawMenu();
    slider.drawSizeSlider();
    slider.mainSlider();
    txEnd();

       /* if (txMouseButtons() == 1)
        {
        txSleep(100);
        cout<<" "<<txMouseX()<<" ";
        cout<<" "<<txMouseY()<<" ";
        }  */

    }

       }
