/*
 * This file is part of SpeechControl.
 *
 * Copyright 2012 Jacky ALcine <jacky.alcine@thesii.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Library General Public License as
 * published by the Free Software Foundation; either version 2 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef SPEECHCONTROL_DAEMON_INSTANCE_HPP
#define SPEECHCONTROL_DAEMON_INSTANCE_HPP

#include <QObject>
#include <QDBusConnection>

namespace SpeechControl {

 class AbstractListener;
 namespace Daemon {
  class Instance : public QObject
  {
   Q_OBJECT
  public:
   Instance();
   virtual ~Instance();
   
  public slots:
   void startListening();
   void stopListening();
   QList<QString> listenerNames() const;
   bool isListening() const;
   
  signals:
   void startedListening();
   void stoppedListening();
   
  private:
   void initializeDbus();
   QList<AbstractListener*> listeners;
   QDBusConnection bus;
  };

 }
}

#endif // SPEECHCONTROL_DAEMON_INSTANCE_HPP
// kate: indent-mode cstyle; indent-width 1; replace-tabs on; 
