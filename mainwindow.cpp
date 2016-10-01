#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_plasmaCacheButton_clicked()
{
    QProcess process;
    process.start("kquitapp", QStringList() << "plasmashell");
    process.waitForFinished();
    QStringList rm_args;
    rm_args << "-R";
    rm_args << "~/.cache/*.kcache";
    rm_args << "~/.cache/plasma*";
    process.start("rm", rm_args );
    process.waitForFinished();
    process.start("kstart", QStringList() << "plasmashell");
    process.waitForFinished();
    return;
}
