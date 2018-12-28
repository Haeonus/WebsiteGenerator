#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include "vector"

using namespace std;

string printHeader(vector<vector <string> > mappingMatrix, int row, string dir){
	//Print out the header info =======================================================================
	string header = "";
	header.append("<doctype html>\n");
	header.append("<html lang=\"en\">\n");
	header.append("\t<head>\n");
	header.append("\t\t<!--Required meta tags-->\n");
	header.append("\t\t<!-- Required meta tags -->\n");
	header.append("\t\t<meta charset\"utf-8\">\n");
	header.append("\t\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, shrink-to-fit=no\">\n");
	header.append("\t\t<!-- Bootstrap CSS -->\n");
	header.append("\t\t<link rel=\"stylesheet\" href=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/css/bootstrap.min.css\" integrity=\"sha384-WskhaSGFgHYWDcbwN70/dfYBj47jz9qbsMId/iRN3ewGhXQFZCSftd1LZCfmhktB\" crossorigin=\"anonymous\">\n");
	header.append("\n\t\t<title>");
	header.append(mappingMatrix[row][0]);
	header.append("\t\t</title>\n");
	header.append("\t\t<link href=\"stickyfooter.css\" rel=\"stylesheet\">\n");
	header.append("\t</head>\n\n");
	
	
	//Print out the Navbar ===========================================================================
	//Nabar beginning
	header.append("\n<nav class=\"navbar navbar-expand-lg navbar-light\" style=\"background-color:#99ebff\">");
   	header.append("\n        <!--First link, header for navbar-->");
   	header.append("\n        <a class=\"navbar-brand\" href=\"https://www.ua.edu/\" style=\"text-align:center\">InsanityDrive</a>");
   	header.append("\n        <!--In case it becomes too small for the screen-->");
   	header.append("\n        <button class=\"navbar-toggler\" type=\"button\" data-toggle=\"collapse\" data-target=\"#navbarSupportedContent\" aria-controls=\"navbarSupportedContent\" aria-expanded=\"false\" aria-label=\"Toggle navigation\">");
   	header.append("\n            <span class=\"navbar-toggler-icon\"></span>");
   	header.append("\n        </button>");
   	
   	//Navbar Body
   	header.append("\n        <!--Body of Navbar-->");
   	header.append("\n        <div class=\"collapse navbar-collapse\" id=\"navbarSupportedContent\">");
   	header.append("\n            <ul class=\"navbar-nav mr-auto mt-2 mt-lg-0\">");
   	
   	//Generated Hierarchy
   	//If Dropdown
   	int rowIndex = 0;
   	string tbd;
   	while(rowIndex < mappingMatrix.size()){

   		if(mappingMatrix[rowIndex].size() > 1){
   			header.append("\n                <li class=\"nav-item dropdown");
   			if(row==rowIndex) header.append(" active");
   			header.append("\">");
    		header.append("\n                    <a class=\"nav-link dropdown-toggle\" href=\"#\" id=\"navbarDropdown\" role=\"button\" data-toggle=\"dropdown\" aria-haspopup=\"true\" aria-expanded=\"false\">\n");
    		header.append(mappingMatrix[rowIndex][0]);
    		header.append("\n                    </a>");
    		header.append("\n                    <div class=\"dropdown-menu\" aria-labelledby=\"navbarDropdown\">");
    		
    		string menu = mappingMatrix[rowIndex][0];
    		while(rowIndex < mappingMatrix.size() && (menu.compare(mappingMatrix[rowIndex][0]) == 0) ){
    			header.append("\n                      <a class=\"dropdown-item");
    			if(row==rowIndex) header.append(" active");
    			header.append("\" href=\"./");
    			header.append(mappingMatrix[rowIndex][1]); header.append(".html\">"); //The Link (TO DO: Update link)
    			header.append(mappingMatrix[rowIndex][1]); 
    			if(row == rowIndex) header.append("<span class=\"sr-only\">(current)</span>");
    			header.append("</a>"); //the name
    			rowIndex++;
    		}
    		rowIndex--;
    		//header.append("\n                      <div class=\"dropdown-divider\"></div>"); //Dropdown menu divider
    		//header.append("\n                      <a class=\"dropdown-item\" href=\"#\">Something else here</a>"); //a special item at bottom of the dropdown menu
    		header.append("\n                    </div>");
    		header.append("\n                </li>");
   		}else{
   			header.append("\n                <li class=\"nav-item");
   			if(row == rowIndex) header.append(" active");
   			header.append("\"><a class=\"nav-link\" href=\"./");
   			header.append(mappingMatrix[rowIndex][0]);
   			header.append(".html\">"); 
   			header.append(mappingMatrix[rowIndex][0]);
   			header.append("<span class=\"sr-only\">");
   			if(row == rowIndex) header.append("(current)");
   			header.append("</span></a></li>");
   			tbd = mappingMatrix[rowIndex][mappingMatrix[rowIndex].size()-1];
		}
		
		//tbd = mappingMatrix[rowIndex][mappingMatrix[rowIndex].size()-1];
		//cout << tbd << " " << rowIndex << endl;
		rowIndex++;
	}
   	
   	//Navbar End
   	header.append("\n            </ul>");   	
   	header.append("\n            <!--Search button--><!--");
   	header.append("\n            <form class=\"form-inline my-2 my-lg-0\">");
   	header.append("\n                <input class=\"form-control mr-sm-2\" type=\"search\" placeholder=\"Search\" aria-label=\"Search\">");
   	header.append("\n                <button class=\"btn btn-outline-success my-2 my-sm-0\" type=\"submit\">Search</button>");
   	header.append("\n             </form>-->");
   	header.append("\n        </div>");
   	header.append("\n    </nav>");
	
	return header;
}

string printFooter(){
	string footer = "";
	
	footer.append("\n\t\t<!-- Optional JavaScript -->\n\t\t<!-- jQuery first, then Popper.js, then Bootstrap JS -->");
    footer.append("\n\t\t<script src=\"https://code.jquery.com/jquery-3.3.1.slim.min.js\" integrity=\"sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo\" crossorigin=\"anonymous\"></script>");
	footer.append("\n\t\t<script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.3/umd/popper.min.js\" integrity=\"sha384-ZMP7rVo3mIykV+2+9J3UJ46jBk0WLaUAdn689aCwoqbBJiSnjAK/l8WvCWPIPm49\" crossorigin=\"anonymous\"></script>");
    footer.append("\n\t\t<script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.1.1/js/bootstrap.min.js\" integrity=\"sha384-smHYKdLADwkXOn1EmN1qk/HfnUcbVRZyYmZ4qpPea6sjB/pTJ0euyQp0Mk8ck+5T\" crossorigin=\"anonymous\"></script>");
    footer.append("\n\t</body>");
	footer.append("\n</html>");
	
	return footer;
}

void printMatrix(vector<vector <string> > mappingMatrix){
	for(int i=0; i<mappingMatrix.size(); i++){
		for(int j=0; j<mappingMatrix[i].size(); j++){
			cout << mappingMatrix[i][j];
		}
		cout << endl;
	}
}

int main(int argc, char **argv){
	if (argc != 3) {
		cerr << "Give me the enclosing folder AND mapping file" << endl;
        exit(1);
    }
	//cout << argv[1] <<endl;
	ifstream mapping (argv[1]);
	if(!mapping.is_open()){
		cout << "Failed to open file." << endl;
	}
	string line;
	
	vector<vector <string> > mappingMatrix;
	
	//cout << "Starting compilation..." << endl;
	
	if(mapping.is_open()){
		//open output file
		
		while(getline (mapping, line)){
			vector<string> lineVect;
			//Extract data from mapping File=================================================
			int i = 0;
			while(line.find(":") != string::npos){
				i = line.find(":");
				string lineSeg = line.substr(0,i);
				lineVect.push_back(lineSeg);	
				line = line.substr(i+1,string::npos);
			}
			lineVect.push_back(line);
			mappingMatrix.push_back(lineVect);	
		}
	}
	
	//Close Mapping File
	mapping.close();
	//Create new folder
	string dir = "mkdir "; dir.append(argv[2]);
	system(dir.c_str());
	
	//Generate page html code ==================================================================
	for(int rowPage = 0; rowPage < mappingMatrix.size(); rowPage++){
		//Open file
		string temp = mappingMatrix[rowPage][mappingMatrix[rowPage].size()-1];
		string fileName = "./"; fileName.append(argv[2]); fileName.append("/"); fileName.append(temp); fileName.append(".html");
		cout << fileName << endl;
		ofstream output;
		output.open(fileName);
		
		//Write information to File
		output << printHeader(mappingMatrix, rowPage, argv[2]) << endl;
		string fileName2 = temp; fileName2.append(".hrp");
		ifstream f (fileName2);
		if (f.is_open()) output << f.rdbuf() << endl;
		output << printFooter() << endl;		
		
		//Close file
		output.close();
	}
		
	return 0;
}