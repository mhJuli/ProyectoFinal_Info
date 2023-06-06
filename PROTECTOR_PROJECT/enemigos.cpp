#include "enemigos.h"
#include <QTimer>
#include <time.h>

// Constructores
Enemigo1::Enemigo1() {
    estado_inicial();
}

Enemigo1::Enemigo1(bool posicionInicial) {
    posF = posicionInicial;
    estado_inicial();
}

Enemigo1::Enemigo1(bool posicionInicial, int vidas) {
    posF = posicionInicial;
    vidastotales = vidas;
    estado_inicial();

}

//Destructores
Enemigo1::~Enemigo1()
{
    delete t_caminar;
}

// Propiedades
int Enemigo1::obtener_total_vidas(){
    return vidastotales;
}



// Metodos
void Enemigo1::estado_inicial(){
    t_caminar = new QTimer;
    t_mostrar_muerte = new QTimer;
    configuracion(enemigo1,true,0,10,432,40);

    CAMbloque(3);

    // Conectar timers con los slots
    connect(t_caminar, SIGNAL (timeout()),this, SLOT(disparo()));
    connect(t_mostrar_muerte, SIGNAL(timeout()), this, SLOT(muerte()));

    // Establece la dirección inical
    if(posF)
        setPos(16*scale_sprite,16*(ancho-(3.7))*scale_sprite);
    else
        setPos(16*(largo-4)*scale_sprite,16*(ancho-(3.7))*scale_sprite);

    // Iniciar movimiento
    t_caminar->start(200);
}

void Enemigo1::muerte(){

}

void Enemigo1::cambioE()
{
    select_bloc(cambio_sprite*48,0,48,43,false,48*1.6,48*1.2,!posF);
    if(cambio_sprite < cambio_spriteD)
        cambio_sprite++;
    else
        cambio_sprite=0;
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

void Enemigo1::disparo()
{
    if(cambio_sprite == cambio_spriteD){
        if(pausa){
            configuracion(enemigo1D,true,0,8,432,40);

        }
        else
            configuracion(enemigo1,true,0,8,432,40);
        pausa = !pausa;
        cambio_spriteD = 3;
        cambio_sprite = 0;
    }
    cambioE();
}

void Enemigo1::recibir_disparo(){
    vidastotales--;
    if(vidastotales == 0){
        muerte();
    }
}

void Enemigo1::terminar(){
    muerte();
}

//----------------------------------------------------------------------------------------------------------------------------------------------
//Constructores
Enemigo2::Enemigo2(){
    estado_inicial();
}

Enemigo2::Enemigo2(bool posicionInicial)
{
    posF2=posicionInicial;
    estado_inicial();
}

Enemigo2::Enemigo2(bool posicionInicial, int vidas)
{
    posF2=posicionInicial;
    vidastotales=vidas;
    estado_inicial();
}




// Propiedades
int Enemigo2::obtener_total_vidas(){
    return vidastotales;
}
//Destructores
Enemigo2::~Enemigo2()
{
    delete t_caminar;
}


//Metodos
void Enemigo2::estado_inicial(){
    t_caminar = new QTimer;
    t_mostrar_muerte= new QTimer;
    configuracion(enemigo2,true,0,10,432,40);

    CAMbloque(3);

    // Conectar timers con los slots
    connect(t_caminar, SIGNAL (timeout()),this, SLOT(disparoE()));
    connect(t_mostrar_muerte, SIGNAL(timeout()), this, SLOT(muerte()));

    // Establece la dirección inical
    if(posF2)
        setPos(0,16*(ancho-(3.7))*scale_sprite);
    else
        setPos(16*(largo)*scale_sprite,16*(ancho-(3.7))*scale_sprite);

    // Iniciar movimiento
    t_caminar->start(500);

}

void Enemigo2::cambioE()
{
    select_bloc(cambio_sprite*48,0,48,43,false,48*1.6,48*1.2,!posF2);
    if(cambio_sprite < cambio_spriteD)
        cambio_sprite++;
    else
        cambio_sprite=0;
    if(pausa2){
        if(posF2){
            setPos(x()+10,y());
            if(x() >= ((16 * (largo-4)) * scale_sprite)){
                giro = false;
                posF2 = !posF2;
            }
        } else {
            setPos(x()-10,y());
            if(x() <= (((largo-27)/2) * scale_sprite)){
                giro = true;
                posF2 = !posF2;
            }
        }
    }
}

void Enemigo2::disparo()
{
    if(cambio_sprite==cambio_spriteD and pausa2==0)
    {
        configuracion(enemigo2,true,0,8,432,40);
        pausa2=1;
        cambio_spriteD=3;
        cambio_sprite=0;

    }
    else if (cambio_sprite==cambio_spriteD and pausa2==1)
    {
        configuracion(enemigo2D,true,0,8,432,40);
        pausa2=2;
        cambio_spriteD=3;
        cambio_sprite=0;

    }
    else if(cambio_sprite==cambio_spriteD and pausa2==2)
    {
        configuracion(enemigo_quieto,true,0,8,432,40);
        pausa2=0;
        cambio_spriteD=3;
        cambio_sprite=0;

    }
    cambioE();
}
void Enemigo2::recibir_disparo(){
    vidastotales--;
    if(vidastotales == 0){
        delete t_caminar;
        configuracion(enemigo2M,true,0,0,288,48);
        cambio_sprite = 0;
        t_mostrar_muerte -> start(200);
    }
}

void Enemigo2::terminar(){
    muerte();
}

void Enemigo2::muerte(){

}

//-----------------------------------------------------------------------------------------------------------------------------------------------
//Constructores
Enemigo3::Enemigo3()
{
    estado_inicial();

}

Enemigo3::Enemigo3(bool posicionInicial)
{
    posF3=posicionInicial;
    estado_inicial();
}

Enemigo3::Enemigo3(bool posicionInicial, int vidas)
{
    posF3=posicionInicial;
    vidastotales=vidas;
    estado_inicial();
}

//Destructores
Enemigo3::~Enemigo3()
{
    delete t_caminar;
    delete t_mostrar_muerte;
}

//Metodos
void Enemigo3::muerte(){

}


int Enemigo3::obtener_total_vidas()
{
    return vidastotales;
}

void Enemigo3::estado_inicial()
{
    t_caminar = new QTimer;
    t_mostrar_muerte= new QTimer;
    configuracion(enemigo3,true,0,10,432,40);

    CAMbloque(3);

    // Conectar timers con los slots
    connect(t_caminar, SIGNAL (timeout()),this, SLOT(disparoE3()));
    connect(t_mostrar_muerte, SIGNAL(timeout()), this, SLOT(muerte()));

    // Establece la dirección inical
    if(posF3)
        setPos(0,16*(ancho*2/11)*scale_sprite);
    else
        setPos(16*(largo)*scale_sprite,16*(ancho*2/11)*scale_sprite);

    // Iniciar movimiento
    t_caminar->start(300);
}

void Enemigo3::cambioE()
{
    select_bloc(cambio_sprite*48,0,35,43,false,30*scale_sprite,30*scale_sprite,giro);
    if(cambio_sprite<cambio_spriteD)
    {
        cambio_sprite++;
    }
    else
    {
        cambio_sprite=0;
    }
    if(pausa3==1)
    {
        if (posF3==false)
            {
            setPos(x()-10,y());
            if (x()==((largo-27)/2)*scale_sprite)
                {
                posF3=true;
                giro=false;
                }
            }
        else if (posF3==true)
            {
            setPos(x()+10,y());
            if (x()==16*(largo-4)*scale_sprite)
                {
                posF3=false;
                giro=true;
                }
            }
    }
}

void Enemigo3::disparo()
{

    if(cambio_sprite==cambio_spriteD and pausa3==0)
    {
        configuracion(enemigo3,true,0,8,432,40);
        pausa3=1;
        cambio_spriteD=3;
        cambio_sprite=0;

    }
    else if (cambio_sprite==cambio_spriteD and pausa3==1)
    {
        configuracion(enemigo3D,true,0,8,432,40);
        pausa3=2;
        cambio_spriteD=3;
        cambio_sprite=0;

    }
    else if(cambio_sprite==cambio_spriteD and pausa3==2)
    {
        configuracion(enemigo_quieto,true,0,8,432,40);
        pausa3=0;
        cambio_spriteD=3;
        cambio_sprite=0;

    }


    cambioE();
}



void Enemigo3::recibir_disparo(){
    vidastotales--;
    if(vidastotales == 0){
        delete t_caminar;
        configuracion(enemigo_muerte,true,0,0,288,48);
        cambio_sprite = 0;
        t_mostrar_muerte -> start(500);
    }
}

void Enemigo3::terminar(){
    muerte();
}



