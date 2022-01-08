#ifndef __QTCOMPONENTSLISTVIEW_P_H__
#define __QTCOMPONENTSLISTVIEW_P_H__

#include <QtGlobal>

#include "components/lib/qtcomponentstheme.h"

class QtComponentsListView;
class QtComponentsListModel;
class QtComponentsListViewData;
class QtComponentsListDelegate;

class QtComponentsListViewPrivate
{
    Q_DISABLE_COPY(QtComponentsListViewPrivate)
    Q_DECLARE_PUBLIC(QtComponentsListView)

public:

    QtComponentsListViewPrivate(QtComponentsListView* q);
    virtual ~QtComponentsListViewPrivate();

    void init();

    QtComponentsListView*const          q_ptr;
    QtComponentsListViewData*           _modelData;
    QtComponentsListModel*              _model;
    QtComponentsListDelegate*           _delegate;

    Components::ExpendMode              _clickModel;

    int                                 _height;
    //del WT0026
    //QRect                               _margin;

    QColor                              _splitColor;
    QColor                              _pressedColor;
    QColor                              _expandColor;

    QColor                              _parentBColor;
    QColor                              _parentHColor;
    QColor                              _parentPColor;

    QColor                              _childBColor;
    QColor                              _childHColor;
    QColor                              _childPColor;

    int                                 _iconMargin;
    QSize                               _iconSize;






};


#endif  //__QTCOMPONENTSLISTVIEW_P_H__