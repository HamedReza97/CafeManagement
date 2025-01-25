#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qpushbutton.h>
#include <QSqlTableModel>
#include <QGroupBox>
#include <QtWidgets/qtablewidget.h>
#include "customer.h"
#include "orientablepushbutton.h"

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

    void initialStorage(bool sub_cat, bool product);

    void initialCatagories();

    void delProduct(int id, int parent);

    void delSubCat(int id, int parent);

    void initialCustomers();

    void delCustomer(int id);

    void addProductTab(int filterId);

    void initialOrder(bool product, bool cus, bool recentOrder);

    void addCardToLayout();

    QGroupBox *createProductCard(int id, QString name, int price, int count);

    void setOrder();

    void delOrder(int id);

    void delRecentOrder(int id);

    void initialEmployees();

    void delEmployee(int id);

private slots:
    void on_rbCat_toggled(bool checked);

    void on_rbProduct_toggled(bool checked);

    void on_btnSaveStorage_pressed();

    void on_tabWidget_currentChanged(int index);

    void on_cbStorageCat_currentTextChanged(const QString &arg1);

    void on_btnDelCat_pressed();

    void on_tblStorageCat_cellClicked(int row, int column);

    void on_tblStorageCat_cellDoubleClicked(int row, int column);

    void on_edtPrice_textEdited(const QString &arg1);

    void on_edtCount_textEdited(const QString &arg1);

    void on_btnCatEdit_pressed();

    void on_tblStorageProduct_cellDoubleClicked(int row, int column);

    void on_edtCustomerBalance_textEdited(const QString &arg1);

    void on_edtCustomerPhone_textEdited(const QString &arg1);

    void on_btnSaveCustomer_pressed();

    void on_tblCustomers_cellDoubleClicked(int row, int column);

    void on_edtSearchOrderFilter_textEdited(const QString &arg1);

    void on_cbOrderCustomer_currentIndexChanged();

    void on_tblOrderList_itemChanged(QTableWidgetItem *item);

    void on_edtOrderDiscount_textEdited(const QString &arg1);

    void on_edtOrderDiscount_returnPressed();

    void on_btnClearOrderList_pressed();

    void on_btnSubmitOrder_clicked();

    void on_edtCustomrDiscount_textEdited(const QString &arg1);

    void on_cbOrderCustomer_editTextChanged(const QString &arg1);

    void on_tblRecentOrder_cellDoubleClicked(int row, int column);

    void on_edtEmployeeSalary_textEdited(const QString &arg1);

    void on_btnSaveEmployee_pressed();

    void on_tabWidget_2_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    QSqlTableModel *productModel, *customersModel, *catModel, *subCatModel, *orderModel, *orderDetailModel, *employeeModel;
    QSqlDatabase database;
    QSqlQuery query;
    QString lastCat;
    int catId, subCatRow = 0, productId, customerId, filterId = -1, orderTotal, employeeId;
    bool catEdit = false, subCatEdit = false , productEdit = false, customerEdit = false, employeeEdit = false;
    QPushButton *btnCancel;
    QLineEdit *edtCat;
    QList<QWidget*> productCardList;
    QVBoxLayout *orderProductLayout;
    QWidget *orderCustomer = new QWidget;
    int orderColumns;
    QList<OrientablePushButton*> buttonList;
    QHash<QString, QVariant> orderItem;
    QLocale locale = QLocale::system();

    Customer customer;

};


#endif // MAINWINDOW_H

