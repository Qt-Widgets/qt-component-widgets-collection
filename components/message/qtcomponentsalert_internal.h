#ifndef QTCOMPONENTSALERT_INTERNAL_H
#define QTCOMPONENTSALERT_INTERNAL_H

#include <QWidget>

class QSequentialAnimationGroup;
class QtComponentsAlert;

class QtComponentsAlertStyle : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsAlertStyle)

public:

    QtComponentsAlertStyle(QtComponentsAlert* parent);
    ~QtComponentsAlertStyle();

protected:

    virtual void paintEvent(QPaintEvent * event);

    virtual bool eventFilter(QObject * obj, QEvent * event);

private:

    void drawBackdrop(QPainter& painter);
    void drawIcon(QPainter& painter);
    void drawText(QPainter& painter);

    QtComponentsAlert*const         _alert;

};


class QtComponentsAlertDelegate : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsAlertDelegate)

public:

    QtComponentsAlertDelegate(QtComponentsAlert* parent);
    ~QtComponentsAlertDelegate();
#if 0
    inline void start();
    inline bool isStart();

    inline void setInterval(int msec);
    inline int interval()const;
#endif


private:

    QSequentialAnimationGroup*     _propertyAnimation;

};


#endif //QTCOMPONENTSALERT_INTERNAL_H