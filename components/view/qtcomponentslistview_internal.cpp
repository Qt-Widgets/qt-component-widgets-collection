#include "qtcomponentslistview_internal.h"
#include "components/lib/qtcomponentstools.h"

#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

QtComponentsListModel::QtComponentsListModel(QtComponentsListView* view, QObject* parent)
    : QAbstractListModel(parent)
    , _view(view)
{
    Q_ASSERT(view);
}

QtComponentsListModel::~QtComponentsListModel()
{

}

void QtComponentsListModel::resetModel()
{
    beginResetModel();
    endResetModel();
}

int QtComponentsListModel::rowCount(const QModelIndex &parent) const
{
    return _view->modelData()->currentItemRowCount();
}

QVariant QtComponentsListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index))
    {
        return QVariant();
    }

    switch (role)
    {
    case Qt::UserRole:
        return QVariant::fromValue((void*)_view->modelData()->currentItem(index.row()));
    default:
        break;
    }

    return QVariant();
}

QtComponentsListDelegate::QtComponentsListDelegate(QtComponentsListView* view, QObject* parent)
    : QStyledItemDelegate(parent)
    , _view(view)
{
    Q_ASSERT(view);
}

QtComponentsListDelegate::~QtComponentsListDelegate()
{

}

QSize QtComponentsListDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    Q_UNUSED(option);
    Q_UNUSED(index);
    return QSize(_view->width(), _view->itemHeight());
}

void QtComponentsListDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QtComponentsListViewData::Item*const item = (QtComponentsListViewData::Item*)index.data(Qt::UserRole).value<void*>();
    Q_ASSERT(item);
    painter->setRenderHint(QPainter::Antialiasing);
    
    QColor color;
    bool parent = item->level == 1 ? true : false;
    bool frost = item->frost;

    if (option.state & QStyle::State_Selected)
    {
        color = parent ? _view->parentPColor() : _view->childPColor();
    }
    else if (option.state & QStyle::State_MouseOver)
    {
        color = parent ? _view->parentHColor() : _view->childHColor();
    }
    else
    {
        color = parent ? _view->parentBColor() : _view->childBColor();
    }
    painter->drawPixmap(0, 0, QtComponentsTools::inst().pixmap(QString("list"), item->icon, color, _view->iconSize()));

}

bool QtComponentsListDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    if (QEvent::MouseButtonDblClick == event->type())
    {
        qDebug() << index.row();
        _view->modelData()->currentItem(index.row())->expand = !_view->modelData()->currentItem(index.row())->expand;
        _view->resetModel();
    }
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}

void QtComponentsListDelegate::drawBackground(QPainter* painter, const QStyleOptionViewItem& option, const QtComponentsListViewData::Item* item) const
{
    painter->save();
    painter->setPen(Qt::NoPen);
    if (option.state & QStyle::State_Selected)
    {
        qDebug() << "selected = " << option.state;
        //painter->fillRect(option.rect, item->pColor);
    }
    else if (option.state & QStyle::State_MouseOver)
    {
        qDebug() << "hover = " << option.state;

        //painter->fillRect(option.rect, item->hColor);
    }
    else
    {
        qDebug() << "def = "<<option.state;

        //painter->fillRect(option.rect, item->bColor);
    }
    painter->restore();
}

void QtComponentsListDelegate::drawIconStyleOption(QPainter* painter, const QStyleOptionViewItem& option, const QtComponentsListViewData::Item* item) const
{
    painter->save();
    
    bool parent = _view->modelData()->isParent(item);



    painter->restore();
}
