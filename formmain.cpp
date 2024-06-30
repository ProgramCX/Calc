#include "formmain.h"
#include "ui_formmain.h"
#include "qdebug.h"
#include "cmath"
#include "qmath.h"
FormMain::FormMain(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::FormMain)
{
    ui->setupUi(this);
    adapter.setWindow(this);
    adapter.adaptAll();
    input="";
    expression="";
}

FormMain::~FormMain()
{
    delete ui;
}

void FormMain::on_btnsqr_clicked()
{
    evoed=0;
    sqrled=0;
    if(expression=="" ||calced){
        calced=0;
        if(input==""){
            input="0";
        }
        double outcome=input.toDouble()*input.toDouble();
        ui->labexp->setText(input+"²");
        input=QString::number(outcome);
        expression=input;
        ui->labout->setText(input);

    }else{
        // if(input==""&& ui->labout->text()!="0"){
        //     expression=expression.left(expression.size()-1)+"+";
        //     ui->labexp->setText(expression);
        //     return;
        // }
        double preoutcome=input.toDouble()*input.toDouble();
        double outcome;
        if(evoed){
            outcome=preoutcome;
            input=QString::number(preoutcome);
            expression=input;
            evoed=0;
        }else{
            input=QString::number(preoutcome);
            calc(expression,input);
        }
        if((QString::number(outcome)=="inf" ||  QString::number(outcome)=="nan")){
            ui->labexp->clear();
            input="";
            ui->labout->setText("Invalid!");
            expression="";
            return;
        }
        expression=QString::number(outcome);
        if(QString::number(outcome)=="inf"){
            ui->labexp->clear();
            input="";
            ui->labout->setText("Invalid!");
            expression="";
            return;
        }
        ui->labexp->setText(expression);
        input="";
        ui->labout->setText("0");

    }
    sqrled=1;
}


void FormMain::on_btnevo_clicked()
{
    if(expression=="" ||calced){
        calced=0;
        if(input==""){
            input="0";
        }
        double outcome=qSqrt(input.toDouble());
        ui->labexp->setText("√"+input);
        input=QString::number(outcome);
        expression=input;
        ui->labout->setText(input);

    }else{
        // if(input==""&& ui->labout->text()!="0"){
        //     expression=expression.left(expression.size()-1)+"";
        //     ui->labexp->setText(expression);
        //     return;
        // }

        double preoutcome=qSqrt(input.toDouble());
        double outcome;
        if(sqrled){
            outcome=preoutcome;
            input=QString::number(preoutcome);
            expression=input;
            sqrled=0;
        }else{
            input=QString::number(preoutcome);
            calc(expression,input);
        }

        if(QString::number(outcome)=="inf"){
            ui->labexp->clear();
            input="";
            ui->labout->setText("Invalid!");
            expression="";
            return;
        }
        expression=QString::number(outcome);
        if(QString::number(outcome)=="inf" ||  QString::number(outcome)=="nan"){
            ui->labexp->clear();
            input="";
            ui->labout->setText("Invalid!");
            expression="";
            return;
        }
        ui->labexp->setText(expression);
        input="";
        ui->labout->setText("0");
    }
    evoed=0;
}


void FormMain::on_btnclear_clicked()
{
    evoed=0;
    sqrled=0;
    ui->labexp->clear();
    input="";
    ui->labout->setText("0");

    expression="";
}


void FormMain::on_btnplus_clicked()
{
    evoed=0;
    sqrled=0;
    if(calced){
        expression=input;
        calced=0;
    }
    if(expression=="" ||(expression.right(1)=="0"
                             ||expression.right(1)=="1"
                             ||expression.right(1)=="2"
                             ||expression.right(1)=="3"
                             ||expression.right(1)=="4"
                             ||expression.right(1)=="5"
                             ||expression.right(1)=="6"
                             ||expression.right(1)=="7"
                             ||expression.right(1)=="8"
                             ||expression.right(1)=="9" )){

        if(input=="" &&expression==""){
            expression="0+";
        }else if(input=="" &&expression!=""){
            input=expression;
            expression=input+"+";
        }else{
            expression=input+"+";
        }
        ui->labexp->setText(expression);
        input="";
        ui->labout->setText("0");
    }else{
        if(input==""&& ui->labout->text()!="0"){
            expression=expression.left(expression.size()-1)+"+";
            ui->labexp->setText(expression);
            return;
        }
        double outcome=calc(expression,input);
        if(QString::number(outcome)=="inf" ||  QString::number(outcome)=="nan"){
            ui->labexp->clear();
            input="";
            ui->labout->setText("Invalid!");
            expression="";
            return;
        }
        expression=QString::number(outcome)+"+";
        if(QString::number(outcome)=="inf"){
            ui->labexp->clear();
            input="";
            ui->labout->setText("Invalid!");
            expression="";
            return;
        }
        ui->labexp->setText(expression);
        input="";
        ui->labout->setText("0");
    }

}


void FormMain::on_btn7_clicked()
{
    evoed=0;
    sqrled=0;
    input.append("7");
    ui->labout->setText(input);
}


void FormMain::on_btn8_clicked()
{
    evoed=0;
    sqrled=0;
    input.append("8");
    ui->labout->setText(input);
}


void FormMain::on_btn9_clicked()
{
    evoed=0;
    sqrled=0;
    input.append("9");
    ui->labout->setText(input);
}


void FormMain::on_btnsub_clicked()
{
    evoed=0;
    sqrled=0;
    if(calced){
        expression=input;
        calced=0;
    }
    if(expression=="" ||(expression.right(1)=="0"
                             ||expression.right(1)=="1"
                             ||expression.right(1)=="2"
                             ||expression.right(1)=="3"
                             ||expression.right(1)=="4"
                             ||expression.right(1)=="5"
                             ||expression.right(1)=="6"
                             ||expression.right(1)=="7"
                             ||expression.right(1)=="8"
                             ||expression.right(1)=="9" )){

        if(input=="" &&expression==""){
            expression="0-";
        }else if(input=="" &&expression!=""){
            input=expression;
            expression=input+"-";
        }else{
            expression=input+"-";
        }
        ui->labexp->setText(expression);
        input="";
        ui->labout->setText("0");
    }else{
        if(input==""&& ui->labout->text()!="0"){
            expression=expression.left(expression.size()-1)+"-";
            ui->labexp->setText(expression);
            return;
        }
        double outcome=calc(expression,input);
        if(QString::number(outcome)=="inf" ||  QString::number(outcome)=="nan"){
            ui->labexp->clear();
            input="";
            ui->labout->setText("Invalid!");
            expression="";
            return;
        }
        expression=QString::number(outcome)+"-";
        ui->labexp->setText(expression);
        input="";
        ui->labout->setText("0");
    }
}


void FormMain::on_btn4_clicked()
{
    evoed=0;
    sqrled=0;
    input.append("4");
    ui->labout->setText(input);
}


void FormMain::on_btn5_clicked()
{
    evoed=0;
    sqrled=0;
    input.append("5");
    ui->labout->setText(input);
}


void FormMain::on_btn6_clicked()
{
    evoed=0;
    sqrled=0;
    input.append("6");
    ui->labout->setText(input);
}


void FormMain::on_btnmulti_clicked()
{
    evoed=0;
    sqrled=0;
    if(calced){
        expression=input;
        calced=0;
    }
    if(expression=="" ||(expression.right(1)=="0"
                             ||expression.right(1)=="1"
                             ||expression.right(1)=="2"
                             ||expression.right(1)=="3"
                             ||expression.right(1)=="4"
                             ||expression.right(1)=="5"
                             ||expression.right(1)=="6"
                             ||expression.right(1)=="7"
                             ||expression.right(1)=="8"
                             ||expression.right(1)=="9" )){

        if(input=="" &&expression==""){
            expression="0×";
        }else if(input=="" &&expression!=""){
            input=expression;
            expression=input+"×";
        }else{
            expression=input+"×";
        }

        ui->labexp->setText(expression);
        input="";
        ui->labout->setText("0");
    }else{
        if(input==""&& ui->labout->text()!="0"){
            expression=expression.left(expression.size()-1)+"×";
            ui->labexp->setText(expression);
            return;
        }

        double outcome=calc(expression,input);
        expression=QString::number(outcome)+"×";
        if(QString::number(outcome)=="inf" ||  QString::number(outcome)=="nan"){
            ui->labexp->clear();
            input="";
            ui->labout->setText("Invalid!");
            expression="";
            return;
        }
        ui->labexp->setText(expression);
        input="";
        ui->labout->setText("0");
    }
}


void FormMain::on_btn1_clicked()
{
    evoed=0;
    sqrled=0;
    input.append("1");
    ui->labout->setText(input);
}


void FormMain::on_btn2_clicked()
{
    evoed=0;
    sqrled=0;
    input.append("2");
    ui->labout->setText(input);
}


void FormMain::on_btn3_clicked()
{
    evoed=0;
    sqrled=0;
    input.append("3");
    ui->labout->setText(input);
}


void FormMain::on_btndivide_clicked()
{
    evoed=0;
    sqrled=0;
    if(calced){
        expression=input;
        calced=0;
    }
    // if(input=="0" && expression!=""){
    //     input=expression;
    // }
    if(expression=="" ||(expression.right(1)=="0"
                             ||expression.right(1)=="1"
                             ||expression.right(1)=="2"
                             ||expression.right(1)=="3"
                             ||expression.right(1)=="4"
                             ||expression.right(1)=="5"
                             ||expression.right(1)=="6"
                             ||expression.right(1)=="7"
                             ||expression.right(1)=="8"
                             ||expression.right(1)=="9" )){

        if(input=="" &&expression==""){
            expression="0÷";
        }else if(input=="" &&expression!=""){
            input=expression;
            expression=input+"÷";
        }else{
            expression=input+"÷";
        }

        ui->labexp->setText(expression);
        input="";
        ui->labout->setText("0");
    }else{
        if(input=="" && ui->labout->text()!="0"){
            expression=expression.left(expression.size()-1)+"÷";
            ui->labexp->setText(expression);
            return;
        }
        double outcome=calc(expression,input);
        // if(QString::number(outcome)=="inf" ||  QString::number(outcome)=="nan"){
        //     ui->labexp->clear();
        //     input="";
        //     ui->labout->setText("Invalid!");
        //     expression="";
        //     return;
        // }
        expression=QString::number(outcome)+"÷";
        ui->labexp->setText(expression);
        input="";
        ui->labout->setText("0");
    }

}


void FormMain::on_btndot_clicked()
{
    evoed=0;
    sqrled=0;
    if(input==""){
        input="0";
    }
    if( !input.contains(".")){
        input.append(".");
        ui->labout->setText(input);
    }
}


void FormMain::on_btn0_clicked()
{
    evoed=0;
    sqrled=0;
    if(input!=""){
        input=input+"0";
        ui->labout->setText(input);
    }
}


void FormMain::on_btnbksp_clicked()
{
    evoed=0;
    sqrled=0;
    if(input!=""){
        input=input.left(input.size()-1);
        if(input==""){
           ui->labout->setText("0");
        }else{
            ui->labout->setText(input);
        }

    }
}


void FormMain::on_btnequal_clicked()
{
    evoed=0;
    sqrled=0;
    if(expression.right(1)=="="){
        expression=input;
        ui->labexp->setText(expression);
        ui->labout->setText(input);
    }
    if(expression=="" ||(expression.right(1)=="0"
                             ||expression.right(1)=="1"
                             ||expression.right(1)=="2"
                             ||expression.right(1)=="3"
                             ||expression.right(1)=="4"
                             ||expression.right(1)=="5"
                             ||expression.right(1)=="6"
                             ||expression.right(1)=="7"
                             ||expression.right(1)=="8"
                             ||expression.right(1)=="9" )){
        ui->labout->setText(QString::number(expression.toDouble()));
    }else{
        double outcome=calc(expression,input);
        if(QString::number(outcome)=="inf" ||  QString::number(outcome)=="nan"){
            ui->labexp->clear();
            input="";
            ui->labout->setText("Invalid!");
            expression="";
            return;
        }
        expression=expression+input+"=";
        input=QString::number(outcome);
        ui->labexp->setText(expression);
        ui->labout->setText(input);
        calced=1;
    }
}

void FormMain::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Enter ||event->key()==Qt::Key_Equal ){
        on_btnequal_clicked();
    }
}

double FormMain::calc(QString firstExpression,QString lastExpression)
{

    double outcome=0.1;
    QString symbol=firstExpression.right(1);
    QString first=firstExpression.left(firstExpression.size()-1);

    qint16 digitcount1=first.lastIndexOf(".");
    qint16 digitcount2=lastExpression.lastIndexOf(".");
    double firstNum;
    double lastNum;
    firstNum=first.toDouble();
    lastNum=lastExpression.toDouble();
    if(digitcount1==-1) digitcount1=0;
    if(digitcount2==-1) digitcount2=0;
    if(digitcount1>=digitcount2){
        lastNum=std::round(lastNum* pow(10, digitcount1))/pow(10, digitcount1);
        outcome=std::round(outcome* pow(10, digitcount1))/pow(10, digitcount1);
    }else{
        firstNum=std::round(firstNum* pow(10, digitcount2))/pow(10, digitcount2);
        outcome=std::round(outcome* pow(10, digitcount2))/pow(10, digitcount2);
    }
    if(symbol=="+"){
        outcome=firstNum+lastNum;
    }else if(symbol=="-"){
        outcome=firstNum-lastNum;
    }else if(symbol=="×"){
        outcome=firstNum*lastNum;
    }else if(symbol=="÷"){
        double temp=firstNum/lastNum;
        if(temp*lastNum!=outcome){
            outcome=std::round((outcome=firstNum/lastNum)* 1000000000)/1000000000;
            outcome=firstNum/lastNum;
        }
    }

    // if(digitcount1>=digitcount2){
    //     outcome=std::round(outcome* pow(10, digitcount2))/pow(10, digitcount2);
    // }else{
    //     outcome=std::round(outcome* pow(10, digitcount1))/pow(10, digitcount1);
    // }

    return  outcome;


}

