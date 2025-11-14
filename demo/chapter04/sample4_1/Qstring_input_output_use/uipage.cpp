#include "uipage.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QGridLayout>
#include <QDebug>

uipage::uipage(QWidget *parent) : QWidget(parent)
{
    initUIpage(); // 第一步：先初始化所有控件（必须在 connect 之前）
    setWindowTitle("字符串与输入输出");
    resize(600, 300);

    // 第二步：再连接信号与槽（此时控件已初始化，指针有效）
    connect(m_pBtnCalc, &QPushButton::clicked,this,&uipage::on_Btn_CacluatePrice);
    connect(m_pBtnDec,&QPushButton::clicked,this,&uipage::on_Btn_intoOthersNum);
    connect(m_pBtnBin,&QPushButton::clicked,this,&uipage::on_Btn_intoOthersNum);
    connect(m_pBtnHex,&QPushButton::clicked,this,&uipage::on_Btn_intoOthersNum);
}

uipage::~uipage()
{
    // Qt 父对象会自动释放子控件，无需手动 delete
}

void uipage::initUIpage()
{
    // 初始化价格计算相关控件
    m_pLabCount = new QLabel("数量", this);
    m_pEditCount = new QLineEdit(this);
    m_pEditCount->setText("12");

    m_pLabPrice = new QLabel("单价", this);
    m_pEditPrice = new QLineEdit(this);
    m_pEditPrice->setText("5.3");

    m_pBtnCalc = new QPushButton("计算", this);

    m_pLabTotal = new QLabel("总价", this);
    m_pEditTotal = new QLineEdit(this);
    m_pEditTotal->setText("63.60");
    m_pEditTotal->setReadOnly(true);

    // 初始化进制转换相关控件
    m_pLabDec = new QLabel("十进制", this);
    m_pEditDec = new QLineEdit(this);
    m_pEditDec->setText("15");
    m_pBtnDec = new QPushButton("转换为其他进制", this);

    m_pLabBin = new QLabel("二进制", this);
    m_pEditBin = new QLineEdit(this);
    m_pEditBin->setText("1111");
    m_pEditBin->setReadOnly(true);
    m_pBtnBin = new QPushButton("转换为其他进制", this);

    m_pLabHex = new QLabel("十六进制", this);
    m_pEditHex = new QLineEdit(this);
    m_pEditHex->setText("F");
    m_pEditHex->setReadOnly(true);
    m_pBtnHex = new QPushButton("转换为其他进制", this);

    // 网格布局设置
    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->setSpacing(10);
    mainLayout->setContentsMargins(20, 20, 20, 20);

    // 第一行：数量、单价
    mainLayout->addWidget(m_pLabCount, 0, 0, Qt::AlignRight);
    mainLayout->addWidget(m_pEditCount, 0, 1);
    mainLayout->addWidget(m_pLabPrice, 0, 2, Qt::AlignRight);
    mainLayout->addWidget(m_pEditPrice, 0, 3);

    // 第二行：计算、总价
    mainLayout->addWidget(m_pBtnCalc, 1, 0, 1, 2, Qt::AlignRight);
    mainLayout->addWidget(m_pLabTotal, 1, 2, Qt::AlignRight);
    mainLayout->addWidget(m_pEditTotal, 1, 3);

    // 第三行：十进制转换
    mainLayout->addWidget(m_pLabDec, 2, 0, Qt::AlignRight);
    mainLayout->addWidget(m_pEditDec, 2, 1);
    mainLayout->addWidget(m_pBtnDec, 2, 2, 1, 2);

    // 第四行：二进制转换
    mainLayout->addWidget(m_pLabBin, 3, 0, Qt::AlignRight);
    mainLayout->addWidget(m_pEditBin, 3, 1);
    mainLayout->addWidget(m_pBtnBin, 3, 2, 1, 2);

    // 第五行：十六进制转换
    mainLayout->addWidget(m_pLabHex, 4, 0, Qt::AlignRight);
    mainLayout->addWidget(m_pEditHex, 4, 1);
    mainLayout->addWidget(m_pBtnHex, 4, 2, 1, 2);

    setLayout(mainLayout);

}

void uipage::on_Btn_CacluatePrice()
{
    QString countText = m_pEditCount->text();
    QString priceText = m_pEditPrice->text();
    int countNum = countText.toInt();
    double priceNum = priceText.toDouble();
    double resPrice = countNum*priceNum;
    QString totalPriceText = QString::number(resPrice);
    m_pEditTotal->setText(totalPriceText);
}

void uipage::on_Btn_intoOthersNum()
{
    // 初始化时给三个按钮设置不同的btnNum属性
    m_pBtnDec->setProperty("btnNum", 1);   // 十进制按钮标识为1
    m_pBtnBin->setProperty("btnNum", 2);   // 二进制按钮标识为2
    m_pBtnHex->setProperty("btnNum", 3);   // 十六进制按钮标识为3
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (!btn) return;
    // 获取当前点击按钮的btnNum属性值
    int btnType = btn->property("btnNum").toInt();

    switch(btnType)
    {
        case 1:
            // 执行十进制转其他进制的逻辑
//            decimalToOther();
            qDebug()<<"执行十进制转其他进制的逻辑";
            break;
        case 2:
            // 执行二进制转其他进制的逻辑
            qDebug()<<"执行二进制转其他进制的逻辑";
//            binaryToOther();
            break;
        case 3:
            // 执行十六进制转其他进制的逻辑
            qDebug()<<"执行十六进制转其他进制的逻辑";
//            hexToOther();
            break;
    }
}
