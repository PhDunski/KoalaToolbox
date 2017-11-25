#ifndef NOTE_SEQUENCE_HPP_INCLUDED
#define NOTE_SEQUENCE_HPP_INCLUDED
#include <random>
#include <array>
#include <string>
namespace Notes{
class Sequence{
public:
	static const std::array<std::string, 13> names;
	Sequence();
	void changeNote(int newValue);
	int selectNote();
	static std::string const & name(int value);
protected:
	int generate(int min, int max);
private:
   std::mt19937 gen_;
   static int previous_;

};
} // namespace Notes
#endif // NOTE_SEQUENCE_HPP_INCLUDED