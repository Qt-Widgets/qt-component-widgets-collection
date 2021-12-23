#ifndef QTCOMPONENTSCIRCLEPROGRESS_H
#define QTCOMPONENTSCIRCLEPROGRESS_H

#include <QProgressBar>

class QtComponentsCircleProgressPrivate;

class QtComponentsCircleProgress : public QProgressBar
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsCircleProgress)
    Q_DECLARE_PRIVATE(QtComponentsCircleProgress)

    Q_PROPERTY(QColor color READ inputColor WRITE setInputColor)
    Q_PROPERTY(QColor color READ frontColor WRITE setFrontColor)
    Q_PROPERTY(int size READ size WRITE setSize)

public:

    explicit QtComponentsCircleProgress(QWidget* parent = NULL);
    ~QtComponentsCircleProgress();

    void setInputColor(const QColor& color);
    QColor inputColor()const;

    void setFrontColor(const QColor& color);
    QColor frontColor()const;

    void setSize(const int size);
    int size()const;

    virtual QSize sizeHint() const;

protected:

    QtComponentsCircleProgress(QtComponentsCircleProgressPrivate& d, QWidget* parent);
    const QSharedPointer<QtComponentsCircleProgressPrivate> d_ptr;

    virtual void paintEvent(QPaintEvent * event);

};

#endif // QTCOMPONENTSCIRCLEPROGRESS_H
