#include "dashboard.h"
#include "ui_dashboard.h"
#include <QStandardItemModel>
#include <QIcon>
#include <QMap>
#include <QHeaderView>

Dashboard::Dashboard(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    // Configuration de la fenêtre
    setWindowTitle("Hotel Management System - Dashboard");
    setMinimumSize(1024, 768);
    setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);
    setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint | Qt::WindowMaximizeButtonHint | Qt::WindowCloseButtonHint);

    // Initialisation organisée
    initializeMenuButtons();
    initializeReservationTable();
    initializeOccupancyTable();

    // Page par défaut - Dashboard
    updateActiveButton(ui->btn_dashboard, ":/new/icons/icons/home_35dp_1193D4_FILL0_wght400_GRAD0_opsz40.png");
    ui->stackedWidget->setCurrentIndex(0);
    ui->frame_menu_container->setStyleSheet(DARK_THEME_MENU);
    ui->page->setStyleSheet(DARK_THEME_PAGE);
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::initializeMenuButtons()
{
    // Configuration des icônes des boutons de menu avec icônes inactives par défaut
    ui->btn_dashboard->setIcon(QIcon(":/new/iconsfade/icons/home_24dp_E3E3E3_FILL0_wght400_GRAD0_opsz24.svg"));
    ui->btn_dashboard->setIconSize(QSize(24, 24));

    ui->btn_reservation->setIcon(QIcon(":/new/icons/icons/date_range_35dp_6B7280_FILL0_wght400_GRAD0_opsz40.png"));
    ui->btn_reservation->setIconSize(QSize(24, 24));

    ui->btn_guest->setIcon(QIcon(":/new/icons/icons/person_2_35dp_6B7280_FILL0_wght400_GRAD0_opsz40.png"));
    ui->btn_guest->setIconSize(QSize(24, 24));

    ui->btn_report->setIcon(QIcon(":/new/icons/icons/bar_chart_4_bars_35dp_6B7280_FILL0_wght400_GRAD0_opsz40.png"));
    ui->btn_report->setIconSize(QSize(24, 24));

    ui->btn_room->setIcon(QIcon(":/new/icons/icons/bed_35dp_6B7280_FILL0_wght400_GRAD0_opsz40.png"));
    ui->btn_room->setIconSize(QSize(24, 24));
}

void Dashboard::initializeReservationTable()
{
    // Configuration du modèle
    QStandardItemModel *modelReservation = new QStandardItemModel(5, 5, this);
    modelReservation->setHorizontalHeaderLabels({"Guest Name", "Room Number", "Check-in", "Check-out", "Status"});

    // Configuration de la vue
    ui->tableView_reservation->setModel(modelReservation);
    ui->tableView_reservation->verticalHeader()->setVisible(false);
    ui->tableView_reservation->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView_reservation->setFocusPolicy(Qt::NoFocus);

    // Configuration des largeurs de colonnes
    ui->tableView_reservation->setColumnWidth(0, 260);
    ui->tableView_reservation->setColumnWidth(1, 255);
    ui->tableView_reservation->setColumnWidth(2, 200);
    ui->tableView_reservation->setColumnWidth(3, 225);
    ui->tableView_reservation->setColumnWidth(4, 250);

    // Configuration des hauteurs de lignes
    for(int i = 0; i < modelReservation->rowCount(); i++) {
        ui->tableView_reservation->setRowHeight(i, 64);
    }

    // Style de l'en-tête
    ui->tableView_reservation->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView_reservation->horizontalHeader()->setStretchLastSection(true);

    // Application du style
    ui->tableView_reservation->setStyleSheet(TABLE_VIEW_STYLE);

    // Remplissage avec des données template
    fillReservationTableWithTemplateData();
}

void Dashboard::initializeOccupancyTable()
{
    // Configuration du modèle
    QStandardItemModel *modelOccupancy = new QStandardItemModel(6, 4, this);
    modelOccupancy->setHorizontalHeaderLabels({"Room Number", "Room Type", "Status", "Guest Name"});

    // Configuration de la vue
    ui->tableView_occupancy->setModel(modelOccupancy);
    ui->tableView_occupancy->verticalHeader()->setVisible(false);
    ui->tableView_occupancy->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView_occupancy->setFocusPolicy(Qt::NoFocus);

    // Configuration des largeurs de colonnes
    ui->tableView_occupancy->setColumnWidth(0, 320);
    ui->tableView_occupancy->setColumnWidth(1, 270);
    ui->tableView_occupancy->setColumnWidth(2, 290);
    ui->tableView_occupancy->setColumnWidth(3, 225);

    // Configuration des hauteurs de lignes
    for(int i = 0; i < modelOccupancy->rowCount(); i++) {
        ui->tableView_occupancy->setRowHeight(i, 64);
    }

    // Style de l'en-tête
    ui->tableView_occupancy->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);
    ui->tableView_occupancy->horizontalHeader()->setStretchLastSection(true);

    // Application du style
    ui->tableView_occupancy->setStyleSheet(TABLE_VIEW_STYLE);

    // Remplissage avec des données template
    fillOccupancyTableWithTemplateData();
}

void Dashboard::fillReservationTableWithTemplateData()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView_reservation->model());
    if (!model) return;

    // Données template pour les réservations (basées sur le HTML)
    QStringList guestNames = {"Ethan Harper", "Olivia Bennett", "Noah Carter", "Ava Morgan", "Liam Foster"};
    QStringList roomNumbers = {"101", "205", "310", "112", "215"};
    QStringList checkInTimes = {"14:00", "15:00", "16:00", "17:00", "18:00"};
    QStringList checkOutTimes = {"11:00", "12:00", "13:00", "14:00", "15:00"};
    QStringList statuses = {"Confirmed", "Checked In", "Pending", "Confirmed", "Checked In"};

    for (int row = 0; row < model->rowCount(); ++row) {
        // GUEST NAME
        QStandardItem *guestItem = new QStandardItem(guestNames[row]);
        guestItem->setForeground(QBrush(QColor("#e2f3f4")));
        model->setItem(row, 0, guestItem);

        // ROOM NUMBER
        QStandardItem *roomItem = new QStandardItem(roomNumbers[row]);
        roomItem->setForeground(QBrush(QColor("#e2f3f4")));
        model->setItem(row, 1, roomItem);

        // CHECK-IN
        QStandardItem *checkInItem = new QStandardItem(checkInTimes[row]);
        checkInItem->setForeground(QBrush(QColor("#e2f3f4")));
        model->setItem(row, 2, checkInItem);

        // CHECK-OUT
        QStandardItem *checkOutItem = new QStandardItem(checkOutTimes[row]);
        checkOutItem->setForeground(QBrush(QColor("#e2f3f4")));
        model->setItem(row, 3, checkOutItem);

        // STATUS
        QStandardItem *statusItem = new QStandardItem(statuses[row]);
        statusItem->setTextAlignment(Qt::AlignCenter);

        // Appliquer des couleurs selon le statut (basé sur le HTML)
        if (statuses[row] == "Confirmed") {
            statusItem->setForeground(QBrush(QColor("#065f46")));
            statusItem->setBackground(QBrush(QColor("#d1fae5")));
        } else if (statuses[row] == "Checked In") {
            statusItem->setForeground(QBrush(QColor("#1e40af")));
            statusItem->setBackground(QBrush(QColor("#dbeafe")));
        } else if (statuses[row] == "Pending") {
            statusItem->setForeground(QBrush(QColor("#92400e")));
            statusItem->setBackground(QBrush(QColor("#fef3c7")));
        }

        model->setItem(row, 4, statusItem);
    }
}

void Dashboard::fillOccupancyTableWithTemplateData()
{
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->tableView_occupancy->model());
    if (!model) return;

    // Données template pour l'occupation (basées sur le HTML)
    QStringList roomNumbers = {"101", "102", "201", "202", "301", "302"};
    QStringList roomTypes = {"Standard", "Standard", "Deluxe", "Deluxe", "Suite", "Suite"};
    QStringList statuses = {"Occupied", "Available", "Occupied", "Available", "Occupied", "Available"};
    QStringList guestNames = {"Ethan Harper", "-", "Olivia Bennett", "-", "Noah Carter", "-"};

    for (int row = 0; row < model->rowCount(); ++row) {
        // ROOM NUMBER
        QStandardItem *roomItem = new QStandardItem(roomNumbers[row]);
        roomItem->setForeground(QBrush(QColor("#e2f3f4")));
        model->setItem(row, 0, roomItem);

        // ROOM TYPE
        QStandardItem *typeItem = new QStandardItem(roomTypes[row]);
        typeItem->setForeground(QBrush(QColor("#e2f3f4")));
        model->setItem(row, 1, typeItem);

        // STATUS
        QStandardItem *statusItem = new QStandardItem(statuses[row]);
        statusItem->setTextAlignment(Qt::AlignCenter);

        // Appliquer des couleurs selon le statut (basé sur le HTML)
        if (statuses[row] == "Occupied") {
            statusItem->setForeground(QBrush(QColor("#991b1b")));
            statusItem->setBackground(QBrush(QColor("#fecaca")));
        } else if (statuses[row] == "Available") {
            statusItem->setForeground(QBrush(QColor("#065f46")));
            statusItem->setBackground(QBrush(QColor("#d1fae5")));
        }

        model->setItem(row, 2, statusItem);

        // GUEST NAME
        QStandardItem *guestItem = new QStandardItem(guestNames[row]);
        guestItem->setForeground(QBrush(QColor("#e2f3f4")));
        model->setItem(row, 3, guestItem);
    }
}

void Dashboard::updateActiveButton(QPushButton* activeButton, QString path)
{
    // Map locale pour stocker les icônes inactives de chaque bouton
    static QMap<QPushButton*, QString> inactiveIcons = {
        {ui->btn_dashboard, ":/new/iconsfade/icons/home_24dp_E3E3E3_FILL0_wght400_GRAD0_opsz24.svg"},
        {ui->btn_reservation, ":/new/icons/icons/date_range_35dp_6B7280_FILL0_wght400_GRAD0_opsz40.png"},
        {ui->btn_guest, ":/new/icons/icons/person_2_35dp_6B7280_FILL0_wght400_GRAD0_opsz40.png"},
        {ui->btn_report, ":/new/icons/icons/bar_chart_4_bars_35dp_6B7280_FILL0_wght400_GRAD0_opsz40.png"},
        {ui->btn_room, ":/new/icons/icons/bed_35dp_6B7280_FILL0_wght400_GRAD0_opsz40.png"}
    };

    QList<QPushButton*> menuButtons = {
        ui->btn_dashboard,
        ui->btn_reservation,
        ui->btn_room,
        ui->btn_guest,
        ui->btn_report
    };

    for (QPushButton* button : menuButtons) {
        if (button == activeButton) {
            // Style et icône active
            button->setStyleSheet(BUTTON_STYLE_ACTIVE);
            button->setIcon(QIcon(path));
        } else {
            // Style et icône inactive
            button->setStyleSheet(BUTTON_STYLE_INACTIVE);
            if (inactiveIcons.contains(button)) {
                button->setIcon(QIcon(inactiveIcons[button]));
            }
        }
    }
}

// ==================== SLOTS DE NAVIGATION ====================

void Dashboard::on_btn_dashboard_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    updateActiveButton(ui->btn_dashboard, ":/new/icons/icons/home_35dp_1193D4_FILL0_wght400_GRAD0_opsz40.png");
}

void Dashboard::on_btn_reservation_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    updateActiveButton(ui->btn_reservation, ":/new/iconsfade/icons/date_range_24dp_1194D4_FILL0_wght400_GRAD0_opsz24.svg");
}

void Dashboard::on_btn_room_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    updateActiveButton(ui->btn_room, ":/new/iconsfade/icons/bed_24dp_1194D4_FILL0_wght400_GRAD0_opsz24.svg");
}

void Dashboard::on_btn_guest_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    updateActiveButton(ui->btn_guest, ":/new/iconsfade/icons/person_24dp_1194D4_FILL0_wght400_GRAD0_opsz24.svg");
}

void Dashboard::on_btn_report_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    updateActiveButton(ui->btn_report, ":/new/iconsfade/icons/bar_chart_4_bars_24dp_1194D4_FILL0_wght400_GRAD0_opsz24.svg");
}
