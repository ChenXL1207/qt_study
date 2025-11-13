#include "qperson.h"

QPerson::QPerson(QObject *parent) : QObject(parent)
{

}

QPerson::~QPerson()
{

}

unsigned QPerson::age()
{
    return m_age;
}

void QPerson::setAge(unsigned value)
{
    m_age = value;
    emit(ageChanged(value));
}

void QPerson::incAge()
{
    m_age++;
    emit(ageChanged(m_age));
}

void QPerson::setPersonInfo(int age, int sex, QString name, int scores)
{
    this->m_age = age;
    this->m_sex = sex;
    this->m_name = name;
    this->m_scores = scores;
    emit(ageChanged(age));
}

int QPerson::getSex() const
{
    return m_sex;
}

QString QPerson::getName() const
{
    return m_name;
}

int QPerson::getScores() const
{
    return m_scores;
}
