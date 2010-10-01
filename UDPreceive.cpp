#include "UDPreceive.hpp"
#include <unistd.h>
#include <sstream>
#include <iomanip>
#include <Common/Helper/iqrUtils.h>

#define DRIVER       "QMYSQL3"  /* see the Qt SQL documentation for a list of available drivers */
//#define DEBUG_MODULEDBACCESS

MAKE_MODULE_DLL_INTERFACE(iqrcommon::UDPreceive,
                          "UDPreceive Module")

iqrcommon::UDPreceive::UDPreceive():ClsThreadModule() {
    tid = 0;

    clsIntParameterPort = addIntParameter("Port", /* _strName */
                                          "Port",  /* _strLabel */
                                          8002, /* _iValue */
                                          1, /* _iMinimum */
                                          100000, /* _iMaximum */
                                          "Port" /* _strDescription */,
                                          "Host" /* _strCategory */);

    output1StateVariable = addOutputToGroup("Val1","Val1");
    output2StateVariable = addOutputToGroup("Val2","Val2");
    output3StateVariable = addOutputToGroup("Val3","Val3");
    output4StateVariable = addOutputToGroup("Val4","Val4");
    output5StateVariable = addOutputToGroup("Val5","Val5");
}

iqrcommon::UDPreceive::~UDPreceive() {
#ifdef DEBUG_MODULEDBACCESS
    cout << "UDPreceive::~UDPreceive()" << endl;
#endif
}

void iqrcommon::UDPreceive::init() {
#ifdef DEBUG_MODULEDBACCESS
    cout << "UDPreceive::init()" << endl;
#endif

    iPort = clsIntParameterPort->getValue();
    cout<<"Get data from PD on port number:"<<iPort<<endl;
    if (iPort <= 0) {
        throw ModuleError(string("Module \"") + label() + "\": Invalid port number");
    }

    iNrCells = output1StateVariable->getStateArray().getWidth();
    cout<<"number of cells "<<iNrCells<<endl;

//---    QSocketDevice::Error error;
    qs = new QUdpSocket (NULL);
//---    error = qs->error();
//CHECK
//qs->setBlocking(false);
    //error = qs->error();

    bool bound = qs->bind(iPort);
    //error = qs->error();
    //cout<<"QHostAddress: "<<QHostAddress()<<endl;
    cout<<"iPort: "<<iPort<<endl;
    cout<<"bound: "<<bound<<endl;

    val1 = val2 = val3 = val4 = val5 = val6 = 0;


}

void iqrcommon::UDPreceive::update() {
//    cerr << "PDreceive::update()" << endl;


#define BUFF_LEN 1024
    char acData[BUFF_LEN];
    bzero(acData, BUFF_LEN);
    //qs->readDatagram ( acData, BUFF_LEN ) ;
    //cout << "read: " << acData << "|" << endl;


    while (qs->hasPendingDatagrams()) {
        QByteArray datagram;
        datagram.resize(qs->pendingDatagramSize());
        qs->readDatagram(datagram.data(), datagram.size());
        //cout << "Received datagram " << datagram.data() << "|" << endl;





        std::stringstream ssResponse;
        ssResponse.str(datagram.data());
        //ssResponse << datagram.data().split();
        //float val1, val2, val3, val4, val5; //= datagram.data().split(" ")[0];
        //float enveloppe; // = datagram.data().split(" ")[1];
        //float onset; // = datagram.data().split(" ")[2];
        char rest;

        //ssResponse>>pitch>>enveloppe>>onset>>rest;
        ssResponse>>val1>>val2>>val3>>val4>>val5>>val6>>rest;


        if (val6 < 20) {
            val1 = val2 = val3 = val4 = val5 = 0;
        } 


        cout<<"val1: "<<val1<<" val2: "<<val2<<" val3: "<<val3<<" val4: "<<val4<<" val5: "<<val5<<" enable: " << val6<< endl;


    }

    qmutexThread->lock();

    StateArray &clsStateArrayOut1 = output1StateVariable->getStateArray();
    StateArray &clsStateArrayOut2 = output2StateVariable->getStateArray();
    StateArray &clsStateArrayOut3 = output3StateVariable->getStateArray();
    StateArray &clsStateArrayOut4 = output4StateVariable->getStateArray();
    StateArray &clsStateArrayOut5 = output5StateVariable->getStateArray();



//    stateArrayOut[0] = 0;

    //cout << pitch << " " << enveloppe << " " << onset << endl;

    for (unsigned int ii=0;ii<clsStateArrayOut1.getWidth();ii++) {
        clsStateArrayOut1[0][ii]=val1;
    }
    for (unsigned int ii=0;ii<clsStateArrayOut2.getWidth();ii++) {
        clsStateArrayOut2[0][ii]=val2;
    }
    for (unsigned int ii=0;ii<clsStateArrayOut3.getWidth();ii++) {
        clsStateArrayOut3[0][ii]=val3;
    }

    for (unsigned int ii=0;ii<clsStateArrayOut4.getWidth();ii++) {
        clsStateArrayOut4[0][ii]=val4;
    }

    for (unsigned int ii=0;ii<clsStateArrayOut5.getWidth();ii++) {
        clsStateArrayOut5[0][ii]=val5;
    }



    /* bool bLoop = true;
    while(bLoop) {
        if(iIndex<iNrCells){
        stateArrayOut[0][iIndex ] = 1.0;
    }

    if(ssResponse.peek()<=0){
        bLoop = false;
    }
    }*/

    qmutexThread->unlock();
    usleep(500);
}

void iqrcommon::UDPreceive::cleanup() {
    qs->close();
}
