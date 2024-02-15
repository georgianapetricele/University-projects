#include "Gui.h"

Gui::Gui(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    service.read_from_file();
    populate_list();
    update_coefficients();
    compute_solution();
}

Gui::~Gui()
{}

void Gui::populate_list()
{
    ui.listWidget->clear();
    for (auto& eq : service.get_equations())
    {
        if (service.compute_delta(eq) >= 0)
        {
            auto* item = new QListWidgetItem(QString::fromStdString(eq.toString()));
            QFont font;
            font.setBold(true);
            item->setFont(font);
            ui.listWidget->addItem(item);
        }
        else
		ui.listWidget->addItem(QString::fromStdString(eq.toString()));
	}
}


void Gui::update_coefficients()
{
    QObject::connect(ui.listWidget, &QListWidget::itemSelectionChanged, [&]()
        {
               int index = ui.listWidget->currentIndex().row();
               if(index<0)
                	return;
               if (!ui.lineEdit->text().isEmpty() && !ui.lineEdit_2->text().isEmpty() && !ui.lineEdit_3->text().isEmpty())
               {
                   double a = ui.lineEdit->text().toDouble();
                   double b = ui.lineEdit_2->text().toDouble();
                   double c = ui.lineEdit_3->text().toDouble();
                   service.update_coefficients(index, a, b, c);
                   populate_list();
               }
		});
}

void Gui::compute_solution()
{
    QObject::connect(ui.pushButton, &QPushButton::clicked, [&]()
        {
            int index = ui.listWidget->currentIndex().row();
            if (index < 0)
                return;
            vector<Equation> equations = service.get_equations();
            Equation equation = equations[index];
            ui.lineEdit->setText(QString::fromStdString(to_string(equation.get_a())));
            ui.lineEdit_2->setText(QString::fromStdString(to_string(equation.get_b())));
            ui.lineEdit_3->setText(QString::fromStdString(to_string(equation.get_c())));

            string solution = service.compute_solutions(equation);
            ui.lineEdit_4->setText(QString::fromStdString(solution));
        });
}