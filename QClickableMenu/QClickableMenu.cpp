#include "QClickableMenu.h"
#include <QMouseEvent>

QClickableMenu::QClickableMenu(QWidget *parent)
    : QMenu(parent)
{
    connect(menuAction(), SIGNAL(triggered(bool)), this, SIGNAL(clicked()));
}

QClickableMenu::QClickableMenu(const QString &title, QWidget *parent)
    : QMenu(title, parent)
{
    connect(menuAction(), SIGNAL(triggered(bool)), this, SIGNAL(clicked()));
}

void QClickableMenu::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        auto pressedAction = actionAt(e->pos());
        if(pressedAction && pressedAction->menu())
        {
            pressedAction->trigger();
            return;
        }
    }
    QMenu::mousePressEvent(e);
}
