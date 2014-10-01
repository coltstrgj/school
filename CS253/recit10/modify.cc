#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
/*	if (argc != 3) {
		cerr << "usage: " << argv[0] << " infile outfile\n";
		return 1;
	}*/
    fstream in(argv[1], ios_base::in | ios_base::out);
	if (!in) {
		cerr << argv[0] << ": can't open " << argv[1] << endl;
		return 1;
	}
	ofstream out(argv[2]);
	if (!out) {
		cerr << argv[0] << ": can't open " << argv[2] << endl;
		return 1;
	}

	string s;
	while (getline(in, s)) {
		size_t n;
		while ( (n=s.find("Bush")) != string::npos )
			s.replace(n, 4, "Gore");
		in.seekp(p, std::ios_base::beg);
        in.write((s+'\n').c_str(), s.length()+1);
        p+= s.length() + 1;

	}

	return 0;
}
