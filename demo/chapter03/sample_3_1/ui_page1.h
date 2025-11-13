#ifndef UI_PAGE1_H
#define UI_PAGE1_H

#include <QWidget>
#include <QLabel>
#include <QDebug>
#include <QTextLine>
#include <QSpinBox>
#include <QTextEdit>
#include <QMetaObject>
#include <QMetaClassInfo>
#include <QMetaProperty>
#include "qperson.h"

class ui_page1 : public QWidget
{
    Q_OBJECT
public:
    explicit ui_page1(QWidget *parent = nullptr);
    ~ui_page1();

private:
    QPerson *boy;
    QPerson *girl;

    QSpinBox *m_pSpinBoyAge; //男生平均年龄
    QSpinBox *m_pPinGirlAge; // 女生平均年龄
    QTextEdit *m_pTextEdit; // 文本显示区域

    void initUIpages(); // 初始化UI函数
    void initPerson(); // 初始化类对象

private slots:
    void slots_onGrowClicked(int sexNum);
    void slots_onShowMetaInfoClicked();
    void slots_onClearClicked();

signals:

};

#endif // UI_PAGE1_H
