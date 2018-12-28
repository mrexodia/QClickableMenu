#include "ClickableMenuFilter.h"
#include <QEvent>
#include <QMouseEvent>
#include <QMenu>

ClickableMenuFilter::ClickableMenuFilter(QObject* parent)
    : QObject(parent)
{
}

bool ClickableMenuFilter::eventFilter(QObject* watched, QEvent* event)
{
    if(event->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);
        if(mouseEvent->button() == Qt::LeftButton)
        {
            QMenu* menu = qobject_cast<QMenu*>(watched);
            QAction* action = menu->actionAt(mouseEvent->pos());
            if(action && action->menu())
            {
                action->trigger();
                return true;
            }
        }
    }
    return QObject::eventFilter(watched, event);
}
