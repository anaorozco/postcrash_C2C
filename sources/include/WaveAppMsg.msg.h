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

//
// TODO generated message class
//

cplusplus {{
#include <Coord.h>
}}

class noncobject Coord;

packet WaveAppMsg {

	string wamData = "";
	
	int applicationType = 0; // Wave Appplication type 0 = undefined
	
	simtime_t timestamp = 0;
	
	//int senderAddress = 0;
	//int recipientAddress = -1;
	//int serial = 0;
	//Coord senderPos;
	
	
}
