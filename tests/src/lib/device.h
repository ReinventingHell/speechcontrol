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

#ifndef TEST_LIB_DEVICE_HPP
#define TEST_LIB_DEVICE_HPP
#include <QObject>

namespace SpeechControl
{
class AbstractAudioSource;
}

class TestDevice : public QObject
{
    Q_OBJECT

private slots:
    void init();
    void cleanup();
    void defaultDevice();
    void listDevices();
    void adjustVolume();
    void toggleMuteState();
};

#endif
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
