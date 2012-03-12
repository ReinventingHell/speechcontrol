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
#ifndef TRAININGSETTINGSPANE_HPP
#define TRAININGSETTINGSPANE_HPP

#include <QFrame>
#include <windows/settings-dialog.hpp>

namespace Ui
{
class TrainingSettingsPane;
}

namespace SpeechControl
{
namespace Windows
{

class TrainingSettingsPane : public AbstractSettingsPane
{
    Q_OBJECT

public:
    explicit TrainingSettingsPane ();
    ~TrainingSettingsPane();
    QString title() const;
    QString id() const;
    virtual bool containsText (const QString& p_query) const;
    virtual QPixmap pixmap() const;
    virtual void resetPanel();
    virtual void restoreDefaults();
    virtual void updateUi();

protected:
    void changeEvent (QEvent* e);

private:
    Ui::TrainingSettingsPane* ui;
};

}
}

#endif // TRAININGSETTINGSPANE_HPP
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
