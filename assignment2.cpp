#include <iostream>
#include <vector>

using namespace std;

struct SuctionCup
{
	float diameter;
	float position;
	float suctionForce;
};

struct Tentacle
{
	float baseDiameter;
	float endDiameter;
	float length;
	float flexibility;
	float maxForce;
	vector<SuctionCup*> cups;
};

struct Head
{
	float diameter;
	float weight;
};

enum Gender
{
	MALE,
	FEMALE
};

struct Octopus
{
	vector<Tentacle*> tentacles;
	struct Head head;
	Gender gender;
	string name;
};

Octopus* createNewOctopus()
{
	Octopus *oct = new Octopus();
	
	oct->head.diameter = 0.5f;
	oct->head.weight = 0.5f;
	oct->gender = FEMALE;
	oct->name = "Food seeker";
	
	for (int i=0; i<8; i++)
	{
		Tentacle *tent = new Tentacle();
		tent->baseDiameter = 0.1;
		tent->endDiameter = 0.01;
		tent->length = 1;
		tent->flexibility = 0.5;
		tent->maxForce = 5;
		
		for (int j=0; j<20; j++)
		{
			SuctionCup *cup = new SuctionCup();
			cup->diameter = 0.03;
			cup->position = j * tent->length / 20;
			cup->suctionForce = 10;
			tent->cups.push_back(cup);
		}
		
		oct->tentacles.push_back(tent);
	}
	
	return oct;
}


int main()
{
	struct Octopus *oct = createNewOctopus();

	// print the octopus
	cout<<"Octopus: "<<oct->name<<endl;
	cout<<"---------------------\n";
	cout<<"Gender: ";
	if (oct->gender == FEMALE) {
		cout<<"Female\n";
	}
	else {
		cout<<"Male\n";
	}

	cout<<"Head: diameter="<<oct->head.diameter<<"m, weight="<<
		oct->head.weight<<"kg\n";
	
	// dump all tentacles
	cout<<"Tentacles:\n";
	for (int i=0; i<oct->tentacles.size(); i++)
	{
		Tentacle *tent = oct->tentacles[i];
		cout<<"  "<<i<<") baseDiameter="<<tent->baseDiameter<<
			"m, endDiameter="<<tent->endDiameter<<"m, length="<<
			tent->length<<"m, flexibility="<<tent->flexibility<<
			", maxForce="<<tent->maxForce<<"kg/m\n";
			
		// dump all suction cups
		cout<<"     Suction cups:\n";
		for (int j=0; j<tent->cups.size(); j++)
		{
			SuctionCup *cup = tent->cups[j];
			cout<<"     "<<j<<") diameter="<<cup->diameter<<"m, position="<<
				cup->position<<"m, suctionForce="<<cup->suctionForce<<"kg/m\n";
		}
	}
	
	// clear out memory
	for (int i=0; i<oct->tentacles.size(); i++)
	{
		Tentacle *tent = oct->tentacles[i];
		for (int j=0; j<tent->cups.size(); j++)
		{
			SuctionCup *cup = tent->cups[j];
			delete cup;
		}
		tent->cups.clear();
		delete tent;
	}
	oct->tentacles.clear();
	
	return 0;	
}
