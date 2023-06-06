#ifndef ENEMIGO_2_H
#define ENEMIGO_2_H

#include "base.h"
#include "operaciones.h"

class enemigo_2:public QObject , public base
{
Q_OBJECT

public:
    //constructores
    enemigo_2();
    enemigo_2(bool posicionInicial);
    enemigo_2(bool posicionInicial,int vidas);

    ~enemigo_2();

    // Propiedades
    int obtener_total_vidas();

    // Metodos
    void recibir_disparo();
    void terminar();
    void estado_inicial();
    void direccion();
    void cargaCorrer();
    bool getvuelta();
    operaciones *calculo;

private:
    QString enemigo2D= ":/sprites/craftpix-net-413273-free-ghost-pixel-art-sprite-sheets/Onre/Attack_1.png";
    QString enemigo2= ":/sprites/craftpix-net-413273-free-ghost-pixel-art-sprite-sheets/Onre/RunI.png";
    QString enemigo2I=":/sprites/craftpix-net-413273-free-ghost-pixel-art-sprite-sheets/Onre/Idle.png";
    QString enemigo2M = ":/sprites/craftpix-net-413273-free-ghost-pixel-art-sprite-sheets/Onre/Dead.png";
    QString enemigo2H = ":/sprites/craftpix-net-413273-free-ghost-pixel-art-sprite-sheets/Onre/Hurt.png";
    QTimer *t_caminar;
    QTimer *t_mostrar_muerte;
    QTimer *animacion;
    bool dobl=false;
    int cambioE2_sprite=0;
    int cambioE2_spriteD=0;
    int cambioE1_spriteI=0;
    bool giro2=true;
    bool pausa2=true;
    bool posF2=false;
    int vidastotales=3;
    int short cambio_sprite=0,cantidad_sprint=3,velocidad=scale_sprite*(23/2),signo;
    bool vuelta=1;
    enemigo_2 *enemigoDos;

private slots:
    void disparoE();
    void cambioE();
    void muerte();
    void escena();
    void movimientoX();
};

#endif // ENEMIGO_2_H
