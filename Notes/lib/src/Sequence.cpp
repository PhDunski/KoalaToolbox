#include <Sequence.hpp>
#include <cassert>
#ifdef __MINGW32__
	#include <ctime>
#endif
namespace Notes{
int Sequence::previous_=0;
const std::array<std::string, 13> Sequence::names = std::array<std::string, 13>{"C","D","E","F","G","A","B","c","d","e","f","g","a"};
std::string const & Sequence::name(int id){
	assert(id >=0 && "note id should be positive only");
	assert(id < 13 && "id out of bound");
	return names[id];
}
/* There is a bug with (at least) MinGW compiler: while using a random_device
 * should produce each time a different sequence, we have always the same
 *
 * We can fix it by using the clock time value as seed
 *
 * FIXME I'm not sure that bug is not present with gcc
 */
#ifndef __MINGW32__
Sequence::Sequence():gen_{std::random_device{}()}{
}
#else
Sequence::Sequence():gen_{static_cast<unsigned int>(std::time(nullptr))}{}
#endif
void Sequence::changeNote(int newVal){
	previous_=newVal;
}
int Sequence::selectNote(){
	auto min = previous_-4 <=0? 0 : previous_-4;
	auto max = previous_+4 >=13? 12 : previous_+4;
	previous_=generate(min, max);
	return previous_;
}
int Sequence::generate(int min, int max){
	std::uniform_int_distribution<int> dis{min, max};
	return dis(gen_);
}
} // namespace Notes