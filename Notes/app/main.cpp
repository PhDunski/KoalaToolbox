
#include "config.h"
#include <Sequence.hpp>
#include <iostream>
int main(){
	std::cout<<"Welcom in "<<PROJECT_NAME <<" "
	         << PROJECT_VERSION_MAJOR <<"."
			 << PROJECT_VERSION_MINOR
			 <<", the full randomly generated partition generator\n\n"
			 <<"Here is such randomly generated partition:\n";
	Notes::Sequence seq;
	for(int i=0;i<10; ++i){
		auto note = seq.selectNote();
		std::cout<< Notes::Sequence::name(note)<<" ";
	}
	std::cout<<"\n";
	return 0;
}