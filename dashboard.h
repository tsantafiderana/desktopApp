#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class Dashboard;
}

class Dashboard : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_btn_reservation_clicked();

    void on_btn_dashboard_clicked();

    void on_btn_room_clicked();

    void on_btn_guest_clicked();

    void on_btn_report_clicked();

private:
    Ui::Dashboard *ui;

    // Méthodes d'initialisation organisées
    void initializeMenuButtons();
    void initializeReservationTable();
    void initializeOccupancyTable();
    void fillReservationTableWithTemplateData();
    void fillOccupancyTableWithTemplateData();
    void updateActiveButton(QPushButton* activeButton, QString path);

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

    const QString BUTTON_STYLE_INACTIVE = R"(
        QPushButton {
            border : none;
            text-align : left;
            padding : 0 0 0 20px;
            color : black;
            font-size : 15.5px;
            border-radius : 10px;
        }
    )";

    const QString BUTTON_STYLE_ACTIVE = R"(
        QPushButton {
            border : none;
            text-align : left;
            padding : 0 0 0 20px;
            color : #1194d4;
            font-weight : bold;
            font-size : 15.5px;
            background-color  : #E7F4FB;
            border-radius : 10px;
        }

    )";
};

#endif // DASHBOARD_H
