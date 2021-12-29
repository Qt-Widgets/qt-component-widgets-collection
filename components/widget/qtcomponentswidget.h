#ifndef QTCOMPONENTSWIDGET_H
#define QTCOMPONENTSWIDGET_H

#include <QWidget>

class QtComponentsWidgetPrivate;

class QtComponentsWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsWidget)
    Q_DECLARE_PRIVATE(QtComponentsWidget)

public:

    explicit QtComponentsWidget(QWidget *parent = NULL);
    ~QtComponentsWidget();

protected:

    QtComponentsWidget(QtComponentsWidgetPrivate& d, QWidget* parent = NULL);
    const QSharedPointer<QtComponentsWidgetPrivate> d_ptr;

    virtual void paintEvent(QPaintEvent * event);
    virtual bool event(QEvent* event);
};

#endif // QTCOMPONENTSWIDGET_H
