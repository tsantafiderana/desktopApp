#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>

namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private:
    Ui::Dashboard *ui;

    // Méthodes d'initialisation organisées
    void initializeMenuButtons();
    void initializeReservationTable();
    void initializeOccupancyTable();
    void fillReservationTableWithTemplateData();  // ← NOUVELLE MÉTHODE
    void fillOccupancyTableWithTemplateData();    // ← NOUVELLE MÉTHODE

    // Style commun pour les tableaux
    const QString TABLE_VIEW_STYLE = R"(
        QTableView {
            border: none;
            outline: none;
            background-color: white;
            gridline-color: transparent;
            color: black;
        }
        QTableView::item {
            border: none;
            border-bottom: 2px solid #F6F7F8;
            padding: 8px 20px;

        }
        QHeaderView::section {
            border: none;
            background-color: #F9FAFB;
            padding: 12px 8px;
            color: black;
            font-weight: 650;
            text-align : left;

        }
        QTableView {
            show-decoration-selected: 0;
        }
    )";
};

#endif // DASHBOARD_H
