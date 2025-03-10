#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>
#include <QLineEdit>
#include <QTabWidget>
#include <QTableWidget>
#include <QHeaderView>
#include <QMessageBox>
#include <QRegularExpression>

#include <vector>
#include <sstream>
#include <random>
#include <chrono>

using namespace std;

vector<int> Sort_Select(vector<int> input_list) {
    for (int j = input_list.size() - 1; j >= 0; j--) {
        int max = input_list[j];
        int idx = j;
        for (int i = 0; i < j; i++)
            if (input_list[i] > max) {
                max = input_list[i];
                idx = i;
            }
        int tmp = input_list[j];
        input_list[j] = input_list[idx];
        input_list[idx] = tmp;
    }
    return input_list;
}

vector<int> Sort_Paste(vector<int> input_list) {
    for (int j = 1; j < input_list.size(); j++) {
        int el = 0;
        for (int i = 0; i <= j; i++) {
            el = input_list[j];
            if (input_list[i] >= el) {
                input_list[j] = input_list[i];
                input_list[i] = el;
            }
        }
    }
    return input_list;
}

vector<int> Sort_Bubble(vector<int> input_list) {
    for (int j = 0; j < input_list.size(); j++) {
        for (int i = 0; i < input_list.size() - 1; i++)
            if (input_list[i+1] < input_list[i]) {
                int tmp = input_list[i+1];
                input_list[i+1] = input_list[i];
                input_list[i] = tmp;
            }
    }
    return input_list;
}

int Sorted_Test(std::vector<int> input_list) {
    for (int i = 0; i < input_list.size() - 1; i++) {
        if (!(input_list[i] <= input_list[i+1])) return 0;
    }
    return 1;
}

class SortingApp : public QWidget {
    Q_OBJECT
private:
    QComboBox* sortMethodComboBox;
    QComboBox* listGenerationMethodComboBox;
    QLineEdit* listSizeLineEdit;
    QLineEdit* iterationsLineEdit;
    QTextEdit* inputListTextEdit;
    QTextEdit* outputListTextEdit;
    QPushButton* generateButton;
    QPushButton* sortButton;
    QPushButton* testButton;
    QTabWidget* tabWidget;
    QTableWidget* testResultsTable;

    const QString sortMethodNames[3] = {
        "Вибіркове сортування", 
        "Сортування вставкою", 
        "Бульбашкове сортування"
    };

    std::vector<int> generateList() {
        int listSize = listSizeLineEdit->text().toInt();
        std::vector<int> list(listSize);
        
        if (listGenerationMethodComboBox->currentIndex() == 0) {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(0, 100);
            
            for (int i = 0; i < listSize; i++) {
                list[i] = distrib(gen);
            }
        } else {
            QString inputText = inputListTextEdit->toPlainText();
            QStringList numberStrings = inputText.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
            
            for (int i = 0; i < qMin(listSize, numberStrings.size()); i++) {
                list[i] = numberStrings[i].toInt();
            }
        }
        
        return list;
    }

public:
    SortingApp(QWidget *parent = nullptr);

private slots:
    void onGenerationMethodChanged(int index) {
        inputListTextEdit->setEnabled(index == 1);
        listSizeLineEdit->setEnabled(index == 0);
    }

    void onGenerateList() {
        if (listGenerationMethodComboBox->currentIndex() == 0) {
            int listSize = listSizeLineEdit->text().toInt();
            std::vector<int> list = generateList();
            
            QString listText;
            for (int num : list) {
                listText += QString::number(num) + " ";
            }
            inputListTextEdit->setPlainText(listText.trimmed());
        }
    }

    void onSortList() {
        std::vector<int> list;
        QString inputText = inputListTextEdit->toPlainText();
        QStringList numberStrings = inputText.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        
        for (const QString& numStr : numberStrings) {
            list.push_back(numStr.toInt());
        }

        std::vector<int> sortedList;
        switch(sortMethodComboBox->currentIndex()) {
            case 0: sortedList = Sort_Select(list); break;
            case 1: sortedList = Sort_Paste(list); break;
            case 2: sortedList = Sort_Bubble(list); break;
        }

        QString outputText;
        for (int num : sortedList) {
            outputText += QString::number(num) + " ";
        }
        outputListTextEdit->setPlainText(outputText.trimmed());
    }

    void onTestSort() {
        int iterations = iterationsLineEdit->text().toInt();
        int listSize = listSizeLineEdit->text().toInt();
        
        QString currentSortMethod = sortMethodNames[sortMethodComboBox->currentIndex()];
        
        testResultsTable->setRowCount(0);

        int errorCount = 0;
        for (int i = 1; i <= iterations; i++) {
            std::vector<int> list = generateList();
            
            std::vector<int> sortedList;
            switch(sortMethodComboBox->currentIndex()) {
                case 0: sortedList = Sort_Select(list); break;
                case 1: sortedList = Sort_Paste(list); break;
                case 2: sortedList = Sort_Bubble(list); break;
            }

            bool isSorted = Sorted_Test(sortedList);
            
            int row = testResultsTable->rowCount();
            testResultsTable->insertRow(row);
            
            testResultsTable->setItem(row, 0, new QTableWidgetItem(QString::number(i)));
            
            testResultsTable->setItem(row, 1, new QTableWidgetItem(QString::number(listSize)));
            
            testResultsTable->setItem(row, 2, new QTableWidgetItem(currentSortMethod));
            
            QTableWidgetItem* statusItem = new QTableWidgetItem(isSorted ? "OK" : "BAD");
            statusItem->setBackground(isSorted ? QColor(0, 255, 0, 50) : QColor(255, 0, 0, 50));
            testResultsTable->setItem(row, 3, statusItem);
            
            if (!isSorted) {
                QString listStr;
                for (int num : sortedList) {
                    listStr += QString::number(num) + " ";
                }
                testResultsTable->setItem(row, 4, new QTableWidgetItem(listStr.trimmed()));
                errorCount++;
            }
        }

        QString resultMessage = QString("Тестування методу '%1' завершено.\n")
            .arg(currentSortMethod)
            + QString("Кількість невдалих спроб: %1/%2\n")
            .arg(errorCount).arg(iterations);
        
        QMessageBox::information(this, "Результати тестування", resultMessage);
    }
};

SortingApp::SortingApp(QWidget *parent) : QWidget(parent) {
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    tabWidget = new QTabWidget();

    QWidget* sortingTab = new QWidget();
    QVBoxLayout* sortingLayout = new QVBoxLayout(sortingTab);

    QHBoxLayout* sortMethodLayout = new QHBoxLayout();
    QLabel* sortMethodLabel = new QLabel("Метод сортування:");
    sortMethodComboBox = new QComboBox();
    sortMethodComboBox->addItems({
        sortMethodNames[0], 
        sortMethodNames[1], 
        sortMethodNames[2]
    });
    sortMethodLayout->addWidget(sortMethodLabel);
    sortMethodLayout->addWidget(sortMethodComboBox);
    sortingLayout->addLayout(sortMethodLayout);

    QHBoxLayout* listGenerationLayout = new QHBoxLayout();
    QLabel* listGenerationLabel = new QLabel("Метод створення списку:");
    listGenerationMethodComboBox = new QComboBox();
    listGenerationMethodComboBox->addItems({"Випадкові числа", "Ручний ввід"});
    listGenerationLayout->addWidget(listGenerationLabel);
    listGenerationLayout->addWidget(listGenerationMethodComboBox);
    sortingLayout->addLayout(listGenerationLayout);

    QHBoxLayout* listSizeLayout = new QHBoxLayout();
    QLabel* listSizeLabel = new QLabel("Розмір списку:");
    listSizeLineEdit = new QLineEdit("10");
    listSizeLayout->addWidget(listSizeLabel);
    listSizeLayout->addWidget(listSizeLineEdit);
    sortingLayout->addLayout(listSizeLayout);

    generateButton = new QPushButton("Згенерувати список");
    sortingLayout->addWidget(generateButton);

    QLabel* inputListLabel = new QLabel("Вхідний список:");
    sortingLayout->addWidget(inputListLabel);
    inputListTextEdit = new QTextEdit();
    sortingLayout->addWidget(inputListTextEdit);

    sortButton = new QPushButton("Сортувати");
    sortingLayout->addWidget(sortButton);

    QLabel* outputListLabel = new QLabel("Відсортований список:");
    sortingLayout->addWidget(outputListLabel);
    outputListTextEdit = new QTextEdit();
    sortingLayout->addWidget(outputListTextEdit);

    QWidget* testingTab = new QWidget();
    QVBoxLayout* testingLayout = new QVBoxLayout(testingTab);

    QHBoxLayout* testSettingsLayout = new QHBoxLayout();
    QLabel* iterationsLabel = new QLabel("Кількість ітерацій:");
    iterationsLineEdit = new QLineEdit("100");
    testSettingsLayout->addWidget(iterationsLabel);
    testSettingsLayout->addWidget(iterationsLineEdit);
    testingLayout->addLayout(testSettingsLayout);

    testButton = new QPushButton("Провести тестування");
    testingLayout->addWidget(testButton);

    testResultsTable = new QTableWidget(0, 5);
    testResultsTable->setHorizontalHeaderLabels({
        "Ітерація", 
        "Розмір списку", 
        "Метод сортування", 
        "Статус", 
        "Список"
    });
    testResultsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    testingLayout->addWidget(testResultsTable);

    tabWidget->addTab(sortingTab, "Сортування");
    tabWidget->addTab(testingTab, "Тестування");
    mainLayout->addWidget(tabWidget);

    connect(generateButton, &QPushButton::clicked, this, &SortingApp::onGenerateList);
    connect(sortButton, &QPushButton::clicked, this, &SortingApp::onSortList);
    connect(testButton, &QPushButton::clicked, this, &SortingApp::onTestSort);
    connect(listGenerationMethodComboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), 
            this, &SortingApp::onGenerationMethodChanged);

    onGenerationMethodChanged(0);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    SortingApp window;
    window.setWindowTitle("АСД лаби 1-?");
    window.resize(500, 700);
    window.show();
    return app.exec();
}

#include "gui.moc" 