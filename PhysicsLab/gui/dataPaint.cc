#include "dataPaint.h"
#include <qmath.h>
#include <qopengl.h>

static void coordInit(DataPaint& obj)
{
    obj.line(0,0,0,  0.1f,0,0,  1,0,0);
    obj.line(0,0,0,  0,0.1f,0,  0,1,0);
    obj.line(0,0,0,  0,0,0.1f,  0,0,1);
}

DataPaint::DataPaint(int pre_allocate)
    : m_face_count(0), m_line_count(0)
{
    if(pre_allocate>0){
    m_face_data.resize(pre_allocate * 9);  //2500 points
    m_line_data.resize(pre_allocate * 6);  //2500 points
    }
    coordInit(*this);
}

float DataPaint::s_radio = 1.f;
void DataPaint::updateData()
{
    const GLfloat x1 = +0.06f;
    const GLfloat y1 = -0.14f;
    const GLfloat z1 = -0.05f;
    const GLfloat x2 = +0.14f;
    const GLfloat y2 = -0.06f;
    const GLfloat z2 = -0.05f;
    const GLfloat x3 = +0.06f;
    const GLfloat y3 = -0.06f;
    const GLfloat z3 = -0.05f;

    const GLfloat xx1 = +0.0f;
    const GLfloat yy1 = +0.0f;
    const GLfloat zz1 =  0.0f;
    const GLfloat xx2 = +3.0f;
    const GLfloat yy2 = +3.0f;
    const GLfloat zz2 =  0.0f;
    const GLfloat xx3 = +0.0f;
    const GLfloat yy3 = +3.0f;
    const GLfloat zz3 =  0.0f;

    const float xxx1 = 0;
    const float yyy1 = 0;
    const float zzz1 = 0.05;
    const float xxx2 = 1.0;
    const float yyy2 = 0;
    const float zzz2 = 0.05;
    const float xxx3 = 1.0;
    const float yyy3 = 1.0;
    const float zzz3 = 0.05;
    const float xxx4 = 0;
    const float yyy4 = 1.0;
    const float zzz4 = 0.05;

    //quad(x1, y1, x2, y2, y2, x2, y1, x1);
    //face(x1,y1,z1,x2,y2,z2,x3,y3,z3,1,1,0);
    triFace(x3,y3,z3, x2,y2,z2, x1,y1,z1, 1,1,1);
    line(xx1,yy1,zz1, xx2,yy2,zz2, 1,0,0);
    line(xx2,yy2,zz2, xx3,yy3,zz3, 1,0,0);
    line(xx3,yy3,zz3, xx1,yy1,zz1, 1,0,0);
    quadFace(xxx1,yyy1,zzz1,xxx2,yyy2,zzz2,xxx3,yyy3,zzz3,xxx4,yyy4,zzz4,0,0,1);
}

void DataPaint::triFace(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3, GLfloat r, GLfloat g, GLfloat b)
{
    if(m_face_count+27 >= m_face_data.size())
        m_face_data.resize((m_face_data.size()+27)*2);
    //QVector3D n = QVector3D::normal(QVector3D(x3 - x1, y3 - y1, z3-z1), QVector3D(x2 - x1, y2 - y1, z2-z1));
    phy_lab::FVec3 n = phy_lab::normal(phy_lab::FVec3(x1 - x2, y1 - y2, z1-z2), phy_lab::FVec3(x1 - x3, y1 - y3, z1-z3));
    GLfloat *p = m_face_data.data() + m_face_count;
    *p++ = x1;
    *p++ = y1;
    *p++ = z1;
    *p++ = n.x();
    *p++ = n.y();
    *p++ = n.z();
    *p++ = r;
    *p++ = g;
    *p++ = b;
    m_face_count += 9;

    *p++ = x2;
    *p++ = y2;
    *p++ = z2;
    *p++ = n.x();
    *p++ = n.y();
    *p++ = n.z();
    *p++ = r;
    *p++ = g;
    *p++ = b;
    m_face_count += 9;

    *p++ = x3;
    *p++ = y3;
    *p++ = z3;
    *p++ = n.x();
    *p++ = n.y();
    *p++ = n.z();
    *p++ = r;
    *p++ = g;
    *p++ = b;
    m_face_count += 9;
}

void DataPaint::quadFace(float x1, float y1, float z1,
                         float x2, float y2, float z2,
                         float x3, float y3, float z3,
                         float x4, float y4, float z4,
                         float  r, float  g, float  b)
{
    triFace(x1,y1,z1,x2,y2,z2,x3,y3,z3,r,g,b);
    triFace(x1,y1,z1,x3,y3,z3,x4,y4,z4,r,g,b);
}

void DataPaint::line(float x1, float y1, float z1, 
                     float x2, float y2, float z2, 
                     float  r, float  g, float  b)
{
    if(m_line_count+12 >= m_line_data.size())
        m_line_data.resize((m_line_data.size()+12)*2);
    GLfloat *p = m_line_data.data() + m_line_count;
    *p++ = x1;
    *p++ = y1;
    *p++ = z1;
    *p++ = r;
    *p++ = g;
    *p++ = b;
    *p++ = x2;
    *p++ = y2;
    *p++ = z2;
    *p++ = r;
    *p++ = g;
    *p++ = b;
    m_line_count += 12;
}

void DataPaint::append(const DataPaint& other)
{
    {
        if(m_face_data.size() <= m_face_count+other.faceCount())
            m_face_data.resize(m_face_count+other.faceCount()*2);
        GLfloat *p = m_face_data.data() + m_face_count;
        const GLfloat *other_p = other.faceData();
        for(int i=0; i<other.faceCount(); i++)
            *p++ = *other_p++ ;
        m_face_count += other.faceCount();
    }
    {
        if(m_line_data.size() <= m_line_count+other.lineCount())
            m_line_data.resize(m_line_count+other.lineCount()*2);
        GLfloat *p = m_line_data.data() + m_line_count;
        const GLfloat *other_p = other.lineData();
        for(int i=0; i<other.lineCount(); i++)
            *p++ = *other_p++ ;
        m_line_count += other.lineCount();
    }
}

void DataPaint::clear()
{
    m_line_count=0;
    m_face_count=0;
    coordInit(*this);   
}