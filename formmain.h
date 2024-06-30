#ifndef FORMMAIN_H
#define FORMMAIN_H

#include <QWidget>
#include "windowsizeadapter.h"
#include "QKeyEvent"
namespace Ui {
class FormMain;
}

class FormMain : public QWidget
{
    Q_OBJECT

public:
    explicit FormMain(QWidget *parent = nullptr);
    ~FormMain();
    WindowSizeAdapter adapter;

private slots:

    void on_btnsqr_clicked();

    void on_btnevo_clicked();

    void on_btnclear_clicked();

    void on_btnplus_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

    void on_btnsub_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btnmulti_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btndivide_clicked();

    void on_btndot_clicked();

    void on_btn0_clicked();

    void on_btnbksp_clicked();

    void on_btnequal_clicked();

private:
    Ui::FormMain *ui;
    QString input;
    QString expression;
    void keyPressEvent(QKeyEvent *event);
    double calc(QString firstExpression,QString lastExpression);
    bool calced=0;
    bool sqrled=0;
    bool evoed=0;
};

#endif // FORMMAIN_H
