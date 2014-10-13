#include <iostream>

using namespace std;

enum Direction {
	North,
	East,
	South,
	West,
};

class MapSite {
public:
	virtual void Enter() = 0;
};

class Room : public MapSite {
public:
	Room(int roomNo):mRoomNumber(roomNo) { }
	MapSite *GetSide(Dirction) const;
	
	virtual void SetSide(Direction direction, MapSite *) {
		cout << "Set the " << mRoomNumber << "room " 
				<< direction << " side." << endl;
	}

	int GetRoomNo() {
		return mRoomNumber;
	}

	virtual void Enter() {
		cout << "Enter the Room." << endl;
	}

private:
	MapSite *mSides[4];
	int mRoomNumber;
};

class Wall : public MapSite {
public:
	Wall() {}
	virtual void Enter() {
		cout << "Enter the wall." << endl;
	} 
};

class Door : public MapSite {
public:
	Door(Room * = 0, Room
};
