#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QChar>
#include <QLabel>
#include <QLocale>
#include <QMainWindow>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <QTranslator>
#include <QVector>

#include "graphtest.h"

extern "C" {
#include "./../../s21_calc.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  GraphTest graph;

 private slots:
  void numbers();
  void on_pushButton_dot_clicked();
  void brackets();
  void operands();
  void on_pushButton_clean_clicked();
  void on_pushButton_equal_clicked();
  void on_pushButton_del_clicked();
  void mat_functions();
  void on_pushButton_x_clicked();
  void on_pushButton_graph_clicked();
};

#endif  // MAINWINDOW_H
