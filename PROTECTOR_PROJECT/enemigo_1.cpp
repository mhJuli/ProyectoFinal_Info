#include "enemigo_1.h"
#include <time.h>


// Constructores
enemigo_1::enemigo_1(){
    estado_inicial();
}

enemigo_1::enemigo_1(bool posicionInicial)
{
    posF = posicionInicial;
    estado_inicial();
}

enemigo_1::enemigo_1(bool posicionInicial, int vidas){
    posF = posicionInicial;
    totalVidas = vidas;
    estado_inicial();
}

//Destructores
enemigo_1::~enemigo_1()
{
    delete t_caminar;
}


// Propiedades
int enemigo_1::obtener_total_vidas(){
    return totalVidas;
}

// Metodos
void enemigo_1::estado_inicial(){
    t_caminar = new QTimer;
    t_mostrar_muerte = new QTimer;
    configuracion(enemigo1,true,0,0,128,128);

    CAMbloque(4);

    // Conectar timers con los slots
    connect(t_mostrar_muerte, SIGNAL (timeout()),this, SLOT(movimientoX()));
    connect(t_caminar, SIGNAL (timeout()),this, SLOT(escena()));
    // Establece la dirección inical

    // Iniciar movimiento
    setPos(x()+30,y()+358.4);


    calculo = new operaciones (x(),y(),0,0,70000);
    t_caminar->start(300);
    t_mostrar_muerte->start(10);
    movimientoX();



}

void enemigo_1::muerte(){

}

void enemigo_1::cambioE1()
{
    select_bloc(128,0,512,128,false,48*1.6,48*1.2,!posF);
    if(cambioE1_sprite > cambioE1_spriteD)
        cambioE1_sprite--;
    else
        cambioE1_sprite=cantidad_sprint;
    if(pausa){
        if(posF){
            setPos(x()+10,y());
            if(x() >= ((16 * (largo-4)) * scale_sprite)){
                giro = false;
                posF = !posF;
            }
        } else {
            setPos(x()-10,y());
            if(x() <= (((largo-27)/2) * scale_sprite)){
                giro = true;
                posF = !posF;
            }
        }
    }
}

void enemigo_1::disparo()
{
    if(cambioE1_sprite == cambioE1_spriteD){
        if(pausa){
            configuracion(enemigo1D,true,0,0,128,128);

        }
        else
            configuracion(enemigo1,true,0,0,128,128);
        pausa = !pausa;
        cambioE1_spriteD = 3;
        cambioE1_sprite = 0;
    }
    cambioE1();
}

void enemigo_1::recibir_disparo(){
    totalVidas--;
    if(totalVidas == 0){
        muerte();
    }
}

void enemigo_1::terminar(){
    muerte();
}
void enemigo_1::escena()
{
    select_bloc(128,0,512,128,false,scale_sprite*x_jugador,2*y_jugador);
    if(vuelta)
    {
        if(cambio_sprit<cantidad_sprint)
        {
            cambio_sprit++;
        }
        else
        {
            cambio_sprit=0;
        }
    }
    else
    {
        if(cambio_sprit > 0)
        {
            cambio_sprit--;
        }
        else
        {
            cambio_sprit=cantidad_sprint;
        }
    }
}

void enemigo_1::movimientoX()
{
    calculo->setVX(20);
    calculo->actualizarX(0.06667);

    setPos(calculo->getPX(),y());

}

void enemigo_1::direccion()
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
void enemigo_1::cargaCorrer()
{

    pospistolaX=(tam_brazo_Descanso*4)/5;
    pospistolaY=pospistolaX;

    if(vuelta)
    {
        configuracion(enemigo1,true,0,0,128,128);




    }
    else
    {
        configuracion(enemigo1,true,0,0,128,128);


        signo=0;
    }


}
bool enemigo_1::getvuelta()
{
    return vuelta ;
}
