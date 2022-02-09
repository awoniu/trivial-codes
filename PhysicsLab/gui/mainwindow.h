#pragma once
#include <QMainWindow>
class GLWidget;
class GLWidget;
class QSlider;
class QSlider;
class QSlider;
class QTextEdit;
class QPushButton;
class QTextBrowser;
class DataPaint;
class Q_WIDGETS_EXPORT MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void myFunc();
    void updatePaint();
    void appendPaintData(const DataPaint& data_paint);
    void clearPaintData();
private:
    QSlider* createSlider();
    DataPaint* m_data;  //todo : need lock?
    GLWidget* m_glWidget;
    QSlider *m_xSlider;
    QSlider *m_ySlider;
    QSlider *m_zSlider;
    QTextEdit *m_edit;
    QTextBrowser *m_log;
    QPushButton *m_btn;
};
