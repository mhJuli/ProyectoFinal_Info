#ifndef ENEMIGO_1_H
#define ENEMIGO_1_H

#include "base.h"
#include "operaciones.h"

class enemigo_1:public QObject , public base
{
Q_OBJECT

public:
    // Constructores
    enemigo_1();
    enemigo_1(bool posicionInicial);
    enemigo_1(bool posicionInicial, int vidas);



    // Deestructor
    ~enemigo_1();

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

    QPointF Velocidad;


private:

    QString enemigo1D= ":/sprites/craftpix-net-413273-free-ghost-pixel-art-sprite-sheets/Gotoku/Attack_1.png";
    QString enemigo1= ":/sprites/craftpix-net-413273-free-ghost-pixel-art-sprite-sheets/Gotoku/Run.png";
    QString enemigo1I=":/sprites/craftpix-net-413273-free-ghost-pixel-art-sprite-sheets/Gotoku/Idle.png";
    QString enemigo1M = ":/sprites/craftpix-net-413273-free-ghost-pixel-art-sprite-sheets/Gotoku/Dead.png";
    QString enemigo1H = ":/sprites/craftpix-net-413273-free-ghost-pixel-art-sprite-sheets/Gotoku/Hurt.png";
    QTimer *t_caminar;
    QTimer *t_mostrar_muerte;
    QTimer *animacion;
    bool dobl=false;
    int cambioE1_sprite=0;
    int cambioE1_spriteD=0;
    int cambioE1_spriteI=0;
    bool giro=true;
    bool pausa=true;
    bool posF=false;
    int totalVidas=3;
    int short cambio_sprit=0,cantidad_sprint=3,velocidad=scale_sprite*(23/2),posmanoX,posmanoY,pospistolaX,pospistolaY,signo;
    bool vuelta=1;
    enemigo_1 *enemigo;




private slots:
    void disparo();
    void cambioE1();
    void muerte();
    void escena();
    void movimientoX();

};

#endif // ENEMIGO_1_H
