
#include "widget.h"
#include "ui_widget.h"
#include <QSlider>
#include <QAbstractButton>
#include <QDebug>
#include <QPalette>
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QScopedPointer>
Widget::Widget(QWidget* parent) : QWidget(parent), ui(new Ui::Widget), btnGroup(new QButtonGroup(this))
{
    initUI();       //初始化UI

    //将按钮加入按钮组
    for (auto btn : findChildren<QPushButton*>())   //findChildren模板函数，查找子类，返回list容器
    {
        btnGroup->addButton(btn);                   //遍历按钮，加入按钮组
    }
}

Widget::~Widget()
{delete ui;}
void Widget::initUI()
{
    ui->setupUi(this);//加载UI里的控件
    //全局样式
    QString global = "*{"
                     "border:none;"                                     //去除默认边框和默认的悬浮特效
                     "background-color: rgb(239,244,249);"              //设置背景色
                     "border-radius:15px;}";                            //圆角
    //全局的按钮样式
    QString Button = "QPushButton{"
                     "background-color: rgba(255,255,255,0);}";         //设置按钮背景色
    QString ButtonHover = "QPushButton:hover{"
                          "background-color: rgba(0,0,0,0);}";          //设置鼠标悬停时按钮背景色
    //等号单独样式
    QString ButtonEqual = "QPushButton#btn_operation_equals_sign{"
                          "background-color: rgba(53,54,87,100);}";     //单独设置等号，背景色
    QString ButtonEqualHover ="QPushButton#btn_operation_equals_sign:hover{"
                               "border:1px solid rgba(0,0,0,200);"      //单独设置等号，鼠标悬停时按钮边框色
                               "background-color: rgba(0,0,0,0);}";     //单独设置等号，鼠标悬停时按钮背景色
    //应用上面写好的样式，字符串拼接
    setStyleSheet(global+Button+ButtonHover+
                  ButtonEqual+ButtonEqualHover);
    //设置等号按钮的字体颜色
    ui->btn_operation_equals_sign->setStyleSheet("color:rgb(255,255,255)");                         //设置按钮字体颜色
    //设置按钮的阴影效果
    QGraphicsDropShadowEffect *shadow = Q_NULLPTR;
    for (auto button : findChildren<QPushButton *>())
    {
        shadow = new QGraphicsDropShadowEffect(this);
        shadow->setOffset(0, 0);                        //阴影的偏移量（右，下）
        shadow->setColor(QColor(0, 0, 0));              //阴影的颜色
        shadow->setBlurRadius(15);                      //控制阴影的模糊程度（光源距离）
        button->setGraphicsEffect(shadow);
    }
    //设置按钮的Frame圆角，填充颜色
    for (auto fra : findChildren<QPushButton*>())
    {
        static_cast<RippleEffect*>(fra->parent())->setRadius(15);//父类转换成子类，否则程序崩溃
        static_cast<RippleEffect*>(fra->parent())->setSpeed(5);
        //static_cast<RippleEffect*>(fra->parent())->setFillColor(func());
    }
}