#ifndef GRAPHTEST_H
#define GRAPHTEST_H

#include <QPushButton>
#include <QWidget>
#include <QtMath>

namespace Ui {
class GraphTest;
}

class GraphTest : public QWidget {
  Q_OBJECT

 public:
  explicit GraphTest(QWidget *parent = nullptr);
  ~GraphTest();

 private slots:
  void on_pushButton_draw_clicked();

 private:
  Ui::GraphTest *ui;
  double xBegin, xEnd, yBegin, yEnd, h, X, graph_value;
  int N;
  QVector<double> x, y;
};

#endif  // GRAPHTEST_H
