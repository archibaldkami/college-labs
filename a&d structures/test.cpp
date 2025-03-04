#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>

class MyWindow : public QWidget {
public:
    MyWindow() {
        // Створення елементів інтерфейсу
        button = new QPushButton("Натисни мене", this);
        lineEdit = new QLineEdit(this);
        label = new QLabel("Результат з'явиться тут", this);

        // Створення макету
        layout = new QVBoxLayout();
        layout->addWidget(lineEdit);
        layout->addWidget(button);
        layout->addWidget(label);
        
        setLayout(layout);

        // Підключення сигналу натискання кнопки до функції
        connect(button, &QPushButton::clicked, this, &MyWindow::onButtonClicked);
    }

private slots:
    void onButtonClicked() {
        // Взяти текст з текстового поля
        QString text = lineEdit->text();

        // Обробка тексту (наприклад, виведення в QLabel)
        label->setText("Ти ввів: " + text);
    }

private:
    QPushButton *button;
    QLineEdit *lineEdit;
    QLabel *label;
    QVBoxLayout *layout;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MyWindow window;
    window.setWindowTitle("Простий графічний інтерфейс");
    window.resize(300, 200);
    window.show();

    return app.exec();
}
