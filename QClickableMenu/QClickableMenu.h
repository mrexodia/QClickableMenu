#pragma once

#include <QMenu>

class QClickableMenu : public QMenu
{
    Q_OBJECT
public:
    explicit QClickableMenu(QWidget *parent = Q_NULLPTR);
    QClickableMenu(const QString &title, QWidget *parent = Q_NULLPTR);

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* e) override;
};
