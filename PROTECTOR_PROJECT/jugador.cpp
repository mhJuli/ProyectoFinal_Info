#include "jugador.h"

//Constructores
jugador::jugador()
{
    animacion=new QTimer;
    andar=new QTimer;
    secuencia_muerte=new QTimer;

    mano=new base;
    pistola=new base;

    configuracion(punk,true,0,0,128,128);

    CAMbloque(2);
    connect(animacion, SIGNAL (timeout()),this, SLOT(escena()));
    connect(andar, SIGNAL (timeout()),this, SLOT(movimientoX()));
    connect(secuencia_muerte, SIGNAL (timeout()),this, SLOT(muerte()));


    setPos(448,358.4);
    calculo= new operaciones (x(),y(),0,0,70000);
    //calculo->Maceleracion(40);

    mano->setPos(x()+20,y()+14);
    mano->configuracion(manoPunk+"2"+png);
    pistola->configuracion(armaB+"2"+png);

    animacion->start(100);
    andar->start(10);
}

//Destructores
jugador::~jugador()
{
    delete animacion;
    delete calculo;
    delete andar;
    delete secuencia_muerte;
    //delete mano;
    //delete pistola;

}


//Metodos
void jugador::direccion()
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

void jugador::movimientoY()
{
    calculo->actualizarY((0.06667));
    setPos(x(),calculo->getPY());
}


void jugador::movimientoX()
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
    mano->setPos(x()+posmanoX,y()+posmanoY);
    pistola->setPos(x()+posmanoX+(signo*pospistolaX),y()+posmanoY+pospistolaY);



}

void jugador::muerte(){
    select_bloc(cambio_sprit*48,0,48,48,false,48*1.6,48*1.2,vuelta);
    cambio_sprit++;
    if(cambio_sprit == 3){
        delete secuencia_muerte;
    }
}

void jugador::saltar()
{
    cantidad_sprint=3;
    animacion->start(150);
    calculo->setPY(y());
    if(vuelta)
    {
        configuracion(salto+png,true,0,0,128,128);
    }
    else
    {
        configuracion(salto+reves+png,true,0,0,128,128);
    }
    cambio_sprit=0;

}

void jugador::cargaCorrer()
{
    mano->configuracion(manoPunk+"2"+png);
    pistola->configuracion(armaB+"2"+png);
    pospistolaX=(tam_brazo_Descanso*4)/5;
    pospistolaY=pospistolaX;

    if(vuelta)
    {
        configuracion(correr+png,true,0,0,128,128);

        mano->select_bloc(12,12,13,13,false,tam_brazo_Descanso*scale_sprite,tam_brazo_Descanso*scale_sprite);

        pistola->select_bloc(0,0,12,12,false,(tam_brazo_Descanso*scale_sprite*4)/5,(tam_brazo_Descanso*scale_sprite*4)/5);
        signo=1;
        posmanoY=9*scale_sprite;
        posmanoX=17*scale_sprite;



    }
    else
    {
        configuracion(correr+reves+png,true,0,0,128,128);
        mano->select_bloc(12,12,13,13,false,tam_brazo_Descanso*scale_sprite,tam_brazo_Descanso*scale_sprite,true);
        pistola->select_bloc(0,0,12,12,false,(tam_brazo_Descanso*scale_sprite*4)/5,(tam_brazo_Descanso*scale_sprite*4)/5,true);
        posmanoX=-5*scale_sprite;
        posmanoY=9*scale_sprite;


        signo=0;
    }


}

void jugador::cargarDisparo()
{

    mano->configuracion(manoPunk+"3"+png);
    pistola->configuracion(armaB+"1"+png);
    pospistolaY=0;

    if(vuelta)
    {
        mano->select_bloc(12,12,13,13,false,tam_brazo_Descanso*scale_sprite,tam_brazo_Descanso*scale_sprite);
        pistola->select_bloc(0,0,12,12,false,(tam_brazo_Descanso*scale_sprite*4)/5,(tam_brazo_Descanso*scale_sprite*4)/5);

    }
    else
    {
        mano->select_bloc(12,12,13,13,false,tam_brazo_Descanso*scale_sprite,tam_brazo_Descanso*scale_sprite,true);
        pistola->select_bloc(0,0,12,12,false,(tam_brazo_Descanso*scale_sprite*4)/5,(tam_brazo_Descanso*scale_sprite*4)/5,true);
    }
}



bool jugador::getvuelta()
{
    return vuelta ;
}

void jugador::recibir_disparo()
{
    vidastotales--;
    if(vidastotales == 0)
    {
        andar->stop();
        configuracion(muerteI,true,0,0,288,48);
        cambio_sprit = 0;
        secuencia_muerte -> start(200);
    }
}

int jugador::mostrar_vidas()
{
    return vidastotales;
}

void jugador::escena()
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



