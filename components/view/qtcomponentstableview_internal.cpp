#include "qtcomponentstableview_internal.h"
#include "qtcomponentstableview.h"
#include  "components/lib/qtcomponentstools.h"

#include <QMouseEvent>
#include <QPainter>
#include <QCheckBox>
#include <QScrollBar>


const unsigned int COUSTOM_LINEDIT_LEFT_MARGIN = 0x000F;

QtComponentsHeaderView::QtComponentsHeaderView(QtComponentsTableView* view, Qt::Orientation orientation, QWidget *parent)
    : QHeaderView(orientation,parent)
    , _state(Qt::Unchecked)
    , _view(view)
{
    Q_ASSERT(view);
}

QtComponentsHeaderView::~QtComponentsHeaderView()
{

}

void QtComponentsHeaderView::setCheckable(Qt::CheckState state)
{
    if (_state == state)
    {
        return;
    }
    _state = state;
    viewport()->update();
}

Qt::CheckState QtComponentsHeaderView::isChecked() const
{
    return _state;
}

void QtComponentsHeaderView::paintSection(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    if (logicalIndex < 0 || logicalIndex >= _view->modelData()->_labels.size())
    {
        return;
    }
    Components::TableHeaderType role = _view->modelData()->_labels[logicalIndex].first;
    painter->setRenderHint(QPainter::Antialiasing);
    QRect nRect = rect.adjusted(7, 7, -7, -7);
    switch (role)
    {
    case Components::ID:
        break;
    case Components::hCheckBox:
        drawHeaderCheckBox(painter, rect, logicalIndex);
        break;
    case Components::hText:
        drawHeaderText(painter, nRect, logicalIndex);
        break;
    case Components::hSort:
        drawHeaderSort(painter, nRect, logicalIndex);
        break;
    case Components::hSearch:
        drawHeaderSearch(painter, nRect);
        break;
    default:
        QHeaderView::paintSection(painter, rect, logicalIndex);
        break;
    }
}

void QtComponentsHeaderView::mousePressEvent(QMouseEvent *event)
{
    int nColumn = logicalIndexAt(event->pos());
    if (nColumn < 0 || nColumn >= _view->modelData()->_labels.size())
    {
        return;
    }
    Components::TableHeaderType role = _view->modelData()->_labels[nColumn].first;
    if ((event->buttons() & Qt::LeftButton))
    {
        if (Components::hCheckBox == role)
        {
            if (Qt::Checked == _state)
            {
                _state = Qt::Unchecked;
            }
            else
            {
                _state = Qt::Checked;
            }
            emit sectionCheckable(_state);
        }
        if (Components::hSort == role)
        {
            emit sectionClicked(nColumn);
        }
        viewport()->update();
    }
    else
    {
        QHeaderView::mousePressEvent(event);
    }
}

void QtComponentsHeaderView::drawHeaderCheckBox(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    painter->save();
    QStyleOptionButton option;
    int w = rect.x() + 7;
    int h = rect.height() / 2 - 7;
    option.rect = QRect(w, h, 14, 14);
    if (Qt::Checked == _state)
        option.state = QStyle::State_On;
    else
        option.state = QStyle::State_Off;
    QCheckBox checkBox;
    style()->drawPrimitive(QStyle::PE_IndicatorCheckBox, &option, painter, &checkBox);
    painter->restore();
}

void QtComponentsHeaderView::drawHeaderText(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    painter->save();
    painter->drawText(rect.adjusted(7, 0, 0, 0), Qt::AlignLeft | Qt::AlignVCenter, _view->modelData()->_labels[logicalIndex].second);
    painter->restore();
    drawCutLine(painter, rect);
}

void QtComponentsHeaderView::drawHeaderSort(QPainter *painter, const QRect &rect, int logicalIndex) const
{
    painter->save();
    drawHeaderText(painter, rect, logicalIndex);
    painter->restore();
}

void QtComponentsHeaderView::drawHeaderSearch(QPainter *painter, const QRect &rect) const
{
    painter->save();
    int w = rect.x() + 7;
    int h = rect.height() / 2 - 5;
    QRect searchRect = QRect(w, h, 24, 24);
    painter->drawPixmap(searchRect, QtComponentsTools::inst().pixmap(QString("table"), QString("search"), searchRect.size()));
    painter->restore();
}

void QtComponentsHeaderView::drawCutLine(QPainter *painter, const QRect &rect) const
{
    painter->save();
    QPen pen(QtComponentsTools::inst().getColor("lineColor"));
    painter->setPen(pen);
    painter->drawLine(rect.topRight(), rect.bottomRight());
    painter->restore();
}

QtComponentsTableDelegate::QtComponentsTableDelegate(QtComponentsTableView* view, QObject* parent)
    : QStyledItemDelegate(parent)
    , _view(view)
{
    Q_ASSERT(view);
}

QtComponentsTableDelegate::~QtComponentsTableDelegate()
{

}

QWidget* QtComponentsTableDelegate::createEditor(QWidget* parent, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    return QStyledItemDelegate::createEditor(parent, option, index);
}

void QtComponentsTableDelegate::setEditorData(QWidget* editor, const QModelIndex& index) const
{
    QStyledItemDelegate::setEditorData(editor, index);
}

void QtComponentsTableDelegate::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex& index) const
{
    QStyledItemDelegate::setModelData(editor, model, index);
}

void QtComponentsTableDelegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(index);
    editor->setGeometry(option.rect);
}

void QtComponentsTableDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    if (!index.isValid())
    {
        return;
    }
    painter->setRenderHint(QPainter::Antialiasing, true);
    if (option.state& QStyle::State_Selected)
    {
        painter->fillRect(option.rect, QBrush(QColor(240, 240, 240)));
    }

    Components::TableModelType role = static_cast<Components::TableModelType>(index.data(Qt::UserRole).toInt());

    switch (role)
    {
    case Components::Search:
        break;
    case Components::ID:
        break;
    case Components::Text:
        drawDefText(painter, option, index);
        break;
    case Components::PointText:
        drawPointText(painter, option, index);
        break;
    case Components::SuccessPointText:
        drawSuccessPointText(painter, option, index);
        break;
    case Components::ErrorPointText:
        drawErrorPointText(painter, option, index);
        break;
    case Components::ColorText:
        drawColorText(painter, option, index);
        break;
    case Components::InitBtn:
        drawInitButton(painter, option, index);
        break;
    case Components::UpdateBtn:
        drawUpdateButton(painter, option, index);
        break;
    case Components::Warn:
        drawDefText(painter, option, index);
        break;
    case Components::BanRun:
        drawDefText(painter, option, index);
        break;
    default:
        QStyledItemDelegate::paint(painter, option, index);
        break;
    }
}

QSize QtComponentsTableDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    return QStyledItemDelegate::sizeHint(option, index);
}

bool QtComponentsTableDelegate::editorEvent(QEvent *event, QAbstractItemModel *model, const QStyleOptionViewItem &option, const QModelIndex &index)
{
    emit clicked(index);
    //TODO: add item clicked event
    if (Components::InitBtn == index.data(Qt::UserRole).toInt())
    {
        emit initClicked(_view->modelData(index.row(),1).second);
    }
    if (Components::UpdateBtn == index.data(Qt::UserRole).toInt())
    {
        emit updateClicked(_view->modelData(index.row(), 1).second);
    }
    return QStyledItemDelegate::editorEvent(event, model, option, index);
}


void QtComponentsTableDelegate::drawDefText(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    painter->save();

    painter->setFont(index.data(Qt::FontRole).value<QFont>());

    QString text = index.data(Qt::EditRole).toString();

   QtComponentsTools::inst().splitText(text, option.rect.width(), painter->font());

    painter->setPen(QPen(QtComponentsTools::inst().getColor("defTextColor")));

    int h = QtComponentsTools::inst().fontMetrics(text).height() / 2;

    QPoint leftPoint = QPoint(option.rect.center() - QPoint((option.rect.width() / 2) - COUSTOM_LINEDIT_LEFT_MARGIN, -h + 4));

    painter->drawText(leftPoint, text);

    painter->restore();
}

void QtComponentsTableDelegate::drawPointText(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    painter->save();
    painter->setPen(QtComponentsTools::inst().getColor("pointTextColor"));
    painter->setBrush(QtComponentsTools::inst().getColor("pointTextColor"));
    painter->drawEllipse(option.rect.topLeft() + QPoint(COUSTOM_LINEDIT_LEFT_MARGIN, option.rect.height() / 2), 2, 2);
    painter->restore();

    painter->save();
    painter->setFont(index.data(Qt::FontRole).value<QFont>());
    painter->setPen(index.data(Qt::TextColorRole).value<QColor>());
    QString text = index.data(Qt::EditRole).toString();
    QtComponentsTools::inst().splitText(text, option.rect.width(), painter->font());
    painter->drawText(option.rect.topLeft() + QPoint(COUSTOM_LINEDIT_LEFT_MARGIN + 7, option.rect.height() / 2 + 5),
        text);
    painter->restore();
}

void QtComponentsTableDelegate::drawSuccessPointText(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    painter->save();
    painter->setPen(QtComponentsTools::inst().getColor("successPointTextColor"));
    painter->setBrush(QtComponentsTools::inst().getColor("successPointTextColor"));
    painter->drawEllipse(option.rect.topLeft() + QPoint(COUSTOM_LINEDIT_LEFT_MARGIN, option.rect.height() / 2), 2, 2);
    painter->restore();

    painter->save();
    painter->setFont(index.data(Qt::FontRole).value<QFont>());
    painter->setPen(QtComponentsTools::inst().getColor("successPointTextColor"));
    painter->drawText(option.rect.topLeft() + QPoint(COUSTOM_LINEDIT_LEFT_MARGIN + 7, option.rect.height() / 2 + 5),
        index.data(Qt::EditRole).toString());
    painter->restore();
}

void QtComponentsTableDelegate::drawErrorPointText(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    painter->save();
    painter->setPen(QtComponentsTools::inst().getColor("pointTextColor"));
    painter->setBrush(QtComponentsTools::inst().getColor("pointTextColor"));
    painter->drawEllipse(option.rect.topLeft() + QPoint(COUSTOM_LINEDIT_LEFT_MARGIN, option.rect.height() / 2), 2, 2);
    painter->restore();

    painter->save();
    painter->setFont(index.data(Qt::FontRole).value<QFont>());
    painter->setPen(QtComponentsTools::inst().getColor("pointTextColor"));
    painter->drawText(option.rect.topLeft() + QPoint(COUSTOM_LINEDIT_LEFT_MARGIN + 7, option.rect.height() / 2 + 5),
        index.data(Qt::EditRole).toString());
    painter->restore();
}

void QtComponentsTableDelegate::drawWarnIcon(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{

}

void QtComponentsTableDelegate::drawBanRunIcon(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{

}

void QtComponentsTableDelegate::drawColorText(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    painter->save();

    painter->setFont(index.data(Qt::FontRole).value<QFont>());

    painter->setPen(Qt::red);

    painter->drawText(option.rect.topLeft() + QPoint(COUSTOM_LINEDIT_LEFT_MARGIN, option.rect.height() / 2 + 5),
        index.data(Qt::EditRole).toString());

    painter->restore();
}

void QtComponentsTableDelegate::drawInitButton(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    painter->save();

    QPixmap initPixMap(QtComponentsTools::inst().pixmap(QString("table"),QString("init"),QSize(17,17)));
    QPoint iconPoint = QPoint(option.rect.topLeft() + QPoint(COUSTOM_LINEDIT_LEFT_MARGIN, option.rect.height() / 2 - 6));
    painter->drawImage(iconPoint, initPixMap.toImage());

    painter->restore();
}

void QtComponentsTableDelegate::drawUpdateButton(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    painter->save();

    QPixmap initPixMap(QtComponentsTools::inst().pixmap(QString("table"), QString("update"), QSize(17, 17)));
    QPoint iconPoint = QPoint(option.rect.topLeft() + QPoint(COUSTOM_LINEDIT_LEFT_MARGIN, option.rect.height() / 2 - 6));
    painter->drawImage(iconPoint, initPixMap.toImage());

    painter->restore();
}

QtComponentsTableModel::QtComponentsTableModel(QtComponentsTableView* view, QObject* parent)
    : QAbstractTableModel(parent)
    , _view(view)
{
    Q_ASSERT(view);
}

QtComponentsTableModel::~QtComponentsTableModel()
{

}

void QtComponentsTableModel::resetModel()
{
    beginResetModel();  
    endResetModel();
}

void QtComponentsTableModel::insertRow(QVector<Components::_TableModelPair>& rows)
{
    beginInsertRows(QModelIndex(), _view->modelData()->_modelData.size(), _view->modelData()->_modelData.size());
    _view->modelData()->_modelData.push_back(rows);
    endInsertRows();
}

void QtComponentsTableModel::removeRow(int row)
{
    beginRemoveRows(QModelIndex(), _view->modelData()->_modelData.size(), _view->modelData()->_modelData.size());
    _view->modelData()->_modelData.remove(row);
    endRemoveRows();
}

void QtComponentsTableModel::clearModel()
{
    _view->modelData()->_modelData.clear();
    resetModel();
    qobject_cast<QtComponentsHeaderView*>(_view->horizontalHeader())->setCheckable(Qt::Unchecked);
}

QVariant QtComponentsTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        return _view->headerLabel(section).second; 
    }
    return QAbstractTableModel::headerData(section, orientation, role);
}

bool QtComponentsTableModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    return QAbstractTableModel::setHeaderData(section,orientation,value,role);
}

int QtComponentsTableModel::rowCount(const QModelIndex &parent) const
{
    return _view->modelData()->_modelData.size();
}

int QtComponentsTableModel::columnCount(const QModelIndex &parent) const
{
    return _view->modelData()->_labels.size();
}

QVariant QtComponentsTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || _view->modelData()->_modelData.isEmpty())
    {
        return QVariant();
    }

    if (index.row() > rowCount(index) || index.column() > columnCount(index))
    {
        return QVariant();
    }

    Components::TableModelType type = _view->modelData()->_modelData[index.row()][index.column()].first;

    switch (role)
    {
    case Qt::ToolTipRole:
    case Qt::DisplayRole:
    case Qt::EditRole:
    {
        return _view->modelData(index.row(), index.column()).second;
    }
    case Qt::UserRole:
    {
        return (int)_view->modelData(index.row(), index.column()).first;
    }
    case Qt::TextAlignmentRole:
    {
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
    }
    case Qt::FontRole:
    {
        QFont textFont;
        textFont.setPixelSize(12);
        return textFont;
    }
    case Qt::TextColorRole:
    {
        if (Components::ColorText == type)
        {
            return QtComponentsTools::inst().getColor("errorColor");
        }
        else
        {
            return QtComponentsTools::inst().getColor("successColor");
        }
    }
    case Qt::CheckStateRole:
    {
        if (Components::Freeze == type)
        {
            return Qt::Unchecked;
        }
        return _view->modelData(index.row(), index.column()).first;
    }
    default:
        break;
    }
    return QVariant();
}

bool QtComponentsTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
    {
        return false;
    }
    switch (role)
    {
    case Qt::DisplayRole:
    case Qt::EditRole:
    {
        //TODO:lock edit WT0026
        //_view->modelData()->_modelData[index.row()][index.column()].second = value.toString();
    }
    break;
    case Qt::UserRole:
    {
        //TODO:Lock key WT0026
        //_view->modelData()->_modelData[index.row()][index.column()].first = static_cast<Components::TableModelType>(value.toInt());
    }
    break;
    case Qt::CheckStateRole:
    {
        _view->modelData()->_modelData[index.row()][index.column()].first = static_cast<Components::TableModelType>(value.toInt());
        if (_view->modelData()->checkedSize() > 0)
        {
            emit sectionCheckable(Qt::Checked);
        }
        else
        {
            emit sectionCheckable(Qt::Unchecked);
        }
    }
    break;
    default:
        break;
    }
    return true;
}

bool QtComponentsTableModel::removeRows(int row, int count, const QModelIndex &parent)
{
    return QAbstractTableModel::removeRows(row, count, parent);
}

bool QtComponentsTableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    return QAbstractTableModel::insertRows(row, count, parent);
}

Qt::ItemFlags QtComponentsTableModel::flags(const QModelIndex &index) const
{
    Components::TableModelType role = static_cast<Components::TableModelType>(index.data(Qt::UserRole).toInt());

    Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    if (Components::UnChecked == role ||
        Components::Checked == role
        )
    {
        return flags |= Qt::ItemIsUserCheckable;
    }
    if (Components::Search == role ||
        Components::ID == role ||
        Components::Freeze == role
        )
    {
        return flags |= Qt::NoItemFlags;
    }
    return flags |= Qt::ItemIsEditable;
}
