#ifndef CLOCK_H
#define CLOCK_H

#include <QObject>
#include <QString>
#include <QDateTime>
#include <QTime>
#include <QTimer>
#include <QDebug>

class DateTime  : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString time READ time WRITE setTime NOTIFY timeChanged)
    Q_PROPERTY(QString date READ date WRITE setDate NOTIFY dateChanged)

public:
    explicit DateTime (QObject *parent = nullptr);
    QString time();
    QString date();

signals:
    void timeChanged();
    void dateChanged();

public slots:
    void setTime(QString);
    void setDate(QString);
    void timerTimeout();
    void btnHandler();

private:
//    double m_time;
    QString m_time;
    QString m_date;
    QTimer m_timer;

};

#endif // CLOCK_H
