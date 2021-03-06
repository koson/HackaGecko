/******************************************************************************
 * @file portlistener.h
 * @brief 
 * @author Energy Micro AS
* @version 1.04
 *******************************************************************************
 * @section License
 * <b>(C) Copyright 2012 Energy Micro AS, http://www.energymicro.com</b>
 *******************************************************************************
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented; you must not
 *    claim that you wrote the original software.
 * 2. Altered source versions must be plainly marked as such, and must not be
 *    misrepresented as being the original software.
 * 3. This notice may not be removed or altered from any source distribution.
 *
 * DISCLAIMER OF WARRANTY/LIMITATION OF REMEDIES: Energy Micro AS has no
 * obligation to support this Software. Energy Micro AS is providing the
 * Software "AS IS", with no express or implied warranties of any kind,
 * including, but not limited to, any implied warranties of merchantability
 * or fitness for any particular purpose or warranties against infringement
 * of any proprietary rights of a third party.
 *
 * Energy Micro AS will not be liable for any consequential, incidental, or
 * special damages, or any other relief, or for any claim by any third party,
 * arising from your use of this Software.
 *
 ******************************************************************************/

#ifndef PORTLISTENER_H_
#define PORTLISTENER_H_

#include <QObject>
#include <QPoint>
#include "qextserialport.h"
#include "datafilter.h"

class PortListener : public QObject
{
Q_OBJECT
public:
    PortListener(const QString & portName);

signals:
    void newPoint(const QPointF &);

private:
    QextSerialPort *port;
    double byteCount;
    DataFilter *m_filter;

private slots:
    void onReadyRead();
    void onDsrChanged(bool status);

};


#endif /*PORTLISTENER_H_*/
