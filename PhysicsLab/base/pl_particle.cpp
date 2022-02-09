
#include "base/pl_particle.h"
namespace phy_lab {
void Particle::iterate(double duration, DVec3 force)
{
    auto vel_t0 = m_vel;
    m_acc = DVec3(force.x()/m_mass, force.y()/m_mass, force.z()/m_mass);
    DVec3 vel_theta;
    vecProductValue(m_acc, duration, vel_theta);
    
    auto vel_t1 = vel_t0 + vel_theta;
    auto pos_t0 = m_pos;
    DVec3 theta_pos;
    vecProductValue(vel_t0+vel_t1, 0.5*duration, theta_pos);
    m_pos = vecAddVec(m_pos, theta_pos);
    m_vel = vel_t1;
}
}