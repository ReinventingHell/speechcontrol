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

#ifndef CONTENTWIZARD_SOURCE_WIKI_HPP
#define CONTENTWIZARD_SOURCE_WIKI_HPP

#include <QWidget>

namespace Ui
{
class WikiContentSourceWidget;
}

namespace SpeechControl
{
class WikiContentSourceWidget : public QWidget
{
    Q_OBJECT
    void updateView();

public:
    explicit WikiContentSourceWidget (QWidget* parent = 0);
    ~WikiContentSourceWidget();

private slots:
    void on_btnFetchPortals_checked();

private:
    Ui::WikiContentSourceWidget* m_ui;
};

}

#endif // CONTENTWIZARD_SOURCE_WIKI_HPP
// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
