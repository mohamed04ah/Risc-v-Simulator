
#include"Ls_instructions.h"
int Bintoint1(string value) {

	/*int result = 0;

	for (int i = value.size(); i >= 0; i--) {
		if (value[i] == '1') {

			result += pow(2, value.size() - i - 1);

		}
	}
	return result;*/
	if (value[0] == '1')
	{
		int r1;
		r1 = bitset<32>(value).to_ullong();

		r1 = -((1 << value.length()) - r1);
		return r1 + 1;
	}
	else
	{
		int result = 0;
		for (int i = value.size(); i >= 0; i--)
		{
			if (value[i] == '1') {

				result += pow(2, value.size() - i - 1);

			}
		}
		return result;
	}

	return 0;


}
int main() {

     read r; 
	
	 
//cout<<	 Bintoint1(bitset<32>(0).to_string());

	

	
}