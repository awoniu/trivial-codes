#include "pl_cube.h"
namespace phy_lab{
Cube::Cube(double length, double width, double height):m_dim_size(length, width, height){  }
void Cube::updatePaint()
{
    m_paint.clear();
    float radio = m_paint.getRadio();
    DVec3 tmp = getPos();
    FVec3 pos((float)tmp.x(), (float)tmp.y(), (float)tmp.z());
    FVec3 pxpypz{ radio*((float)m_dim_size.x()/2+pos.x()),  radio*((float) m_dim_size.y()/2+pos.y()),  radio*((float) m_dim_size.z()/2+pos.z())};
    FVec3 pxpynz{ radio*((float)m_dim_size.x()/2+pos.x()),  radio*((float) m_dim_size.y()/2+pos.y()),  radio*((float)-m_dim_size.z()/2+pos.z())};
    FVec3 pxnypz{ radio*((float)m_dim_size.x()/2+pos.x()),  radio*((float)-m_dim_size.y()/2+pos.y()),  radio*((float) m_dim_size.z()/2+pos.z())};
    FVec3 pxnynz{ radio*((float)m_dim_size.x()/2+pos.x()),  radio*((float)-m_dim_size.y()/2+pos.y()),  radio*((float)-m_dim_size.z()/2+pos.z())};
    FVec3 nxpypz{ radio*((float)-m_dim_size.x()/2+pos.x()), radio*((float) m_dim_size.y()/2+pos.y()),  radio*((float) m_dim_size.z()/2+pos.z())};
    FVec3 nxpynz{ radio*((float)-m_dim_size.x()/2+pos.x()), radio*((float) m_dim_size.y()/2+pos.y()),  radio*((float)-m_dim_size.z()/2+pos.z())};
    FVec3 nxnypz{ radio*((float)-m_dim_size.x()/2+pos.x()), radio*((float)-m_dim_size.y()/2+pos.y()),  radio*((float) m_dim_size.z()/2+pos.z())};
    FVec3 nxnynz{ radio*((float)-m_dim_size.x()/2+pos.x()), radio*((float)-m_dim_size.y()/2+pos.y()),  radio*((float)-m_dim_size.z()/2+pos.z())};
    //top
    m_paint.quadFace( pxpypz.x(),  pxpypz.y(),  pxpypz.z(), 
                      nxpypz.x(),  nxpypz.y(),  nxpypz.z(),
                      nxnypz.x(),  nxnypz.y(),  nxnypz.z(),
                      pxnypz.x(),  pxnypz.y(),  pxnypz.z(),
                     m_color.x(), m_color.y(), m_color.z() );
    //down
    m_paint.quadFace( pxnynz.x(),  pxnynz.y(),  pxnynz.z(),
                      nxnynz.x(),  nxnynz.y(),  nxnynz.z(),
                      nxpynz.x(),  nxpynz.y(),  nxpynz.z(),
                      pxpynz.x(),  pxpynz.y(),  pxpynz.z(), 
                     m_color.x(), m_color.y(), m_color.z() );
    //right
    m_paint.quadFace( pxpynz.x(),  pxpynz.y(),  pxpynz.z(), 
                      pxpypz.x(),  pxpypz.y(),  pxpypz.z(),
                      pxnypz.x(),  pxnypz.y(),  pxnypz.z(),
                      pxnynz.x(),  pxnynz.y(),  pxnynz.z(),
                     m_color.x(), m_color.y(), m_color.z() );
    //left
    m_paint.quadFace( nxnynz.x(),  nxnynz.y(),  nxnynz.z(),
                      nxnypz.x(),  nxnypz.y(),  nxnypz.z(),
                      nxpypz.x(),  nxpypz.y(),  nxpypz.z(),
                      nxpynz.x(),  nxpynz.y(),  nxpynz.z(),
                     m_color.x(), m_color.y(), m_color.z() );
    //front
    m_paint.quadFace( pxnypz.x(),  pxnypz.y(),  pxnypz.z(),
                      nxnypz.x(),  nxnypz.y(),  nxnypz.z(),
                      nxnynz.x(),  nxnynz.y(),  nxnynz.z(),
                      pxnynz.x(),  pxnynz.y(),  pxnynz.z(),
                     m_color.x(), m_color.y(), m_color.z() );
    //back
    m_paint.quadFace( pxpynz.x(),  pxpynz.y(),  pxpynz.z(),
                      nxpynz.x(),  nxpynz.y(),  nxpynz.z(),
                      nxpypz.x(),  nxpypz.y(),  nxpypz.z(),
                      pxpypz.x(),  pxpypz.y(),  pxpypz.z(),
                     m_color.x(), m_color.y(), m_color.z() );
    m_paint.line(pxpypz.x(), pxpypz.y(), pxpypz.z(),
                 pxpynz.x(), pxpynz.y(), pxpynz.z(),
                 0 ,0, 0 );
    m_paint.line(nxpypz.x(), nxpypz.y(), nxpypz.z(),
                 nxpynz.x(), nxpynz.y(), nxpynz.z(),
                 0 ,0, 0 );
    m_paint.line(pxnypz.x(), pxnypz.y(), pxnypz.z(),
                 pxnynz.x(), pxnynz.y(), pxnynz.z(),
                 0 ,0, 0 );
    m_paint.line(nxnypz.x(), nxnypz.y(), nxnypz.z(),
                 nxnynz.x(), nxnynz.y(), nxnynz.z(),
                 0 ,0, 0 );

    m_paint.line(pxpypz.x(), pxpypz.y(), pxpypz.z(),
                 nxpypz.x(), nxpypz.y(), nxpypz.z(),
                 0 ,0, 0 );
    m_paint.line(pxnypz.x(), pxnypz.y(), pxnypz.z(),
                 nxnypz.x(), nxnypz.y(), nxnypz.z(),
                 0 ,0, 0 );
    m_paint.line(pxpynz.x(), pxpynz.y(), pxpynz.z(),
                 nxpynz.x(), nxpynz.y(), nxpynz.z(),
                 0 ,0, 0 );
    m_paint.line(pxnynz.x(), pxnynz.y(), pxnynz.z(),
                 nxnynz.x(), nxnynz.y(), nxnynz.z(),                                  
                 0 ,0, 0 );

    m_paint.line(pxpypz.x(), pxpypz.y(), pxpypz.z(),
                 pxnypz.x(), pxnypz.y(), pxnypz.z(),
                 0 ,0, 0 );
    m_paint.line(nxpypz.x(), nxpypz.y(), nxpypz.z(),
                 nxnypz.x(), nxnypz.y(), nxnypz.z(),
                 0 ,0, 0 );
    m_paint.line(pxpynz.x(), pxpynz.y(), pxpynz.z(),
                 pxnynz.x(), pxnynz.y(), pxnynz.z(),
                 0 ,0, 0 );
    m_paint.line(nxpynz.x(), nxpynz.y(), nxpynz.z(),
                 nxnynz.x(), nxnynz.y(), nxnynz.z(),
                 0 ,0, 0 );                                                   

}

}//namespace phy_lab