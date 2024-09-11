#ifndef WIDGET_H
#define WIDGET_H
#include <QWidget>
#include <QButtonGroup>
#include <QVector>
#include <QString>
#include <QVariant>
#include "RippleEffect.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget* parent = nullptr);
    ~Widget();
private:
    Ui::Widget* ui;
    QButtonGroup* btnGroup;
    bool pointAilve = false;
    QString BtnText;//按钮上的文字
private:
    void initUI();//初始化UI
    void initMember();//初始化成员变量
    void clearC();//清空
};
#endif // WIDGET_H







