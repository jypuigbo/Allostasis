#include <string>
#include <iostream>
#include <iomanip>
#include <yarp/os/all.h>
#include <yarp/sig/all.h>
#include <yarp/math/SVD.h>
#include <map>
#include <vector>


using namespace std;
using namespace yarp::os;
using namespace yarp::sig;
using namespace yarp::math;


#include "homeostasisManager.h"






class homeostaticModule: public RFModule
{
private:

    std::string moduleName;
    double period;

    //vector< yarp::os::BufferedPort<yarp::os::Bottle> *> output_ports;
    //vector< yarp::os::BufferedPort<yarp::os::Bottle> *> input_ports;
    vector< yarp::os::BufferedPort<Bottle>* > input_ports;
    vector< yarp::os::BufferedPort<Bottle>* > outputM_ports;
    vector< yarp::os::BufferedPort<Bottle>* > outputm_ports;
    homeostasisManager manager = homeostasisManager(0);

	//Reflexes

    Port    rpc;

    bool addNewDrive(string driveName, yarp::os::Bottle* grpHomeostatic, int d);
    //bool addNewDrive(string driveName, yarp::os::Value grpHomeostatic, int d);
	//void configureTactile(yarp::os::ResourceFinder &rf);
	//void configureSalutation(yarp::os::ResourceFinder &rf);

public:

    Drive bDrive(yarp::os::Bottle* b)
    {
        Drive d = Drive(b->get(0).asString(),b->get(1).asDouble(),b->get(2).asDouble(),b->get(3).asDouble(),b->get(4).asDouble(),b->get(5).asBool());
        return d;
    }

    bool openPorts(string driveName, int d);

    bool configure(yarp::os::ResourceFinder &rf);

    bool interruptModule()
    {
        return true;
    }

    bool close();

    double getPeriod()
    {
        return period;
    }
    bool updateModule();

	bool updateAllostatic();

	//RPC & scenarios
	bool respond(const Bottle& cmd, Bottle& reply);
};
