#include "enemigo_2.h"
#include <time.h>

//Constructores
enemigo_2::enemigo_2(){
    estado_inicial();
}

enemigo_2::enemigo_2(bool posicionInicial)
{
    posF2=posicionInicial;
    estado_inicial();
}

enemigo_2::enemigo_2(bool posicionInicial, int vidas)
{
    posF2=posicionInicial;
    vidastotales=vidas;
    estado_inicial();
}




// Propiedades
int enemigo_2::obtener_total_vidas(){
    return vidastotales;
}



//Destructores
enemigo_2::~enemigo_2()
{
    delete t_caminar;
}


//Metodos
void enemigo_2::estado_inicial(){
    t_caminar = new QTimer;
    t_mostrar_muerte = new QTimer;

    configuracion(enemigo2,true,0,0,128,128);

    CAMbloque(4);

    // Conectar timers con los slots
    connect(t_mostrar_muerte, SIGNAL (timeout()),this, SLOT(movimientoX()));
    connect(t_caminar, SIGNAL (timeout()),this, SLOT(escena()));
    // Establece la dirección inical

    // Iniciar movimiento
    setPos(x()+890,y()+358.4);


    calculo = new operaciones (x(),y(),0,0,70000);
    t_caminar->start(200);
    t_mostrar_muerte->start(10);
    movimientoX();

}

void enemigo_2::cambioE()
{
    select_bloc(cambioE2_sprite*48,0,128,128,false,48*1.6,48*1.2,!posF2);
    if(cambioE2_sprite < cambioE2_spriteD)
        cambioE2_sprite++;

    else
        cambioE2_sprite=0;
    if(pausa2){
        if(posF2){
            setPos(x()+10,y());
            if(x() >= ((16 * (largo-4)) * scale_sprite)){
                giro2 = false;
                posF2 = !posF2;
            }
        } else {
            setPos(x()-10,y());
            if(x() <= (((largo-27)/2) * scale_sprite)){
                giro2 = true;
                posF2 = !posF2;
            }
        }
    }
}

void enemigo_2::disparoE()
{
    if(cambioE2_sprite==cambioE2_spriteD and pausa2==0)
    {
        configuracion(enemigo2,true,0,8,432,40);
        pausa2=1;
        cambioE2_spriteD=3;
        cambioE2_sprite=0;

    }
    else if (cambioE2_sprite==cambioE2_spriteD and pausa2==1)
    {
        configuracion(enemigo2D,true,0,8,432,40);
        pausa2=2;
        cambioE2_spriteD=3;
        cambioE2_sprite=0;

    }
    else if(cambioE2_sprite==cambioE2_spriteD and pausa2==1)
    {
        pausa2=0;
        cambioE2_spriteD=3;
        cambioE2_sprite=0;

    }
    cambioE();
}
void enemigo_2::recibir_disparo(){
    vidastotales--;
    if(vidastotales == 0){
        delete t_caminar;
        configuracion(enemigo2M,true,0,0,288,48);
        cambioE2_sprite = 0;
        t_mostrar_muerte -> start(200);
    }
}

void enemigo_2::terminar(){
    muerte();
}

void enemigo_2::muerte(){

}
void enemigo_2::movimientoX()
{
    calculo->setVX(-20);
    calculo->actualizarX(0.06667);

    setPos(calculo->getPX(),y());

}
void enemigo_2::direccion()
{
    animacion->start(100);
    cantidad_sprint=5;
    if(vuelta)
    {
        vuelta=0;
        calculo->setAX(-20);
    }
    else
    {
        vuelta=1;
        calculo->setAX(20);
    }
    cargaCorrer();
    velocidad=-velocidad;
}
void enemigo_2::cargaCorrer()
{

    if(vuelta)
    {
        configuracion(enemigo2,true,0,0,128,128);

    }
    else
    {
        configuracion(enemigo2,true,0,0,128,128);


        signo=0;
    }


}
bool enemigo_2::getvuelta()
{
    return vuelta ;
}

void enemigo_2::escena()
{
    select_bloc(0,0,128,128,false,scale_sprite*x_jugador,2*y_jugador);
    if(vuelta==1)
    {
        if(cambio_sprite<cantidad_sprint)
        {
            cambio_sprite++;
        }
        else
        {
            cambio_sprite=0;
        }
    }
    else
    {
        if(cambio_sprite > 0)
        {
            cambio_sprite--;
        }
        else
        {
            cambio_sprite=cantidad_sprint;
        }
    }
}
