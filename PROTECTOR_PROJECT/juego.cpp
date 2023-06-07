#include "juego.h"
#include "enemigo_1.h"
#include "enemigo_2.h"
#include "enemigo_3.h"
#include "button.h"
#include <QApplication>

//Constructores
juego::juego()
{
    srand(time(NULL));
    setSceneRect(0,0,16*scale_sprite*largo,16*scale_sprite*ancho);
    mapa();
}

//Destructores
juego::~juego()
{
    for(int i=0;i<largo;i++){
        for(int j=0;j<2;j++) delete bl[i][j];
    }
    for (unsigned var = 0; var < dispa; ++var)
    {
        delete cartuchoprota[var];
    }
    //delete personaje;
    delete caida;
    delete t_disparo_protagonista;
    delete movimiento_drones;

}


//Metodos
void juego::iniciar_juego(){
    puntaje_total = 0;
    nivel_activo = 1;
    t_enemigos = 6000;
    e1_vidas = 3;
    total_enemigos1 = 0;
    total_enemigos2 = 0;
    total_enemigos3 = 0;
    mapa();

    QString s_puntaje_total = QStringLiteral("%1").arg(puntaje_total, 5, 10, QLatin1Char('0'));
    puntaje_pad = new QGraphicsTextItem(s_puntaje_total);
    QFont puntajeFont("comic sans",15);
    puntaje_pad->setFont(puntajeFont);
    int txPos = 130;
    int tyPos = 22;
    puntaje_pad->setPos(txPos,tyPos);
   // addItem(puntaje_pad);

    nivel_etiqueta = new base;
    QString imagen = ":/sprites/interfaz/1.png";
    nivel_etiqueta->configuracion(imagen);
    nivel_etiqueta->select_bloc(0,0,32,232,false,largo*2,(ancho)*2);
    nivel_etiqueta-> setPos(16*4*scale_sprite,16*(ancho-1.25)*scale_sprite);
    //addItem(nivel_etiqueta);

    personaje= new jugador;
   // addItem(personaje->mano);
    //addItem(personaje->pistola);
    addItem(personaje);

    TimerGlobal =  new QTimer;
    t_disparo_protagonista=new QTimer;
    caida= new QTimer;
    movimiento_drones=new QTimer;
    Disparo_enemigos=new QTimer;
    invencible=new QTimer;

    TimerGlobal->start(1);
    connect(TimerGlobal, SIGNAL(timeout()), this, SLOT(Actualizar()));

    connect(invencible, SIGNAL (timeout()),this, SLOT(parpadeo()));
    connect(caida, SIGNAL (timeout()),this, SLOT(movimien()));
    connect(t_disparo_protagonista, SIGNAL (timeout()),this, SLOT(disparo_protagonista()));
    connect(Disparo_enemigos, SIGNAL (timeout()),this, SLOT(disparoEnemigos()));

    // Carga Enemigos Aleatoriamente

    movimiento_drones->start(150);
    Disparo_enemigos->start(10);
    trampolin =new objetivo ;


     cargar_enemigos();
    //agregarAleatorioItem();

}

void juego::mapa()
{
    fondo =new base;
    fondo->configuracion(":/sprites/zona sprites/2 Background/Sin título.png");

    fondo->select_bloc(0,0,576,324,false,largo*32,(ancho-2)*32);
    addItem(fondo);

    nivel = new base;
    nivel->configuracion(":/sprites/interfaz/LEVEL-removebg-preview.png");

    puntaje = new base;
    puntaje->configuracion(":/sprites/interfaz/SCORE-removebg-preview.png");

   for(int i=0;i<largo;i++)
    {

            bl[i][0] = new bloques;
            bl[i][0]->configuracion(":/sprites/zona sprites/1 Tiles/IndustrialTile_05.png");
            bl[i][0]->select_bloc(0);
            bl[i][0]->setPos(16*i*scale_sprite,16*(ancho-2)*scale_sprite);
            addItem(bl[i][0]);

    }

    for(int i=0;i<largo;i++)
    {

            QString sprint ;
            sprint=char(49+( rand() % (7  )) );
            QString nom=":/sprites/zona sprites/1 Tiles/IndustrialTile_1"+sprint + ".png";

            bl[i][1] = new bloques;

            bl[i][1]->configuracion(nom);
            bl[i][1]->select_bloc(0);
            bl[i][1]->setPos(16*i*scale_sprite,16*(ancho-1)*scale_sprite);
            addItem(bl[i][1]);

    }
    nivel->select_bloc(0,0,320,40,false,largo*3,(ancho)*1);
    nivel-> setPos(16*1*scale_sprite,16*(ancho-1)*scale_sprite);
    //addItem(nivel);

    puntaje->select_bloc(0,0,320,40,false,largo*3,(ancho)*1);
    puntaje-> setPos(16*1*scale_sprite,16*(ancho-14)*scale_sprite);
   // addItem(puntaje);

}

void juego::mostrar_puntaje(){
    QString s_puntaje_total = QStringLiteral("%1").arg(puntaje_total, 5, 10, QLatin1Char('0'));
    puntaje_pad->setPlainText(s_puntaje_total);
}

void juego::volver_a_iniciar(){
    base *logo= new base;
    logo->configuracion(":/sprites/interfaz/CONTINUE-removebg-preview.png");
    logo->select_bloc(0,0,512,96,false,512,96);
    int txPos = this->width()/2 - 256;
    int tyPos = 150;
    logo-> setPos(txPos,tyPos);
    addItem(logo);

    Button* playButton = new Button(QString("Jugar"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 275;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(iniciar_juego()));
    addItem(playButton);

    Button* quitButton = new Button(QString("Salir"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(salir()));
    addItem(quitButton);
}

void juego::MoverEnemigos()
{

}

void juego::salir(){
    QApplication::quit();
}

void juego::Actualizar()
{
    colision();
}

void juego::colision()
{
    if (personaje->collidesWithItem(enemigo)||personaje->collidesWithItem(enemigo2)||personaje->collidesWithItem(enemigo3)){
         if (estado_invencible) {
             personaje->recibir_disparo();
              estado_invencible=false;
             invencible->start(100);
              parpadeo();

             if(personaje->mostrar_vidas()==0){
                 detener();}
}
    }
}

void juego::disparo_protagonista()
{
    bool exit = false;
    if(dispa > 0){
        for (unsigned var = 0; var < dispa; ++var)
        {
            cartuchoprota[var]->fisicas();
            QList<QGraphicsItem *> items = collidingItems(cartuchoprota[var], Qt::ItemSelectionMode::IntersectsItemShape);

            foreach (QGraphicsItem * i, items) {
                enemigo_1 * e1 = dynamic_cast<enemigo_1 *>(i);
                if(e1){
                    e1->recibir_disparo();
                    removeItem(cartuchoprota[var]);
                    cartuchoprota.remove(var);
                    dispa--;
                    if(e1->obtener_total_vidas() > 0){
                        exit = true;
                        break;
                    }
                    else{
                        this -> removeItem(i);
                        e1->terminar();
                        total_enemigos1=0;
                        puntaje_total += 10;
                        mostrar_puntaje();
                    }
                }
                enemigo_2 * e2 = dynamic_cast<enemigo_2 *>(i);
                if(e2){
                    e2->recibir_disparo();
                    removeItem(cartuchoprota[var]);
                    cartuchoprota.remove(var);
                    dispa--;
                    if(e2->obtener_total_vidas() > 0){
                        exit = true;
                        break;
                    }
                    else{
                        this -> removeItem(i);
                        e2->terminar();
                        total_enemigos2=0;
                        puntaje_total += 20;
                        mostrar_puntaje();
                    }
                }
                enemigo_3 * e3 = dynamic_cast<enemigo_3 *>(i);
                if(e3){
                    e3->recibir_disparo();
                    removeItem(cartuchoprota[var]);
                    cartuchoprota.remove(var);
                    dispa--;
                    if(e3->obtener_total_vidas() > 0){
                        exit = true;
                        break;
                    } else {
                        this -> removeItem(i);
                        total_enemigos3--;
                        puntaje_total += 30;
                        mostrar_puntaje();
                    }
                }
                polvora * e4 = dynamic_cast<polvora *>(i);
                if(e4){
                    cartuchoEnemigos.remove(cartuchoEnemigos.indexOf(e4));
                    removeItem(e4);
                    dronesbalas--;
                    dispa--;
                    removeItem(cartuchoprota[var]);
                    cartuchoprota.remove(var);
                    exit = true;
                    break;
                }
            }
            if(puntaje_total > 99999)
                puntaje_total=0;
            if(exit) break;
        }
    } else {
        t_disparo_protagonista->stop();
    }
}

void juego::disparoEnemigos()
{
    unsigned total_balas = dronesbalas;
        for (unsigned var = 0; var < total_balas; ++var)
        {
            cartuchoEnemigos[var]->fisicas(personaje->x()+((x_jugador/2)*scale_sprite),personaje->y()+((y_jugador/2)*scale_sprite),personaje->calculo->getmasa());
            if(( (cartuchoEnemigos[var]->x()<=0) or (cartuchoEnemigos[var]->x()>=largo*scale_sprite*16)) or (cartuchoEnemigos[var]->y()<0) or (cartuchoEnemigos[var]->y()>ancho*16*scale_sprite))
            {
                removeItem(cartuchoEnemigos[var]);
                cartuchoEnemigos.remove(var);
                dronesbalas--;
                break;
            }
            else if(cartuchoEnemigos[var]->collidesWithItem(personaje))
            {
                removeItem(cartuchoEnemigos[var]);
                cartuchoEnemigos.remove(var);
                dronesbalas--;
                if(estado_invencible)
                {
                    personaje->recibir_disparo();
                    estado_invencible=!estado_invencible;
                    invencible->start(200);

                    if(personaje->mostrar_vidas()==0){
                        detener();
                    }
                }
                break;
            }
        }
         trampolin->Msen();
}

void juego::detener(){
    puntaje = 0;
    t_disparo_protagonista->stop();
    caida->stop();
    movimiento_drones->stop();
    Disparo_enemigos->stop();
    invencible->stop();
    t_cargar_enemigos->stop();
    removeItem(personaje);
    for(unsigned i = 0; i < cartuchoEnemigos.length();i++){
        removeItem(cartuchoEnemigos[i]);
    }
    for(unsigned i = 0; i < cartuchoprota.length();i++){
        removeItem(cartuchoprota[i]);
    }
    cartuchoEnemigos.remove(0,cartuchoEnemigos.length());
    cartuchoprota.remove(0,cartuchoprota.length());
    dronesbalas = 0;
    dispa = 0;
    foreach (QGraphicsItem *var, items_totales) {
        enemigo_1 * e1 = dynamic_cast<enemigo_1 *>(var);
        if(e1){
            e1->terminar();
        }
        enemigo_2 * e2 = dynamic_cast<enemigo_2 *>(var);
        if(e2){
            e2->terminar();
        }
        enemigo_3 * e3 = dynamic_cast<enemigo_3 *>(var);
        if(e3){
            e3->terminar();
        }
        removeItem(var);
    }
    volver_a_iniciar();

}

void juego::iniciar(){
    t_disparo_protagonista->start();
    caida->start();
    movimiento_drones->start();
    Disparo_enemigos->start();
    invencible->start();
    t_cargar_enemigos->start();
}

void juego::cargar_enemigos(){
    enemigo = new enemigo_1;
    addItem(enemigo);

    enemigo2 = new enemigo_2;
    addItem(enemigo2);

    enemigo3 = new enemigo_3;
    addItem(enemigo3);

}

void juego::parpadeo()
{
    if(prendido)
    {
        removeItem(personaje);
    }
    else
    {
        addItem(personaje);
    }
    prendido=!prendido;
    Iparpadeo++;
    if(Cparpadeo==Iparpadeo)
    {
        estado_invencible= !estado_invencible;
        invencible->stop();
        Iparpadeo=0;
        prendido=true;
    }
}

bool juego::aleatorio()
{
    return rand()<=p*(RAND_MAX+1)-1;
}

void juego::movimien()
{
    personaje->movimientoY();
    for(int i=0;i<largo;i++)
    {
        if(bl[i][0]->collidesWithItem(personaje))
        {
            personaje->calculo->setAY(0);
            personaje->setPos(personaje->x(),bl[i][0]->y()-(48*1.2)-0.22);
            personaje->cargaCorrer();
            permisoO=true;
            caida->stop();
        }
    }
}

void juego::keyPressEvent(QKeyEvent *i)
{
    const int e=i->key();

    if(e == Qt::Key_I)
    {
        if(personaje->collidesWithItem(trampolin))
        {
            permisoO=true;
        }
        if(permisoO)
        {
            permisoO=false;
            personaje->saltar();
            personaje->calculo->setAY(40);
            personaje->calculo->setVY(-80);
            caida->start(10);
        }
    }
    if(e == Qt::Key_P)
    {
        personaje->direccion();
    }
    if(e == Qt::Key_O)
    {
        int v;
        dispa++;
        personaje->cargarDisparo();
        cartuchoprota.push_back(new polvora);

        if(personaje->getvuelta())
        {v=1;}
        else
        { v=-1;}
        cartuchoprota[dispa-1]->Iparametros(":/sprites/armas y movimientos sprites/5 Bullets/9.png",(personaje->mano->x()),(personaje->mano->y())+8,0,0,v*scale_sprite*40,0,0,personaje->getvuelta());
        addItem(cartuchoprota[dispa-1]);
        t_disparo_protagonista -> start(10);
    }
}

void juego::randomItem()
{
    //QGraphicsItem* enemigo; // Variable para almacenar el nuevo item creado

    // Lógica para crear y agregar el item de manera aleatoria
    // Aquí debes implementar tu propia lógica para crear el item

    // Agregar el item a la escena
   // scene->addItem(item);

    //cargar_enemigos();
}

void juego::agregarAleatorioItem()
{
    QTimer* timer = new QTimer;
    connect(timer, SIGNAL (timeout()),this, SLOT(cargarenemigos()));
    timer->start(1000); // Intervalo de tiempo en milisegundos para agregar un nuevo item (1 segundo en este ejemplo)
}
