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

namespace SpeechControl
{

class GenericSource;
class StreamAudioSource;
struct GenericSinkPrivate;
struct StreamSinkPrivate;

struct GenericSinkPrivate {
    explicit GenericSinkPrivate() : m_src (0) { }
    virtual ~GenericSinkPrivate() {

    }
    GenericSource* m_src;
};

struct StreamSinkPrivate : public GenericSinkPrivate {
    explicit StreamSinkPrivate() : GenericSinkPrivate(), m_audioSrc (0) { }
    virtual ~StreamSinkPrivate() {

    }
    StreamAudioSource* m_audioSrc;
};
}
// kate: indent-mode cstyle; replace-tabs on; 
