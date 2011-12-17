/**
 * This file is part of SpeechControl
 *
 * Copyright 2011 Jacky Alcine <jacky.alcine@thesii.org>
 *
 * SpeechControl is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * SpeechControl is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with SpeechControl; if not, write to the
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */


#include "settings.hpp"
#include "core.hpp"
#include "ui_settings.h"

namespace SpeechControl {
namespace Windows {

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    for (int i = 0; i < ui->tabWidgetWizards->count(); ++i)
        on_tabWidgetWizards_currentChanged(i);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_tabWidgetWizards_currentChanged(int p_index)
{
    switch (p_index){
        case 0:
            ui->checkBoxSysStart->setChecked(Core::instance()->getConfig("Options/AutoStart",QVariant(false)).toBool());
            ui->checkBoxDictate->setChecked(Core::instance()->getConfig("Options/Dictation",QVariant(false)).toBool());
            ui->checkBoxDesktopControl->setChecked(Core::instance()->getConfig("Options/Control",QVariant(false)).toBool());
            ui->checkBoxVoxForge->setChecked(Core::instance()->getConfig("VoxForge/EnableUploading",QVariant(false)).toBool());
        break;
    }

}

void Settings::on_buttonBox_accepted()
{
    Core::instance()->setConfig("Options/AutoStart",ui->checkBoxSysStart->checkState());
    Core::instance()->setConfig("Options/Dictation",ui->checkBoxDictate->checkState());
    Core::instance()->setConfig("Options/Control",ui->checkBoxDesktopControl->checkState());
    Core::instance()->setConfig("VoxForge/EnableUploading",ui->checkBoxVoxForge->checkState());
}

}}