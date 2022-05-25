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
package calitest.sources;


import org.mixim.base.modules.*;
import org.mixim.modules.nic.Nic80211p;
import org.mixim.base.modules.IBaseApplLayer;
import org.mixim.base.modules.IMobility;

module Car
{
    parameters:
        string applType; //type of the application layer
        string mobilityType; //type of the mobility module       
        @display("bgb=237,280");
    gates:
        input radioIn; // gate for sendDirect
    submodules:
        appl: <applType> like IBaseApplLayer {
            parameters:
                @display("p=60,50;i=block/app2");
        }

        arp: BaseArp {
            parameters:
                @display("p=155,124");
        }

        nic: Nic80211p {
            parameters:
                @display("p=60,200");
        }

        mobility: <mobilityType> like IMobility {
            parameters:
                @display("p=155,200;i=block/cogwheel");
        }

        routing: DrgLayer {
            parameters:
                @display("p=60,124;i=block/cogwheel");
        }
    connections:
        nic.upperLayerOut --> routing.lowerLayerIn;
        nic.upperLayerIn <-- routing.lowerLayerOut;
        nic.upperControlOut --> routing.lowerControlIn;
        nic.upperControlIn <-- routing.lowerControlOut;

        routing.upperLayerOut --> appl.lowerLayerIn;
        routing.upperLayerIn <-- appl.lowerLayerOut;
        routing.upperControlOut --> appl.lowerControlIn;
        routing.upperControlIn <-- appl.lowerControlOut;

        radioIn --> nic.radioIn;

}
