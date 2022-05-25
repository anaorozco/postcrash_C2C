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
import org.mixim.base.modules.BaseNetwLayer;

simple DrgLayer extends BaseNetwLayer{
	parameters:
	    @class(DrgLayer);
	    
	    @signal[geocastAlgorithm](type="double");
	    @statistic[algorithm](title="Protocol distance calculation"; source="algorithm"; record=vector; interpolationmode=none);
	    
	    @signal[geocastPacketRx](type="bool");
	    @statistic[geocastPacketRx](title="geocastPacketRx"; source="geocastPacketRx"; record=vector; interpolationmode=none);
	    
	    @signal[timeAccidentReceived](type="double");
	    @statistic[timeAccidentReceived](title="timeAccidentReceived"; source="timeAccidentReceived"; record=vector; interpolationmode=none);
	    
	    @signal[timeAccidentAnnounced](type="double");
	    @statistic[timeAccidentAnnounced](title="timeAccidentAnnounced"; source="timeAccidentAnnounced"; record=vector; interpolationmode=none);
	    
	    @signal[distanceToAccident](type="double");
	    @statistic[distanceToAccident](title="distanceToAccident"; source="distanceToAccident"; record=vector; interpolationmode=none);
	    
	    @signal[numberPacketSent](type="int");
	    @statistic[numberPacketSent](title="numberPacketSent"; source="numberPacketSent"; record=vector; interpolationmode=none);
	    
	    @signal[numberPacketReceived](type="int");
	    @statistic[numberPacketReceived](title="numberPacketReceived"; source="numberPacketReceived"; record=vector; interpolationmode=none);
	    
	    @signal[currentDist](type="double");
	    @statistic[currentDist](title="currentDist"; source="currentDist"; record=vector; interpolationmode=none);
	         
	    double maxOffset = default(0.005);
	    bool sendBeacons = default(false);
	    int beaconLengthBits = default (256);
	    int beaconPriority = default(3);
	    int beaconInterval = default(1);
	    bool sendData = default (true);
	    int dataLengthBits = default(256);
	    bool dataOnSch = default(false);
	    int dataPriority = default(2);
	    
	  }