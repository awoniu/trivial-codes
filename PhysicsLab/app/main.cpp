#include <QApplication>
#include <iostream>
#include <QSurfaceFormat>
#include <memory.h>
#include <QThread>
#include <chrono>
#include "gui/mainwindow.h"
#include "env/pl_env.h"
#include "geom/pl_cube.h"
class EnvThread: public QThread{
public:
    MainWindow* gui;
protected:
    void run(){
        while(1){
        std::cout << "threadEnv start" << std::endl;
        Env env;
        phy_lab::Cube cube(0.25,0.25,0.25);
        cube.m_particle.setMass(1);
        cube.setPos(0,0,5);
        cube.setVel(5,0,0);
        cube.updatePaint();
        env.setGui(gui);
            env.m_gui->clearPaintData();
            env.m_gui->appendPaintData(cube.getDataPaint());
            env.m_gui->appendPaintData(env.m_ground);
            env.m_gui->updatePaint();
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "set gui" << std::endl;
        for(int i=0; i<100; i++)
        {
            cube.m_particle.iterate(0.02, {0,0,-2});
            cube.updatePaint();
            env.m_gui->clearPaintData();
            env.m_gui->appendPaintData(cube.getDataPaint());
            env.m_gui->appendPaintData(env.m_ground);
            env.m_gui->updatePaint();
            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};

int main(int argc, char *argv[])
{
    DataPaint::setRadio(0.1);
    QApplication app(argc, argv);
    MainWindow window;
    window.show();
    EnvThread env_thread;
    env_thread.gui = &window;
    env_thread.setObjectName("env_t");
    env_thread.start();
    return app.exec();
}