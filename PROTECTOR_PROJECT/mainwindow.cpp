#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "button.h"
#include "base.h"
#include "enemigo_1.h"

//Constructores
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setup_window();
    menu_inicio();
}


//Metodos
void MainWindow::setup_window()
{
    setWindowTitle("PROTECTOR");
    setMaximumSize(16*scale_sprite*largo+2,16*scale_sprite*ancho+2);
    setMinimumSize(16*scale_sprite*largo+2,16*scale_sprite*ancho+2);
}

void MainWindow::menu_inicio(){
    scene = new juego;
    ui->graphicsView->setGeometry(0,0,16*scale_sprite*largo+2,16*scale_sprite*ancho+2);
    ui->graphicsView->setScene(scene);

    logo= new base;
    logo->configuracion(":/sprites/interfaz/TITLE_2-removebg-preview.png");
    logo->select_bloc(0,0,512,96,false,512,96);
    int txPos = this->width()/2 - 256;
    int tyPos = 150;
    logo-> setPos(txPos,tyPos);
    //scene->addItem(logo);

    Button* playButton = new Button(QString("Jugar"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(iniciar_juego()));
    scene->addItem(playButton);

    Button* quitButton = new Button(QString("Salir"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void MainWindow::setup_juego()
{
    scene = new juego;
    scene->iniciar_juego();
    ui->graphicsView->setGeometry(0,0,16*scale_sprite*largo+2,16*scale_sprite*ancho+2);
    ui->graphicsView->setScene(scene);
}

void MainWindow::iniciar_juego(){
    //delete scene;
    setup_juego();
}

//Destructores
MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}

void MainWindow::removerFuera(QGraphicsItem* enemigo)
{
    QRectF sceneRect = scene->sceneRect(); // Obtener los límites de la escena
    QRectF itemRect = enemigo->sceneBoundingRect(); // Obtener el rectángulo del objeto en la escena

    if (!sceneRect.contains(itemRect)) {
        scene->removeItem(enemigo); // Remover el objeto de la escena
        delete enemigo; // Liberar la memoria del objeto si es necesario
    }
}

void MainWindow::removerFuera2(QGraphicsItem* enemigoDos)
{
    QRectF sceneRect = scene->sceneRect(); // Obtener los límites de la escena
    QRectF itemRect = enemigoDos->sceneBoundingRect(); // Obtener el rectángulo del objeto en la escena

    if (!sceneRect.contains(itemRect)) {
        scene->removeItem(enemigoDos); // Remover el objeto de la escena
        delete enemigoDos; // Liberar la memoria del objeto si es necesario
    }
}
