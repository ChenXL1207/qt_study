#ifndef QPERSON_H
#define QPERSON_H
#include <QObject>
#include <QString>

/*
    @author : chenxl
 Q_CLASSINFO 宏:用于为类添加自定义元信息，可在运行时通过元对象获取这些信息
           格式:格式：Q_CLASSINFO ("键", "值")，支持多个声明
  Q_PROPERTY 宏:用于声明类的属性，使属性可通过元对象系统进行访问（如属性浏览器、动态属性操作）
*/

class QPerson : public QObject
{
    Q_OBJECT
    Q_CLASSINFO("author","Arxibye")
    Q_CLASSINFO("company","NCHL")
    Q_CLASSINFO("version","1.0")
    Q_PROPERTY(unsigned age READ age WRITE setAge NOTIFY ageChanged) // 声明 age 属性，支持读写和通知
    Q_PROPERTY(QString name MEMBER m_name)  // 声明 name 属性，直接关联成员变量 m_nam
    Q_PROPERTY(int score MEMBER m_scores)   // 声明 score 属性，直接关联成员变量 m_scores
public:
    explicit QPerson(QObject *parent = nullptr);
    ~QPerson();
    unsigned age();
    void setAge(unsigned value);
    void incAge();
    void setPersonInfo(int age, int sex, QString name, int scores);
    int getSex() const;
    QString getName() const;
    int getScores() const;
private:
    int m_age = 10;
    int m_sex; // 0：男生，1：女生
    QString m_name;
    int m_scores = 79;

signals:
    void ageChanged(unsigned value);
};

#endif // QPERSON_H
