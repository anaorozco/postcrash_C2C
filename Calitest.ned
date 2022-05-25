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

import org.mixim.base.connectionManager.ConnectionManager;
import org.mixim.base.modules.BaseWorldUtility;
import org.mixim.modules.obstacle.ObstacleControl;
import org.mixim.modules.mobility.traci.TraCIScenarioManagerLaunchd;

network Calitest
{
    parameters:
        double playgroundSizeX @unit(m); // x size of the area the nodes are in (in meters)
        double playgroundSizeY @unit(m); // y size of the area the nodes are in (in meters)
        double playgroundSizeZ @unit(m); // z size of the area the nodes are in (in meters)

        //@display("bgb=602,408,white;bgp=0,0");
        @display("bgb=468,104,white");
    submodules:
        connectionManager: ConnectionManager {
            parameters:
                @display("p=150,0;b=42,42,rect,green,,;i=abstract/multicast");
        }
        world: BaseWorldUtility {
            parameters:
                playgroundSizeX = playgroundSizeX;
                playgroundSizeY = playgroundSizeY;
                playgroundSizeZ = playgroundSizeZ;
                @display("p=30,0;i=misc/globe");
        }
        obstacles: ObstacleControl {
            @display("p=357,14");
        }
        manager: TraCIScenarioManagerLaunchd {
            parameters:
                @display("p=266,14");
        }

    connections allowunconnected:

}
