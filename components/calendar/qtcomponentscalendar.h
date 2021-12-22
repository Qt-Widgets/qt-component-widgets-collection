#ifndef QTCOMPONENTSCALEMDAR_H
#define QTCOMPONENTSCALEMDAR_H


#include <QCalendarWidget>

class QtComponentsCalendarWidgetPrivate;

class QtComponentsCalendarWidget : public QCalendarWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsCalendarWidget)
    Q_DECLARE_PRIVATE(QtComponentsCalendarWidget)

public:

    explicit QtComponentsCalendarWidget(QWidget* parent = NULL);
    ~QtComponentsCalendarWidget();


protected:

    QtComponentsCalendarWidget(QtComponentsCalendarWidgetPrivate& d, QWidget* parent = NULL);
    const QSharedPointer<QtComponentsCalendarWidgetPrivate> d_ptr;


};




#endif //!QTCOMPONENTSCALEMDAR_H
