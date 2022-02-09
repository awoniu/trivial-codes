#include "env/pl_env.h"
Env::Env(){
    m_ground.quadFace(-10,-10,0, 10,-10,0, 10,10,0, -10,10,0, 0,1,1);
    m_ground.quadFace(-10,10,0, 10,10,0, 10,-10,0, -10,-10,0, 1,1,0);
    float radio = m_ground.getRadio();
    for(float i=-10; i<=10; i+=radio)
    {
        m_ground.line(-10,i,0, 10,i,0, 1,1,1);
        m_ground.line(i,-10,0, i,10,0, 1,1,1);
    }
}