#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QStackedLayout>
#include <QCloseEvent>
#include <QTcpSocket>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void slot_recvmessage(); //接收来自服务器的消息的槽
    void onLoadFinished();
private:
    Ui::MainWindow *ui;
    QWebEngineView *m_webView;
    QTcpSocket *m_tcp; //发送消息套接字

};
#endif // MAINWINDOW_H
