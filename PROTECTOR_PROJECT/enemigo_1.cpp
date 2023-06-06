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
    connect(t_caminar, SIGNAL (timeout()),this, SLOT(escena()));
    connect(t_avance, SIGNAL(timeout()), this, SLOT(movimientoX()));

    // Iniciar movimiento
    setPos(x()+10,y()+358.4);
    calculo= new operaciones (x(),y(),0,0,70000);
    t_avance->start(200);

}

void enemigo_1::muerte(){

}

void enemigo_1::cambioE1()
{
    select_bloc(cambioE1_sprite*48,0,128,120,false,48*1.6,48*1.2,!posF);
    if(cambioE1_sprite < cambioE1_spriteD)
        cambioE1_sprite++;
    else
        cambioE1_sprite=0;
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
            configuracion(enemigo1D,true,0,8,432,40);

        }
        else
            configuracion(enemigo1,true,0,8,432,40);
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

void enemigo_1::notificacion_enemigo( int x, int y){

    // Crear instancia del enemigo y establecer su posición
    enemigo_1 *enemigo1 = new enemigo_1();
    // Mostrar al enemigo en la escena en la parte derecha de la pantalla
    int pantalla_ancho = largo * 16 * scale_sprite;
    int pantalla_alto = ancho * 16 * scale_sprite;
    int enemigo_ancho = enemigo1->boundingRect().width();
    int enemigo_alto = enemigo1->boundingRect().height();
    int enemigo_x = pantalla_ancho - enemigo_ancho;
    int enemigo_y = (pantalla_alto - enemigo_alto) / 2;
    enemigo1->setPos(enemigo_x, enemigo_y);


    // Agregar el enemigo a la escena

    }
void enemigo_1::escena()
{
    select_bloc(0,0,128,128,false,scale_sprite*x_jugador,2*y_jugador);
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
    if(x()>0 and x()+x_jugador*scale_sprite < (scale_sprite*16*largo))
        calculo->actualizarX(0.06667);
    if( x()<0)
    {
        calculo->setPX(1);
        calculo->setAX(25*scale_sprite);
    }
    if(x()+x_jugador*scale_sprite > (scale_sprite*16*largo))
    {
        calculo->setPX((scale_sprite*16*largo)-x_jugador*scale_sprite-1);
        calculo->setAX(-1*25*scale_sprite);
    }

    if((calculo->getVX() > velocidad) and ( calculo->getAX() > 0 ) )
    {
        calculo->setAX(0);
        calculo->setVX(velocidad);
    }
    else if( (calculo->getVX() < velocidad) and (calculo->getAX() < 0)  )
    {
        calculo->setAX(0);
        calculo->setVX(velocidad);

    }


    setPos(calculo->getPX(),y());


}
