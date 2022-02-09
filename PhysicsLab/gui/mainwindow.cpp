#include "mainwindow.h"
#include <iostream>
#include <QWidget>
#include <QSurfaceFormat>
#include <QSlider>
#include <QLabel>
#include <QTextEdit>
#include <QTextBrowser>
#include <QPushButton>
#include <QVBoxLayout>
#include "gui/dataPaint.h"
#include "gui/glwidget.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),m_data(new DataPaint()), m_glWidget(new GLWidget(m_data, this)),
    m_xSlider(createSlider()), m_ySlider(createSlider()), m_zSlider(createSlider()),
    m_edit(new QTextEdit(this)), m_log(new QTextBrowser(this)),m_btn(new QPushButton(this))
{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    QHBoxLayout *container = new QHBoxLayout;
    { // opengl widget and sliders
        container->addWidget(m_glWidget);
        container->addWidget(m_xSlider);
        container->addWidget(m_ySlider);
        container->addWidget(m_zSlider);
    }
    { // python editor
        QVBoxLayout *editorLayout = new QVBoxLayout();
        QLabel *editorLabel = new QLabel(this);
        editorLabel->setText("Python Editor");
        editorLayout->addWidget(editorLabel);
        editorLayout->addWidget(m_edit);
        container->addLayout(editorLayout);
    }
    mainLayout->addLayout(container);
    {// log info
        QVBoxLayout *logLayout = new QVBoxLayout();
        QLabel *logLabel = new QLabel(this);
        logLabel->setText("info:");
        logLayout->addWidget(logLabel);
        logLayout->addWidget(m_log);
        mainLayout->addLayout(logLayout);
    }
    {
        QVBoxLayout * btnLayout = new QVBoxLayout();
        btnLayout->addWidget(m_btn);
        mainLayout->addLayout(btnLayout);
    }
    QWidget* central_widget = new QWidget(this);

    central_widget->setLayout(mainLayout);
    this->setCentralWidget(central_widget);

    connect(m_xSlider, &QSlider::valueChanged, m_glWidget, &GLWidget::setXRotation);
    connect(m_glWidget, &GLWidget::xRotationChanged, m_xSlider, &QSlider::setValue);
    connect(m_ySlider, &QSlider::valueChanged, m_glWidget, &GLWidget::setYRotation);
    connect(m_glWidget, &GLWidget::yRotationChanged, m_ySlider, &QSlider::setValue);
    connect(m_zSlider, &QSlider::valueChanged, m_glWidget, &GLWidget::setZRotation);
    connect(m_glWidget, &GLWidget::zRotationChanged, m_zSlider, &QSlider::setValue);
    connect(m_btn, &QPushButton::clicked, this, &MainWindow::myFunc);
}

void MainWindow::myFunc()
{
    m_glWidget->update();
}

MainWindow::~MainWindow()
{

}

QSlider* MainWindow::createSlider()
{
    QSlider *slider = new QSlider(Qt::Vertical);
    slider->setRange(0, 360 * 16);
    slider->setSingleStep(16);
    slider->setPageStep(15 * 16);
    slider->setTickInterval(15 * 16);
    slider->setTickPosition(QSlider::TicksRight);
    return slider;
}

void MainWindow::appendPaintData(const DataPaint& data_paint)
{
    m_data->append(data_paint);
};

void MainWindow::clearPaintData()
{
    m_data->clear();
}

void MainWindow::updatePaint()
{
    m_glWidget->update();
}