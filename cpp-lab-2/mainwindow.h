//Dyrektywy preprocesora
//Wstepne przygotowanie kodu
//Preprocessing
//Przechowywanie deklaracji. Ten plik jest wciagamy i zaczynymy kompilacje
//Dyrektywy zaczynajace sie do # to instrukcje dla preporcesora

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//Przestrzen nazw. Grupowanie nazw w pewne w podprzestrzenie
//Analogia do pakietów
//Grupowanie klas
//Trzeba ustalic systematyna nazw namespacow, podobnie jak w pakietach

namespace Ui {
class MainWindow;
}

//deklaracja klasy
//: QMqinWindow tak jak extend w javie
class MainWindow : public QMainWindow
{
//znacznik ktory podczas kompilacji jest sprawdzaony czy wystepuje w kodzie
// kolejny etap przed kompilacja

    Q_OBJECT

//deklaracja metod publicznych
//konstruktow
public:
    //parent jest obiektem nadrzednym dla obiektu danej klasy
    //okienko ma nadrzedny obiekt ktory jest ndrzedny nad okienkiem glownym
    //jak zabiejmy parenat to zabijemy okienko i buttony
    explicit MainWindow(QWidget *parent = 0);
    //destruktor. wywolywany jest wtedy kiedy obiekt jest niszczony
    //
    ~MainWindow();
//deklaracja metod prywatnych

private slots:
    void on_actionCut_triggered();

    void on_actionPaste_triggered();

    void on_actionCopy_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionOpen_triggered();

private:
    //ui jest wskaznikiem do Mainwindom w namespace Ui
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
