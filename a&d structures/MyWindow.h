#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>

class MyWindow : public QWidget {
    Q_OBJECT  // Обов’язково!

public:
    MyWindow(QWidget *parent = nullptr);

private slots:
    void onButtonClicked();

private:
    QLineEdit *inputField;
    QLabel *outputLabel;
};

#endif // MYWINDOW_H
