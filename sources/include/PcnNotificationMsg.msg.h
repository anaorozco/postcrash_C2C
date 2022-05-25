//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

cplusplus {{
#include "PcnMsg_m.h"
#include "Coord.h"
#include <String>

}}

class noncobject Coord;

packet PcnMsg;

//
// TODO generated message class
//
packet PcnNotificationMsg extends PcnMsg {
    Coord coordinates; // Coordinates where an accident occured
    string accidentStatus;  // Field for update accident status, possible values are: accidentOccured and accidentResolved
}
