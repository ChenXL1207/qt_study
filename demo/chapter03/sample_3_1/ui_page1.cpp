#include "ui_page1.h"
#include <QPushButton>
#include <QHBoxLayout>
#include "qperson.h"

ui_page1::ui_page1(QWidget *parent)
    : QWidget(parent),
    m_pSpinBoyAge(nullptr),
    m_pPinGirlAge(nullptr),
    m_pTextEdit(nullptr)
{
    // 初始化 QPerson 对象
    initPerson();
    initUIpages();
    setWindowTitle("MetaObject的使用");
    resize(600, 400);  // 设置初始窗口大小

    m_pSpinBoyAge->setProperty("isBoy",true); // 设置动态属性
    m_pPinGirlAge->setProperty("isBoy",false);
}

// 析构函数
ui_page1::~ui_page1()
{

}

void ui_page1::initUIpages()
{
    QLabel *m_plable_SettingBoyAge = new QLabel("设置男生年龄",this);
    m_pSpinBoyAge = new QSpinBox(this);
    m_pSpinBoyAge->setValue(10);
    m_pSpinBoyAge->setRange(0,150);

    QPushButton *btnBoyGrow = new QPushButton("boy长大一岁");
    QPushButton *btnMetaInfo = new QPushButton("类的元对象信息");

    // 第一行水平布局
    QHBoxLayout *Layout_Line1_Boy = new QHBoxLayout;
    Layout_Line1_Boy->addWidget(m_plable_SettingBoyAge);
    Layout_Line1_Boy->addWidget(m_pSpinBoyAge);
    Layout_Line1_Boy->addWidget(btnBoyGrow);
    Layout_Line1_Boy->addWidget(btnMetaInfo);

    // 第二行水平布局
    QLabel *m_plable_SettingGirlAge = new QLabel("设置女生年龄",this);
    m_pPinGirlAge= new QSpinBox(this);
    m_pPinGirlAge->setValue(20);
    m_pPinGirlAge->setRange(0,150);

    QPushButton *btnGirlGrow = new QPushButton("girl长大一岁");
    QPushButton *btnClear = new QPushButton("清空文本框");

    QHBoxLayout *Layout_Line2_Girl = new QHBoxLayout;
    Layout_Line2_Girl->addWidget(m_plable_SettingGirlAge);
    Layout_Line2_Girl->addWidget(m_pPinGirlAge);
    Layout_Line2_Girl->addWidget(btnGirlGrow);
    Layout_Line2_Girl->addWidget(btnClear);

    // 文本显示区域
    m_pTextEdit = new QTextEdit();
    m_pTextEdit->setReadOnly(false);

    QGridLayout *mainLayout = new QGridLayout();
    mainLayout->setSpacing(15);
    mainLayout->setContentsMargins(20,20,20,20);

    mainLayout->addLayout(Layout_Line1_Boy,0,0);
    mainLayout->addLayout(Layout_Line2_Girl,1,0);
    mainLayout->addWidget(m_pTextEdit,2,0);

    setLayout(mainLayout);

    connect(btnBoyGrow, &QPushButton::clicked,this,&ui_page1::slots_onGrowClicked);
    connect(btnGirlGrow, &QPushButton::clicked,this,&ui_page1::slots_onGrowClicked);
    connect(btnMetaInfo,&QPushButton::clicked,this,&ui_page1::slots_onShowMetaInfoClicked);
    connect(btnClear,&QPushButton::clicked,this,&ui_page1::slots_onClearClicked);
}

void ui_page1::initPerson()
{
    boy = new QPerson(this);
    girl = new QPerson(this);

    boy->setPersonInfo(18, 0, "chen", 95);  // 0：男生
    girl->setPersonInfo(20, 1, "song", 99); // 1：女生
}

void ui_page1::slots_onGrowClicked(int sexNum)
{
    Q_UNUSED(sexNum);
    /*
        sender() 是 QObject 的成员函数，返回发送当前信号的对象指针（此处是触发 valueChanged 信号的 QSpinBox）。
        qobject_cast 是 Qt 提供的安全类型转换，用于将 sender() 返回的 QObject* 转换为 QSpinBox*（若类型不匹配，返回 nullptr）。
    */
    // QSpinBox *spinBox = qobject_cast<QSpinBox*>(sender());
    if(m_pSpinBoyAge->property("isBoy").toBool())
    {
      boy->setAge(m_pSpinBoyAge->value());
    }
    else if(m_pPinGirlAge->property("isBoy").toBool()){
      girl->setAge(m_pPinGirlAge->value());
    }
}

void ui_page1::slots_onShowMetaInfoClicked()
{
    m_pTextEdit->clear(); // 清空文本框

    // 步骤1：获取 QPerson 类的元对象
    const QMetaObject *personMeta = boy->metaObject();

    // 步骤2：显示类的基本信息
    m_pTextEdit->append("=== QPerson 类元信息 ===");
    m_pTextEdit->append(QString("类名：%1").arg(personMeta->className()));
    m_pTextEdit->append(QString("父类名：%1").arg(personMeta->superClass()->className()));

    // 步骤3：显示 Q_CLASSINFO 自定义信息
    m_pTextEdit->append("\n==== 自定义元信息（Q_CLASSINFO） ====");
    for (int i = 0; i < personMeta->classInfoCount(); ++i) {
        QMetaClassInfo info = personMeta->classInfo(i);
        m_pTextEdit->append(QString("%1: %2").arg(info.name()).arg(info.value()));
    }

    // 步骤4：显示 Q_PROPERTY 属性信息
    m_pTextEdit->append("\n==== 属性信息（Q_PROPERTY） ====");
    for (int i = 0; i < personMeta->propertyCount(); ++i) {
        QMetaProperty prop = personMeta->property(i);
        m_pTextEdit->append(QString(
            "属性名：%1\n"
            "  类型：%2\n"
            "  可读：%3\n"
            "  可写：%4\n"
            "  通知信号：%5"
        )
        .arg(prop.name())
        .arg(prop.typeName())
        .arg(prop.isReadable() ? "是" : "否")
        .arg(prop.isWritable() ? "是" : "否")
        .arg(QString::fromLatin1(prop.notifySignal().name())));
    }

    // 步骤5：显示当前对象的具体信息
    m_pTextEdit->append("\n==== 当前对象信息 ====");
    m_pTextEdit->append(QString("Boy对象信息："));
    m_pTextEdit->append(QString("  姓名：%1").arg(boy->getName()));
    m_pTextEdit->append(QString("  年龄：%1").arg(boy->age()));
    m_pTextEdit->append(QString("  性别：%1").arg(boy->getSex() == 0 ? "男" : "女"));
    m_pTextEdit->append(QString("  分数：%1").arg(boy->getScores()));
    
    m_pTextEdit->append(QString("\nGirl对象信息："));
    m_pTextEdit->append(QString("  姓名：%1").arg(girl->getName()));
    m_pTextEdit->append(QString("  年龄：%1").arg(girl->age()));
    m_pTextEdit->append(QString("  性别：%1").arg(girl->getSex() == 0 ? "男" : "女"));
    m_pTextEdit->append(QString("  分数：%1").arg(girl->getScores()));
}

void ui_page1::slots_onClearClicked()
{
    m_pTextEdit->clear();
}



