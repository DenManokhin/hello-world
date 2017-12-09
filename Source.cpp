#include <iostream>
#include <string>
using namespace std;

int main() {
	string str = "NSWE";
	bool t = true;
	string GPSDATA;
	cin >> GPSDATA;
	int l = GPSDATA.length();
	int *x, *y;
	x = new int[l];
	y = new int[l];
	for (int i = 0; i < l; i++) {
		x[i] = y[i] = 0;
	}
	for (int i = 1; i < l+1; i++) {
		x[i] = x[i-1];
		y[i] = y[i-1];
		if (GPSDATA[i-1] == str[0]) y[i] = y[i] + 1;
		if (GPSDATA[i-1] == str[1]) y[i] = y[i] - 1;
		if (GPSDATA[i-1] == str[2]) x[i] = x[i] - 1;
		if (GPSDATA[i-1] == str[3]) x[i] = x[i] + 1;
		for (int j = 0; j < i; j++) {
			if ((x[i]==x[j])&&(y[i]==y[j])) {
				t = false; break;
			}
		}
		if (t == false);
	}
	if (t) cout << "Looks OK." << endl;
	else cout << "Something goes wrong..." << endl;
	return 0;
}