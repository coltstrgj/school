#include <iostream>
#include <string>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
//#include <dirent.h>
#include <glob.h>
#include <vector>
#include <sys/stat.h>

using namespace std;
void globDir(string &pat, glob_t &gres){
        glob(pat.c_str(),GLOB_ONLYDIR|GLOB_MARK,NULL,&gres);
}

void globPat(string &pat, glob_t &gres){
        glob(pat.c_str(),GLOB_MARK,NULL,&gres);
}
void globAll(string &pat, glob_t &gres){
        glob(pat.c_str(),GLOB_MARK|GLOB_PERIOD,NULL,&gres);
}



vector<string> globFiles(bool all = false, bool dir = false, string pattern = "*"){
	vector<string> files;	
	glob_t glob_result;	
	
	if(all){
		globAll(pattern, glob_result);
	}else if(dir){
		globDir(pattern, glob_result);
	}else{
		globPat(pattern, glob_result);
	}
	//the following copies the stuff from the glob vector
	for(unsigned int i=0; i<glob_result.gl_pathc;i++){
		string sub = glob_result.gl_pathv[i];
		sub=sub.substr(sub.length()-2);
		if(sub.compare("./")!=0)//remove the dot and dot dot
			files.push_back(string(glob_result.gl_pathv[i]));
	}
	return files;
}

vector<string> globRecurs(vector<string> &dirs, string path, string pattern){
	vector<string> tmp = globFiles(0, 1,path+pattern);//get only the directories
	//vector<string> dirs;//dirs store all of the directories
	dirs.insert(dirs.end(),tmp.begin(), tmp.end()); //appends the tmp to the end of this array (for recursion) and to avoid data clobber
	

	//for loop will go into each subdir and then acts as its own base case cus dirs will be empety if there are no subs
	for(unsigned int i=0; i<tmp.size(); i++){
		//cout<<tmp[i]<<endl;
		globRecurs(dirs, tmp[i],pattern);
	}
	return tmp;
}

void rmNonFiles(vector<string> &globAll){
	vector<string> tmp;
	for(unsigned int i=0; i<globAll.size(); i++){
		if(!globAll[i].substr(globAll[i].length()-1).compare("/")==0)//if it ends with / it is a directory
			tmp.push_back(globAll[i]);
			//globAll.erase(globAll.begin()+i);
	}
	globAll=tmp;
}
int getAge(string fPath){
	int days;
	//stop clobbering my time struct
	time_t rawtime;
	struct tm *timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	days=timeinfo->tm_yday+(timeinfo->tm_year*365);//this is the num of days since 1990
	
	struct stat attrib;			// create a file attribute structure
        stat(fPath.c_str(), &attrib);		// get the attributes of afile.txt
	timeinfo = gmtime(&(attrib.st_mtime));	// number of days between 1990 and file creation
	days=days - (timeinfo->tm_yday+(timeinfo->tm_year*365));//get the age in days since 1990 or something... doesnt matter. Compare to time since same start date
	
	return days;
}

void rmOld(vector<string> &globAll, int age){
	vector<string> tmp; //some things arent removed correctly
	for(unsigned int i=0; i<globAll.size(); i++){
		if(!(getAge(globAll[i])>age))
			tmp.push_back(globAll[i]);
			//globAll.erase(globAll.begin()+i);//dont forget rm !
	}
	globAll=tmp;
}

void globThem (vector<string> &globAll, string path, bool allFlg, bool fileFlg, bool dirFlg, string pattern, bool ageR = false, int age =0){
	vector<string> directories;
	directories.push_back(path);
	globRecurs(directories, path,"*");	
	vector<string> tmp;
		
	for(unsigned int i=0; i<directories.size(); i++){
		tmp = globFiles(allFlg,dirFlg,directories[i]+pattern);
		//cout<<directories[i];
		globAll.insert(globAll.end(),tmp.begin(), tmp.end());
	}	
	if(fileFlg)
		rmNonFiles(globAll);//removes all non files
	
	if(ageR){
		rmNonFiles(globAll);
		rmOld(globAll, age);
	}
		

	//this will print all that shit	
/*	for(unsigned int i=0; i<globAll.size(); i++){
		cout << globAll[i] << "\n";	
	}*/

	return;
}




int main (int argc, char **argv){
	bool dirFlg;
	bool allFlg;
	bool fileFlg;
	bool ageR;//restrict based on age?  implies -f
	string pattern;
	vector<string> inputs;
	int days = 0;
	opterr = 0;
	int c;
	getAge("./that");
	while ((c = getopt (argc, argv, "afdp:D:")) != -1)
		switch (c){
			case 'a':
				allFlg = true;
				break;
			case 'f':
				fileFlg = true;
				break;
			case 'd':
				dirFlg = true;
				break;
			case 'p':
				pattern = optarg;
				break;
			case 'D':
				days = atoi(optarg);
				ageR=true;
				break;
			case '?':
				if (optopt == 'p' || optopt == 'D')
					cout << "Option -" << static_cast<char>(optopt) << " requires an argument.\n";
				else//checks for any other options that arent defined
					cout << "Unknown option '-" << static_cast<char>(optopt)  <<"'.\n";
			default:
				break;
		}
	//get the non option arguments(in the for loop, and display all of the read in options so that compiler stops hating
	for (int index = optind; index < argc; index++){
		//cout << "Non-option argument " << argv[index]<<endl;
		inputs.push_back(argv[index]);
	}



	//cout << "-a " << allFlg << " -f " << fileFlg << " -d "<< dirFlg << " -p " << pattern << days << "\n";
	if(pattern == "")
		pattern="*";
	
	vector<string> allThem;
	
	for(unsigned int i=0; i<inputs.size(); i++){
		globThem(allThem, inputs[i], allFlg, fileFlg, dirFlg, pattern, ageR, days);
	}

	for(unsigned int i=0; i<allThem.size(); i++){
		cout << allThem[i] << "\n";
	}	

	return 0;
}
