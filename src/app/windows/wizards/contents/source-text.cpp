/***
 *  This file is part of SpeechControl.
 *
 *  Copyright (C) 2012 SpeechControl Developers <spchcntrl-devel@thesii.org>
 *
 *  SpeechControl is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  SpeechControl is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with SpeechControl .  If not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "source-text.hpp"
#include "app/windows/contents-wizard.hpp"
#include "app/sessions/content.hpp"
#include "ui_contentwizard-source-text.h"

#include <QDebug>
#include <QTextStream>
#include <QDomDocument>
#include <QFileDialog>
#include <QMessageBox>

using SpeechControl::Content;
using SpeechControl::TextContentSource;
using SpeechControl::AbstractContentSource;
using SpeechControl::TextContentSourceWidget;


TextContentSourceWidget::TextContentSourceWidget (QWidget* parent) :
    QWidget (parent),
    m_ui (new Ui::TextContentSourceWidget)
{
    m_ui->setupUi (this);
    this->setLayout(m_ui->gridLayout);
    setProperty ("id", "txt");
    setProperty ("title", "Text-Based");
}

void TextContentSourceWidget::on_btnOpen_clicked()
{
    QString l_path = QFileDialog::getOpenFileName (this, "Select SpeechControl Content",
                     QDir::homePath());

    Q_ASSERT (QFile::exists (l_path) != false);

    m_ui->lineEditPath->setText (l_path);
    updateView();
}

void TextContentSourceWidget::updateView()
{
    TextContentSource* l_src = new TextContentSource;
    l_src->setUrl (QUrl::fromUserInput (m_ui->lineEditPath->text()));
    Content* l_content = l_src->generate();
    Q_ASSERT (l_content != 0);
    m_ui->lblInfo->setText (tr ("<h2>%1</h2>by <b>%2</b>").arg (l_content->title()).arg (l_content->author()));

    ( (SpeechControl::Wizards::ContentWizard*) this->window())->setSource (l_src);
}

TextContentSourceWidget::~TextContentSourceWidget()
{
    delete m_ui;
}

#include "source-text.moc"
// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
