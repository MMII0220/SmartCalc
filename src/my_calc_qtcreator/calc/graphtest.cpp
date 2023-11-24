#include "graphtest.h"

#include "ui_graphtest.h"

GraphTest::GraphTest(QWidget *parent) : QWidget(parent), ui(new Ui::GraphTest) {
  ui->setupUi(this);
}

GraphTest::~GraphTest() { delete ui; }

void GraphTest::on_pushButton_draw_clicked() {
  graph_value = (ui->pushButton_value->text()).toDouble();
  h = (ui->pushButton_step->text()).toDouble();
  xBegin = (ui->pushButton_x_min->text()).toDouble();
  xEnd = (ui->pushButton_x_max->text()).toDouble() + h;
  yBegin = (ui->pushButton_y_min->text()).toDouble();
  yEnd = (ui->pushButton_y_max->text()).toDouble() + h;
  ui->widget->xAxis->setRange(xBegin, xEnd);
  ui->widget->yAxis->setRange(yBegin, yEnd);
  int dots_amount = (xEnd - xBegin) / h;
  double X = xBegin;

  for (int i = 0; i < dots_amount; i++) {
    x.push_back(graph_value);
    if (ui->pushButton_value->text() == "sin(") {
      y.push_back(sin(X));
    } else {
      y.push_back(graph_value + X);
    }
    X += h;
  }
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}
