#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(numbers()));

  connect(ui->pushButton_bracketLeft, SIGNAL(clicked()), this,
          SLOT(brackets()));
  connect(ui->pushButton_bracketRight, SIGNAL(clicked()), this,
          SLOT(brackets()));

  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(operands()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(operands()));

  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(mat_functions()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(mat_functions()));
  connect(ui->pushButton_log, SIGNAL(clicked()), this, SLOT(mat_functions()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(mat_functions()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(mat_functions()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(mat_functions()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(mat_functions()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(mat_functions()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(mat_functions()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_pushButton_graph_clicked() { graph.show(); }

void MainWindow::numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString str = ui->result_show->text();
  if (str == "0" &&
      button->text() ==
          '0') {  // чтобы в пустой строке ни писалось больше одного нулей
    ui->result_show->setText(button->text());
  } else if (str == "0" &&
             button->text() !=
                 '0') {  // случай в нашей result 0 и после нажимаем на число
    ui->result_show->setText(button->text());
  } else {
    ui->result_show->setText(ui->result_show->text() + button->text());
  }
}

int isOperand(QChar ch) {
  int res = 0;
  if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^') {
    res = 1;
  }
  return res;
}

void MainWindow::on_pushButton_dot_clicked() {
  int res = 0;
  QString str = ui->result_show->text();
  int len = str.length();
  for (int i = 0; i < len; ++i) {
    if (str[i] == '.') {
      res = 1;
    } else if (isOperand(str[i])) {
      res = 0;
    } else if ((len - 1) == i &&
               res == 0) {  // будет ли точка поставлена или нет
      ui->result_show->setText(ui->result_show->text() + '.');
    }
  }
}

void MainWindow::brackets() {
  QPushButton *button = (QPushButton *)sender();
  ui->result_show->setText(ui->result_show->text() + button->text());
}

void MainWindow::operands() {
  QPushButton *button = (QPushButton *)sender();

  ui->result_show->setText(ui->result_show->text() + button->text());
}

void MainWindow::on_pushButton_clean_clicked() {
  ui->result_show->setText("");
  ui->x_label->setText("");
}

void MainWindow::on_pushButton_del_clicked() {
  QString str = ui->result_show->text();
  int len = str.length();
  if (len != 0) {
    str.remove(len - 1, 1);
    ui->result_show->setText(str);
  }
}

void MainWindow::mat_functions() {
  QPushButton *button = (QPushButton *)sender();
  ui->result_show->setText(ui->result_show->text() + button->text() + '(');
}

void MainWindow::on_pushButton_x_clicked() {
  QString str = ui->result_show->text();
  if (!str.contains('x')) {
    ui->result_show->setText(str + 'x');
  }
}

void MainWindow::on_pushButton_equal_clicked() {
  QString str = ui->result_show->text();
  int len = str.length();
  char *outStr = NULL;

  char str_expression[255] = {'\0'};
  std::string std_str = str.toStdString();
  for (int i = 0; i < len; ++i) {
    str_expression[i] = (char)std_str[i];
  }

  for (int i = 0; i < len; ++i) {
    if (i < (len - 1) && str[i] == 'x' && !isOperand(str[i + 1])) {  //
      ui->result_show->setText("Error with X");
    } else if (i != 0 && str[i] == 'x' && !isOperand(str[i - 1])) {  //
      ui->result_show->setText("Error with X");
    }
  }
  if (ui->result_show->text() != "Error with X") {
    QString x = ui->x_label->text();
    if (str == "x" && x[0] != 's' && x[0] != 'c' && x[0] != 't') {
      ui->result_show->setText(x);
    } else {
      char x_expression[255] = {'\0'};
      std::string x_std_str = x.toStdString();

      for (int i = 0; i < len; ++i) {
        x_expression[i] = (char)x_std_str[i];
      }
      check_valid_form(str_expression, &outStr);

      if (outStr == NULL) {
        double num_res = 0.0;
        char real_result[256] = {'\0'};
        infixToPostfix(str_expression, real_result);
        evaluatePostfix(real_result, &num_res, x_expression);
        QString s = QString::number(num_res);
        ui->result_show->setText(s);
      } else {
        ui->result_show->setText(outStr);
      }
    }
  }
}
