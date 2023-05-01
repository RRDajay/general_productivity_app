#include "datetime.h"

DateTime ::DateTime (QObject *parent)
    : QObject{parent}
{

    // Setup QTimer
    m_timer.setInterval(1000);

    // Connect signals and slots
    QObject::connect(&m_timer, &QTimer::timeout, this, &DateTime ::timerTimeout);

    // Start the timer
    m_timer.start();

}

void DateTime ::timerTimeout() {

    auto currDateTime = QDateTime::currentDateTime();
    QString currTime = currDateTime.time().toString();
    QString currDate = currDateTime.date().toString();

    setTime(currTime);
    setDate(currDate);

}

QString DateTime ::time()
{
    return m_time;
}

QString DateTime ::date()
{
    return m_date;
}

void DateTime ::setTime(QString newTime)
{
    m_time = newTime;
    emit timeChanged();
}

void DateTime ::setDate(QString newDate)
{

    if (m_date == newDate)
        return;

    m_date = newDate;
    emit dateChanged();
}

void DateTime ::btnHandler()
{
    if (m_timer.isActive()) {
        m_timer.stop();
    } else {
        m_timer.start();
    }
}
