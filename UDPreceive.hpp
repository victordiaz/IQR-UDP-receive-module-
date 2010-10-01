#ifndef PDreceive_HPP
#define PDreceive_HPP

#include <sys/ioctl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <termios.h>
#include <unistd.h> 
#include <sys/time.h>
#include <bitset>
#include <vector>

#include<QtNetwork/QUdpSocket>
#include<QtNetwork/QHostAddress>


#include <Common/Item/threadModule.hpp>

using namespace std;

namespace iqrcommon {

    class UDPreceive : public ClsThreadModule {
    public:
	UDPreceive();
	~UDPreceive();

	void init();
	void update();
	void cleanup();
	
    private:
	ClsStringParameter* clsStringParameterHostName;
	ClsIntParameter* clsIntParameterPort;
	ClsStateVariable* output1StateVariable;
	ClsStateVariable* output2StateVariable; 
	ClsStateVariable* output3StateVariable; 
	ClsStateVariable* output4StateVariable; 
	ClsStateVariable* output5StateVariable;

	int iPort;
	int iNrCells; 

	float val1, val2, val3, val4, val5, val6; 

	QUdpSocket* qs;

    };
}
#endif
