/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFormLayout *formLayout;
    QLabel *channel1Label;
    QLineEdit *channel1Edit;
    QLabel *channel2Label;
    QLineEdit *channel2Edit;
    QLabel *channel3Label;
    QLineEdit *channel3Edit;
    QLabel *channel4Label;
    QLineEdit *channel4Edit;
    QLabel *channel5Label;
    QLineEdit *channel5Edit;
    QLabel *channel6Label;
    QLineEdit *channel6Edit;
    QLabel *channel7Label;
    QLabel *channel8Label;
    QLabel *channel9Label;
    QLabel *channel10Label;
    QLabel *channel11Label;
    QLabel *channel12Label;
    QLineEdit *channel7Edit;
    QLineEdit *channel8Edit;
    QLineEdit *channel9Edit;
    QLineEdit *channel10Edit;
    QLineEdit *channel11Edit;
    QLineEdit *channel12Edit;
    QPushButton *initButton;
    QGroupBox *settingsBox;
    QFormLayout *formLayout_2;
    QLabel *baudrateLabel;
    QLabel *comPortLabel;
    QComboBox *comPortsBox;
    QComboBox *baudrateBox;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPlainTextEdit *plainTextEdit;
    QCheckBox *debugBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(733, 647);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        formLayout = new QFormLayout(centralWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        channel1Label = new QLabel(centralWidget);
        channel1Label->setObjectName(QStringLiteral("channel1Label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, channel1Label);

        channel1Edit = new QLineEdit(centralWidget);
        channel1Edit->setObjectName(QStringLiteral("channel1Edit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, channel1Edit);

        channel2Label = new QLabel(centralWidget);
        channel2Label->setObjectName(QStringLiteral("channel2Label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, channel2Label);

        channel2Edit = new QLineEdit(centralWidget);
        channel2Edit->setObjectName(QStringLiteral("channel2Edit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, channel2Edit);

        channel3Label = new QLabel(centralWidget);
        channel3Label->setObjectName(QStringLiteral("channel3Label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, channel3Label);

        channel3Edit = new QLineEdit(centralWidget);
        channel3Edit->setObjectName(QStringLiteral("channel3Edit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, channel3Edit);

        channel4Label = new QLabel(centralWidget);
        channel4Label->setObjectName(QStringLiteral("channel4Label"));

        formLayout->setWidget(3, QFormLayout::LabelRole, channel4Label);

        channel4Edit = new QLineEdit(centralWidget);
        channel4Edit->setObjectName(QStringLiteral("channel4Edit"));

        formLayout->setWidget(3, QFormLayout::FieldRole, channel4Edit);

        channel5Label = new QLabel(centralWidget);
        channel5Label->setObjectName(QStringLiteral("channel5Label"));

        formLayout->setWidget(4, QFormLayout::LabelRole, channel5Label);

        channel5Edit = new QLineEdit(centralWidget);
        channel5Edit->setObjectName(QStringLiteral("channel5Edit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, channel5Edit);

        channel6Label = new QLabel(centralWidget);
        channel6Label->setObjectName(QStringLiteral("channel6Label"));

        formLayout->setWidget(5, QFormLayout::LabelRole, channel6Label);

        channel6Edit = new QLineEdit(centralWidget);
        channel6Edit->setObjectName(QStringLiteral("channel6Edit"));

        formLayout->setWidget(5, QFormLayout::FieldRole, channel6Edit);

        channel7Label = new QLabel(centralWidget);
        channel7Label->setObjectName(QStringLiteral("channel7Label"));

        formLayout->setWidget(6, QFormLayout::LabelRole, channel7Label);

        channel8Label = new QLabel(centralWidget);
        channel8Label->setObjectName(QStringLiteral("channel8Label"));

        formLayout->setWidget(7, QFormLayout::LabelRole, channel8Label);

        channel9Label = new QLabel(centralWidget);
        channel9Label->setObjectName(QStringLiteral("channel9Label"));

        formLayout->setWidget(8, QFormLayout::LabelRole, channel9Label);

        channel10Label = new QLabel(centralWidget);
        channel10Label->setObjectName(QStringLiteral("channel10Label"));

        formLayout->setWidget(9, QFormLayout::LabelRole, channel10Label);

        channel11Label = new QLabel(centralWidget);
        channel11Label->setObjectName(QStringLiteral("channel11Label"));

        formLayout->setWidget(10, QFormLayout::LabelRole, channel11Label);

        channel12Label = new QLabel(centralWidget);
        channel12Label->setObjectName(QStringLiteral("channel12Label"));

        formLayout->setWidget(11, QFormLayout::LabelRole, channel12Label);

        channel7Edit = new QLineEdit(centralWidget);
        channel7Edit->setObjectName(QStringLiteral("channel7Edit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, channel7Edit);

        channel8Edit = new QLineEdit(centralWidget);
        channel8Edit->setObjectName(QStringLiteral("channel8Edit"));

        formLayout->setWidget(7, QFormLayout::FieldRole, channel8Edit);

        channel9Edit = new QLineEdit(centralWidget);
        channel9Edit->setObjectName(QStringLiteral("channel9Edit"));

        formLayout->setWidget(8, QFormLayout::FieldRole, channel9Edit);

        channel10Edit = new QLineEdit(centralWidget);
        channel10Edit->setObjectName(QStringLiteral("channel10Edit"));

        formLayout->setWidget(9, QFormLayout::FieldRole, channel10Edit);

        channel11Edit = new QLineEdit(centralWidget);
        channel11Edit->setObjectName(QStringLiteral("channel11Edit"));

        formLayout->setWidget(10, QFormLayout::FieldRole, channel11Edit);

        channel12Edit = new QLineEdit(centralWidget);
        channel12Edit->setObjectName(QStringLiteral("channel12Edit"));

        formLayout->setWidget(11, QFormLayout::FieldRole, channel12Edit);

        initButton = new QPushButton(centralWidget);
        initButton->setObjectName(QStringLiteral("initButton"));

        formLayout->setWidget(13, QFormLayout::LabelRole, initButton);

        settingsBox = new QGroupBox(centralWidget);
        settingsBox->setObjectName(QStringLiteral("settingsBox"));
        formLayout_2 = new QFormLayout(settingsBox);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        baudrateLabel = new QLabel(settingsBox);
        baudrateLabel->setObjectName(QStringLiteral("baudrateLabel"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, baudrateLabel);

        comPortLabel = new QLabel(settingsBox);
        comPortLabel->setObjectName(QStringLiteral("comPortLabel"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, comPortLabel);

        comPortsBox = new QComboBox(settingsBox);
        comPortsBox->setObjectName(QStringLiteral("comPortsBox"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, comPortsBox);

        baudrateBox = new QComboBox(settingsBox);
        baudrateBox->setObjectName(QStringLiteral("baudrateBox"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, baudrateBox);


        formLayout->setWidget(13, QFormLayout::FieldRole, settingsBox);

        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        formLayout->setWidget(14, QFormLayout::LabelRole, startButton);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        formLayout->setWidget(15, QFormLayout::LabelRole, stopButton);

        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        formLayout->setWidget(16, QFormLayout::SpanningRole, plainTextEdit);

        debugBox = new QCheckBox(centralWidget);
        debugBox->setObjectName(QStringLiteral("debugBox"));

        formLayout->setWidget(14, QFormLayout::FieldRole, debugBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 733, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "testware_proto", 0));
        channel1Label->setText(QApplication::translate("MainWindow", "1-\321\213\320\271", 0));
        channel2Label->setText(QApplication::translate("MainWindow", "2-\321\213\320\271", 0));
        channel3Label->setText(QApplication::translate("MainWindow", "3-\320\270\320\271", 0));
        channel4Label->setText(QApplication::translate("MainWindow", "4-\321\213\320\271", 0));
        channel5Label->setText(QApplication::translate("MainWindow", "5-\321\213\320\271", 0));
        channel6Label->setText(QApplication::translate("MainWindow", "6-\320\276\320\271", 0));
        channel7Label->setText(QApplication::translate("MainWindow", "7-\320\276\320\271", 0));
        channel8Label->setText(QApplication::translate("MainWindow", "8-\320\276\320\271", 0));
        channel9Label->setText(QApplication::translate("MainWindow", "9-\321\213\320\271", 0));
        channel10Label->setText(QApplication::translate("MainWindow", "10-\321\213\320\271", 0));
        channel11Label->setText(QApplication::translate("MainWindow", "11-\321\213\320\271", 0));
        channel12Label->setText(QApplication::translate("MainWindow", "12-\321\213\320\271", 0));
        initButton->setText(QApplication::translate("MainWindow", "\320\230\320\275\320\270\321\206\320\270\320\260\320\273\320\270\320\267\320\270\321\200\320\276\320\262\320\260\321\202\321\214", 0));
        settingsBox->setTitle(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", 0));
        baudrateLabel->setText(QApplication::translate("MainWindow", "\320\241\320\272\320\276\321\200\321\201\321\202\321\214", 0));
        comPortLabel->setText(QApplication::translate("MainWindow", "Com-\320\277\320\276\321\200\321\202", 0));
        baudrateBox->clear();
        baudrateBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "9600", 0)
        );
        startButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214", 0));
        stopButton->setText(QApplication::translate("MainWindow", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214", 0));
        debugBox->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\273\320\260\320\264\320\276\321\207\320\275\321\213\320\271 \321\200\320\265\320\266\320\270\320\274", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
