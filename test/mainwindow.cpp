#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("TCP - 客户端");

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


    //加载完成后进行全屏展示
    connect(m_webView, &QWebEngineView::loadFinished, this, &MainWindow::onLoadFinished);





    // 创建通信的套接字对象
    m_tcp = new QTcpSocket(this);

    this->m_tcp->connectToHost("127.0.0.1",10000);

    //有新数据到达时的readyread()信号连接到slot_recvmessage()
    connect(m_tcp,SIGNAL(readyRead()),this,SLOT(slot_recvmessage()));




}

MainWindow::~MainWindow()
{
    delete ui;
}


//接收数据
void MainWindow::slot_recvmessage()
{
    QByteArray byteArray = this->m_tcp->readAll();
    QString str = QString(byteArray);
    m_webView->load(str);
    ui->addressEdit->setText(str);


}


//进行全屏展示
void MainWindow::onLoadFinished()
{
    showFullScreen();
}
