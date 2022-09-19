#include "aggreg.h"
#include "fstream.h"

void main(void)
{
	fstream output;
	output.open("output.txt", ios::out);
/*
Generator Gen(100.0, 0.3, 40);      // Generator is to aggregate traffic 
// from 40 sources and to generate 
// the load of 0.3 on a link with 
// rate 100 Mbps (that is average 
// throughput of 30 Mbps)

  Gen.OutputTraces( 1000000 );        // generate one million packets 
  // and output them to STDOUT
*/
	
	
	DOUBLE load  = 0.6;                 // desired load
    DOUBLE delta = 0.01;                // acceptable difference between the 
	// requested and obtained load
	
    int32u max_packets = 1000;    // generate no more than 100 mln. packets
	
    Generator Gen(100.0, load, 32);     // Generator is to aggregate traffic 
	// from 32 sources and to generate 
	// the load of XYZ on a link with 
	// rate 100 Mbps 
	
    //while( Gen.GetPackets() < max_packets && fabs( Gen.GetLoad() - load) > delta )
	Trace trace;

	while( Gen.GetPackets() < max_packets)
	{
		trace = Gen.GenerateTrace();

		cout << trace << endl; 
		output<< trace << endl; 
        
	}

	output.close();
	
}
