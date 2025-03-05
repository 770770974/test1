#include "tcp_server.h"
#include "ui_tcp_server.h"
//#include <QMessageBox>
#include <QDateTime>

TCP_Server::TCP_Server(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TCP_Server)
{
    ui->setupUi(this);

    //初始化
    setWindowTitle("TCP - 服务器");
    TCP_server = new QTcpServer();
    TCP_connectSocket = nullptr;
    connect(ui->pushButton_send,SIGNAL(clicked()),this,SLOT(slot_sendmessage()));

    //调用listen函数监听同时绑定IP和端口号
    if(TCP_server->listen(QHostAddress::Any,10000)) //判断listen是否成功
    {
        connect(TCP_server,SIGNAL(newConnection()),this,SLOT(slot_newconnect()));
    }else
    {
        qWarning() << "无法启动服务器：" << TCP_server->errorString();
    }


}

TCP_Server::~TCP_Server()
{
    delete ui;
}


//建立新连接的槽
void TCP_Server::slot_newconnect()
{
    TCP_connectSocket = TCP_server->nextPendingConnection(); //获取客户端套接字
}



//发送消息的槽
void TCP_Server::slot_sendmessage()
{
    QString sendMessage = ui->lineEdit->text();
    if(TCP_connectSocket != nullptr && !sendMessage.isEmpty()) //确保有客户端连接，并且发送内容不为空
    {
        TCP_connectSocket->write(sendMessage.toLatin1());   //发送消息到客户端
    }

    ui->lineEdit->clear();

}


