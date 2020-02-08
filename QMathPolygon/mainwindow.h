#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "scenewithdrawing.h"
#include "viewwithbuttons.h"
#include "addpolygon.h"
#include "anymathpolygon.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_triangle_button_clicked();
    void on_quadrangle_button_clicked();
    void on_pentagon_button_clicked();
    void on_square_button_clicked();
    void on_xsquare_button_clicked();

private:
    Ui::MainWindow* ui;
    SceneWithDrawing* coordSystem;
    ViewWithButtons* systemView;

};
#endif // MAINWINDOW_H
