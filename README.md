# QClickableMenu

This is a very simple project to support the `triggered` signal of the `QMenu::menuAction` if you click on the QMenu.

![screenshot](https://i.imgur.com/rtuKaR4.gif)

## Implementation

It has been implemented as an [event filter](http://doc.qt.io/archives/qt-4.8/eventsandfilters.html#event-filters) for `QMenu`. Here is a relevant snippet:

```c++
// Create menu and install event filter
QMenu* mainMenu = new QMenu(this);
mainMenu->installEventFilter(new ClickableMenuFilter(mainMenu));

// Add some children for show
mainMenu->addAction("action1");
QMenu* childMenu = new QMenu("childMenu", this);
connect(childMenu->menuAction(), &QAction::triggered, [this]()
{
    QMessageBox::information(this, "triggered", "childMenu");
});
childMenu->addAction("child1");
childMenu->addAction("child2");
mainMenu->addMenu(childMenu);
mainMenu->addAction("action2");
```

## Links

https://stackoverflow.com/questions/22197496/how-to-perform-action-on-clicking-a-qmenu-object-only