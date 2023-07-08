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
};