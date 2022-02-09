#pragma once
#include <vector>
#include "base/pl_vector.h"
class DataPaint
{
public:
    static void  setRadio(float radio){s_radio=radio;};
    static float getRadio(){return s_radio;}; 
public:
    DataPaint(int pre_alloc=0);
    void append(const DataPaint& other);
    void clear();
    const float *faceData() const { return m_face_data.data(); }
    int faceCount() const { return m_face_count; }
    int faceVertexCount() const { return m_face_count / 9; }
    const float *lineData() const { return m_line_data.data(); }
    int lineCount() const { return m_line_count; }
    int lineVertexCount() const { return m_line_count / 6; }
    void updateData(); 

    void triFace(float x1, float y1, float z1,
                float x2, float y2, float z2,
                float x3, float y3, float z3,
                float  r, float  g, float  b);
    void quadFace(float x1, float y1, float z1,
                float x2, float y2, float z2,
                float x3, float y3, float z3,
                float x4, float y4, float z4,
                float  r, float  g, float  b);
    void line(float x1, float y1, float z1,
              float x2, float y2, float z2,
              float  r, float  g, float  b);
private:
    static float s_radio;
    std::vector<float> m_face_data;
    int m_face_count=0;
    std::vector<float> m_line_data;
    int m_line_count=0;
};

