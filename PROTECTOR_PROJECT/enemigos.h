#ifndef ENEMIGOS_H
#define ENEMIGOS_H


#include "base.h"

class Enemigos : public QObject, public base {
    Q_OBJECT

public:
    // Propiedades
    virtual int obtener_total_vidas();

    // Métodos
    virtual void recibir_disparo();
    virtual void terminar();

protected:
    // Propiedades
    QTimer* t_caminar;
    QTimer* t_mostrar_muerte;
    int cambio_sprite=0;
    int cambio_spriteD=0;
    int cambio_spriteI=0;
    bool giro=true;
    bool pausa;
    bool posF;
    int vidastotales=3;

protected slots:
    // Métodos protegidos
    virtual void cambioE();
    virtual void disparo();
    virtual void muerte();
};

class Enemigo1 : public Enemigos {
    Q_OBJECT

public:
    // Constructores
    Enemigo1();
    Enemigo1(bool posicionInicial, int vidas);

    Enemigo1(bool posicionInicial);

    // Propiedades
    int obtener_total_vidas() override;

    // Metodos
    void recibir_disparo() override;
    void terminar() override;


    //Destructor
    ~Enemigo1();

private:
    QString enemigo1D= ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Attack.png";
    QString enemigo1= ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Walk.png";
    QString enemigo1I=":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Idle.png";
    QString enemigo1M = ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Death.png";
    QString enemigo1H = ":/sprites/enemigos robots y drones con armas y animaciones sprites/2/Hurt.png";

    bool dobl=false;
    bool pausa=true;
    bool posF=false;

     void estado_inicial();

protected slots:
    // Métodos protegidos
    void cambioE() override;
    void disparo() override;
    void muerte() override;
};

class Enemigo2 : public Enemigos {
    Q_OBJECT

public:
    // Constructores
    Enemigo2();
    Enemigo2(bool posicionInicial);
    Enemigo2(bool posicionInicial, int vidas);

    // Propiedades
    int obtener_total_vidas() override;

    // Metodos
    void recibir_disparo() override;
    void terminar() override;

    //Destructor
    ~Enemigo2();

private:
    QString enemigo2D=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Attack.png";
    QString enemigo2=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Walk.png";
    QString enemigo2M="";
    QString enemigo_quieto=":/sprites/enemigos robots y drones con armas y animaciones sprites/6/Idle.png";

    unsigned pausa2=1;
    bool posF2=false;
    int punto2=85;
    int punto_contrario2=2;
     void estado_inicial();

protected slots:
    // Métodos protegidos
    void cambioE() override;
    void disparo() override;
    void muerte() override;
};

class Enemigo3 : public Enemigos {
    Q_OBJECT

public:
    // Constructores
    Enemigo3();
    Enemigo3(bool posicionInicial);
    Enemigo3(bool posicionInicial, int vidas);

    // Propiedades
    int obtener_total_vidas() override;

    // Metodos
    void recibir_disparo() override;
    void terminar() override;

    //Destructor
    ~Enemigo3();

private:
    QString enemigo3D=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Attack.png";
    QString enemigo3=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Walk.png";
    QString enemigo_quieto=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Idle.png" ;
    QString enemigo_muerte=":/sprites/enemigos robots y drones con armas y animaciones sprites/5/Death.png";
    int pausa3=0;
    bool posF3=false;
    int punto3=85;
    int punto_contrario3=2;
    void estado_inicial();

protected slots:
    // Métodos protegidos
    void cambioE() override;
    void disparo() override;
    void muerte() override;
};


#endif // ENEMIGOS_H
