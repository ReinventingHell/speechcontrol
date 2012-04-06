/***
 *  This file is part of SpeechControl.
 *
 *  Copyright (C) 2012 Jacky Alciné <jackyalcine@gmail.com>
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
 *  along with SpeechControl.  If not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include "service.hpp"
#include "app/services/module.hxx"
#include "app/services/dictation/sphinx.hpp"

namespace SpeechControl
{
namespace Dictation
{

class Service;
class ServicePrivate : public Services::AbstractModulePrivate
{
friend class Service;
private:
    Service::SafetyMode m_safetyMode;
    Sphinx* m_sphinx;
    ServicePrivate (Service* p_qPtr);
    virtual ~ServicePrivate();
    void setSafetyMode(const Service::SafetyMode& p_mode);
    Service::SafetyMode safetyMode() const;
    virtual AbstractModule::ActivityState handleStateChange (const AbstractModule::ActivityState& p_stt);
};
}
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on;