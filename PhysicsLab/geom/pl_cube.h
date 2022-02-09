#pragma once
#include "base/pl_vector.h"
#include "gui/dataPaint.h"
#include "base/pl_particle.h"
namespace phy_lab{
class Cube{
public:
    Cube(double length, double width, double height);
    void setPos(double x, double y, double z){m_particle.setPos({x,y,z});};
    void setVel(double x_vel, double y_vel, double z_vel){m_particle.setVelocity({x_vel,y_vel,z_vel});};
    DVec3 getPos(){return m_particle.getPos();};    
    const DataPaint& getDataPaint(){return m_paint;};
    void updatePaint();
public:
    DVec3     m_dim_size;
    Particle  m_particle;
    DataPaint m_paint;
    DVec3     m_color = {1,1,1};
};
};