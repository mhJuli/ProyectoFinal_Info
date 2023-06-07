#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bloques.h"
#include "macros.h"
#include "juego.h"
#include "base.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    //Constructor
    MainWindow(QWidget *parent = nullptr);

    //Metodos
    void setup_window();
    void setup_juego();
    void menu_inicio();
    void removerFuera(QGraphicsItem* enemigo);
    void removerFuera2(QGraphicsItem* enemigoDos);
    //Destructor
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    juego *scene;
    base *logo;
    enemigo_1 *enemigo;
    enemigo_1 *enemigoDos;

public slots:
    void iniciar_juego();
};
#endif // MAINWINDOW_H
