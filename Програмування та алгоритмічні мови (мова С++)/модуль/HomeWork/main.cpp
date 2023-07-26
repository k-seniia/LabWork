#include "Sphere.h"

#define DEBUG

void generateData(const string& filename, int count);

int main() {
	srand(time(nullptr));

	try {
#ifdef DEBUG
		Sphere sphere(rand() % 100 / 10., Point3D(rand() % 100 / 10., rand() % 100 / 10., rand() % 100 / 10.));
#else
		Sphere sphere;
		cout << "\nEnter the sphere: -> \n";
		cin >> sphere;
#endif // DEBUG
		cout << sphere << endl;

#ifdef DEBUG
		Point3D point(rand() % 100 / 10., rand() % 100 / 10., rand() % 100 / 10.);
#else
		Point3D point;
		cout << "\nEnter the point: -> \n";
		cin >> point;
#endif // DEBUG
		cout << "Point: " << point << endl;

		string position = sphere.determinePosition(point);
		cout << "\nPosition of the point relative to the sphere: " << position << endl;


		int increaseValue{};
#ifdef DEBUG
		increaseValue = rand() % 10;
#else
		cout << "\nEnter the increase value -> ";
		cin >> increaseValue;
#endif // DEBUG
		sphere* increaseValue;
		cout << "\nIncreased radius by " << increaseValue << ". New radius: " << sphere.getRadius() << endl;

		int decreaseValue{};
#ifdef DEBUG
		decreaseValue = rand() % 10;
#else
		cout << "\nEnter the decrease value -> ";
		cin >> decreaseValue;
#endif // DEBUG
		sphere / decreaseValue;
		cout << "\nDecreased radius by " << decreaseValue << ". New radius: " << sphere.getRadius() << endl;

#ifdef DEBUG
		string filename = "data.txt";
#else
		string filename;
		cout << "\nSave the sphere data to a file -> ";
		cin >> filename;
#endif // DEBUG
		sphere.saveToFile(filename);
		cout << "\nSaved sphere data to file: " << filename << endl;

		Sphere loadedSphere;
		if (loadedSphere.loadFromFile(filename)) {
			cout << "\nLoaded sphere data from file: " << endl;
			cout << loadedSphere;
		}
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}

	try {
		int dataCount{};
#ifdef DEBUG
		dataCount = rand() % 10 + 1;
#else
		cout << " -> "; // TODO
		cin >> dataCount;
#endif // DEBUG
		string generatedDataFile = "generated_data.txt";
		generateData(generatedDataFile, dataCount);
		cout << "\nGenerated " << dataCount << " random sphere data entries in file: " << generatedDataFile << endl;
	}
	catch (const exception& e) {
		cerr << "Error: " << e.what() << endl;
	}

	return 0;
}

void generateData(const string& filename, int count) {
	ofstream fout(filename);
	if (!fout) {
		cerr << "Error: Unable to open file " << filename << endl;
		return;
	}

	for (int i = 0; i < count; ++i) {
		double x = rand() % 100 / 10.;
		double y = rand() % 100 / 10.;
		double z = rand() % 100 / 10.;

		Point3D center(x, y, z);
		double radius = rand() % 100 / 10.;

		fout << radius << center << endl;
	}

	fout.close();
}