#include <vector>
#include <bitset>
#define RAM_SIZE 65536
using namespace std;

class Memory
{
public:
	Memory();
	~Memory();
	std::bitset<32> GetMDR();
	void SetMDR();
private:
	std::vector< std::bitset<8> > RAM; //Vector of 8 bit numbers to act as RAM
	std::bitset<16> MAR;
	std::bitset<32> MDR;	
	
};
Memory::Memory(){
	for(int i = 0;i<RAM_SIZE;i++){
		RAM.push_back(0); //Fills RAM up to the defined size
	}
}
Memory::~Memory(){
	RAM.clear(); //Clears the RAM
}
std::bitset<32> Memory::GetMDR(){
	return MDR; //Returns data value at address
}
void Memory::SetMDR(){
	for(int i = 0;i < 8; i++){
		MDR[i] = RAM[(int)MAR.to_ulong()][i];//Sets value of specified address in RAM
	}
}