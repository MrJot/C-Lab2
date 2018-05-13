//Dolaczenie zawartosci dla danego pliku
//Jak kompilacja bedzie to nie bedzie plikow tylko wklejona ich zawartosc

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>

//Nazwa klasy, konstruktora

MainWindow::MainWindow(QWidget *parent) :
    //sekcja inicjalizacyjna konstruktora
    //etap 1
    QMainWindow(parent),
    //utworzenie instancji glownego okna
    //wkaznik do mijsca na stercie na glowne okno
    ui(new Ui::MainWindow)
  //etap 2
  //wywolanie konstruktora klasy nadrzednej
  //(super) java
  //setupUi sklada nam okienko
  //wskaznik ui wywoluje metode setupUi

  // C c1 - obiekt jest na stosie
  // new c2 - obiekt trafia na strerte (tutaj kontrolujemy czas zycia obiektu, mamy na to wplyw)
  //zmienna to nzawana komorka w pamieci
  //R A I I - POCZYTAC O TYM (resaurce acousition)

  //https://codeshare.io/aVpXM3
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
}
//destrukcja to nie tylko uwalnianie pamiecie, ale moze tez sluzyc do wykonania pewnych akcji.
MainWindow::~MainWindow()
{
    delete ui;
}

//wykonanie operacji usuniecie tekstu i skopiowania do schowka
void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open the file");

    QFile file(fileName);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "..", "File has not been opened");
        return;
    }

    QTextStream in(&file);
    ui->textEdit->setText(in.readAll());

    file.close();
}
