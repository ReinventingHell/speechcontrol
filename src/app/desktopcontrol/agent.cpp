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

#include "core.hpp"
#include "agent.hpp"
#include "command.hpp"

namespace SpeechControl {
namespace DesktopControl {

Agent* Agent::s_instance = 0;

Agent::Agent() : AbstractAgent ( AbstractCategory::global() ) {
    _asr = new DesktopASR ( DesktopASR::standardDescription(), parent() );
    connect ( _asr, SIGNAL ( finished ( QString ) ), this, SLOT ( invokeCommand ( QString ) ) );
}

Agent* Agent::instance() {
    if ( s_instance == 0 ) {
        s_instance = new Agent;
    }

    return s_instance;
}

AbstractAgent::OperationState Agent::onStateChanged ( const AbstractAgent::OperationState p_state ) {
    switch ( p_state ) {
    case Enabled: {
        if (!isEnabled())
            return Disabled;

        if ( !_asr->start() ) {
            qWarning() << "[DesktopControl::Agent] Start unsuccessful.";
            return Disabled;
        }

    }
    return Enabled;
    break;

    case Disabled:
        _asr->stop();
        return Disabled;
        break;

    case Undefined:
    default:
        break;
    }

    return Undefined;
}

bool Agent::isActive() const {
    return _asr->isRunning();
}

bool Agent::isEnabled() {
    return Core::configuration("DesktopControl/Enabled").toBool();
}

/// @todo Since this returns more than one command, should we provide a UI that allows you to pick which command you might want?
void Agent::invokeCommand ( const QString& p_cmd ) {
    AbstractCategory* l_glbl = AbstractCategory::global();
    CommandList l_cmds = l_glbl->matchAllCommands ( p_cmd );

    Q_FOREACH ( AbstractCommand* l_cmd, l_cmds ) {
        qDebug() << l_cmd->id() << l_cmd->statements();
    }
}

Agent::~Agent() {

}

}
}
#include "../desktopcontrol/agent.moc"
// kate: indent-mode cstyle; indent-width 4; replace-tabs on;
