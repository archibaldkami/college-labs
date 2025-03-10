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

vector<int> Sort_Merge(vector<int> input_list) {
    int mid = input_list.size() / 2;
    if (input_list.size() % 2 == 1)
        mid++;
    int h = 1;
    int *c = new int[input_list.size()];
    int step;
    
    while (h < input_list.size()) {
        step = h;
        int i = 0;
        int j = mid;
        int k = 0;
        while (step <= mid) {
            while ((i < step) && (j < input_list.size())) {
                if (j < (mid + step) && (input_list[i] > input_list[j])) {
                    c[k] = input_list[j];
                    j++;
                } else {
                    c[k] = input_list[i];
                    i++;
                }
                k++;
            }
            while (i < step) {
                c[k] = input_list[i];
                i++;
                k++;
            }
            while (j < (mid + step) && j < input_list.size()) {
                c[k] = input_list[j];
                j++;
                k++;
            }
            step = step + h;
        }
        for (i = 0; i < input_list.size(); i++)
        input_list[i] = c[i];
        h = h * 2;
    }
    delete[] c;
    return input_list;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

vector<int> QuickSort(vector<int> input_list) {
    int list_[input_list.size()];
    for (int i = 0; i < input_list.size(); i++) {
        list_[i] = input_list[i];
    }

    quickSort(list_, 0, input_list.size());
    
    for (int i = 0; i < input_list.size(); i++) {
        input_list[i] = list_[i];
    }

    return input_list;
}

int Sorted_Test(vector<int> input_list) {
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

    const QString sortMethodNames[5] = {
        "Сортування вибором", 
        "Сортування вставкою", 
        "Сортування бульбашкою",
        "Сортування злиттям",
        "Швидке сортування"
    };

    vector<int> generateList() {
        int listSize = listSizeLineEdit->text().toInt();
        vector<int> list(listSize);
        
        if (listGenerationMethodComboBox->currentIndex() == 0) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> distrib(0, 100);
            
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
            vector<int> list = generateList();
            
            QString listText;
            for (int num : list) {
                listText += QString::number(num) + " ";
            }
            inputListTextEdit->setPlainText(listText.trimmed());
        }
    }

    void onSortList() {
        vector<int> list;
        QString inputText = inputListTextEdit->toPlainText();
        QStringList numberStrings = inputText.split(QRegularExpression("\\s+"), Qt::SkipEmptyParts);
        
        for (const QString& numStr : numberStrings) {
            list.push_back(numStr.toInt());
        }

        vector<int> sortedList;
        switch(sortMethodComboBox->currentIndex()) {
            case 0: sortedList = Sort_Select(list); break;
            case 1: sortedList = Sort_Paste(list); break;
            case 2: sortedList = Sort_Bubble(list); break;
            case 3: sortedList = Sort_Merge(list); break;
            case 4: sortedList = QuickSort(list); break;
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
            vector<int> list = generateList();
            
            vector<int> sortedList;
            switch(sortMethodComboBox->currentIndex()) {
                case 0: sortedList = Sort_Select(list); break;
                case 1: sortedList = Sort_Paste(list); break;
                case 2: sortedList = Sort_Bubble(list); break;
                case 3: sortedList = Sort_Merge(list); break;
                case 4: sortedList = QuickSort(list); break;
                
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

        QString resultMessage = QString("Тестування методу '%1' завершено.\n").arg(currentSortMethod) + QString("Кількість невдалих спроб: %1/%2\n").arg(errorCount).arg(iterations);
        
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
        sortMethodNames[2],
        sortMethodNames[3],
        sortMethodNames[4]
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
    window.setWindowTitle("ASD Labs");
    window.resize(500, 700);
    window.show();
    return app.exec();
}

#include "gui.moc" 