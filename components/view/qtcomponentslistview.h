#ifndef __QTCOMPONENTSLISTVIEW_H__
#define __QTCOMPONENTSLISTVIEW_H__

#include <QListView>

class QtComponentsListViewData;
class QtComponentsListViewPrivate;

class QtComponentsListView : public QListView
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsListView)
    Q_DECLARE_PRIVATE(QtComponentsListView)

    Q_PROPERTY(int margin READ iconMargin WRITE setIconMargin)
    Q_PROPERTY(QSize size READ iconSize WRITE setIconSize)
    Q_PROPERTY(QColor color READ parentBColor WRITE setParentBColor)
    Q_PROPERTY(QColor color READ parentHColor WRITE setParentHColor)
    Q_PROPERTY(QColor color READ parentPColor WRITE setParentPColor)
    Q_PROPERTY(QColor color READ childBColor WRITE setChildBColor)
    Q_PROPERTY(QColor color READ childHColor WRITE setChildHColor)
    Q_PROPERTY(QColor color READ childPColor WRITE setChildPColor)

public:

    explicit QtComponentsListView(QWidget* parent = NULL);
    ~QtComponentsListView();

    void setModelData(QtComponentsListViewData* data);
    QtComponentsListViewData* modelData()const;

    void setItemHeight(int height);
    int itemHeight()const;

    void setParentBColor(const QColor& color);
    QColor parentBColor()const;

    void setParentHColor(const QColor& color);
    QColor parentHColor()const;

    void setParentPColor(const QColor& color);
    QColor parentPColor()const;

    void setChildBColor(const QColor& color);
    QColor childBColor()const;

    void setChildHColor(const QColor& color);
    QColor childHColor()const;

    void setChildPColor(const QColor& color);
    QColor childPColor()const;

    void setIconMargin(int margin);
    int iconMargin()const;

    void setIconSize(const QSize& size);
    QSize iconSize()const;

    void resetModel();


protected:

    QtComponentsListView(QtComponentsListViewPrivate& d, QWidget* parent = NULL);
    const QSharedPointer<QtComponentsListViewPrivate>      d_ptr;
};



class QtComponentsListViewData : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsListViewData)

public:

    struct Item : public QObject
    {
        int             level;
        QString         text;
        QString         tip;
        QString         icon;
        bool            expand = false;
        bool            frost  = false;
        QVector<QtComponentsListViewData::Item*> _childs;
    };

    int currentItemRowCount();
    int itemRowCount(QtComponentsListViewData::Item* item);

    QtComponentsListViewData::Item* currentItem(int logicalIndex);
    QtComponentsListViewData::Item* item(QVector<QtComponentsListViewData::Item*> items, int logicalIndex);

    bool isParent(int logicalIndex);
    bool isParent(const QtComponentsListViewData::Item* item);


    QtComponentsListViewData(QtComponentsListView* view, QObject* parent = NULL);
    ~QtComponentsListViewData();

    QVector<QtComponentsListViewData::Item*>        _items;


private:

    QtComponentsListView*const              _view;
};


#endif  //__QTCOMPONENTSLISTVIEW_H__