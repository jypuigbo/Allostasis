#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "homeostasis.h"

using namespace std;



class homeostasisManager
{
private:

	
    
    

public:
	std::vector<Drive*> drives;
	std::vector<string*> drive_names;
	std::vector<double*> drive_values;
	unsigned int n_drives;

	homeostasisManager(int n)
    {
    	drives.resize(n);
    	n_drives = n;
    }
    
	//bool configHomeostatic(n_drives);
	bool addDrive(Drive *D,unsigned int n);
	/*Generates a drive in the homeostasis manager. 
	Homeostasis manager will take care of updating it. 
	Input must be a drive and its position*/
	bool removeDrive(Drive &D,unsigned int n);
	/*Not implemented*/
	bool updateDrives(double t);
	/*Calls the update function for each drive. */
	bool setDriveParameter(int d, int p, double val)
	{
		/*Allows to change any parameter from a drive, except name. 
		Name must be defined on creation. */
		switch (p)
		{
			case 0:
				drives[d]->setValue(val);
				break;			
			case 1:
				drives[d]->setDecay(val);
				break;
			case 2:
				drives[d]->setHomeostasisMin(val);
				break;
			case 3:
				drives[d]->setHomeostasisMax(val);
				break;
			default:
				cout<<"ERROR!! Could not process parameter"<< p << endl;
				cout<< "Parameter options are: " <<endl;
				cout <<"0: Value"<<endl;
				cout <<"1: Decay"<<endl;
				cout << "2: HomeostasisMin"<<endl;
				cout << "3: HomeostasisMax"<<endl;
				cout << endl<<" Please revise the module. "<<endl;
				return false;
				break;

		}
		return true;
	}

	bool deltaDriveParameter(int d, int p, double delta)
	{
		/*Allows to change any parameter from a drive, except name. 
		Name must be defined on creation. */
		switch (p)
		{
			case 0:
				drives[d]->deltaValue(delta);
				break;			
			case 1:
				drives[d]->deltaDecay(delta);
				break;
			case 2:
				drives[d]->deltaHomeostasisMin(delta);
				break;
			case 3:
				drives[d]->deltaHomeostasisMax(delta);
				break;
			default:
				cout<<"ERROR!! Could not process parameter"<< p << endl;
				cout<< "Parameter options are: " <<endl;
				cout <<"0: Value"<<endl;
				cout <<"1: Decay"<<endl;
				cout << "2: HomeostasisMin"<<endl;
				cout << "3: HomeostasisMax"<<endl;
				cout << endl<<" Please revise the module. "<<endl;
				return false;
				break;

		}
		return true;
	}

	vector<double*> getDriveStatus(int n);
	/*Returns a vector with the updated list of values
	of each drive, or a specific one. */

	

};
