#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include <QKeyEvent>
#include <stdlib.h>
#include "bloques.h"
#include <cstdlib>
#include <time.h>
#include "jugador.h"
#include "polvora.h"
#include "objetivo.h"
#include "enemigo_1.h"
#include "enemigo_2.h"
#include "enemigo_3.h"
#include "operaciones.h"
#include "base.h"


class juego : public QGraphicsScene
{
Q_OBJECT
public:
    //Constructores
    juego();

    //Destructores
    ~juego();

    QTimer *TimerGlobal;

    //Metodos
    void mapa();
    void keyPressEvent(QKeyEvent *i) override;
    operaciones *calculo;


private:
    void detener();
    void iniciar();
    void mostrar_puntaje();
    void volver_a_iniciar();
    void MoverEnemigos();
    int select_bloc(int i, int j);
    bool aleatorio(),permisoO=true,estado_invencible=true,prendido=true;
    void randomItem();
    void agregarAleatorioItem();


    unsigned dispa=0;
    unsigned dronesEnemigos=0,dronesbalas=0,limiteDrones;
    unsigned nivel_activo = 1;
    unsigned por_nivel=100;
    unsigned total_enemigos1 = 0;
    unsigned total_enemigos2 = 0;
    unsigned total_enemigos3 = 0;
    unsigned puntaje_total = 0;
    float p = 0.3;
    objetivo *trampolin;
    bloques *bl[largo][2];
    base *fondo;
    base *nivel;
    base *puntaje;
    base *nivel_etiqueta;
    jugador *personaje;
    enemigo_1 *enemigo;
    enemigo_2 *enemigo2;
    enemigo_3 *enemigo3;

    QGraphicsTextItem* puntaje_pad;

    int t_enemigos = 6000;
    int e1_vidas = 3,Cparpadeo=10,Iparpadeo=0;
    int n=1;

    QTimer *caida
    , *timer ,*t_disparo_protagonista,
    *movimiento_drones,
    *Disparo_enemigos,
    *t_cargar_enemigos,
    *invencible;

    QVector<polvora*> cartuchoprota;
    QVector<polvora*> cartuchoEnemigos;
    QList<QGraphicsItem *> items_totales;

public slots:

     void iniciar_juego();

    //movimiento personaje
    void movimien();

    // fisicas disparos
    void disparo_protagonista();
    void disparoEnemigos();


    // inteligencia enemigos
    void cargar_enemigos();
    void parpadeo();
    void salir();

    void Actualizar();
    void colision();

};

#endif // JUEGO_H
