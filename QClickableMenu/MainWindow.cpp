#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include "ClickableMenuFilter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create menu and install event filter
    mainMenu = new QMenu(this);
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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mainMenu->exec(QCursor::pos());
}
