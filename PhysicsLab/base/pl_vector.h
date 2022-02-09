#pragma once
#include <iostream>
#include <math.h>
namespace phy_lab {

template <class T>
class Vec3{
public:
    Vec3(const Vec3& v)=default;
    Vec3(Vec3&& v)=default;
    Vec3(T x=0, T y=0, T z=0):m_x(x), m_y(y), m_z(z){}
    Vec3<T>& operator=(Vec3<T>&& v)=default;
    Vec3<T>& operator=(const Vec3<T>& v)=default;   
public:
    T x()const {return m_x;}
    T y()const {return m_y;}
    T z()const {return m_z;}
    void setX(T x){m_x = x;}
    void setY(T y){m_y = y;}
    void setZ(T z){m_z = z;}
    T squareMagnitude() const{return x*x+y*y+z*z;}
    Vec3<T> operator+(const Vec3<T>& v){return Vec3<T>{m_x+v.x(),m_y+v.y(),m_z+v.z()};}
    Vec3<T> operator-(const Vec3<T>& v){return Vec3<T>{m_x-v.x(),m_y-v.y(),m_z-v.z()};}
    Vec3<T> operator*(T v){return Vec3<T>{m_x*v, m_y*v, m_z*v};}


    T magnitude() const{return std::sqrt(squareMagnitude());}
    void normalize() const{T l=magnitude(); if(l == 1) return; m_x /= l; m_y /= l; m_z /= l;}
    Vec3<T>  scalarProduct(T s) const{return Vec3<T>(m_x*s, m_y*s, m_z*s);}
    Vec3<T>& scalarProductUpdate(T s) {m_x*=s; m_y*=s; m_z*=s; return *this;}
    Vec3<T>  componentProduct(const Vec3<T>& v) const{return Vec3<T>(m_x*v.x(), m_y*v.y(), m_z*v.z());}
    Vec3<T>& componentProductUpdate(const Vec3<T>& v) {m_x*=v.x(); m_y*=v.y(); m_z*=v.z(); return *this;}
    Vec3<T>  vecProduct(const Vec3<T>& v) const{return Vec3<T>(y*v.z()-z*v.y(), z*v.x()-x*v.z(), x*v.y()-y*v.x());}
    Vec3<T>& vecProductUpdate(const Vec3<T>& v) {m_x=y*v.z()-z*v.y(); m_y=z*v.x()-x*v.z(); m_z=x*v.y()-y*v.x();return *this;}
    T dotProduct(const Vec3<T>& v) const{return m_x*v.x()+m_y*v.y()+m_z*v.z();}
    Vec3<T>  vectorAdd(const Vec3<T>& v)const{return Vec3<T>(m_x+v.x(), m_y+v.y(), m_z+v.z());}
    Vec3<T>& vectorAddUpdate(const Vec3<T>& v){m_x+=v.x(); m_y+=v.y(); m_z+=v.z(); return *this;}
    Vec3<T>  vectorAdd(T s)const{return Vec3<T>(m_x+s, m_y+s, m_z+s);}
    Vec3<T>& scalarAddUpdate(T s){m_x+=s; m_y+=s; m_z+=s; return *this;}

private:
    T m_x=0;
    T m_y=0;
    T m_z=0;
};
typedef Vec3<double> DVec3;
typedef Vec3<float> FVec3;
template<class T>
Vec3<T> normal(const Vec3<T>& v1, const Vec3<T>& v2)
{
    return Vec3<T>(v1.y()*v2.z()-v1.z()*v2.y(),
                   v1.z()*v2.x()-v1.x()*v2.z(),
                   v1.x()*v2.y()-v1.y()*v2.x());
}

template<class T>
Vec3<T> vecAddVec(const Vec3<T>& v1, const Vec3<T>& v2)
{
    return Vec3<T>(v1.x()+v2.x(), v1.y()+v2.y(), v1.z()+v2.z()); 
}

template<class T>
Vec3<T> vecSubVec(const Vec3<T>& v1, const Vec3<T>& v2)
{
    return Vec3<T>(v1.x()-v2.x(), v1.y()-v2.y(), v1.z()-v2.z());
}

template<class T>
T vecDotProductVec(const Vec3<T>& v1, const Vec3<T>& v2)
{
    return v1.x()*v2.x()+v1.y()*v2.y()+v1.z()*v2.z();
}

template<class T>
void vecProductValue(const Vec3<T>& v_src, T value, Vec3<T>& v_des)
{
    v_des.setX(v_src.x()*value);
    v_des.setY(v_src.y()*value);
    v_des.setZ(v_src.z()*value);
}

template<class T>
std::ostream& operator<<(std::ostream& out, const Vec3<T>& vec)
{
    out << vec.x() << vec.y() << vec << vec.z();
    return out;
}
}// namespace phy_lab
