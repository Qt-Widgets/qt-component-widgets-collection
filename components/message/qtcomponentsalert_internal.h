#ifndef QTCOMPONENTSALERT_INTERNAL_H
#define QTCOMPONENTSALERT_INTERNAL_H

#include <QWidget>

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

private:

    QtComponentsAlert*const         _alert;

};


#endif //QTCOMPONENTSALERT_INTERNAL_H