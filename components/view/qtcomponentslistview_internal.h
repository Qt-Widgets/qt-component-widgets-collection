#ifndef __QTCOMPONENTSLISTVIEW_INTERNAL_H__
#define __QTCOMPONENTSLISTVIEW_INTERNAL_H__

#include <QAbstractListModel>
#include <QStyledItemDelegate>

#include "qtcomponentslistview.h"
#include "components/lib/qtcomponentstheme.h"

class QtComponentsListView;

class QtComponentsListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsListModel)

public:

    QtComponentsListModel(QtComponentsListView* view, QObject* parent = NULL);
    ~QtComponentsListModel();
    
    void resetModel();

protected:

    virtual int rowCount(const QModelIndex &parent) const;

    virtual QVariant data(const QModelIndex &index, int role) const;

private:

    QtComponentsListView*const      _view;
};

class QtComponentsListDelegate : public QStyledItemDelegate
{
    Q_OBJECT
    Q_DISABLE_COPY(QtComponentsListDelegate)

public:

    QtComponentsListDelegate(QtComponentsListView* view, QObject* parent = NULL);
    ~QtComponentsListDelegate();

protected:

    virtual QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;

    virtual void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;

    virtual bool editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index);

private:

    void drawBackground(QPainter* painter, const QStyleOptionViewItem& option, const QtComponentsListViewData::Item* item) const;

    void drawIconStyleOption(QPainter* painter, const QStyleOptionViewItem& option, const QtComponentsListViewData::Item* item) const;


private:
    
    QtComponentsListView*const      _view;
};


#endif  //__QTCOMPONENTSLISTVIEW_INTERNAL_H__