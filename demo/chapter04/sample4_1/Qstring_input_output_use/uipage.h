#ifndef UIPAGE_H
#define UIPAGE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>

class uipage : public QWidget
{
    Q_OBJECT
public:
    explicit uipage(QWidget *parent = nullptr);
    ~uipage() override;

private:
    void initUIpage();
    QLabel      *m_pLabCount;      // 数量标签
    QLineEdit   *m_pEditCount;     // 数量输入框
    QLabel      *m_pLabPrice;      // 单价标签
    QLineEdit   *m_pEditPrice;     // 单价输入框
    QPushButton *m_pBtnCalc;       // 计算按钮
    QLabel      *m_pLabTotal;      // 总价标签
    QLineEdit   *m_pEditTotal;     // 总价输入框

    // 进制转换相关控件
    QLabel      *m_pLabDec;        // 十进制标签
    QLineEdit   *m_pEditDec;       // 十进制输入框
    QPushButton *m_pBtnDec;        // 十进制转换按钮
    QLabel      *m_pLabBin;        // 二进制标签
    QLineEdit   *m_pEditBin;       // 二进制输入框
    QPushButton *m_pBtnBin;        // 二进制转换按钮
    QLabel      *m_pLabHex;        // 十六进制标签
    QLineEdit   *m_pEditHex;       // 十六进制输入框
    QPushButton *m_pBtnHex;        // 十六进制转换按钮
private slots:
    void on_Btn_CacluatePrice();
    void on_Btn_intoOthersNum();
};

#endif // UIPAGE_H
