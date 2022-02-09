#pragma once
#include "base/pl_vector.h"
namespace phy_lab {
class Particle{
public:
    void setPos(const DVec3& pos){m_pos=pos;}
    const DVec3& getPos() const{return m_pos;}
    void setVelocity(const DVec3& vel){m_vel=vel;}
    const DVec3& getVelocity() const{return m_vel;}
    void setAcceleration(const DVec3& acc){m_acc=acc;}
    const DVec3& getAcceleration() const{return m_acc;}

    void setMass(double mass){m_mass=mass;}
    double getMass() const{return m_mass;}
    void setDamp(double damp){m_damp=damp;}
    double getDamp() const{return m_damp;}

    void iterate(double duration, DVec3 force);

private:
    DVec3 m_pos;
    DVec3 m_vel;
    DVec3 m_acc;
    DVec3 m_norm;
    double m_damp;
    double m_mass;
    double m_time;
};
} //namespace phy_lab