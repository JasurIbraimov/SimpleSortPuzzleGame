#include <iostream>
#include <string>

using namespace std; 


class Vial {
private:
	char contents[4];
	int filled;
	int label; 

public: 
	Vial() {
		for (int i = 0; i < 4; i++) {
			contents[i] = ' ';
		}
		filled = 0;
		label = 0; 
	}
	Vial(char* contents, int size, int filled) {
		for (int i = 0; i < size; i++) {
			this->contents[i] = contents[i];
		}
		this->filled = filled;
		this->label = 0;
	}
	Vial(char c1, char c2, char c3, char c4, int filled) {
		contents[0] = c1;
		contents[1] = c2;
		contents[2] = c3;
		contents[3] = c4;
		this->filled = filled;
		this->label = 0;
	}
	bool add(char content) {
		if (filled < 4) {
			contents[filled] = content;
			filled++;
			return true;
		}
		return false;
	}
	void display() {
		cout << label << " [";
		for (int i = 0; i < filled; i++) {
			cout << contents[i] << " ";
		}
		cout << "]" << endl;
	}
	bool isComplete() {
		char firstChar = contents[0];
		for (int i = 1; i < filled; i++) {
			if (contents[i] != firstChar) {
				return false; // Found a different character, vial is not complete
			}
		}
		return true; // All characters are the same, vial is complete
	}
	void setLabel(int label) {
		this->label = label;
	}
	bool transfer(Vial& destination) {
		if (filled == 0) {
			cout << "Source vial is empty." << endl;
			return false;
		}

		if (destination.filled == 4) {
			cout << "Destination vial is already filled." << endl;
			return false;
		}

		if (destination.filled > 0 && contents[filled - 1] != destination.contents[destination.filled - 1]) {
			cout << "Contents do not match." << endl;
			return false;
		}

		int numItemsToTransfer = 0;
		for (int i = filled - 1; i >= 0; i--) {
			if (contents[i] != contents[filled - 1]) {
				break;
			}
			numItemsToTransfer++;
		}

		if (destination.filled + numItemsToTransfer > 4) {
			numItemsToTransfer = 4 - destination.filled;
		}

		for (int i = 0; i < numItemsToTransfer; i++) {
			destination.contents[destination.filled] = contents[filled - 1];
			destination.filled++;
		}

		for (int i = filled - 1; i >= filled - numItemsToTransfer; i--) {
			contents[i] = ' ';
		}

		filled -= numItemsToTransfer;
		return true;
	}
	char* getContents() {
		return contents;
	}
	int getFilled() {
		return filled;
	}

	int getLabel() {
		return label;
	}
};
void displayVials(Vial* vials, int numOfVials) {
	for (int i = 0; i < numOfVials; i++) {
		vials[i].display();
	}
}

bool isGameComplete(Vial* vials, int numOfVials) {
	for (int i = 0; i < numOfVials; i++) {
		if (!vials[i].isComplete()) {
			return false;
		}
	}
	return true; 
}

int main() {
	cout << "Simple Sort Puzzle" << endl;
	const int numOfVials = 6;
	srand(time(0));
	Vial vials[numOfVials];
	for (int i = 0; i < numOfVials; i++) {
		vials[i].setLabel(i + 1);
	}
	
	char contents[] = { 'a', 'b', 'c', 'd' };

	for (int i = 0; i < 4; i++) {
		for (char item : contents) {
			int vialIndex;
			do {
				vialIndex = std::rand() % 4;
			} while (vials[vialIndex].getFilled() > i);
			vials[vialIndex].add(item);
		}
	}
	

	displayVials(vials, numOfVials);
	int movesCount = 0;
	string placeholder = ", ";
	// Game loop
	while (!isGameComplete(vials, numOfVials)) {
		movesCount++;
		cout << "Move: " << movesCount << endl;
		int sourceVialIndex, destinationVialIndex;

		// Allow the player to set the source vial and the destination vial
		cout << "Source, Destination: ";
		cin >> sourceVialIndex >> placeholder >> destinationVialIndex;
		sourceVialIndex--;
		destinationVialIndex--;

		if (sourceVialIndex < 0 || sourceVialIndex >= numOfVials || destinationVialIndex < 0 || destinationVialIndex >= numOfVials) {
			cout << "You typed wrong index" << endl;
			continue;
		}

		bool transferSuccess = vials[sourceVialIndex].transfer(vials[destinationVialIndex]);
		if (!transferSuccess) {
			cout << "You cannot make this move..." << endl;
		}

		displayVials(vials, numOfVials);
	}

	cout << "Congratulations! You solved this puzzle!";

}