//Dolaczenie zawartosci dla danego pliku
//Jak kompilacja bedzie to nie bedzie plikow tylko wklejona ich zawartosc

#include "mainwindow.h"
#include "ui_mainwindow.h"

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

{
    ui->setupUi(this);
}
//destrukcja to nie tylko uwalnianie pamiecie, ale moze tez sluzyc do wykonania pewnych akcji.
MainWindow::~MainWindow()
{
    delete ui;
}
