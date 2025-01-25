/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_10;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_5;
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QVBoxLayout *verticalLayout_9;
    QTabWidget *tabWidget;
    QWidget *storage;
    QHBoxLayout *horizontalLayout_10;
    QHBoxLayout *horizontalLayout_9;
    QVBoxLayout *vlStorage;
    QLabel *label_7;
    QFrame *line;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_2;
    QComboBox *cbStorageCat;
    QPushButton *btnCatEdit;
    QRadioButton *rbProduct;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *edtProductTitle;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *edtPrice;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *edtCount;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *edtProductDes;
    QRadioButton *rbCat;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_6;
    QLineEdit *edtCatTitle;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_9;
    QLineEdit *edtCatDes;
    QPushButton *btnSaveStorage;
    QPushButton *btnDelCat;
    QTableWidget *tblStorageCat;
    QTableWidget *tblStorageProduct;
    QWidget *tab_4;
    QHBoxLayout *horizontalLayout_15;
    QVBoxLayout *vlCustomer;
    QLabel *label_12;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_8;
    QLineEdit *edtCustomerName;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_10;
    QLineEdit *edtCustomerBalance;
    QCheckBox *chbDeptor;
    QHBoxLayout *horizontalLayout_23;
    QLabel *label_20;
    QLineEdit *edtCustomrDiscount;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_11;
    QLineEdit *edtCustomerPhone;
    QPushButton *btnSaveCustomer;
    QTableWidget *tblCustomers;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_28;
    QVBoxLayout *vlEmployees;
    QLabel *label_21;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_24;
    QLabel *label_22;
    QLineEdit *edtEmployeeName;
    QHBoxLayout *horizontalLayout_25;
    QLabel *label_23;
    QLineEdit *edtEmployeeSalary;
    QPushButton *btnSaveEmployee;
    QTableWidget *tblEmployees;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_33;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_26;
    QLabel *label_25;
    QLineEdit *edtInventoryCost;
    QHBoxLayout *horizontalLayout_27;
    QLabel *label_26;
    QLineEdit *edtEmployeesCost;
    QHBoxLayout *horizontalLayout_29;
    QLabel *label_27;
    QLineEdit *edtEnergyCost;
    QHBoxLayout *horizontalLayout_30;
    QLabel *label_28;
    QLineEdit *edtRentCost;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_31;
    QLabel *label_29;
    QLineEdit *edtTotalSale;
    QHBoxLayout *horizontalLayout_32;
    QLabel *label_30;
    QLineEdit *edtProfit;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tab_3;
    QWidget *tab_8;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_20;
    QScrollArea *orderFilterArea;
    QWidget *scrollAreaWidgetContents_2;
    QVBoxLayout *vlOrderFilter;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label_18;
    QLineEdit *edtSearchOrderFilter;
    QScrollArea *orderCardHolder;
    QWidget *scrollAreaWidgetContents;
    QFrame *frame;
    QVBoxLayout *vlOrderList;
    QHBoxLayout *horizontalLayout_18;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnClearOrderList;
    QTableWidget *tblOrderList;
    QHBoxLayout *horizontalLayout_17;
    QLabel *label_14;
    QLabel *lblOrderTotal;
    QHBoxLayout *horizontalLayout_22;
    QLabel *label_19;
    QLineEdit *edtOrderDiscount;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_17;
    QComboBox *cbOrderCustomer;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_15;
    QLabel *lblCheckout;
    QPushButton *btnSubmitOrder;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_13;
    QTableWidget *tblRecentOrder;
    QWidget *page_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1064, 800);
        MainWindow->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        MainWindow->setStyleSheet(QString::fromUtf8("QWidget{\n"
"background: solid qlineargradient(spread:pad, x1:0, y1:1, x2:0, y2:0, stop:0 rgba(10, 10, 10, 255), stop:1 rgba(20, 20, 25, 255));\n"
"border: none;\n"
"border-radius: 15px;\n"
"font-family: \"Peyda\";\n"
"font-size : 14px;\n"
"}\n"
"QPushButton {\n"
"background-color: rgba(255,255,255,10);\n"
"color: #ffffff;\n"
"border: 1px solid transparent;\n"
"border-radius: 12px;\n"
"padding: 10px 30px 10px 30px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: rgba(255,255,255,20);\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgba(255,255,255,10);\n"
"}\n"
"QPushButton:disabled {\n"
"background-color: #222222;\n"
"color: #666666;\n"
"}\n"
"QPushButton:focus {\n"
"outline: none;\n"
"border: 1px solid #0066FF;\n"
"}\n"
"QScrollArea{\n"
"border: 1px solid transparent;\n"
"border-radius: 20px;\n"
"}\n"
"\n"
"QListView {\n"
"background-color: rgba(255,255,255,10);\n"
"border: 1px solid transparent;\n"
"border-radius: 15px;\n"
"padding: 5px;\n"
"}\n"
"QListView::item {\n"
"border: none;\n"
"padding: 5"
                        "px;\n"
"margin: 5px;\n"
"color: #ffffff;\n"
"}\n"
"QListView::item:selected {\n"
"background-color: #0066FF;\n"
"border: 1px solid transparent;\n"
"border-radius: 5px;\n"
"color: #ffffff;\n"
"}\n"
"QListView::item:selected:focus {\n"
"border: 1px solid #0066FF;\n"
"}\n"
"QListView::item:hover {\n"
"background-color: rgba(0,102,255,20);\n"
"border: 1px solid transparent;\n"
"border-radius: 5px;\n"
"color: #0066FF;\n"
"}\n"
"QListView::item:disabled {\n"
"color: #666666;\n"
"background-color: #222222;\n"
"}\n"
"QLineEdit {\n"
"background-color: rgba(255,255,255,10);\n"
"border: 1px solid transparent;\n"
"border-radius: 10px;\n"
"padding: 8px;\n"
"color: #ffffff;\n"
"}\n"
"QLineEdit:focus {\n"
"border: 1px solid #0066FF;\n"
"}\n"
"QLineEdit::placeholder {\n"
"color: #666666;\n"
"}\n"
"QLineEdit:disabled {\n"
"background-color: #222222;\n"
"color: #666666;\n"
"border: 1px solid transparent;\n"
"}\n"
"QProgressBar {\n"
"border: 1px solid transparent;\n"
"height: 12px;\n"
"border-radius: 6px;\n"
"background-color: r"
                        "gba(255,255,255,10);\n"
"text-align: center;\n"
"}\n"
"QProgressBar::chunk {\n"
"background-color: #00DC72;\n"
"border: 1px solid transparent;\n"
"border-radius: 6px;\n"
"}\n"
"QProgressBar::indicator {\n"
"border: 1px solid transparent;\n"
"border-radius: 5px;\n"
"}\n"
"QProgressBar:disabled {\n"
"border: 1px solid transparent;\n"
"background-color: #222222;\n"
"}\n"
"QProgressBar:focus {\n"
"border: 1px solid transparent;\n"
"}\n"
"QCheckBox {\n"
"background-color: transparent;\n"
"color: #ffffff;\n"
"border: 1px solid transparent;\n"
"border-radius: 5px;\n"
"}\n"
"QCheckBox::indicator {\n"
"width: 18px;\n"
"height: 18px;\n"
"margin-left: 5px;\n"
"}\n"
"QRadioButton {\n"
"color: #ffffff;\n"
"border: none;\n"
"}\n"
"QRadioButton::indicator {\n"
"width: 15px;\n"
"height: 15px;\n"
"margin-left: 5px;\n"
"}\n"
"QTabWidget::pane {\n"
"border: none;\n"
"border-radius: 20px;\n"
"background-color: rgba(255,255,255,10);\n"
"}\n"
"QTabWidget > QWidget{\n"
"background: transparent;\n"
"}\n"
"QTabBar::tab {\n"
"color: wh"
                        "ite;\n"
"border: 1px solid transparent;\n"
"border-bottom-color: rgba(255,255,255,10);\n"
"border-top-left-radius: 15px;\n"
"min-width: 100px;\n"
"border-top-right-radius: 15px;\n"
"padding: 6px;\n"
"margin-right: 2px;\n"
"}\n"
"QTabBar::tab:selected {\n"
"background-color: rgba(255,255,255,10);\n"
"border-bottom: 2px solid #00DC72;\n"
"color: white;\n"
"}\n"
"QTabBar::tab:!selected {\n"
"background-color: rgba(255,255,255,20);\n"
"color: #dddddd;\n"
"}\n"
"QTabBar::tab:hover {\n"
"background-color: rgba(255,255,255,20);\n"
"}\n"
"QTabBar::tab:pressed {\n"
"background-color: rgba(255,255,255,10);\n"
"}\n"
"QTabBar::tab:disabled {\n"
"background-color: rgba(255,255,255,30);\n"
"color: #666666;\n"
"}\n"
"QComboBox {\n"
"background-color: rgba(255,255,255,10);\n"
"border: 1px solid transparent;\n"
"border-radius: 10px;\n"
"padding: 8px;\n"
"color: #ffffff;\n"
"}\n"
"QComboBox:hover {\n"
"background-color: rgba(255,255,255,20);\n"
"}\n"
"QComboBox:disabled {\n"
"background-color: rgba(255,255,255,30);\n"
"color: #"
                        "666666;\n"
"}\n"
"QComboBox:pressed {\n"
"background-color: rgba(255,255,255,10);\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"background: solid transparent;\n"
"border: 1px solid transparent;\n"
"border-radius: 5px;\n"
"}\n"
"QComboBox::item {\n"
"padding:5px 0px 5px 0px;\n"
"max-height: 18px;\n"
"}\n"
"QComboBox::item:selected {\n"
"background: solid #0066FF;\n"
"border: 1px solid transparent;\n"
"border-radius: 5px;\n"
"}\n"
"QGroupBox {\n"
"background-color: rgba(255,255,255,10);\n"
"border: 1px solid transparent;\n"
"border-radius: 15px;\n"
"padding: 10px;\n"
"margin: 20px;\n"
"}\n"
"QGroupBox::title {\n"
"margin-top: -20px;\n"
"subcontrol-position: top;\n"
"padding: 3px 15px 5px 15px;\n"
"color: #ffffff;\n"
"background-color: #222222;\n"
"border: 1px solid transparent;\n"
"border-radius: 10px;\n"
"}\n"
"\n"
"QTableWidget {\n"
"background-color: rgba(255,255,255,10);\n"
"gridline-color: rgba(255,255,255,30);\n"
"border: 1px solid transparent;\n"
"border-radius: 15px;\n"
"}\n"
"\n"
"QTableWidget QHeaderView"
                        "{\n"
"background-color:  transparent;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal {\n"
"background-color:  transparent;\n"
"color: #ffffff;\n"
"padding: 4px;\n"
"}\n"
"\n"
"QHeaderView::section::vertical {\n"
"background-color:  transparent;\n"
"color: #ffffff;\n"
"padding: 4px;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"background-color: rgba(255,255,255,10);\n"
"padding: 7px;\n"
"border: 1px solid transparent;\n"
"}\n"
"\n"
"QTableWidget::item:alternate {\n"
"background-color: rgba(255,255,255,30);\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"border-bottom: 2px solid #00DC72;\n"
"color: white;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"background-color: rgba(255,255,255,20);\n"
"color: white;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"background-color: transparent;\n"
"width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"background-color: rgba(255,255,255,30);\n"
"border: 1px solid transparent;\n"
"border-radius: 5"
                        "px;\n"
"min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"background-color: transparent;\n"
"width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"background-color: rgba(255,255,255,30);\n"
"border: 1px solid transparent;\n"
"border-radius: 5px;\n"
"min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QLabel{\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QPlainTextEdit {\n"
"background-color: rgba(255,255,255,10);\n"
"border: 1px solid transparent;\n"
"border-radius: 10px;\n"
"padding: 8px;\n"
"color: #ffffff;\n"
"}\n"
"QPlainTextEdit:focus {\n"
"border: 1px solid #0066FF;\n"
"}\n"
"QPlainTextEdit::placeholder {\n"
"color: #666666;\n"
"}\n"
"QPlainTextEdit:disabled {\n"
"background-color: #222222;\n"
"color: #666666;\n"
"border: none;\n"
"}\n"
"QRadioButton{\n"
"background-color:"
                        " transparent;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QFont font;
        font.setFamilies({QString::fromUtf8("Peyda")});
        centralwidget->setFont(font);
        verticalLayout_10 = new QVBoxLayout(centralwidget);
        verticalLayout_10->setObjectName("verticalLayout_10");
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setFont(font);
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_5 = new QVBoxLayout(page);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        tabWidget_2 = new QTabWidget(page);
        tabWidget_2->setObjectName("tabWidget_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget_2->sizePolicy().hasHeightForWidth());
        tabWidget_2->setSizePolicy(sizePolicy);
        tabWidget_2->setMinimumSize(QSize(0, 400));
        tabWidget_2->setStyleSheet(QString::fromUtf8(""));
        tabWidget_2->setTabPosition(QTabWidget::TabPosition::South);
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        verticalLayout_9 = new QVBoxLayout(tab_7);
        verticalLayout_9->setObjectName("verticalLayout_9");
        verticalLayout_9->setContentsMargins(0, 10, 0, 0);
        tabWidget = new QTabWidget(tab_7);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab{\n"
"margin: 1px;\n"
"min-height: 100px;\n"
"min-width: 24px;\n"
"border-top-left-radius: 15px;\n"
"border-top-right-radius: 0px;\n"
"border-bottom-left-radius: 15px;\n"
"border-bottom-right-radius: 0px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"background-color: rgba(255,255,255,10);\n"
"border-right: 2px solid #00DC72;\n"
"border-bottom: none;\n"
"color: white;\n"
"}\n"
"QTabBar::tab:!selected {\n"
"background-color: rgba(255,255,255,20);\n"
"color: #dddddd;\n"
"}"));
        tabWidget->setTabPosition(QTabWidget::TabPosition::East);
        storage = new QWidget();
        storage->setObjectName("storage");
        horizontalLayout_10 = new QHBoxLayout(storage);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        vlStorage = new QVBoxLayout();
        vlStorage->setObjectName("vlStorage");
        label_7 = new QLabel(storage);
        label_7->setObjectName("label_7");
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vlStorage->addWidget(label_7, 0, Qt::AlignmentFlag::AlignBottom);

        line = new QFrame(storage);
        line->setObjectName("line");
        line->setFont(font);
        line->setFrameShape(QFrame::Shape::HLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);

        vlStorage->addWidget(line);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(10);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        label_2 = new QLabel(storage);
        label_2->setObjectName("label_2");
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_7->addWidget(label_2);

        cbStorageCat = new QComboBox(storage);
        cbStorageCat->setObjectName("cbStorageCat");
        cbStorageCat->setFont(font);
        cbStorageCat->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        cbStorageCat->setEditable(true);

        horizontalLayout_7->addWidget(cbStorageCat);

        btnCatEdit = new QPushButton(storage);
        btnCatEdit->setObjectName("btnCatEdit");
        btnCatEdit->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_7->addWidget(btnCatEdit);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 7);

        vlStorage->addLayout(horizontalLayout_7);

        rbProduct = new QRadioButton(storage);
        rbProduct->setObjectName("rbProduct");
        rbProduct->setEnabled(false);
        rbProduct->setFont(font);
        rbProduct->setCheckable(true);
        rbProduct->setChecked(false);

        vlStorage->addWidget(rbProduct);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label = new QLabel(storage);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout_3->addWidget(label);

        edtProductTitle = new QLineEdit(storage);
        edtProductTitle->setObjectName("edtProductTitle");
        edtProductTitle->setEnabled(false);
        edtProductTitle->setFont(font);
        edtProductTitle->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        edtProductTitle->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_3->addWidget(edtProductTitle);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(storage);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_4->addWidget(label_3);

        edtPrice = new QLineEdit(storage);
        edtPrice->setObjectName("edtPrice");
        edtPrice->setEnabled(false);
        edtPrice->setFont(font);
        edtPrice->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        edtPrice->setInputMethodHints(Qt::InputMethodHint::ImhNone);
        edtPrice->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_4->addWidget(edtPrice);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(storage);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_5->addWidget(label_4);

        edtCount = new QLineEdit(storage);
        edtCount->setObjectName("edtCount");
        edtCount->setEnabled(false);
        edtCount->setFont(font);
        edtCount->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        edtCount->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_5->addWidget(edtCount);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(storage);
        label_5->setObjectName("label_5");
        label_5->setFont(font);

        horizontalLayout_6->addWidget(label_5);

        edtProductDes = new QLineEdit(storage);
        edtProductDes->setObjectName("edtProductDes");
        edtProductDes->setEnabled(false);
        edtProductDes->setFont(font);
        edtProductDes->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        edtProductDes->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_6->addWidget(edtProductDes);


        verticalLayout->addLayout(horizontalLayout_6);


        vlStorage->addLayout(verticalLayout);

        rbCat = new QRadioButton(storage);
        rbCat->setObjectName("rbCat");
        rbCat->setFont(font);
        rbCat->setChecked(true);

        vlStorage->addWidget(rbCat);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_6 = new QLabel(storage);
        label_6->setObjectName("label_6");
        label_6->setFont(font);

        horizontalLayout_8->addWidget(label_6);

        edtCatTitle = new QLineEdit(storage);
        edtCatTitle->setObjectName("edtCatTitle");
        edtCatTitle->setEnabled(true);
        edtCatTitle->setFont(font);
        edtCatTitle->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        edtCatTitle->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_8->addWidget(edtCatTitle);


        verticalLayout_2->addLayout(horizontalLayout_8);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        label_9 = new QLabel(storage);
        label_9->setObjectName("label_9");
        label_9->setFont(font);

        horizontalLayout_11->addWidget(label_9);

        edtCatDes = new QLineEdit(storage);
        edtCatDes->setObjectName("edtCatDes");
        edtCatDes->setEnabled(true);
        edtCatDes->setFont(font);
        edtCatDes->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
        edtCatDes->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        edtCatDes->setClearButtonEnabled(false);

        horizontalLayout_11->addWidget(edtCatDes);


        verticalLayout_2->addLayout(horizontalLayout_11);


        vlStorage->addLayout(verticalLayout_2);

        btnSaveStorage = new QPushButton(storage);
        btnSaveStorage->setObjectName("btnSaveStorage");
        btnSaveStorage->setFont(font);

        vlStorage->addWidget(btnSaveStorage);

        btnDelCat = new QPushButton(storage);
        btnDelCat->setObjectName("btnDelCat");

        vlStorage->addWidget(btnDelCat);


        horizontalLayout_9->addLayout(vlStorage);

        tblStorageCat = new QTableWidget(storage);
        tblStorageCat->setObjectName("tblStorageCat");
        tblStorageCat->setFont(font);
        tblStorageCat->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tblStorageCat->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tblStorageCat->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        horizontalLayout_9->addWidget(tblStorageCat);

        tblStorageProduct = new QTableWidget(storage);
        tblStorageProduct->setObjectName("tblStorageProduct");
        tblStorageProduct->setEnabled(true);
        tblStorageProduct->setFont(font);
        tblStorageProduct->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tblStorageProduct->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tblStorageProduct->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        horizontalLayout_9->addWidget(tblStorageProduct);

        horizontalLayout_9->setStretch(0, 2);
        horizontalLayout_9->setStretch(1, 3);
        horizontalLayout_9->setStretch(2, 4);

        horizontalLayout_10->addLayout(horizontalLayout_9);

        tabWidget->addTab(storage, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        horizontalLayout_15 = new QHBoxLayout(tab_4);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        vlCustomer = new QVBoxLayout();
        vlCustomer->setObjectName("vlCustomer");
        label_12 = new QLabel(tab_4);
        label_12->setObjectName("label_12");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Peyda")});
        font1.setBold(true);
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vlCustomer->addWidget(label_12, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignBottom);

        line_2 = new QFrame(tab_4);
        line_2->setObjectName("line_2");
        line_2->setFrameShape(QFrame::Shape::HLine);
        line_2->setFrameShadow(QFrame::Shadow::Sunken);

        vlCustomer->addWidget(line_2);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        label_8 = new QLabel(tab_4);
        label_8->setObjectName("label_8");
        label_8->setFont(font);

        horizontalLayout_12->addWidget(label_8);

        edtCustomerName = new QLineEdit(tab_4);
        edtCustomerName->setObjectName("edtCustomerName");
        edtCustomerName->setFont(font);

        horizontalLayout_12->addWidget(edtCustomerName);


        vlCustomer->addLayout(horizontalLayout_12);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_10 = new QLabel(tab_4);
        label_10->setObjectName("label_10");
        label_10->setFont(font);

        horizontalLayout_13->addWidget(label_10);

        edtCustomerBalance = new QLineEdit(tab_4);
        edtCustomerBalance->setObjectName("edtCustomerBalance");
        edtCustomerBalance->setFont(font);

        horizontalLayout_13->addWidget(edtCustomerBalance);

        chbDeptor = new QCheckBox(tab_4);
        chbDeptor->setObjectName("chbDeptor");

        horizontalLayout_13->addWidget(chbDeptor);


        vlCustomer->addLayout(horizontalLayout_13);

        horizontalLayout_23 = new QHBoxLayout();
        horizontalLayout_23->setObjectName("horizontalLayout_23");
        label_20 = new QLabel(tab_4);
        label_20->setObjectName("label_20");
        label_20->setFont(font);

        horizontalLayout_23->addWidget(label_20);

        edtCustomrDiscount = new QLineEdit(tab_4);
        edtCustomrDiscount->setObjectName("edtCustomrDiscount");
        edtCustomrDiscount->setFont(font);

        horizontalLayout_23->addWidget(edtCustomrDiscount);


        vlCustomer->addLayout(horizontalLayout_23);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        label_11 = new QLabel(tab_4);
        label_11->setObjectName("label_11");
        label_11->setFont(font);

        horizontalLayout_14->addWidget(label_11);

        edtCustomerPhone = new QLineEdit(tab_4);
        edtCustomerPhone->setObjectName("edtCustomerPhone");
        edtCustomerPhone->setFont(font);

        horizontalLayout_14->addWidget(edtCustomerPhone);


        vlCustomer->addLayout(horizontalLayout_14);

        btnSaveCustomer = new QPushButton(tab_4);
        btnSaveCustomer->setObjectName("btnSaveCustomer");
        btnSaveCustomer->setFont(font);

        vlCustomer->addWidget(btnSaveCustomer);


        horizontalLayout_15->addLayout(vlCustomer);

        tblCustomers = new QTableWidget(tab_4);
        tblCustomers->setObjectName("tblCustomers");
        tblCustomers->setFont(font);
        tblCustomers->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tblCustomers->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
        tblCustomers->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        horizontalLayout_15->addWidget(tblCustomers);

        horizontalLayout_15->setStretch(0, 1);
        horizontalLayout_15->setStretch(1, 3);
        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        horizontalLayout_28 = new QHBoxLayout(tab);
        horizontalLayout_28->setObjectName("horizontalLayout_28");
        vlEmployees = new QVBoxLayout();
        vlEmployees->setObjectName("vlEmployees");
        label_21 = new QLabel(tab);
        label_21->setObjectName("label_21");
        label_21->setFont(font1);
        label_21->setAlignment(Qt::AlignmentFlag::AlignCenter);

        vlEmployees->addWidget(label_21, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignBottom);

        line_5 = new QFrame(tab);
        line_5->setObjectName("line_5");
        line_5->setFrameShape(QFrame::Shape::HLine);
        line_5->setFrameShadow(QFrame::Shadow::Sunken);

        vlEmployees->addWidget(line_5);

        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setObjectName("horizontalLayout_24");
        label_22 = new QLabel(tab);
        label_22->setObjectName("label_22");
        label_22->setFont(font);

        horizontalLayout_24->addWidget(label_22);

        edtEmployeeName = new QLineEdit(tab);
        edtEmployeeName->setObjectName("edtEmployeeName");
        edtEmployeeName->setFont(font);

        horizontalLayout_24->addWidget(edtEmployeeName);


        vlEmployees->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName("horizontalLayout_25");
        label_23 = new QLabel(tab);
        label_23->setObjectName("label_23");
        label_23->setFont(font);

        horizontalLayout_25->addWidget(label_23);

        edtEmployeeSalary = new QLineEdit(tab);
        edtEmployeeSalary->setObjectName("edtEmployeeSalary");
        edtEmployeeSalary->setFont(font);

        horizontalLayout_25->addWidget(edtEmployeeSalary);


        vlEmployees->addLayout(horizontalLayout_25);

        btnSaveEmployee = new QPushButton(tab);
        btnSaveEmployee->setObjectName("btnSaveEmployee");
        btnSaveEmployee->setFont(font);

        vlEmployees->addWidget(btnSaveEmployee);


        horizontalLayout_28->addLayout(vlEmployees);

        tblEmployees = new QTableWidget(tab);
        tblEmployees->setObjectName("tblEmployees");
        tblEmployees->setFont(font);
        tblEmployees->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tblEmployees->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
        tblEmployees->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        horizontalLayout_28->addWidget(tblEmployees);

        horizontalLayout_28->setStretch(0, 1);
        horizontalLayout_28->setStretch(1, 3);
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        horizontalLayout_33 = new QHBoxLayout(tab_2);
        horizontalLayout_33->setObjectName("horizontalLayout_33");
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName("groupBox");
        verticalLayout_7 = new QVBoxLayout(groupBox);
        verticalLayout_7->setObjectName("verticalLayout_7");
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName("horizontalLayout_26");
        label_25 = new QLabel(groupBox);
        label_25->setObjectName("label_25");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_25->sizePolicy().hasHeightForWidth());
        label_25->setSizePolicy(sizePolicy1);

        horizontalLayout_26->addWidget(label_25);

        edtInventoryCost = new QLineEdit(groupBox);
        edtInventoryCost->setObjectName("edtInventoryCost");

        horizontalLayout_26->addWidget(edtInventoryCost);


        verticalLayout_7->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName("horizontalLayout_27");
        label_26 = new QLabel(groupBox);
        label_26->setObjectName("label_26");
        sizePolicy1.setHeightForWidth(label_26->sizePolicy().hasHeightForWidth());
        label_26->setSizePolicy(sizePolicy1);

        horizontalLayout_27->addWidget(label_26);

        edtEmployeesCost = new QLineEdit(groupBox);
        edtEmployeesCost->setObjectName("edtEmployeesCost");

        horizontalLayout_27->addWidget(edtEmployeesCost);


        verticalLayout_7->addLayout(horizontalLayout_27);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName("horizontalLayout_29");
        label_27 = new QLabel(groupBox);
        label_27->setObjectName("label_27");
        sizePolicy1.setHeightForWidth(label_27->sizePolicy().hasHeightForWidth());
        label_27->setSizePolicy(sizePolicy1);

        horizontalLayout_29->addWidget(label_27);

        edtEnergyCost = new QLineEdit(groupBox);
        edtEnergyCost->setObjectName("edtEnergyCost");

        horizontalLayout_29->addWidget(edtEnergyCost);


        verticalLayout_7->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName("horizontalLayout_30");
        label_28 = new QLabel(groupBox);
        label_28->setObjectName("label_28");
        sizePolicy1.setHeightForWidth(label_28->sizePolicy().hasHeightForWidth());
        label_28->setSizePolicy(sizePolicy1);

        horizontalLayout_30->addWidget(label_28);

        edtRentCost = new QLineEdit(groupBox);
        edtRentCost->setObjectName("edtRentCost");

        horizontalLayout_30->addWidget(edtRentCost);


        verticalLayout_7->addLayout(horizontalLayout_30);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_2);


        horizontalLayout_33->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab_2);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_8 = new QVBoxLayout(groupBox_2);
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName("horizontalLayout_31");
        label_29 = new QLabel(groupBox_2);
        label_29->setObjectName("label_29");
        sizePolicy1.setHeightForWidth(label_29->sizePolicy().hasHeightForWidth());
        label_29->setSizePolicy(sizePolicy1);

        horizontalLayout_31->addWidget(label_29);

        edtTotalSale = new QLineEdit(groupBox_2);
        edtTotalSale->setObjectName("edtTotalSale");

        horizontalLayout_31->addWidget(edtTotalSale);


        verticalLayout_8->addLayout(horizontalLayout_31);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName("horizontalLayout_32");
        label_30 = new QLabel(groupBox_2);
        label_30->setObjectName("label_30");
        sizePolicy1.setHeightForWidth(label_30->sizePolicy().hasHeightForWidth());
        label_30->setSizePolicy(sizePolicy1);

        horizontalLayout_32->addWidget(label_30);

        edtProfit = new QLineEdit(groupBox_2);
        edtProfit->setObjectName("edtProfit");

        horizontalLayout_32->addWidget(edtProfit);


        verticalLayout_8->addLayout(horizontalLayout_32);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_8->addItem(verticalSpacer);


        horizontalLayout_33->addWidget(groupBox_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_33->addItem(horizontalSpacer_2);

        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget->addTab(tab_3, QString());

        verticalLayout_9->addWidget(tabWidget);

        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        verticalLayout_11 = new QVBoxLayout(tab_8);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(-1, 20, -1, -1);
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName("horizontalLayout_20");
        orderFilterArea = new QScrollArea(tab_8);
        orderFilterArea->setObjectName("orderFilterArea");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(orderFilterArea->sizePolicy().hasHeightForWidth());
        orderFilterArea->setSizePolicy(sizePolicy2);
        orderFilterArea->setMinimumSize(QSize(60, 0));
        orderFilterArea->setFont(font);
        orderFilterArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 58, 696));
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy3);
        vlOrderFilter = new QVBoxLayout(scrollAreaWidgetContents_2);
        vlOrderFilter->setObjectName("vlOrderFilter");
        vlOrderFilter->setContentsMargins(-1, -1, 0, -1);
        orderFilterArea->setWidget(scrollAreaWidgetContents_2);

        horizontalLayout_20->addWidget(orderFilterArea);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_18 = new QLabel(tab_8);
        label_18->setObjectName("label_18");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy4);
        label_18->setMinimumSize(QSize(50, 0));
        label_18->setFont(font);

        horizontalLayout->addWidget(label_18);

        edtSearchOrderFilter = new QLineEdit(tab_8);
        edtSearchOrderFilter->setObjectName("edtSearchOrderFilter");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(edtSearchOrderFilter->sizePolicy().hasHeightForWidth());
        edtSearchOrderFilter->setSizePolicy(sizePolicy5);
        edtSearchOrderFilter->setMinimumSize(QSize(300, 0));
        edtSearchOrderFilter->setFont(font);

        horizontalLayout->addWidget(edtSearchOrderFilter);


        verticalLayout_4->addLayout(horizontalLayout);

        orderCardHolder = new QScrollArea(tab_8);
        orderCardHolder->setObjectName("orderCardHolder");
        sizePolicy2.setHeightForWidth(orderCardHolder->sizePolicy().hasHeightForWidth());
        orderCardHolder->setSizePolicy(sizePolicy2);
        orderCardHolder->setMinimumSize(QSize(400, 0));
        orderCardHolder->setFont(font);
        orderCardHolder->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 398, 642));
        orderCardHolder->setWidget(scrollAreaWidgetContents);

        verticalLayout_4->addWidget(orderCardHolder);


        horizontalLayout_20->addLayout(verticalLayout_4);

        frame = new QFrame(tab_8);
        frame->setObjectName("frame");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy6);
        frame->setFont(font);
        frame->setStyleSheet(QString::fromUtf8("QFrame{\n"
"background-color: rgba(255,255,255,10);\n"
"border: 1px solid transparent;\n"
"border-radius: 15px;\n"
"}\n"
"\n"
"QPushButton {\n"
"background-color: rgba(255,255,255,10);\n"
"color: #ffffff;\n"
"border: 1px solid transparent;\n"
"border-radius: 12px;\n"
"padding: 10px 20px 10px 20px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: rgba(255,255,255,20);\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: rgba(255,255,255,10);\n"
"}\n"
"QPushButton:disabled {\n"
"background-color: #222222;\n"
"color: #666666;\n"
"}\n"
"QPushButton:focus {\n"
"outline: none;\n"
"border: 1px solid #0066FF;\n"
"}\n"
"QListView {\n"
"background-color: rgba(255,255,255,10);\n"
"border: 1px solid transparent;\n"
"border-radius: 15px;\n"
"padding: 5px;\n"
"}\n"
"QListView::item {\n"
"border: none;\n"
"padding: 5px;\n"
"margin: 5px;\n"
"color: #ffffff;\n"
"}\n"
"QListView::item:selected {\n"
"background-color: #0066FF;\n"
"border: 1px solid transparent;\n"
"border-radius: 5px;\n"
"color: #ffffff;\n"
"}\n"
"QListView:"
                        ":item:selected:focus {\n"
"border: 1px solid #0066FF;\n"
"}\n"
"QListView::item:hover {\n"
"background-color: rgba(0,102,255,20);\n"
"border: 1px solid transparent;\n"
"border-radius: 5px;\n"
"color: #0066FF;\n"
"}\n"
"QListView::item:disabled {\n"
"color: #666666;\n"
"background-color: #222222;\n"
"}\n"
"\n"
"QComboBox {\n"
"background-color: rgba(255,255,255,10);\n"
"border: 1px solid transparent;\n"
"border-radius: 10px;\n"
"padding: 8px;\n"
"color: #ffffff;\n"
"}\n"
"QComboBox:hover {\n"
"background-color: rgba(255,255,255,20);\n"
"}\n"
"QComboBox:disabled {\n"
"background-color: rgba(255,255,255,30);\n"
"color: #666666;\n"
"}\n"
"QComboBox:pressed {\n"
"background-color: rgba(255,255,255,10);\n"
"}\n"
"QComboBox QAbstractItemView {\n"
"background: solid transparent;\n"
"border: 1px solid transparent;\n"
"border-radius: 5px;\n"
"}\n"
"QComboBox::item {\n"
"padding:5px 0px 5px 0px;\n"
"max-height: 18px;\n"
"}\n"
"QComboBox::item:selected {\n"
"background: solid #0066FF;\n"
"border: 1px solid transparent;\n"
""
                        "border-radius: 5px;\n"
"}\n"
"\n"
"QTableWidget {\n"
"background-color: rgba(255,255,255,10);\n"
"gridline-color: rgba(255,255,255,30);\n"
"border: 1px solid transparent;\n"
"border-radius: 15px;\n"
"}\n"
"\n"
"QTableWidget QHeaderView{\n"
"background-color:  transparent;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal {\n"
"background-color:  transparent;\n"
"color: #ffffff;\n"
"padding: 4px;\n"
"}\n"
"\n"
"QHeaderView::section::vertical {\n"
"background-color:  transparent;\n"
"color: #ffffff;\n"
"padding: 4px;\n"
"}\n"
"\n"
"QTableCornerButton::section {\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"background-color: rgba(255,255,255,10);\n"
"padding: 7px;\n"
"border: 1px solid transparent;\n"
"}\n"
"\n"
"QTableWidget::item:alternate {\n"
"background-color: rgba(255,255,255,30);\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"border-bottom: 2px solid #00DC72;\n"
"color: white;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"background-color: rgba(255,255,255,20);\n"
"color: white"
                        ";\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"background-color: transparent;\n"
"width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"background-color: rgba(255,255,255,30);\n"
"border: 1px solid transparent;\n"
"border-radius: 5px;\n"
"min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"background-color: transparent;\n"
"width: 10px;\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"background-color: rgba(255,255,255,30);\n"
"border: 1px solid transparent;\n"
"border-radius: 5px;\n"
"min-height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {\n"
"background-color: transparent;\n"
"}\n"
"\n"
"QLabel{\n"
"background-color: transparent;\n"
"}"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        vlOrderList = new QVBoxLayout(frame);
        vlOrderList->setObjectName("vlOrderList");
        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        label_16 = new QLabel(frame);
        label_16->setObjectName("label_16");
        sizePolicy4.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy4);
        label_16->setFont(font);

        horizontalLayout_18->addWidget(label_16);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_18->addItem(horizontalSpacer);

        btnClearOrderList = new QPushButton(frame);
        btnClearOrderList->setObjectName("btnClearOrderList");
        btnClearOrderList->setFont(font);
        btnClearOrderList->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"padding: 2px 14px 4px 14px;\n"
"border-radius: 5px;\n"
"}"));

        horizontalLayout_18->addWidget(btnClearOrderList);


        vlOrderList->addLayout(horizontalLayout_18);

        tblOrderList = new QTableWidget(frame);
        tblOrderList->setObjectName("tblOrderList");
        tblOrderList->setFont(font);
        tblOrderList->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tblOrderList->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        vlOrderList->addWidget(tblOrderList);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        label_14 = new QLabel(frame);
        label_14->setObjectName("label_14");
        sizePolicy4.setHeightForWidth(label_14->sizePolicy().hasHeightForWidth());
        label_14->setSizePolicy(sizePolicy4);
        label_14->setFont(font);

        horizontalLayout_17->addWidget(label_14);

        lblOrderTotal = new QLabel(frame);
        lblOrderTotal->setObjectName("lblOrderTotal");
        lblOrderTotal->setFont(font1);
        lblOrderTotal->setStyleSheet(QString::fromUtf8("QLabel{\n"
"font-size: 18px;\n"
"font-style: bold;\n"
"}"));

        horizontalLayout_17->addWidget(lblOrderTotal);


        vlOrderList->addLayout(horizontalLayout_17);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName("horizontalLayout_22");
        label_19 = new QLabel(frame);
        label_19->setObjectName("label_19");
        sizePolicy4.setHeightForWidth(label_19->sizePolicy().hasHeightForWidth());
        label_19->setSizePolicy(sizePolicy4);
        label_19->setFont(font);

        horizontalLayout_22->addWidget(label_19);

        edtOrderDiscount = new QLineEdit(frame);
        edtOrderDiscount->setObjectName("edtOrderDiscount");
        edtOrderDiscount->setEnabled(false);

        horizontalLayout_22->addWidget(edtOrderDiscount);


        vlOrderList->addLayout(horizontalLayout_22);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        label_17 = new QLabel(frame);
        label_17->setObjectName("label_17");
        sizePolicy4.setHeightForWidth(label_17->sizePolicy().hasHeightForWidth());
        label_17->setSizePolicy(sizePolicy4);
        label_17->setFont(font);

        horizontalLayout_19->addWidget(label_17);

        cbOrderCustomer = new QComboBox(frame);
        cbOrderCustomer->setObjectName("cbOrderCustomer");
        cbOrderCustomer->setEnabled(false);
        cbOrderCustomer->setFont(font);
        cbOrderCustomer->setEditable(true);

        horizontalLayout_19->addWidget(cbOrderCustomer);


        vlOrderList->addLayout(horizontalLayout_19);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        label_15 = new QLabel(frame);
        label_15->setObjectName("label_15");
        sizePolicy4.setHeightForWidth(label_15->sizePolicy().hasHeightForWidth());
        label_15->setSizePolicy(sizePolicy4);
        label_15->setFont(font);

        horizontalLayout_21->addWidget(label_15);

        lblCheckout = new QLabel(frame);
        lblCheckout->setObjectName("lblCheckout");
        lblCheckout->setFont(font1);
        lblCheckout->setStyleSheet(QString::fromUtf8("QLabel{\n"
"color: #00DC72;\n"
"font-size: 18px;\n"
"font-style: bold;\n"
"}"));

        horizontalLayout_21->addWidget(lblCheckout);


        vlOrderList->addLayout(horizontalLayout_21);

        btnSubmitOrder = new QPushButton(frame);
        btnSubmitOrder->setObjectName("btnSubmitOrder");
        btnSubmitOrder->setEnabled(false);
        btnSubmitOrder->setFont(font);

        vlOrderList->addWidget(btnSubmitOrder);


        horizontalLayout_20->addWidget(frame);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        label_13 = new QLabel(tab_8);
        label_13->setObjectName("label_13");
        sizePolicy4.setHeightForWidth(label_13->sizePolicy().hasHeightForWidth());
        label_13->setSizePolicy(sizePolicy4);
        label_13->setFont(font);
        label_13->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_16->addWidget(label_13);


        verticalLayout_3->addLayout(horizontalLayout_16);

        tblRecentOrder = new QTableWidget(tab_8);
        tblRecentOrder->setObjectName("tblRecentOrder");
        sizePolicy3.setHeightForWidth(tblRecentOrder->sizePolicy().hasHeightForWidth());
        tblRecentOrder->setSizePolicy(sizePolicy3);
        tblRecentOrder->setMinimumSize(QSize(0, 0));
        tblRecentOrder->setFont(font);
        tblRecentOrder->setStyleSheet(QString::fromUtf8("QLineEdit{\n"
"background: solid #111111;\n"
"padding: 5px;\n"
"min-height: 18px;\n"
"margin: 0px;\n"
"}"));
        tblRecentOrder->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tblRecentOrder->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tblRecentOrder->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout_3->addWidget(tblRecentOrder);


        horizontalLayout_20->addLayout(verticalLayout_3);


        verticalLayout_11->addLayout(horizontalLayout_20);

        tabWidget_2->addTab(tab_8, QString());

        verticalLayout_5->addWidget(tabWidget_2);

        verticalLayout_5->setStretch(0, 1);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        verticalLayout_10->addWidget(stackedWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1064, 25));
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(cbStorageCat, edtCustomerPhone);
        QWidget::setTabOrder(edtCustomerPhone, edtProductTitle);
        QWidget::setTabOrder(edtProductTitle, edtPrice);
        QWidget::setTabOrder(edtPrice, edtCount);
        QWidget::setTabOrder(edtCount, edtProductDes);
        QWidget::setTabOrder(edtProductDes, edtCatTitle);
        QWidget::setTabOrder(edtCatTitle, edtCatDes);
        QWidget::setTabOrder(edtCatDes, btnDelCat);
        QWidget::setTabOrder(btnDelCat, tblStorageCat);
        QWidget::setTabOrder(tblStorageCat, tblStorageProduct);
        QWidget::setTabOrder(tblStorageProduct, edtCustomerName);
        QWidget::setTabOrder(edtCustomerName, edtCustomerBalance);
        QWidget::setTabOrder(edtCustomerBalance, chbDeptor);
        QWidget::setTabOrder(chbDeptor, tblCustomers);
        QWidget::setTabOrder(tblCustomers, btnSaveCustomer);
        QWidget::setTabOrder(btnSaveCustomer, rbProduct);
        QWidget::setTabOrder(rbProduct, rbCat);
        QWidget::setTabOrder(rbCat, btnCatEdit);
        QWidget::setTabOrder(btnCatEdit, btnSaveStorage);

        retranslateUi(MainWindow);
        QObject::connect(edtProductTitle, &QLineEdit::returnPressed, btnSaveStorage, qOverload<>(&QPushButton::click));
        QObject::connect(edtPrice, &QLineEdit::returnPressed, btnSaveStorage, qOverload<>(&QPushButton::click));
        QObject::connect(edtCount, &QLineEdit::returnPressed, btnSaveStorage, qOverload<>(&QPushButton::click));
        QObject::connect(edtProductDes, &QLineEdit::returnPressed, btnSaveStorage, qOverload<>(&QPushButton::click));
        QObject::connect(edtCatTitle, &QLineEdit::returnPressed, btnSaveStorage, qOverload<>(&QPushButton::click));
        QObject::connect(edtCatDes, &QLineEdit::returnPressed, btnSaveStorage, qOverload<>(&QPushButton::click));
        QObject::connect(edtCustomerName, &QLineEdit::returnPressed, btnSaveCustomer, qOverload<>(&QPushButton::click));
        QObject::connect(edtCustomerBalance, &QLineEdit::returnPressed, btnSaveCustomer, qOverload<>(&QPushButton::click));
        QObject::connect(edtCustomerPhone, &QLineEdit::returnPressed, btnSaveCustomer, qOverload<>(&QPushButton::click));
        QObject::connect(edtCustomrDiscount, &QLineEdit::returnPressed, btnSaveCustomer, qOverload<>(&QPushButton::click));

        stackedWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\331\205\330\257\333\214\330\261\333\214\330\252 \330\247\331\206\330\250\330\247\330\261", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\330\250\330\256\330\264", nullptr));
        btnCatEdit->setText(QString());
        rbProduct->setText(QCoreApplication::translate("MainWindow", "\331\205\330\255\330\265\331\210\331\204", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\330\271\331\206\331\210\330\247\331\206 \331\205\330\255\330\265\331\210\331\204", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\331\202\333\214\331\205\330\252", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\330\252\330\271\330\257\330\247\330\257", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252", nullptr));
        rbCat->setText(QCoreApplication::translate("MainWindow", "\330\257\330\263\330\252\331\207\342\200\214\330\250\331\206\330\257\333\214", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\330\271\331\206\331\210\330\247\331\206", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\330\252\331\210\330\266\333\214\330\255\330\247\330\252", nullptr));
        btnSaveStorage->setText(QCoreApplication::translate("MainWindow", "\330\253\330\250\330\252 \331\210 \330\260\330\256\333\214\330\261\331\207", nullptr));
        btnDelCat->setText(QCoreApplication::translate("MainWindow", "\330\255\330\260\331\201 \330\250\330\256\330\264 \330\247\331\206\330\252\330\256\330\247\330\250 \330\264\330\257\331\207", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(storage), QCoreApplication::translate("MainWindow", "\331\205\330\257\333\214\330\261\333\214\330\252 \330\247\331\206\330\250\330\247\330\261", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\331\205\330\257\333\214\330\261\333\214\330\252 \331\205\330\264\330\252\330\261\333\214\330\247\331\206", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\331\206\330\247\331\205 \331\205\330\264\330\252\330\261\333\214", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\331\205\331\210\330\254\331\210\330\257\333\214", nullptr));
        edtCustomerBalance->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        chbDeptor->setText(QCoreApplication::translate("MainWindow", "\330\250\330\257\331\207\332\251\330\247\330\261", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "\330\257\330\261\330\265\330\257 \330\252\330\256\331\201\333\214\331\201", nullptr));
        edtCustomrDiscount->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "\330\264\331\205\330\247\330\261\331\207 \330\252\331\205\330\247\330\263", nullptr));
        btnSaveCustomer->setText(QCoreApplication::translate("MainWindow", "\330\260\330\256\333\214\330\261\331\207 \331\210 \330\253\330\250\330\252", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\331\205\330\264\330\252\330\261\333\214\330\247\331\206", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "\331\205\330\257\333\214\330\261\333\214\330\252 \332\251\330\247\330\261\332\251\331\206\330\247\331\206", nullptr));
        label_22->setText(QCoreApplication::translate("MainWindow", "\331\206\330\247\331\205", nullptr));
        label_23->setText(QCoreApplication::translate("MainWindow", "\330\255\331\202\331\210\331\202", nullptr));
        edtEmployeeSalary->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnSaveEmployee->setText(QCoreApplication::translate("MainWindow", "\330\260\330\256\333\214\330\261\331\207 \331\210 \330\253\330\250\330\252", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\332\251\330\247\330\261\332\251\331\206\330\247\331\206", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\331\207\330\262\333\214\331\206\331\207\342\200\214\332\251\330\261\330\257", nullptr));
        label_25->setText(QCoreApplication::translate("MainWindow", "\331\205\331\210\330\247\330\257 \330\247\331\210\331\204\333\214\331\207", nullptr));
        label_26->setText(QCoreApplication::translate("MainWindow", "\332\251\330\247\330\261\332\251\331\206\330\247\331\206", nullptr));
        label_27->setText(QCoreApplication::translate("MainWindow", "\331\207\330\262\333\214\331\206\331\207 \330\247\331\206\330\261\332\230\333\214", nullptr));
        label_28->setText(QCoreApplication::translate("MainWindow", "\330\247\330\254\330\247\330\261\331\207", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\330\257\330\261\330\242\331\205\330\257", nullptr));
        label_29->setText(QCoreApplication::translate("MainWindow", "\331\201\330\261\331\210\330\264", nullptr));
        label_30->setText(QCoreApplication::translate("MainWindow", "\330\263\331\210\330\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\330\255\330\263\330\247\330\250\330\257\330\247\330\261\333\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\330\252\331\206\330\270\333\214\331\205\330\247\330\252", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QCoreApplication::translate("MainWindow", "\331\205\330\257\333\214\330\261\333\214\330\252", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "\330\254\330\263\330\252 \331\210 \330\254\331\210", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "\330\263\331\201\330\247\330\261\330\264 \330\254\330\257\333\214\330\257", nullptr));
        btnClearOrderList->setText(QCoreApplication::translate("MainWindow", "\330\255\330\260\331\201 \331\207\331\205\331\207", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "\331\205\330\254\331\205\331\210\330\271", nullptr));
        lblOrderTotal->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "\330\257\330\261\330\265\330\257 \330\252\330\256\331\201\333\214\331\201", nullptr));
        edtOrderDiscount->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "\331\205\330\264\330\252\330\261\333\214", nullptr));
        cbOrderCustomer->setPlaceholderText(QString());
        label_15->setText(QCoreApplication::translate("MainWindow", "\331\202\330\247\330\250\331\204 \331\276\330\261\330\257\330\247\330\256\330\252", nullptr));
        lblCheckout->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnSubmitOrder->setText(QCoreApplication::translate("MainWindow", "\330\253\330\250\330\252 \330\263\331\201\330\247\330\261\330\264", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "\330\263\331\201\330\247\330\261\330\264\330\247\330\252 \330\247\330\256\333\214\330\261", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QCoreApplication::translate("MainWindow", "\330\253\330\250\330\252 \330\263\331\201\330\247\330\261\330\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
