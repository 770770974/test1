#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    m_webView = new QWebEngineView(this);
    QStackedLayout* layout = new QStackedLayout(ui->frame);
    ui->frame->setLayout(layout);
    layout->addWidget(m_webView);

    connect(ui->btnGo, &QPushButton::clicked, this, [this]()
            {
                QString url = ui->addressEdit->text();
                if (!url.isEmpty())
                {
                    m_webView->load(url);
                }
            });

    connect(ui->btnRefresh, &QPushButton::clicked, this, [this]()
            {
                m_webView->reload();
            });
}

MainWindow::~MainWindow()
{
    delete ui;
}
