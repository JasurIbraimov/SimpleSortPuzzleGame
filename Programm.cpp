#include <iostream>
#include <string>

using namespace std; 


class Vial {
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
		cout << "+------------------+" << endl;
		cout << "|      Vial " << label << "      |" << endl;
		cout << "+------------------+" << endl;
		cout << "| ";
		for (int i = 0; i < filled; i++) {
			cout << contents[i] << " ";
		}
		for (int i = filled; i < 4; i++) {
			cout << "  ";
		}
		cout << "|" << endl;
		cout << "+------------------+" << endl;
	}
	bool isComplete() {
		if (filled == 0) {
			return false; // Vial is empty, not complete
		}
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

		if (contents[filled - 1] != destination.contents[destination.filled - 1]) {
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
};

int main() {

	// Game loop
	while (true) {
	}

}