/***
 *  This file is part of SpeechControl.
 *
 *  Copyright (C) 2012 SpeechControl Developers <spchcntrl-devel@thesii.org>
 *            (C) 2012 Jacky Alcine <jacky.alcine@thesii.org>
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


#define TEST_SUITE

#include <cstdlib>
#include <iostream>

// libcpptest includes
#include <cpptest-textoutput.h>

// local includes
#include "include/base.hpp"

using namespace SpeechControl;

int main ( int argc, char** argv ) {
    Test::TextOutput l_output ( Test::TextOutput::Verbose );
    return TestModule::instance()->run ( l_output ) ? EXIT_SUCCESS : EXIT_FAILURE;
}
// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 