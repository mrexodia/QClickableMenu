#include "MainWindow.h"
#include <QApplication>
#include <QProxyStyle>

// Delay menu popup for testing
class Style : public QProxyStyle
{
public:
    Style(QStyle *baseStyle)
        : QProxyStyle(baseStyle)
    {
    }

    int styleHint(QStyle::StyleHint hint, const QStyleOption *option = 0, const QWidget *widget = 0, QStyleHintReturn *returnData = 0) const
    {
        return hint == QStyle::SH_Menu_SubMenuPopupDelay ? 1000 : QProxyStyle::styleHint(hint, option, widget, returnData);
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle(new Style(a.style()));
    MainWindow w;
    w.show();

    return a.exec();
}
