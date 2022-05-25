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

package calitest;

import org.mixim.base.modules.*;
import org.mixim.modules.application.ieee80211p.BaseWaveApplLayer;

simple App_PCN extends BaseWaveApplLayer
{
      parameters:
          @class(App_PCN);
          @signal[accidentSent](type="double");
	      @statistic[accidentSent](title="accidentSent"; source="accidentSent"; record=vector; interpolationmode=none);
	      
	       @signal[numberPacketReceivedAppl](type="int");
         	@statistic[numberPacketReceivedAppl](title="numberPacketReceivedAppl"; source="numberPacketReceivedAppl"; record=vector; interpolationmode=none);
       
          @display("i=block/app2");
          bool pcnAccidentPermit = default(false); // Node which broadcast AccidentMessage
          int accidentMsgTimes = default(3);  // 
          int intervalMsg = default(2); // seconds between message sending
          double appZone = default(800);
}