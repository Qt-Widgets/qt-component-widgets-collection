#include "qtcomponentslistview.h"
#include "qtcomponentslistview_p.h"
#include "qtcomponentslistview_internal.h"


QtComponentsListViewPrivate::QtComponentsListViewPrivate(QtComponentsListView* q)
    : q_ptr(q)
{
    Q_ASSERT(q);
}

QtComponentsListViewPrivate::~QtComponentsListViewPrivate()
{

}

void QtComponentsListViewPrivate::init()
{
    Q_Q(QtComponentsListView);

    _parentBColor = QColor("#EDF2F9");
    _parentHColor = QColor("#F26520");
    _parentPColor = QColor("#00BCD4");

    _childBColor = QColor("#EDF2F9");
    _childHColor = QColor("#F26520");
    _childPColor = QColor("#00BCD4");

    _clickModel = Components::SingleClick;

    _height = 30;

    _iconSize = QSize(16, 16);

    _delegate = new QtComponentsListDelegate(q);

    _model = new QtComponentsListModel(q);

    _modelData = new QtComponentsListViewData(q);

    q->setItemDelegate(_delegate);

    q->setModel(_model);

}

QtComponentsListView::QtComponentsListView(QWidget* parent /*= NULL*/)
    : QListView(parent)
    , d_ptr(new QtComponentsListViewPrivate(this))
{
    d_func()->init();
}

QtComponentsListView::QtComponentsListView(QtComponentsListViewPrivate& d, QWidget* parent /*= NULL*/)
    : QListView(parent)
    , d_ptr(&d)
{
    d_func()->init();
}

QtComponentsListView::~QtComponentsListView()
{

}


void QtComponentsListView::setModelData(QtComponentsListViewData* data)
{
    Q_D(QtComponentsListView);
    d->_modelData = data;
}

QtComponentsListViewData* QtComponentsListView::modelData() const
{
    Q_D(const QtComponentsListView);
    return d->_modelData;
}

void QtComponentsListView::setItemHeight(int height)
{
    Q_D(QtComponentsListView);
    d->_height = height;
}

int QtComponentsListView::itemHeight() const
{
    Q_D(const QtComponentsListView);
    return d->_height;
}

void QtComponentsListView::setParentBColor(const QColor& color)
{
    Q_D(QtComponentsListView);
    d->_parentBColor = color;
}

QColor QtComponentsListView::parentBColor() const
{
    Q_D(const QtComponentsListView);
    return d->_parentBColor;
}

void QtComponentsListView::setParentHColor(const QColor& color)
{
    Q_D(QtComponentsListView);
    d->_parentHColor = color;
}

QColor QtComponentsListView::parentHColor() const
{
    Q_D(const QtComponentsListView);
    return d->_parentHColor;
}

void QtComponentsListView::setParentPColor(const QColor& color)
{
    Q_D(QtComponentsListView);
    d->_parentPColor = color;
}

QColor QtComponentsListView::parentPColor() const
{
    Q_D(const QtComponentsListView);
    return d->_parentPColor;
}

void QtComponentsListView::setChildBColor(const QColor& color)
{
    Q_D(QtComponentsListView);
    d->_childBColor = color;
}

QColor QtComponentsListView::childBColor() const
{
    Q_D(const QtComponentsListView);
    return d->_childBColor;
}

void QtComponentsListView::setChildHColor(const QColor& color)
{
    Q_D(QtComponentsListView);
    d->_childHColor = color;
}

QColor QtComponentsListView::childHColor() const
{
    Q_D(const QtComponentsListView);
    return d->_childHColor;
}

void QtComponentsListView::setChildPColor(const QColor& color)
{
    Q_D(QtComponentsListView);
    d->_childPColor = color;
}

QColor QtComponentsListView::childPColor() const
{
    Q_D(const QtComponentsListView);
    return d->_childPColor;
}

void QtComponentsListView::setIconMargin(int margin)
{
    Q_D(QtComponentsListView);
    d->_iconMargin = margin;
}

int QtComponentsListView::iconMargin() const
{
    Q_D(const QtComponentsListView);
    return d->_iconMargin;
}

void QtComponentsListView::setIconSize(const QSize& size)
{
    Q_D(QtComponentsListView);
    d->_iconSize = size;
}

QSize QtComponentsListView::iconSize() const
{
    Q_D(const QtComponentsListView);
    return d->_iconSize;
}

void QtComponentsListView::resetModel()
{
    Q_D(QtComponentsListView);
    d->_model->resetModel();
}

int QtComponentsListViewData::itemRowCount(QtComponentsListViewData::Item* item)
{
    int row = 0;
    if (item->expand)
    {
        for (int i = 0; i < item->_childs.size(); ++i)
        {
            row += itemRowCount(item->_childs[i]);
        }
        if (item->_childs.isEmpty())
        {
            row++;
        }
    }
    else
    {
        row++;
    }
    return row;
}

QtComponentsListViewData::Item* QtComponentsListViewData::item(QVector<QtComponentsListViewData::Item*> items, int logicalIndex)
{
    QtComponentsListViewData::Item* item = NULL;
    int curIndex = 0;
    for (int row = 0; row < items.size(); ++row)
    {
        if (row == logicalIndex)
        {
            item = items[row];
            break;
        }
        curIndex += itemRowCount(_items[row]);
        if (curIndex >= logicalIndex)
        {
            curIndex -= logicalIndex;
            item = _items[row]->_childs[curIndex];
            break;
        }
    }
    return item;
}

int QtComponentsListViewData::currentItemRowCount()
{
    int rows = 0;
    for (int row = 0; row < _items.size(); ++row)
    {
        if (_items[row]->expand)
        {
            rows += itemRowCount(_items[row]);
        }
        rows++;
    }
    return rows;
}

QtComponentsListViewData::Item* QtComponentsListViewData::currentItem(int logicalIndex)
{
    return item(_items, logicalIndex);
}

bool QtComponentsListViewData::isParent(int logicalIndex)
{
    int curIndex = 0;
    for (int row = 0; row < _items.size(); ++row)
    {
        if (logicalIndex == row)
        {
            return true;
        }
        curIndex += itemRowCount(_items[row]);
        if (curIndex >= logicalIndex)
        {
            curIndex -= logicalIndex;
            if (!_items[row]->_childs[curIndex]->_childs.isEmpty())
            {
                return true;
            }
        }
    }
    return false;
}

bool QtComponentsListViewData::isParent(const QtComponentsListViewData::Item* item)
{
    for (int i = 0; i < _items.size(); ++i)
    {
        if (item == _items[i])
        {
            return true;
        }
        for (int c = 0; c < _items[i]->_childs.size(); ++c)
        {
            if (item == _items[i]->_childs[c] && !_items[i]->_childs[c]->_childs.isEmpty())
            {
                return true;
            }
        }
    }
    return false;
}

QtComponentsListViewData::QtComponentsListViewData(QtComponentsListView* view, QObject* parent /*= NULL*/)
    : QObject(parent)
    , _view(view)
{
    Q_ASSERT(view);
}

QtComponentsListViewData::~QtComponentsListViewData()
{

}

