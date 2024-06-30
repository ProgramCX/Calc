#include "windowsizeadapter.h"
#include "QDesktopWidget"
#include "qdebug.h"
WindowSizeAdapter::WindowSizeAdapter(QObject *parent)
    : QObject{parent}
{

}

void WindowSizeAdapter::setWindow(QWidget *w)
{
    window=w;

}

void WindowSizeAdapter::addWidget(QWidget *widget)
{
    widgets.append(widget);
}

QRect WindowSizeAdapter::getPaintRect()
{
    QRect reRect;
    reRect.setX(0);
    reRect.setY(0);
    reRect.setHeight(window->height());
    reRect.setWidth(70*windowScaling);
    return reRect;
}




bool WindowSizeAdapter::adaptAll()
{


        QDesktopWidget desktop;


        qint64 height=desktop.height()*0.5;
        qint64 width=height/1.4;
        qint16 y=(desktop.height()-height)/2;
        qint16 x=(desktop.width()-width)/2;
        qDebug()<<"desktopheight"<<desktop.height();
        qDebug()<<"desktopwidth"<<desktop.width();
        qDebug()<<"height"<<height;
        qDebug()<<"width"<<width;
        //窗口长宽缩放以及窗口居中；

        double scaling=(height+0.0001)/window->geometry().height();
        windowScaling=scaling;
        window->setMinimumHeight(height);
        window->setMinimumWidth(width);
        window->setGeometry(x,y,width,height);


        return 1;

}
