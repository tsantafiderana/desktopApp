#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QMainWindow>
#include <QPushButton>
#include <QStyledItemDelegate>

class BadgeItemDelegate : public QStyledItemDelegate
{
public:
    explicit BadgeItemDelegate(QObject *parent = nullptr) : QStyledItemDelegate(parent) {}

protected:
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

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
    BadgeItemDelegate *m_badgeDelegate;

    void initializeMenuButtons();
    void initializeReservationTable();
    void initializeOccupancyTable();
    void fillReservationTableWithTemplateData();
    void fillOccupancyTableWithTemplateData();
    void updateActiveButton(QPushButton* activeButton, QString path);

    const QString TABLE_VIEW_STYLE = R"(
        QTableView {
            border: 1px solid #2d3f4a;
            border-radius: 8px;
            background-color: #18262d;
            gridline-color: transparent;
            color: #e2f3f4;
            alternate-background-color: #18262d;
        }
        QTableView::item {
            border: none;
            border-bottom: 1px solid #2d3f4a;
            padding: 12px 24px;
            background-color: #18262d;
            color: #e2f3f4;
            font-size : 15px;
        }
        QTableView::item:alternate {
            background-color: #18262d;
        }
        QHeaderView::section {
            background-color: #101c22;
            padding: 12px 24px;
            border: none;
            border-bottom: 1px solid #2d3f4a;
            color: #e2f3f4;
            font-weight: bold;
            font-size: 12.25px;
            text-transform: uppercase;
        }
        QTableView QTableCornerButton::section {
            background-color: #101c22;
            border: none;
            border-bottom: 1px solid #2d3f4a;
            border-right: 1px solid #2d3f4a;
        }
    )";

    const QString BUTTON_STYLE_INACTIVE = R"(
        QPushButton {
            border : none;
            text-align : left;
            padding : 0 0 0 20px;
            color : #90A4AE;
            font-size : 15.5px;
            border-radius : 10px;
        }

        QPushButton:hover {
            background-color : #16384e;
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
            background-color : #16384e;
            border-radius : 10px;
        }
    )";

    const QString DARK_THEME_MENU = R"(
        #frame_menu_container {
            background-color : #18262d;
        }

        #label_menu_title {
            color :#F0F3F4;
            font : 17.5px bold;
        }

        #label_icon {
            background-color : #1193d4;
            border-radius : 10px;
        }
    )";

    const QString DARK_THEME_PAGE = R"(
        QWidget {
            background-color : #101c22;
        }

        #label_3{
            color : #F0F3F5;
            font-size : 30px;
            font-weight : bold;
        }

        #label_4{
            color : #84a4aa;
            font-size : 15px;
            padding : 0 0 0 10px;
        }

        #label_5, #label_6, #label_7{
            color : #F0F3F4;
            font-weight : bold;
            font-size : 20px;
            padding : 0 0 0 7.5px;
        }

        #label_10, #label_18, #label_22{
            font : 500 14px;
            background-color: transparent;
            padding : 10px;
            color : #859eae;
        }
        #widget_availability, #widget_occupying, #widget_checkins {
            border : 2px solid #2d3f4a;
            background-color : #18262d;
            border-radius: 8px;
        }
        #label_11, #label_19, #label_23{
            background-color :#18262d ;
            font : 30px bold;
            padding : 8px;
            color : #e2f3f4;
        }

    )";
};

#endif // DASHBOARD_H
