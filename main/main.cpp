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

class sizeSlider
{
private:
int smw,smh, slx, sly;

public:

    int sizeSlider(int sWidth, int sHeight, int slX, int slY)
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
    txCreateWindow(800, 600);
    txSetFillColour(TX_WHITE);
    txClear();

        paintmenu menu(200,300,2,3);
       //button b1(100,300,30,30);

    while(txMouseButtons() != 3)
{
    //b1.drawButton();
    menu.drawMenu();
}
    }

