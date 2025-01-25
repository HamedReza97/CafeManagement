#include "mainwindow.h"
#include "customer.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>
#include <QCompleter>
#include <QtWidgets/qgroupbox.h>
#include <QStandardItem>
#include <QDateTime>
#include <QGraphicsRotation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,customer(0, "", 0, 0, "", 0)
{
    ui->setupUi(this);

    //Daatabase Connection
    database = QSqlDatabase::addDatabase("QMARIADB");
    database.setDatabaseName("cafe_mars");
    query = QSqlQuery(database);
    if (!database.open()) {
        QMessageBox::warning(this,"Error",query.lastError().text(),QMessageBox::Ok);
        ui->tabWidget->setEnabled(false);
        return;
    }
    //Models Initilization
    productModel = new QSqlTableModel(this);
    productModel->setTable("products");
    productModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    customersModel = new QSqlTableModel(this);
    customersModel->setTable("customers");
    customersModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    catModel = new QSqlTableModel(this);
    catModel->setTable("catagories");
    catModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    subCatModel = new QSqlTableModel(this);
    subCatModel->setTable("sub_catagories");
    subCatModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    orderModel = new QSqlTableModel(this);
    orderModel->setTable("orders");
    orderModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    orderDetailModel = new QSqlTableModel(this);
    orderDetailModel->setTable("order_details");
    orderDetailModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    employeeModel = new QSqlTableModel(this);
    employeeModel->setTable("employees");
    employeeModel->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // Initilization
    initialCatagories();
    QStringList catName = ui->cbStorageCat->itemText(0).split("|");
    lastCat = catName[1];
    initialCatagories();
    initialStorage(true,true);
    initialCustomers();
    initialOrder(true,true,true);
    delete ui->scrollAreaWidgetContents->layout();
    initialEmployees();
    addProductTab(-1); 

    // Connections
    connect(ui->tblStorageCat->verticalHeader(), &QHeaderView::sectionClicked, this, [this](int section) {
        if(QMessageBox::question(this, "حذف دسته بندی", "در صورت ادامه دسته‌بندی انتخاب شده و تمامی محصولات این دسته‌بندی حذف خواهد شد. ادامه می‌دهید؟",
                                  QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes){
        int id = ui->tblStorageCat->item(section,0)->text().toInt();
        delProduct(-1, id);
        delSubCat(id, -1);
        }
    });

    connect(ui->tblStorageProduct->verticalHeader(), &QHeaderView::sectionClicked, this, [this](int section) {
        int id = ui->tblStorageProduct->item(section,0)->text().toInt();
        delProduct(id, -1);
    });

    connect(ui->tblCustomers->verticalHeader(), &QHeaderView::sectionClicked, this, [this](int section){
        int id = ui->tblCustomers->item(section, 0)->text().toInt();
        delCustomer(id);
    });

    connect(ui->tblOrderList->verticalHeader(), &QHeaderView::sectionClicked, this, [this](int section){
        int id = ui->tblOrderList->item(section, 0)->text().toInt();
        delOrder(id);
    });

    connect(ui->tblRecentOrder->verticalHeader(), &QHeaderView::sectionClicked, this, [this](int section) {
        int id = ui->tblRecentOrder->item(section,0)->text().toInt();
        delRecentOrder(id);
    });

    connect(ui->tblEmployees->verticalHeader(), &QHeaderView::sectionClicked, this, [this](int section){
        int id = ui->tblEmployees->item(section,0)->text().toInt();
        delEmployee(id);
    });


    // Setting Validators
    QRegularExpression regex("[0-9۰-۹]*");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    QRegularExpression regexPhone("[0-9۰-۹+-]*");
    QRegularExpressionValidator *validatorPhone = new QRegularExpressionValidator(regexPhone, this);

    ui->edtCount->setValidator(validator);
    ui->edtPrice->setValidator(validator);
    ui->edtOrderDiscount->setValidator(validator);
    ui->edtCustomerBalance->setValidator(validator);
    ui->edtCustomrDiscount->setValidator(validator);
    ui->edtCustomerPhone->setValidator(validatorPhone);
    ui->edtEmployeeSalary->setValidator(validator);

    //UI Widgets Initilization
    ui->btnCatEdit->setIcon(QIcon(":icon/edit.svg"));
    ui->btnCatEdit->setIconSize(QSize(18,18));

    ui->tblOrderList->setRowCount(0);
    ui->tblOrderList->setColumnCount(5);
    ui->tblOrderList->setHorizontalHeaderLabels({"شناسه", "نام", "قیمت", "تعداد","بیرون‌بر"});
    ui->tblOrderList->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tblOrderList->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblOrderList->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);
    ui->tblOrderList->setColumnWidth(0, 70);
    ui->tblOrderList->horizontalHeader()->setSectionResizeMode(4,QHeaderView::Fixed);
    ui->tblOrderList->setColumnWidth(4, 50);

    ui->orderCardHolder->setWidgetResizable(true);
    ui->orderFilterArea->setWidgetResizable(true);
    ui->orderFilterArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->btnDelCat->setEnabled(false);


}

MainWindow::~MainWindow()
{
    try {
        delete ui;
        delete btnCancel;
        delete edtCat;
        foreach (QWidget *card, productCardList) {
            delete card;
        }

        foreach (QPushButton *button, buttonList) {
            delete button;
        }
        buttonList.clear();
        productCardList.clear();
        delete productModel;
        delete customersModel;
        delete catModel;
        delete subCatModel;
        delete orderProductLayout;
        delete orderCustomer;
        delete orderModel;
    } catch (...) {
        qDebug() << "Unkown Error occurred";
    }
}

/*
============================================================================================
SECTION: Initialization
============================================================================================
*/

void MainWindow::initialStorage(bool sub_cat, bool product){
    // Initilization Sub Categories
    if(sub_cat){
        ui->tblStorageCat->clear();
        ui->tblStorageCat->setRowCount(0);

        ui->tblStorageCat->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
        ui->tblStorageCat->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tblStorageCat->setColumnCount(3);
        ui->tblStorageCat->setHorizontalHeaderLabels({"شناسه", "نام دسته‌بندی", "توضیحات"});
        ui->tblStorageCat->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);
        ui->tblStorageCat->setColumnWidth(0,70);

        QStringList catIdStr = ui->cbStorageCat->currentText().split("|");
        int index = catIdStr[0].trimmed().toInt();

        subCatModel->setTable("sub_categories");
        subCatModel->setFilter(QString("parent = %1").arg(index));
        subCatModel->select();
        if(subCatModel->rowCount() > 0)
        {
        for(int i = 0; i < subCatModel->rowCount(); i++){

            ui->tblStorageCat->insertRow(i);
            ui->tblStorageCat->setItem(i, 0, new QTableWidgetItem(subCatModel->data(subCatModel->index(i,0)).toString()));
            ui->tblStorageCat->setItem(i, 1, new QTableWidgetItem(subCatModel->data(subCatModel->index(i,1)).toString()));
            ui->tblStorageCat->setItem(i, 2, new QTableWidgetItem(subCatModel->data(subCatModel->index(i,2)).toString()));

            ui->tblStorageCat->item(i,0)->setTextAlignment(Qt::AlignCenter);
            ui->tblStorageCat->item(i,1)->setTextAlignment(Qt::AlignCenter);
            ui->tblStorageCat->item(i,2)->setTextAlignment(Qt::AlignCenter);

            QIcon addRowIcon(":/icon/trash.svg");
            QTableWidgetItem *headerItem = new QTableWidgetItem;
            headerItem->setIcon(addRowIcon);
            ui->tblStorageCat->setVerticalHeaderItem(i, headerItem);
        }
        }
    }

    // Initilization Products
    if(product){
        int parent = ui->tblStorageCat->rowCount() > 0 ? ui->tblStorageCat->item(subCatRow, 0)->text().toInt() : 0;
        ui->tblStorageProduct->clear();
        ui->tblStorageProduct->setRowCount(0);

        ui->tblStorageProduct->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
        ui->tblStorageProduct->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->tblStorageProduct->setColumnCount(5);
        ui->tblStorageProduct->setHorizontalHeaderLabels({"شناسه", "نام محصول", "قیمت", "تعداد", "توضیحات"});
        ui->tblStorageProduct->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);
        ui->tblStorageProduct->setColumnWidth(0,70);

        productModel->setTable("products");
        productModel->setFilter(QString("parent = %1").arg(parent));
        productModel->select();

        if(productModel->rowCount() > 0){
        for(int i = 0; i < productModel->rowCount(); i++){
            ui->tblStorageProduct->insertRow(i);
            ui->tblStorageProduct->setItem(i, 0, new QTableWidgetItem(productModel->data(productModel->index(i,0)).toString()));
            ui->tblStorageProduct->setItem(i, 1, new QTableWidgetItem(productModel->data(productModel->index(i,1)).toString()));
            ui->tblStorageProduct->setItem(i, 2, new QTableWidgetItem(locale.toString(productModel->data(productModel->index(i,2)).toInt())));
            ui->tblStorageProduct->setItem(i, 3, new QTableWidgetItem(productModel->data(productModel->index(i,4)).toString()));
            ui->tblStorageProduct->setItem(i, 4, new QTableWidgetItem(productModel->data(productModel->index(i,3)).toString()));

            ui->tblStorageProduct->item(i,0)->setTextAlignment(Qt::AlignCenter);
            ui->tblStorageProduct->item(i,1)->setTextAlignment(Qt::AlignCenter);
            ui->tblStorageProduct->item(i,2)->setTextAlignment(Qt::AlignCenter);
            ui->tblStorageProduct->item(i,3)->setTextAlignment(Qt::AlignCenter);
            ui->tblStorageProduct->item(i,4)->setTextAlignment(Qt::AlignCenter);

            QIcon addRowIcon(":/icon/trash.svg");
            QTableWidgetItem *headerItem = new QTableWidgetItem;
            headerItem->setIcon(addRowIcon);
            ui->tblStorageProduct->setVerticalHeaderItem(i, headerItem);
        }
        }
    }

}

void MainWindow::initialCatagories(){

    // Initilization Categories
    catModel->setTable("categories");
    catModel->select();

    QList <QString> cat;
    ui->cbStorageCat->blockSignals(true);
    ui->cbStorageCat->clear();

    for(int i = 0; i < catModel->rowCount(); i++){
        cat.append(catModel->data(catModel->index(i,0)).toString() + " | " + catModel->data(catModel->index(i,1)).toString());
    }

    ui->cbStorageCat->addItems(cat);
    QCompleter *completer = new QCompleter(cat, ui->cbStorageCat);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->cbStorageCat->setCompleter(completer);
    ui->cbStorageCat->blockSignals(false);

    if(!lastCat.isEmpty())
    {
        int id = ui->cbStorageCat->findText(lastCat,Qt::MatchFlag(Qt::MatchContains));
        ui->cbStorageCat->setCurrentIndex(id);
    }
    else
    {
        if(ui->cbStorageCat->count()>0){
            ui->cbStorageCat->setCurrentIndex(ui->cbStorageCat->count()-1);
    }
    }
}

void MainWindow::delProduct(int id, int parent)
{
    QString qry;
    // Delete single product
    if (id != -1 && ui->tblStorageProduct->rowCount() > 0) {
        productModel->setTable("products");
        productModel->setFilter(QString("id = %1").arg(id));
        productModel->select();
        if (productModel->rowCount() > 0) {
            productModel->removeRows(0, productModel->rowCount());
            if(!productModel->submitAll()){
                QMessageBox::warning(this, "Error", productModel->lastError().text(), QMessageBox::Ok);
                return;
            }
        }
        initialStorage(false, true);
    }
    // Delete products of a sub category
    if(parent != -1){
        productModel->setTable("products");
        productModel->setFilter(QString("parent = %1").arg(parent));
        productModel->select();
        if (productModel->rowCount() > 0) {
            productModel->removeRows(0, productModel->rowCount());
            if(!productModel->submitAll()){
                QMessageBox::warning(this, "Error", productModel->lastError().text(), QMessageBox::Ok);
                return;
            }
        }
        initialStorage(false, true);
    }
    // Resetting auto increment if count = 0
    productModel->setTable("products");
    productModel->select();
    if (productModel->rowCount() == 0) {
        qry = "TRUNCATE TABLE products;";
        query.prepare(qry);
        if (!query.exec()) {
            QMessageBox::warning(this, "Error", query.lastError().text(), QMessageBox::Ok);
            return;
        }
    }
}

void MainWindow::delSubCat(int id, int parent)
{
    QString qry;
    //Deleting single subcategory
    if (id != -1 && ui->tblStorageCat->rowCount() > 0) {

        subCatModel->setTable("sub_categories");
        subCatModel->setFilter(QString("id = %1").arg(id));
        subCatModel->select();
        if (subCatModel->rowCount() > 0) {
            subCatModel->removeRows(0, subCatModel->rowCount());
            if(!subCatModel->submitAll())
            {
                QMessageBox::warning(this, "Error", subCatModel->lastError().text(), QMessageBox::Ok);
                return;
            }
        }

        initialStorage(true, false);
    }

    //Deleting sub categories of a category
    if(parent != -1){

        subCatModel->setTable("sub_categories");
        subCatModel->setFilter(QString("parent = %1").arg(parent));
        subCatModel->select();
        if (subCatModel->rowCount() > 0) {
            subCatModel->removeRows(0, subCatModel->rowCount());
            if(!subCatModel->submitAll())
            {
                QMessageBox::warning(this, "Error", subCatModel->lastError().text(), QMessageBox::Ok);
                return;
            }
        }

        initialStorage(true, false);
    }

    // Resetting auto increment if count = 0
    subCatModel->setTable("sub_categories");
    subCatModel->select();
    if (subCatModel->rowCount() == 0) {
        qry = "TRUNCATE TABLE sub_categories;";
        query.prepare(qry);
        if (!query.exec()) {
            QMessageBox::warning(this, "Error", query.lastError().text(), QMessageBox::Ok);
            return;
        }
    }
}

void MainWindow::initialCustomers()
{
    // Initialization of customers
    ui->tblCustomers->clear();
    ui->tblCustomers->setRowCount(0);
    ui->tblCustomers->setColumnCount(6);
    ui->tblCustomers->setHorizontalHeaderLabels({"شناسه", "نام", "موجودی" ,"درصد تخفیف", "شماره تماس", "مجموع خرید"});
    ui->tblCustomers->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tblCustomers->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblCustomers->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Fixed);
    ui->tblCustomers->setColumnWidth(0, 80);
    
    customersModel->setTable("customers");
    customersModel->select();
    
    for(int i = 0; i < customersModel->rowCount(); i++)
    {
        ui->tblCustomers->insertRow(i);
        ui->tblCustomers->setItem(i, 0, new QTableWidgetItem(customersModel->data(customersModel->index(i,0)).toString()));
        ui->tblCustomers->setItem(i, 1, new QTableWidgetItem(customersModel->data(customersModel->index(i,1)).toString()));
        ui->tblCustomers->setItem(i, 2, new QTableWidgetItem(locale.toString(customersModel->data(customersModel->index(i,2)).toInt())));
        ui->tblCustomers->setItem(i, 3, new QTableWidgetItem(customersModel->data(customersModel->index(i,5)).toString()));
        ui->tblCustomers->setItem(i, 4, new QTableWidgetItem(customersModel->data(customersModel->index(i,3)).toString()));
        ui->tblCustomers->setItem(i, 5, new QTableWidgetItem(locale.toString(customersModel->data(customersModel->index(i,4)).toInt())));


        ui->tblCustomers->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tblCustomers->item(i, 1)->setTextAlignment(Qt::AlignCenter);
        ui->tblCustomers->item(i, 2)->setTextAlignment(Qt::AlignCenter);
        ui->tblCustomers->item(i, 3)->setTextAlignment(Qt::AlignCenter);
        ui->tblCustomers->item(i, 4)->setTextAlignment(Qt::AlignCenter);
        ui->tblCustomers->item(i, 5)->setTextAlignment(Qt::AlignCenter);

        if(locale.toInt(ui->tblCustomers->item(i,2)->text()) < 0){
            ui->tblCustomers->item(i, 2)->setForeground(QBrush(QColor("#e81051")));
        }
        else{
            ui->tblCustomers->item(i, 2)->setForeground(QBrush(QColor("#37c778")));
        }
        
        QIcon icon(":/icon/trash.svg");
        QTableWidgetItem *headerItem = new QTableWidgetItem();
        headerItem->setIcon(icon);
        ui->tblCustomers->setVerticalHeaderItem(i, headerItem);
    }
}

void MainWindow::delCustomer(int id)
{
    //Delete selected customer
    if(QMessageBox::question(this, "حذف مشتری", "مشتری انتخاب شده حذف خواهد شد. ادامه می‌دهید؟", QMessageBox::Yes,
                              QMessageBox::No) == QMessageBox::Yes)
    {
        customersModel->setTable("customers");
        customersModel->setFilter(QString("id = %1").arg(id));
        customersModel->select();
        if(customersModel->rowCount() > 0){
            customersModel->removeRows(0, customersModel->rowCount());
            if(!customersModel->submitAll())
            {
                QMessageBox::warning(this, "Error", customersModel->lastError().text(), QMessageBox::Ok);
                return;
            }
        }
        customersModel->setTable("customers");
        customersModel->select();
        if(customersModel->rowCount() == 0){
            QString qry = "TRUNCATE TABLE customers;";
            query.prepare(qry);
            if(!query.exec()){
                QMessageBox::warning(this,"Error",query.lastError().text(),QMessageBox::Ok);
                return;
            }
        }

    initialCustomers();
    }
}

QGroupBox* MainWindow::createProductCard(int id, QString name, int price, int count)
{
    QGroupBox *card = new QGroupBox;

    card->setStyleSheet(R"(QGroupBox {
                        border: 1px solid rgba(35,35,35,180);
                        background: solid rgba(30,30,30,80);
                        border-radius: 20px;
                        padding: 5px;
                        margin: 5px;})");

    QHBoxLayout *mainLayout = new QHBoxLayout(card);
    QVBoxLayout *vLayout = new QVBoxLayout;
    QHBoxLayout *hLayout = new QHBoxLayout;
    QHBoxLayout *hLayout2 = new QHBoxLayout;

    QLabel *idLabel = new QLabel(QString::number(id));
    idLabel->setFont(QFont("Peyda", 16, 1));
    idLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    hLayout->addWidget(idLabel);
    QLabel *nameLabel = new QLabel(name);
    nameLabel->setFont(QFont("Peyda", 16, 1));
    nameLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    hLayout->addWidget(nameLabel);
    hLayout->addSpacerItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum));

    QLabel *priceLabel = new QLabel("قیمت: "+locale.toString(price));
    priceLabel->setFont(ui->centralwidget->font());
    priceLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    hLayout2->addWidget(priceLabel);

    QLabel  *countLabel = new QLabel("موجودی: "+QString::number(count));
    countLabel->setFont(ui->centralwidget->font());
    countLabel->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    hLayout2->addWidget(countLabel);

    vLayout->addLayout(hLayout);
    vLayout->addLayout(hLayout2);
    mainLayout->addLayout(vLayout);
    mainLayout->addSpacerItem(new QSpacerItem(40,20,QSizePolicy::Expanding,QSizePolicy::Minimum));

    QLineEdit *edtOrderCount = new QLineEdit(QString::number(0));
    edtOrderCount->setAlignment(Qt::AlignCenter);
    QRegularExpression regex("[0-9۰-۹]*");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex);
    edtOrderCount->setValidator(validator);
    edtOrderCount->setStyleSheet("QLineEdit{padding: 5px; margin: 0px; min-width: 40px; max-width: 40px; min-height: 24px; max-height: 24px;}");
    edtOrderCount->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QPushButton *addButton = new QPushButton("+");
    QPushButton *decreaseButton = new QPushButton("-");
    decreaseButton->setEnabled(false);

    QString btnStyleSheet = R"(
                        QPushButton{
                        padding: 5px;
                        margin: 0px;
                        min-height: 24px;
                        min-width: 24px;
                        max-height: 24px;
                        max-width: 24px;})";

    addButton->setStyleSheet(btnStyleSheet);
    decreaseButton->setStyleSheet(btnStyleSheet);

    addButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    edtOrderCount->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    decreaseButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

    mainLayout->addWidget(addButton);
    mainLayout->addWidget(edtOrderCount);
    mainLayout->addWidget(decreaseButton);

    // mainLayout->addLayout(countLayout);

    QObject::connect(addButton, &QPushButton::clicked, [count, this, edtOrderCount, addButton, decreaseButton, id]() {
        if(count > edtOrderCount->text().toInt()){
            orderItem["count"] = edtOrderCount->text().toInt() + 1;
            orderItem["productId"] = id;
            edtOrderCount->setText(orderItem["count"].toString());
            decreaseButton->setEnabled(true);
            setOrder();
        }
        if(count == edtOrderCount->text().toInt()){
            addButton->setEnabled(false);
        }
    });

    QObject::connect(decreaseButton, &QPushButton::clicked, [count, edtOrderCount, this, addButton, decreaseButton, id]() {
        if(count > 0 & edtOrderCount->text().toInt() > 0){
            orderItem["count"] = edtOrderCount->text().toInt() - 1;
            orderItem["productId"] = id;
            edtOrderCount->setText(orderItem["count"].toString());
            addButton->setEnabled(true);
            setOrder();
        }
        if(count == 0 || edtOrderCount->text().toInt() == 0){
            decreaseButton->setEnabled(false);
        }
        if(edtOrderCount->text().toInt() == 0){
            delOrder(id);
        }
    });

    QObject::connect(edtOrderCount, &QLineEdit::textEdited, [edtOrderCount, count, this, addButton, decreaseButton, id](){

        bool blockSignals = edtOrderCount->blockSignals(true);
        edtOrderCount->blockSignals(blockSignals);

        QString text = edtOrderCount->text();
        text.replace(QChar(0x06F0), '0');
        text.replace(QChar(0x06F1), '1');
        text.replace(QChar(0x06F2), '2');
        text.replace(QChar(0x06F3), '3');
        text.replace(QChar(0x06F4), '4');
        text.replace(QChar(0x06F5), '5');
        text.replace(QChar(0x06F6), '6');
        text.replace(QChar(0x06F7), '7');
        text.replace(QChar(0x06F8), '8');
        text.replace(QChar(0x06F9), '9');
        edtOrderCount->setText(text);
        if(text.toInt() > count){
            QMessageBox::warning(this, "خطا", "موجودی این محصول کمتر از مقدار وارد شده است.", QMessageBox::Ok);
            edtOrderCount->setText(QString::number(count));
            addButton->setEnabled(false);
            decreaseButton->setEnabled(true);
        }
        if(text.toInt() == count){
            addButton->setEnabled(false);
            decreaseButton->setEnabled(true);
        }
        else if(text.toInt() == 0){
            addButton->setEnabled(true);
            decreaseButton->setEnabled(false);
        }
        else{
            addButton->setEnabled(true);
            decreaseButton->setEnabled(true);
        }
        orderItem["count"] = text.toInt();
        orderItem["productId"] = id;
        if(edtOrderCount->text().isEmpty()){
            edtOrderCount->setText("0");
        }
    });

    QObject::connect(edtOrderCount, &QLineEdit::returnPressed, [this, edtOrderCount, id](){
        if(edtOrderCount->text().toInt() != 0)
        {
        setOrder();
        }
        else
        {
            delOrder(id);
        }
    });

    return card;
}

void MainWindow::addProductTab(int filterId) {
    productModel->setTable("products");
    subCatModel->setTable("sub_categories");
    catModel->setTable("categories");

    if(filterId == -1){
        productModel->select(); //If no filter applied
    }
    else{
    subCatModel->setFilter(QString("parent = %1").arg(filterId));
    subCatModel->select();

    QStringList subCategoryIds;
    for (int i = 0; i < subCatModel->rowCount(); ++i) {
        int subCategoryId = subCatModel->data(subCatModel->index(i, 0)).toInt();
        subCategoryIds << QString::number(subCategoryId);
    }
    productModel->setFilter(QString("parent IN (%1)").arg(subCategoryIds.join(",")));
    productModel->select();
    }
    if(productCardList.count() > 0){
        foreach (QWidget *card, productCardList) {
            delete card;
        }
        productCardList.clear();
    }
    if(productModel->rowCount() > 0) {
        for(int i = 0; i < productModel->rowCount(); i++) {
            int id = productModel->data(productModel->index(i,0)).toInt();
            QString name = productModel->data(productModel->index(i,1)).toString();
            int price = productModel->data(productModel->index(i,2)).toInt();
            int count = productModel->data(productModel->index(i,4)).toInt();

            QWidget *productCard = createProductCard(id, name, price, count);
            productCard->setFont(ui->centralwidget->font());
            if(count <= 0){
                productCard->setEnabled(false);
            }
            productCardList.append(productCard);
        }
    }
    if(productCardList.count()>0){
        addCardToLayout();
    }
}

void MainWindow::addCardToLayout(){
    delete ui->scrollAreaWidgetContents->layout();
    QWidget *tabWidget = ui->scrollAreaWidgetContents;
    orderProductLayout = new QVBoxLayout(tabWidget);
    orderProductLayout->setAlignment(Qt::AlignTop);
    orderProductLayout->setSpacing(5);
    tabWidget->setLayout(orderProductLayout);

    foreach (QWidget *card, productCardList) {
        orderProductLayout->addWidget(card);
    }
}

void MainWindow::initialOrder(bool product, bool cus, bool recentOrder) {
    customer.setId(0);

    if(product){
    QList<QString> catList;
    QStringList catName;
    for (int i = 0; i < ui->cbStorageCat->count(); i++) {
        catName = ui->cbStorageCat->itemText(i).split("|");
        catList.append(catName[1].trimmed());
    }

    QVBoxLayout *orderFilter= ui->vlOrderFilter;
    OrientablePushButton *filterButton;

    foreach (OrientablePushButton *button, buttonList) {
        delete button;
    }
    buttonList.clear();

    filterButton = new OrientablePushButton("همه");
    filterButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
    filterButton->setOrientation(OrientablePushButton::VerticalTopToBottom);
    filterButton->setStyleSheet(R"(QPushButton{
            border-bottom: 2px solid #00DC72;})");

    buttonList.append(filterButton);
    orderFilter->insertWidget(ui->vlOrderFilter->count(), filterButton);

    foreach (QString cat, catList) {
        filterButton = new OrientablePushButton(cat);
        filterButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        filterButton->setOrientation(OrientablePushButton::VerticalTopToBottom);
        filterButton->setStyleSheet(R"(QPushButton{
            border: 1px solid transparent;})");
        buttonList.append(filterButton);
        orderFilter->insertWidget(ui->vlOrderFilter->count(), filterButton);
    }

    foreach (OrientablePushButton *button, buttonList) {
        button->setFont(ui->centralwidget->font());

        connect(button, &OrientablePushButton::clicked, this, [button, this]() {
            foreach (OrientablePushButton *btn, buttonList) {
                btn->setStyleSheet(R"(QPushButton{
                border: 1px solid transparent;})");
            }
            button->setStyleSheet(R"(QPushButton{
            border-bottom: 2px solid #00DC72;})");
            QStringList catName;
            for(int i = 0; i < ui->cbStorageCat->count(); i++){
                if(ui->cbStorageCat->itemText(i).contains(button->text())){
                    catName = ui->cbStorageCat->itemText(i).split("|");
                    filterId = catName[0].toInt();
                    addProductTab(catName[0].toInt());
                }
            }
            if(button->text() == "همه"){
                filterId = -1;
                addProductTab(-1);
            }
        });
    }

    addProductTab(-1);
    }

    if(cus){
    customersModel->setTable("customers");
    customersModel->select();
    QString name;
    QString phone;
    QStringList customersList;
    ui->cbOrderCustomer->clear();
    for(int i = 0; i < customersModel->rowCount(); i++)
    {
        name = customersModel->data(customersModel->index(i,1)).toString();
        phone = customersModel->data(customersModel->index(i,3)).toString();
        customersList.append(name + " | " + phone);
    }
    ui->cbOrderCustomer->blockSignals(true);
    ui->cbOrderCustomer->addItems(customersList);
    QCompleter *orderCompleter = new QCompleter(customersList, ui->cbOrderCustomer);
    orderCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->cbOrderCustomer->setCompleter(orderCompleter);
    ui->cbOrderCustomer->setCurrentIndex(-1);
    ui->cbOrderCustomer->blockSignals(false);
    }

    if(recentOrder){
    orderModel->setTable("orders");
    orderModel->select();

    ui->tblRecentOrder->clear();
    ui->tblRecentOrder->setRowCount(0);
    ui->tblRecentOrder->setColumnCount(5);
    ui->tblRecentOrder->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tblRecentOrder->setHorizontalHeaderLabels({"شناسه","مشتری","تاریخ","مبلغ کل","تخفیف"});
    ui->tblRecentOrder->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Fixed);
    ui->tblRecentOrder->setColumnWidth(0,60);

    if(orderModel->rowCount() > 0){

        for(int i = 0; i < orderModel->rowCount(); i++)
        {
            int customerId;
            customerId = orderModel->data(orderModel->index(i,1)).toInt();

            customersModel->setTable("customers");
            customersModel->setFilter(QString("id = %1").arg(customerId));
            customersModel->select();

            ui->tblRecentOrder->insertRow(i);
            ui->tblRecentOrder->setItem(i,0, new QTableWidgetItem(orderModel->data(orderModel->index(i,0)).toString()));
            ui->tblRecentOrder->setItem(i,1, new QTableWidgetItem(customersModel->data(customersModel->index(0,1)).toString()));
            ui->tblRecentOrder->setItem(i,2, new QTableWidgetItem(orderModel->data(orderModel->index(i,2)).toString()));
            ui->tblRecentOrder->setItem(i,3, new QTableWidgetItem(locale.toString(orderModel->data(orderModel->index(i,3)).toInt())));
            ui->tblRecentOrder->setItem(i,4, new QTableWidgetItem(locale.toString(orderModel->data(orderModel->index(i,4)).toInt())));

            ui->tblRecentOrder->item(i,0)->setTextAlignment(Qt::AlignCenter);
            ui->tblRecentOrder->item(i,1)->setTextAlignment(Qt::AlignCenter);
            ui->tblRecentOrder->item(i,2)->setTextAlignment(Qt::AlignCenter);
            ui->tblRecentOrder->item(i,3)->setTextAlignment(Qt::AlignCenter);
            ui->tblRecentOrder->item(i,4)->setTextAlignment(Qt::AlignCenter);

            QTableWidgetItem *delItem = new QTableWidgetItem();
            delItem->setIcon(QIcon(":/icon/trash.svg"));
            ui->tblRecentOrder->setVerticalHeaderItem(i, delItem);
        }
    }
    }
}

void MainWindow::setOrder()
{
    int row = ui->tblOrderList->rowCount();

    productModel->setTable("products");
    if(!orderItem.isEmpty()){
        productModel->setFilter(QString("id = %1").arg(orderItem["productId"].toInt()));
        productModel->select();
        ui->edtOrderDiscount->setEnabled(true);
        ui->cbOrderCustomer->setEnabled(true);
        ui->btnSubmitOrder->setEnabled(true);
    }
    else
    {
        ui->edtOrderDiscount->setEnabled(false);
        ui->cbOrderCustomer->setEnabled(false);
        ui->btnSubmitOrder->setEnabled(false);
        return;
    }
    for(int i = 0; i < ui->tblOrderList->rowCount(); i++){
        if(orderItem["productId"] == ui->tblOrderList->item(i, 0)->text().toInt()){
            row = i;
            break;
        }
    }

    int id = productModel->data(productModel->index(0,0)).toInt();
    QString name = productModel->data(productModel->index(0,1)).toString();
    int price = productModel->data(productModel->index(0,2)).toInt();
    if(ui->tblOrderList->rowCount() == 0 || row == ui->tblOrderList->rowCount()){
    ui->tblOrderList->insertRow(row);
    }
    ui->tblOrderList->blockSignals(true);
    ui->tblOrderList->setItem(row, 0, new QTableWidgetItem(QString::number(id)));
    ui->tblOrderList->setItem(row, 1, new QTableWidgetItem(name));
    ui->tblOrderList->setItem(row, 2, new QTableWidgetItem(locale.toString(price)));
    ui->tblOrderList->setItem(row, 3, new QTableWidgetItem(QString::number(orderItem["count"].toInt())));
    QTableWidgetItem *check = new QTableWidgetItem();
    check->setCheckState(Qt::Unchecked);
    ui->tblOrderList->setItem(row, 4, check);

    ui->tblOrderList->item(row, 0)->setTextAlignment(Qt::AlignCenter);
    ui->tblOrderList->item(row, 1)->setTextAlignment(Qt::AlignCenter);
    ui->tblOrderList->item(row, 2)->setTextAlignment(Qt::AlignCenter);
    ui->tblOrderList->blockSignals(false);
    ui->tblOrderList->item(row, 3)->setTextAlignment(Qt::AlignCenter);
    ui->tblOrderList->item(row, 4)->setTextAlignment(Qt::AlignCenter);
    QIcon icon(":/icon/trash.svg");
    QTableWidgetItem *headerItem = new QTableWidgetItem();
    headerItem->setIcon(icon);
    ui->tblOrderList->setVerticalHeaderItem(row, headerItem);
    if(ui->cbOrderCustomer->currentIndex() > -1)
    {
        if(ui->edtOrderDiscount->text().toInt() > 0){
            on_edtOrderDiscount_returnPressed();
        }
        if(orderCustomer){
            QCheckBox *check = orderCustomer->findChild<QCheckBox*>();
            if(check->checkState()){
            check->checkStateChanged(Qt::Checked);
            }
        }
    }
}

void MainWindow::delOrder(int id)
{
    for(int i = 0; i < ui->tblOrderList->rowCount(); i++){
        if(ui->tblOrderList->item(i, 0)->text().toInt() == id){
            ui->tblOrderList->removeRow(i);
            break;
        }
    }
    if(ui->tblOrderList->rowCount() > 0){
        orderTotal = 0;
        for(int i = 0; i < ui->tblOrderList->rowCount(); i++)
        {
            orderTotal = orderTotal + (locale.toInt(ui->tblOrderList->item(i,2)->text()) * ui->tblOrderList->item(i,3)->text().toInt());
        }
        ui->lblOrderTotal->setText(locale.toString(orderTotal));
        ui->lblCheckout->setText(locale.toString(orderTotal));
    }
    else
    {
        ui->cbOrderCustomer->setCurrentIndex(-1);
        on_cbOrderCustomer_currentIndexChanged();
        if(orderCustomer){
            delete orderCustomer;
            orderCustomer = new QWidget;
        }
        ui->edtSearchOrderFilter->setFocus();
        orderTotal = 0;
        ui->lblOrderTotal->setText("0");
        ui->lblCheckout->setText("0");
        ui->edtOrderDiscount->setText("0");
        on_edtOrderDiscount_returnPressed();
        ui->edtOrderDiscount->setEnabled(false);
        ui->cbOrderCustomer->setEnabled(false);
        ui->btnSubmitOrder->setEnabled(false);
        ui->lblOrderTotal->setText(locale.toString(orderTotal));
        ui->lblCheckout->setText(locale.toString(orderTotal));
    }
}

void MainWindow::delRecentOrder(int id)
{
    orderModel->setTable("orders");
    orderModel->setFilter(QString("id = %1").arg(id));
    orderModel->select();
    customerId = orderModel->data(orderModel->index(0,1)).toInt();
    orderTotal = orderModel->data(orderModel->index(0,3)).toInt() - orderModel->data(orderModel->index(0,4)).toInt();
    orderModel->removeRows(0,orderModel->rowCount());

    orderDetailModel->setTable("order_details");
    orderDetailModel->setFilter(QString("order_id = %1").arg(id));
    orderDetailModel->select();
    while(orderDetailModel->rowCount() > 0){
        int product = orderDetailModel->data(orderDetailModel->index(0,2)).toInt();
        productModel->setTable("products");
        productModel->setFilter(QString("id = %1").arg(product));
        productModel->select();
        productModel->setData(productModel->index(0,4), productModel->data(productModel->index(0,4)).toInt() +
                                                             orderDetailModel->data(orderDetailModel->index(0,3)).toInt());
        productModel->submitAll();

        orderDetailModel->removeRow(0);
        orderDetailModel->submitAll();
    }

    customersModel->setTable("customers");
    customersModel->setFilter(QString("id = %1").arg(customerId));
    customersModel->select();
    customersModel->setData(customersModel->index(0,4), customersModel->data(customersModel->index(0,4)).toInt() - orderTotal);

    if(!orderDetailModel->submitAll())
    {
        QMessageBox::warning(this,"Error", orderDetailModel->lastError().text(), QMessageBox::Ok);
        return;
    }

    if(!orderModel->submitAll())
    {
        QMessageBox::warning(this,"Error", orderModel->lastError().text(), QMessageBox::Ok);
        return;
    }

    if(!customersModel->submitAll())
    {
        QMessageBox::warning(this,"Error", customersModel->lastError().text(), QMessageBox::Ok);
        return;
    }

    initialOrder(false,false,true);

    QString qry;
    orderModel->setTable("orders");
    orderModel->select();
    if(orderModel->rowCount() == 0)
    {
        qry = "TRUNCATE TABLE orders;";
        query.prepare(qry);
        query.exec();
    }
    orderDetailModel->setTable("order_details");
    orderDetailModel->select();

    if(orderDetailModel->rowCount() == 0)
    {
        qry = "TRUNCATE TABLE order_details;";
        query.prepare(qry);
        query.exec();
    }
}

void MainWindow::initialEmployees()
{
    employeeModel->setTable("employees");
    employeeModel->select();

    ui->tblEmployees->clear();
    ui->tblEmployees->setRowCount(0);
    ui->tblEmployees->setColumnCount(3);
    ui->tblEmployees->setHorizontalHeaderLabels({"شناسه","نام","حقوق"});
    ui->tblEmployees->horizontalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tblEmployees->verticalHeader()->setDefaultAlignment(Qt::AlignCenter);
    ui->tblEmployees->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    if(employeeModel->rowCount() > 0)
    {
    for(int i = 0; i < employeeModel->rowCount(); i++)
    {
        ui->tblEmployees->insertRow(i);
        ui->tblEmployees->setItem(i, 0, new QTableWidgetItem(employeeModel->data(employeeModel->index(i,0)).toString()));
        ui->tblEmployees->setItem(i, 1, new QTableWidgetItem(employeeModel->data(employeeModel->index(i,1)).toString()));
        ui->tblEmployees->setItem(i, 2, new QTableWidgetItem(locale.toString(employeeModel->data(employeeModel->index(i,2)).toInt())));

        QTableWidgetItem *headerItem = new QTableWidgetItem;
        headerItem->setIcon(QIcon(":/icon/trash.svg"));
        ui->tblEmployees->setVerticalHeaderItem(i, headerItem);

        ui->tblEmployees->item(i, 0)->setTextAlignment(Qt::AlignCenter);
        ui->tblEmployees->item(i, 1)->setTextAlignment(Qt::AlignCenter);
        ui->tblEmployees->item(i, 2)->setTextAlignment(Qt::AlignCenter);
    }
    }
}

void MainWindow::delEmployee(int id)
{
    employeeModel->setTable("employees");
    employeeModel->setFilter(QString("id = %1").arg(id));
    employeeModel->select();

    employeeModel->removeRow(0);
    if(!employeeModel->submitAll()){
        QMessageBox::warning(this, "Error", employeeModel->lastError().text(), QMessageBox::Ok);
        return;
    }
    initialEmployees();

    employeeModel->setTable("employees");
    employeeModel->select();
    if(employeeModel->rowCount() ==0){
        QString qry = "TRUNCATE TABLE employees;";
        query.prepare(qry);
        if (!query.exec()) {
            QMessageBox::warning(this, "Error", query.lastError().text(), QMessageBox::Ok);
            return;
        }
    }
}
/*
============================================================================================
SECTION: Event Handlers
============================================================================================
*/

//Storage Operations

void MainWindow::on_rbCat_toggled(bool checked)
{
    if(checked){
        ui->edtCatDes->setEnabled(true);
        ui->edtCatTitle->setEnabled(true);
        ui->edtProductTitle->setEnabled(false);
        ui->edtPrice->setEnabled(false);
        ui->edtCount->setEnabled(false);
        ui->edtProductDes->setEnabled(false);
    }
}


void MainWindow::on_rbProduct_toggled(bool checked)
{
    if(checked){
        ui->edtCatDes->setEnabled(false);
        ui->edtCatTitle->setEnabled(false);
        ui->edtProductTitle->setEnabled(true);
        ui->edtPrice->setEnabled(true);
        ui->edtCount->setEnabled(true);
        ui->edtProductDes->setEnabled(true);
    }
}

void MainWindow::on_btnSaveStorage_pressed()
{
    if(catEdit){
        if(!edtCat->text().isEmpty()){
            QStringList idStr = ui->cbStorageCat->currentText().split("|");
            int id = idStr[0].trimmed().toInt();
            catModel->setTable("categories");
            catModel->setFilter(QString("id = %1").arg(id));
            catModel->select();
            if(catModel->rowCount() > 0){
                QModelIndex index = catModel->index(0, catModel->fieldIndex("name"));
                catModel->setData(index, edtCat->text());

                if(!catModel->submitAll()){
                    QMessageBox::warning(this,"Error",catModel->lastError().text(),QMessageBox::Ok);
                    return;
                }
            }
            lastCat = edtCat->text();
            initialCatagories();
            btnCancel->click();
            catEdit = false;
        }
    }
    else
    {

    if(ui->rbCat->isChecked()){
        if(ui->cbStorageCat->currentText() == ""){
            QMessageBox::warning(this,"Error","بخش نمی‌تواند خالی باشد.",QMessageBox::Ok);
        }
        else
        {

        QString catTitle = ui->edtCatTitle->text();
        QString catDes = ui->edtCatDes->text();

        if(subCatEdit){

            subCatModel->setTable("sub_categories");
            subCatModel->setFilter(QString("id = %1").arg(catId));
            subCatModel->select();
            if(subCatModel->rowCount() > 0){
                QModelIndex indexName = subCatModel->index(0, subCatModel->fieldIndex("name"));
                QModelIndex indexDes = subCatModel->index(0, subCatModel->fieldIndex("description"));
                subCatModel->setData(indexName, catTitle);
                subCatModel->setData(indexDes, catDes);

                if(!subCatModel->submitAll()){
                    QMessageBox::warning(this,"Error",subCatModel->lastError().text(),QMessageBox::Ok);
                    return;
                }
            }

            initialStorage(true, true);
            btnCancel->click();
            subCatEdit = false;
        }
        else
        {
        if(catTitle != ""){
            if(ui->cbStorageCat->findText(ui->cbStorageCat->currentText()) == -1){

                catModel->setTable("sub_categories");
                catModel->select();

                int row = catModel->rowCount();
                catModel->insertRows(row,1);
                catModel->setData(catModel->index(row, catModel->fieldIndex("name")),ui->cbStorageCat->currentText());

                if(!catModel->submitAll()){
                    QMessageBox::warning(this,"Error",catModel->lastError().text(),QMessageBox::Ok);
                    return;
                }

            lastCat.clear();
            initialCatagories();
            }

            QStringList catIdStr = ui->cbStorageCat->currentText().split("|");
            int index = catIdStr[0].trimmed().toInt();

                subCatModel->setTable("sub_categories");
                subCatModel->select();

                int row = subCatModel->rowCount();
                subCatModel->insertRows(row,1);
                subCatModel->setData(subCatModel->index(row, subCatModel->fieldIndex("name")), ui->edtCatTitle->text());
                subCatModel->setData(subCatModel->index(row, subCatModel->fieldIndex("description")), ui->edtCatDes->text());
                subCatModel->setData(subCatModel->index(row, subCatModel->fieldIndex("parent")), index);

                if(!subCatModel->submitAll()){
                    QMessageBox::warning(this,"Error",subCatModel->lastError().text(),QMessageBox::Ok);
                    return;
                }
        }
        else
        {
            QMessageBox::warning(this,"Error","نام دسته‌‌بندی نمی‌تواند خالی باشد",QMessageBox::Ok);

        }
        }
        ui->edtCatDes->clear();
        ui->edtCatTitle->clear();
        initialStorage(true, false);
        ui->edtCatTitle->setFocus();
        }
    }
    else if(ui->rbProduct->isChecked()){
        if(productEdit){

            productModel->setTable("products");
            productModel->setFilter(QString("id = %1").arg(productId));
            productModel->select();
            if(productModel->rowCount() > 0){

                productModel->setData(productModel->index(0, productModel->fieldIndex("name")), ui->edtProductTitle->text());
                productModel->setData(productModel->index(0, productModel->fieldIndex("price")), locale.toInt(ui->edtPrice->text()));
                productModel->setData(productModel->index(0, productModel->fieldIndex("count")), ui->edtCount->text().toInt());
                productModel->setData(productModel->index(0, productModel->fieldIndex("description")), ui->edtProductDes->text());

                if(!productModel->submitAll()){
                    QMessageBox::warning(this,"Error",productModel->lastError().text(),QMessageBox::Ok);
                    return;
                }
            }

            initialStorage(true, true);
            btnCancel->click();
            productEdit = false;
        }
        else
        {
        if(ui->cbStorageCat->currentText() == ""){
            QMessageBox::warning(this,"Error","آیتم بخش نمی‌تواند خالی باشد.",QMessageBox::Ok);
        }
        else
        {

        QString productTitle = ui->edtProductTitle->text();
        int price = ui->edtPrice->text().isEmpty() ? 0: locale.toInt(ui->edtPrice->text());
        int count = ui->edtCount->text().isEmpty() ? 0: ui->edtCount->text().toInt();
        QString productDes = ui->edtProductDes->text();
        int parent = ui->tblStorageCat->rowCount() > 0 ? ui->tblStorageCat->item(subCatRow, 0)->text().toInt() : 0;

        if(productTitle != ""){

            productModel->setTable("products");
            productModel->select();

            int row = productModel->rowCount();
            productModel->insertRows(row,1);
            productModel->setData(productModel->index(row, productModel->fieldIndex("name")), productTitle);
            productModel->setData(productModel->index(row, productModel->fieldIndex("price")), price);
            productModel->setData(productModel->index(row, productModel->fieldIndex("description")), productDes);
            productModel->setData(productModel->index(row, productModel->fieldIndex("count")), count);
            productModel->setData(productModel->index(row, productModel->fieldIndex("parent")),parent);

            if(!productModel->submitAll()){
                QMessageBox::warning(this,"Error",productModel->lastError().text(),QMessageBox::Ok);
                return;
            }

            initialStorage(false, true);
            ui->edtProductTitle->clear();
            ui->edtProductDes->clear();
            ui->edtPrice->clear();
            ui->edtCount->clear();
            ui->edtProductTitle->setFocus();
        }
        else
        {
            QMessageBox::warning(this,"Error","نام محصول نمی‌تواند خالی باشد",QMessageBox::Ok);

        }
        }
        }
    }
    }
    lastCat = ui->cbStorageCat->currentText();
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    switch (index) {
    case 0:
        initialCatagories();
        initialStorage(true, true);
        break;
    case 1:
        initialCustomers();
        break;
    case 2:
        initialEmployees();
        break;
    default:
        break;
    }
}


void MainWindow::on_cbStorageCat_currentTextChanged(const QString &arg1)
{
    lastCat = arg1;
    ui->rbCat->setChecked(true);
    initialStorage(true, true);
    if(!arg1.isEmpty() && ui->cbStorageCat->count() > 0){
    ui->btnDelCat->setEnabled(true);
    }
}


void MainWindow::on_btnDelCat_pressed()
{
    if(QMessageBox::question(this, "حذف بخش انتخاب شده", "در صورت ادامه بخش انتخاب شده و تمامی محصولات و دسته‌بندی‌های این بخش حذف خواهد شد.",
                              QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes){
    QList <int> subCat;

    for(int i = 0; i < ui->tblStorageCat->rowCount(); i++)
    {
        subCat.append(ui->tblStorageCat->item(i,0)->text().toInt());
    }

    foreach (int parent, subCat)
    {
        delProduct(-1,parent);
    }

    QStringList catIdStr = ui->cbStorageCat->currentText().split("|");
    int cat = catIdStr[0].trimmed().toInt();

    delSubCat(-1, cat);
    catModel->setTable("categories");
    catModel->setFilter(QString("id = %1").arg(cat));
    catModel->select();
    if(catModel->rowCount() > 0){
        catModel->removeRows(0, catModel->rowCount());
        if(!catModel->submitAll()){
            QMessageBox::warning(this, "Error", catModel->lastError().text(), QMessageBox::Ok);
            return;
        }
    }

    delSubCat(-1, cat);
    catModel->setTable("categories");
    catModel->select();

    if (catModel->rowCount() == 0) {
        QString qry = "TRUNCATE TABLE categories;";
        query.prepare(qry);
        if (!query.exec()) {
            QMessageBox::warning(this, "Error", query.lastError().text(), QMessageBox::Ok);
            return;
        }
    }

    if (ui->cbStorageCat->count() > 0)
    {
        lastCat = ui->cbStorageCat->itemText(ui->cbStorageCat->count()-1);
    }
    else
    {
        lastCat.clear();
    }
    ui->cbStorageCat->clear();
    ui->rbCat->setChecked(true);
    initialCatagories();
    initialStorage(true, true);
    }
}


void MainWindow::on_tblStorageCat_cellClicked(int row, int column)
{
    Q_UNUSED(column);
    ui->rbProduct->setChecked(true);
    subCatRow = row;
    initialStorage(false,true);
    ui->edtProductTitle->setFocus();
}


void MainWindow::on_tblStorageCat_cellDoubleClicked(int row, int column)
{
    Q_UNUSED(column);
    catId = ui->tblStorageCat->item(row,0)->text().toInt();
    ui->edtCatTitle->setText(ui->tblStorageCat->item(row,1)->text());
    ui->edtCatDes->setText(ui->tblStorageCat->item(row,2)->text());
    subCatEdit = true;
    ui->edtCatTitle->setFocus();
    ui->rbCat->setChecked(true);

    btnCancel = new QPushButton("لغو ویرایش", this);
    QPushButton *btnSaveStorage = ui->btnSaveStorage;
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(btnCancel);
    hLayout->addWidget(btnSaveStorage);
    ui->vlStorage->insertLayout(ui->vlStorage->count()-1, hLayout);
    ui->tblStorageCat->setEnabled(false);
    ui->tblStorageProduct->setEnabled(false);
    ui->cbStorageCat->setEnabled(false);
    ui->btnDelCat->setEnabled(false);

    connect(btnCancel, &QPushButton::clicked, this, [this, hLayout, btnSaveStorage]() {
        ui->vlStorage->removeItem(hLayout);
        ui->vlStorage->insertWidget(ui->vlStorage->count()-1, btnSaveStorage);
        ui->edtCatTitle->clear();
        ui->edtCatDes->clear();
        subCatEdit = false;
        ui->tblStorageCat->setEnabled(true);
        ui->tblStorageProduct->setEnabled(true);
        ui->cbStorageCat->setEnabled(true);
        ui->btnDelCat->setEnabled(true);

        delete btnCancel;
        delete hLayout;
    });
}


void MainWindow::on_edtPrice_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1);
    QString text = ui->edtPrice->text();
    text.replace(QChar(0x06F0), '0');
    text.replace(QChar(0x06F1), '1');
    text.replace(QChar(0x06F2), '2');
    text.replace(QChar(0x06F3), '3');
    text.replace(QChar(0x06F4), '4');
    text.replace(QChar(0x06F5), '5');
    text.replace(QChar(0x06F6), '6');
    text.replace(QChar(0x06F7), '7');
    text.replace(QChar(0x06F8), '8');
    text.replace(QChar(0x06F9), '9');
    int price = text.remove(",").toInt();
    ui->edtPrice->setText(locale.toString(price));
}


void MainWindow::on_edtCount_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1);
    QString text = ui->edtCount->text();
    text.replace(QChar(0x06F0), '0');
    text.replace(QChar(0x06F1), '1');
    text.replace(QChar(0x06F2), '2');
    text.replace(QChar(0x06F3), '3');
    text.replace(QChar(0x06F4), '4');
    text.replace(QChar(0x06F5), '5');
    text.replace(QChar(0x06F6), '6');
    text.replace(QChar(0x06F7), '7');
    text.replace(QChar(0x06F8), '8');
    text.replace(QChar(0x06F9), '9');
    ui->edtCount->setText(text);
}


void MainWindow::on_btnCatEdit_pressed()
{
    if(ui->vlStorage->count() <= 9 ){
    edtCat = new QLineEdit(this);
    QLabel *lblCat = new QLabel("عنوان بخش",this);
    QPushButton *btnSaveStorage = ui->btnSaveStorage;
    btnCancel = new QPushButton("لغو ویرایش", this);
    QHBoxLayout *hLayout = new QHBoxLayout;
    QHBoxLayout *hLayout2 = new QHBoxLayout;

    hLayout2->addWidget(lblCat);
    hLayout2->addWidget(edtCat);
    ui->vlStorage->insertLayout(3,hLayout2);
    hLayout->addWidget(btnCancel);
    hLayout->addWidget(btnSaveStorage);
    ui->vlStorage->insertLayout(ui->vlStorage->count()-1, hLayout);
    edtCat->setPlaceholderText("عنوان جدید را وارد کنید");
    edtCat->setFont(QFont(ui->cbStorageCat->font()));
    lblCat->setFont(QFont(ui->cbStorageCat->font()));
    ui->edtCatTitle->setEnabled(false);
    ui->edtCatDes->setEnabled(false);
    ui->tblStorageCat->setEnabled(false);
    ui->tblStorageProduct->setEnabled(false);
    ui->cbStorageCat->setEnabled(false);
    ui->btnDelCat->setEnabled(false);

    edtCat->setFocus();
    catEdit = true;

    connect(btnCancel, &QPushButton::clicked, this, [this, hLayout, btnSaveStorage, lblCat, hLayout2]() {
        ui->vlStorage->removeItem(hLayout);
        ui->vlStorage->removeItem(hLayout2);
        ui->vlStorage->insertWidget(ui->vlStorage->count()-1, btnSaveStorage);

        ui->edtCatTitle->setEnabled(true);
        ui->edtCatDes->setEnabled(true);
        ui->rbCat->setChecked(true);
        ui->tblStorageCat->setEnabled(true);
        ui->tblStorageProduct->setEnabled(true);
        ui->cbStorageCat->setEnabled(true);
        ui->btnDelCat->setEnabled(true);

        catEdit = false;

        delete edtCat;
        delete btnCancel;
        delete hLayout;
        delete hLayout2;
        delete lblCat;
    });
    }
    else{
        btnCancel->click();
    }
}


void MainWindow::on_tblStorageProduct_cellDoubleClicked(int row, int column)
{
    Q_UNUSED(column);
    productId = ui->tblStorageProduct->item(row,0)->text().toInt();
    ui->edtProductTitle->setText(ui->tblStorageProduct->item(row,1)->text());
    ui->edtPrice->setText(ui->tblStorageProduct->item(row, 2)->text());
    ui->edtCount->setText(ui->tblStorageProduct->item(row, 3)->text());
    ui->edtProductDes->setText(ui->tblStorageProduct->item(row,4)->text());
    productEdit = true;
    ui->edtProductTitle->setFocus();
    ui->rbProduct->setChecked(true);

    btnCancel = new QPushButton("لغو ویرایش", this);
    QPushButton *btnSaveStorage = ui->btnSaveStorage;
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(btnCancel);
    hLayout->addWidget(btnSaveStorage);
    ui->vlStorage->insertLayout(ui->vlStorage->count()-1, hLayout);
    ui->tblStorageCat->setEnabled(false);
    ui->tblStorageProduct->setEnabled(false);
    ui->cbStorageCat->setEnabled(false);
    ui->btnDelCat->setEnabled(false);

    connect(btnCancel, &QPushButton::clicked, this, [this, hLayout, btnSaveStorage]() {
        ui->vlStorage->removeItem(hLayout);
        ui->vlStorage->insertWidget(ui->vlStorage->count()-1, btnSaveStorage);
        ui->edtProductDes->clear();
        ui->edtProductTitle->clear();
        ui->edtCount->clear();
        ui->edtPrice->clear();
        productEdit = false;
        ui->rbCat->setChecked(true);
        ui->tblStorageCat->setEnabled(true);
        ui->tblStorageProduct->setEnabled(true);
        ui->cbStorageCat->setEnabled(true);
        ui->btnDelCat->setEnabled(true);

        delete btnCancel;
        delete hLayout;
    });
}

//Customer Operations

void MainWindow::on_edtCustomerBalance_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1);
    QString text = ui->edtCustomerBalance->text();
    text.replace(QChar(0x06F0), '0');
    text.replace(QChar(0x06F1), '1');
    text.replace(QChar(0x06F2), '2');
    text.replace(QChar(0x06F3), '3');
    text.replace(QChar(0x06F4), '4');
    text.replace(QChar(0x06F5), '5');
    text.replace(QChar(0x06F6), '6');
    text.replace(QChar(0x06F7), '7');
    text.replace(QChar(0x06F8), '8');
    text.replace(QChar(0x06F9), '9');
    int price = text.remove(",").toInt();
    ui->edtCustomerBalance->setText(locale.toString(price));
}


void MainWindow::on_edtCustomerPhone_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1);
    QString text = ui->edtCustomerPhone->text();
    text.replace(QChar(0x06F0), '0');
    text.replace(QChar(0x06F1), '1');
    text.replace(QChar(0x06F2), '2');
    text.replace(QChar(0x06F3), '3');
    text.replace(QChar(0x06F4), '4');
    text.replace(QChar(0x06F5), '5');
    text.replace(QChar(0x06F6), '6');
    text.replace(QChar(0x06F7), '7');
    text.replace(QChar(0x06F8), '8');
    text.replace(QChar(0x06F9), '9');
    ui->edtCustomerPhone->setText(text);
}


void MainWindow::on_btnSaveCustomer_pressed()
{
    QString customerName = ui->edtCustomerName->text();
    int customerBalance = ui->edtCustomerBalance->text().isEmpty() ? 0: locale.toInt(ui->edtCustomerBalance->text());
    QString customerPhone = ui->edtCustomerPhone->text();
    if(ui->chbDeptor->checkState()){
        customerBalance = customerBalance *-1;
    }
    QString qry;
    if(customerName == "")
    {
        QMessageBox::warning(this,"Error","نام مشتری نمی‌تواند خالی باشد.",QMessageBox::Ok);
    }
    else
    {
        if(customerEdit){
            customersModel->setTable("customers");
            customersModel->setFilter(QString("id = %1").arg(customerId));
            customersModel->select();
            if(customersModel->rowCount() > 0){
                customersModel->setData(customersModel->index(0, customersModel->fieldIndex("name")), ui->edtCustomerName->text());
                customersModel->setData(customersModel->index(0, customersModel->fieldIndex("balance")), customerBalance);
                customersModel->setData(customersModel->index(0, customersModel->fieldIndex("phone")), ui->edtCustomerPhone->text());
                customersModel->setData(customersModel->index(0, customersModel->fieldIndex("discount")), ui->edtCustomrDiscount->text().toInt());

                if(!customersModel->submitAll()){
                    QMessageBox::warning(this,"Error",customersModel->lastError().text(),QMessageBox::Ok);
                    return;
                }
                initialCustomers();
                btnCancel->click();
            }
        }
        else
        {
            customersModel->setTable("customers");
            customersModel->select();
            int row = customersModel->rowCount();
            customersModel->insertRows(row,1);
            customersModel->setData(customersModel->index(row, customersModel->fieldIndex("name")), customerName);
            customersModel->setData(customersModel->index(row, customersModel->fieldIndex("balance")), customerBalance);
            customersModel->setData(customersModel->index(row, customersModel->fieldIndex("phone")), customerPhone);
            customersModel->setData(customersModel->index(row, customersModel->fieldIndex("discount")), ui->edtCustomrDiscount->text().toInt());


            if(!customersModel->submitAll()){
                QMessageBox::warning(this,"Error",customersModel->lastError().text(),QMessageBox::Ok);
                return;
            }
            initialCustomers();
            ui->edtCustomerName->clear();
            ui->edtCustomerBalance->clear();
            ui->edtCustomerPhone->clear();
            ui->edtCustomerName->setFocus();
        }
    }
}



void MainWindow::on_tblCustomers_cellDoubleClicked(int row, int column)
{
    Q_UNUSED(column);

    ui->edtCustomerName->setText(ui->tblCustomers->item(row, 1)->text());
    ui->edtCustomerBalance->setText(ui->tblCustomers->item(row, 2)->text().remove("-"));
    ui->edtCustomerPhone->setText(ui->tblCustomers->item(row, 4)->text());
    ui->edtCustomrDiscount->setText(ui->tblCustomers->item(row,3)->text());
    customerId = ui->tblCustomers->item(row,0)->text().toInt();

    ui->edtCustomerName->setFocus();
    customerEdit = true;

    btnCancel = new QPushButton("لغو ویرایش", this);
    QPushButton *btnSaveCustomer = ui->btnSaveCustomer;
    QHBoxLayout *hLayout = new QHBoxLayout;
    hLayout->addWidget(btnCancel);
    hLayout->addWidget(btnSaveCustomer);
    ui->vlCustomer->insertLayout(ui->vlCustomer->count(), hLayout);
    ui->tblCustomers->setEnabled(false);
    if(locale.toInt(ui->tblCustomers->item(row, 2)->text()) <0){
        ui->chbDeptor->setCheckState(Qt::Checked);
    }
    else{
        ui->chbDeptor->setCheckState(Qt::Unchecked);
    }

    connect(btnCancel, &QPushButton::clicked, this, [this, hLayout, btnSaveCustomer]() {
        ui->vlCustomer->removeItem(hLayout);
        ui->vlCustomer->insertWidget(ui->vlCustomer->count(), btnSaveCustomer);

        ui->edtCustomerName->clear();
        ui->edtCustomerBalance->clear();
        ui->edtCustomerPhone->clear();
        customerEdit = false;
        ui->chbDeptor->setCheckState(Qt::Unchecked);
        ui->tblCustomers->setEnabled(true);
        ui->edtCustomerName->setFocus();

        delete btnCancel;
        delete hLayout;
    });
}

void MainWindow::on_edtSearchOrderFilter_textEdited(const QString &arg1)
{
    productModel->setTable("products");
    QString filter = QString(
                         "name LIKE '%%1%' OR "
                         "id LIKE '%%1%'"
                         ).arg(arg1);
    productModel->setFilter(filter);
    productModel->select();

    if(productCardList.count() > 0){
        foreach (QWidget *card, productCardList) {
            delete card;
        }
        productCardList.clear();
    }
    if(productModel->rowCount() > 0) {
        for(int i = 0; i < productModel->rowCount(); i++) {
            int id = productModel->data(productModel->index(i,0)).toInt();
            QString name = productModel->data(productModel->index(i,1)).toString();
            int price = productModel->data(productModel->index(i,2)).toInt();            int count = productModel->data(productModel->index(i,4)).toInt();

            QWidget *productCard = createProductCard(id, name, price, count);
            productCard->setFont(ui->centralwidget->font());
            productCardList.append(productCard);
        }
    }
    if(productCardList.count()>0){
        addCardToLayout();
    }
}


void MainWindow::on_cbOrderCustomer_currentIndexChanged()
{
    if(ui->cbOrderCustomer->count()>0 && ui->cbOrderCustomer->currentIndex() > -1){
    if(orderCustomer){
        delete orderCustomer; //Delete previus widget
        orderCustomer = new QWidget;
    }
    customersModel->setTable("customers");
    customersModel->setFilter(QString("name = '%1' AND phone = '%2'").arg(
        ui->cbOrderCustomer->currentText().split("|")[0].trimmed()).arg(ui->cbOrderCustomer->currentText().split("|")[1].trimmed()));
    customersModel->select();

    int id = customersModel->data(customersModel->index(0,0)).toInt();
    QString name = customersModel->data(customersModel->index(0,1)).toString();
    QString phone = customersModel->data(customersModel->index(0,3)).toString();
    int discount = customersModel->data(customersModel->index(0,5)).toInt();
    int balance = customersModel->data(customersModel->index(0,2)).toInt();

    customer.setId(id);
    customer.setName(name);
    customer.setBalance(balance);
    customer.setPhone(phone);
    customer.setDiscount(discount);

    QVBoxLayout *layout = ui->vlOrderList;
    QVBoxLayout *vLayout = new QVBoxLayout(orderCustomer);
    QHBoxLayout *hLayout = new QHBoxLayout;
    QCheckBox *check = new QCheckBox("پرداخت از موجودی");
    QCheckBox *checkDebt = new QCheckBox("ثبت بعنوان بدهی");
    QLabel *label = new QLabel("موجودی");
    QLabel *labelBalance = new QLabel(locale.toString(balance));
    label->setFont(ui->centralwidget->font());
    check->setFont(ui->centralwidget->font());
    hLayout->addWidget(label);
    hLayout->addWidget(labelBalance);
    vLayout->insertLayout(vLayout->count(),hLayout);
    if(balance > 0)
    {
        vLayout->insertWidget(vLayout->count(),check);
    }
    else{
        vLayout->insertWidget(vLayout->count(),checkDebt);
        int checkout = locale.toInt(ui->lblOrderTotal->text());
        checkout = checkout - (checkout * (ui->edtOrderDiscount->text().toFloat()/100));
        ui->lblCheckout->setText(locale.toString(checkout));
    }

    ui->edtOrderDiscount->setText(QString::number(discount));
    ui->edtOrderDiscount->setEnabled(true);
    ui->cbOrderCustomer->setEnabled(true);
    ui->btnSubmitOrder->setEnabled(true);
    ui->edtOrderDiscount->returnPressed();

    QObject::connect(check, &QCheckBox::checkStateChanged, [check, this, balance](){
        if(check->checkState() == Qt::Checked)
            {
            int checkout = locale.toInt(ui->lblOrderTotal->text());
            checkout = checkout - (checkout * (ui->edtOrderDiscount->text().toFloat()/100));
            checkout = checkout - balance;
            if(checkout < 0){
                ui->lblCheckout->setText("0");
            }
            else
            {
                ui->lblCheckout->setText(locale.toString(checkout));
            }
        }
        else{
            int checkout = locale.toInt(ui->lblOrderTotal->text());
            checkout = checkout - (checkout * (ui->edtOrderDiscount->text().toFloat()/100));
            ui->lblCheckout->setText(locale.toString(checkout));
        }
    });

    QObject::connect(checkDebt, &QCheckBox::checkStateChanged, [checkDebt, this](){
        if(checkDebt->checkState() == Qt::Checked)
        {
            ui->lblCheckout->setText("0");
        }
        else{
            int checkout = locale.toInt(ui->lblOrderTotal->text());
            checkout = checkout - (checkout * (ui->edtOrderDiscount->text().toFloat()/100));
            ui->lblCheckout->setText(locale.toString(checkout));
        }
    });

    check->checkStateChanged(Qt::Unchecked);
    checkDebt->checkStateChanged(Qt::Unchecked);

    layout->insertWidget(layout->count()-2, orderCustomer);

    }

}

void MainWindow::on_tblOrderList_itemChanged(QTableWidgetItem *item)
{
    if(ui->tblOrderList->rowCount() > 0){
    orderTotal = 0;
    for(int i = 0; i < ui->tblOrderList->rowCount(); i++)
    {
        orderTotal = orderTotal + (locale.toInt(ui->tblOrderList->item(i,2)->text()) * ui->tblOrderList->item(i,3)->text().toInt());
    }
    int checkout = orderTotal - (orderTotal * (ui->edtOrderDiscount->text().toFloat()/100));
    ui->lblOrderTotal->setText(locale.toString(orderTotal));
    ui->lblCheckout->setText(locale.toString(checkout));
    }
}

void MainWindow::on_edtOrderDiscount_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1);
    QString text = ui->edtOrderDiscount->text();
    text.replace(QChar(0x06F0), '0');
    text.replace(QChar(0x06F1), '1');
    text.replace(QChar(0x06F2), '2');
    text.replace(QChar(0x06F3), '3');
    text.replace(QChar(0x06F4), '4');
    text.replace(QChar(0x06F5), '5');
    text.replace(QChar(0x06F6), '6');
    text.replace(QChar(0x06F7), '7');
    text.replace(QChar(0x06F8), '8');
    text.replace(QChar(0x06F9), '9');
    ui->edtOrderDiscount->setText(text);
    if(ui->edtOrderDiscount->text().isEmpty()){
        ui->edtOrderDiscount->setText("0");
        on_edtOrderDiscount_returnPressed();
    }
    if(ui->edtOrderDiscount->text().toInt() > 100){
        ui->edtOrderDiscount->setText("100");
    }
}


void MainWindow::on_edtOrderDiscount_returnPressed()
{
    int checkout = locale.toInt(ui->lblOrderTotal->text());
    if(!ui->edtOrderDiscount->text().isEmpty()){
        checkout = checkout - (checkout * (ui->edtOrderDiscount->text().toFloat()/100));
        if(orderCustomer){
            if(QCheckBox *check = orderCustomer->findChild<QCheckBox*>())
            {
                if(check->checkState() == Qt::Checked){
                    checkout = checkout - (customer.getBalance() > 0 ? customer.getBalance(): checkout);
                    if(checkout < 0){
                        checkout = 0;
                    }
                }
            }
        }
        ui->lblCheckout->setText(locale.toString(checkout));
        ui->edtOrderDiscount->setStyleSheet("QLineEdit{border-bottom: 2px solid #00DC72}");
    }
    if(ui->edtOrderDiscount->text() == "0"){
        ui->edtOrderDiscount->setStyleSheet(ui->tabWidget->styleSheet());
    }
}


void MainWindow::on_btnClearOrderList_pressed()
{
    while(ui->tblOrderList->rowCount() > 0){
    delOrder(ui->tblOrderList->item(0, 0)->text().toInt());
    }
}

void MainWindow::on_edtCustomrDiscount_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1);
    QString text = ui->edtCustomrDiscount->text();
    text.replace(QChar(0x06F0), '0');
    text.replace(QChar(0x06F1), '1');
    text.replace(QChar(0x06F2), '2');
    text.replace(QChar(0x06F3), '3');
    text.replace(QChar(0x06F4), '4');
    text.replace(QChar(0x06F5), '5');
    text.replace(QChar(0x06F6), '6');
    text.replace(QChar(0x06F7), '7');
    text.replace(QChar(0x06F8), '8');
    text.replace(QChar(0x06F9), '9');
    ui->edtOrderDiscount->setText(text);
    if(ui->edtCustomrDiscount->text().isEmpty()){
        ui->edtCustomrDiscount->setText("0");
    }
    if(ui->edtOrderDiscount->text().toInt() > 100){
        ui->edtCustomrDiscount->setText("100");
    }
}


void MainWindow::on_cbOrderCustomer_editTextChanged(const QString &arg1)
{
    if(arg1.isEmpty())
    {
        ui->cbOrderCustomer->setCurrentIndex(-1);
        customer.setId(0);
        ui->edtOrderDiscount->setText("0");
        on_edtOrderDiscount_returnPressed();

        if(orderCustomer){
            QCheckBox *check = orderCustomer->findChild<QCheckBox*>();
            if(check){
            if(check->checkState()){
                check->checkStateChanged(Qt::Unchecked);
            }
            }
            delete orderCustomer;
            orderCustomer = new QWidget;
        }
    }
}


void MainWindow::on_btnSubmitOrder_clicked()
{
    orderModel->setTable("orders");
    orderModel->select();
    orderTotal = locale.toInt(ui->lblOrderTotal->text());
    int row = orderModel->rowCount();
    int checkout = orderTotal - (orderTotal * (ui->edtOrderDiscount->text().toFloat()/100));

    orderModel->insertRows(row,1);
    orderModel->setData(orderModel->index(row,1),customer.getId());
    orderModel->setData(orderModel->index(row,2), QDateTime::currentDateTime());
    orderModel->setData(orderModel->index(row,3),locale.toInt(ui->lblOrderTotal->text()));
    orderModel->setData(orderModel->index(row,4), orderTotal * (ui->edtOrderDiscount->text().toFloat()/100));

    if(!orderModel->submitAll())
    {
        QMessageBox::warning(this,"Error",orderModel->lastError().text(),QMessageBox::Ok);
        return;
    }
    customerId = customer.getId();
    if(customerId == 0){
        customersModel->setTable("customers");
        customersModel->select();
        int row = customersModel->rowCount();
        customersModel->insertRows(row , 1);
        customersModel->setData(customersModel->index(row,1), ui->cbOrderCustomer->currentText());
        customersModel->setData(customersModel->index(row,4), checkout);
    }
    else
    {
    customersModel->setTable("customers");
    customersModel->setFilter(QString("id = %1").arg(customer.getId()));
    customersModel->select();
    customersModel->setData(customersModel->index(0,4), customersModel->data(customersModel->index(0,4)).toInt() + checkout);
    if(QCheckBox *check = orderCustomer->findChild<QCheckBox*>())
    {
        if(check->checkState() == Qt::Checked){
            int balance = customer.getBalance() - checkout;
            customersModel->setData(customersModel->index(0,2), balance);
        }
    }
    }
    orderModel->setTable("orders");
    orderModel->select();

    int orderId = orderModel->data(orderModel->index(orderModel->rowCount()-1, 0)).toInt();
    orderDetailModel->setTable("order_details");
    orderDetailModel->select();
    int detailRow = orderDetailModel->rowCount();

    productModel->setTable("products");

    for(int i = 0; i < ui->tblOrderList->rowCount(); i++)
    {
        int id = ui->tblOrderList->item(i,0)->text().toInt();
        int count = ui->tblOrderList->item(i,3)->text().toInt();
        int price = locale.toInt(ui->tblOrderList->item(i, 2)->text()) * count;
        int takeAway = ui->tblOrderList->item(i, 4)->checkState()? 1: 0;
        productModel->setFilter(QString("id = %1").arg(id));
        productModel->select();
        int availableCount = productModel->data(productModel->index(0,4)).toInt() - count;
        availableCount = availableCount < 0 ? 0: availableCount;
        productModel->setData(productModel->index(0,4),availableCount);

        if(!productModel->submitAll())
        {
            QMessageBox::warning(this,"Error",productModel->lastError().text(),QMessageBox::Ok);
            return;
        }

        orderDetailModel->insertRows(detailRow,1);
        orderDetailModel->setData(orderDetailModel->index(detailRow,1),orderId);
        orderDetailModel->setData(orderDetailModel->index(detailRow,2),id);
        orderDetailModel->setData(orderDetailModel->index(detailRow,3), count);
        orderDetailModel->setData(orderDetailModel->index(detailRow,4),price);
        orderDetailModel->setData(orderDetailModel->index(detailRow,5),takeAway);
    }

    if(!orderDetailModel->submitAll())
    {
        QMessageBox::warning(this,"Error",orderDetailModel->lastError().text(),QMessageBox::Ok);
        return;
    }

    if(!customersModel->submitAll())
    {
        QMessageBox::warning(this,"Error",customersModel->lastError().text(),QMessageBox::Ok);
        return;
    }

    initialOrder(false,true,true);

    while(ui->tblOrderList->rowCount()>0)
    {
        delOrder(ui->tblOrderList->item(0,0)->text().toInt());
    }
}

void MainWindow::on_tblRecentOrder_cellDoubleClicked(int row, int column)
{
    Q_UNUSED(column);
    QDialog *modal = new QDialog(this);
    modal->setStyleSheet(ui->tabWidget->styleSheet());
    modal->setModal(true);
    modal->setWindowTitle("جزئیات سفارش");
    modal->setLayoutDirection(Qt::RightToLeft);

    int orderId = ui->tblRecentOrder->item(row,0)->text().toInt();
    orderDetailModel->setTable("order_details");
    orderDetailModel->setFilter(QString("order_id = %1").arg(orderId));
    orderDetailModel->select();
    QTableWidget *table = new QTableWidget;
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels({"شناسه سفارش","نام محصول","تعداد","قیمت کل","بیرون‌بر"});
    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    table->horizontalHeader()->setSectionResizeMode(4, QHeaderView::ResizeToContents);

    for(int i = 0; i < orderDetailModel->rowCount(); i++)
    {
        table->insertRow(i);
        table->setItem(i, 0, new QTableWidgetItem(orderDetailModel->data(orderDetailModel->index(i, 1)).toString()));
        productModel->setTable("products");
        productModel->setFilter(QString("id = %1").arg(orderDetailModel->data(orderDetailModel->index(i, 2)).toInt()));
        productModel->select();
        QString product = productModel->data(productModel->index(0,1)).toString();
        table->setItem(i, 1, new QTableWidgetItem(product));
        table->setItem(i, 2, new QTableWidgetItem(orderDetailModel->data(orderDetailModel->index(i, 3)).toString()));
        table->setItem(i, 3, new QTableWidgetItem(orderDetailModel->data(orderDetailModel->index(i, 4)).toString()));
        QTableWidgetItem *check = new QTableWidgetItem();
        check->setCheckState(orderDetailModel->data(orderDetailModel->index(i, 5)).toString() == "0" ? Qt::Unchecked: Qt::Checked);
        table->setItem(i, 4, check);
    }
    table->resizeColumnsToContents();
    table->setFont(ui->centralwidget->font());
    QHBoxLayout *layout = new QHBoxLayout(modal);
    layout->addWidget(table);
    modal->setMinimumWidth(600);
    modal->setMinimumHeight(300);
    modal->exec();

    table->deleteLater();
    layout->deleteLater();
    modal->deleteLater();
}



void MainWindow::on_edtEmployeeSalary_textEdited(const QString &arg1)
{
    Q_UNUSED(arg1);
    QString text = ui->edtEmployeeSalary->text();
    text.replace(QChar(0x06F0), '0');
    text.replace(QChar(0x06F1), '1');
    text.replace(QChar(0x06F2), '2');
    text.replace(QChar(0x06F3), '3');
    text.replace(QChar(0x06F4), '4');
    text.replace(QChar(0x06F5), '5');
    text.replace(QChar(0x06F6), '6');
    text.replace(QChar(0x06F7), '7');
    text.replace(QChar(0x06F8), '8');
    text.replace(QChar(0x06F9), '9');
    int price = text.remove(",").toInt();
    ui->edtEmployeeSalary->setText(locale.toString(price));
}


void MainWindow::on_btnSaveEmployee_pressed()
{
    if(ui->edtEmployeeName->text() == ""){

        QMessageBox::warning(this, "Error", "نام نمی‌تواند خالی باشد.", QMessageBox::Ok);
        return;
    }
    if(employeeEdit == true){
        qDebug() << "Edit";
        employeeModel->setTable("employees");
        employeeModel->setFilter(QString("id = %1").arg(employeeId));
        employeeModel->select();
        employeeModel->setData(employeeModel->index(0, 1), ui->edtEmployeeName->text());
        employeeModel->setData(employeeModel->index(0, 2), locale.toInt(ui->edtEmployeeSalary->text()));
        if(!employeeModel->submitAll())
        {
            QMessageBox::warning(this, "Error", employeeModel->lastError().text(), QMessageBox::Ok);
            return;
        }
        ui->edtEmployeeName->clear();
        ui->edtEmployeeSalary->clear();
        employeeEdit = false;
        ui->edtEmployeeName->setFocus();
        initialEmployees();
    }
    else{
        employeeModel->setTable("employees");
        employeeModel->select();
        int row = employeeModel->rowCount();
        employeeModel->insertRows(row,1);
        employeeModel->setData(employeeModel->index(row, 1), ui->edtEmployeeName->text());
        employeeModel->setData(employeeModel->index(row, 2), locale.toInt(ui->edtEmployeeSalary->text()));
        if(!employeeModel->submitAll())
        {
            QMessageBox::warning(this, "Error", employeeModel->lastError().text(), QMessageBox::Ok);
            return;
        }
        ui->edtEmployeeName->clear();
        ui->edtEmployeeSalary->clear();
        ui->edtEmployeeName->setFocus();
        initialEmployees();
    }
}

void MainWindow::on_tabWidget_2_currentChanged(int index)
{
    if(index == 1){
        initialOrder(true, true, true);
    }
}

