/********************************************************************************
** Form generated from reading UI file 'tcp_server.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCP_SERVER_H
#define UI_TCP_SERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCP_Server
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton_send;

    void setupUi(QWidget *TCP_Server)
    {
        if (TCP_Server->objectName().isEmpty())
            TCP_Server->setObjectName("TCP_Server");
        TCP_Server->resize(551, 76);
        lineEdit = new QLineEdit(TCP_Server);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(20, 30, 351, 20));
        pushButton_send = new QPushButton(TCP_Server);
        pushButton_send->setObjectName("pushButton_send");
        pushButton_send->setGeometry(QRect(430, 30, 75, 24));

        retranslateUi(TCP_Server);

        QMetaObject::connectSlotsByName(TCP_Server);
    } // setupUi

    void retranslateUi(QWidget *TCP_Server)
    {
        TCP_Server->setWindowTitle(QCoreApplication::translate("TCP_Server", "TCP_Server", nullptr));
        pushButton_send->setText(QCoreApplication::translate("TCP_Server", "send", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCP_Server: public Ui_TCP_Server {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCP_SERVER_H
