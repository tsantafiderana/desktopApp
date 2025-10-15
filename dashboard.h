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
    void loadStylesheet(); // NOUVELLE MÉTHODE

    // SUPPRIMER toutes les constantes de style QString
    // const QString TABLE_VIEW_STYLE = R"(...)" -> SUPPRIMÉ
    // const QString BUTTON_STYLE_INACTIVE = R"(...)" -> SUPPRIMÉ
    // const QString BUTTON_STYLE_ACTIVE = R"(...)" -> SUPPRIMÉ
    // const QString DARK_THEME_MENU = R"(...)" -> SUPPRIMÉ
    // const QString DARK_THEME_PAGE = R"(...)" -> SUPPRIMÉ
};

#endif // DASHBOARD_H
