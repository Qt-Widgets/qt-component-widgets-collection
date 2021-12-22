#ifndef QTCOMPONENTSPROGRESS_H
#define QTCOMPONENTSPROGRESS_H

#include <QProgressBar>

class QtComponentsProgressPrivate;

class QtComponentsProgress : public QProgressBar
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsProgress)
    Q_DECLARE_PRIVATE(QtComponentsProgress)
    Q_PROPERTY(QColor color READ inputColor WRITE setInputColor)
    Q_PROPERTY(QColor color READ frontColor WRITE setFrontColor)

public:

    explicit QtComponentsProgress(QWidget *parent = NULL);
    ~QtComponentsProgress();

    void setInputColor(const QColor& color);
    QColor inputColor()const;

    void setFrontColor(const QColor& color);
    QColor frontColor()const;


protected:
    QtComponentsProgress(QtComponentsProgressPrivate& d, QWidget* parent);
    const QSharedPointer<QtComponentsProgressPrivate> d_ptr;

    virtual void paintEvent(QPaintEvent * event);

};

#endif // QTCOMPONENTSPROGRESS_H
